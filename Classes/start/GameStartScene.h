#ifndef __GAMESTART_SCENE_H__
#define __GAMESTART_SCENE_H__

#include "cocos2d.h"
#include "game1/Battle1Scene.h"
#include "store1/store.h"

extern bool showTalk;
extern bool talkTo1, talkTo2, talkTo3, talkTo4, talkTo5, talkTo6;

class GameStart : public cocos2d::Layer
{
	cocos2d::Sprite * hero;
	cocos2d::Sprite * npc1;
	cocos2d::Sprite * npc2;
	cocos2d::Sprite * npc3;
	cocos2d::Sprite * npc4;
	cocos2d::Sprite * npc5;
	cocos2d::Sprite * npc6;
	cocos2d::Sprite * npc7;
	cocos2d::Sprite * npc8;
	cocos2d::Sprite * npc9;
	cocos2d::Sprite * npc10;

	cocos2d::Sprite * f1;//对话提示
	cocos2d::Sprite * f2;
	cocos2d::Sprite * f3;
	cocos2d::Sprite * f4;
	cocos2d::Sprite * f5;
	cocos2d::Sprite * f6;

	cocos2d::Sprite * door;//胜利后的传送点
	cocos2d::TMXTiledMap * tileMap;
	cocos2d::TMXLayer *collidable;

	bool heropressd, heropressw, heropresss, heropressa;//英雄移动
	bool heropressf;//英雄对话
	bool BossDead = true;//判断Boss是否阵亡
public:

	static cocos2d::Scene* createScene();


	virtual bool init();
	virtual void onExitTransitionDidStart();
	virtual void onEnterTransitionDidFinish();
	void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	void keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);

	virtual void update(float dt);
	void setViewpointCenter(cocos2d::Vec2 position);
	void setheroPosition(cocos2d::Vec2 position);

	cocos2d::Vec2 tileCoordFromPosition(cocos2d::Vec2 position);

	CREATE_FUNC(GameStart);
	void GameStart::gotogame(cocos2d::Ref *pSender);
};

#endif // __GAMESTART_SCENE_H__