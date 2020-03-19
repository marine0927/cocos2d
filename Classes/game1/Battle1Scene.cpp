
#include "Battle1Scene.h"

USING_NS_CC;

Scene* Battle1::createScene()
{
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0, 0));
	auto layer = Battle1::create();
	auto battleUI = Battle1UI::create();
	scene->addChild(layer, 0, 0);
	scene->addChild(battleUI, 1,1);
	return scene;
}

void Battle1::scheduleSkill(cocos2d::CCObject * obj)
{

	//mProgressTimer->setVisible(true);
	//mProgressTimer->setType(kCCProgressTimerTypeRadial);
	//mProgressTimer->setReverseProgress(true); // 设置进度条为逆时针

	//CCActionInterval* action_progress_from_to = CCProgressFromTo::create(mCDTime, 100, 0);

	//CCCallFunc* action_callback = CCCallFuncN::create(this, callfuncN_selector(Battle1::skillCoolDown));
	//mProgressTimer->runAction(CCSequence::create(action_progress_from_to, action_callback, NULL));
}
void Battle1::skillCoolDown(CCNode * node)
{
	//// 进度条技能不可见
	//mProgressTimer->setVisible(false);

	//// 按钮置为可用
	//mItem1Skill->setEnabled(true);
}
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
bool Battle1::init()
{

    if ( !Layer::init() )
    {
        return false;
    }
	

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	SpriteFrameCache * frameCache = SpriteFrameCache::getInstance();
	Texture2D* herofront=Director::getInstance()->getTextureCache()->addImage("hero1.png");
	Texture2D* bossleft = Director::getInstance()->getTextureCache()->addImage("boss/Magic2.png");
    //使用纹理图集 
	hero = Hero::createWithTexture(herofront);
	boss = Boss::createWithTexture(bossleft,1);
    
	tileMap = Sprite::create("map/MagicRoom.png");
	if (tileMap == nullptr)
	{
		problemLoading("map/MagicRoom.png");
	}
	else
	{
		tileMap->setAnchorPoint(Vec2::ZERO);
		tileMap->setScale(1);
		addChild(tileMap, 0, 10);
	}

	if (hero == nullptr)
	{
		problemLoading("hero");
	}
	else
	{
		hero->setPosition(Vec2(tileMap->getContentSize().width / 2, visibleSize.height / 2 + origin.y));
		hero->setHp(100);
		hero->setInitHp(100);
		this->addChild(hero, 1, 20);
		boss->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		boss->setScale(1.2);
		boss->setHp(1000);
		boss->setInitHp(1000);
		this->addChild(boss, 1, 40);
	}

	auto body = PhysicsBody::createEdgeBox(Size(2280, 2100), PhysicsMaterial(1, 0, 0));
	auto edgeNode = Node::create();
	edgeNode->setPosition(1200, 1110);
	edgeNode->setPhysicsBody(body);
	body->setCategoryBitmask(0xFFFFFFFF);
	body->setCollisionBitmask(0xFFFFFFFF);
	body->setContactTestBitmask(0xFFFFFFFF);
	this->addChild(edgeNode,0,30);

	auto label1 = Label::createWithSystemFont("Heaven", "Arial", 36);
	label1->setPosition(Vec2(tileMap->getContentSize().width / 2, 600));
	this->addChild(label1, 1);
	label1->setOpacity(0);//FadeIn之前先设置精灵不透明度，0~255,0为完全透明
	FiniteTimeAction* ac0 = (FiniteTimeAction*)label1->runAction(FadeIn::create(1));
	FiniteTimeAction* ac1 = (FiniteTimeAction*)label1->runAction(FadeOut::create(1));
	label1->runAction(Sequence::create(ac0, ac1, NULL));

	Door = Sprite::create("ingame/door.png");
	Door->setPosition(0,0);
	Door->setScale(0.0);
	addChild(Door, 2, 300);

	WallContact = 0;

	for (int i = 1; i <= 40; i++)
	{
		skillDemage[i] = 0;
		skillMaxDemage[i] = 20;
	}
	skillMaxDemage[1] = 1000;
	skillMaxDemage[8] = 1000;

	keypressa = 0;
	keypressd = 0;
	keypresss = 0;
	keypressw = 0;

	return true;
}
void Battle1::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{
	Texture2D* herofront = Director::getInstance()->getTextureCache()->addImage("hero1.png");
	Texture2D* heroback = Director::getInstance()->getTextureCache()->addImage("hero2.png");
	Texture2D* heroleft = Director::getInstance()->getTextureCache()->addImage("hero3.png");
	Texture2D* heroright = Director::getInstance()->getTextureCache()->addImage("hero4.png");
	int speed=hero->getMovingSpeed();
	auto herobody = hero->getPhysicsBody();
	Vec2 heroPos = hero->getPosition();
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_D) {
		herobody->setVelocity((Vec2(speed, hero->getPhysicsBody()->getVelocity().y)));
		keypressd = 1;
	}
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_W) {
		herobody->setVelocity((Vec2(hero->getPhysicsBody()->getVelocity().x, speed)));
		keypressw = 1;
	}
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_A) {
		herobody->setVelocity(Vec2(-speed, hero->getPhysicsBody()->getVelocity().y)); 
		keypressa = 1;
	}
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_S) {
		herobody->setVelocity(Vec2(hero->getPhysicsBody()->getVelocity().x, -speed));
		keypresss = 1;
	}
	if (hero->getPhysicsBody()->getVelocity().x > 0)hero->setTexture(heroleft);
	if (hero->getPhysicsBody()->getVelocity().x < 0)hero->setTexture(heroright);
	if (hero->getPhysicsBody()->getVelocity().y > 0)hero->setTexture(heroback);
	if (hero->getPhysicsBody()->getVelocity().y < 0)hero->setTexture(herofront);
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_SPACE) {
		Vec2 heroPos = hero->getPosition();
		Vec2 setposition = Vec2(10, 0)*keypressd + Vec2(-10, 0)*keypressa + Vec2(0, 10)*keypressw + Vec2(0, -10)*keypresss;
		if (setposition != Vec2::ZERO&&heroSkill.skillCDover[hero->Skill[2]]==1)
		{
			heroSkill.skillCDover[hero->Skill[2]] = 0;
			heroSkill.skillrelease(hero->Skill[2], (Layer*)Director::getInstance()->getRunningScene()->getChildByTag(0), MousePoint);
			float distance = setposition.length();
			Vec2 truepoint = Vec2(setposition.x / distance * 300, setposition.y / distance * 300)+ hero->getPosition() ;
			Vec2 firepoint = truepoint - hero->getPosition();
			truepoint.x = max(min(truepoint.x, 2300.0f), 100.0f);
			truepoint.y = max(min(truepoint.y, 2200.0f), 140.0f);
			hero->setPosition(truepoint);





			switch (hero->Skill[2])
			{
			case 7:
			{

				Sprite * blackhole = Sprite::create();
				this->addChild(blackhole, 5, 70);

				Animation * animation = Animation::create();
				SpriteFrameCache::getInstance()->addSpriteFramesWithFile("skill/blackhole.plist");
				SpriteFrame *blackhole1 = SpriteFrameCache::getInstance()->getSpriteFrameByName("blackhole3.png");
				SpriteFrame *blackhole2 = SpriteFrameCache::getInstance()->getSpriteFrameByName("blackhole1.png");
				SpriteFrame *blackhole3 = SpriteFrameCache::getInstance()->getSpriteFrameByName("blackhole2.png");
				animation->addSpriteFrame(blackhole1);
				animation->addSpriteFrame(blackhole2);
				animation->addSpriteFrame(blackhole3);
				animation->setDelayPerUnit(0.1);
				animation->setRestoreOriginalFrame(true);
				Animate *action = Animate::create(animation);
				blackhole->setPosition(hero->getPosition());
				blackhole->runAction(action);
			}
			case 8:
			{
				for (int i = 0; i < 3; i++)
				{
					if (setposition.x != 0) {
						SkillSprite *tracefire = SkillSprite::create("skill/tracefire.png");
						tracefire->setPosition(heroPos + Vec2(0, tracefire->getContentSize().height * 3)*(i - 1));
						FiniteTimeAction*ac0 = (FiniteTimeAction*)tracefire->runAction(MoveBy::create(1, (firepoint) * 3 - Vec2(0, tracefire->getContentSize().height * 3)*(i - 1)));
						FiniteTimeAction*acf = CCCallFuncN::create(CC_CALLBACK_1(Battle1::traceRemove, this));
						tracefire->runAction(Sequence::create(ac0, acf, NULL));
						tracefire->setDemage(heroSkill.skillDemage[hero->Skill[2]]);
						auto tracebody = PhysicsBody::createCircle(23.101, PhysicsMaterial(1, 0, 0), Vec2(-10.429, 4.071));
						tracebody->setCategoryBitmask(0xFFFFFFFF);
						tracebody->setCollisionBitmask(0x00000000);
						tracebody->setContactTestBitmask(0xFFFFFFFF);
						tracefire->setPhysicsBody(tracebody);
						tracefire->setColor(Color3B::GREEN);
						addChild(tracefire, 5, 801 + i);
					}
					else
					{
						SkillSprite *tracefire = SkillSprite::create("skill/tracefire.png");
						tracefire->setPosition(heroPos + Vec2((tracefire->getContentSize().width * 3)*(i - 1), 0));
						FiniteTimeAction*ac0 = (FiniteTimeAction*)tracefire->runAction(MoveBy::create(1, (firepoint) * 3 - Vec2((tracefire->getContentSize().width * 3)*(i - 1),0)));
						FiniteTimeAction*acf = CCCallFuncN::create(CC_CALLBACK_1(Battle1::traceRemove, this));
						tracefire->runAction(Sequence::create(ac0, acf, NULL));
						tracefire->setDemage(heroSkill.skillDemage[hero->Skill[2]]);
						auto tracebody = PhysicsBody::createCircle(23.101, PhysicsMaterial(1, 0, 0), Vec2(-10.429, 4.071));
						tracebody->setCategoryBitmask(0xFFFFFFFF);
						tracebody->setCollisionBitmask(0x00000000);
						tracebody->setContactTestBitmask(0xFFFFFFFF);
						tracefire->setPhysicsBody(tracebody);
						tracefire->setColor(Color3B::GREEN);
						addChild(tracefire, 5, 801 + i);
					}
				}
			}
			}
		}

	}


	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_Q) {
		heroSkill.skillrelease(hero->Skill[4],(Layer*)Director::getInstance()->getRunningScene()->getChildByTag(0), MousePoint);
	}
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_E) {
		heroSkill.skillrelease(hero->Skill[5],(Layer*)Director::getInstance()->getRunningScene()->getChildByTag(0), MousePoint);
	}
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_SHIFT) {
		heroSkill.skillrelease(hero->Skill[6],(Layer*)Director::getInstance()->getRunningScene()->getChildByTag(0), MousePoint);
	}
}
void Battle1::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{

	Texture2D* herofront = Director::getInstance()->getTextureCache()->addImage("hero1.png");
	Texture2D* heroback = Director::getInstance()->getTextureCache()->addImage("hero2.png");
	Texture2D* heroleft = Director::getInstance()->getTextureCache()->addImage("hero3.png");
	Texture2D* heroright = Director::getInstance()->getTextureCache()->addImage("hero4.png");
	int speed = hero->getMovingSpeed();
	auto herobody = hero->getPhysicsBody();
	Vec2 heroPos = hero->getPosition();
	if (herobody->getVelocity().length() != 0) {

		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_D) {
			if (herobody->getVelocity().x > 0)herobody->setVelocity(herobody->getVelocity() - Vec2(speed, 0)); 
			keypressd = 0;
		}
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_W) {
			if (herobody->getVelocity().y > 0)herobody->setVelocity(herobody->getVelocity() - Vec2(0, speed)); 
			keypressw = 0;
		}
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_A) {
			if (herobody->getVelocity().x < 0)herobody->setVelocity(herobody->getVelocity() + Vec2(speed, 0)); 
			keypressa = 0;
		}
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_S) {
			if (herobody->getVelocity().y < 0)herobody->setVelocity(herobody->getVelocity() + Vec2(0, speed)); 
			keypresss = 0;
		}
	}
	else
	{
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_D) {
			keypressd = 0;
		}
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_W) {
			keypressw = 0;
		}
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_A) {
			keypressa = 0;
		}
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_S) {
			keypresss = 0;
		}

	}
	if (hero->getPhysicsBody()->getVelocity().x > 0)hero->setTexture(heroleft);
	if (hero->getPhysicsBody()->getVelocity().x < 0)hero->setTexture(heroright);
	if (hero->getPhysicsBody()->getVelocity().y > 0)hero->setTexture(heroback);
	if (hero->getPhysicsBody()->getVelocity().y < 0)hero->setTexture(herofront);
}
void Battle1::mouseDown(cocos2d::EventMouse * event)
{
	cocos2d::EventMouse::MouseButton mousebutton = (event->getMouseButton());
	if (mousebutton == cocos2d::EventMouse::MouseButton::BUTTON_LEFT) {
		switch (hero->Skill[1]) {
		case 10: 
		{
			heroSkill.skillrelease(hero->Skill[1], (Layer*)Director::getInstance()->getRunningScene()->getChildByTag(0), MousePoint);
			Vec2 bossoffset = boss->getPosition() - hero->getPosition();
			Vec2 mouseoffset = MousePoint - hero->getPosition();
			if ((bossoffset).length() < 300 & (bossoffset.x* mouseoffset.x) > 0, (bossoffset.y* mouseoffset.y) > 0);
			{
				skillDemage[1] = skillDemage[1] + heroSkill.skillDemage[hero->Skill[1]];
			}
		}
		case 11: 
		{
			heroSkill.skillrelease(hero->Skill[1], (Layer*)Director::getInstance()->getRunningScene()->getChildByTag(0), MousePoint);
		}


		}
	}
}
void Battle1::mouseMove(cocos2d::EventMouse * event)
{
	MousePoint.x = event->getCursorX();
	MousePoint.y = event->getCursorY();
}
void Battle1::update(float dt)
{
	Vec2 heroPos = hero->getPosition();
	this->setViewpointCenter(heroPos);
	this->setheroposition();
	this->setheroframe();

	if (hero->getBoundingBox().intersectsRect(Door->getBoundingBox()))//进入传送门
		gotostore(this);
}
void Battle1::setViewpointCenter(Vec2 position)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	int x = MAX(position.x, visibleSize.width / 2);
	int y = MAX(position.y, visibleSize.height / 2);
	x = MIN(x, (tileMap->getContentSize().width - visibleSize.width / 2));
	y = MIN(y, (tileMap->getContentSize().height - visibleSize.height / 2));

	Vec2 pointA = Vec2(visibleSize.width / 2, visibleSize.height / 2);
	Vec2 pointB = Vec2(x, y);

	Vec2 offset = pointA - pointB;
	this ->setPosition(offset);
}
void Battle1::onEnter()
{
	Layer::onEnter();
	auto contactlistener = EventListenerPhysicsContact::create();
	contactlistener->onContactBegin= CC_CALLBACK_1(Battle1::ContactBegin, this);
	contactlistener->onContactPreSolve = CC_CALLBACK_2(Battle1::ContactPreSolve, this);
	contactlistener->onContactPostSolve = CC_CALLBACK_2(Battle1::ContactPostSolve, this);
	contactlistener->onContactSeparate = CC_CALLBACK_1(Battle1::ContactSeparate, this);

	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(Battle1::keyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(Battle1::keyReleased, this);

	auto mouseListener = EventListenerMouse::create();
	mouseListener->onMouseDown = CC_CALLBACK_1(Battle1::mouseDown, this);
	mouseListener->onMouseMove = CC_CALLBACK_1(Battle1::mouseMove, this);

	auto eventDispatcher = Director::getInstance()->getEventDispatcher();
	eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);
	eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);
	eventDispatcher->addEventListenerWithSceneGraphPriority(contactlistener, this);

	this->schedule(schedule_selector(Battle1::update), 1.0f / 60);
	this->schedule(schedule_selector(Battle1::BloodControl), 12.0f / 60);
	this->schedule(schedule_selector(Battle1::BossAttack), 90.0f / 60);
	this->schedule(schedule_selector(Battle1::traceSkill), 1.0f / 60);
}
bool Battle1::ContactBegin(PhysicsContact& contact)
{
	auto spriteA = (SkillSprite*)contact.getShapeA()->getBody()->getNode();
	auto spriteB = (SkillSprite*)contact.getShapeB()->getBody()->getNode();
	if (spriteA&&spriteA->getTag() > 100 &&spriteA->getTag() < 3100&&spriteB->getTag() == 40)
	{
		auto boss = (Boss*)contact.getShapeB()->getBody()->getNode();

		if (200 < spriteA->getTag() && spriteA->getTag() < 400) {
			int skillindex = spriteA->getTag() / 100;
			skillDemage[skillindex] = skillDemage[skillindex] + spriteA->getDemage();
			
		}
		else {
			if (1000<=spriteA->getTag())
			{
				int skillindex = spriteA->getTag() / 100;
				skillDemage[skillindex] = skillDemage[skillindex] + spriteA->getDemage();
				log("%i", skillindex);
			}
			else {
				spriteA->setVisible(false);
				spriteA->getPhysicsBody()->removeFromWorld();
				int skillindex = spriteA->getTag() / 100;
				skillDemage[skillindex] = skillDemage[skillindex] + spriteA->getDemage();
			}
		}
	}
	if (spriteB&&spriteB->getTag() > 100 &&spriteB->getTag() < 3100 && spriteA->getTag() == 40) {
		auto boss = (Boss*)contact.getShapeA()->getBody()->getNode();
		if (200 < spriteB->getTag() && spriteB->getTag() < 400) {
			int skillindex = spriteB->getTag() / 100;
			skillDemage[skillindex] = skillDemage[skillindex] + spriteB->getDemage();
		}
		else {
			if (1000 <= spriteB->getTag())
			{
				int skillindex = spriteA->getTag() / 100;
				skillDemage[skillindex] = skillDemage[skillindex] + spriteA->getDemage();
				log("%i", skillindex);
			}
			else {
				spriteB->setVisible(false);
				spriteB->getPhysicsBody()->removeFromWorld();
				int skillindex = spriteB->getTag() / 100;
				skillDemage[skillindex] = skillDemage[skillindex] + spriteB->getDemage();
			}
		}
	}



	if (spriteA&&spriteA->getTag() > 3100 && spriteB->getTag() == 20)
	{
		auto hero = (Hero*)contact.getShapeB()->getBody()->getNode();

		if (3100 < spriteA->getTag()) {
			int skillindex = spriteA->getTag() / 100;
			skillDemage[skillindex] = skillDemage[skillindex] + spriteA->getDemage();
		}
		else {
			spriteA->setVisible(false);
			spriteA->getPhysicsBody()->removeFromWorld();
			int skillindex = spriteA->getTag() / 100;
			skillDemage[skillindex] = skillDemage[skillindex] + spriteA->getDemage();
		}
	}
	if (spriteB&&spriteB->getTag() >3100 && spriteA->getTag() == 20) {
		auto hero = (Hero*)contact.getShapeA()->getBody()->getNode();

		if (3100 < spriteB->getTag() ) {
			int skillindex = spriteB->getTag() / 100;
			skillDemage[skillindex] = skillDemage[skillindex] + spriteB->getDemage();
		}
		else {
			spriteB->setVisible(false);
			spriteB->getPhysicsBody()->removeFromWorld();
			int skillindex = spriteB->getTag() / 100;
			skillDemage[skillindex] = skillDemage[skillindex] + spriteB->getDemage();
		}
	}




	return true;
}
bool Battle1::ContactPreSolve(PhysicsContact & contact, PhysicsContactPreSolve & solve)
{
	return true;
}
void Battle1::ContactPostSolve(PhysicsContact & contact, const PhysicsContactPostSolve & solve)
{

}
void Battle1::ContactSeparate(PhysicsContact & contact)
{

}
void Battle1::BloodControl(float dt)
{
	for (int i = 0; i <= 30; i++)
	{
		if (skillDemage[i] > 0) {
			if (skillDemage[i] > skillMaxDemage[i])skillDemage[i] = skillMaxDemage[i];

			String*demageLabel = String::createWithFormat("-%i", skillDemage[i]);
			auto label1 = Label::createWithSystemFont(demageLabel->getCString(), "Arial", 36);
			label1->setPosition(boss->getPosition());
			this->addChild(label1, 6);
			auto *upMove = MoveBy::create(1.0f, ccp(0, 100));
			auto *fadeOut = FadeOut::create(0.8f); // ����
			auto  *spawn = Spawn::create(upMove, fadeOut, NULL);
			label1->runAction(spawn);
			boss->setHp(boss->getHp() - skillDemage[i]);
			skillDemage[i] = 0;

		}

	}

	for (int i = 31; i <= 40; i++)
	{
		if (skillDemage[i] > 0) {
			if (skillDemage[i] > skillMaxDemage[i])skillDemage[i] = skillMaxDemage[i];
			hero->setHp(hero->getHp() - skillDemage[i]);
			skillDemage[i] = 0;

		}

	}

}

