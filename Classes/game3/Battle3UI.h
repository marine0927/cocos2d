#pragma once
#ifndef __BATTLE3UI_SCENE_H__
#define __BATTLE3UI_SCENE_H__
#include"Skill.h"
#include"Hero.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "Boss.h"

class Battle3UI : public cocos2d::Layer
{
	cocos2d::Sprite * skill1;
	cocos2d::Sprite * skill2;
	cocos2d::Sprite * skill3;
	cocos2d::Sprite * skill4;
	cocos2d::Sprite * skill5;
	cocos2d::Sprite * skill6;
	cocos2d::Sprite * skill7;
	cocos2d::Sprite * herostate;

	cocos2d::Sprite * q;
	cocos2d::Sprite * e;
	cocos2d::Sprite * space;
	cocos2d::Sprite * shift;
	cocos2d::Sprite * left;
	cocos2d::Sprite * right;


	Sprite * skillCDbutton[7];
	Sprite * skillCD;
	cocos2d::TMXTiledMap * tileMap;
	cocos2d::TMXLayer *collidable;
	Hero * hero;
	Hero * boss;
	bool WallContact;
	Vec2 MousePoint;
	int mCDTime;



public:
	void scheduleBlood(float delta);
	virtual bool init();
	// implement the "static create()" method manually
	CREATE_FUNC(Battle3UI);
};
#endif
