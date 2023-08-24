#ifndef ROLE_H
#define ROLE_H


class role
{
public:
    role() {}
    ~role() {}
    int gethp() {return hp;}
    int getattack() {return attack;}
    int getdefend() {return defend;}
    int getmoney() {return money;}
    int getexp() {return exp;}
    int getmiss() {return miss;}
    int getChit() {return Chit;}

    void sethp(int hp) {this->hp=hp;}
    void setattack(int attack) {this->attack=attack;}
    void setdefend(int defend) {this->defend=defend;}
    void setmoney(int money) {this->money=money;}
    void setexp(int exp) {this->exp=exp;}
    void setmiss(int miss) {this->miss=miss;}
    void setChit(int Chit) {this->Chit=Chit;}

    int hp;
    int attack;
    int defend;
    int money;
    int exp;
    int miss;
    int Chit;
};

#endif // ROLE_H
