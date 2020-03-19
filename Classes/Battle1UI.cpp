#include "Battle1UI.h"

void Battle1UI::scheduleBlood(float delta)
{
	auto boss = (Boss *)Director::getInstance()->getRunningScene()->getChildByTag(0)->getChildByTag(40);
	auto progress = (ProgressTimer *)this->getChildByTag(50);
	progress->setPercentage((((float)boss->getHp()) / boss->getInitHp()) * 100);  //这里是百分制显示
}

bool Battle1UI::init()
{
	auto bloodframe = Sprite::create("bloodframe.png");   //创建进度框
	bloodframe->setPosition(400, 800); //设置框的位置
	this->addChild(bloodframe);    //加到默认图层里面去

	auto headshot = Sprite::create("headshot.png");//血条旁边的头像
	headshot->setPosition(Vec2(59, 800));
	this->addChild(headshot);

	auto bloodlabel = Label::createWithSystemFont("525/525", "Arial", 36);//在这里是血条的数字
	bloodlabel->setPosition(700, 850);//
	this->addChild(bloodlabel);


	auto bloodbar = Sprite::create("bloodbar.png");  //创建血条
	ProgressTimer * mProgressTimer = ProgressTimer::create(bloodbar); //创建progress对象
	mProgressTimer->setType(ProgressTimer::Type::BAR);        //类型：条状
	mProgressTimer->setPosition(400, 800);
	//从右到左减少血量
	mProgressTimer->setMidpoint(Point(0, 0.5));     //如果是从左到右的话，改成(1,0.5)即可
	mProgressTimer->setBarChangeRate(Point(1, 0));
	mProgressTimer->setTag(50);       //做一个标记
	this->addChild(mProgressTimer);
	schedule(schedule_selector(Battle1UI::scheduleBlood, 0.1f));  //刷新函数，每隔0.1秒


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
