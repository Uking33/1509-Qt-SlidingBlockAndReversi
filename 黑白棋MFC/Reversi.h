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
	int  m_nFlag;  //��ǰ���ķ����ӡ�1����,-1����,0����ֹ����
	int  m_aGrid[8][8];  //0������,1������,-1������
    int  Get(int RowPos, int ColPos);                //�鿴
    bool Set(int color, int RowPos, int ColPos); //����
    bool SetAuto(int color); //��������
    int  GetFlag();    //�鿴��˭����
    int  Judge();          //ʤ���ж�	
	bool IfCanSet(int color, int RowPos, int ColPos);	
	bool IfOneCanSet(int color, int RowPos, int ColPos,int direction);
	void init();
};

#endif // !defined(AFX_REVERSI_H__10B75C17_9CDC_4AD2_AEE1_AFD2422AE2D3__INCLUDED_)
