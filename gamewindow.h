#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMenuBar>
#include <QString>
#include <QLabel>
#include <QWidget>

class GameWindow : public QWidget
{
    Q_OBJECT
public:
    GameWindow(QWidget *parent = nullptr);
    ~GameWindow();
    void start();
private:
    QLabel* hpLabel;

};


#endif // GAMEWINDOW_H
