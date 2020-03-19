#include "HomeScene.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
USING_NS_CC;

Scene* Home::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Home::create();

	// add layer as a child to scene
	scene->addChild(layer,0,100);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool Home::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	//背景
	Sprite *bg = Sprite::create("HomeScene3.png");
	bg->setScale(visibleSize.height / bg->getContentSize().height);
	bg->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	this->addChild(bg);

	// 开始菜单

	
	
	
	auto startSpriteNormal = Sprite::create("start.png");
	auto startSpriteSelected = Sprite::create("start0.png");
	auto startMenuItem = MenuItemSprite::create(
		startSpriteNormal,
		startSpriteSelected,
		CC_CALLBACK_1(Home::menuStart, this));

	// 设置菜单
	auto settingSpriteNormal = Sprite::create("setting.png");
	auto settingSpriteSelected = Sprite::create("setting0.png");
	auto settingMenuItem = MenuItemSprite::create(
		settingSpriteNormal,
		settingSpriteSelected,
		CC_CALLBACK_1(Home::menuSetting, this));

	// 帮助菜单
	auto helppriteNormal = Sprite::create("help.png");
	auto helpSpriteSelected = Sprite::create("help0.png");
	auto helpMenuItem = MenuItemSprite::create(
		helppriteNormal,
		helpSpriteSelected,
		CC_CALLBACK_1(Home::menuHelp, this));

	// 商店菜单
	auto storepriteNormal = Sprite::create("store.png");
	auto storeSpriteSelected = Sprite::create("store0.png");
	auto storeMenuItem = MenuItemSprite::create(
		storepriteNormal,
		storeSpriteSelected,
		CC_CALLBACK_1(Home::menuStore, this));
	

	Menu* mn = Menu::create(startMenuItem, settingMenuItem, helpMenuItem, storeMenuItem,NULL);
	mn->setPosition(visibleSize.width +origin.x-100, 450);
	mn->setAnchorPoint(Vec2(1, 0));
	mn->alignItemsVerticallyWithPadding(5);
	this->addChild(mn);
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/Michel F.April - Dead By Daylight(Theme).mp3", true);
	return true;
}
//
void Home::menuStart(cocos2d::Ref *psender)
{
	UserDefault *defaults = UserDefault::getInstance();
	if (defaults->getBoolForKey(SOUND_KEY)) {
		SimpleAudioEngine::getInstance()->playEffect("sound/dianji.mp3");
	}
	auto sc = GameStart::createScene();
	Director::getInstance()->replaceScene(sc);
}
void Home::menuStore(cocos2d::Ref *psender)
{
	UserDefault *defaults = UserDefault::getInstance();
	if (defaults->getBoolForKey(SOUND_KEY)) {
		SimpleAudioEngine::getInstance()->playEffect("sound/dianji.mp3");
	}
	auto sc = Store1::createScene();
	Director::getInstance()->pushScene(sc);
}
void Home::menuSetting(cocos2d::Ref *psender)
{
	UserDefault *defaults = UserDefault::getInstance();
	if (defaults->getBoolForKey(SOUND_KEY)) {
		SimpleAudioEngine::getInstance()->playEffect("sound/dianji.mp3");
	}
	auto sc = Setting::createScene();
	Director::getInstance()->pushScene(sc);
}
void Home::menuHelp(cocos2d::Ref *psender)
{
	UserDefault *defaults = UserDefault::getInstance();
	if (defaults->getBoolForKey(SOUND_KEY)) {
		SimpleAudioEngine::getInstance()->playEffect("sound/dianji.mp3");
	}
	auto sc = Help::createScene();
	Director::getInstance()->pushScene(sc);
}
void Home::onEnter()
{
	Layer::onEnter();
	log("HelloWorld onEnter");
	UserDefault *defaults = UserDefault::getInstance();
	if (defaults->getBoolForKey(MUSIC_KEY)) {
		SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/DBD.mp3", true);
	}
}

void Home::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	log("HelloWorld onEnterTransitionDidFinish");
}

void Home::onExit()
{
	Layer::onExit();
	log("HelloWorld onExit");
}

void Home::onExitTransitionDidStart()
{
	Layer::onExitTransitionDidStart();
	log("HelloWorld onExitTransitionDidStart");
}

void Home::cleanup()
{
	Layer::cleanup();
	log("HelloWorld cleanup");
	//停止
	SimpleAudioEngine::getInstance()->stopBackgroundMusic("sound/DBD.mp3");
}

