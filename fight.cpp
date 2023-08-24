#include "fight.h"
#include "player.h"
#include "monster.h"
#include <QDebug>
#include <QPainter>
#include <QRect>

extern Player player;
extern monster monster;

Fight::Fight(QWidget *parent) : QWidget(parent)
{
    monster.sethp(160);
    monster.setdefend(20);
    monster.setexp(50);
    monster.setattack(50);
    setStyleSheet("background-image: url(:/new/prefix1/resources/fight_back/1.png)");
    backgroundImage.load(":/new/prefix1/resources/fight_back/1.png");
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Background, backgroundImage);
    this->setPalette(palette);

    monster.create();

    setFixedSize(640, 640);
    createButtonsLayout();
}

void Fight::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);

    // Draw image 1 in the square (40, 200) to (280, 440)
    QRect square1(40, 200, 240, 240);
    QImage image1(":/new/prefix1/resources/renwu/1.png");
    painter.drawImage(square1, image1);

    // Draw image 2 in the square (360, 150) to (600, 390)
    QRect square2(360, 150, 240, 240);
    QImage image2(":/new/prefix1/resources/monster/16.png");
    painter.drawImage(square2, image2);
}

void Fight::createButtonsLayout()
{
    buttonsLayout = new QGridLayout(this);
    buttonsLayout->setContentsMargins(0, 489, 0, 0);

    QPushButton *normalButton = new QPushButton("普通", this);
    QPushButton *skillButton = new QPushButton("技能", this);
    QPushButton *itemButton = new QPushButton("道具", this);
    QPushButton *retreatButton = new QPushButton("撤退", this);

    buttonsLayout->addWidget(normalButton, 0, 0);
    buttonsLayout->addWidget(skillButton, 0, 1);
    buttonsLayout->addWidget(itemButton, 0, 2);
    buttonsLayout->addWidget(retreatButton, 0, 3);

    connect(normalButton, &QPushButton::clicked, this, &Fight::handleNormalButton);
    connect(skillButton, &QPushButton::clicked, this, &Fight::handleSkillButton);
    connect(itemButton, &QPushButton::clicked, this, &Fight::handleItemButton);
    connect(retreatButton, &QPushButton::clicked, this, &Fight::close);
}

void Fight::createButtonsLayout1()
{
    clearButtonsLayout();

    if(player.getmiss()<qrand()%100&&player.getdefend()/10<monster.getattack())
    {
        player.sethp(player.gethp()-monster.getattack()+player.getdefend()/10);
    }

    QPushButton *normalButton = new QPushButton("普通", this);
    QPushButton *skillButton = new QPushButton("技能", this);
    QPushButton *itemButton = new QPushButton("道具", this);
    QPushButton *retreatButton = new QPushButton("撤退", this);

    buttonsLayout->addWidget(normalButton, 0, 0);
    buttonsLayout->addWidget(skillButton, 0, 1);
    buttonsLayout->addWidget(itemButton, 0, 2);
    buttonsLayout->addWidget(retreatButton, 0, 3);

    connect(normalButton, &QPushButton::clicked, this, &Fight::handleNormalButton);
    connect(skillButton, &QPushButton::clicked, this, &Fight::handleSkillButton);
    connect(itemButton, &QPushButton::clicked, this, &Fight::handleItemButton);
    connect(retreatButton, &QPushButton::clicked, this, &Fight::close);

}

void Fight::handleNormalButton()
{
    clearButtonsLayout();

    QPushButton *chopButton = new QPushButton("劈砍", this);
    QPushButton *protectButton = new QPushButton("防护", this);
    QPushButton *retreatButton = new QPushButton("后退", this);

    buttonsLayout->addWidget(chopButton, 0, 0);
    buttonsLayout->addWidget(protectButton, 0, 1);
    buttonsLayout->addWidget(retreatButton, 0, 2);

    if(player.gethp()<1)
    {
        connect(chopButton, &QPushButton::clicked, this, &Fight::close);
        connect(protectButton, &QPushButton::clicked, this, &Fight::close);
        connect(retreatButton, &QPushButton::clicked, this, &Fight::close);
    }

    if(monster.gethp()<1)
    {
        player.setexp(player.getexp()+monster.getexp());
        player.setmoney(player.getmoney()+50+qrand()%15);
        if(player.getexp()>=player.getneed())
        {
            player.levelup();
        }
        connect(chopButton, &QPushButton::clicked, this, &Fight::close);
        connect(protectButton, &QPushButton::clicked, this, &Fight::close);
        connect(retreatButton, &QPushButton::clicked, this, &Fight::close);
    }

    connect(chopButton, &QPushButton::clicked, this, &Fight::handleChopButton);
    connect(protectButton, &QPushButton::clicked, this, &Fight::handleProtectButton);
    connect(retreatButton, &QPushButton::clicked, this, &Fight::handleRetreatButton);
}

