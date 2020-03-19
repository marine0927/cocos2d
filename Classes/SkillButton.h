
#ifndef _SKILLBUTTON_H_
#define _SKILLBUTTON_H_
#include <cocos2d.h>
#include "SurroundingSkill.h"

class SkillButton : public cocos2d::CCNode
{
public:
	SkillButton();
	virtual ~SkillButton();

	/* 创建一个SkillButton对象 */
	static SkillButton* createSkillButton(float cdTime,
		const char* stencil_file_name,
		const char* button_normal_name,
		const char* button_click_name,
		Hero*hero);

	/* CD时间设置 */
	void    setCDTime(float time) { mCDTime = time; }
	float   getCDTime() const { return mCDTime; }

	/* 技能按钮点击回调 */
	void    skillClickCallBack(cocos2d::CCObject* obj);

	/* 技能冷却完毕回调 */
	void    skillCoolDownCallBack(cocos2d::CCNode* node);

	/* 读取英雄技能标签 */
	void getHeroSkillLabel(Hero * hero)
	{
		SkillLabel = hero->Skill[0];
	}
	/* 得到英雄 */
	void getHero(Hero *hero)
	{
		this->hero = hero;
	}
private:

	/** 初始化 */
	bool    init(float cdTime, const char* stencil_file_name, const char* button_normal_name, const char* button_click_name,Hero *hero);

public:
	cocos2d::CCMenuItemImage*   mItemSkill;     // 技能按钮
	cocos2d::CCMenu*            mMenuSkill;     // 技能按钮所在menu
	cocos2d::CCSprite*          mStencil;       // 蒙板精灵,黑色半透明(这个是为了显示一个冷却计时效果)
	cocos2d::CCProgressTimer*   mProgressTimer; // 时间进度条精灵(360度旋转)
	float                       mCDTime;          // CD时间
	int SkillLabel;//技能标签
	int SkillPos;//技能栏位置
	Hero* hero;
};
#endif