void Battle1::BossAttack(float dt)
{
	if (!bossAttack) {
		bossAttack = 1;
		Texture2D* bossleft = Director::getInstance()->getTextureCache()->addImage("boss/Magic2.png");
		Texture2D* bossright = Director::getInstance()->getTextureCache()->addImage("boss/Magic1.png");
		Vec2 heroposition = hero->getPosition();
		Vec2 bossposition = boss->getPosition();
		Vec2 heroworldposition = tileMap->convertToNodeSpace(heroposition);
		Vec2 bossworldposition = tileMap->convertToNodeSpace(bossposition);
		Vec2 distance = Vec2(heroworldposition.x - bossworldposition.x, heroworldposition.y - bossworldposition.y);
		if (distance.x < 0)boss->setTexture(bossleft);
		else { boss->setTexture(bossright); }
		bossSkill.skillrelease(31, this, MousePoint);
	}
	else {
		Texture2D* bossleft = Director::getInstance()->getTextureCache()->addImage("boss/Magic2.png");
		Texture2D* bossright = Director::getInstance()->getTextureCache()->addImage("boss/Magic1.png");
		Vec2 heroposition = hero->getPosition();
		Vec2 bossposition = boss->getPosition();
		Vec2 heroworldposition = tileMap->convertToNodeSpace(heroposition);
		Vec2 bossworldposition = tileMap->convertToNodeSpace(bossposition);
		Vec2 distance = Vec2(heroworldposition.x - bossworldposition.x, heroworldposition.y - bossworldposition.y);
		float length = distance.length();
		if (length == 0) { return; }
		Vec2 truepoint = Vec2(distance.x / length * (1000 < length ? 1000 : length), distance.y / length * (1000 < length ? 1000 : length));
		CCMoveBy* run = MoveBy::create(0.5*length / 1000, truepoint);
		ActionInterval *seq = Sequence::create(run, NULL);
		boss->runAction(seq);
		bossAttack = 0;
		if (distance.x < 0)boss->setTexture(bossleft);
		else { boss->setTexture(bossright); }
		/*}*/
	}
}
void Battle1::setheroposition()
{
	Vec2 heroPos = hero->getPosition();
	if (heroPos.x<100)
	{
		if(hero->getPhysicsBody()->getVelocity().x<0)
		hero->getPhysicsBody()->setVelocity(Vec2(0, hero->getPhysicsBody()->getVelocity().y));
	}
	if (heroPos.x > 2300)
	{
		if (hero->getPhysicsBody()->getVelocity().x > 0)
			hero->getPhysicsBody()->setVelocity(Vec2(0, hero->getPhysicsBody()->getVelocity().y));
	}
	if (heroPos.y > 2200)
	{
		if (hero->getPhysicsBody()->getVelocity().y > 0)
			hero->getPhysicsBody()->setVelocity(Vec2(hero->getPhysicsBody()->getVelocity().x, 0));
	}
	if (heroPos.y < 140)
	{
		if (hero->getPhysicsBody()->getVelocity().y < 0)
			hero->getPhysicsBody()->setVelocity(Vec2(hero->getPhysicsBody()->getVelocity().x,0));
	}
}
void Battle1::setheroframe()
{

	
}

