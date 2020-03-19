#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}
// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite *bg = Sprite::create("HelloWorld.png");
	bg->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	this->addChild(bg);

	//½øÈëHome
	auto tohome = Sprite::create("enter.png");
	auto tohome0 = Sprite::create("enter.png");
	auto tohome1 = MenuItemSprite::create(
		tohome,
		tohome0,
		CC_CALLBACK_1(HelloWorld::toHomeScene, this));
	tohome1->setPosition(Director::getInstance()->convertToGL(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2)));

	Menu* mn = Menu::create(tohome1,NULL);
	mn->setPosition(Vec2::ZERO);
	this->addChild(mn);
	return true;
}


void HelloWorld::toHomeScene(Ref* pSender)
{
	auto sc = Home::createScene();
	Director::getInstance()->replaceScene(sc);
}
