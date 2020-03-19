#include"Skill.h"

void Skill::skillrelease(int skillindex,cocos2d::Layer*layer, Vec2 mousePoint)
{
	if (skillFirstCreate)
	{
		auto progressSprite = Sprite::create("stencil.png");
		Layer *battleUI = (Layer*)Director::getInstance()->getRunningScene()->getChildByTag(1);
		for (int i = 1; i <= 6; i++)
		{
			mProgressTimer[i] = ProgressTimer::create(progressSprite);
			mProgressTimer[i]->setPosition(70*(i-1), 0);
			mProgressTimer[i]->setType(kCCProgressTimerTypeRadial);
			mProgressTimer[i]->setReverseProgress(true);
			mProgressTimer[i]->setVisible(false);
			battleUI->getChildByTag(60)->addChild(mProgressTimer[i], 5, 70+i);
		}
		skillFirstCreate = 0;
	}

	switch (skillindex)
	{
	case 4:
	{
		if (skillCDover[skillindex])
		{
			skillCDover[skillindex] = 0;

			SkillSprite*ball = SkillSprite::create("ball.png");
			auto body = PhysicsBody::createCircle(ball->getContentSize().width / 2);
			body->setCategoryBitmask(0xFFFFFFFF);
			body->setCollisionBitmask(0x00000000);
			body->setContactTestBitmask(0xFFFFFFFF);


			ball->setPhysicsBody(body);
			Vec2 ballPoint = (layer->getChildByTag(20)->convertToWorldSpace(Vec2(9, 25)));
			Vec2 setPoint = (layer->getChildByTag(10)->convertToNodeSpace(mousePoint));
			Vec2 ballworldPoint = layer->getChildByTag(10)->convertToNodeSpace(ballPoint);
			ball->setPosition(ballworldPoint);
			Vec2 distance = Vec2(setPoint.x - ballworldPoint.x, setPoint.y - ballworldPoint.y);
			float length = distance.length();
			Vec2 truepoint = Vec2(distance.x / length * 500, distance.y / length * 500);
			CCMoveBy* shot = MoveBy::create(1.5, truepoint);
			FiniteTimeAction*acf = CCCallFuncN::create(CC_CALLBACK_1(Skill::skillOver, this));
			ActionInterval *seq = Sequence::create(shot, acf, NULL);
			ball->setDemage(skillDemage[skillindex]);
			ball->runAction(seq);
			layer->addChild(ball, 5, 401);

		}
		break;
	}
	case 2:
	{
		if (skillCDover[skillindex])
		{
			skillCDover[skillindex] = 0;

			auto hero = layer->getChildByTag(20);

			for (int i = 0; i < 6; i++)
			{
				auto surrounding1body = PhysicsBody::create();
				Point vert1[4] = {
					Point(-8.02500,-4.00000),
					Point(-34.02500,7.00000),
					Point(32.97500,13.00000),
					Point(32.97500,-13.00000) };
				surrounding1body->addShape(PhysicsShapePolygon::create(vert1, 4, PhysicsMaterial(1, 0, 0)));
				Point vert2[4] = {
					Point(-46.02500,7.00000),
					Point(-34.02500,7.00000),
					Point(-35.52500,0.10000),
					Point(-46.02500,0.00000) };
				surrounding1body->addShape(PhysicsShapePolygon::create(vert2, 4, PhysicsMaterial(1, 0, 0)));
				Point vert3[3] = {
					Point(-35.52500,0.10000),
					Point(-34.02500,7.00000),
					Point(-8.02500,-4.00000) };
				surrounding1body->addShape(PhysicsShapePolygon::create(vert3, 3, PhysicsMaterial(1, 0, 0)));
				surrounding1body->setCategoryBitmask(0xFFFFFFFF);
				surrounding1body->setCollisionBitmask(0x00000000);
				surrounding1body->setContactTestBitmask(0xFFFFFFFF);
				surrounding1[i] = SkillSprite::create("skill/surrounding1.png");
				surrounding1[i]->setScale(0.2);
				surrounding1[i]->setAnchorPoint(Vec2(0.5, 0.5) + Vec2(120 / surrounding1[i]->getContentSize().width, 0));
				surrounding1[i]->setPosition(hero->getContentSize().width / 2, hero->getContentSize().height / 2);
				surrounding1[i]->setPhysicsBody(surrounding1body);
				surrounding1[i]->setRotation(60 * (i - 1));
				surrounding1[i]->setDemage(skillDemage[skillindex]);
				hero->addChild(surrounding1[i], 3, 201 + i);
				FiniteTimeAction*surrounding1_ac0 = (FiniteTimeAction*)surrounding1[i]->runAction(RotateBy::create(8, 1080));
				FiniteTimeAction*acf = CCCallFuncN::create(CC_CALLBACK_1(Skill::skillOver, this));
				surrounding1[i]->runAction(Sequence::create(surrounding1_ac0, acf, NULL));
			}
		}
		break;
	}
	case 3:
	{
		if (skillCDover[skillindex])
		{
			skillCDover[skillindex] = 0;

			auto hero = layer->getChildByTag(20);

			auto circle = Sprite::create("skill/circle.png");
			circle->setScale(0.2);
			for (int i = 0; i < 3; i++)
			{
				auto surrounding2body = PhysicsBody::create();
				Point vert1[5] = {
					Point(39.50000,26.50000),
					Point(8.50000,14.50000),
					Point(7.50000,15.50000),
					Point(27.50000,46.50000),
					Point(57.50000,59.50000) };
				surrounding2body->addShape(PhysicsShapePolygon::create(vert1, 5, PhysicsMaterial(1, 0, 0)));
				Point vert2[5] = {
					Point(-27.50000,44.50000),
					Point(-13.50000,15.50000),
					Point(-16.50000,13.50000),
					Point(-42.50000,27.50000),
					Point(-58.50000,60.50000) };
				surrounding2body->addShape(PhysicsShapePolygon::create(vert2, 5, PhysicsMaterial(1, 0, 0)));
				Point vert3[5] = {
					Point(9.50000,-14.50000),
					Point(12.50000,-7.50000),
					Point(25.50000,-22.50000),
					Point(50.50000,-59.50000),
					Point(24.50000,-42.50000)
				};
				surrounding2body->addShape(PhysicsShapePolygon::create(vert3, 5, PhysicsMaterial(1, 0, 0)));
				Point vert4[5] = {
					Point(-57.50000,-56.50000),
					Point(-62.50000,-51.50000),
					Point(-44.50000,-26.50000),
					Point(-25.50000,-26.50000),
					Point(-30.50000,-40.50000)
				};
				surrounding2body->addShape(PhysicsShapePolygon::create(vert4, 5, PhysicsMaterial(1, 0, 0)));
				Point vert5[4] = {
					Point(-17.50000,-10.50000),
					Point(-11.50000,-13.50000),
					Point(-25.50000,-26.50000),
					Point(-44.50000,-26.50000)
				};
				surrounding2body->addShape(PhysicsShapePolygon::create(vert5, 4, PhysicsMaterial(1, 0, 0)));
				Point vert6[8] = {
					Point(-21.50000,-2.50000),
					Point(-20.50000,2.50000),
					Point(-5.50000,17.50000),
					Point(16.50000,3.50000),
					Point(22.50000,-1.50000),
					Point(12.50000,-7.50000),
					Point(-11.50000,-13.50000),
					Point(-17.50000,-10.50000)
				};
				surrounding2body->addShape(PhysicsShapePolygon::create(vert6, 8, PhysicsMaterial(1, 0, 0)));
				Point vert7[4] = {
					Point(50.50000,-59.50000),
					Point(25.50000,-22.50000),
					Point(36.50000,-26.50000),
					Point(55.50000,-55.50000)
				};
				surrounding2body->addShape(PhysicsShapePolygon::create(vert7, 4, PhysicsMaterial(1, 0, 0)));
				Point vert8[5] = {
					Point(-67.50000,1.50000),
					Point(-67.50000,3.50000),
					Point(-35.25862,3.50000),
					Point(-20.50000,2.50000),
					Point(-46.50000,-3.50000)
				};
				surrounding2body->addShape(PhysicsShapePolygon::create(vert8, 5, PhysicsMaterial(1, 0, 0)));
				Point vert9[4] = {
					Point(-0.50000,-16.5000),
					Point(-11.50000,-13.50000),
					Point(12.50000,-7.50000),
					Point(9.50000,-14.50000)
				};
				surrounding2body->addShape(PhysicsShapePolygon::create(vert9, 4, PhysicsMaterial(1, 0, 0)));
				Point vert10[4] = {
					Point(-13.50000,15.50000),
					Point(-5.50000,17.50000),
					Point(-20.50000,2.50000),
					Point(-16.50000,13.50000)
				};
				surrounding2body->addShape(PhysicsShapePolygon::create(vert10, 4, PhysicsMaterial(1, 0, 0)));
				Point vert11[3] = {
					Point(-35.25862,3.50000),
					Point(-67.50000,3.50000),
					Point(-48.53448,5.56896)
				};
				surrounding2body->addShape(PhysicsShapePolygon::create(vert11, 3, PhysicsMaterial(1, 0, 0)));
				Point vert12[4] = {
					Point(-7.50000,-20.50000),
					Point(-0.50000,-16.50000),
					Point(-2.50000,-67.50000),
					Point(-5.50000,-67.50000)
				};
				surrounding2body->addShape(PhysicsShapePolygon::create(vert12, 4, PhysicsMaterial(1, 0, 0)));
				Point vert13[3] = {
					Point(-11.50000,-13.50000),
					Point(-0.50000,-16.50000),
					Point(-7.50000,-20.50000)
				};
				surrounding2body->addShape(PhysicsShapePolygon::create(vert13, 3, PhysicsMaterial(1, 0, 0)));
				Point vert14[3] = {
					Point(-20.50000,2.50000),
					Point(-21.50000,-2.50000),
					Point(-32.50000,-0.50000)
				};
				surrounding2body->addShape(PhysicsShapePolygon::create(vert14, 3, PhysicsMaterial(1, 0, 0)));
				Point vert15[4] = {
					Point(22.50000,-1.50000),
					Point(16.50000,3.50000),
					Point(66.50000,-0.50000),
					Point(66.50000,-2.50000)
				};
				surrounding2body->addShape(PhysicsShapePolygon::create(vert15, 4, PhysicsMaterial(1, 0, 0)));
				Point vert16[5] = {
					Point(8.50000,14.50000),
					Point(16.50000,3.50000),
					Point(-5.50000,17.50000),
					Point(3.50000,17.50000),
					Point(7.50000,15.50000)
				};
				surrounding2body->addShape(PhysicsShapePolygon::create(vert16, 5, PhysicsMaterial(1, 0, 0)));
				Point vert17[4] = {
					Point(-0.50000,67.50000),
					Point(0.50000,67.50000),
					Point(3.50000,17.50000),
					Point(-5.50000,17.50000)
				};
				surrounding2body->addShape(PhysicsShapePolygon::create(vert17, 4, PhysicsMaterial(1, 0, 0)));


				surrounding2body->setCategoryBitmask(0xFFFFFFFF);
				surrounding2body->setCollisionBitmask(0x00000000);
				surrounding2body->setContactTestBitmask(0xFFFFFFFF);

				surrounding2[i] = SkillSprite::create("skill/surrounding2.png");
				surrounding2[i]->setScale(0.6);
				surrounding2[i]->setAnchorPoint(Vec2(0.5, 0.5));
				surrounding2[i]->setPosition(Vec2(circle->getContentSize().width*cos(120.0*i*pi / 180) / 2, circle->getContentSize().height*sin(120.0*i*pi / 180) / 2) + Vec2(circle->getContentSize().width / 2, circle->getContentSize().height / 2));
				surrounding2[i]->setPhysicsBody(surrounding2body);
				surrounding2[i]->setDemage(skillDemage[skillindex]);
				circle->addChild(surrounding2[i], 3, 301 + i);
				FiniteTimeAction*surrounding2_ac1 = (FiniteTimeAction*)surrounding2[i]->runAction(RotateBy::create(8, 2160));
				FiniteTimeAction*surrounding2_ac2 = (FiniteTimeAction*)surrounding2[i]->runAction(ScaleTo::create(8, 0.15));
				surrounding2[i]->runAction(Spawn::create(surrounding2_ac1, surrounding2_ac2, NULL));
			}
			circle->setPosition(hero->getContentSize().width / 2, hero->getContentSize().height / 2);
			circle->setAnchorPoint(Vec2(0.5, 0.5));
			hero->addChild(circle, 3, 300);
			FiniteTimeAction*surrounding2_ac1 = (FiniteTimeAction*)circle->runAction(RotateBy::create(8, 2160));
			FiniteTimeAction*surrounding2_ac2 = (FiniteTimeAction*)circle->runAction(ScaleTo::create(8, 0.6));
			FiniteTimeAction*surrounding2_ac0 = (FiniteTimeAction*)circle->runAction(Spawn::create(surrounding2_ac1, surrounding2_ac2, NULL));
			FiniteTimeAction*acf = CCCallFuncN::create(CC_CALLBACK_1(Skill::skillOver, this));
			circle->runAction(Sequence::create(surrounding2_ac0, acf, NULL));

		}
		break;
	}
	case 1:
	{
		if (skillCDover[skillindex])
		{
			skillCDover[skillindex] = 0;

			auto hero = layer->getChildByTag(20);
			auto circle = Sprite::create("skill/circle.png");
			circle->setScale(0.3);

			for (int i = 0; i < 6; i++)
			{

				fireball[i] = SkillSprite::create("skill/fireball.png");
				fireball[i]->setScale(0.5);
				fireball[i]->setAnchorPoint(Vec2(0.5, 0.5));
				fireball[i]->setPosition(Vec2(circle->getContentSize().width*cos(60.0*i*pi / 180) / 2, circle->getContentSize().height*sin(60.0*i*pi / 180) / 2) + Vec2(circle->getContentSize().width / 2, circle->getContentSize().height / 2));
				fireball[i]->setDemage(skillDemage[skillindex]);
				circle->addChild(fireball[i], 3, 101 + i);
			}
			circle->setPosition(hero->getContentSize().width / 2, hero->getContentSize().height / 2);
			circle->setAnchorPoint(Vec2(0.5, 0.5));
			hero->addChild(circle, 3, 100);
			FiniteTimeAction*surrounding2_ac1 = (FiniteTimeAction*)circle->runAction(RotateBy::create(2, 180));
			FiniteTimeAction*acf_1 = CCCallFuncN::create(CC_CALLBACK_1(Skill::traceSkill, this));
			FiniteTimeAction*acf_2 = CCCallFuncN::create(CC_CALLBACK_1(Skill::skillOver, this));
			circle->runAction(Sequence::create(surrounding2_ac1, acf_1, acf_2, NULL));



		}
		break;
	}
	case 31:
	{
		auto boss = layer->getChildByTag(40);
		for (int i = 0; i < 24; i++)
		{

			auto surrounding = PhysicsBody::createCircle(27.406, PhysicsMaterial(1, 0, 0), Vec2(8.600, -10.900));


			surrounding->setCategoryBitmask(0xFFFFFFFF);
			surrounding->setCollisionBitmask(0x00000000);
			surrounding->setContactTestBitmask(0xFFFFFFFF);

			auto fireball = SkillSprite::create("skill/bossfire.png");
			fireball->setPhysicsBody(surrounding);
			fireball->setScale(1);
			fireball->setAnchorPoint(Vec2(0.5, 0.5));
			fireball->setPosition(Vec2(boss->getContentSize().width*1.5*cos(15.0*i*pi / 180) / 2, boss->getContentSize().width*1.5*sin(15.0*i*pi / 180) / 2) + boss->getPosition());
			fireball->setDemage(skillDemage[skillindex]);
			layer->addChild(fireball, 3, 3101 + i);
			FiniteTimeAction*surrounding2_ac1 = (FiniteTimeAction*)fireball->runAction(MoveBy::create(2, Vec2(boss->getContentSize().width * 7 * cos(15.0*i*pi / 180) / 2, boss->getContentSize().width * 7 * sin(15.0*i*pi / 180) / 2)));
			FiniteTimeAction*acf = CCCallFuncN::create(CC_CALLBACK_1(Skill::BossSkillOver, this));
			fireball->runAction(Sequence::create(surrounding2_ac1, acf, NULL));
		}

		break;
	}
	case 7:
	{
		skillCoolDown(2, skillindex);
		break;
	}
	case 8:
	{
		skillCoolDown(2, skillindex);
		break;
	}
	case 9:
	{
		skillCoolDown(2, skillindex);
		break;
	}
	case 10:
	{
		Sprite *fire = Sprite::create("skill/fireattack.png");
		auto hero = (Hero*)layer->getChildByTag(20);

		Texture2D* heroleft = Director::getInstance()->getTextureCache()->addImage("hero3.png");
		Texture2D* heroright = Director::getInstance()->getTextureCache()->addImage("hero4.png");
		mousePoint = layer->getChildByTag(10)->convertToNodeSpace(mousePoint);
		Vec2 heroposition = hero->getPosition();
		if ((mousePoint.x - heroposition.x) > 0) {
			hero->setTexture(heroleft);
		}
		if ((mousePoint.x - heroposition.x) < 0) {
			hero->setTexture(heroright);
		}
		Vec2 distance = mousePoint - heroposition;
		float length = distance.length();
		fire->setPosition(Vec2(hero->getContentSize().width / 2, hero->getContentSize().height / 2) + Vec2(distance.x / length * 30, distance.y / length * 30));
		fire->setScale(0.2);

		Animation * animation = Animation::create();
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("skill/fire.plist");
		SpriteFrame *fire1 = SpriteFrameCache::getInstance()->getSpriteFrameByName("fire1.png");
		SpriteFrame *fire2 = SpriteFrameCache::getInstance()->getSpriteFrameByName("fire2.png");
		SpriteFrame *fire3 = SpriteFrameCache::getInstance()->getSpriteFrameByName("fire3.png");
		animation->addSpriteFrame(fire1);
		animation->addSpriteFrame(fire2);
		animation->addSpriteFrame(fire3);
		animation->setDelayPerUnit(0.1);
		animation->setRestoreOriginalFrame(true);
		Animate *action = Animate::create(animation);
		layer->getChildByTag(20)->addChild(fire, 5, 1000);

		fire->runAction(action);
		skillCoolDown(1, skillindex);
		break;
	}
	case 21://伤害强化
	{

		for (int i = 0; i < 21; i++)
		{
			skillDemage[i] = 1.5*skillDemage[i];
		}
		break;
	}
	case 20://CD强化
	{

		for (int i = 0; i < 21; i++)
		{
			skillCDtime[i] = skillCDtime[i] - 1;
		}
		break;
	}
	case 19://速度强化
	{

		for (int i = 0; i < 21; i++)
		{
			auto hero = (Hero*)layer->getChildByTag(20);
			hero->setMovingSpeed(hero->getMovingSpeed()*1.2);
		}
		break;
	}
	case 18://血量强化
	{

		for (int i = 0; i < 21; i++)
		{
			auto hero = (Hero*)layer->getChildByTag(20);
			hero->setInitHp(hero->getInitHp()+20);
			hero->setHp(hero->getHp() + 20);
		}
		break;
	}
	case 11:
	{
		auto hero = (Hero*)layer->getChildByTag(20);
		SkillSprite* herocatch = SkillSprite::create("skill/catch.png");
		auto body = PhysicsBody::create();
		Point vert1[3] = {
					Point(220.50000,-11.98300),
					Point(179.50000,-69.98300),
					Point(180.50000,30.01700),
		};
		body->addShape(PhysicsShapePolygon::create(vert1, 3, PhysicsMaterial(1, 0, 0)));


		body->setCategoryBitmask(0xFFFFFFFF);
		body->setCollisionBitmask(0x00000000);
		body->setContactTestBitmask(0xFFFFFFFF);
		herocatch->setPhysicsBody(body);
		
		herocatch->setScale(0.1);
		Vec2 offset = layer->getChildByTag(10)->convertToNodeSpace(mousePoint) - hero->getPosition();
		if (offset.y>0&& offset.x>0)
		{
			herocatch->setRotation(-asin(offset.y / offset.length()) / pi * 180);
		}
		else {
			if (offset.y > 0 && offset.x < 0) {
				herocatch->setRotation(180 + asin(offset.y / offset.length()) / pi * 180);
			}
			else
			{
				if (offset.y < 0 && offset.x < 0) {
					herocatch->setRotation(180 + asin(offset.y / offset.length()) / pi * 180);
				}
				else
				{
					herocatch->setRotation( -asin(offset.y / offset.length()) / pi * 180);
				}
			}
		}
		Texture2D* heroleft = Director::getInstance()->getTextureCache()->addImage("hero3.png");
		Texture2D* heroright = Director::getInstance()->getTextureCache()->addImage("hero4.png");
		if ((offset.x) > 0) {
			hero->setTexture(heroleft);
		}
		if ((offset.x) < 0) {
			hero->setTexture(heroright);
		}
		herocatch->setDemage(skillDemage[skillindex]);
		
		herocatch->setPosition(hero->getContentSize().width / 2, hero->getContentSize().height / 2);
		hero->addChild(herocatch, 5, 1100);
		FiniteTimeAction*ac0=(FiniteTimeAction*)herocatch->runAction(MoveBy::create(0.5, Vec2(offset.x / offset.length() * 20, offset.y / offset.length() * 20)));
		FiniteTimeAction*acf = CCCallFuncN::create(CC_CALLBACK_1(Skill::traceRemove, this));
		herocatch->runAction(Sequence::create(ac0, acf, NULL));
	}
	}
}

