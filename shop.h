#ifndef SHOP_H
#define SHOP_H

#include <QWidget>

class Shop : public QWidget
{
    Q_OBJECT
public:
    explicit Shop(QWidget *parent = nullptr);

    void setToolTip(const QString &);
    void sword1();
    void sword2();
    void sword3();
    void yao1();
    void shield1();

    void jinggao();

private:
    int money;

signals:

};

#endif // SHOP_H
