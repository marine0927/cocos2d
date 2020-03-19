#pragma once
#include"cocos2d.h"
USING_NS_CC;

class Boss :public Sprite
{
	CC_SYNTHESIZE(int, initHp, InitHp);//��ʼ���� Ĭ����500
	CC_SYNTHESIZE(int, hp, Hp);//��ǰ����
	CC_SYNTHESIZE(int, movingSpeed, MovingSpeed);//�ƶ��ٶ� Ĭ����300
	CC_SYNTHESIZE(int, toward, Toward);//���� �������� ��Ӧ 0123 Ĭ���ǳ�����
	CC_SYNTHESIZE(int, attack, Attack);//������ Ĭ����2
public:
	static Boss *createWithTexture(Texture2D *texture,int bossindex);
	static Boss *createWithSpriteFrame(SpriteFrame *spriteFrame);
	int Skill[7] = { 0,1,2,3,4,5,6 };//������ Ĭ��0Ϊ��
};
