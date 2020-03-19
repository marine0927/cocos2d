#include "HelpScene.h"

USING_NS_CC;
using namespace CocosDenshion;
Scene* Help::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Help::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool Help::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	
	Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//游戏说明   操作说明
	Sprite *bg = Sprite::create("HomeScene3.png");
	bg->setScale(visibleSize.height / bg->getContentSize().height);
	bg->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	this->addChild(bg);
	
	auto exitMenuItem = MenuItemImage::create("exit.png","exit0.png",CC_CALLBACK_1(Help::menuExitCallback,this));
	exitMenuItem->setPosition(Vec2(origin.x + visibleSize.width, 100));
	exitMenuItem->setAnchorPoint(Vec2(1, 0));
	Menu* mn = Menu::create(exitMenuItem, NULL);
	mn->setPosition(Vec2::ZERO);
	this->addChild(mn);

	Sprite *help = Sprite::create("helpinformation.png");
	// position the label on the center of the screen
	help->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	help->setScale(1.5);

	this->addChild(help);



	//返回按钮
	/*auto exitMenuItem = MenuItemImage::create(
		"exit.png",
		"exit0.png",
		CC_CALLBACK_1(Help::menuExitCallback, this));

	exitMenuItem->setPosition(Vec2(origin.x + visibleSize.width ,
		origin.y));

	Menu* mn = Menu::create(exitMenuItem, NULL);
	mn->setPosition(Vec2::ZERO);
	this->addChild(mn);*/
	return true;
}

void Help::menuExitCallback(Ref* pSender)
{
	UserDefault *defaults = UserDefault::getInstance();
	if (defaults->getBoolForKey(SOUND_KEY)) {
		SimpleAudioEngine::getInstance()->playEffect("sound/dianji.mp3");
	}
	Director::getInstance()->popScene();
}