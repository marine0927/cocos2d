#include "EndScene.h"

USING_NS_CC;

Scene* GameEnd::createScene()
{
	auto scene = Scene::create();

	auto layer = GameEnd::create();
	scene->addChild(layer);

	return scene;
}

bool GameEnd::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	theend = Sprite::create("text/end.png");
	theend->setAnchorPoint(Vec2(0.5, 0));
	theend->setScale(1.5);
	theend->setPosition(Vec2(origin.x + visibleSize.height / 2, 0));
	this->addChild(theend, 1);
	theend->runAction(MoveTo::create(2.0, Vec2(origin.x + visibleSize.height / 2, 1200)));

	return true;
}