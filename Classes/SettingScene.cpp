#include "SettingScene.h"

USING_NS_CC;
using namespace CocosDenshion;
Scene* Setting::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Setting::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool Setting::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	
	Sprite *bg = Sprite::create("HomeScene3.png");
	bg->setScale(visibleSize.height / bg->getContentSize().height);
	bg->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	this->addChild(bg);

	/*//ÒôÐ§
	auto soundOnMenuItem = MenuItemImage::create(
		"yinxiaoon.png",
		"yinxiaoon.png");
	auto soundOffMenuItem = MenuItemImage::create(
		"yinxiaooff.png",
		"yinxiaooff.png");

	auto soundToggleMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(Setting::menuSoundToggleCallback, this),
		soundOnMenuItem,
		soundOffMenuItem,
		NULL);

	//ÒôÀÖ
	auto musicOnMenuItem = MenuItemImage::create(
		"soundon.png",
		"soundon.png");
	auto musicOffMenuItem = MenuItemImage::create(
		"soundoff.png",
		"soundoff.png");
	auto musicToggleMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(Setting::menuMusicToggleCallback, this),
		musicOnMenuItem,
		musicOffMenuItem,
		NULL);*/

	auto soundOnSprite = Sprite::create("yinxiaoon.png"); auto soundOnSprite0 = Sprite::create("yinxiaoon0.png");
	auto soundOffSprite = Sprite::create("yinxiaooff.png");	auto soundOffSprite0 = Sprite::create("yinxiaooff0.png");
	auto soundOnMenuItem = MenuItemSprite::create(soundOnSprite, soundOnSprite0);
	auto soundOffMenuItem = MenuItemSprite::create(soundOffSprite, soundOffSprite0);
	auto soundToggleMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(Setting::menuSoundToggleCallback, this), soundOnMenuItem, soundOffMenuItem, NULL);

	//ÒôÀÖ.
	auto musicOnSprite = Sprite::create("soundon.png"); auto musicOnSprite0 = Sprite::create("soundon0.png");
	auto musicOffSprite = Sprite::create("soundoff.png"); auto musicOffSprite0 = Sprite::create("soundoff0.png");
	auto musicOnMenuItem = MenuItemSprite::create(musicOnSprite, musicOnSprite0);
	auto musicOffMenuItem = MenuItemSprite::create(musicOffSprite, musicOffSprite0);
	auto musicToggleMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(Setting::menuMusicToggleCallback, this), musicOnMenuItem, musicOffMenuItem, NULL);

	//Ok°´Å¥
	auto okMenuItem = MenuItemImage::create(
		"exit.png",
		"exit0.png",
		CC_CALLBACK_1(Setting::menuOkCallback, this));

	Menu* mn = Menu::create(soundToggleMenuItem, musicToggleMenuItem, okMenuItem,NULL);
	mn->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	mn->alignItemsVerticallyWithPadding(5);
	this->addChild(mn);
	//ÉèÖÃÒôÐ§ºÍÒôÀÖÑ¡ÖÐ×´Ì¬
	UserDefault *defaults = UserDefault::getInstance();
	if (defaults->getBoolForKey(MUSIC_KEY)) {
		musicToggleMenuItem->setSelectedIndex(0);
	}
	else {
		musicToggleMenuItem->setSelectedIndex(1);
	}
	if (defaults->getBoolForKey(SOUND_KEY)) {
		soundToggleMenuItem->setSelectedIndex(0);
	}
	else {
		soundToggleMenuItem->setSelectedIndex(1);
	}
	return true;
}

void Setting::menuOkCallback(Ref* pSender)
{
	UserDefault *defaults = UserDefault::getInstance();
	if (defaults->getBoolForKey(SOUND_KEY)) {
		SimpleAudioEngine::getInstance()->playEffect("sound/dianji.mp3");
	}
	Director::getInstance()->popScene();
}

void Setting::menuSoundToggleCallback(Ref* pSender)
{
	UserDefault *defaults = UserDefault::getInstance();
	if (defaults->getBoolForKey(SOUND_KEY)) {
		defaults->setBoolForKey(SOUND_KEY, false);
	}
	else {
		defaults->setBoolForKey(SOUND_KEY, true);
		SimpleAudioEngine::getInstance()->playEffect("sound/dianji.mp3");
	}
}


void Setting::menuMusicToggleCallback(Ref* pSender)
{
	UserDefault *defaults = UserDefault::getInstance();
	if (defaults->getBoolForKey(MUSIC_KEY)) {
		defaults->setBoolForKey(MUSIC_KEY, false);
		SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	}
	else {
		defaults->setBoolForKey(MUSIC_KEY, true);
		SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/DBD.mp3", true);
	}
}