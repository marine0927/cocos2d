#include "store.h"
#include "SimpleAudioEngine.h"
#include "BackGroundLayer.h"
#include "BackPackLayer.h"
#include "TabLayer.h"

USING_NS_CC;
extern int tag = 0;
extern cocos2d::Map < std::string, cocos2d::Sprite* > skillmap = Map<std::string, Sprite*>();
extern int backpack = 0;
extern int gold = 8000;//金钱
extern int MAX_SKILL = 30;//总技能数
extern int tagin1 = 0, tagin2 = 0, tagin3 = 0, tagin4 = 0, tagin5 = 0, tagin6 = 0, tagin7 = 0;
extern bool normal1 = false, blink1 = false, special11 = false, special21 = false, special31 = false, special41 = false, buff1 = false, normal2 = false, blink2 = false, special12 = false, special22 = false, special32 = false, special42 = false, buff2 = false;
extern bool changeNormal = false, changeBlink = false, changeSpecial1 = false, changeSpecial2 = false, changeSpecial3 = false, changeSpecial4 = false, changeBuff = true;
extern Vec2 initPosition = Vec2(0, 0);
extern bool showShop = false;//商店的显示与隐藏

Scene* Store1::createScene()
{
	auto scene = Scene::create();
	auto layer = Store1::create();
	auto backlayer = BackGround::create();
	auto backpack = BackPack::create();
	auto Tab = TabinGame1::create();
	scene->addChild(layer);//主层
	scene->addChild(backlayer);//技能层
	scene->addChild(backpack);//背包层
	scene->addChild(Tab);
	return scene;
}

bool Store1::init()
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
	keyboardListener->onKeyPressed = CC_CALLBACK_2(Store1::keyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(Store1::keyReleased, this);

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);
	this->scheduleUpdate();
	return true;
}


void Store1::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{

	switch (keyCode)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_D:heropressd = 1; break;
	case cocos2d::EventKeyboard::KeyCode::KEY_W:heropressw = 1; break;
	case cocos2d::EventKeyboard::KeyCode::KEY_S:heropresss = 1; break;
	case cocos2d::EventKeyboard::KeyCode::KEY_A:heropressa = 1; break;


	}
}
void Store1::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{

	switch (keyCode)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_D:heropressd = 0; break;
	case cocos2d::EventKeyboard::KeyCode::KEY_W:heropressw = 0; break;
	case cocos2d::EventKeyboard::KeyCode::KEY_S:heropresss = 0; break;
	case cocos2d::EventKeyboard::KeyCode::KEY_A:heropressa = 0; break;


	}
}



void Store1::update(float dt)
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

	this->setheroPosition(heroPos);
	this->setViewpointCenter(heroPos);

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
		menuItemcontinueCallBACK(this);
}

void Store1::setViewpointCenter(Vec2 position)
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

void Store1::setheroPosition(cocos2d::Vec2 position)
{
	Vec2 tileCoord = this->tileCoordFromPosition(position);
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

cocos2d::Vec2 Store1::tileCoordFromPosition(cocos2d::Vec2 position)
{
	float x = position.x / tileMap->getTileSize().width;
	float y = ((tileMap->getMapSize().height*tileMap->getTileSize().height) - position.y) / tileMap->getTileSize().height;
	return cocos2d::Vec2(x, y);

}

void Store1::onExitTransitionDidStart()
{
	Layer::onExitTransitionDidStart();
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();//注销监听器
}
void Store1::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(Store1::keyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(Store1::keyReleased, this);

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);
}

void Store1::menuItemcontinueCallBACK(Ref* pSender)
{
	auto sc = Battle2::createScene();
	Director::getInstance()->pushScene(sc);
}