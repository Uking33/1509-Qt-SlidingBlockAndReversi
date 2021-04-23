#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QTimerEvent>
#include <QPainter>
#include "math.h"

class Window : public QWidget
{
    Q_OBJECT
public:
    Window(QWidget *parent = 0);
    ~Window();
    int add;
    bool isStart;
    int m_pX;
    int m_nTimerId; //时间
private:
    void CalPosition();
    double dX;       //主动块与参考原点的距离
    double L,W;      //连杆的长度和宽度
    double L1,W1;    //主动块的长度和宽度
    double L2,W2;    //从动块的长度和宽度
    QPoint Gui1[4];  //画主动导轨两条线的四个点
    QPoint Gui2[4];  //画从动导轨两条线的四个点
    QPoint Gan[4];     //连杆四边形的四点
    QPoint Kuai1[4]; //主动块四边形的四点
    QPoint Kuai2[4];  //从动块四边形的四点
    QPoint Origin;   //主动导轨的中点    
    QPoint Path[101]; //中点路径
protected:
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *);
};

#endif // WINDOW_H
