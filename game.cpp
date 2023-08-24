#include "game.h"
#include <QPushButton>
#include <QDebug>
#include <QPalette>
#include <QWidget>
#include<QEvent>
#include <QBrush>
#include <QImage>
#include <gamewindow.h>

game::game(QWidget *parent)
    : QMainWindow(parent)

{
    QPixmap backgroundImage(":/new/prefix1/resources/kaitou/background.png");
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Background, backgroundImage);
    this->setPalette(palette);

    QPushButton * btm=new QPushButton;
    btm->setParent(this);
    btm->setText("开始游戏");
    connect(btm, &QPushButton::clicked, this, &game::startgame);
    btm->setGeometry(240,360,70,30);
    setFixedSize(550,448);
    setWindowTitle("game start");
    //btm->setFlat(true);

    QPushButton * btm3=new QPushButton;
    btm3->setParent(this);
    btm3->setText("退出游戏");
    btm3->setGeometry(240,400,70,30);
    connect(btm3,&QPushButton::clicked,this,&QWidget::close);
    //btm3->setFlat(true);
}

void game::startgame()
{
    GameWindow* gameWindow = new GameWindow();
    hide();
    gameWindow->show();
}

game::~game()
{
    qDebug();
}

