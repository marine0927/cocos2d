#ifndef _BACKPACKLAYER_H_
#define _BACKPACKLAYER_H_

#include "store2.h"
#include "Backpack2.h"
#include "cocos2d.h"

bool BackPack2::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	x = 0;
	y = 0;

	//背包
	bg = Sprite::create("backpack/bg.png");
	bg->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	bg->setOpacity(100);
	//bg->setScale(0);
	this->addChild(bg, 2, 200);

	//金币
	__String * money = __String::createWithFormat("%d", gold);
	const char * golden = money->getCString();
	golds = Label::createWithSystemFont(golden, "Arial", 36);
	golds->setPosition(Vec2(200, 800));
	this->addChild(golds);

	//商店内的技能

	skill1_1 = Sprite::create("skill/Normal2.png");
	skill1_1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 100, origin.y + visibleSize.height / 2 + 100));
	//skill1_1->setScale(0);
	this->addChild(skill1_1, 3, NORMAL_TAG);

	skill2_1 = Sprite::create("skill/Blink2.png");
	skill2_1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 240, origin.y + visibleSize.height / 2 + 200));
	//skill2_1->setScale(0);
	this->addChild(skill2_1, 3, BLINK_TAG);

	skill3_1 = Sprite::create("skill/Point2.png");
	skill3_1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 100, origin.y + visibleSize.height / 2 - 100));
	//skill3_1->setScale(0);
	this->addChild(skill3_1, 3, POINT_TAG);

	skill4_1 = Sprite::create("skill/Round2.png");
	skill4_1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 240, origin.y + visibleSize.height / 2 - 200));
	//	skill4_1->setScale(0);
	this->addChild(skill4_1, 3, ROUND_TAG);

	skill5_1 = Sprite::create("skill/Special2.png");
	skill5_1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 480, origin.y + visibleSize.height / 2 + 160));
	//skill5_1->setScale(0);
	this->addChild(skill5_1, 3, AIM_TAG);

	skill6_1 = Sprite::create("skill/Follow2.png");
	skill6_1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 480, origin.y + visibleSize.height / 2 - 160));
	//skill6_1->setScale(0);
	this->addChild(skill6_1, 3, FOLLOW_TAG);

	skill7_1 = Sprite::create("skill/Buff2.png");
	skill7_1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 300, origin.y + visibleSize.height / 2));
	//skill7_1->setScale(0);
	this->addChild(skill7_1, 3, BUFF_TAG);

	skill8_1 = Sprite::create("skill/Normal3.png");
	skill8_1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 200, origin.y + visibleSize.height / 2 + 100));
	this->addChild(skill8_1, 3, NORMAL2_TAG);

	skill9_1 = Sprite::create("skill/Blink3.png");
	skill9_1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 340, origin.y + visibleSize.height / 2 + 200));
	this->addChild(skill9_1, 3, BLINK2_TAG);

	skill10_1 = Sprite::create("skill/Point3.png");
	skill10_1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 200, origin.y + visibleSize.height / 2 - 100));
	this->addChild(skill10_1, 3, POINT2_TAG);

	skill11_1 = Sprite::create("skill/Round3.png");
	skill11_1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 340, origin.y + visibleSize.height / 2 - 200));
	this->addChild(skill11_1, 3, ROUND2_TAG);

	skill12_1 = Sprite::create("skill/Special3.png");
	skill12_1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 480, origin.y + visibleSize.height / 2 + 260));
	this->addChild(skill12_1, 3, AIM2_TAG);

	skill13_1 = Sprite::create("skill/Follow3.png");
	skill13_1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 480, origin.y + visibleSize.height / 2 - 60));
	this->addChild(skill13_1, 3, FOLLOW2_TAG);

	skill14_1 = Sprite::create("skill/Buff3.png");
	skill14_1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 400, origin.y + visibleSize.height / 2));
	this->addChild(skill14_1, 3, BUFF2_TAG);

	//技能介绍
	text = Sprite::create("text/bg.png");
	text->setPosition(Vec2(800, 500));
	text->setScale(0.0);
	this->addChild(text, 4);



	//装备中的技能（仅供阴暗，拖拽提示）
	skill1_2 = Sprite::create("skill/hero_skill_bg.png");
	skill1_2->setPosition(Vec2(70, 50));
	skill1_2->setOpacity(100);
	//	skill1_2->setScale(0);
	this->addChild(skill1_2, 3, 200);

	skill2_2 = Sprite::create("skill/hero_skill_bg.png");
	skill2_2->setPosition(Vec2(70 * 2, 50));
	skill2_2->setOpacity(100);
	//skill2_2->setScale(0);
	this->addChild(skill2_2, 3, 200);

	skill3_2 = Sprite::create("skill/hero_skill_bg.png");
	skill3_2->setPosition(Vec2(70 * 3, 50));
	skill3_2->setOpacity(100);
	//skill3_2->setScale(0);
	this->addChild(skill3_2, 3, 200);

	skill4_2 = Sprite::create("skill/hero_skill_bg.png");
	skill4_2->setPosition(Vec2(70 * 4, 50));
	skill4_2->setOpacity(100);
	//skill4_2->setScale(0);
	this->addChild(skill4_2, 3, 200);

	skill5_2 = Sprite::create("skill/hero_skill_bg.png");
	skill5_2->setPosition(Vec2(70 * 5, 50));
	skill5_2->setOpacity(100);
	//skill5_2->setScale(0);
	this->addChild(skill5_2, 3, 200);

	skill6_2 = Sprite::create("skill/hero_skill_bg.png");
	skill6_2->setPosition(Vec2(70 * 6, 50));
	skill6_2->setOpacity(100);
	//skill6_2->setScale(0);
	this->addChild(skill6_2, 3, 200);

	skill7_2 = Sprite::create("skill/hero_skill_bg.png");
	skill7_2->setPosition(Vec2(70 * 7, visibleSize.height - 50));
	skill7_2->setOpacity(100);
	//skill7_2->setScale(0);
	this->addChild(skill7_2, 3, 200);

	for (int i = 0; i < 7; i++)
	{
		__String * skillkey = __String::createWithFormat("skill_%d", i);

		skillmap.at(skillkey->getCString())->setPosition(Vec2(750 + x, 700 - y));

		this->addChild(skillmap.at(skillkey->getCString()), 3);
		x += 80;
		if ((800 + x) > 1150)
		{
			x = 0;
			y += 80;
		}
	}
	pos15 = skillmap.at("skill_0")->getPosition();
	pos16 = skillmap.at("skill_1")->getPosition();
	pos17 = skillmap.at("skill_2")->getPosition();
	pos18 = skillmap.at("skill_3")->getPosition();
	pos19 = skillmap.at("skill_4")->getPosition();
	pos20 = skillmap.at("skill_5")->getPosition();
	pos21 = skillmap.at("skill_6")->getPosition();
	this->scheduleUpdate();

	return true;
}
bool addliss = true;
void BackPack2::update(float dt)
{
	//拖拽事件
	auto draglistener = EventListenerTouchOneByOne::create();
	draglistener->setSwallowTouches(true);
	draglistener->onTouchBegan = CC_CALLBACK_2(BackPack2::dragbegin2, this);
	draglistener->onTouchMoved = CC_CALLBACK_2(BackPack2::dragmove2, this);
	draglistener->onTouchEnded = CC_CALLBACK_2(BackPack2::dragend2, this);

	EventDispatcher * drageventDispatcher = Director::getInstance()->getEventDispatcher();
	if (addliss)
	{
		addliss = false;
		drageventDispatcher->addEventListenerWithSceneGraphPriority(draglistener, getChildByTag(INIT_NORMAL_TAG));
		drageventDispatcher->addEventListenerWithSceneGraphPriority(draglistener->clone(), getChildByTag(INIT_BLINK_TAG));
		drageventDispatcher->addEventListenerWithSceneGraphPriority(draglistener->clone(), getChildByTag(INIT_SPECIAL1_TAG));
		drageventDispatcher->addEventListenerWithSceneGraphPriority(draglistener->clone(), getChildByTag(INIT_SPECIAL2_TAG));
		drageventDispatcher->addEventListenerWithSceneGraphPriority(draglistener->clone(), getChildByTag(INIT_SPECIAL3_TAG));
		drageventDispatcher->addEventListenerWithSceneGraphPriority(draglistener->clone(), getChildByTag(INIT_SPECIAL4_TAG));
		drageventDispatcher->addEventListenerWithSceneGraphPriority(draglistener->clone(), getChildByTag(INIT_BUFF_TAG));
	}
	if (normal1)
	{
		drageventDispatcher->addEventListenerWithSceneGraphPriority(draglistener, getChildByTag(HERO_NORMAL_TAG));
		normal1 = false;
	}
	if (blink1)
	{
		drageventDispatcher->addEventListenerWithSceneGraphPriority(draglistener->clone(), getChildByTag(HERO_BLINK_TAG));
		blink1 = false;
	}
	if (special11)
	{
		drageventDispatcher->addEventListenerWithSceneGraphPriority(draglistener->clone(), getChildByTag(HERO_SPECIAL1_TAG));
		special11 = false;
	}
	if (special21)
	{
		drageventDispatcher->addEventListenerWithSceneGraphPriority(draglistener->clone(), getChildByTag(HERO_SPECIAL2_TAG));
		special21 = false;
	}
	if (special31)
	{
		drageventDispatcher->addEventListenerWithSceneGraphPriority(draglistener->clone(), getChildByTag(HERO_SPECIAL3_TAG));
		special31 = false;
	}
	if (special41)
	{
		drageventDispatcher->addEventListenerWithSceneGraphPriority(draglistener->clone(), getChildByTag(HERO_SPECIAL4_TAG));
		special41 = false;
	}
	if (buff1)
	{
		drageventDispatcher->addEventListenerWithSceneGraphPriority(draglistener->clone(), getChildByTag(HERO_BUFF_TAG));
		buff1 = false;
	}

	if (normal2)
	{
		drageventDispatcher->addEventListenerWithSceneGraphPriority(draglistener, getChildByTag(HERO2_NORMAL_TAG));
		normal2 = false;
	}
	if (blink2)
	{
		drageventDispatcher->addEventListenerWithSceneGraphPriority(draglistener->clone(), getChildByTag(HERO2_BLINK_TAG));
		blink2 = false;
	}
	if (special12)
	{
		drageventDispatcher->addEventListenerWithSceneGraphPriority(draglistener->clone(), getChildByTag(HERO2_SPECIAL1_TAG));
		special12 = false;
	}
	if (special22)
	{
		drageventDispatcher->addEventListenerWithSceneGraphPriority(draglistener->clone(), getChildByTag(HERO2_SPECIAL2_TAG));
		special22 = false;
	}
	if (special32)
	{
		drageventDispatcher->addEventListenerWithSceneGraphPriority(draglistener->clone(), getChildByTag(HERO2_SPECIAL3_TAG));
		special32 = false;
	}
	if (special42)
	{
		drageventDispatcher->addEventListenerWithSceneGraphPriority(draglistener->clone(), getChildByTag(HERO2_SPECIAL4_TAG));
		special42 = false;
	}
	if (buff2)
	{
		drageventDispatcher->addEventListenerWithSceneGraphPriority(draglistener->clone(), getChildByTag(HERO2_BUFF_TAG));
		buff2 = false;
	}
	if (showShop)
	{
		BackPack2::setScale(1.0);
	}
	else
	{
		BackPack2::setScale(0.0);
	}
}

