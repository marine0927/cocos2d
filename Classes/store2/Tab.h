#ifndef __TABINGAME2_H__
#define __TABINGAME2_H__


#include "cocos2d.h"
USING_NS_CC;

class TabinGame2 : public cocos2d::Layer
{
	cocos2d::Sprite * skill1;
	cocos2d::Sprite * skill2;
	cocos2d::Sprite * skill3;
	cocos2d::Sprite * skill4;
	cocos2d::Sprite * skill5;
	cocos2d::Sprite * skill6;
	cocos2d::Sprite * skill7;
	cocos2d::Sprite * bg; 
	cocos2d::Sprite * text;
	bool show = false;
	int index = 1;
public:
	virtual bool init();
	virtual void update(float dt);
	virtual void onEnterTransitionDidFinish();
	virtual void onExitTransitionDidStart();
	void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	bool touchbegin(cocos2d::Touch* touch, cocos2d::Event *event);
	void touchend(cocos2d::Touch* touch, cocos2d::Event *event);
	CREATE_FUNC(TabinGame2);
};
#endif