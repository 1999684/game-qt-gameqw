#include "mazegame.h"
#include "player.h"
#include "xiayiguan_jinggao.h"
#include "monster.h"
#include "fight.h"
#include <QPainter>
#include <QKeyEvent>
#include <QtMath>
#include <QDebug>

extern Player player;
extern monster monster;

MazeGame::MazeGame(QWidget *parent) : QWidget(parent)
{
    image1.load(":/new/prefix1/resources/map/3.png");
    image2.load(":/new/prefix1/resources/map/4.png");
    playerImage.load(":/new/prefix1/resources/renwu/1.png");
    wallImage.load(":/new/prefix1/resources/map/5.png");
    monsterimage.load(":/new/prefix1/resources/monster_xiangsu/Cleric.png");

    // 设置迷宫地图大小
    mapWidth = 32;
    mapHeight = 32;

    // 随机生成迷宫地图
    generateMap();

    // 设置玩家初始位置
    playerPos = QPoint(0, 0);

    setFixedSize(mapWidth * blockSize, mapHeight * blockSize);
    setWindowTitle("开始游戏咯");

}

void MazeGame::paintEvent(QPaintEvent *event)
{
    // 创建绘图对象
    QPainter painter(this);

    if(map_type>=0&&map_type<=10)
    {
        image1.load(":/new/prefix1/resources/map/3.png");
        image2.load(":/new/prefix1/resources/map/4.png");
    }
    if(map_type>10)
    {
        image1.load(":/new/prefix1/resources/map/0.png");
        image2.load(":/new/prefix1/resources/map/1.png");
    }


    // 绘制迷宫地图
    for (int row = 0; row < maze.size(); ++row) {
        for (int col = 0; col < maze[row].size(); ++col) {
            QRect rect(col * blockSize, row * blockSize, blockSize, blockSize);
            painter.drawImage(rect, maze[row][col]);
        }
    }
    //绘制玩家
    QRect playerRect(playerPos.x() * blockSize, playerPos.y() * blockSize, blockSize, blockSize);
    painter.drawImage(playerRect, playerImage);
    //绘制怪物
    for (int shuliang = 0;shuliang<15;shuliang++)
    {
        monsterPos = QPoint(n[shuliang],m[shuliang]);
        QRect monsterRect(monsterPos.x() * blockSize, monsterPos.y() * blockSize, blockSize, blockSize);
        painter.drawImage(monsterRect, monsterimage);
    }
}

void MazeGame::keyPressEvent(QKeyEvent *event)
{
    // 处理玩家操作
    switch (event->key()) {
        case Qt::Key_Up:
            movePlayer(0, -1);
            break;
        case Qt::Key_Down:
            movePlayer(0, 1);
            break;
        case Qt::Key_Left:
            movePlayer(-1, 0);
            break;
        case Qt::Key_Right:
            movePlayer(1, 0);
            break;
    }
}

void MazeGame::generateMap()
{
    // 创建迷宫地图
    maze.resize(32, std::vector<QImage>(32, QImage(1, 1, QImage::Format_ARGB32)));

    // 随机生成迷宫地图
    for (int row = 0; row < maze.size(); ++row) {
        for (int col = 0; col < maze[row].size(); ++col) {
            maze[row][col] = (qrand() % 2 == 0) ? image1 : image2;
        }
    }
    maze[playerPos.x()][playerPos.y()] = image1;
    i=qrand()%31;t=qrand()%31;meet=13;map_type=qrand()%15;
    // 设置怪物位置
    for (int shu = 0;shu < 15;shu++)
    {
        n[shu]=qrand()%31;
        m[shu]=qrand()%31;
    }
    maze[i][t] = wallImage; // 出口
}

void MazeGame::movePlayer(int dx, int dy)
{
    if(player.gethp()<1)
    {
        hide();
    }

    QPainter painter(this);
    // 移动玩家位置
    int newPosX = playerPos.x() + dx;
    int newPosY = playerPos.y() + dy;


    // 检查是否越界或碰撞到墙壁
    if (newPosX >= 0 && newPosX < maze[0].size() && newPosY >= 0 && newPosY < maze.size() &&maze[newPosY][newPosX] != wallImage)
    {
        playerPos.setX(newPosX);
        playerPos.setY(newPosY);
    }
    // 判断是否进入战斗
    for (int l = 0;l < 15;l++)
    {
        if(newPosX == n[l] && newPosY == m[l] )
        {
            n[l]=500;
            m[l]=500;
            meet++;
            qDebug()<<map_type;
            //monster.creatermonster();
            qDebug()<<"saigao";
            infight();
        }
    }
    // 判断是否到达下一层入口
    if(newPosX == t && newPosY == i && meet >= 15)
    {
        player.setfloor(player.getfloor()+1);
        generateMap();
        playerPos = QPoint(qrand()%31,qrand()%31);
        // 重绘窗口
        update();
    }
    if(newPosX == t && newPosY == i && meet < 15)
    {
        jinggao();
    }

    update();
}

void MazeGame::infight()
{
    Fight * in = new Fight();
    in->show();
}

void MazeGame::jinggao()
{
    xiayiguan_jinggao * error = new xiayiguan_jinggao();
    error->show();
}
