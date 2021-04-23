#ifndef REVERSI_H
#define REVERSI_H


class Reversi
{
public:
    Reversi();
    ~Reversi();
public:
    //电脑数据
    int _maxRow;
    int _maxCol;
    int _computerColor;
    //棋盘数据
    int  m_nFlag;  //当前该哪方下子。1—黑,-1—白,0—禁止下子
    int  m_aGrid[8][8];  //0—无子,1—黑子,-1—白子
    int  Get(int RowPos, int ColPos);                //查看
    bool Set(int color, int RowPos, int ColPos); //下子
    void SetAuto(int color); //电脑思考
    void SetAutoAfter();    //电脑下子
    int  GetFlag();    //查看该谁下子
    int  Judge();          //胜负判断
    bool IfCanSet(int color, int RowPos, int ColPos);
    bool IfOneCanSet(int color, int RowPos, int ColPos,int direction);
    void init();
};

#endif // REVERSI_H
