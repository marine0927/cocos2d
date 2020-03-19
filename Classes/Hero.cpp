#include "Hero.h"

Hero* Hero::createWithTexture(Texture2D *texture)
{
	Hero *hero = new  Hero();
	if (hero && hero->initWithTexture(texture))
	{
		hero->autorelease();
		auto herobody = PhysicsBody::create();
		Point vert1[6] = {
			Point(-2.00000,-9.50000),
			Point(-4.00000,-7.50000),
			Point(-4.00000,5.50000),
			Point(4.00000,5.50000),
			Point(4.00000,-7.50000),
			Point(2.00000,-9.50000) };
		herobody->addShape(PhysicsShapePolygon::create(vert1, 6, PhysicsMaterial(1, 0, 0)));
		Point vert2[4] = {
			Point(1.00000,9.50000),
			Point(4.00000,5.50000),
			Point(-4.00000,5.50000),
			Point(-1.00000,9.50000)};
		herobody->addShape(PhysicsShapePolygon::create(vert2, 4, PhysicsMaterial(1, 0, 0)));
		herobody->setCategoryBitmask(0xFFFFFFFF);
		herobody->setCollisionBitmask(0x00000000);
		herobody->setContactTestBitmask(0xFFFFFFFF);
		herobody->setGravityEnable(0);
		herobody->setRotationEnable(false);

		hero->setPhysicsBody(herobody);
		hero->setScale(5);
		hero->setAnchorPoint(Vec2(0.5, 0.5));
		hero->setMovingSpeed(500);
		return hero;
	}
	CC_SAFE_DELETE(hero);
	return nullptr;
}
