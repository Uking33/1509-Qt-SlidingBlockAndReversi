#include "view.h"
#include <QDebug>

View::View(QWidget *parent,int model)
    : QWidget(parent)
{
    init(parent,model);
}

void View::init(QWidget *parent,int model)
{
    _model=model;
    setFocus();
    //设置窗口
    switch(_model)
    {
        case 0:
            parent->setWindowTitle("黑白棋-双人对战");
            break;
        case 1:
            parent->setWindowTitle("黑白棋-人机对战（黑）");
            break;
        case -1:
            parent->setWindowTitle("黑白棋-人机对战（白）");
            break;
    }

    setMinimumSize(GE_WIDTH*GE_NUM*3/2+50,GE_WIDTH*GE_NUM+50);
    setMaximumSize(GE_WIDTH*GE_NUM*3/2+50,GE_WIDTH*GE_NUM+50);
    //数据初始化
    m_nR=3;
    m_nC=3;
    m_black_win=0;
    m_white_win=0;
    _isWait=false;
    //对局
    m_Reversi.init();
    update();
    if(_model==-1)
    {
        m_Reversi.SetAuto(1);
        _isWait=true;
        QTimer::singleShot(1000,this, &View::computerWait);
    }
    update();
}

View::~View()
{
}

void View::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    //if(_isWait) return;
    QRect rect=this->geometry();
    QPoint m_ptOrigin;
    m_ptOrigin.setX((rect.width()-40*12)/2);
    m_ptOrigin.setY((rect.height()-40*8)/2);
    QPen pen1,pen2,penOld;
    int i,j;
    QBrush brushB(QColor(0,0,0)),brushW(QColor(255,255,255)),brush0;
    //棋盘-纹理
    brush0.setTexture(QPixmap(":/bg"));
    painter.setBrush(brush0);
    painter.fillRect(m_ptOrigin.rx(),m_ptOrigin.ry(),8*40,8*40,brush0);
    //棋盘-线
    pen1.setWidth(2);
    pen1.setColor(QColor(125,42,42));
    painter.setPen(pen1);
    for(i=0;i<9;i++)
        painter.drawLine(m_ptOrigin.rx(),m_ptOrigin.ry()+i*40,m_ptOrigin.rx()+8*40,m_ptOrigin.ry()+i*40);
    for(i=0;i<9;i++)
        painter.drawLine(m_ptOrigin.rx()+i*40,m_ptOrigin.ry(),m_ptOrigin.rx()+i*40,m_ptOrigin.ry()+8*40);
    //光标
    pen2.setWidth(3);
    pen2.setColor(QColor(64,244,205));
    painter.setPen(pen2);
    painter.drawRect(m_ptOrigin.rx()+m_nR*GE_WIDTH,m_ptOrigin.ry()+m_nC*GE_WIDTH,GE_WIDTH,GE_WIDTH);
    //棋子
    painter.setPen(penOld);
    for(i=0;i<GE_NUM;i++)
       for(j=0;j<GE_NUM;j++)
       {
            if(m_Reversi.m_aGrid[i][j]==-1)
                painter.setBrush(brushW);
            if(m_Reversi.m_aGrid[i][j]==1)
                painter.setBrush(brushB);
            if(m_Reversi.m_aGrid[i][j])
            {
                painter.drawEllipse(m_ptOrigin.rx()+i*GE_WIDTH+3,m_ptOrigin.ry()+j*GE_WIDTH+3,GE_WIDTH-6,GE_WIDTH-6);
            }
        }
    //文字-胜局
    int tip_x;
    int tip_y;
    int per;
    tip_x=m_ptOrigin.rx()+40*8+20;
    tip_y=m_ptOrigin.ry()+20;
    QString str;

    if(_model==0)
    {
        if(m_Reversi.GetFlag()==1)
            str="  √  黑方：胜 "+QString::number(m_black_win)+" 局";
        else
            str="      黑方：胜 "+QString::number(m_black_win)+" 局";
    }
    else if(_model==-1)
    {
        if(m_Reversi.GetFlag()==1)
            str="  √  电脑：胜 "+QString::number(m_black_win)+" 局";
        else
            str="      电脑：胜 "+QString::number(m_black_win)+" 局";
    }
    else if(_model==1)
    {
        if(m_Reversi.GetFlag()==1)
            str="  √  玩家：胜 "+QString::number(m_black_win)+" 局";
        else
            str="      玩家：胜 "+QString::number(m_black_win)+" 局";
    }
    painter.drawText(tip_x,tip_y,str);

    if(m_white_win+m_black_win==0)
        per=0;
    else
     per=(int)((double)(m_black_win)/(m_white_win+m_black_win)*100);
    str="      胜率："+QString::number(per)+" %";
    tip_y+=25;
    painter.drawText(tip_x,tip_y,str);

    if(_model==0)
    {
        if(m_Reversi.GetFlag()==-1)
            str="  √  白方：胜 "+QString::number(m_white_win)+" 局";
        else
            str="      白方：胜 "+QString::number(m_white_win)+" 局";
    }
    else if(_model==-1)
    {
        if(m_Reversi.GetFlag()==-1)
            str="  √  玩家：胜 "+QString::number(m_white_win)+" 局";
        else
            str="      玩家：胜 "+QString::number(m_white_win)+" 局";
    }
    else if(_model==1)
    {
        if(m_Reversi.GetFlag()==-1)
            str="  √  电脑：胜 "+QString::number(m_white_win)+" 局";
        else
            str="      电脑：胜 "+QString::number(m_white_win)+" 局";
    }
    tip_y+=40;
    painter.drawText(tip_x,tip_y,str);

    tip_y+=25;
    if(m_white_win+m_black_win==0)
        per=0;
    else
        per=(int)((double)(m_white_win)/(m_white_win+m_black_win)*100);
    str="      胜率："+QString::number(per)+" %";
    painter.drawText(tip_x,tip_y,str);
    //文字-提示
    tip_y=m_ptOrigin.ry()+40*5+20;

    if(_model==0)
    {
        str="提示：黑棋用箭头键和";
        painter.drawText(tip_x,tip_y,str);
        tip_y+=25;
        str="回车键走棋；白棋用W";
        painter.drawText(tip_x,tip_y,str);
        tip_y+=25;
        str="ASD和空格键走棋。";
        painter.drawText(tip_x,tip_y,str);
    }
    else
    {
        str="提示：用箭头键和回车";
        painter.drawText(tip_x,tip_y,str);
        tip_y+=25;
        str="键走棋";
        painter.drawText(tip_x,tip_y,str);
    }
}

