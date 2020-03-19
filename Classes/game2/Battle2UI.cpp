#include "Battle2UI.h"
#include "store1/store.h"

void Battle2UI::scheduleBlood(float delta)
{
	auto boss = (Boss *)Director::getInstance()->getRunningScene()->getChildByTag(0)->getChildByTag(40);
	auto Door = (Sprite *)Director::getInstance()->getRunningScene()->getChildByTag(0)->getChildByTag(300);
	auto bossprogress = (ProgressTimer *)this->getChildByTag(50);
	bossprogress->setPercentage((((float)boss->getHp()) / boss->getInitHp()) * 100);  //�����ǰٷ�����ʾ
	if (bossprogress->getPercentage() == 0)
	{
		boss->setScale(0);
		Door->setScale(1);
		Door->setPosition(boss->getPosition());
	}

	auto hero = (Hero *)Director::getInstance()->getRunningScene()->getChildByTag(0)->getChildByTag(20);
	auto heroprogress = (ProgressTimer *)this->getChildByTag(80);
	heroprogress->setPercentage((((float)hero->getHp()) / hero->getInitHp()) * 100);  //�����ǰٷ�����ʾ

}

bool Battle2UI::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto bossbloodframe = Sprite::create("bloodframe.png");   //�������ȿ�
	bossbloodframe->setPosition(visibleSize.width / 2 , visibleSize.height- bossbloodframe->getContentSize().height); //���ÿ��λ��
	this->addChild(bossbloodframe);            //�ӵ�Ĭ��ͼ������ȥ
	auto bossbloodbar = Sprite::create("bloodbar.png");  //����Ѫ��
	ProgressTimer * bossProgressTimer = ProgressTimer::create(bossbloodbar); //����progress����
	bossProgressTimer->setType(ProgressTimer::Type::BAR);        //���ͣ���״
	bossProgressTimer->setPosition( visibleSize.width / 2 , visibleSize.height- bossbloodframe->getContentSize().height);
	//���ҵ������Ѫ��
	bossProgressTimer->setMidpoint(Point(0, 0.5));     //����Ǵ����ҵĻ����ĳ�(1,0.5)����
	bossProgressTimer->setBarChangeRate(Point(1, 0));
	bossProgressTimer->setTag(50);       //��һ�����
	this->addChild(bossProgressTimer);

	auto herobloodframe = Sprite::create("bloodframe.png");   //�������ȿ�
	herobloodframe->setPosition(herobloodframe->getContentSize().width / 2, visibleSize.height - herobloodframe->getContentSize().height); //���ÿ��λ��
	this->addChild(herobloodframe);            //�ӵ�Ĭ��ͼ������ȥ
	auto herobloodbar = Sprite::create("bloodbar.png");  //����Ѫ��
	ProgressTimer * heroProgressTimer = ProgressTimer::create(herobloodbar); //����progress����
	heroProgressTimer->setType(ProgressTimer::Type::BAR);        //���ͣ���״
	heroProgressTimer->setPosition(herobloodframe->getContentSize().width/2, visibleSize.height - herobloodframe->getContentSize().height);
	//���ҵ������Ѫ��
	heroProgressTimer->setMidpoint(Point(0, 0.5));     //����Ǵ����ҵĻ����ĳ�(1,0.5)����
	heroProgressTimer->setBarChangeRate(Point(1, 0));
	heroProgressTimer->setTag(80);       //��һ�����
	this->addChild(heroProgressTimer);


	this->schedule(schedule_selector(Battle2UI::scheduleBlood),0.1f);  //ˢ�º�����ÿ��0.1��


	skillCD = new Sprite();

	//����
	//�չ�
	skill1 = Sprite::create("skill/Normal1.png");
	skill1->setPosition(Vec2(70, 50));
	skill1->setTag(HERO_NORMAL_TAG);
	skillCDbutton[1] = skill1;
	//��˸
	skill2 = Sprite::create("skill/Blink1.png");
	skill2->setPosition(Vec2(70 * 2, 50));
	skill2->setTag(HERO_BLINK_TAG);
	skillCDbutton[2] = skill2;
	//���⼼��
	skill3 = Sprite::create("skill/Point1.png");
	skill3->setPosition(Vec2(70 * 3, 50));
	skill3->setTag(HERO_SPECIAL1_TAG);
	skillCDbutton[3] = skill3;

	skill4 = Sprite::create("skill/Round1.png");
	skill4->setPosition(Vec2(70 * 4, 50));
	skill4->setTag(HERO_SPECIAL2_TAG);
	skillCDbutton[4] = skill4;

	skill5 = Sprite::create("skill/Special1.png");
	skill5->setPosition(Vec2(70 * 5, 50));
	skill5->setTag(HERO_SPECIAL3_TAG);
	skillCDbutton[5] = skill5;

	skill6 = Sprite::create("skill/Follow1.png");
	skill6->setPosition(Vec2(70 * 6, 50));
	skill6->setTag(HERO_SPECIAL4_TAG);
	skillCDbutton[6] = skill6;

	//����
	skill7 = Sprite::create("skill/Buff1.png");
	skill7->setPosition(Vec2(70 * 7, visibleSize.height - 50));
	skill7->setTag(HERO_BUFF_TAG);
	this->addChild(skill7, 3);


	//�����Ϸ��İ�����ʾ
	left = Sprite::create("skill/left.png");
	left->setPosition(Vec2(70, 80));
	left->setScale(0.5);
	this->addChild(left, 4);

	space = Sprite::create("skill/space.png");
	space->setPosition(Vec2(70 * 2, 80));
	space->setScale(0.5);
	this->addChild(space, 4);

	right = Sprite::create("skill/right.png");
	right->setPosition(Vec2(70 * 3, 80));
	right->setScale(0.5);
	this->addChild(right, 4);

	q = Sprite::create("skill/q.png");
	q->setPosition(Vec2(70 * 4, 80));
	q->setScale(0.5);
	this->addChild(q, 4);

	e = Sprite::create("skill/e.png");
	e->setPosition(Vec2(70 * 5, 80));
	e->setScale(0.5);
	this->addChild(e, 4);

	shift = Sprite::create("skill/shift.png");
	shift->setPosition(Vec2(70 * 6, 80));
	shift->setScale(0.5);
	this->addChild(shift, 4);

	//״̬

	for (int i = 1; i <= 6; i++)
	{
		skillCDbutton[i]->setPosition(((skillCDbutton[i]->getContentSize().width+10)*(i - 1)), 0);
		skillCD->addChild(skillCDbutton[i], 0, 1);
	}

	skillCD->setPosition(70, 50);
	this->addChild(skillCD, 3, 60);


	return true;
}
