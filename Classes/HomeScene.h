#ifndef __HOME_SCENE_H__
#define __HOME_SCENE_H__

#include "cocos2d.h"

#include "start/GameStartScene.h"
#include "SettingScene.h"
#include "store1/store.h"
#include "HelpScene.h"
#include "System.h"

class Home : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();
	virtual void onEnter();
	virtual void onEnterTransitionDidFinish();
	virtual void onExit();
	virtual void onExitTransitionDidStart();
	virtual void cleanup();
	void Home::menuStart(cocos2d::Ref *psender);
	void Home::menuHelp(cocos2d::Ref *psender);
	void Home::menuStore(cocos2d::Ref *psender);
	void Home::menuSetting(cocos2d::Ref *psender);
	// implement the "static create()" method manually
	CREATE_FUNC(Home);
};

#endif // __HOME_SCENE_H__
