#ifndef _BACKPACKLAYER_H_
#define _BACKPACKLAYER_H_

#include "store.h"
#include "Backpack.h"
#include "cocos2d.h"

extern int x = 0;
extern int y = 0;

bool BackPack::init()
{
	if (!Layer::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

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

	for (int i = 0; i < 7; i++)
	{
		__String * skillkey = __String::createWithFormat("skill_%d", i);

		skillmap.at(skillkey->getCString())->setPosition(Vec2(origin.x + visibleSize.width / 2 + 80 + x, 700 - y));

		this->addChild(skillmap.at(skillkey->getCString()), 3);
		x += 80;
		if ((800 + x) > 1200)
		{
			x = 0;
			y += 80;
		}
	}
	pos1 = skillmap.at("skill_0")->getPosition();
	pos2 = skillmap.at("skill_1")->getPosition();
	pos3 = skillmap.at("skill_2")->getPosition();
	pos4 = skillmap.at("skill_3")->getPosition();
	pos5 = skillmap.at("skill_4")->getPosition();
	pos6 = skillmap.at("skill_5")->getPosition();
	pos7 = skillmap.at("skill_6")->getPosition();

	//商店内的技能

	skill1_1 = Sprite::create("skill/Normal2.png");
	skill1_1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 100, origin.y + visibleSize.height / 2 + 100));
	this->addChild(skill1_1, 3, NORMAL_TAG);

	skill2_1 = Sprite::create("skill/Blink2.png");
	skill2_1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 240, origin.y + visibleSize.height / 2 + 200));
	this->addChild(skill2_1, 3, BLINK_TAG);

	skill3_1 = Sprite::create("skill/Point2.png");
	skill3_1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 100, origin.y + visibleSize.height / 2 - 100));
	this->addChild(skill3_1, 3, POINT_TAG);

	skill4_1 = Sprite::create("skill/Round2.png");
	skill4_1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 240, origin.y + visibleSize.height / 2 - 200));
	this->addChild(skill4_1, 3, ROUND_TAG);

	skill5_1 = Sprite::create("skill/Special2.png");
	skill5_1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 480, origin.y + visibleSize.height / 2 + 160));
	this->addChild(skill5_1, 3, AIM_TAG);

	skill6_1 = Sprite::create("skill/Follow2.png");
	skill6_1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 480, origin.y + visibleSize.height / 2 - 160));
	this->addChild(skill6_1, 3, FOLLOW_TAG);

	skill7_1 = Sprite::create("skill/Buff2.png");
	skill7_1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 300, origin.y + visibleSize.height / 2));
	this->addChild(skill7_1, 3, BUFF_TAG);



	skill8_1 = Sprite::create("skill/shadow/Normal3.png");
	skill8_1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 200, origin.y + visibleSize.height / 2 + 100));
	skill8_1->setScale(0.5);
	this->addChild(skill8_1, 3);

	skill9_1 = Sprite::create("skill/shadow/Blink3.png");
	skill9_1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 340, origin.y + visibleSize.height / 2 + 200));
	skill9_1->setScale(0.5);
	this->addChild(skill9_1, 3);

	skill10_1 = Sprite::create("skill/shadow/Point3.png");
	skill10_1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 200, origin.y + visibleSize.height / 2 - 100));
	skill10_1->setScale(0.5);
	this->addChild(skill10_1, 3);

	skill11_1 = Sprite::create("skill/shadow/Round3.png");
	skill11_1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 340, origin.y + visibleSize.height / 2 - 200));
	skill11_1->setScale(0.5);
	this->addChild(skill11_1, 3);

	skill12_1 = Sprite::create("skill/shadow/Special3.png");
	skill12_1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 480, origin.y + visibleSize.height / 2 + 260));
	skill12_1->setScale(0.5);
	this->addChild(skill12_1, 3);

	skill13_1 = Sprite::create("skill/shadow/Follow3.png");
	skill13_1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 480, origin.y + visibleSize.height / 2 -60));
	skill13_1->setScale(0.5);
	this->addChild(skill13_1, 3);

	skill14_1 = Sprite::create("skill/shadow/Buff3.png");
	skill14_1->setPosition(Vec2(origin.x + visibleSize.width / 2 - 400, origin.y + visibleSize.height / 2));
	skill14_1->setScale(0.5);
	this->addChild(skill14_1, 3);

	

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

	this->scheduleUpdate();

	return true;
}
bool addlis = true;
void BackPack::update(float dt)
{
	auto draglistener = EventListenerTouchOneByOne::create();
	draglistener->setSwallowTouches(true);
	draglistener->onTouchBegan = CC_CALLBACK_2(BackPack::dragbegin, this);
	draglistener->onTouchMoved = CC_CALLBACK_2(BackPack::dragmove, this);
	draglistener->onTouchEnded = CC_CALLBACK_2(BackPack::dragend, this);

	EventDispatcher * drageventDispatcher = Director::getInstance()->getEventDispatcher();

	if (addlis)
	{
		addlis = false;
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
		drageventDispatcher->addEventListenerWithSceneGraphPriority(draglistener->clone(), getChildByTag(HERO_NORMAL_TAG));
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
	if (showShop)
	{
		BackPack::setScale(1.0);
	}
	else
	{
		BackPack::setScale(0.0);
	}
}

void BackPack::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();


	//鼠标事件
	auto mouseListener = EventListenerMouse::create();
	mouseListener->onMouseMove = CC_CALLBACK_1(BackPack::mouseMove, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, getChildByTag(NORMAL_TAG));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener->clone(), getChildByTag(BLINK_TAG));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener->clone(), getChildByTag(POINT_TAG));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener->clone(), getChildByTag(ROUND_TAG));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener->clone(), getChildByTag(AIM_TAG));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener->clone(), getChildByTag(FOLLOW_TAG));
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener->clone(), getChildByTag(BUFF_TAG));


	//触摸事件
	auto touchlistener = EventListenerTouchOneByOne::create();
	// 设置是否吞没事件，在 onTouchBegan 方法返回 true 时吞没
	touchlistener->setSwallowTouches(true);
	touchlistener->onTouchBegan = CC_CALLBACK_2(BackPack::touchbegin, this);
	touchlistener->onTouchEnded = CC_CALLBACK_2(BackPack::touchend, this);

	EventDispatcher * toucheventDispatcher = Director::getInstance()->getEventDispatcher();
	toucheventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener, getChildByTag(NORMAL_TAG));
	toucheventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener->clone(), getChildByTag(BLINK_TAG));
	toucheventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener->clone(), getChildByTag(POINT_TAG));
	toucheventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener->clone(), getChildByTag(ROUND_TAG));
	toucheventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener->clone(), getChildByTag(AIM_TAG));
	toucheventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener->clone(), getChildByTag(FOLLOW_TAG));
	toucheventDispatcher->addEventListenerWithSceneGraphPriority(touchlistener->clone(), getChildByTag(BUFF_TAG));

	//拖拽事件

}

