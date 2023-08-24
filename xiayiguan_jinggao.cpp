#include "xiayiguan_jinggao.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

xiayiguan_jinggao::xiayiguan_jinggao(QWidget *parent) : QWidget(parent)
{
    setFixedSize(370,320);

    QFont font ("DFKai-SB", 20);
    // 创建一个QLabel对象
    QLabel *label = new QLabel(this);
    // 设置文本内容
    label->setText("魔物没有除净，无法进入");
    // 设置对齐方式为居中对齐
    label->setAlignment(Qt::AlignCenter);
    label->setFont(font);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);

    QPushButton * exit=new QPushButton;
    exit->setParent(this);
    exit->setText("确定");
    exit->setGeometry(280,270,70,30);
    connect(exit,&QPushButton::clicked,this,&QWidget::close);
}
