#ifndef MAZEGAME_H
#define MAZEGAME_H

#include "role_monster.h"
#include <QWidget>

class MazeGame : public QWidget
{
public:
    explicit MazeGame(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    QPoint playerPos; // 玩家位置
    int blockSize = 20; // 地块大小
    QImage playerImage; // 玩家贴图
    int m[15];//怪物生成y
    int n[15];//怪物生产x
    int map_type;
    int i;//出口y
    int t;//出口x
    int meet;//单个地图遇到魔物次数
    void jinggao();
    void generateMap();
    QImage wallImage; // 墙壁贴图

signals:
private:
    //void generateMap();
    void movePlayer(int dx, int dy);
    void infight();


    int mapWidth; // 迷宫地图宽度
    int mapHeight; // 迷宫地图高度

    std::vector<std::vector<QImage>> maze; // 迷宫地图
    QImage image1; // 第一种地块贴图
    QImage image2; // 第二种地块贴图
    QImage monsterimage;// 第一种怪物贴图
    //QImage wallImage; // 墙壁贴图
    //QImage playerImage; // 玩家贴图
    //QPoint playerPos; // 玩家位置
    QPoint monsterPos; //怪物位置
    //int blockSize = 20; // 地块大小
    //int i;//出口y
    //int t;//出口x
    //int m[15];//怪物生成y
    //int n[15];//怪物生产x
    //int meet;//单个地图遇到魔物次数
    //int map_type=1;
};

#endif // MAZEGAME_H
