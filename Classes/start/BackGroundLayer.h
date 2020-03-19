#ifndef _BACKGROUNDINSTARTLAYER_H_
#define _BACKGROUNDINSTARTLAYER_H_

#include "store1/store.h"
#include "BackGround.h"
#include "cocos2d.h"

bool BackGroundInStart::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//技能
	//普攻
	skill1 = Sprite::create("skill/skillbg.png");
	skill1->setPosition(Vec2(70, 50));
	skill1->setTag(HERO_NORMAL_TAG);
	this->addChild(skill1, 3);
	//闪烁
	skill2 = Sprite::create("skill/skillbg.png");
	skill2->setPosition(Vec2(70 * 2, 50));
	skill2->setTag(HERO_BLINK_TAG);
	this->addChild(skill2, 3);
	//特殊技能
	skill3 = Sprite::create("skill/skillbg.png");
	skill3->setPosition(Vec2(70 * 3, 50));
	skill3->setTag(HERO_SPECIAL1_TAG);
	this->addChild(skill3, 3);

	skill4 = Sprite::create("skill/skillbg.png");
	skill4->setPosition(Vec2(70 * 4, 50));
	skill4->setTag(HERO_SPECIAL2_TAG);
	this->addChild(skill4, 3);

	skill5 = Sprite::create("skill/skillbg.png");
	skill5->setPosition(Vec2(70 * 5, 50));
	skill5->setTag(HERO_SPECIAL3_TAG);
	this->addChild(skill5, 3);

	skill6 = Sprite::create("skill/skillbg.png");
	skill6->setPosition(Vec2(70 * 6, 50));
	skill6->setTag(HERO_SPECIAL4_TAG);
	this->addChild(skill6, 3);

	//被动
	skill7 = Sprite::create("skill/Buff1.png");
	skill7->setPosition(Vec2(70 * 7, visibleSize.height - 50));
	skill7->setTag(HERO_BUFF_TAG);
	this->addChild(skill7, 3);

	//技能上方的按键提示
	left = Sprite::create("skill/left.png");
	left->setPosition(Vec2(70, 80));
	left->setScale(0.5);
	this->addChild(left, 4);

	space = Sprite::create("skill/space.png");
	space->setPosition(Vec2(70 * 2, 80));
	space->setScale(0.5);
	this->addChild(space, 4);

	right = Sprite::create("skill/right.png");
	right->setPosition(Vec2(70 * 3, 80));
	right->setScale(0.5);
	this->addChild(right, 4);

	q = Sprite::create("skill/q.png");
	q->setPosition(Vec2(70 * 4, 80));
	q->setScale(0.5);
	this->addChild(q, 4);

	e = Sprite::create("skill/e.png");
	e->setPosition(Vec2(70 * 5, 80));
	e->setScale(0.5);
	this->addChild(e, 4);

	shift = Sprite::create("skill/shift.png");
	shift->setPosition(Vec2(70 * 6, 80));
	shift->setScale(0.5);
	this->addChild(shift, 4);

	//背包中的技能
	for (int i = 0; i < MAX_SKILL; i++)
	{
		__String * skillkey = __String::createWithFormat("skill_%d", i);
		auto sprite1 = Sprite::create("skill/hero_skill_bg.png");
		skillmap.insert(skillkey->getCString(), sprite1);
	}

	Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal1.png");
	skillmap.at("skill_0")->setTexture(texture);
	skillmap.at("skill_0")->setTag(INIT_NORMAL_TAG);

	texture = Director::getInstance()->getTextureCache()->addImage("skill/Blink1.png");
	skillmap.at("skill_1")->setTexture(texture);
	skillmap.at("skill_1")->setTag(INIT_BLINK_TAG);

	texture = Director::getInstance()->getTextureCache()->addImage("skill/Point1.png");
	skillmap.at("skill_2")->setTexture(texture);
	skillmap.at("skill_2")->setTag(INIT_SPECIAL1_TAG);

	texture = Director::getInstance()->getTextureCache()->addImage("skill/Round1.png");
	skillmap.at("skill_3")->setTexture(texture);
	skillmap.at("skill_3")->setTag(INIT_SPECIAL2_TAG);

	texture = Director::getInstance()->getTextureCache()->addImage("skill/Special1.png");
	skillmap.at("skill_4")->setTexture(texture);
	skillmap.at("skill_4")->setTag(INIT_SPECIAL3_TAG);

	texture = Director::getInstance()->getTextureCache()->addImage("skill/Follow1.png");
	skillmap.at("skill_5")->setTexture(texture);
	skillmap.at("skill_5")->setTag(INIT_SPECIAL4_TAG);

	texture = Director::getInstance()->getTextureCache()->addImage("skill/Buff1.png");
	skillmap.at("skill_6")->setTexture(texture);
	skillmap.at("skill_6")->setTag(INIT_BUFF_TAG);

	this->scheduleUpdate();

	return true;
}
void BackGroundInStart::update(float dt)
{
	if (changeNormal)
	{
		changePic(tag, 1);
		changeNormal = false;
	}
	if (changeBlink)
	{
		changePic(tag, 2);
		changeBlink = false;
	}
	if (changeSpecial1)
	{
		changePic(tag, 3);
		changeSpecial1 = false;
	}
	if (changeSpecial2)
	{
		changePic(tag, 4);
		changeSpecial2 = false;
	}
	if (changeSpecial3)
	{
		changePic(tag, 5);
		changeSpecial3 = false;
	}
	if (changeSpecial4)
	{
		changePic(tag, 6);
		changePic(tag, 7);
		changeSpecial4 = false;
	}
	if (changeBuff)
	{
		changePic(tag, 7);
		changeBuff = false;
	}
}

