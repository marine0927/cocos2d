#ifndef __GAMEPLAYTHREE_SCENE_H__
#define __GAMEPLAYTHREE_SCENE_H__

#include "cocos2d.h"
#include "HomeScene.h"
USING_NS_CC;
class GamePlayThree : public cocos2d::Layer
{
	cocos2d::Sprite * hero;
	cocos2d::Sprite * door;//ʤ����Ĵ��͵�
	cocos2d::TMXTiledMap * tileMap;
	cocos2d::TMXLayer *collidable;
	cocos2d::Sprite * theend;
	bool heropressd, heropressw, heropresss, heropressa;//Ӣ���ƶ�
	bool BossDead = true;//�ж�Boss�Ƿ�����
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

	void GamePlayThree::end(cocos2d::Ref* pSender);//������ҳ��
	// implement the "static create()" method manually
	CREATE_FUNC(GamePlayThree);
};

#endif // __GAMEPLAYTHREE_SCENE_H__
