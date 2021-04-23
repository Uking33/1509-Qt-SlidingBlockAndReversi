// Reversi.h: interface for the Reversi class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_REVERSI_H__10B75C17_9CDC_4AD2_AEE1_AFD2422AE2D3__INCLUDED_)
#define AFX_REVERSI_H__10B75C17_9CDC_4AD2_AEE1_AFD2422AE2D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Reversi  
{
public:
	Reversi();
	virtual ~Reversi();
public:
	int  m_nFlag;  //当前该哪方下子。1—黑,-1—白,0—禁止下子
	int  m_aGrid[8][8];  //0—无子,1—黑子,-1—白子
    int  Get(int RowPos, int ColPos);                //查看
    bool Set(int color, int RowPos, int ColPos); //下子
    bool SetAuto(int color); //电脑下子
    int  GetFlag();    //查看该谁下子
    int  Judge();          //胜负判断	
	bool IfCanSet(int color, int RowPos, int ColPos);	
	bool IfOneCanSet(int color, int RowPos, int ColPos,int direction);
	void init();
};

#endif // !defined(AFX_REVERSI_H__10B75C17_9CDC_4AD2_AEE1_AFD2422AE2D3__INCLUDED_)
