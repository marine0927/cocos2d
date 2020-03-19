



#include "SkillButton.h"

USING_NS_CC;

SkillButton::SkillButton() :
	mItemSkill(NULL),
	mMenuSkill(NULL),
	mStencil(NULL),
	mProgressTimer(NULL),
	mCDTime(1.f)
{

}

SkillButton::~SkillButton()
{

}

SkillButton* SkillButton::createSkillButton(float cdTime, const char* stencil_file_name, const char* button_normal_name, const char* button_click_name,Hero *hero)
{
	SkillButton* skillButton = new SkillButton();
	if (skillButton && skillButton->init(cdTime, stencil_file_name, button_normal_name, button_click_name,hero))
	{
		skillButton->autorelease();
		return skillButton;
	}
	else
	{
		delete skillButton;
		skillButton = NULL;
	}

	return NULL;
}


bool SkillButton::init(float cdTime, const char* stencil_file_name, const char* button_normal_name, const char* button_click_name,Hero *hero)
{
	CCAssert(stencil_file_name, "SkillButton::init stencil_file_name != NULL");
	CCAssert(button_normal_name, "SkillButton::init button_normal_name != NULL");
	CCAssert(button_click_name, "SkillButton::init button_click_name != NULL");
	this->hero = hero;
	// 添加技能按钮 下层
	mItemSkill = CCMenuItemImage::create(button_normal_name, button_click_name, this, menu_selector(SkillButton::skillClickCallBack));
	mItemSkill->setPosition(Point::ZERO);

	mMenuSkill = CCMenu::create(mItemSkill, NULL);
	mMenuSkill->setPosition(Point::ZERO);
	addChild(mMenuSkill, -100);

	// 添加旋转进度条精灵---半阴影 上层
	CCSprite* progressSprite = CCSprite::create(stencil_file_name);
	mProgressTimer = CCProgressTimer::create(progressSprite);
	mProgressTimer->setPosition(Point::ZERO);
	mProgressTimer->setVisible(false);
	addChild(mProgressTimer, 100);

	mCDTime = cdTime;
	return true;
}

/** 技能按钮点击回调 */
void SkillButton::skillClickCallBack(cocos2d::CCObject* obj)
{
	// 冷却计时，即时状态技能按钮不可点击
	mItemSkill->setEnabled(false);

	mProgressTimer->setVisible(true);
	mProgressTimer->setType(kCCProgressTimerTypeRadial);
	mProgressTimer->setReverseProgress(true); // 设置进度条为逆时针

	//准备一个旋转360度的动画(逐渐覆盖半透模板形成冷却效果;这里进行计时冷却动画的实现和时间控制)

	//注意这里冷却效果是从100%到0%顺时针变化的
	CCActionInterval* action_progress_from_to = CCProgressFromTo::create(mCDTime, 100, 0);

	CCCallFunc* action_callback = CCCallFuncN::create(this, callfuncN_selector(SkillButton::skillCoolDownCallBack));
	mProgressTimer->runAction(CCSequence::create(action_progress_from_to, action_callback, NULL));

	switch (hero->Skill[SkillPos])//判断第0个技能种类
	{
	case 10://瞬移（暂定）
	{
		switch (hero->getToward())
		{
	case 0:
	{
		hero->runAction(Place::create(hero->getPosition() + Vec2(0, 50)));
		break;
	}
	case 1:
	{
		hero->runAction(Place::create(hero->getPosition() + Vec2(0, -50)));
		break;
	}
	case 2:
	{
		hero->runAction(Place::create(hero->getPosition() + Vec2(-50, 0)));
		break;
	}
	case 3:
	{
		hero->runAction(Place::create(hero->getPosition() + Vec2(50, 0)));
		break;
	}
	default:
		break;
	    }
		break;
	}
	case 20:
	{
		SurroundingSkill *surroundingskill = SurroundingSkill::create(hero);
		surroundingskill->SkillStart(surroundingskill->hero);
	}
	default:
		break;
	}
		
}

/* 技能冷却完成回调 */
void SkillButton::skillCoolDownCallBack(CCNode* node)
{
	// 进度条技能不可见
	mProgressTimer->setVisible(false);

	// 按钮置为可用
	mItemSkill->setEnabled(true);
}