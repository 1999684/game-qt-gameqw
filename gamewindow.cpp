#include "gamewindow.h"
#include "mazegame.h"
#include "player.h"
#include "playerwindows.h"
#include "role.h"
#include "monster.h"
#include <QWidget>
#include <QPalette>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
Player player;
monster monster;
role role;

GameWindow::GameWindow(QWidget *parent) : QWidget(parent)
{
    QPixmap backgroundImage(":/new/prefix1/resources/kaitou/background2.png");
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Background, backgroundImage);
    this->setPalette(palette);

    setWindowTitle("开始游戏咯");
    setFixedSize(900,760);

    QPushButton * btn=new QPushButton;
    btn->setParent(this);
    btn->setText("高等难度");
    connect(btn, &QPushButton::clicked, this, [=]()
    {
        player.chooseplayer(1);
    });
    btn->setGeometry(110,700,80,40);

    QPushButton * btn1=new QPushButton;
    btn1->setParent(this);
    btn1->setText("中等难度");
    connect(btn1, &QPushButton::clicked, this, [=]()
    {
        player.chooseplayer(2);
    });
    btn1->setGeometry(410,700,80,40);

    QPushButton * btn2=new QPushButton;
    btn2->setParent(this);
    btn2->setText("低等难度");
    connect(btn2, &QPushButton::clicked, this, [=]()
    {
        player.chooseplayer(3);
    });
    btn2->setGeometry(710,700,80,40);

    connect(btn, &QPushButton::clicked, this, &GameWindow::start);
    connect(btn1, &QPushButton::clicked, this, &GameWindow::start);
    connect(btn2, &QPushButton::clicked, this, &GameWindow::start);
}

void GameWindow::start()
{
    playwindows* playwindow = new playwindows();
    hide();
    playwindow->show();
    MazeGame* mazeGame = new MazeGame();
    mazeGame->show();
}

GameWindow::~GameWindow()
{

}
