#ifndef PLAYER_H
#define PLAYER_H

#include "role.h"
#include <QObject>

class Player : public role
{
public:
    Player() {}
    ~Player() {}
    int getposx() {return posx;}
    int getposy() {return posy;}
    int getlevel() {return level;}
    int getfloor() {return floor;}
    int getneed() {return need;}
    int gettoward() {return toward;}
    int getinitial() {return initial;}

    void setposx(int posx) {this->posx=posx;}
    void setposy(int posy) {this->posy=posy;}
    void setlevel(int level) {this->level=level;}
    void setfloor(int floor) {this->floor=floor;}
    void setneed(int need) {this->need=need;}
    void settoward(int toward) {this->toward=toward;}
    void setinitial(int initial) {this->initial=initial;}

    void levelup();
    void chooseplayer(int initial);

private:
    int posx;
    int posy;
    int level;
    int floor;
    int toward;
    int need;
    int initial;


};

#endif // PLAYER_H
