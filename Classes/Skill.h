#pragma once
#ifndef _SKILL_H_
#define _SKILL_H_
#include"cocos2d.h"
#include "SimpleAudioEngine.h"
#include "game1/Battle1UI.h"
#include "SkillSprite.h"
#include <math.h>
USING_NS_CC;
using namespace std;



class Skill : public cocos2d::CCNode
{
public:
	void traceRemove(Ref * psender);
	float pi = 3.141592654;
	void skillrelease(int skillindex, cocos2d::Layer*layer, Vec2 mousePoint);
	Skill();
	void skillCDstart(CCNode *node);
	void skillCoolDown(int skillposition, int skillindex);
	void traceSkill(CCNode *node);
	void BossSkillOver(Ref*psender);
	Vec2 fireballoffset[6];
	int skillDemage[40];
	bool skillCDover[40];
	//virtual ~SkillButton();

	///* 创建一个SkillButton对象 */
	//static SkillButton* createSkillButton(float cdTime,
	//	const char* stencil_file_name,
	//	const char* button_normal_name,
	//	const char* button_click_name,
	//	Hero*hero);

	///* CD时间设置 */
	//void    setCDTime(float time) { mCDTime = time; }
	//float   getCDTime() const { return mCDTime; }
	//
	///* 技能按钮点击回调 */
	//void    skillClickCallBack(cocos2d::CCObject* obj);

	///* 技能冷却完毕回调 */
	//void    skillCoolDownCallBack(cocos2d::CCNode* node);

	///* 读取英雄技能标签 */
	//void getHeroSkillLabel(Hero * hero)
	//{
	//	SkillLabel = hero->Skill[0];
	//}
	///* 得到英雄 */
	//void getHero(Hero *hero)
	//{
	//	this->hero = hero;
	//}
private:
	
	float skillCDtime[40];

	ProgressTimer * mProgressTimer[7];
	bool skillFirstCreate;
	Sprite* progressSprite;// 技能蒙版
	SkillSprite* surrounding1[6];
	SkillSprite* surrounding2[3];
	SkillSprite* fireball[6];
	void skillOver(Ref *psender);
//	/** 初始化 */
//	bool    init(float cdTime, const char* stencil_file_name, const char* button_normal_name, const char* button_click_name, Hero *hero);
//
//public:
//	cocos2d::CCMenuItemImage*   mItemSkill;     // 技能按钮
//	cocos2d::CCMenu*            mMenuSkill;     // 技能按钮所在menu
//	cocos2d::CCSprite*          mStencil;       // 蒙板精灵,黑色半透明(这个是为了显示一个冷却计时效果)
//	cocos2d::CCProgressTimer*   mProgressTimer; // 时间进度条精灵(360度旋转)
//	float                       mCDTime;          // CD时间
//	int SkillLabel;//技能标签
//	int SkillPos;//技能栏位置
//};
	
};
#endif
