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

	///* ����һ��SkillButton���� */
	//static SkillButton* createSkillButton(float cdTime,
	//	const char* stencil_file_name,
	//	const char* button_normal_name,
	//	const char* button_click_name,
	//	Hero*hero);

	///* CDʱ������ */
	//void    setCDTime(float time) { mCDTime = time; }
	//float   getCDTime() const { return mCDTime; }
	//
	///* ���ܰ�ť����ص� */
	//void    skillClickCallBack(cocos2d::CCObject* obj);

	///* ������ȴ��ϻص� */
	//void    skillCoolDownCallBack(cocos2d::CCNode* node);

	///* ��ȡӢ�ۼ��ܱ�ǩ */
	//void getHeroSkillLabel(Hero * hero)
	//{
	//	SkillLabel = hero->Skill[0];
	//}
	///* �õ�Ӣ�� */
	//void getHero(Hero *hero)
	//{
	//	this->hero = hero;
	//}
private:
	
	float skillCDtime[40];

	ProgressTimer * mProgressTimer[7];
	bool skillFirstCreate;
	Sprite* progressSprite;// �����ɰ�
	SkillSprite* surrounding1[6];
	SkillSprite* surrounding2[3];
	SkillSprite* fireball[6];
	void skillOver(Ref *psender);
//	/** ��ʼ�� */
//	bool    init(float cdTime, const char* stencil_file_name, const char* button_normal_name, const char* button_click_name, Hero *hero);
//
//public:
//	cocos2d::CCMenuItemImage*   mItemSkill;     // ���ܰ�ť
//	cocos2d::CCMenu*            mMenuSkill;     // ���ܰ�ť����menu
//	cocos2d::CCSprite*          mStencil;       // �ɰ徫��,��ɫ��͸��(�����Ϊ����ʾһ����ȴ��ʱЧ��)
//	cocos2d::CCProgressTimer*   mProgressTimer; // ʱ�����������(360����ת)
//	float                       mCDTime;          // CDʱ��
//	int SkillLabel;//���ܱ�ǩ
//	int SkillPos;//������λ��
//};
	
};
#endif
