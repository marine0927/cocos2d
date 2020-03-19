



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
	// ��Ӽ��ܰ�ť �²�
	mItemSkill = CCMenuItemImage::create(button_normal_name, button_click_name, this, menu_selector(SkillButton::skillClickCallBack));
	mItemSkill->setPosition(Point::ZERO);

	mMenuSkill = CCMenu::create(mItemSkill, NULL);
	mMenuSkill->setPosition(Point::ZERO);
	addChild(mMenuSkill, -100);

	// �����ת����������---����Ӱ �ϲ�
	CCSprite* progressSprite = CCSprite::create(stencil_file_name);
	mProgressTimer = CCProgressTimer::create(progressSprite);
	mProgressTimer->setPosition(Point::ZERO);
	mProgressTimer->setVisible(false);
	addChild(mProgressTimer, 100);

	mCDTime = cdTime;
	return true;
}

/** ���ܰ�ť����ص� */
void SkillButton::skillClickCallBack(cocos2d::CCObject* obj)
{
	// ��ȴ��ʱ����ʱ״̬���ܰ�ť���ɵ��
	mItemSkill->setEnabled(false);

	mProgressTimer->setVisible(true);
	mProgressTimer->setType(kCCProgressTimerTypeRadial);
	mProgressTimer->setReverseProgress(true); // ���ý�����Ϊ��ʱ��

	//׼��һ����ת360�ȵĶ���(�𽥸��ǰ�͸ģ���γ���ȴЧ��;������м�ʱ��ȴ������ʵ�ֺ�ʱ�����)

	//ע��������ȴЧ���Ǵ�100%��0%˳ʱ��仯��
	CCActionInterval* action_progress_from_to = CCProgressFromTo::create(mCDTime, 100, 0);

	CCCallFunc* action_callback = CCCallFuncN::create(this, callfuncN_selector(SkillButton::skillCoolDownCallBack));
	mProgressTimer->runAction(CCSequence::create(action_progress_from_to, action_callback, NULL));

	switch (hero->Skill[SkillPos])//�жϵ�0����������
	{
	case 10://˲�ƣ��ݶ���
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

/* ������ȴ��ɻص� */
void SkillButton::skillCoolDownCallBack(CCNode* node)
{
	// ���������ܲ��ɼ�
	mProgressTimer->setVisible(false);

	// ��ť��Ϊ����
	mItemSkill->setEnabled(true);
}