#ifndef _TABINSTARTLAYER_H_
#define _TABINSTARTLAYER_H_

#include "store1/store.h"
#include "Tab.h"
#include "cocos2d.h"
USING_NS_CC;

bool TabinStart::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	
	bg = Sprite::create("Tab/bg.png");
	bg->setPosition(650,400);
	bg->setScale(1.2);
	bg->setOpacity(180);
	this->addChild(bg, 2, 300);

	skill1 = Sprite::create("skill/skillbg.png");
	skill1->setPosition(Vec2(42, 50));
	skill1->setScale(0.6);
	bg->addChild(skill1, 3);

	skill2 = Sprite::create("skill/skillbg.png");
	skill2->setPosition(Vec2(42 * 2, 50));
	skill2->setScale(0.6);
	bg->addChild(skill2, 3);

	skill3 = Sprite::create("skill/skillbg.png");
	skill3->setPosition(Vec2(42 * 3, 50));
	skill3->setScale(0.6);
	bg->addChild(skill3, 3);

	skill4 = Sprite::create("skill/skillbg.png");
	skill4->setPosition(Vec2(42 * 4, 50));
	skill4->setScale(0.6);
	bg->addChild(skill4, 3);

	skill5 = Sprite::create("skill/skillbg.png");
	skill5->setPosition(Vec2(42 * 5, 50));
	skill5->setScale(0.6);
	bg->addChild(skill5, 3);

	skill6 = Sprite::create("skill/skillbg.png");
	skill6->setPosition(Vec2(42 * 6, 50));
	skill6->setScale(0.6);
	bg->addChild(skill6, 3);

	skill7 = Sprite::create("skill/skillbg.png");
	skill7->setPosition(Vec2(42 * 7, 50));
	skill7->setScale(0.6);
	bg->addChild(skill7, 3);

	text = Sprite::create("text/bg.png");
	text->setPosition(Vec2(650, 450));
	text->setScale(0.0);
	this->addChild(text, 3);

	this->scheduleUpdate();

	return true;
}
void TabinStart::update(float dt)
{
	if (show)
		TabinStart::setScale(1.0);
	else 
		TabinStart::setScale(0.0);
	if (tagin1 == INIT_NORMAL_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal1.png");
		skill1->setTexture(texture);
		skill1->setTag(tagin1);
	}
	else if (tagin1 == HERO_NORMAL_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal2.png");
		skill1->setTexture(texture);
		skill1->setTag(tagin1);
	}
	else if (tagin1 == HERO2_NORMAL_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal3.png");
		skill1->setTexture(texture);
		skill1->setTag(tagin1);
	}

	if (tagin2 == INIT_BLINK_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Blink1.png");
		skill2->setTexture(texture);
		skill2->setTag(tagin2);
	}
	else if (tagin2 == HERO_BLINK_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Blink2.png");
		skill2->setTexture(texture);
		skill2->setTag(tagin2);
	}
	else if (tagin2 == HERO2_BLINK_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Blink3.png");
		skill2->setTexture(texture);
		skill2->setTag(tagin2);
	}

	if (tagin3 == INIT_SPECIAL1_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Point1.png");
		skill3->setTexture(texture);
		skill3->setTag(tagin3);
	}
	else if (tagin3 == INIT_SPECIAL2_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Round1.png");
		skill3->setTexture(texture);
		skill3->setTag(tagin3);
	}
	else if (tagin3 == INIT_SPECIAL3_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Special1.png");
		skill3->setTexture(texture);
		skill3->setTag(tagin3);
	}
	else if (tagin3 == INIT_SPECIAL4_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Follow1.png");
		skill3->setTexture(texture);
		skill3->setTag(tagin3);
	}
	else if (tagin3 == HERO_SPECIAL1_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Point2.png");
		skill3->setTexture(texture);
		skill3->setTag(tagin3);
	}
	else if (tagin3 == HERO_SPECIAL2_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Round2.png");
		skill3->setTexture(texture);
		skill3->setTag(tagin3);
	}
	else if (tagin3 == HERO_SPECIAL3_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Special2.png");
		skill3->setTexture(texture);
		skill3->setTag(tagin3);
	}
	else if (tagin3 == HERO_SPECIAL4_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Follow2.png");
		skill3->setTexture(texture);
		skill3->setTag(tagin3);
	}
	else if (tagin3 == HERO2_SPECIAL1_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Point3.png");
		skill3->setTexture(texture);
		skill3->setTag(tagin3);
	}
	else if (tagin3 == HERO2_SPECIAL2_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Round3.png");
		skill3->setTexture(texture);
		skill3->setTag(tagin3);
	}
	else if (tagin3 == HERO2_SPECIAL3_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Special3.png");
		skill3->setTexture(texture);
		skill3->setTag(tagin3);
	}
	else if (tagin3 == HERO2_SPECIAL4_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Follow3.png");
		skill3->setTexture(texture);
		skill3->setTag(tagin3);
	}

	if (tagin4 == INIT_SPECIAL1_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Point1.png");
		skill4->setTexture(texture);
		skill4->setTag(tagin4);
	}
	else if (tagin4 == INIT_SPECIAL2_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Round1.png");
		skill4->setTexture(texture);
		skill4->setTag(tagin4);
	}
	else if (tagin4 == INIT_SPECIAL3_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Special1.png");
		skill4->setTexture(texture);
		skill4->setTag(tagin4);
	}
	else if (tagin4 == INIT_SPECIAL4_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Follow1.png");
		skill4->setTexture(texture);
		skill4->setTag(tagin4);
	}
	else if (tagin4 == HERO_SPECIAL1_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Point2.png");
		skill4->setTexture(texture);
		skill4->setTag(tagin4);
	}
	else if (tagin4 == HERO_SPECIAL2_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Round2.png");
		skill4->setTexture(texture);
		skill4->setTag(tagin4);
	}
	else if (tagin4 == HERO_SPECIAL3_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Special2.png");
		skill4->setTexture(texture);
		skill4->setTag(tagin4);
	}
	else if (tagin4 == HERO_SPECIAL4_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Follow2.png");
		skill4->setTexture(texture);
		skill4->setTag(tagin4);
	}
	else if (tagin4 == HERO2_SPECIAL1_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Point3.png");
		skill4->setTexture(texture);
		skill4->setTag(tagin4);
	}
	else if (tagin4 == HERO2_SPECIAL2_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Round3.png");
		skill4->setTexture(texture);
		skill4->setTag(tagin4);
	}
	else if (tagin4 == HERO2_SPECIAL3_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Special3.png");
		skill4->setTexture(texture);
		skill4->setTag(tagin4);
	}
	else if (tagin4 == HERO2_SPECIAL4_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Follow3.png");
		skill4->setTexture(texture);
		skill4->setTag(tagin4);
	}

	if (tagin5 == INIT_SPECIAL1_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Point1.png");
		skill5->setTexture(texture);
		skill5->setTag(tagin5);
	}
	else if (tagin5 == INIT_SPECIAL2_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Round1.png");
		skill5->setTexture(texture);
		skill5->setTag(tagin5);
	}
	else if (tagin5 == INIT_SPECIAL3_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Special1.png");
		skill5->setTexture(texture);
		skill5->setTag(tagin5);
	}
	else if (tagin5 == INIT_SPECIAL4_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Follow1.png");
		skill5->setTexture(texture);
		skill5->setTag(tagin5);
	}
	else if (tagin5 == HERO_SPECIAL1_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Point2.png");
		skill5->setTexture(texture);
		skill5->setTag(tagin5);
	}
	else if (tagin5 == HERO_SPECIAL2_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Round2.png");
		skill5->setTexture(texture);
		skill5->setTag(tagin5);
	}
	else if (tagin5 == HERO_SPECIAL3_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Special2.png");
		skill5->setTexture(texture);
		skill5->setTag(tagin5);
	}
	else if (tagin5 == HERO_SPECIAL4_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Follow2.png");
		skill5->setTexture(texture);
		skill5->setTag(tagin5);
	}
	else if (tagin5 == HERO2_SPECIAL1_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Point3.png");
		skill5->setTexture(texture);
		skill5->setTag(tagin5);
	}
	else if (tagin5 == HERO2_SPECIAL2_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Round3.png");
		skill5->setTexture(texture);
		skill5->setTag(tagin5);
	}
	else if (tagin5 == HERO2_SPECIAL3_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Special3.png");
		skill5->setTexture(texture);
		skill5->setTag(tagin5);
	}
	else if (tagin5 == HERO2_SPECIAL4_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Follow3.png");
		skill5->setTexture(texture);
		skill5->setTag(tagin5);
	}

	if (tagin6 == INIT_SPECIAL1_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Point1.png");
		skill6->setTexture(texture);
		skill6->setTag(tagin6);
	}
	else if (tagin6 == INIT_SPECIAL2_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Round1.png");
		skill6->setTexture(texture);
		skill6->setTag(tagin6);
	}
	else if (tagin6 == INIT_SPECIAL3_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Special1.png");
		skill6->setTexture(texture);
		skill6->setTag(tagin6);
	}
	else if (tagin6 == INIT_SPECIAL4_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Follow1.png");
		skill6->setTexture(texture);
		skill6->setTag(tagin6);
	}
	else if (tagin6 == HERO_SPECIAL1_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Point2.png");
		skill6->setTexture(texture);
		skill6->setTag(tagin6);
	}
	else if (tagin6 == HERO_SPECIAL2_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Round2.png");
		skill6->setTexture(texture);
		skill6->setTag(tagin6);
	}
	else if (tagin6 == HERO_SPECIAL3_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Special2.png");
		skill6->setTexture(texture);
		skill6->setTag(tagin6);
	}
	else if (tagin6 == HERO_SPECIAL4_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Follow2.png");
		skill6->setTexture(texture);
		skill6->setTag(tagin6);
	}
	else if (tagin6 == HERO2_SPECIAL1_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Point3.png");
		skill6->setTexture(texture);
		skill6->setTag(tagin6);
	}
	else if (tagin6 == HERO2_SPECIAL2_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Round3.png");
		skill6->setTexture(texture);
		skill6->setTag(tagin6);
	}
	else if (tagin6 == HERO2_SPECIAL3_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Special3.png");
		skill6->setTexture(texture);
		skill6->setTag(tagin6);
	}
	else if (tagin6 == HERO2_SPECIAL4_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Follow3.png");
		skill6->setTexture(texture);
		skill6->setTag(tagin6);
	}

	if (tagin7 == INIT_BUFF_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Buff1.png");
		skill7->setTexture(texture);
		skill7->setTag(tagin7);
	}
	else if (tagin7 == HERO_BUFF_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Buff2.png");
		skill7->setTexture(texture);
		skill7->setTag(tagin7);
	}
	else if (tagin7 == HERO2_BUFF_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Buff3.png");
		skill7->setTexture(texture);
		skill7->setTag(tagin7);
	}

}
void TabinStart::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();

	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(TabinStart::keyPressed, this);

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);

	auto touchlistener = EventListenerTouchOneByOne::create();

	touchlistener->setSwallowTouches(true);
	touchlistener->onTouchBegan = CC_CALLBACK_2(TabinStart::touchbegin, this);
	touchlistener->onTouchEnded = CC_CALLBACK_2(TabinStart::touchend, this);

	EventDispatcher * toucheventDispatcher = Director::getInstance()->getEventDispatcher();
	toucheventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener, skill1);
	toucheventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener->clone(), skill2);
	toucheventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener->clone(), skill3);
	toucheventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener->clone(), skill4);
	toucheventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener->clone(), skill5);
	toucheventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener->clone(), skill6);
	toucheventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener->clone(), skill7);
}
void TabinStart::onExitTransitionDidStart()
{
	Layer::onExitTransitionDidStart();
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
}
void TabinStart::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{
	index++;
	switch (keyCode)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_TAB:
		if (index % 2 == 0)
			show = true;
		else
			show = false;
		break;
	}
}
bool TabinStart::touchbegin(Touch* touch, Event *event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());

	Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

	if (rect.containsPoint(locationInNode))
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("text/bg.png");
		if (target->getTag() == INIT_NORMAL_TAG)
			texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal1.png");
		if (target->getTag() == INIT_BLINK_TAG)
			texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal1.png");
		if (target->getTag() == INIT_SPECIAL1_TAG)
			texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal1.png");
		if (target->getTag() == INIT_SPECIAL2_TAG)
			texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal1.png");
		if (target->getTag() == INIT_SPECIAL3_TAG)
			texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal1.png");
		if (target->getTag() == INIT_SPECIAL4_TAG)
			texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal1.png");
		if (target->getTag() == INIT_BUFF_TAG)
			texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal1.png");
		if (target->getTag() == HERO_NORMAL_TAG)
			texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal1.png");
		if (target->getTag() == HERO_BLINK_TAG)
			texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal1.png");
		if (target->getTag() == HERO_SPECIAL1_TAG)
			texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal1.png");
		if (target->getTag() == HERO_SPECIAL2_TAG)
			texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal1.png");
		if (target->getTag() == HERO_SPECIAL3_TAG)
			texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal1.png");
		if (target->getTag() == HERO_SPECIAL4_TAG)
			texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal1.png");
		if (target->getTag() == HERO_BUFF_TAG)
			texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal1.png");
		if (target->getTag() == HERO2_NORMAL_TAG)
			texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal1.png");
		if (target->getTag() == HERO2_BLINK_TAG)
			texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal1.png");
		if (target->getTag() == HERO2_SPECIAL1_TAG)
			texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal1.png");
		if (target->getTag() == HERO2_SPECIAL2_TAG)
			texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal1.png");
		if (target->getTag() == HERO2_SPECIAL3_TAG)
			texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal1.png");
		if (target->getTag() == HERO2_SPECIAL4_TAG)
			texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal1.png");
		if (target->getTag() == HERO2_BUFF_TAG)
			texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal1.png");
		text->setTexture(texture);
		text->setScale(1.0);
		return true;
	}
	return false;
}
void TabinStart::touchend(Touch* touch, Event *event)
{
	text->setScale(0.0);
}
#endif