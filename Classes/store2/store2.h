#ifndef __STOREE_SCENE_H__
#define __STOREE_SCENE_H__

#include "cocos2d.h"
#include "store1/store.h"
#include "game3/Battle3Scene.h"
USING_NS_CC;

class Store2 : public cocos2d::Layer
{
	cocos2d::Sprite * bg;
	cocos2d::TMXTiledMap * tileMap;
	cocos2d::Sprite * hero;
	cocos2d::Sprite * shop;
	cocos2d::Sprite * door;
	cocos2d::TMXLayer *collidable;

	bool heropressd, heropressw, heropresss, heropressa;//英雄移动
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	virtual void onExitTransitionDidStart();
	virtual void onEnterTransitionDidFinish();
	void keyPressed2(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	void keyReleased2(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	// a selector callback
	virtual void update(float dt);
	void setViewpointCenter2(cocos2d::Vec2 position);
	void setheroPosition2(cocos2d::Vec2 position);
	cocos2d::Vec2 tileCoordFromPosition2(cocos2d::Vec2 position);
	// implement the "static create()" method manually

//场景转换函数
	void menuItemcontinueCallBACK2(cocos2d::Ref *pSender);
	CREATE_FUNC(Store2);
};

#endif // __STOREE_SCENE_H__
