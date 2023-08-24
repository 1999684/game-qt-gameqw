#ifndef FIGHT_H
#define FIGHT_H

#include "mazegame.h"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QScrollBar>
#include <QLabel>

class Fight : public QWidget
{
    Q_OBJECT
public:
    explicit Fight(QWidget *parent = nullptr);
    MazeGame mazegame;
    void drawmonster();
    void onButtonClick();

signals:

private:
    QGridLayout *buttonsLayout;
    QGridLayout *monsterLayout;
    QGridLayout *playerLayout;
    QLabel *monsterimage1;
    QLabel *playerimage1;
    void paintEvent(QPaintEvent *event);
    void createButtonsLayout();
    void createButtonsLayout1();
    void handleNormalButton();
    void handleSkillButton();
    void handleItemButton();
    void handleChopButton();
    void handleProtectButton();
    void handleRetreatButton();
    void handleSwordButton();
    void handleMagicButton();
    void handlePhysicalButton();
    void handleHealButton();
    void clearButtonsLayout();
    QPixmap backgroundImage;

    QImage texiao1;
    QImage texiao2;
    QImage texiao3;
    QImage texiao4;
    QImage texiao5;
    QImage texiao6;
    QImage texiao7;
    QImage texiao8;
};

#endif // FIGHT_H
