#ifndef _BACKGROUNDINGAMELAYER2_H_
#define _BACKGROUNDINGAMELAYER2_H_

#include "store1/store.h"
#include "BackGround.h"
#include "cocos2d.h"

bool BackGroundInGame2::init()
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
	skill7 = Sprite::create("skill/skillbg.png");
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

	//状态
	herostate = Sprite::create("state/blood.png");
	herostate->setPosition(Vec2(0, visibleSize.height - 100));
	herostate->setAnchorPoint(Vec2(0, 0));
	this->addChild(herostate, 3);

	this->scheduleUpdate();

	return true;
}

void BackGroundInGame2::update(float dt)
{
	
}

void BackGroundInGame2::onEnter()
{
	Layer::onEnter();

	if (tagin1 == INIT_NORMAL_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal1.png");
		skill1->setTexture(texture);
	}
	else if (tagin1 == HERO_NORMAL_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Normal2.png");
		skill1->setTexture(texture);
	}

	if (tagin2 == INIT_BLINK_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Blink1.png");
		skill2->setTexture(texture);
	}
	else if (tagin2 == HERO_BLINK_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Blink2.png");
		skill2->setTexture(texture);
	}

	if (tagin3 == INIT_SPECIAL1_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Point1.png");
		skill3->setTexture(texture);
	}
	else if (tagin3 == INIT_SPECIAL2_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Round1.png");
		skill3->setTexture(texture);
	}
	else if (tagin3 == INIT_SPECIAL3_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Special1.png");
		skill3->setTexture(texture);
	}
	else if (tagin3 == INIT_SPECIAL4_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Follow1.png");
		skill3->setTexture(texture);
	}
	else if (tagin3 == HERO_SPECIAL1_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Point2.png");
		skill3->setTexture(texture);
	}
	else if (tagin3 == HERO_SPECIAL2_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Round2.png");
		skill3->setTexture(texture);
	}
	else if (tagin3 == HERO_SPECIAL3_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Special2.png");
		skill3->setTexture(texture);
	}
	else if (tagin3 == HERO_SPECIAL4_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Follow2.png");
		skill3->setTexture(texture);
	}

	if (tagin4 == INIT_SPECIAL1_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Point1.png");
		skill4->setTexture(texture);
	}
	else if (tagin4 == INIT_SPECIAL2_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Round1.png");
		skill4->setTexture(texture);
	}
	else if (tagin4 == INIT_SPECIAL3_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Special1.png");
		skill4->setTexture(texture);
	}
	else if (tagin4 == INIT_SPECIAL4_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Follow1.png");
		skill4->setTexture(texture);
	}
	else if (tagin4 == HERO_SPECIAL1_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Point2.png");
		skill4->setTexture(texture);
	}
	else if (tagin4 == HERO_SPECIAL2_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Round2.png");
		skill4->setTexture(texture);
	}
	else if (tagin4 == HERO_SPECIAL3_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Special2.png");
		skill4->setTexture(texture);
	}
	else if (tagin4 == HERO_SPECIAL4_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Follow2.png");
		skill4->setTexture(texture);
	}

	if (tagin5 == INIT_SPECIAL1_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Point1.png");
		skill5->setTexture(texture);
	}
	else if (tagin5 == INIT_SPECIAL2_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Round1.png");
		skill5->setTexture(texture);
	}
	else if (tagin5 == INIT_SPECIAL3_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Special1.png");
		skill5->setTexture(texture);
	}
	else if (tagin5 == INIT_SPECIAL4_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Follow1.png");
		skill5->setTexture(texture);
	}
	else if (tagin5 == HERO_SPECIAL1_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Point2.png");
		skill5->setTexture(texture);
	}
	else if (tagin5 == HERO_SPECIAL2_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Round2.png");
		skill5->setTexture(texture);
	}
	else if (tagin5 == HERO_SPECIAL3_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Special2.png");
		skill5->setTexture(texture);
	}
	else if (tagin5 == HERO_SPECIAL4_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Follow2.png");
		skill5->setTexture(texture);
	}

	if (tagin6 == INIT_SPECIAL1_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Point1.png");
		skill6->setTexture(texture);
	}
	else if (tagin6 == INIT_SPECIAL2_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Round1.png");
		skill6->setTexture(texture);
	}
	else if (tagin6 == INIT_SPECIAL3_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Special1.png");
		skill6->setTexture(texture);
	}
	else if (tagin6 == INIT_SPECIAL4_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Follow1.png");
		skill6->setTexture(texture);
	}
	else if (tagin6 == HERO_SPECIAL1_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Point2.png");
		skill6->setTexture(texture);
	}
	else if (tagin6 == HERO_SPECIAL2_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Round2.png");
		skill6->setTexture(texture);
	}
	else if (tagin6 == HERO_SPECIAL3_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Special2.png");
		skill6->setTexture(texture);
	}
	else if (tagin6 == HERO_SPECIAL4_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Follow2.png");
		skill6->setTexture(texture);
	}

	if (tagin7 == INIT_BUFF_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Buff1.png");
		skill7->setTexture(texture);
	}
	else if (tagin7 == HERO_BUFF_TAG)
	{
		Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("skill/Buff2.png");
		skill7->setTexture(texture);
	}
}
#endif