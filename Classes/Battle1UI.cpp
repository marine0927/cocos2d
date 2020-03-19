#include "Battle1UI.h"

void Battle1UI::scheduleBlood(float delta)
{
	auto boss = (Boss *)Director::getInstance()->getRunningScene()->getChildByTag(0)->getChildByTag(40);
	auto progress = (ProgressTimer *)this->getChildByTag(50);
	progress->setPercentage((((float)boss->getHp()) / boss->getInitHp()) * 100);  //�����ǰٷ�����ʾ
}

bool Battle1UI::init()
{
	auto bloodframe = Sprite::create("bloodframe.png");   //�������ȿ�
	bloodframe->setPosition(400, 800); //���ÿ��λ��
	this->addChild(bloodframe);    //�ӵ�Ĭ��ͼ������ȥ

	auto headshot = Sprite::create("headshot.png");//Ѫ���Աߵ�ͷ��
	headshot->setPosition(Vec2(59, 800));
	this->addChild(headshot);

	auto bloodlabel = Label::createWithSystemFont("525/525", "Arial", 36);//��������Ѫ��������
	bloodlabel->setPosition(700, 850);//
	this->addChild(bloodlabel);


	auto bloodbar = Sprite::create("bloodbar.png");  //����Ѫ��
	ProgressTimer * mProgressTimer = ProgressTimer::create(bloodbar); //����progress����
	mProgressTimer->setType(ProgressTimer::Type::BAR);        //���ͣ���״
	mProgressTimer->setPosition(400, 800);
	//���ҵ������Ѫ��
	mProgressTimer->setMidpoint(Point(0, 0.5));     //����Ǵ����ҵĻ����ĳ�(1,0.5)����
	mProgressTimer->setBarChangeRate(Point(1, 0));
	mProgressTimer->setTag(50);       //��һ�����
	this->addChild(mProgressTimer);
	schedule(schedule_selector(Battle1UI::scheduleBlood, 0.1f));  //ˢ�º�����ÿ��0.1��


	skillCD = new Sprite();
	for (int i = 1; i <= 6; i++)
	{
		skillCDbutton[i] = Sprite::create("click.png");
		skillCDbutton[i]->setPosition(skillCDbutton[i]->getContentSize().width*(i - 1), 0);
		skillCD->addChild(skillCDbutton[i], 0, 1);
	}

	skillCD->setPosition(200, 200);
	this->addChild(skillCD, 5, 60);


	return true;
}
