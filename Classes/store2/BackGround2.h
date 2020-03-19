#ifndef __BACKGROUND_H__
#define __BACKGROUND_H__

#include "cocos2d.h"
USING_NS_CC;

class BackGround2 : public cocos2d::Layer
{
	cocos2d::Sprite * skill1;
	cocos2d::Sprite * skill2;
	cocos2d::Sprite * skill3;
	cocos2d::Sprite * skill4;
	cocos2d::Sprite * skill5;
	cocos2d::Sprite * skill6;
	cocos2d::Sprite * skill7;

	cocos2d::Sprite * q;
	cocos2d::Sprite * e;
	cocos2d::Sprite * space;
	cocos2d::Sprite * shift;
	cocos2d::Sprite * left;
	cocos2d::Sprite * right;

public:
	virtual bool init();
	virtual void update(float dt);
	void onEnter();
	void changePic2(int tag, int index);//改变技能图标
	CREATE_FUNC(BackGround2);
};

#endif