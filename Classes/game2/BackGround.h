#ifndef __BACKGROUNDINGAME2_H__
#define __BACKGROUNDINGAME2_H__

#include "cocos2d.h"
USING_NS_CC;

class BackGroundInGame2 : public cocos2d::Layer
{
	cocos2d::Sprite * skill1;
	cocos2d::Sprite * skill2;
	cocos2d::Sprite * skill3;
	cocos2d::Sprite * skill4;
	cocos2d::Sprite * skill5;
	cocos2d::Sprite * skill6;
	cocos2d::Sprite * skill7;
	cocos2d::Sprite * herostate;

	cocos2d::Sprite * q;
	cocos2d::Sprite * e;
	cocos2d::Sprite * space;
	cocos2d::Sprite * shift;
	cocos2d::Sprite * left;
	cocos2d::Sprite * right;

public:
	virtual bool init();
	virtual void update(float dt);
	virtual void onEnter();
	CREATE_FUNC(BackGroundInGame2);
};

#endif