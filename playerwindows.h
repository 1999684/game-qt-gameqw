#ifndef PLAYWINDOWS_H
#define PLAYWINDOWS_H

#include <QMainWindow>
#include "player.h"
#include <QMenuBar>
#include <QString>
#include <QImage>
#include <QTableWidget>

class playwindows : public QMainWindow
{
    Q_OBJECT
public:
    explicit playwindows(QWidget *parent = nullptr);
    ~playwindows();
    void CreateActions();
    void getinformation();

public slots:
    void slotShop();
    void CreateMenus();
    void timerTimeout();

signals:

private:
    QAction *exitGame;
    QAction *shop;
    QTimer *timer;
    QTableWidget *tablewidget;

    void updateTable();
};

#endif // PLAYWINDOWS_H