void Fight::handleSkillButton()
{
    clearButtonsLayout();

    QPushButton *swordButton = new QPushButton("剑法", this);
    QPushButton *magicButton = new QPushButton("魔法", this);
    QPushButton *physicalButton = new QPushButton("体术", this);
    QPushButton *healButton = new QPushButton("治疗", this);

    buttonsLayout->addWidget(swordButton, 0, 0);
    buttonsLayout->addWidget(magicButton, 0, 1);
    buttonsLayout->addWidget(physicalButton, 1, 0);
    buttonsLayout->addWidget(healButton, 1, 1);

    connect(swordButton, &QPushButton::clicked, this, &Fight::handleSwordButton);
    connect(magicButton, &QPushButton::clicked, this, &Fight::handleMagicButton);
    connect(physicalButton, &QPushButton::clicked, this, &Fight::handlePhysicalButton);
    connect(healButton, &QPushButton::clicked, this, &Fight::handleHealButton);
}

void Fight::handleItemButton()
{
    clearButtonsLayout();

    // Add code here to display the new buttons and scrollbar for items

    QPushButton *returnButton = new QPushButton("返回", this);
    buttonsLayout->addWidget(returnButton, 0, 0);

    connect(returnButton, &QPushButton::clicked, this, &Fight::createButtonsLayout1);
}

void Fight::handleChopButton()
{
    if(player.getChit()>qrand()%100)
    {
        monster.sethp(monster.gethp()-player.getattack()*2+monster.getdefend()/4);
    }
    else
    {
        monster.sethp(monster.gethp()-player.getattack()+monster.getdefend()/4);
    }
    createButtonsLayout1();
}

void Fight::handleProtectButton()
{
    // Add code here to handle the "防护" button click event
    player.setdefend(player.getdefend()+2*qrand()%4);
    // Return to initial layout
    createButtonsLayout1();
}

void Fight::handleRetreatButton()
{
    // Add code here to handle the "后退" button click event
    player.setmiss(player.getmiss()+2);
    // Close the window
    createButtonsLayout1();
}

void Fight::handleSwordButton()
{
    clearButtonsLayout();
    // Add code here to handle the "剑法" button click event
    // Display  new buttons and scrollbar
    QPushButton *returnButton = new QPushButton("暂未拥有", this);
    buttonsLayout->addWidget(returnButton, 0, 0);

    connect(returnButton, &QPushButton::clicked, this, &Fight::createButtonsLayout1);
}

void Fight::handleMagicButton()
{
    clearButtonsLayout();
    // Add code here to handle the "魔法" button click event
    // Display new buttons and scrollbar
    QPushButton *returnButton = new QPushButton("暂未拥有", this);
    buttonsLayout->addWidget(returnButton, 0, 0);

    connect(returnButton, &QPushButton::clicked, this, &Fight::createButtonsLayout1);
}

void Fight::handlePhysicalButton()
{
    clearButtonsLayout();
    // Add code here to handle the "体术" button click event
    // Display new buttons and scrollbar
    QPushButton *returnButton = new QPushButton("暂未拥有", this);
    buttonsLayout->addWidget(returnButton, 0, 0);

    connect(returnButton, &QPushButton::clicked, this, &Fight::createButtonsLayout1);
}

void Fight::handleHealButton()
{
    clearButtonsLayout();
    // Add code here to handle the "治疗" button click event
    // Display new buttons and scrollbar
    QPushButton *returnButton = new QPushButton("暂未拥有", this);
    buttonsLayout->addWidget(returnButton, 0, 0);

    connect(returnButton, &QPushButton::clicked, this, &Fight::createButtonsLayout1);
}

void Fight::clearButtonsLayout()
{
    QLayoutItem *child;
    while ((child = buttonsLayout->takeAt(0)) != nullptr)
    {
        delete child->widget();
        delete child;
    }
}
