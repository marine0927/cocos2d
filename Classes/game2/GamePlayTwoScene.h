#ifndef __GAMEPLAYTWO_SCENE_H__
#define __GAMEPLAYTWO_SCENE_H__

#include "cocos2d.h"
#include "store2/store2.h"
#include "game3/GamePlayThreeScene.h"

class GamePlayTwo : public cocos2d::Layer
{
	cocos2d::Sprite * hero;
	cocos2d::Sprite * door;//胜利后的传送点
	cocos2d::TMXTiledMap * tileMap;
	cocos2d::TMXLayer *collidable;

	bool heropressd, heropressw, heropresss, heropressa;//英雄移动
	bool BossDead = true;//判断Boss是否阵亡
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();
	virtual void onExitTransitionDidStart();
	virtual void onEnterTransitionDidFinish();
	void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	void keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);

	virtual void update(float dt);
	void setViewpointCenter(cocos2d::Vec2 position);
	void setheroPosition(cocos2d::Vec2 position);
	cocos2d::Vec2 tileCoordFromPosition(cocos2d::Vec2 position);
	CREATE_FUNC(GamePlayTwo);
	void GamePlayTwo::gotostore(cocos2d::Ref *pSender);
};

#endif // __GAMEPLAYTWO_SCENE_H__