#include "playerwindows.h"
#include "shop.h"
#include "role.h"
#include "player.h"
#include <QWidget>
#include <QApplication>
#include <QTimer>
#include <QDebug>

extern Player player;

playwindows::playwindows(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("开始游戏咯");
    setFixedSize(400,760);

    //创建操作
    CreateActions();
    //创建菜单
    // Create all menus in mainwindow
    CreateMenus();

    tablewidget = new QTableWidget(10, 2, this);
    setCentralWidget(tablewidget);

    QStringList headers;
    headers<<"信息"<<"数值";
    tablewidget->setHorizontalHeaderLabels(headers);

    if(player.gethp()<1)
    {
        hide();
    }

    updateTable();

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerTimeout()));
    timer->start(1000/30);
}

QString a[9]={"生命",""};

playwindows::~playwindows()
{
    delete timer;
}

void playwindows::updateTable()
{
    QStringList properties;
    properties<<"生命"<<"攻击"<<"防御"<<"闪避"<<"暴击"<<"层数"<<"等级"<<"经验"<<"还需"<<"金钱";
    for(int row = 0;row<10;row++)
    {
        QTableWidgetItem *item = new QTableWidgetItem(properties[row]);
        tablewidget->setItem(row,0,item);

        if(row==0)
        {
            QTableWidgetItem *data = new QTableWidgetItem(QString::number(player.gethp()));
            tablewidget->setItem(row,1,data);
        }
        if(row==1)
        {
            QTableWidgetItem *data = new QTableWidgetItem(QString::number(player.getattack()));
            tablewidget->setItem(row,1,data);
        }
        if(row==2)
        {
            QTableWidgetItem *data = new QTableWidgetItem(QString::number(player.getdefend()));
            tablewidget->setItem(row,1,data);
        }
        if(row==3)
        {
            QTableWidgetItem *data = new QTableWidgetItem(QString::number(player.getmiss()));
            tablewidget->setItem(row,1,data);
        }
        if(row==4)
        {
            QTableWidgetItem *data = new QTableWidgetItem(QString::number(player.getChit()));
            tablewidget->setItem(row,1,data);
        }
        if(row==5)
        {
            QTableWidgetItem *data = new QTableWidgetItem(QString::number(player.getfloor()));
            tablewidget->setItem(row,1,data);
        }
        if(row==6)
        {
            QTableWidgetItem *data = new QTableWidgetItem(QString::number(player.getlevel()));
            tablewidget->setItem(row,1,data);
        }
        if(row==7)
        {
            QTableWidgetItem *data = new QTableWidgetItem(QString::number(player.getexp()));
            tablewidget->setItem(row,1,data);
        }
        if(row==8)
        {
            QTableWidgetItem *data = new QTableWidgetItem(QString::number(player.getneed()));
            tablewidget->setItem(row,1,data);
        }
        if(row==9)
        {
            QTableWidgetItem *data = new QTableWidgetItem(QString::number(player.getmoney()));
            tablewidget->setItem(row,1,data);
        }
    }
}

void playwindows::timerTimeout()
{
    updateTable();
}

void playwindows::CreateActions()
{
    exitGame = new QAction(tr("退出"), this);
    shop = new QAction(tr("商店"));

    exitGame->setShortcut(tr("Q"));
    shop->setShortcut(tr("S"));

    connect(exitGame, SIGNAL(triggered()), this, SLOT(close()));
    connect(shop, SIGNAL(triggered()), this, SLOT(slotShop()));
}

void playwindows::CreateMenus()
{

    QMenu *fileMenu = menuBar()->addMenu(tr(" Menu "));

    fileMenu->addAction(exitGame);
    fileMenu->addAction(shop);
}


void playwindows::slotShop()
{
    Shop* shoping = new Shop();
    shoping->show();
}
