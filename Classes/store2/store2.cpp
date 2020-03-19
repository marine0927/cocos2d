#include "store2.h"
#include "SimpleAudioEngine.h"
#include "BackGroundLayer2.h"
#include "BackPackLayer2.h"
#include "TabLayer.h"
USING_NS_CC;

Scene* Store2::createScene()
{
	auto scene = Scene::create();
	auto layer = Store2::create();
	auto backlayer = BackGround2::create();
	auto backpack = BackPack2::create();
	auto Tab = TabinGame2::create();
	scene->addChild(layer);//主层
	scene->addChild(backlayer);//技能层
	scene->addChild(backpack);//背包层
	scene->addChild(Tab);
	return scene;
}

bool Store2::init()
{

	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 3. add your codes below...

	//玩家
	SpriteFrameCache * frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("hero/hero.plist");
	SpriteFrame* herofront = frameCache->getSpriteFrameByName("hero1.png");

	//地图
	tileMap = TMXTiledMap::create("map/map.tmx");
	if (tileMap == nullptr)
	{
		return false;
	}
	else
	{
		tileMap->setScale(1);
		addChild(tileMap, 1, 100);
	}
	collidable = tileMap->getLayer("collidable");
	collidable->setVisible(false);

	hero = Sprite::createWithSpriteFrame(herofront);
	if (hero == nullptr)
	{
		return false;
	}
	else
	{
		// position the sprite on the center of the screen
		hero->setAnchorPoint(Vec2(0.5, 0.5));
		hero->setPosition(Vec2(tileMap->getContentSize().width / 2, 150));
		hero->setScale(5);
		// add the sprite as a child to this layer
		this->addChild(hero, 2, 200);
	}
	//商店
	shop = Sprite::create("hero.png");
	shop->setPosition(Vec2(tileMap->getContentSize().width / 2, 500));
	shop->setScale(3);
	this->addChild(shop, 2, 200);

	//传送点
	door = Sprite::create("ingame/door.png");
	door->setPosition(Vec2(tileMap->getContentSize().width / 2, tileMap->getContentSize().height / 2));
	addChild(door, 2, 300);

	heropressd = 0; heropressa = 0; heropresss = 0; heropressw = 0;
	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(Store2::keyPressed2, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(Store2::keyReleased2, this);

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);
	this->scheduleUpdate();
	return true;
}


void Store2::keyPressed2(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{

	switch (keyCode)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_D:heropressd = 1; break;
	case cocos2d::EventKeyboard::KeyCode::KEY_W:heropressw = 1; break;
	case cocos2d::EventKeyboard::KeyCode::KEY_S:heropresss = 1; break;
	case cocos2d::EventKeyboard::KeyCode::KEY_A:heropressa = 1; break;


	}
}
void Store2::keyReleased2(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{

	switch (keyCode)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_D:heropressd = 0; break;
	case cocos2d::EventKeyboard::KeyCode::KEY_W:heropressw = 0; break;
	case cocos2d::EventKeyboard::KeyCode::KEY_S:heropresss = 0; break;
	case cocos2d::EventKeyboard::KeyCode::KEY_A:heropressa = 0; break;


	}
}



void Store2::update(float dt)
{
	//前后左右
	SpriteFrame* herofront = SpriteFrameCache::getInstance()->getSpriteFrameByName("hero1.png");
	SpriteFrame* heroback = SpriteFrameCache::getInstance()->getSpriteFrameByName("hero2.png");
	SpriteFrame* heroright = SpriteFrameCache::getInstance()->getSpriteFrameByName("hero3.png");
	SpriteFrame* heroleft = SpriteFrameCache::getInstance()->getSpriteFrameByName("hero4.png");
	Vec2 heroPos = hero->getPosition();
	if (heropressd) {
		heroPos = heroPos + Vec2(10, 0);
		hero->setSpriteFrame(heroright);
	}
	if (heropresss) {
		heroPos = heroPos + Vec2(0, -10);
		hero->setSpriteFrame(herofront);
	}
	if (heropressa) {
		heroPos = heroPos + Vec2(-10, 0);
		hero->setSpriteFrame(heroleft);
	}
	if (heropressw) {
		heroPos = heroPos + Vec2(0, 10);
		hero->setSpriteFrame(heroback);
	}

	this->setheroPosition2(heroPos);
	this->setViewpointCenter2(heroPos);

	if (shop->getBoundingBox().intersectsRect(hero->getBoundingBox())) {
		backpack = 1;
		showShop = true;
	}
	else {
		backpack = 0;
		showShop = false;
		log("TouchMoved");
	}
	if (hero->getBoundingBox().intersectsRect(door->getBoundingBox()))//进入传送门
		menuItemcontinueCallBACK2(this);
}

void Store2::setViewpointCenter2(Vec2 position)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	int x = MAX(position.x, visibleSize.width / 2);
	int y = MAX(position.y, visibleSize.height / 2);
	x = MIN(x, (2400 - visibleSize.width / 2));
	y = MIN(y, (2400 - visibleSize.height / 2));

	Vec2 pointA = Vec2(visibleSize.width / 2, visibleSize.height / 2);
	Vec2 pointB = Vec2(x, y);

	Vec2 offset = pointA - pointB;
	this->setPosition(offset);
}

void Store2::setheroPosition2(cocos2d::Vec2 position)
{
	Vec2 tileCoord = this->tileCoordFromPosition2(position);
	int tileGid = collidable->getTileGIDAt(tileCoord);

	if (tileGid > 0)
	{
		return;
	}
	else
	{
		hero->setPosition(position);
	}
}

cocos2d::Vec2 Store2::tileCoordFromPosition2(cocos2d::Vec2 position)
{
	float x = position.x / tileMap->getTileSize().width;
	float y = ((tileMap->getMapSize().height*tileMap->getTileSize().height) - position.y) / tileMap->getTileSize().height;
	return cocos2d::Vec2(x, y);

}

void Store2::onExitTransitionDidStart()
{
	Layer::onExitTransitionDidStart();
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();//注销监听器
}
void Store2::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(Store2::keyPressed2, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(Store2::keyReleased2, this);

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);
}

void Store2::menuItemcontinueCallBACK2(Ref* pSender)
{
	auto sc = Battle3::createScene();
	Director::getInstance()->pushScene(sc);
}