void View::keyPressEvent(QKeyEvent *event)
{
    if(_isWait) return;
    int color;
    if(!_model)
    {
        if((('A'==event->key() && -1==m_Reversi.GetFlag()) || (Qt::Key_Left==event->key() && 1==m_Reversi.GetFlag())) && m_nR>0)
            m_nR--;
        else if((('D'==event->key() && -1==m_Reversi.GetFlag()) || (Qt::Key_Right==event->key() && 1==m_Reversi.GetFlag())) && m_nR<7)
            m_nR++;
        else if((('W'==event->key() && -1==m_Reversi.GetFlag()) || (Qt::Key_Up==event->key() && 1==m_Reversi.GetFlag())) && m_nC>0)
            m_nC--;
        else if((('S'==event->key() && -1==m_Reversi.GetFlag()) || (Qt::Key_Down==event->key() && 1==m_Reversi.GetFlag())) && m_nC<7)
            m_nC++;
        else if(Qt::Key_Space==event->key() && -1==m_Reversi.GetFlag())
            color=-1;
        else if((Qt::Key_Return==event->key()||Qt::Key_Enter==event->key()) && 1==m_Reversi.GetFlag())
            color=1;
        update();
    }
    else
    {
        if(_model==1)
            color=1;
        if(_model==-1)
            color=-1;
        if(Qt::Key_Left==event->key() && color==m_Reversi.GetFlag() && m_nR>0)
            m_nR--;
        else if(Qt::Key_Right==event->key() && color==m_Reversi.GetFlag() && m_nR<7)
            m_nR++;
        else if(Qt::Key_Up==event->key() && color==m_Reversi.GetFlag() && m_nC>0)
            m_nC--;
        else if(Qt::Key_Down==event->key() && color==m_Reversi.GetFlag() && m_nC<7)
            m_nC++;
        update();
    }
    //下子
    if(((Qt::Key_Return==event->key()||Qt::Key_Enter==event->key())) || (Qt::Key_Space==event->key() && -1==m_Reversi.GetFlag()))
        if(m_Reversi.Set(color,m_nR,m_nC))
        {
            update();
            if(int win=m_Reversi.Judge())//判断胜负
            {
                if(win==1)
                {
                    m_black_win++;
                    QMessageBox::information(NULL, "黑棋胜利", "黑棋胜利", QMessageBox::Yes, QMessageBox::Yes);
                }
                if(win==-1)
                {
                    m_white_win++;
                    QMessageBox::information(NULL, "白棋胜利", "白棋胜利", QMessageBox::Yes, QMessageBox::Yes);
                }
                if(win==2)
                    QMessageBox::information(NULL, "平局", "平局", QMessageBox::Yes, QMessageBox::Yes);
                m_Reversi.init();
                update();
            }
            //电脑下
            if(_model)
            {
                color=-color;
                m_Reversi.SetAuto(color);
                _isWait=true;
                QTimer::singleShot(1000,this, &View::computerWait);
            }
        }
}
void View::computerWait()
{
    _isWait=false;
    m_Reversi.SetAutoAfter();
    update();
    if(int win=m_Reversi.Judge())//判断胜负
    {
        if(win==1)
        {
            m_black_win++;
            QMessageBox::information(NULL, "黑棋胜利", "黑棋胜利", QMessageBox::Yes, QMessageBox::Yes);
        }
        if(win==-1)
        {
            m_white_win++;
            QMessageBox::information(NULL, "白棋胜利", "白棋胜利", QMessageBox::Yes, QMessageBox::Yes);
        }
        if(win==2)
            QMessageBox::information(NULL, "平局", "平局", QMessageBox::Yes, QMessageBox::Yes);
        m_Reversi.init();
    }
}
