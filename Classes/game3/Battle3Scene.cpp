
#include "Battle3Scene.h"

USING_NS_CC;

Scene* Battle3::createScene()
{
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0, 0));
	auto layer = Battle3::create();
	auto battleUI = Battle3UI::create();
	scene->addChild(layer, 0, 0);
	scene->addChild(battleUI, 1,1);
	return scene;
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
bool Battle3::init()
{

    if ( !Layer::init() )
    {
        return false;
    }
	

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	SpriteFrameCache * frameCache = SpriteFrameCache::getInstance();
	Texture2D* herofront=Director::getInstance()->getTextureCache()->addImage("hero1.png");
    //使用纹理图集 
	hero = Hero::createWithTexture(herofront);
	boss = Boss::createWithTexture(herofront,1);
    
	tileMap = Sprite::create("map/Church.png");
	if (tileMap == nullptr)
	{
		problemLoading("map/Church.png");
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
		boss->setScale(10);
		boss->setColor(Color3B::BLACK);
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

	for (int i = 1; i <= 20; i++)
	{
		skillDemage[i] = 0;
		skillMaxDemage[i] = 10;
	}
	skillMaxDemage[1] = 1000;

	return true;
}
void Battle3::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
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
	}
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_W) {
		herobody->setVelocity((Vec2(hero->getPhysicsBody()->getVelocity().x, speed)));
	}
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_A) {
		herobody->setVelocity(Vec2(-speed, hero->getPhysicsBody()->getVelocity().y)); 
	}
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_S) {
		herobody->setVelocity(Vec2(hero->getPhysicsBody()->getVelocity().x, -speed)); 
	}
	if (hero->getPhysicsBody()->getVelocity().x > 0)hero->setTexture(heroleft);
	if (hero->getPhysicsBody()->getVelocity().x < 0)hero->setTexture(heroright);
	if (hero->getPhysicsBody()->getVelocity().y > 0)hero->setTexture(heroback);
	if (hero->getPhysicsBody()->getVelocity().y < 0)hero->setTexture(herofront);
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_SPACE) {
		heroSkill.skillrelease(hero->Skill[2],(Layer*)Director::getInstance()->getRunningScene()->getChildByTag(0), MousePoint);
	}
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_Q) {
		heroSkill.skillrelease(hero->Skill[1],(Layer*)Director::getInstance()->getRunningScene()->getChildByTag(0), MousePoint);
	}
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_E) {
		heroSkill.skillrelease(hero->Skill[2],(Layer*)Director::getInstance()->getRunningScene()->getChildByTag(0), MousePoint);
	}
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_SHIFT) {
		heroSkill.skillrelease(hero->Skill[3], (Layer*)Director::getInstance()->getRunningScene()->getChildByTag(0), MousePoint);
	}
}
void Battle3::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
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
		}
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_W) {
			if (herobody->getVelocity().y > 0)herobody->setVelocity(herobody->getVelocity() - Vec2(0, speed)); 
		}
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_A) {
			if (herobody->getVelocity().x < 0)herobody->setVelocity(herobody->getVelocity() + Vec2(speed, 0)); 
		}
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_S) {
			if (herobody->getVelocity().y < 0)herobody->setVelocity(herobody->getVelocity() + Vec2(0, speed)); 
		}
	}
	if (hero->getPhysicsBody()->getVelocity().x > 0)hero->setTexture(heroleft);
	if (hero->getPhysicsBody()->getVelocity().x < 0)hero->setTexture(heroright);
	if (hero->getPhysicsBody()->getVelocity().y > 0)hero->setTexture(heroback);
	if (hero->getPhysicsBody()->getVelocity().y < 0)hero->setTexture(herofront);
}
void Battle3::mouseDown(cocos2d::EventMouse * event)
{
	cocos2d::EventMouse::MouseButton mousebutton = (event->getMouseButton());
	if (mousebutton == cocos2d::EventMouse::MouseButton::BUTTON_LEFT) {
		heroSkill.skillrelease(hero->Skill[4],(Layer*)Director::getInstance()->getRunningScene()->getChildByTag(0), MousePoint);
	}
}
void Battle3::mouseMove(cocos2d::EventMouse * event)
{
	MousePoint.x = event->getCursorX();
	MousePoint.y = event->getCursorY();
}
bool isend = true;
int endtime = 0;
void Battle3::update(float dt)
{
	Vec2 heroPos = hero->getPosition();
	this->setViewpointCenter(heroPos);
	this->setheroposition();
	this->setheroframe();
	if (hero->getBoundingBox().intersectsRect(Door->getBoundingBox()))//进入传送门
	{
		endtime++;
		if (isend)
		{
			isend = false;
			end(this);
		}
		if (endtime == 2400)
		{
			Director::getInstance()->popToSceneStackLevel(0);
		}
	}
}
void Battle3::setViewpointCenter(Vec2 position)
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
void Battle3::onEnter()
{
	Layer::onEnter();
	auto contactlistener = EventListenerPhysicsContact::create();
	contactlistener->onContactBegin= CC_CALLBACK_1(Battle3::ContactBegin, this);
	contactlistener->onContactPreSolve = CC_CALLBACK_2(Battle3::ContactPreSolve, this);
	contactlistener->onContactPostSolve = CC_CALLBACK_2(Battle3::ContactPostSolve, this);
	contactlistener->onContactSeparate = CC_CALLBACK_1(Battle3::ContactSeparate, this);

	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(Battle3::keyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(Battle3::keyReleased, this);

	auto mouseListener = EventListenerMouse::create();
	mouseListener->onMouseDown = CC_CALLBACK_1(Battle3::mouseDown, this);
	mouseListener->onMouseMove = CC_CALLBACK_1(Battle3::mouseMove, this);

	auto eventDispatcher = Director::getInstance()->getEventDispatcher();
	eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);
	eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);
	eventDispatcher->addEventListenerWithSceneGraphPriority(contactlistener, this);

	this->schedule(schedule_selector(Battle3::update), 1.0f / 60);
	this->schedule(schedule_selector(Battle3::BloodControl), 12.0f / 60);
	this->schedule(schedule_selector(Battle3::BossAttack), 90.0f / 60);
	this->schedule(schedule_selector(Battle3::traceSkill), 1.0f / 60);
}
bool Battle3::ContactBegin(PhysicsContact& contact)
{
	auto spriteA = (SkillSprite*)contact.getShapeA()->getBody()->getNode();
	auto spriteB = (SkillSprite*)contact.getShapeB()->getBody()->getNode();
	if (spriteA&&spriteA->getTag() > 100 && spriteB->getTag() == 40)
	{
		auto boss = (Hero*)contact.getShapeB()->getBody()->getNode();

		if (200 < spriteA->getTag() && spriteA->getTag() < 400) {
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
	if (spriteB&&spriteB->getTag() > 100 && spriteA->getTag() == 40) {
		auto boss = (Hero*)contact.getShapeA()->getBody()->getNode();

		if (200 < spriteB->getTag() && spriteB->getTag() < 400) {
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
bool Battle3::ContactPreSolve(PhysicsContact & contact, PhysicsContactPreSolve & solve)
{
	return true;
}
void Battle3::ContactPostSolve(PhysicsContact & contact, const PhysicsContactPostSolve & solve)
{

}
void Battle3::ContactSeparate(PhysicsContact & contact)
{

}
void Battle3::BloodControl(float dt)
{
	for (int i = 0; i <= 20; i++)
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


}

void Battle3::BossAttack(float dt)
{
	if (!bossAttack) {
		bossAttack = 1;
	}
	else {
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
	}
}
void Battle3::setheroposition()
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
void Battle3::setheroframe()
{

	
}

void Battle3::gotostore(Ref *pSender)
{
	auto sc = Store1::createScene();
	Director::getInstance()->replaceScene(sc);
}

void Battle3::traceSkill(float dt)
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
				ActionInterval *seq = Sequence::create(run, NULL);
				fireball->runAction(seq);
			}
			else
			{
				fireball->setPosition(hero->getPosition() + heroSkill.fireballoffset[i]);
			}
		}
	}
}
void Battle3::end(cocos2d::Ref* pSender)
{
	theend = Sprite::create("text/end.png");
	theend->setAnchorPoint(Vec2(0.5, 0));
	theend->setScale(2);
	theend->setPosition(1200, -1000);
	this->addChild(theend, 10);
	theend->runAction(MoveTo::create(30, Vec2(1200, 1800)));
}