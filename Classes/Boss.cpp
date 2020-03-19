#include "Boss.h"

Boss* Boss::createWithTexture(Texture2D *texture, int bossindex)
{
	switch (bossindex)
	{
	case(1):
	{
		Boss *boss = new  Boss();
		if (boss && boss->initWithTexture(texture))
		{
			boss->autorelease();
			auto bossbody = PhysicsBody::create();
			Point vert1[4] = {
				Point(22.00000,-102.00000),
				Point(-20.00000,-102.00000),
				Point(-18.00000,75.00000),
				Point(26.00000,75.00000) };
			bossbody->addShape(PhysicsShapePolygon::create(vert1, 4, PhysicsMaterial(1, 0, 0)));
			bossbody->setCategoryBitmask(0xFFFFFFFF);
			bossbody->setCollisionBitmask(0x00000000);
			bossbody->setContactTestBitmask(0xFFFFFFFF);
			bossbody->setGravityEnable(0);
			bossbody->setRotationEnable(false);

			boss->setPhysicsBody(bossbody);
			boss->setScale(5);
			boss->setAnchorPoint(Vec2(0.5, 0.5));
			boss->setMovingSpeed(300);
			return boss;
			CC_SAFE_DELETE(boss);
			return nullptr;
			
		}
	}
	}

}