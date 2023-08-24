#ifndef GAME_H
#define GAME_H

#include <QMainWindow>


class game : public QMainWindow
{
    Q_OBJECT

public:
    game(QWidget *parent = nullptr);
    ~game();


private:
    void startgame();
};
#endif // GAME_H
