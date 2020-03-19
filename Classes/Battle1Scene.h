#ifndef __BATTLE1_SCENE_H__
#define __BATTLE1_SCENE_H__
#include"Skill.h"
#include"Hero.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "Boss.h"
#include "SkillSprite.h"
#include <iostream>
using namespace std;
class Battle1 : public cocos2d::Layer
{
	Sprite * skillCDbutton[7];
	Sprite * skillCD;
	Sprite * tileMap;
	Hero * hero;
	Boss * boss;
	bool WallContact;
	Vec2 MousePoint;
	Skill heroSkill;
	int mCDTime;
	int skillDemage[20];
	int skillMaxDemage[20];
	bool bossAttack=0;
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
	void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	void keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	void mouseDown(cocos2d::EventMouse * event);
	void mouseMove(cocos2d::EventMouse * event);
    // a selector callback
	virtual void update(float dt);
	void setViewpointCenter(cocos2d::Vec2 position);
	void onEnter();
	bool ContactBegin(PhysicsContact& contact);
	bool ContactPreSolve(PhysicsContact& contact, PhysicsContactPreSolve& solve);
	void ContactPostSolve(PhysicsContact& contact, const PhysicsContactPostSolve& solve);
	void ContactSeparate(PhysicsContact& contact);
	void setheroposition();
	void setheroframe();
	void BloodControl(float dt);
	void BossAttack(float dt);
	void traceSkill(float dt);
    // implement the "static create()" method manually
    CREATE_FUNC(Battle1);
};
#endif

