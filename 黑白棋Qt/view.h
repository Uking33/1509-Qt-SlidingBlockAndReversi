#ifndef VIEW_H
#define VIEW_H

#define GE_NUM 8
#define GE_WIDTH 40

#include <QWidget>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QPixmap>
#include <QBrush>
#include <QMessageBox>
#include <QTimer>
#include "reversi.h"

class View:public QWidget
{
    Q_OBJECT
public:
    View(QWidget *parent, int model);
    ~View();
public:
    void init(QWidget *parent, int model);
    void computerWait();   //电脑思考
    bool _isWait;
    //对局数据对象
    Reversi m_Reversi;      //棋局对象
    int  m_nR, m_nC;        //光标当前在第几行、第几列
    int  m_black_win;
    int  m_white_win;
    int _model;//0为人人；1人为黑，-1人为白
protected:
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *event);
};

#endif // VIEW_H