Skill::Skill()
{
	for (int i=0; i < 40; i++)
	{
		skillCDover[i] = 1;
		skillCDtime[i] = 3;
		skillDemage[i] = 10;
	}
	skillDemage[1] = 100;
	skillDemage[31] = 10;
	skillDemage[8] = 100;
	skillCDtime[7] = 1.5;
	skillFirstCreate = 1;
}

void Skill::skillCDstart(CCNode *node)
{
	int skillposition = node->getTag()-70;
	Hero *hero = (Hero*)Director::getInstance()->getRunningScene()->getChildByTag(0)->getChildByTag(20);
	if (hero->Skill[skillposition]==1)
	{
		auto layer = (Layer*)Director::getInstance()->getRunningScene()->getChildByTag(0);
		for (int i = 0; i < 6; i++) {
			layer->getChildByTag(101 + i)->removeFromParent();
		}
		skillCDover[hero->Skill[skillposition]] = 1;
	}
	else {
		skillCDover[hero->Skill[skillposition]] = 1;
	}
}

void Skill::skillCoolDown(int skillposition,int skillindex)
{
	mProgressTimer[skillposition]->setVisible(true);
	mProgressTimer[skillposition]->setType(kCCProgressTimerTypeRadial);
	mProgressTimer[skillposition]->setReverseProgress(true); // 设置进度条为逆时针

	//准备一个旋转360度的动画(逐渐覆盖半透模板形成冷却效果;这里进行计时冷却动画的实现和时间控制)

	//注意这里冷却效果是从100%到0%顺时针变化的
	CCActionInterval* action_progress_from_to = CCProgressFromTo::create(skillCDtime[skillindex], 100, 0);

	CCCallFunc* action_callback = CCCallFuncN::create(this, callfuncN_selector(Skill::skillCDstart));
	mProgressTimer[skillposition]->runAction(CCSequence::create(action_progress_from_to, action_callback, NULL));
}

