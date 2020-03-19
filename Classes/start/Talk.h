#ifndef __TALK_H__
#define __TALK_H__

#include "cocos2d.h"
#include "GameStartScene.h"
#include "CCLabelBMFontAnimated.h"

USING_NS_CC;

float heroX;
float heroY;
Vec2 initPosition1;

typedef enum
{
	BG_TAG = 0
	
} TalkTypes;

class Talk : public cocos2d::Layer
{
	cocos2d::Sprite * talkbg;

	CCLabelBMFontAnimated *label1;
	CCLabelBMFontAnimated *label2;

	CCLabelBMFontAnimated *label3;
	CCLabelBMFontAnimated *label4;

	CCLabelBMFontAnimated *label5;
	CCLabelBMFontAnimated *label6;

	CCLabelBMFontAnimated *label7;
	CCLabelBMFontAnimated *label8;

	CCLabelBMFontAnimated *label9;
	CCLabelBMFontAnimated *label10;

	CCLabelBMFontAnimated *label11;
	CCLabelBMFontAnimated *label12;

	cocos2d::Size visibleSize;
	cocos2d::Point origin;
public:
	virtual bool init();
	virtual void update(float dt);

	void Talk::onExitTransitionDidStart2();
	void Talk::onEnterTransitionDidFinish2();

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

	char * FontToUTF8(const char* font);

	CREATE_FUNC(Talk);
};

#endif