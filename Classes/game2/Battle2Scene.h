#ifndef __BATTLE2_SCENE_H__
#define __BATTLE2_SCENE_H__
#include"Skill.h"
#include"Hero.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "Boss.h"
#include "SkillSprite.h"
#include "store2/store2.h"
#include "Battle2UI.h"

class Battle2 : public cocos2d::Layer
{
	cocos2d::Sprite * Door;//胜利后的传送点
	Sprite * skillCDbutton[7];
	Sprite * skillCD;
	cocos2d::Sprite * tileMap;
	Hero * hero;
	Boss * boss;
	bool WallContact;
	Vec2 MousePoint;
	Skill heroSkill;
	int mCDTime;
	int skillDemage[20];
	int skillMaxDemage[20];
	bool bossAttack = 0;
public:
    static cocos2d::Scene* createScene();
	void scheduleSkill(cocos2d::CCObject* obj);
	void skillCoolDown(CCNode* node);
    virtual bool init();
	void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	void keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	void mouseDown(cocos2d::EventMouse * event);
	void mouseMove(cocos2d::EventMouse * event);
    // a selector callback
	virtual void update(float dt);
	void setViewpointCenter(cocos2d::Vec2 position);
	void onEnter();
	void BloodControl(float dt);
	void BossAttack(float dt);
	void traceSkill(float dt);
	bool ContactBegin(PhysicsContact& contact);
	bool ContactPreSolve(PhysicsContact& contact, PhysicsContactPreSolve& solve);
	void ContactPostSolve(PhysicsContact& contact, const PhysicsContactPostSolve& solve);
	void ContactSeparate(PhysicsContact& contact);
	cocos2d::Vec2 tileCoordFromPosition(cocos2d::Vec2 position);
	void setheroposition();
	void setheroframe();
	void gotostore(Ref * pSender);
    // implement the "static create()" method manually
    CREATE_FUNC(Battle2);

};
#endif

