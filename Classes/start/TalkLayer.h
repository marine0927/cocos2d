#include "Talk.h"
#include "GameStartScene.h"
#include "store1/store.h"

USING_NS_CC;
bool show1 = true;
bool click = false;
bool Talk::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	talkbg = Sprite::create("talk/talkbg.png");
	talkbg->setAnchorPoint(Vec2(0.0, 0.0));
	talkbg->setPosition(Vec2(0, 0));
	talkbg->setOpacity(100);
	talkbg->setScale(0.0);
	talkbg->setTag(BG_TAG);
	this->addChild(talkbg, 6);
	
	this->scheduleUpdate();
	
	return true;
}

void Talk::update(float dt)
{

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);

	touchListener->onTouchBegan = CC_CALLBACK_2(Talk::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(Talk::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(Talk::onTouchEnded, this);

	EventDispatcher * toucheventDispatcher = Director::getInstance()->getEventDispatcher();
	toucheventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, getChildByTag(BG_TAG));
	if (showTalk)
		Talk::setScale(1.0);
	else
		Talk::setScale(0.0);
	if (talkTo1)
	{ 
		if (show1)
		{
			click = false;
			talkbg->setScale(1.0);
			show1 = false;
			label1 = CCLabelBMFontAnimated::createWithBMFont("fonts/NBFont1.fnt", "", cocos2d::TextHAlignment::CENTER, visibleSize.width, cocos2d::Vec2(0, 0));
			label1->setScale(0.5);
			label1->setTag(5);
			label1->setPosition(Vec2(heroX - 500, 150));
			this->addChild(label1, 7);

			label1->setString("well bro, It's hard to make that decision, I adore you.");
			label1->animateInTypewriter(1);
		}
		
		if (click)
		{
			click = false;
			label1->setScale(0.0);
			label2 = CCLabelBMFontAnimated::createWithBMFont("fonts/NBFont1.fnt", "", cocos2d::TextHAlignment::CENTER, visibleSize.width, cocos2d::Vec2(0, 0));
			label2->setScale(0.5);
			label2->setTag(5);
			label2->setPosition(Vec2(heroX - 500, 150));
			this->addChild(label2, 7);

			label2->setString("OK, at least let me help you a little bit.");
			label2->animateInTypewriter(1);

			tag = HERO_NORMAL_TAG;
			changeNormal = true;
			talkTo1 = false;
			show1 = true;
			//技能提示
			auto skilllabel = Label::createWithSystemFont("press left mouse button to hit", "Arial", 36);
			skilllabel->setPosition(Vec2(heroX-400, 600));
			this->addChild(skilllabel, 1);
			skilllabel->setOpacity(0);
			FiniteTimeAction* ac0 = (FiniteTimeAction*)skilllabel->runAction(FadeIn::create(1.5));
			FiniteTimeAction* ac1 = (FiniteTimeAction*)skilllabel->runAction(FadeOut::create(1.5));
			skilllabel->runAction(Sequence::create(ac0, ac1, NULL));

			tagin1 = INIT_NORMAL_TAG;
		}
	}

	if (talkTo2)
	{
		label2->setScale(0.0);
		if (show1)
		{
			click = false;
			talkbg->setScale(1.0);
			show1 = false;
			label3 = CCLabelBMFontAnimated::createWithBMFont("fonts/NBFont1.fnt", "", cocos2d::TextHAlignment::CENTER, visibleSize.width, cocos2d::Vec2(0, 0));
			label3->setScale(0.5);
			label3->setPosition(Vec2(heroX - 800, 150));
			this->addChild(label3, 7);

			label3->setString("I'm sorry......");
			label3->animateInTypewriter(1);
		}

		if (click)
		{
			click = false;
			label3->setScale(0.0);
			label4 = CCLabelBMFontAnimated::createWithBMFont("fonts/NBFont1.fnt", "", cocos2d::TextHAlignment::CENTER, visibleSize.width, cocos2d::Vec2(0, 0));
			label4->setScale(0.5);
			label4->setPosition(Vec2(heroX - 800, 150));
			this->addChild(label4, 7);

			label4->setString("It's my only thing I can teach you.");
			label4->animateInTypewriter(1);

			tag = HERO_BLINK_TAG;
			changeBlink = true;
			talkTo2 = false;
			show1 = true;
			//技能提示
			auto skilllabe2 = Label::createWithSystemFont("press SPACE to bilnk", "Arial", 36);
			skilllabe2->setPosition(Vec2(heroX - 650, 600));
			this->addChild(skilllabe2, 1);
			skilllabe2->setOpacity(0);
			FiniteTimeAction* ac0 = (FiniteTimeAction*)skilllabe2->runAction(FadeIn::create(1.5));
			FiniteTimeAction* ac1 = (FiniteTimeAction*)skilllabe2->runAction(FadeOut::create(1.5));
			skilllabe2->runAction(Sequence::create(ac0, ac1, NULL));

			tagin2 = INIT_BLINK_TAG;
		}
	}

	if (talkTo3)
	{
		label4->setScale(0.0);
		if (show1)
		{
			click = false;
			talkbg->setScale(1.0);
			show1 = false;
			label5 = CCLabelBMFontAnimated::createWithBMFont("fonts/NBFont1.fnt", "", cocos2d::TextHAlignment::CENTER, visibleSize.width, cocos2d::Vec2(0, 0));
			label5->setScale(0.5);
			label5->setPosition(Vec2(heroX - 500, 150));
			this->addChild(label5, 7);

			label5->setString("Here you are.");
			label5->animateInTypewriter(1);
		}

		if (click)
		{
			click = false;
			label5->setScale(0.0);
			label6 = CCLabelBMFontAnimated::createWithBMFont("fonts/NBFont1.fnt", "", cocos2d::TextHAlignment::CENTER, visibleSize.width, cocos2d::Vec2(0, 0));
			label6->setScale(0.5);
			label6->setPosition(Vec2(heroX - 500, 150));
			this->addChild(label6, 7);

			label6->setString("You need it, belive me.");
			label6->animateInTypewriter(1);

			tag = HERO_SPECIAL1_TAG;
			changeSpecial1 = true;
			talkTo3 = false;
			show1 = true;
			//技能提示
			auto skilllabe2 = Label::createWithSystemFont("press right mouse button to use it", "Arial", 36);
			skilllabe2->setPosition(Vec2(heroX - 400, 600));
			this->addChild(skilllabe2, 1);
			skilllabe2->setOpacity(0);
			FiniteTimeAction* ac0 = (FiniteTimeAction*)skilllabe2->runAction(FadeIn::create(1.5));
			FiniteTimeAction* ac1 = (FiniteTimeAction*)skilllabe2->runAction(FadeOut::create(1.5));
			skilllabe2->runAction(Sequence::create(ac0, ac1, NULL));

			tagin3 = INIT_SPECIAL1_TAG;
		}
	}

	if (talkTo4)
	{
		label6->setScale(0.0);
		if (show1)
		{
			click = false;
			talkbg->setScale(1.0);
			show1 = false;
			label7 = CCLabelBMFontAnimated::createWithBMFont("fonts/NBFont1.fnt", "", cocos2d::TextHAlignment::CENTER, visibleSize.width, cocos2d::Vec2(0, 0));
			label7->setScale(0.5);
			label7->setPosition(Vec2(heroX - 800, 150));
			this->addChild(label7, 7);

			label7->setString("Why you never tell me....");
			label7->animateInTypewriter(1);
		}

		if (click)
		{
			click = false;
			label7->setScale(0.0);
			label8 = CCLabelBMFontAnimated::createWithBMFont("fonts/NBFont1.fnt", "", cocos2d::TextHAlignment::CENTER, visibleSize.width, cocos2d::Vec2(0, 0));
			label8->setScale(0.5);
			label8->setPosition(Vec2(heroX - 800, 150));
			this->addChild(label8, 7);

			label8->setString("take it, please.");
			label8->animateInTypewriter(1);

			tag = HERO_SPECIAL2_TAG;
			changeSpecial2 = true;
			talkTo4 = false;
			show1 = true;
			//技能提示
			auto skilllabe2 = Label::createWithSystemFont("press Q to use it", "Arial", 36);
			skilllabe2->setPosition(Vec2(heroX - 650, 600));
			this->addChild(skilllabe2, 1);
			skilllabe2->setOpacity(0);
			FiniteTimeAction* ac0 = (FiniteTimeAction*)skilllabe2->runAction(FadeIn::create(1.5));
			FiniteTimeAction* ac1 = (FiniteTimeAction*)skilllabe2->runAction(FadeOut::create(1.5));
			skilllabe2->runAction(Sequence::create(ac0, ac1, NULL));

			tagin4 = INIT_SPECIAL2_TAG;
		}
	}

	if (talkTo5)
	{
		label8->setScale(0.0);
		if (show1)
		{
			click = false;
			talkbg->setScale(1.0);
			show1 = false;
			label9 = CCLabelBMFontAnimated::createWithBMFont("fonts/NBFont1.fnt", "", cocos2d::TextHAlignment::CENTER, visibleSize.width, cocos2d::Vec2(0, 0));
			label9->setScale(0.5);
			label9->setPosition(Vec2(heroX - 500, 150));
			this->addChild(label9, 7);

			label9->setString("Come on! Why? fxxk.");
			label9->animateInTypewriter(1);
		}

		if (click)
		{
			click = false;
			label9->setScale(0.0);
			label10 = CCLabelBMFontAnimated::createWithBMFont("fonts/NBFont1.fnt", "", cocos2d::TextHAlignment::CENTER, visibleSize.width, cocos2d::Vec2(0, 0));
			label10->setScale(0.5);
			label10->setPosition(Vec2(heroX - 500, 150));
			this->addChild(label10, 7);

			label10->setString("No death, promise.");
			label10->animateInTypewriter(1);

			tag = HERO_SPECIAL3_TAG;
			changeSpecial3 = true;
			talkTo5 = false;
			show1 = true;
			//技能提示
			auto skilllabe2 = Label::createWithSystemFont("press E to use it", "Arial", 36);
			skilllabe2->setPosition(Vec2(heroX - 400, 600));
			this->addChild(skilllabe2, 1);
			skilllabe2->setOpacity(0);
			FiniteTimeAction* ac0 = (FiniteTimeAction*)skilllabe2->runAction(FadeIn::create(1.5));
			FiniteTimeAction* ac1 = (FiniteTimeAction*)skilllabe2->runAction(FadeOut::create(1.5));
			skilllabe2->runAction(Sequence::create(ac0, ac1, NULL));

			tagin5 = INIT_SPECIAL3_TAG;
		}
	}

	if (talkTo6)
	{
		label10->setScale(0.0);
		if (show1)
		{
			click = false;
			talkbg->setScale(1.0);
			show1 = false;
			label11 = CCLabelBMFontAnimated::createWithBMFont("fonts/NBFont1.fnt", "", cocos2d::TextHAlignment::CENTER, visibleSize.width, cocos2d::Vec2(0, 0));
			label11->setScale(0.5);
			label11->setPosition(Vec2(heroX - 800, 150));
			this->addChild(label11, 7);

			label11->setString("My son....");
			label11->animateInTypewriter(1);
		}

		if (click)
		{
			click = false;
			label11->setScale(0.0);
			label12 = CCLabelBMFontAnimated::createWithBMFont("fonts/NBFont1.fnt", "", cocos2d::TextHAlignment::CENTER, visibleSize.width, cocos2d::Vec2(0, 0));
			label12->setScale(0.5);
			label12->setPosition(Vec2(heroX - 800, 150));
			this->addChild(label12, 7);

			label12->setString("Be brave, be calm, go ahead my son.");
			label12->animateInTypewriter(1);

			tag = HERO_SPECIAL4_TAG;
			changeSpecial4 = true;
			talkTo6 = false;
			show1 = true;
			//技能提示
			auto skilllabe2 = Label::createWithSystemFont("press SHIFT to use it", "Arial", 36);
			skilllabe2->setPosition(Vec2(heroX - 650, 600));
			this->addChild(skilllabe2, 1);
			skilllabe2->setOpacity(0);
			FiniteTimeAction* ac0 = (FiniteTimeAction*)skilllabe2->runAction(FadeIn::create(1.5));
			FiniteTimeAction* ac1 = (FiniteTimeAction*)skilllabe2->runAction(FadeOut::create(1.5));
			skilllabe2->runAction(Sequence::create(ac0, ac1, NULL));

			tagin6 = INIT_SPECIAL4_TAG;
			tagin7 = INIT_BUFF_TAG;
		}
	}
}

void Talk::onExitTransitionDidStart2()
{
	Layer::onExit();
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();

}
void Talk::onEnterTransitionDidFinish2()
{
	Layer::onEnter();
	
}


char *Talk::FontToUTF8(const char* font) 
{
	int len = MultiByteToWideChar(CP_ACP, 0, font, -1, NULL, 0);
	wchar_t *wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_ACP, 0, font, -1, wstr, len);
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
	char *str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
	if (wstr)delete[] wstr;
	return str;

}

bool Talk::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) {

	return true;

}

void Talk::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event) {

	return;
}

void Talk::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) {
	
	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	initPosition1 = target->getPosition();
	Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

	// 点击范围判断检测
	if (rect.containsPoint(locationInNode))
	{
		if (target->getTag() == BG_TAG)
		{
			click = true;
		}
	}
	return;
}

