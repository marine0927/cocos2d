#include "GameStartScene.h"
#include "BackGroundLayer.h"
#include "TabLayer.h"
#include "TalkLayer.h"
USING_NS_CC;

extern bool showTalk = false;
extern bool talkTo1 = false, talkTo2 = false, talkTo3 = false, talkTo4 = false, talkTo5 = false, talkTo6 = false;

Scene* GameStart::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameStart::create();
	auto BackGround = BackGroundInStart::create();
	auto Talk = Talk::create();
	auto Tab = TabinStart::create();
	// add layer as a child to scene
	scene->addChild(layer);
	scene->addChild(BackGround);
	scene->addChild(Talk);
	scene->addChild(Tab);
	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameStart::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	//地图
	tileMap = TMXTiledMap::create("map/map.tmx");
	if (tileMap == nullptr)
	{
		return false;
	}
	else
	{
		tileMap->setScale(0);
		tileMap->setOpacity(0);
		addChild(tileMap, 0, 100);
	}
	collidable = tileMap->getLayer("collidable");
	collidable->setVisible(false);

	auto bg = Sprite::create("NPC/Hall.png");
	bg->setAnchorPoint(Vec2(0.5, 0));
	bg->setPosition(Vec2(tileMap->getContentSize().width / 2, 0));
	this->addChild(bg, 1, 101);

	//玩家
	SpriteFrameCache * frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("hero/hero.plist");
	SpriteFrame* herofront = frameCache->getSpriteFrameByName("hero1.png");

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
		this->setheroPosition(hero->getPosition());
		this->setViewpointCenter(hero->getPosition());
		hero->setScale(5);
		// add the sprite as a child to this layer
		this->addChild(hero, 3, 200);
	}

	//关卡提示
	auto label1 = Label::createWithSystemFont("CASTLE", "Arial", 36);
	label1->setPosition(Vec2(tileMap->getContentSize().width / 2, 600));
	this->addChild(label1, 1);
	label1->setOpacity(0);
	FiniteTimeAction* ac0 = (FiniteTimeAction*)label1->runAction(FadeIn::create(1));
	FiniteTimeAction* ac1 = (FiniteTimeAction*)label1->runAction(FadeOut::create(1));
	label1->runAction(Sequence::create(ac0, ac1, NULL));
	
	//对话提示
	f1 = Sprite::create("NPC/f.png");
	f1->setPosition(Vec2(30, 180));
	f1->setScale(0.0);

	f2 = Sprite::create("NPC/f.png");
	f2->setPosition(Vec2(30, 180));
	f2->setScale(0.0);

	f3 = Sprite::create("NPC/f.png");
	f3->setPosition(Vec2(30, 180));
	f3->setScale(0.0);

	f4 = Sprite::create("NPC/f.png");
	f4->setPosition(Vec2(30, 180));
	f4->setScale(0.0);

	f5 = Sprite::create("NPC/f.png");
	f5->setPosition(Vec2(30, 180));
	f5->setScale(0.0);

	f6 = Sprite::create("NPC/f.png");
	f6->setPosition(Vec2(30, 180));
	f6->setScale(0.0);

	//npc们
	npc1 = Sprite::create("NPC/npc1.png");
	npc1->setPosition(Vec2(tileMap->getContentSize().width / 2 - 150, 300));
	this->addChild(npc1, 3, 200);
	npc1->addChild(f1, 4);

	npc2 = Sprite::create("NPC/npc2.png");
	npc2->setPosition(Vec2(tileMap->getContentSize().width / 2 + 150, 600));
	this->addChild(npc2, 3, 200);	
	npc2->addChild(f2, 4);

	npc3 = Sprite::create("NPC/npc3.png");
	npc3->setPosition(Vec2(tileMap->getContentSize().width / 2 - 150, 900));
	this->addChild(npc3, 3, 200);
	npc3->addChild(f3, 4);

	npc4 = Sprite::create("NPC/npc4.png");
	npc4->setPosition(Vec2(tileMap->getContentSize().width / 2 + 150, 1200));
	this->addChild(npc4, 3, 200);
	npc4->addChild(f4, 4);

	npc5 = Sprite::create("NPC/npc5.png");
	npc5->setPosition(Vec2(tileMap->getContentSize().width / 2 - 150, 1500));
	this->addChild(npc5, 3, 200);
	npc5->addChild(f5, 4);

	npc6 = Sprite::create("NPC/npc6.png");
	npc6->setPosition(Vec2(tileMap->getContentSize().width / 2 + 150, 1800));
	this->addChild(npc6, 3, 200);
	npc6->addChild(f6, 4);

	//传送点
	door = Sprite::create("ingame/door.png");
	door->setPosition(Vec2(tileMap->getContentSize().width / 2, tileMap->getContentSize().height - 150));
	door->setScale(0.0);
	addChild(door, 2, 300);

	heropressd = 0; heropressa = 0; heropresss = 0; heropressw = 0;
	heropressf = false;
	
	this->scheduleUpdate();
	return true;
}
void GameStart::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{

	switch (keyCode)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_D:heropressd = 1; break;
	case cocos2d::EventKeyboard::KeyCode::KEY_W:heropressw = 1; break;
	case cocos2d::EventKeyboard::KeyCode::KEY_S:heropresss = 1; break;
	case cocos2d::EventKeyboard::KeyCode::KEY_A:heropressa = 1; break;
	case cocos2d::EventKeyboard::KeyCode::KEY_F:heropressf = true; break;


	}
}
void GameStart::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{

	switch (keyCode)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_D:heropressd = 0; break;
	case cocos2d::EventKeyboard::KeyCode::KEY_W:heropressw = 0; break;
	case cocos2d::EventKeyboard::KeyCode::KEY_S:heropresss = 0; break;
	case cocos2d::EventKeyboard::KeyCode::KEY_A:heropressa = 0; break;


	}
}

