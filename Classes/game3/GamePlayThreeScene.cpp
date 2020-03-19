#include "GamePlayThreeScene.h"
#include "BackGroundLayer.h"
USING_NS_CC;

Scene* GamePlayThree::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GamePlayThree::create();
	auto BackGround = BackGroundInGame3::create();
	// add layer as a child to scene
	scene->addChild(layer);
	scene->addChild(BackGround);
	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GamePlayThree::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//��ͼ
	tileMap = TMXTiledMap::create("map/map.tmx");
	if (tileMap == nullptr)
	{
		return false;
	}
	else
	{
		tileMap->setScale(1);
		addChild(tileMap, 0, 100);
	}
	collidable = tileMap->getLayer("collidable");
	collidable->setVisible(false);

	//���
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

	//�ؿ���ʾ
	auto label1 = Label::createWithSystemFont("TOWER", "Arial", 36);
	label1->setPosition(Vec2(tileMap->getContentSize().width / 2, 600));
	this->addChild(label1, 1);
	label1->setOpacity(0);//FadeIn֮ǰ�����þ��鲻͸���ȣ�0~255,0Ϊ��ȫ͸��
	FiniteTimeAction* ac0 = (FiniteTimeAction*)label1->runAction(FadeIn::create(1));
	FiniteTimeAction* ac1 = (FiniteTimeAction*)label1->runAction(FadeOut::create(1));
	label1->runAction(Sequence::create(ac0, ac1, NULL));

	//���͵�
	door = Sprite::create("ingame/door.png");
	door->setPosition(Vec2(tileMap->getContentSize().width / 2, tileMap->getContentSize().height / 2));
	door->setScale(0.0);
	addChild(door, 2, 300);

	heropressd = 0; heropressa = 0; heropresss = 0; heropressw = 0;
	auto keyboardListener1 = EventListenerKeyboard::create();
	keyboardListener1->onKeyPressed = CC_CALLBACK_2(GamePlayThree::keyPressed, this);
	keyboardListener1->onKeyReleased = CC_CALLBACK_2(GamePlayThree::keyReleased, this);

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener1, this);
	this->scheduleUpdate();
	return true;
}
//�����ص�
void GamePlayThree::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{

	switch (keyCode)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_D:heropressd = 1; break;
	case cocos2d::EventKeyboard::KeyCode::KEY_W:heropressw = 1; break;
	case cocos2d::EventKeyboard::KeyCode::KEY_S:heropresss = 1; break;
	case cocos2d::EventKeyboard::KeyCode::KEY_A:heropressa = 1; break;


	}
}
void GamePlayThree::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{

	switch (keyCode)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_D:heropressd = 0; break;
	case cocos2d::EventKeyboard::KeyCode::KEY_W:heropressw = 0; break;
	case cocos2d::EventKeyboard::KeyCode::KEY_S:heropresss = 0; break;
	case cocos2d::EventKeyboard::KeyCode::KEY_A:heropressa = 0; break;


	}
}

void GamePlayThree::onExitTransitionDidStart()
{
	Layer::onExitTransitionDidStart();
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();//ע��������
}
void GamePlayThree::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(GamePlayThree::keyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(GamePlayThree::keyReleased, this);

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);
}
bool isend = true;
int endtime = 0;
void GamePlayThree::update(float dt)
{
	//ǰ������
	SpriteFrame* herofront = SpriteFrameCache::getInstance()->getSpriteFrameByName("hero1.png");
	SpriteFrame* heroback = SpriteFrameCache::getInstance()->getSpriteFrameByName("hero2.png");
	SpriteFrame* heroright = SpriteFrameCache::getInstance()->getSpriteFrameByName("hero3.png");
	SpriteFrame* heroleft = SpriteFrameCache::getInstance()->getSpriteFrameByName("hero4.png");
	Vec2 heroPos = hero->getPosition();
	if (heropressd) {
		log("press d");
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
	if (BossDead == true)//Boss������ִ�����
		door->setScale(1.0);
	if (hero->getBoundingBox().intersectsRect(door->getBoundingBox()))//���봫����
	{
		endtime++;
		if (isend)
		{
			isend = false;
			end(this);
		}
		if (endtime == 2400)
		{
			Director::getInstance()->popToSceneStackLevel(0);
		}
	}
}

void GamePlayThree::setViewpointCenter(Vec2 position)
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

void GamePlayThree::setheroPosition(cocos2d::Vec2 position)
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

cocos2d::Vec2 GamePlayThree::tileCoordFromPosition(cocos2d::Vec2 position)
{
	float x = position.x / tileMap->getTileSize().width;
	float y = ((tileMap->getMapSize().height*tileMap->getTileSize().height) - position.y) / tileMap->getTileSize().height;
	return cocos2d::Vec2(x, y);
}

void GamePlayThree::end(cocos2d::Ref* pSender)
{
	theend = Sprite::create("text/end.png");
	theend->setAnchorPoint(Vec2(0.5, 0));
	theend->setScale(2);
	theend->setPosition(1200, -1000);
	this->addChild(theend, 10);
	theend->runAction(MoveTo::create(30, Vec2(1200, 1800)));
}