void BackPack2::onEnter()
{
	Layer::onEnter();

	


	//鼠标事件
	auto mouseListener = EventListenerMouse::create();
	mouseListener->onMouseMove = CC_CALLBACK_1(BackPack2::mouseMove2, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, getChildByTag(NORMAL_TAG));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener->clone(), getChildByTag(BLINK_TAG));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener->clone(), getChildByTag(POINT_TAG));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener->clone(), getChildByTag(ROUND_TAG));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener->clone(), getChildByTag(AIM_TAG));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener->clone(), getChildByTag(FOLLOW_TAG));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener->clone(), getChildByTag(BUFF_TAG));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener->clone(), getChildByTag(NORMAL2_TAG));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener->clone(), getChildByTag(BLINK2_TAG));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener->clone(), getChildByTag(POINT2_TAG));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener->clone(), getChildByTag(ROUND2_TAG));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener->clone(), getChildByTag(AIM2_TAG));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener->clone(), getChildByTag(FOLLOW2_TAG));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener->clone(), getChildByTag(BUFF2_TAG));

	//触摸事件
	auto touchlistener = EventListenerTouchOneByOne::create();
	// 设置是否吞没事件，在 onTouchBegan 方法返回 true 时吞没
	touchlistener->setSwallowTouches(true);
	touchlistener->onTouchBegan = CC_CALLBACK_2(BackPack2::touchbegin2, this);
	touchlistener->onTouchEnded = CC_CALLBACK_2(BackPack2::touchend2, this);

	EventDispatcher * toucheventDispatcher = Director::getInstance()->getEventDispatcher();
	toucheventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener, getChildByTag(NORMAL_TAG));
	toucheventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener->clone(), getChildByTag(BLINK_TAG));
	toucheventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener->clone(), getChildByTag(POINT_TAG));
	toucheventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener->clone(), getChildByTag(ROUND_TAG));
	toucheventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener->clone(), getChildByTag(AIM_TAG));
	toucheventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener->clone(), getChildByTag(FOLLOW_TAG));
	toucheventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener->clone(), getChildByTag(BUFF_TAG));
	toucheventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener->clone(), getChildByTag(NORMAL2_TAG));
	toucheventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener->clone(), getChildByTag(BLINK2_TAG));
	toucheventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener->clone(), getChildByTag(POINT2_TAG));
	toucheventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener->clone(), getChildByTag(ROUND2_TAG));
	toucheventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener->clone(), getChildByTag(AIM2_TAG));
	toucheventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener->clone(), getChildByTag(FOLLOW2_TAG));
	toucheventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener->clone(), getChildByTag(BUFF2_TAG));

	//拖拽事件

}

