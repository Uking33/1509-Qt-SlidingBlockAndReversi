#include "window.h"

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    //对不需要变化的数据初始化
    L = 100;   //连杆长度
    W = 10;    //连杆宽度
    L1 = 25;   //主动块长度
    W1 = 20;   //主动块宽度
    L2 = 50;   //从动块长度
    W2 = 40;   //从动块宽度
    Origin = QPoint(0,0);  //暂时初始化为(0,0)点，一会要根据窗口实际情况变化
    //dX开始时为0，dX是要变化的
    dX = 0;
    setFocus();
}

Window::~Window()
{

}

void Window::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(Qt::white);
    QPen pen,pen1;
    pen.setWidth(1);
    painter.setPen(pen);
    //先确定参考原点的位置
    Origin.setX( this->size().width()/2 );
    Origin.setY( this->size().height()/3 );
    if(isStart)
    {
        dX=-L+L/50*m_pX;
    }
    //原点可能以变化，需重新计算各部件位置
    CalPosition();
    //画主动导轨
    painter.drawLine(Gui1[0],Gui1[1]);
    painter.drawLine(Gui1[2],Gui1[3]);
    //画从动导轨
    painter.drawLine(Gui2[0],Gui2[1]);
    painter.drawLine(Gui2[2],Gui2[3]);
    //换笔
    pen.setWidth(3);
    painter.setPen(pen);
    //画主动块
    painter.drawPolygon(Kuai1,4);
    //画从动块
    painter.drawPolygon(Kuai2,4);
    //画连杆
    painter.drawPolygon(Gan,4);
    //换笔
    pen1.setWidth(2);
    pen1.setColor(QColor(200,20,60));
    painter.setPen(pen1);
    if(isStart)
        {
            if(add==1)
                for(int i=0;i<m_pX;i++)
                {
                    painter.drawLine(Path[i],Path[i+1]);
                }
            if(add==-1)
                for(int i=100;i>m_pX;i--)
                {
                    painter.drawLine(Path[i],Path[i-1]);
                }
        }
}

void Window::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Left||event->key()==Qt::Key_A)
    {
        if (dX-2 >= (-L+10)) dX -= 2;
    }
    else if(event->key()==Qt::Key_Right||event->key()==Qt::Key_D)
    {
        if (dX+2 <= (L-10)) dX += 2;
    }
    CalPosition();
    update();
}
void Window::timerEvent( QTimerEvent * )

{
    if(m_pX>=100)
            add=-1;
    if(m_pX<=0)
        add=1;
    if(!isStart)
        killTimer(m_nTimerId);
    update();
    m_pX+=add;

}
void Window::CalPosition()
{
    //计算主动导轨四点的位置
    Gui1[0].setX( (int)(Origin.rx() - L - 10 + 0.5) );
    Gui1[0].setY( (int)(Origin.ry() - W1/2 + 0.5 ));
    Gui1[1].setX( (int)(Origin.rx() + L + 10 + 0.5) );
    Gui1[1].setY( (int)(Origin.ry() - W1/2 + 0.5) );
    Gui1[2].setX( (int)(Origin.rx() - L - 10 + 0.5) );
    Gui1[2].setY( (int)(Origin.ry() + W1/2 + 0.5) );
    Gui1[3].setX( (int)(Origin.rx() + L + 10 + 0.5) );
    Gui1[3].setY( (int)(Origin.ry() + W1/2 + 0.5) );

    //计算主动块位置
    Kuai1[0].setX( (int)(Origin.rx() +dX - L1/2 + 0.5) );
    Kuai1[0].setY( (int)(Origin.ry() - W1/2 + 0.5) );
    Kuai1[1].setX( (int)(Origin.rx() +dX + L1/2 + 0.5) );
    Kuai1[1].setY( (int)(Origin.ry() - W1/2 + 0.5) );
    Kuai1[2].setX( (int)(Origin.rx() +dX + L1/2 + 0.5) );
    Kuai1[2].setY( (int)(Origin.ry() + W1/2 + 0.5) );
    Kuai1[3].setX( (int)(Origin.rx() +dX - L1/2 + 0.5) );
    Kuai1[3].setY( (int)(Origin.ry() + W1/2 + 0.5) );

    //计算从动导轨四点的位置
    Gui2[0].setX( (int)(Origin.rx() - W2/2.0) );
    Gui2[0].setY( (int)(Origin.ry() + 20) );
    Gui2[1].setX( (int)(Origin.rx() - W2/2.0) );
    Gui2[1].setY( (int)(Origin.ry() + L + L2) );
    Gui2[2].setX( (int)(Origin.rx() + W2/2.0) );
    Gui2[2].setY( (int)(Origin.ry() + 20 ));
    Gui2[3].setX( (int)(Origin.rx() + W2/2.0) );
    Gui2[3].setY( (int)(Origin.ry() + L + L2) );

    //计算从动块位置
    Kuai2[0].setX( (int)(Origin.rx() + W2/2.0) );
    Kuai2[0].setY( (int)(Origin.ry() + sqrt(L*L-dX*dX) + L2/2.0) );
    Kuai2[1].setX( (int)(Origin.rx() - W2/2.0) );
    Kuai2[1].setY( (int)(Origin.ry() + sqrt(L*L-dX*dX) + L2/2.0) );
    Kuai2[2].setX( (int)(Origin.rx() - W2/2.0) );
    Kuai2[2].setY( (int)(Origin.ry() + sqrt(L*L-dX*dX) - L2/2.0) );
    Kuai2[3].setX( (int)(Origin.rx() + W2/2.0) );
    Kuai2[3].setY( (int)(Origin.ry() + sqrt(L*L-dX*dX) - L2/2.0) );

    //计算连杆位置
    Gan[0].setX( (int)(Origin.rx() + dX - W*sqrt(L*L-dX*dX)/2.0/L) );
    Gan[0].setY( (int)(Origin.ry() - W*dX/2.0/L) );
    Gan[1].setX( (int)(Origin.rx() + dX + W*sqrt(L*L-dX*dX)/2.0/L) );
    Gan[1].setY( (int)(Origin.ry() + W*dX/2.0/L) );
    Gan[2].setX( (int)(Origin.rx() + W*sqrt(L*L-dX*dX)/2.0/L) );
    Gan[2].setY( (int)(Origin.ry() + sqrt(L*L-dX*dX) + W*dX/2.0/L) );
    Gan[3].setX( (int)(Origin.rx() - W*sqrt(L*L-dX*dX)/2.0/L) );
    Gan[3].setY( (int)(Origin.ry() + sqrt(L*L-dX*dX) - W*dX/2.0/L) );

    for(int i=0;i<=100;i++)
    {
        double pX=-L+L/50.0*i;
        Path[i].setX((int)(pX+0+Origin.x()*2)/2.0 );
        Path[i].setY((int)(0+sqrt(L*L-pX*pX)+Origin.y()*2)/2.0 );
    }
}