void BackPack::onExitTransitionDidStart()
{
	Layer::onExitTransitionDidStart();
	this->removeAllChildren();
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
}

void BackPack::mouseMove(Event *event)//判断鼠标位置
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
bool BackPack::touchbegin(Touch* touch, Event *event)
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
void BackPack::touchend(Touch* touch, Event *event)
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
		if (target->getTag() == NORMAL_TAG)
		{
			price = 100;
		}
		if (target->getTag() == BLINK_TAG)
		{
			price = 150;
		}
		if (target->getTag() == POINT_TAG)
		{
			price = 200;
		}
		if (target->getTag() == ROUND_TAG)
		{
			price = 250;
		}
		if (target->getTag() == AIM_TAG)
		{
			price = 300;
		}
		if (target->getTag() == FOLLOW_TAG)
		{
			price = 350;
		}
		if (target->getTag() == BUFF_TAG)
		{
			price = 400;
		}
		if (gold >= price) {
			gold -= price;
			__String * money = __String::createWithFormat("%d", gold);
			const char * golden = money->getCString();
			golds->setString(golden);
			addskill(target);
		}
	}
	else
	{
		target->runAction(ScaleTo::create(0.06f, 1.0f));
	}

}
bool add1 = true, add2 = true, add3 = true, add4 = true, add5 = true, add6 = true, add7 = true;
void BackPack::addskill(Sprite * sprite)//往背包中添加技能
{
	if (sprite->getTag() == NORMAL_TAG)
	{
		if (add1)
		{
			add1 = false;
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal2.png");
			skillmap.at("skill_7")->setTexture(texture);
			skillmap.at("skill_7")->setPosition(Vec2(origin.x + visibleSize.width / 2 + 80 + x, 700 - y));
			this->addChild(skillmap.at("skill_7"), 3, HERO_NORMAL_TAG);
			pos8 = skillmap.at("skill_7")->getPosition();
			normal1 = true;
			x += 80;
		}
	}
	if (sprite->getTag() == BLINK_TAG)
	{
		if (add2)
		{
			add2 = false;
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Blink2.png");
			skillmap.at("skill_8")->setTexture(texture);
			skillmap.at("skill_8")->setPosition(Vec2(origin.x + visibleSize.width / 2 + 80 + x, 700 - y));
			skillmap.at("skill_8")->setTag(HERO_BLINK_TAG);
			this->addChild(skillmap.at("skill_8"), 3, HERO_BLINK_TAG);
			pos9 = skillmap.at("skill_8")->getPosition();
			blink1 = true;
			x += 80;
		}
		
	}
	if (sprite->getTag() == POINT_TAG)
	{
		if (add3)
		{
			add3 = false;
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Point2.png");
			skillmap.at("skill_9")->setTexture(texture);
			skillmap.at("skill_9")->setPosition(Vec2(origin.x + visibleSize.width / 2 + 80 + x, 700 - y));
			this->addChild(skillmap.at("skill_9"), 3, HERO_SPECIAL1_TAG);
			pos10 = skillmap.at("skill_9")->getPosition();
			special11 = true;
			x += 80;
		}
	}
	if (sprite->getTag() == ROUND_TAG)
	{
		if (add4)
		{
			add4 = false;
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Round2.png");
			skillmap.at("skill_10")->setTexture(texture);
			skillmap.at("skill_10")->setPosition(Vec2(origin.x + visibleSize.width / 2 + 80 + x, 700 - y));
			this->addChild(skillmap.at("skill_10"), 3, HERO_SPECIAL2_TAG);
			pos11 = skillmap.at("skill_10")->getPosition();
			special21 = true;
			x += 80;
		}
	}
	if (sprite->getTag() == AIM_TAG)
	{
		if (add5)
		{
			add5 = false;
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Special2.png");
			skillmap.at("skill_11")->setTexture(texture);
			skillmap.at("skill_11")->setPosition(Vec2(origin.x + visibleSize.width / 2 + 80 + x, 700 - y));
			this->addChild(skillmap.at("skill_11"), 3, HERO_SPECIAL3_TAG);
			pos12 = skillmap.at("skill_11")->getPosition();
			special31 = true;
			x += 80;
		}
	}
	if (sprite->getTag() == FOLLOW_TAG)
	{
		if (add6)
		{
			add6 = false;
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Follow2.png");
			skillmap.at("skill_12")->setTexture(texture);
			skillmap.at("skill_12")->setPosition(Vec2(origin.x + visibleSize.width / 2 + 80 + x, 700 - y));
			this->addChild(skillmap.at("skill_12"), 3, HERO_SPECIAL4_TAG);
			pos13 = skillmap.at("skill_12")->getPosition();
			special41 = true;
			x += 80;
		}
	}
		
	if (sprite->getTag() == BUFF_TAG)
	{
		if (add7)
		{
			add7 = false;
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Buff2.png");
			skillmap.at("skill_13")->setTexture(texture);
			skillmap.at("skill_13")->setPosition(Vec2(origin.x + visibleSize.width / 2 + 80 + x, 700 - y));
			this->addChild(skillmap.at("skill_13"), 3, HERO_BUFF_TAG);
			pos14 = skillmap.at("skill_13")->getPosition();
			buff1 = true;
			x += 80;
		}
	}

	
	if ((800 + x) > 1150)
	{
		x = 0;
		y += 80;
	}
}

