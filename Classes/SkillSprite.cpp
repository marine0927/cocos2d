#include "SkillSprite.h"

SkillSprite* SkillSprite::create(const std::string& filename)
{
	SkillSprite *sprite = new (std::nothrow) SkillSprite();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}