void BackPack2::onExit()
{
	Layer::onExit();
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
}

void BackPack2::mouseMove2(Event *event)//判断鼠标位置
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

	EventMouse* e = (EventMouse*)event;
	float x = e->getCursorX();
	float y = e->getCursorY();
	Vec2 Location = target->convertToNodeSpace(Vec2(x, y));

	if (rect.containsPoint(Location))
	{
		text->setScale(1.0);
	}
	else
	{
		text->setScale(0.0);
	}
}
bool BackPack2::touchbegin2(Touch* touch, Event *event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());

	// 获取当前点击点所在相对按钮的位置坐标
	Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

	// 点击范围判断检测
	if (rect.containsPoint(locationInNode))
	{
		log("sprite x = %f, y = %f ", locationInNode.x, locationInNode.y);
		log("sprite tag = %d", target->getTag());
		target->runAction(ScaleTo::create(0.06f, 1.5f));
		text->setScale(1.0);
		return true;
	}
	return false;

}
void BackPack2::touchend2(Touch* touch, Event *event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	// 获取当前点击点所在相对按钮的位置坐标
	Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

	// 点击范围判断检测
	if (rect.containsPoint(locationInNode))
	{
		text->setScale(0.0);
		log("sprite x = %f, y = %f ", locationInNode.x, locationInNode.y);
		log("sprite tag = %d", target->getTag());
		target->runAction(ScaleTo::create(0.06f, 1.0f));
		int price;
		if (target->getTag() == NORMAL_TAG || target->getTag() == NORMAL2_TAG)
		{
			price = 100;
		}
		if (target->getTag() == BLINK_TAG || target->getTag() == BLINK2_TAG)
		{
			price = 150;
		}
		if (target->getTag() == POINT_TAG || target->getTag() == POINT2_TAG)
		{
			price = 200;
		}
		if (target->getTag() == ROUND_TAG || target->getTag() == ROUND2_TAG)
		{
			price = 250;
		}
		if (target->getTag() == AIM_TAG || target->getTag() == AIM2_TAG)
		{
			price = 300;
		}
		if (target->getTag() == FOLLOW_TAG || target->getTag() == FOLLOW2_TAG)
		{
			price = 350;
		}
		if (target->getTag() == BUFF_TAG || target->getTag() == BUFF2_TAG)
		{
			price = 400;
		}
		if (gold >= price) {
			gold -= price;
			__String * money = __String::createWithFormat("%d", gold);
			const char * golden = money->getCString();
			golds->setString(golden);
			target->runAction(ScaleTo::create(0.06f, 0.0f));
			addskill2(target);
		}
	}
	else
	{
		target->runAction(ScaleTo::create(0.06f, 1.0f));
	}

}
bool Add1 = true, Add2 = true, Add3 = true, Add4 = true, Add5 = true, Add6 = true, Add7 = true, Add8 = true, Add9 = true, Add10 = true, Add11 = true, Add12 = true, Add13 = true, Add14 = true;
void BackPack2::addskill2(Sprite * sprite)//往背包中添加技能
{
	if (sprite->getTag() == NORMAL_TAG)
	{
		if (Add1)
		{
			Add1 = false;
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal2.png");
			skillmap.at("skill_7")->setTexture(texture);
			skillmap.at("skill_7")->setPosition(Vec2(750 + x, 700 - y));
			this->addChild(skillmap.at("skill_7"), 3, HERO_NORMAL_TAG);
			pos1 = skillmap.at("skill_7")->getPosition();
			normal1 = true;
			x += 80;
		}
	}
	if (sprite->getTag() == BLINK_TAG)
	{
		if (Add2)
		{
			Add2 = false;
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Blink2.png");
			skillmap.at("skill_8")->setTexture(texture);
			skillmap.at("skill_8")->setPosition(Vec2(750 + x, 700 - y));
			skillmap.at("skill_8")->setTag(HERO_BLINK_TAG);
			this->addChild(skillmap.at("skill_8"), 3, HERO_BLINK_TAG);
			pos2 = skillmap.at("skill_8")->getPosition();
			blink1 = true;
			x += 80;
		}

	}
	if (sprite->getTag() == POINT_TAG)
	{
		if (Add3)
		{
			Add3 = false;
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Point2.png");
			skillmap.at("skill_9")->setTexture(texture);
			skillmap.at("skill_9")->setPosition(Vec2(750 + x, 700 - y));
			this->addChild(skillmap.at("skill_9"), 3, HERO_SPECIAL1_TAG);
			pos3 = skillmap.at("skill_9")->getPosition();
			special11 = true;
			x += 80;
		}
	}
	if (sprite->getTag() == ROUND_TAG)
	{
		if (Add4)
		{
			Add4 = false;
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Round2.png");
			skillmap.at("skill_10")->setTexture(texture);
			skillmap.at("skill_10")->setPosition(Vec2(750 + x, 700 - y));
			this->addChild(skillmap.at("skill_10"), 3, HERO_SPECIAL2_TAG);
			pos4 = skillmap.at("skill_10")->getPosition();
			special21 = true;
			x += 80;
		}
	}
	if (sprite->getTag() == AIM_TAG)
	{
		if (Add5)
		{
			Add5 = false;
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Special2.png");
			skillmap.at("skill_11")->setTexture(texture);
			skillmap.at("skill_11")->setPosition(Vec2(750 + x, 700 - y));
			this->addChild(skillmap.at("skill_11"), 3, HERO_SPECIAL3_TAG);
			pos5 = skillmap.at("skill_11")->getPosition();
			special31 = true;
			x += 80;
		}
	}
	if (sprite->getTag() == FOLLOW_TAG)
	{
		if (Add6)
		{
			Add6 = false;
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Follow2.png");
			skillmap.at("skill_12")->setTexture(texture);
			skillmap.at("skill_12")->setPosition(Vec2(750 + x, 700 - y));
			this->addChild(skillmap.at("skill_12"), 3, HERO_SPECIAL4_TAG);
			pos6 = skillmap.at("skill_12")->getPosition();
			special41 = true;
			x += 80;
		}
	}

	if (sprite->getTag() == BUFF_TAG)
	{
		if (Add7)
		{
			Add7 = false;
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Buff2.png");
			skillmap.at("skill_13")->setTexture(texture);
			skillmap.at("skill_13")->setPosition(Vec2(750 + x, 700 - y));
			this->addChild(skillmap.at("skill_13"), 3, HERO_BUFF_TAG);
			pos7 = skillmap.at("skill_13")->getPosition();
			buff1 = true;
			x += 80;
		}
	}

	if (sprite->getTag() == NORMAL2_TAG)
	{
		if (Add8)
		{
			Add8 = false;
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal3.png");
			skillmap.at("skill_14")->setTexture(texture);
			skillmap.at("skill_14")->setPosition(Vec2(750 + x, 700 - y));
			this->addChild(skillmap.at("skill_14"), 3, HERO2_NORMAL_TAG);
			pos8 = skillmap.at("skill_14")->getPosition();
			normal2 = true;
			x += 80;
		}
	}
	if (sprite->getTag() == BLINK2_TAG)
	{
		if (Add9)
		{
			Add9 = false;
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Blink3.png");
			skillmap.at("skill_15")->setTexture(texture);
			skillmap.at("skill_15")->setPosition(Vec2(750 + x, 700 - y));
			this->addChild(skillmap.at("skill_15"), 3, HERO2_BLINK_TAG);
			pos9 = skillmap.at("skill_15")->getPosition();
			blink2 = true;
			x += 80;
		}
	}
	if (sprite->getTag() == POINT2_TAG)
	{
		if (Add10)
		{
			Add10 = false;
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Point3.png");
			skillmap.at("skill_16")->setTexture(texture);
			skillmap.at("skill_16")->setPosition(Vec2(750 + x, 700 - y));
			this->addChild(skillmap.at("skill_16"), 3, HERO2_SPECIAL1_TAG);
			pos10 = skillmap.at("skill_16")->getPosition();
			special12 = true;
			x += 80;
		}
	}
	if (sprite->getTag() == ROUND2_TAG)
	{
		if (Add11)
		{
			Add11 = false;
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Round3.png");
			skillmap.at("skill_17")->setTexture(texture);
			skillmap.at("skill_17")->setPosition(Vec2(750 + x, 700 - y));
			this->addChild(skillmap.at("skill_17"), 3, HERO2_SPECIAL2_TAG);
			pos11 = skillmap.at("skill_17")->getPosition();
			special22 = true;
			x += 80;
		}
	}
	if (sprite->getTag() == AIM2_TAG)
	{
		if (Add12)
		{
			Add12 = false;
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Special3.png");
			skillmap.at("skill_18")->setTexture(texture);
			skillmap.at("skill_18")->setPosition(Vec2(750 + x, 700 - y));
			this->addChild(skillmap.at("skill_18"), 3, HERO2_SPECIAL3_TAG);
			pos12 = skillmap.at("skill_18")->getPosition();
			special32 = true;
			x += 80;
		}
	}
	if (sprite->getTag() == FOLLOW2_TAG)
	{
		if (Add13)
		{
			Add13 = false;
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Follow3.png");
			skillmap.at("skill_19")->setTexture(texture);
			skillmap.at("skill_19")->setPosition(Vec2(750 + x, 700 - y));
			this->addChild(skillmap.at("skill_19"), 3, HERO2_SPECIAL4_TAG);
			pos13 = skillmap.at("skill_19")->getPosition();
			special42 = true;
			x += 80;
		}
	}
	if (sprite->getTag() == BUFF2_TAG)
	{
		if (Add14)
		{
			Add14 = false;
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Buff3.png");
			skillmap.at("skill_20")->setTexture(texture);
			skillmap.at("skill_20")->setPosition(Vec2(750 + x, 700 - y));
			this->addChild(skillmap.at("skill_20"), 3, HERO2_BUFF_TAG);
			pos14 = skillmap.at("skill_20")->getPosition();
			buff2 = true;
			x += 80;
		}
	}
	
	if ((800 + x) > 1150)
	{
		x = 0;
		y += 80;
	}
}