bool BackPack::dragbegin(cocos2d::Touch* touch, cocos2d::Event *event)
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
		if (target->getTag() == HERO_NORMAL_TAG || target->getTag() == INIT_NORMAL_TAG)
		{
			skill1_2->setOpacity(0);
		}
		if (target->getTag() == HERO_BLINK_TAG || target->getTag() == INIT_BLINK_TAG)
		{
			skill2_2->setOpacity(0);
		}
		if (target->getTag() == HERO_SPECIAL1_TAG || target->getTag() == HERO_SPECIAL2_TAG || target->getTag() == HERO_SPECIAL3_TAG || target->getTag() == HERO_SPECIAL4_TAG ||target->getTag() == INIT_SPECIAL1_TAG || target->getTag() == INIT_SPECIAL2_TAG || target->getTag() == INIT_SPECIAL3_TAG || target->getTag() == INIT_SPECIAL4_TAG)
		{
			skill3_2->setOpacity(0);
			skill4_2->setOpacity(0);
			skill5_2->setOpacity(0);
			skill6_2->setOpacity(0);
		}
		if (target->getTag() == HERO_BUFF_TAG || target->getTag() == INIT_BUFF_TAG)
		{
			skill7_2->setOpacity(0);
		}
		return true;
	}
	return false;
}
void BackPack::dragmove(cocos2d::Touch* touch, cocos2d::Event *event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	target->setPosition(target->getPosition() + touch->getDelta());
}
void BackPack::dragend(cocos2d::Touch* touch, cocos2d::Event *event)
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
	if (target->getTag() == INIT_NORMAL_TAG)
	{
		if (target->getBoundingBox().intersectsRect(skill1_2->getBoundingBox()))
		{
			back(pos1, target);
			tag = target->getTag();
			changeNormal = true;
		}
		else
		{
			back(pos1, target);
		}
	}
	if (target->getTag() == INIT_BLINK_TAG)
	{
		if (target->getBoundingBox().intersectsRect(skill2_2->getBoundingBox()))
		{
			back(pos2, target);
			tag = target->getTag();
			changeBlink = true;
		}
		else
		{
			back(pos2, target);
		}
	}
	if (target->getTag() == INIT_SPECIAL1_TAG || target->getTag() == INIT_SPECIAL2_TAG || target->getTag() == INIT_SPECIAL3_TAG || target->getTag() == INIT_SPECIAL4_TAG)
	{
		if (target->getBoundingBox().intersectsRect(skill3_2->getBoundingBox()))
		{
			if (target->getTag() == INIT_SPECIAL1_TAG)
			{
				back(pos3, target);
			}
			if (target->getTag() == INIT_SPECIAL2_TAG)
			{
				back(pos4, target);
			}
			if (target->getTag() == INIT_SPECIAL3_TAG)
			{
				back(pos5, target);
			}
			if (target->getTag() == INIT_SPECIAL4_TAG)
			{
				back(pos6, target);
			}
			tag = target->getTag();
			changeSpecial1 = true;
		}
		else if (target->getBoundingBox().intersectsRect(skill4_2->getBoundingBox()))
		{
			if (target->getTag() == INIT_SPECIAL1_TAG)
			{
				back(pos3, target);
			}
			if (target->getTag() == INIT_SPECIAL2_TAG)
			{
				back(pos4, target);
			}
			if (target->getTag() == INIT_SPECIAL3_TAG)
			{
				back(pos5, target);
			}
			if (target->getTag() == INIT_SPECIAL4_TAG)
			{
				back(pos6, target);
			}
			tag = target->getTag();
			changeSpecial2 = true;
		}
		else if (target->getBoundingBox().intersectsRect(skill5_2->getBoundingBox()))
		{
			if (target->getTag() == INIT_SPECIAL1_TAG)
			{
				back(pos3, target);
			}
			if (target->getTag() == INIT_SPECIAL2_TAG)
			{
				back(pos4, target);
			}
			if (target->getTag() == INIT_SPECIAL3_TAG)
			{
				back(pos5, target);
			}
			if (target->getTag() == INIT_SPECIAL4_TAG)
			{
				back(pos6, target);
			}
			tag = target->getTag();
			changeSpecial3 = true;
		}
		else if (target->getBoundingBox().intersectsRect(skill6_2->getBoundingBox()))
		{
			if (target->getTag() == INIT_SPECIAL1_TAG)
			{
				back(pos3, target);
			}
			if (target->getTag() == INIT_SPECIAL2_TAG)
			{
				back(pos4, target);
			}
			if (target->getTag() == INIT_SPECIAL3_TAG)
			{
				back(pos5, target);
			}
			if (target->getTag() == INIT_SPECIAL4_TAG)
			{
				back(pos6, target);
			}
			tag = target->getTag();
			changeSpecial4 = true;
		}
		else
		{
			if (target->getTag() == INIT_SPECIAL1_TAG)
			{
				back(pos3, target);
			}
			if (target->getTag() == INIT_SPECIAL2_TAG)
			{
				back(pos4, target);
			}
			if (target->getTag() == INIT_SPECIAL3_TAG)
			{
				back(pos5, target);
			}
			if (target->getTag() == INIT_SPECIAL4_TAG)
			{
				back(pos6, target);
			}
		}
	}
	if (target->getTag() == INIT_BUFF_TAG)
	{
		if (target->getBoundingBox().intersectsRect(skill7_2->getBoundingBox()))
		{
			back(pos7, target);
			tag = target->getTag();
			changeBuff = true;
		}
		else
		{
			back(pos7, target);
		}
	}


	if (target->getTag() == HERO_NORMAL_TAG)
	{
		if (target->getBoundingBox().intersectsRect(skill1_2->getBoundingBox()))
		{
			back(pos8, target);
			tag = target->getTag();
			changeNormal = true;
		}
		else
		{
			back(pos8, target);
		}
	}
	if (target->getTag() == HERO_BLINK_TAG)
	{
		if (target->getBoundingBox().intersectsRect(skill2_2->getBoundingBox()))
		{
			back(pos9, target);
			tag = target->getTag();
			changeBlink = true;
		}
		else
		{
			back(pos9, target);
		}
	}
	if (target->getTag() == HERO_SPECIAL1_TAG || target->getTag() == HERO_SPECIAL2_TAG || target->getTag() == HERO_SPECIAL3_TAG || target->getTag() == HERO_SPECIAL4_TAG)
	{
		if (target->getBoundingBox().intersectsRect(skill3_2->getBoundingBox()))
		{
			if (target->getTag() == HERO_SPECIAL1_TAG)
			{
				back(pos10, target);
			}
			if (target->getTag() == HERO_SPECIAL2_TAG)
			{
				back(pos11, target);
			}
			if (target->getTag() == HERO_SPECIAL3_TAG)
			{
				back(pos12, target);
			}
			if (target->getTag() == HERO_SPECIAL4_TAG)
			{
				back(pos13, target);
			}
			tag = target->getTag();
			changeSpecial1 = true;
		}
		else if (target->getBoundingBox().intersectsRect(skill4_2->getBoundingBox()))
		{
			if (target->getTag() == HERO_SPECIAL1_TAG)
			{
				back(pos10, target);
			}
			if (target->getTag() == HERO_SPECIAL2_TAG)
			{
				back(pos11, target);
			}
			if (target->getTag() == HERO_SPECIAL3_TAG)
			{
				back(pos12, target);
			}
			if (target->getTag() == HERO_SPECIAL4_TAG)
			{
				back(pos13, target);
			}
			tag = target->getTag();
			changeSpecial2 = true;
		}
		else if (target->getBoundingBox().intersectsRect(skill5_2->getBoundingBox()))
		{
			if (target->getTag() == HERO_SPECIAL1_TAG)
			{
				back(pos10, target);
			}
			if (target->getTag() == HERO_SPECIAL2_TAG)
			{
				back(pos11, target);
			}
			if (target->getTag() == HERO_SPECIAL3_TAG)
			{
				back(pos12, target);
			}
			if (target->getTag() == HERO_SPECIAL4_TAG)
			{
				back(pos13, target);
			}
			tag = target->getTag();
			changeSpecial3 = true;
		}
		else if (target->getBoundingBox().intersectsRect(skill6_2->getBoundingBox()))
		{
			if (target->getTag() == HERO_SPECIAL1_TAG)
			{
				back(pos10, target);
			}
			if (target->getTag() == HERO_SPECIAL2_TAG)
			{
				back(pos11, target);
			}
			if (target->getTag() == HERO_SPECIAL3_TAG)
			{
				back(pos12, target);
			}
			if (target->getTag() == HERO_SPECIAL4_TAG)
			{
				back(pos13, target);
			}
			tag = target->getTag();
			changeSpecial4 = true;
		}
		else
		{
			if (target->getTag() == HERO_SPECIAL1_TAG)
			{
				back(pos10, target);
			}
			if (target->getTag() == HERO_SPECIAL2_TAG)
			{
				back(pos11, target);
			}
			if (target->getTag() == HERO_SPECIAL3_TAG)
			{
				back(pos12, target);
			}
			if (target->getTag() == HERO_SPECIAL4_TAG)
			{
				back(pos13, target);
			}
		}
	}
	if (target->getTag() == HERO_BUFF_TAG)
	{
		if (target->getBoundingBox().intersectsRect(skill7_2->getBoundingBox()))
		{
			back(pos14, target);
			tag = target->getTag();
			changeBuff = true;
		}
		else
		{
			back(pos14, target);
		}
	}
}

void BackPack::back(Vec2 pos, Sprite * sprite)
{
	sprite->setPosition(pos);
}


#endif