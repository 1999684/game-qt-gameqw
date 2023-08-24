#ifndef MONSTER_H
#define MONSTER_H

#include "role_monster.h"
#include <QObject>

class monster : public role_monster
{
public:
    monster() {}
    ~monster() {}
    void create();

private:



};

#endif // MONSTER_H