void BackGroundInStart::changePic(int tag, int index)
{
	if (tag == HERO_NORMAL_TAG && index == 1)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal1.png");
		skill1->setTexture(texture);
	}
	if (tag == HERO_BLINK_TAG && index == 2)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Blink1.png");
		skill2->setTexture(texture);
	}
	if (index == 3)
	{
		if (tag == HERO_SPECIAL1_TAG)
		{
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Point1.png");
			skill3->setTexture(texture);
		}
		if (tag == HERO_SPECIAL2_TAG)
		{
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Round1.png");
			skill3->setTexture(texture);
		}
		if (tag == HERO_SPECIAL3_TAG)
		{
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Special1.png");
			skill3->setTexture(texture);
		}
		if (tag == HERO_SPECIAL4_TAG)
		{
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Follow1.png");
			skill3->setTexture(texture);
		}
	}
	if (index == 4)
	{
		if (tag == HERO_SPECIAL1_TAG)
		{
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Point1.png");
			skill4->setTexture(texture);
		}
		if (tag == HERO_SPECIAL2_TAG)
		{
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Round1.png");
			skill4->setTexture(texture);
		}
		if (tag == HERO_SPECIAL3_TAG)
		{
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Special1.png");
			skill4->setTexture(texture);
		}
		if (tag == HERO_SPECIAL4_TAG)
		{
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Follow1.png");
			skill4->setTexture(texture);
		}
	}
	if (index == 5)
	{
		if (tag == HERO_SPECIAL1_TAG)
		{
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Point1.png");
			skill5->setTexture(texture);
		}
		if (tag == HERO_SPECIAL2_TAG)
		{
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Round1.png");
			skill5->setTexture(texture);
		}
		if (tag == HERO_SPECIAL3_TAG)
		{
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Special1.png");
			skill5->setTexture(texture);
		}
		if (tag == HERO_SPECIAL4_TAG)
		{
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Follow1.png");
			skill5->setTexture(texture);
		}
	}
	if (index == 6)
	{
		if (tag == HERO_SPECIAL1_TAG)
		{
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Point1.png");
			skill6->setTexture(texture);
		}
		if (tag == HERO_SPECIAL2_TAG)
		{
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Round1.png");
			skill6->setTexture(texture);
		}
		if (tag == HERO_SPECIAL3_TAG)
		{
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Special1.png");
			skill6->setTexture(texture);
		}
		if (tag == HERO_SPECIAL4_TAG)
		{
			Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Follow1.png");
			skill6->setTexture(texture);
		}
	}
	if (tag == HERO_BUFF_TAG && index == 7)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Buff1.png");
		skill7->setTexture(texture);
	}
}

#endif