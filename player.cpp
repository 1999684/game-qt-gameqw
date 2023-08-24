#include "player.h"
#include "gamewindow.h"
#include <QtMath>
#include <QDebug>

void Player::chooseplayer(int initial)
{
    if(initial == 1)
    {
        sethp(100);
        setattack(10);
        setdefend(10);
        setmiss(5);
        setChit(20);
        setmoney(0);
        qDebug()<<"h";
    }
    if(initial == 2)
    {
        sethp(120);
        setattack(15);
        setdefend(20);
        setmiss(10);
        setChit(20);
        setmoney(100);
        qDebug()<<"l";
    }
    if(initial == 3)
    {
        sethp(200);
        setattack(30);
        setdefend(30);
        setmiss(15);
        setChit(80);
        setmoney(1000);
        qDebug()<<"d";
    }
    setexp(0);
    this->level = 0;
    this->posx = 6;
    this->posy =200;
    this->floor = 0;
    this->need = 100;

}

void Player::levelup()
{
    level +=1;
    sethp(gethp()+10);
    setattack(getattack()+2);
    setdefend(getdefend()+1);
    setexp(getexp()-need);
    need=qFloor(need*1.5-getexp());
}
