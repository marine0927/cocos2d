#ifndef __STORE_SCENE_H__
#define __STORE_SCENE_H__

#include "cocos2d.h"
#include "game2/Battle2Scene.h"
USING_NS_CC;

extern int tag;
extern cocos2d::Map < std::string, cocos2d::Sprite* > skillmap;
extern int backpack;
extern int gold;//金钱
extern int MAX_SKILL;//总技能数
extern int tagin1, tagin2, tagin3, tagin4, tagin5, tagin6, tagin7;
extern bool normal1, blink1, special11, special21, special31, special41, buff1, normal2, blink2, special12, special22, special32, special42, buff2;
extern bool changeNormal, changeBlink, changeSpecial1, changeSpecial2, changeSpecial3, changeSpecial4, changeBuff;
extern Vec2 initPosition;
extern bool showShop;//商店的显示与隐藏

typedef enum
{
	NORMAL_TAG = 0,//普通攻击
	BLINK_TAG,//位移技能
	POINT_TAG,//指向性技能
	ROUND_TAG,//环绕性技能
	AIM_TAG,//击中判定技能
	FOLLOW_TAG,//追踪型技能
	BUFF_TAG,//被动
	NORMAL2_TAG,//普通攻击
	BLINK2_TAG,//位移技能
	POINT2_TAG,//指向性技能
	ROUND2_TAG,//环绕性技能
	AIM2_TAG,//击中判定技能
	FOLLOW2_TAG,//追踪型技能
	BUFF2_TAG//被动
} SkillTypes;//技能标签



typedef enum
{
	INIT_NORMAL_TAG = 20,//普通攻击
	INIT_BLINK_TAG,//位移技能
	INIT_SPECIAL1_TAG,//特殊技能
	INIT_SPECIAL2_TAG,//特殊技能
	INIT_SPECIAL3_TAG,//特殊技能
	INIT_SPECIAL4_TAG,//特殊技能
	INIT_BUFF_TAG,//被动
	HERO_NORMAL_TAG,//普通攻击
	HERO_BLINK_TAG,//位移技能
	HERO_SPECIAL1_TAG,//特殊技能
	HERO_SPECIAL2_TAG,//特殊技能
	HERO_SPECIAL3_TAG,//特殊技能
	HERO_SPECIAL4_TAG,//特殊技能
	HERO_BUFF_TAG,//被动
	HERO2_NORMAL_TAG,//普通攻击
	HERO2_BLINK_TAG,//位移技能
	HERO2_SPECIAL1_TAG,//特殊技能
	HERO2_SPECIAL2_TAG,//特殊技能
	HERO2_SPECIAL3_TAG,//特殊技能
	HERO2_SPECIAL4_TAG,//特殊技能
	HERO2_BUFF_TAG//被动
} HeroSkillTypes;//可装备技能标签

class Store1 : public cocos2d::Layer
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
	void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	void keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	// a selector callback
	virtual void update(float dt);
	void setViewpointCenter(cocos2d::Vec2 position);
	void setheroPosition(cocos2d::Vec2 position);
	cocos2d::Vec2 tileCoordFromPosition(cocos2d::Vec2 position);
	// implement the "static create()" method manually

//场景转换函数
	void menuItemcontinueCallBACK(cocos2d::Ref *pSender);
	CREATE_FUNC(Store1);
};

#endif // __STORE_SCENE_H__