void Skill::traceSkill(CCNode * node)
{
	for (int i = 0; i < 6; i++) {

		auto tileMap = Director::getInstance()->getRunningScene()->getChildByTag(0)->getChildByTag(10);

		SkillSprite * sprite = (SkillSprite*)node->getChildByTag(101+i);
		auto fireballbody = PhysicsBody::create();
		fireballbody->addShape(PhysicsShapeCircle::create(30.867, PhysicsMaterial(1, 0, 0), Vec2(-1.167, -3.333)));
		fireballbody->setCategoryBitmask(0xFFFFFFFF);
		fireballbody->setCollisionBitmask(0x00000000);
		fireballbody->setContactTestBitmask(0xFFFFFFFF);

		auto hero = Director::getInstance()->getRunningScene()->getChildByTag(0)->getChildByTag(20);

		Vec2 fireballposition = sprite->getPosition();
		Vec2 fireballheroposition = hero->getChildByTag(100)->convertToWorldSpace(fireballposition);
		Vec2 fireballworldposition = tileMap->convertToNodeSpace(fireballheroposition);
		//log("%f,%f,%f,%f,%f,%f", fireballposition.x, fireballposition.y, fireballheroposition.x, fireballheroposition.y, fireworldposition.x, fireworldposition.y);

		SkillSprite * fireball = SkillSprite::create("skill/fireball.png");
		fireball->setPhysicsBody(fireballbody);
		fireball->setScale(0.75);
		fireball->setAnchorPoint(Vec2(0.5, 0.5));
		fireball->setPosition(fireballworldposition);
		fireballoffset[i] = fireball->getPosition() - hero->getPosition();
		fireball->setDemage(sprite->getDemage());
		Director::getInstance()->getRunningScene()->getChildByTag(0)->addChild(fireball, 5, sprite->getTag());
		sprite->removeFromParent();

		auto boss = Director::getInstance()->getRunningScene()->getChildByTag(0)->getChildByTag(40);
		
	}

}

void Skill::BossSkillOver(Ref * psender)
{
	auto sprite = (Sprite*)psender;
	sprite->removeFromParent();
}

void Skill::skillOver(Ref * psender)
{
	int skillposition;
	Layer *layer = (Layer*)Director::getInstance()->getRunningScene()->getChildByTag(0);
	auto skill = (Sprite*)psender;
	auto hero = (Hero*)layer->getChildByTag(20);
	skill->removeFromParent();
	int skillindex = skill->getTag() / 100;
	for (int i = 1; i <= 6; i++)
	{
		if (hero->Skill[i] == skillindex)
		{
			skillposition = i;
			break;
		}
	}


	skillCoolDown(skillposition, skillindex);
}
void Skill::traceRemove(Ref * psender)
{
	Sprite*sprite = (Sprite*)psender;
	sprite->removeFromParent();
}

