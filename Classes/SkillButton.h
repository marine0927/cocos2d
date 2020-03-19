
#ifndef _SKILLBUTTON_H_
#define _SKILLBUTTON_H_
#include <cocos2d.h>
#include "SurroundingSkill.h"

class SkillButton : public cocos2d::CCNode
{
public:
	SkillButton();
	virtual ~SkillButton();

	/* ����һ��SkillButton���� */
	static SkillButton* createSkillButton(float cdTime,
		const char* stencil_file_name,
		const char* button_normal_name,
		const char* button_click_name,
		Hero*hero);

	/* CDʱ������ */
	void    setCDTime(float time) { mCDTime = time; }
	float   getCDTime() const { return mCDTime; }

	/* ���ܰ�ť����ص� */
	void    skillClickCallBack(cocos2d::CCObject* obj);

	/* ������ȴ��ϻص� */
	void    skillCoolDownCallBack(cocos2d::CCNode* node);

	/* ��ȡӢ�ۼ��ܱ�ǩ */
	void getHeroSkillLabel(Hero * hero)
	{
		SkillLabel = hero->Skill[0];
	}
	/* �õ�Ӣ�� */
	void getHero(Hero *hero)
	{
		this->hero = hero;
	}
private:

	/** ��ʼ�� */
	bool    init(float cdTime, const char* stencil_file_name, const char* button_normal_name, const char* button_click_name,Hero *hero);

public:
	cocos2d::CCMenuItemImage*   mItemSkill;     // ���ܰ�ť
	cocos2d::CCMenu*            mMenuSkill;     // ���ܰ�ť����menu
	cocos2d::CCSprite*          mStencil;       // �ɰ徫��,��ɫ��͸��(�����Ϊ����ʾһ����ȴ��ʱЧ��)
	cocos2d::CCProgressTimer*   mProgressTimer; // ʱ�����������(360����ת)
	float                       mCDTime;          // CDʱ��
	int SkillLabel;//���ܱ�ǩ
	int SkillPos;//������λ��
	Hero* hero;
};
#endif
