#pragma once
#ifndef __BATTLE1UI_SCENE_H__
#define __BATTLE1UI_SCENE_H__
#include"Skill.h"
#include "Boss.h"
#include"Hero.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

class Battle1UI : public cocos2d::Layer
{
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
	CREATE_FUNC(Battle1UI);
};
#endif