void GameStart::onExitTransitionDidStart()
{
	Layer::onExitTransitionDidStart();
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();//注销监听器
}
void GameStart::onEnterTransitionDidFinish()
{

	Layer::onEnterTransitionDidFinish();
	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(GameStart::keyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(GameStart::keyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);
}

void GameStart::update(float dt)
{
	bool bounding = hero->getBoundingBox().intersectsRect(npc1->getBoundingBox()) ||
		hero->getBoundingBox().intersectsRect(npc2->getBoundingBox()) ||
		hero->getBoundingBox().intersectsRect(npc3->getBoundingBox()) ||
		hero->getBoundingBox().intersectsRect(npc4->getBoundingBox()) ||
		hero->getBoundingBox().intersectsRect(npc5->getBoundingBox()) ||
		hero->getBoundingBox().intersectsRect(npc6->getBoundingBox());

	heroX = hero->getPositionX();
	heroY = hero->getPositionY();
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
	if (BossDead == true)//Boss死后出现传送门
		door->setScale(1.0);
	if (hero->getBoundingBox().intersectsRect(door->getBoundingBox()))//进入传送门
		gotogame(this);
	if (hero->getBoundingBox().intersectsRect(npc1->getBoundingBox()))
	{
		f1->setScale(2.0);
		if (heropressf == true)
		{
			heropressf = false;
			showTalk = true;
			talkTo1 = true;
		}
	}
	else if (!bounding)
	{
		showTalk = false;
		f1->setScale(0.0);
		talkTo1 = false;
	}
		
	if (hero->getBoundingBox().intersectsRect(npc2->getBoundingBox()))
	{
		f2->setScale(2.0);
		if (heropressf == true)
		{
			heropressf = false;
			showTalk = true;
			talkTo2 = true;
		}
	}
	else if (!bounding)
	{
		showTalk = false;
		f2->setScale(0.0);
		talkTo2 = false;
	}

	if (hero->getBoundingBox().intersectsRect(npc3->getBoundingBox()))
	{
		f3->setScale(2.0);
		if (heropressf == true)
		{
			heropressf = false;
			showTalk = true;
			talkTo3 = true;
		}
	}
	else if (!bounding)
	{
		showTalk = false;
		f3->setScale(0.0);
		talkTo3 = false;
	}

	if (hero->getBoundingBox().intersectsRect(npc4->getBoundingBox()))
	{
		f4->setScale(2.0);
		if (heropressf == true)
		{
			heropressf = false;
			showTalk = true;
			talkTo4 = true;
		}
	}
	else if (!bounding)
	{
		showTalk = false;
		f4->setScale(0.0);
		talkTo4 = false;
	}

	if (hero->getBoundingBox().intersectsRect(npc5->getBoundingBox()))
	{
		f5->setScale(2.0);
		if (heropressf == true)
		{
			heropressf = false;
			showTalk = true;
			talkTo5 = true;
		}
	}
	else if (!bounding)
	{
		showTalk = false;
		f5->setScale(0.0);
		talkTo5 = false;
	}

	if (hero->getBoundingBox().intersectsRect(npc6->getBoundingBox()))
	{
		f6->setScale(2.0);
		if (heropressf == true)
		{
			heropressf = false;
			showTalk = true;
			talkTo6 = true;
		}
	}
	else if (!bounding)
	{
		showTalk = false;
		f6->setScale(0.0);
		talkTo6 = false;
	}
}

void GameStart::setViewpointCenter(Vec2 position)
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

void GameStart::setheroPosition(cocos2d::Vec2 position)
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

cocos2d::Vec2 GameStart::tileCoordFromPosition(cocos2d::Vec2 position)
{
	float x = position.x / tileMap->getTileSize().width;
	float y = ((tileMap->getMapSize().height*tileMap->getTileSize().height) - position.y) / tileMap->getTileSize().height;
	return cocos2d::Vec2(x, y);

}

void GameStart::gotogame(Ref *pSender)
{
	auto sc = Battle1::createScene();
	Director::getInstance()->replaceScene(sc);
}
