#ifndef __STORE_SCENE_H__
#define __STORE_SCENE_H__

#include "cocos2d.h"
#include "game2/Battle2Scene.h"
USING_NS_CC;

extern int tag;
extern cocos2d::Map < std::string, cocos2d::Sprite* > skillmap;
extern int backpack;
extern int gold;//��Ǯ
extern int MAX_SKILL;//�ܼ�����
extern int tagin1, tagin2, tagin3, tagin4, tagin5, tagin6, tagin7;
extern bool normal1, blink1, special11, special21, special31, special41, buff1, normal2, blink2, special12, special22, special32, special42, buff2;
extern bool changeNormal, changeBlink, changeSpecial1, changeSpecial2, changeSpecial3, changeSpecial4, changeBuff;
extern Vec2 initPosition;
extern bool showShop;//�̵����ʾ������

typedef enum
{
	NORMAL_TAG = 0,//��ͨ����
	BLINK_TAG,//λ�Ƽ���
	POINT_TAG,//ָ���Լ���
	ROUND_TAG,//�����Լ���
	AIM_TAG,//�����ж�����
	FOLLOW_TAG,//׷���ͼ���
	BUFF_TAG,//����
	NORMAL2_TAG,//��ͨ����
	BLINK2_TAG,//λ�Ƽ���
	POINT2_TAG,//ָ���Լ���
	ROUND2_TAG,//�����Լ���
	AIM2_TAG,//�����ж�����
	FOLLOW2_TAG,//׷���ͼ���
	BUFF2_TAG//����
} SkillTypes;//���ܱ�ǩ



typedef enum
{
	INIT_NORMAL_TAG = 20,//��ͨ����
	INIT_BLINK_TAG,//λ�Ƽ���
	INIT_SPECIAL1_TAG,//���⼼��
	INIT_SPECIAL2_TAG,//���⼼��
	INIT_SPECIAL3_TAG,//���⼼��
	INIT_SPECIAL4_TAG,//���⼼��
	INIT_BUFF_TAG,//����
	HERO_NORMAL_TAG,//��ͨ����
	HERO_BLINK_TAG,//λ�Ƽ���
	HERO_SPECIAL1_TAG,//���⼼��
	HERO_SPECIAL2_TAG,//���⼼��
	HERO_SPECIAL3_TAG,//���⼼��
	HERO_SPECIAL4_TAG,//���⼼��
	HERO_BUFF_TAG,//����
	HERO2_NORMAL_TAG,//��ͨ����
	HERO2_BLINK_TAG,//λ�Ƽ���
	HERO2_SPECIAL1_TAG,//���⼼��
	HERO2_SPECIAL2_TAG,//���⼼��
	HERO2_SPECIAL3_TAG,//���⼼��
	HERO2_SPECIAL4_TAG,//���⼼��
	HERO2_BUFF_TAG//����
} HeroSkillTypes;//��װ�����ܱ�ǩ

class Store1 : public cocos2d::Layer
{
	cocos2d::Sprite * bg;
	cocos2d::TMXTiledMap * tileMap;
	cocos2d::Sprite * hero;
	cocos2d::Sprite * shop;
	cocos2d::Sprite * door;
	cocos2d::TMXLayer *collidable;

	bool heropressd, heropressw, heropresss, heropressa;//Ӣ���ƶ�
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

//����ת������
	void menuItemcontinueCallBACK(cocos2d::Ref *pSender);
	CREATE_FUNC(Store1);
};

#endif // __STORE_SCENE_H__