bool BackPack2::dragbegin2(cocos2d::Touch* touch, cocos2d::Event *event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	initPosition = target->getPosition();
	Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

	// 点击范围判断检测
	if (rect.containsPoint(locationInNode))
	{
		log("sprite x = %f, y = %f ", locationInNode.x, locationInNode.y);
		log("sprite tag = %d", target->getTag());
		target->runAction(ScaleBy::create(0.06f, 1.06f));
		if (target->getTag() == HERO2_NORMAL_TAG || target->getTag() == HERO_NORMAL_TAG || target->getTag() == INIT_NORMAL_TAG)
		{
			skill1_2->setOpacity(0);
		}
		if (target->getTag() == HERO2_BLINK_TAG || target->getTag() == HERO_BLINK_TAG || target->getTag() == INIT_BLINK_TAG)
		{
			skill2_2->setOpacity(0);
		}
		if (target->getTag() == HERO2_SPECIAL1_TAG || target->getTag() == HERO2_SPECIAL2_TAG || target->getTag() == HERO2_SPECIAL3_TAG || target->getTag() == HERO2_SPECIAL4_TAG || target->getTag() == HERO_SPECIAL1_TAG || target->getTag() == HERO_SPECIAL2_TAG || target->getTag() == HERO_SPECIAL3_TAG || target->getTag() == HERO_SPECIAL4_TAG || target->getTag() == INIT_SPECIAL1_TAG || target->getTag() == INIT_SPECIAL2_TAG || target->getTag() == INIT_SPECIAL3_TAG || target->getTag() == INIT_SPECIAL4_TAG)
		{
			skill3_2->setOpacity(0);
			skill4_2->setOpacity(0);
			skill5_2->setOpacity(0);
			skill6_2->setOpacity(0);
		}
		if (target->getTag() == HERO2_BUFF_TAG || target->getTag() == HERO_BUFF_TAG || target->getTag() == INIT_BUFF_TAG)
		{
			skill7_2->setOpacity(0);
		}
		return true;
	}
	return false;
}
void BackPack2::dragmove2(cocos2d::Touch* touch, cocos2d::Event *event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	target->setPosition(target->getPosition() + touch->getDelta());
}
void BackPack2::dragend2(cocos2d::Touch* touch, cocos2d::Event *event)
{
	skill1_2->setOpacity(100);
	skill2_2->setOpacity(100);
	skill3_2->setOpacity(100);
	skill4_2->setOpacity(100);
	skill5_2->setOpacity(100);
	skill6_2->setOpacity(100);
	skill7_2->setOpacity(100);
	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);
	// 点击范围判断检测
	if (rect.containsPoint(locationInNode))
	{
		log("sprite x = %f, y = %f ", locationInNode.x, locationInNode.y);
		log("sprite tag = %d", target->getTag());
		target->runAction(ScaleTo::create(0.06f, 1.0f));
	}
	if (target->getTag() == HERO_NORMAL_TAG)
	{
		if (target->getBoundingBox().intersectsRect(skill1_2->getBoundingBox()))
		{
			back2(pos1, target);
			tag = target->getTag();
			changeNormal = true;
		}
		else
		{
			back2(pos1, target);
		}
	}
	if (target->getTag() == HERO_BLINK_TAG)
	{
		if (target->getBoundingBox().intersectsRect(skill2_2->getBoundingBox()))
		{
			back2(pos2, target);
			tag = target->getTag();
			changeBlink = true;
		}
		else
		{
			back2(pos2, target);
		}
	}
	if (target->getTag() == HERO_SPECIAL1_TAG || target->getTag() == HERO_SPECIAL2_TAG || target->getTag() == HERO_SPECIAL3_TAG || target->getTag() == HERO_SPECIAL4_TAG)
	{
		if (target->getBoundingBox().intersectsRect(skill3_2->getBoundingBox()))
		{
			if (target->getTag() == HERO_SPECIAL1_TAG)
			{
				back2(pos3, target);
			}
			if (target->getTag() == HERO_SPECIAL2_TAG)
			{
				back2(pos4, target);
			}
			if (target->getTag() == HERO_SPECIAL3_TAG)
			{
				back2(pos5, target);
			}
			if (target->getTag() == HERO_SPECIAL4_TAG)
			{
				back2(pos6, target);
			}
			tag = target->getTag();
			changeSpecial1 = true;
		}
		else if (target->getBoundingBox().intersectsRect(skill4_2->getBoundingBox()))
		{
			if (target->getTag() == HERO_SPECIAL1_TAG)
			{
				back2(pos3, target);
			}
			if (target->getTag() == HERO_SPECIAL2_TAG)
			{
				back2(pos4, target);
			}
			if (target->getTag() == HERO_SPECIAL3_TAG)
			{
				back2(pos5, target);
			}
			if (target->getTag() == HERO_SPECIAL4_TAG)
			{
				back2(pos6, target);
			}
			tag = target->getTag();
			changeSpecial2 = true;
		}
		else if (target->getBoundingBox().intersectsRect(skill5_2->getBoundingBox()))
		{
			if (target->getTag() == HERO_SPECIAL1_TAG)
			{
				back2(pos3, target);
			}
			if (target->getTag() == HERO_SPECIAL2_TAG)
			{
				back2(pos4, target);
			}
			if (target->getTag() == HERO_SPECIAL3_TAG)
			{
				back2(pos5, target);
			}
			if (target->getTag() == HERO_SPECIAL4_TAG)
			{
				back2(pos6, target);
			}
			tag = target->getTag();
			changeSpecial3 = true;
		}
		else if (target->getBoundingBox().intersectsRect(skill6_2->getBoundingBox()))
		{
			if (target->getTag() == HERO_SPECIAL1_TAG)
			{
				back2(pos3, target);
			}
			if (target->getTag() == HERO_SPECIAL2_TAG)
			{
				back2(pos4, target);
			}
			if (target->getTag() == HERO_SPECIAL3_TAG)
			{
				back2(pos5, target);
			}
			if (target->getTag() == HERO_SPECIAL4_TAG)
			{
				back2(pos6, target);
			}
			tag = target->getTag();
			changeSpecial4 = true;
		}
		else
		{
			if (target->getTag() == HERO_SPECIAL1_TAG)
			{
				back2(pos3, target);
			}
			if (target->getTag() == HERO_SPECIAL2_TAG)
			{
				back2(pos4, target);
			}
			if (target->getTag() == HERO_SPECIAL3_TAG)
			{
				back2(pos5, target);
			}
			if (target->getTag() == HERO_SPECIAL4_TAG)
			{
				back2(pos6, target);
			}
		}
	}
	if (target->getTag() == HERO_BUFF_TAG)
	{
		if (target->getBoundingBox().intersectsRect(skill7_2->getBoundingBox()))
		{
			back2(pos7, target);
			tag = target->getTag();
			changeBuff = true;
		}
		else
		{
			back2(pos7, target);
		}
	}


	if (target->getTag() == HERO2_NORMAL_TAG)
	{
		if (target->getBoundingBox().intersectsRect(skill1_2->getBoundingBox()))
		{
			back2(pos8, target);
			tag = target->getTag();
			changeNormal = true;
		}
		else
		{
			back2(pos8, target);
		}
	}
	if (target->getTag() == HERO2_BLINK_TAG)
	{
		if (target->getBoundingBox().intersectsRect(skill2_2->getBoundingBox()))
		{
			back2(pos9, target);
			tag = target->getTag();
			changeBlink = true;
		}
		else
		{
			back2(pos9, target);
		}
	}
	if (target->getTag() == HERO2_SPECIAL1_TAG || target->getTag() == HERO2_SPECIAL2_TAG || target->getTag() == HERO2_SPECIAL3_TAG || target->getTag() == HERO2_SPECIAL4_TAG)
	{
		if (target->getBoundingBox().intersectsRect(skill3_2->getBoundingBox()))
		{
			if (target->getTag() == HERO2_SPECIAL1_TAG)
			{
				back2(pos10, target);
			}
			if (target->getTag() == HERO2_SPECIAL2_TAG)
			{
				back2(pos11, target);
			}
			if (target->getTag() == HERO2_SPECIAL3_TAG)
			{
				back2(pos12, target);
			}
			if (target->getTag() == HERO2_SPECIAL4_TAG)
			{
				back2(pos13, target);
			}
			tag = target->getTag();
			changeSpecial1 = true;
		}
		else if (target->getBoundingBox().intersectsRect(skill4_2->getBoundingBox()))
		{
			if (target->getTag() == HERO2_SPECIAL1_TAG)
			{
				back2(pos10, target);
			}
			if (target->getTag() == HERO2_SPECIAL2_TAG)
			{
				back2(pos11, target);
			}
			if (target->getTag() == HERO2_SPECIAL3_TAG)
			{
				back2(pos12, target);
			}
			if (target->getTag() == HERO2_SPECIAL4_TAG)
			{
				back2(pos13, target);
			}
			tag = target->getTag();
			changeSpecial2 = true;
		}
		else if (target->getBoundingBox().intersectsRect(skill5_2->getBoundingBox()))
		{
			if (target->getTag() == HERO2_SPECIAL1_TAG)
			{
				back2(pos10, target);
			}
			if (target->getTag() == HERO2_SPECIAL2_TAG)
			{
				back2(pos11, target);
			}
			if (target->getTag() == HERO2_SPECIAL3_TAG)
			{
				back2(pos12, target);
			}
			if (target->getTag() == HERO2_SPECIAL4_TAG)
			{
				back2(pos13, target);
			}
			tag = target->getTag();
			changeSpecial3 = true;
		}
		else if (target->getBoundingBox().intersectsRect(skill6_2->getBoundingBox()))
		{
			if (target->getTag() == HERO2_SPECIAL1_TAG)
			{
				back2(pos10, target);
			}
			if (target->getTag() == HERO2_SPECIAL2_TAG)
			{
				back2(pos11, target);
			}
			if (target->getTag() == HERO2_SPECIAL3_TAG)
			{
				back2(pos12, target);
			}
			if (target->getTag() == HERO2_SPECIAL4_TAG)
			{
				back2(pos13, target);
			}
			tag = target->getTag();
			changeSpecial4 = true;
		}
		else
		{
			if (target->getTag() == HERO2_SPECIAL1_TAG)
			{
				back2(pos10, target);
			}
			if (target->getTag() == HERO2_SPECIAL2_TAG)
			{
				back2(pos11, target);
			}
			if (target->getTag() == HERO2_SPECIAL3_TAG)
			{
				back2(pos12, target);
			}
			if (target->getTag() == HERO2_SPECIAL4_TAG)
			{
				back2(pos13, target);
			}
		}
	}
	if (target->getTag() == HERO2_BUFF_TAG)
	{
		if (target->getBoundingBox().intersectsRect(skill7_2->getBoundingBox()))
		{
			back2(pos14, target);
			tag = target->getTag();
			changeBuff = true;
		}
		else
		{
			back2(pos14, target);
		}
	}

	if (target->getTag() == INIT_NORMAL_TAG)
	{
		if (target->getBoundingBox().intersectsRect(skill1_2->getBoundingBox()))
		{
			back2(pos15, target);
			tag = target->getTag();
			changeNormal = true;
		}
		else
		{
			back2(pos15, target);
		}
	}
	if (target->getTag() == INIT_BLINK_TAG)
	{
		if (target->getBoundingBox().intersectsRect(skill2_2->getBoundingBox()))
		{
			back2(pos16, target);
			tag = target->getTag();
			changeBlink = true;
		}
		else
		{
			back2(pos16, target);
		}
	}
	if (target->getTag() == INIT_SPECIAL1_TAG || target->getTag() == INIT_SPECIAL2_TAG || target->getTag() == INIT_SPECIAL3_TAG || target->getTag() == INIT_SPECIAL4_TAG)
	{
		if (target->getBoundingBox().intersectsRect(skill3_2->getBoundingBox()))
		{
			if (target->getTag() == INIT_SPECIAL1_TAG)
			{
				back2(pos17, target);
			}
			if (target->getTag() == INIT_SPECIAL2_TAG)
			{
				back2(pos18, target);
			}
			if (target->getTag() == INIT_SPECIAL3_TAG)
			{
				back2(pos19, target);
			}
			if (target->getTag() == INIT_SPECIAL4_TAG)
			{
				back2(pos20, target);
			}
			tag = target->getTag();
			changeSpecial1 = true;
		}
		else if (target->getBoundingBox().intersectsRect(skill4_2->getBoundingBox()))
		{
			if (target->getTag() == INIT_SPECIAL1_TAG)
			{
				back2(pos17, target);
			}
			if (target->getTag() == INIT_SPECIAL2_TAG)
			{
				back2(pos18, target);
			}
			if (target->getTag() == INIT_SPECIAL3_TAG)
			{
				back2(pos19, target);
			}
			if (target->getTag() == INIT_SPECIAL4_TAG)
			{
				back2(pos20, target);
			}
			tag = target->getTag();
			changeSpecial2 = true;
		}
		else if (target->getBoundingBox().intersectsRect(skill5_2->getBoundingBox()))
		{
			if (target->getTag() == INIT_SPECIAL1_TAG)
			{
				back2(pos17, target);
			}
			if (target->getTag() == INIT_SPECIAL2_TAG)
			{
				back2(pos18, target);
			}
			if (target->getTag() == INIT_SPECIAL3_TAG)
			{
				back2(pos19, target);
			}
			if (target->getTag() == INIT_SPECIAL4_TAG)
			{
				back2(pos20, target);
			}
			tag = target->getTag();
			changeSpecial3 = true;
		}
		else if (target->getBoundingBox().intersectsRect(skill6_2->getBoundingBox()))
		{
			if (target->getTag() == INIT_SPECIAL1_TAG)
			{
				back2(pos17, target);
			}
			if (target->getTag() == INIT_SPECIAL2_TAG)
			{
				back2(pos18, target);
			}
			if (target->getTag() == INIT_SPECIAL3_TAG)
			{
				back2(pos19, target);
			}
			if (target->getTag() == INIT_SPECIAL4_TAG)
			{
				back2(pos20, target);
			}
			tag = target->getTag();
			changeSpecial4 = true;
		}
		else
		{
			if (target->getTag() == INIT_SPECIAL1_TAG)
			{
				back2(pos17, target);
			}
			if (target->getTag() == INIT_SPECIAL2_TAG)
			{
				back2(pos18, target);
			}
			if (target->getTag() == INIT_SPECIAL3_TAG)
			{
				back2(pos19, target);
			}
			if (target->getTag() == INIT_SPECIAL4_TAG)
			{
				back2(pos20, target);
			}
		}
	}
	if (target->getTag() == INIT_BUFF_TAG)
	{
		if (target->getBoundingBox().intersectsRect(skill7_2->getBoundingBox()))
		{
			back2(pos21, target);
			tag = target->getTag();
			changeBuff = true;
		}
		else
		{
			back2(pos21, target);
		}
	}
}

void BackPack2::back2(Vec2 pos, Sprite * sprite)
{
	sprite->setPosition(pos);
}


#endif