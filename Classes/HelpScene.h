#ifndef __HELP_SCENE_H__
#define __HELP_SCENE_H__

#include "cocos2d.h"
#include "SettingScene.h"
#include "SimpleAudioEngine.h"
#include "System.h"
class Help : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	// a selector callback
	void Help::menuExitCallback(Ref* pSender);
	// implement the "static create()" method manually
	CREATE_FUNC(Help);
};

#endif // __HELP_SCENE_H__