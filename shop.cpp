#include "shop.h"
#include "player.h"
#include "shop_jinggao.h"
#include <QPushButton>
#include <QDebug>

extern Player player;
void setToolTip(const QString &);

Shop::Shop(QWidget *parent) : QWidget(parent)
{

    setFixedSize(300,700);
    setWindowTitle("商店呐~");
    QPushButton * buy1=new QPushButton;
    buy1->setParent(this);
    buy1->setText("长剑");
    connect(buy1, &QPushButton::clicked, this, &Shop::sword1);
    buy1->setToolTip("攻击+3");
    buy1->move(120,50);
    buy1->setIcon(QIcon(":/new/prefix1/resources/shop/1.png"));
    buy1->setIconSize(QSize(20,20));

    QPushButton * buy2=new QPushButton;
    buy2->setParent(this);
    buy2->setText("短剑");
    connect(buy2, &QPushButton::clicked, this, &Shop::sword2);
    buy2->setToolTip("攻击+1");
    buy2->move(20,50);
    buy2->setIcon(QIcon(":/new/prefix1/resources/shop/3.png"));
    buy2->setIconSize(QSize(20,20));

    QPushButton * buy4=new QPushButton;
    buy4->setParent(this);
    buy4->setText("巨剑");
    connect(buy4, &QPushButton::clicked, this, &Shop::sword3);
    buy4->setToolTip("攻击+10");
    buy4->move(220,50);
    buy4->setIcon(QIcon(":/new/prefix1/resources/shop/5.png"));
    buy4->setIconSize(QSize(20,20));

    QPushButton * buy3=new QPushButton;
    buy3->setParent(this);
    buy3->setText("小盾");
    buy3->setToolTip("防御+4\n闪避-3");
    connect(buy3, &QPushButton::clicked, this, &Shop::shield1);
    buy3->move(20,90);
    buy3->setIcon(QIcon(":/new/prefix1/resources/shop/2.png"));
    buy3->setIconSize(QSize(20,20));

    QPushButton * buy5=new QPushButton;
    buy5->setParent(this);
    buy5->setText("小药");
    buy5->setToolTip("生命+30");
    connect(buy5, &QPushButton::clicked, this, &Shop::yao1);
    buy5->move(120,90);
    buy5->setIcon(QIcon(":/new/prefix1/resources/shop/29.png"));
    buy5->setIconSize(QSize(20,20));
}

void Shop::sword1()
{
    money=player.getmoney();
    if(money>=50)
    {
        player.setattack(player.getattack()+3);
        player.setmoney(player.getmoney()-50);
    }
    else
        jinggao();
}

void Shop::sword2()
{
    money=player.getmoney();
    if(money>=30)
    {
        player.setattack(player.getattack()+1);
        player.setmoney(player.getmoney()-30);
    }
    else
        jinggao();
}

void Shop::sword3()
{
    money=player.getmoney();
    if(money>=300)
    {
        player.setattack(player.getattack()+10);
        player.setmoney(player.getmoney()-300);
    }
    else
        jinggao();
}

void Shop::shield1()
{
    money=player.getmoney();
    if(money>=100)
    {
        player.setdefend(player.getdefend()+4);
        player.setmoney(player.getmoney()-100);
        player.setmiss(player.getmiss()-3);
    }
    else
        jinggao();
}

void Shop::yao1()
{
    money=player.getmoney();
    if(money>=60)
    {
        player.sethp(player.gethp()+30);
        player.setmoney(player.getmoney()-60);
    }
    else
        jinggao();
}

void Shop::jinggao()
{
    shop_jinggao * error = new shop_jinggao();
    error->show();
}
