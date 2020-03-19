
#pragma once
#include"cocos2d.h"
USING_NS_CC;

class Hero :public Sprite
{
	CC_SYNTHESIZE(int, initHp, InitHp);//初始生命 默认是500
	CC_SYNTHESIZE(int, hp, Hp);//当前生命
	CC_SYNTHESIZE(int, movingSpeed, MovingSpeed);//移动速度 默认是300
	CC_SYNTHESIZE(int, toward, Toward);//朝向 上下左右 对应 0123 默认是朝向右
	CC_SYNTHESIZE(int, attack, Attack);//攻击力 默认是2
public:
	static Hero *createWithTexture(Texture2D *texture);
	static Hero *createWithSpriteFrame(SpriteFrame *spriteFrame);
	int Skill[7] = {0,11,8,0,4,2,3 };//技能栏 默认0为空
};
