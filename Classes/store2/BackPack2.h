#ifndef __BACKPACK_H__
#define __BACKPACK_H__

#include "cocos2d.h"
USING_NS_CC;

extern int x;
extern int y;

class BackPack2 : public cocos2d::Layer
{
	//�̵��ڵļ���
	cocos2d::Sprite * skill1_1;
	cocos2d::Sprite * skill2_1;
	cocos2d::Sprite * skill3_1;
	cocos2d::Sprite * skill4_1;
	cocos2d::Sprite * skill5_1;
	cocos2d::Sprite * skill6_1;
	cocos2d::Sprite * skill7_1;
	cocos2d::Sprite * skill8_1;
	cocos2d::Sprite * skill9_1;
	cocos2d::Sprite * skill10_1;
	cocos2d::Sprite * skill11_1;
	cocos2d::Sprite * skill12_1;
	cocos2d::Sprite * skill13_1;
	cocos2d::Sprite * skill14_1;
	//�������ڵļ���
	cocos2d::Sprite * skill1_2;
	cocos2d::Sprite * skill2_2;
	cocos2d::Sprite * skill3_2;
	cocos2d::Sprite * skill4_2;
	cocos2d::Sprite * skill5_2;
	cocos2d::Sprite * skill6_2;
	cocos2d::Sprite * skill7_2;

	cocos2d::Label * golds;//���
	cocos2d::Sprite * bg;//����
	cocos2d::Sprite * text;//����

	bool showtext = false;//�Ƿ���ʾ��������
	Vec2 pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9, pos10, pos11, pos12, pos13, pos14, pos15, pos16, pos17, pos18, pos19, pos20, pos21;//ԭ��������λ��
	bool skill1isBlank = true, skill2isBlank = true, skill3isBlank = true, skill4isBlank = true, skill5isBlank = true, skill6isBlank = true, skill7isBlank = true;//�ռ��ܲ��ж�
	bool skill_0 = false, skill_1 = false, skill_2 = false, skill_3 = false, skill_4 = false, skill_5 = false, skill_6 = false;//ռ���ж�
public:
	virtual bool init();
	virtual void onEnter();
	virtual void onExit();
	virtual void update(float dt);
	void addskill2(cocos2d::Sprite * sprite);//�޸�map
	void back2(Vec2 pos, cocos2d::Sprite * sprite);//���ܷ���ԭλ
	void mouseMove2(cocos2d::Event *event);
	bool touchbegin2(cocos2d::Touch* touch, cocos2d::Event *event);
	void touchend2(cocos2d::Touch* touch, cocos2d::Event *event);

	bool dragbegin2(cocos2d::Touch* touch, cocos2d::Event *event);
	void dragmove2(cocos2d::Touch* touch, cocos2d::Event *event);
	void dragend2(cocos2d::Touch* touch, cocos2d::Event *event);

	CREATE_FUNC(BackPack2);
};

#endif