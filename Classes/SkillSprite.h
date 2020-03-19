#include"cocos2d.h"
USING_NS_CC; 
#pragma once
class SkillSprite :public Sprite
{
private:
	CC_SYNTHESIZE(int, demage, Demage);//…À∫¶÷µ
public:
	static SkillSprite* create(const std::string& filename);
};