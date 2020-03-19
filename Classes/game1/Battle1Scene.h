#ifndef __BATTLE1_SCENE_H__
#define __BATTLE1_SCENE_H__
#include"Skill.h"
#include"Hero.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "Boss.h"
#include "SkillSprite.h"
#include "store1/store.h"
#include "Battle1UI.h"
using namespace std;
class Battle1 : public cocos2d::Layer
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
	Skill bossSkill;
	int mCDTime;
	int skillDemage[40];
	int skillMaxDemage[40];
	bool bossAttack = 0;
	bool keypressa, keypressw, keypressd, keypresss;
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
	void traceRemove(Ref*psender);
    // implement the "static create()" method manually
    CREATE_FUNC(Battle1);


	void Battle1::gotostore(cocos2d::Ref *pSender);

};
#endif

