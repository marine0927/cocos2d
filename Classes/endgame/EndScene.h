#ifndef __GAMEEND_SCENE_H__
#define __GAMEEND_SCENE_H__

#include "cocos2d.h"

class GameEnd : public cocos2d::Layer
{
	cocos2d::Sprite * theend;
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameEnd);
}
#endif