void Battle1::traceRemove(Ref * psender)
{
	Sprite*sprite = (Sprite*)psender;
	sprite->removeFromParent();
}

//void Battle1::traceRemove(Ref*psender)
//{
//	auto sprite = (SkillSprite*)psender;
//	sprite->removeFromParent();
//}

void Battle1::gotostore(Ref *pSender)
{
	auto sc = Store1::createScene();
	Director::getInstance()->replaceScene(sc);
}

void Battle1::traceSkill(float dt)
{

	for (int i = 0; i < 6; i++) {

		if (this->getChildByTag(101 + i)) {
			SkillSprite * fireball = (SkillSprite*)this->getChildByTag(101 + i);

			Vec2 fireballposition = fireball->getPosition();
			Vec2 bossposition = boss->getPosition();
			Vec2 fireballtrueposition = tileMap->convertToNodeSpace(fireballposition);
			Vec2 bossworldposition = tileMap->convertToNodeSpace(bossposition);
			Vec2 distance = Vec2(bossworldposition.x - fireballtrueposition.x, bossworldposition.y - fireballtrueposition.y);
			float length = distance.length();
			if (length == 0) { return; }
			Vec2 truepoint = Vec2(distance.x / length * 20, distance.y / length * 20);
			if (length < 500) {
				CCMoveBy* run = MoveBy::create(1.0f / 60, truepoint);
				ActionInterval *seq = Sequence::create(run,NULL);
				fireball->runAction(seq);
			}
			else
			{
				fireball->setPosition(hero->getPosition() + heroSkill.fireballoffset[i]);
			}			
		}
	}
}