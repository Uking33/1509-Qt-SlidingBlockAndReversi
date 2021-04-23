// Reversi.cpp: implementation of the Reversi class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BlackAndWhite.h"
#include "Reversi.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Reversi::Reversi()
{
	init();
}

Reversi::~Reversi()
{

}

void Reversi::init()
{
	//初始化
	int i,j;
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
		{
			m_aGrid[i][j]=0;
		}
	m_aGrid[3][3]=1;
	m_aGrid[4][4]=1;
	m_aGrid[3][4]=-1;
	m_aGrid[4][3]=-1;
	m_nFlag=1;
}

int  Reversi::Get(int RowPos, int ColPos)                //查看
{
	return m_aGrid[RowPos][ColPos];
}

bool Reversi::Set(int color, int RowPos, int ColPos)	//下子
{
	if(IfCanSet( color, RowPos, ColPos))//判断该位置是否能下子
	{
		m_aGrid [RowPos][ColPos] = color;
		m_nFlag = -m_nFlag;
		return true ;
	}
    else
		return false;
}

bool Reversi::SetAuto(int color)	//电脑下子
{
	int i,j,k,maxRow=-1,maxCol=-1,max=0,temp=0;
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
		{
			if(m_aGrid[i][j]!=0) continue;
			for(k=1;k<=9;k++)//看能不能下
			{
				temp=0;
				if(k!=5 && IfOneCanSet(color, i, j, k))
				{
					int cr,cc;
					int RowFind=i,ColFind=j;
					switch(k)
					{
						case 1:
							cr=1;
							cc=-1;
							break;
						case 2:
							cr=1;
							cc=0;
							break;
						case 3:
							cr=1;
							cc=1;
							break;
						case 4:
							cr=0;
							cc=-1;
							break;
						case 6:
							cr=0;
							cc=1;
							break;
						case 7:
							cr=-1;
							cc=-1;
							break;
						case 8:
							cr=-1;
							cc=0;
							break;
						case 9:
							cr=-1;
							cc=1;
							break;
					}
					while(1)
					{
						RowFind+=cr;
						ColFind+=cc;
						if(m_aGrid[RowFind][ColFind]==-color)
							temp++;
						else
							break;
					}
				}
				if(temp>max) 
				{
					max=temp;
					maxRow=i;
					maxCol=j;
				}
			}
		}
	if(maxRow!=-1 && maxCol!=-1)
	{
		m_aGrid [maxRow][maxCol] = color;
		m_nFlag = -m_nFlag;
		for(k=1;k<=9;k++)
		if(k!=5 &&  IfOneCanSet(color, maxRow, maxCol, k))
		{
			int cr,cc;
			int RowFind=maxRow,ColFind=maxCol;
			switch(k)
			{
				case 1:
					cr=1;
					cc=-1;
					break;
				case 2:
					cr=1;
					cc=0;
					break;
				case 3:
					cr=1;
					cc=1;
					break;
				case 4:
					cr=0;
					cc=-1;
					break;
				case 6:
					cr=0;
					cc=1;
					break;
				case 7:
					cr=-1;
					cc=-1;
					break;
				case 8:
					cr=-1;
					cc=0;
					break;
				case 9:
					cr=-1;
					cc=1;
					break;
			}
			while(1)
			{
				RowFind+=cr;
				ColFind+=cc;
				if(m_aGrid[RowFind][ColFind]==-color)
					m_aGrid[RowFind][ColFind]=color;
				else
					break;
			}
		}
		return true ;
	}
	return false;
}

int  Reversi::GetFlag()	//查看该谁下子
{
	return m_nFlag;
}

int  Reversi::Judge()          //胜负判断
{
	//遍历
	int i,j;
	int white=0,black=0,block=0;
	bool isCan=false;
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
		{
			if(m_aGrid[i][j]==-1)
				white++;
			if(m_aGrid[i][j]==1)
				black++;
			if(m_aGrid[i][j]==0)
			{
				block++;
				for(int k=1;k<=9;k++)
					if(k!=5 && IfOneCanSet(GetFlag(), i, j, k))
						isCan=true;
			}
		}
	//已无黑子
	if(!black)
		return -1;
	//已无白子
    if(!white)
		return 1;
	//无空位
	if(!block)
	{
		if(black>white) return 1;
		else if(black<white) return -1;
		else return 2;
	}
	//无法下
	if(!isCan)		
	{
		m_nFlag=-m_nFlag;
		return 0;
	}
	return 0;
}

bool Reversi::IfCanSet(int color, int RowPos, int ColPos)
{
	bool isCan=false;
	if(m_aGrid [RowPos][ColPos])//无空位
		return  false;
	for(int i=1;i<=9;i++)
		if(i!=5 && IfOneCanSet(color, RowPos, ColPos, i))//往不同方向在遇到空位前找到color颜色
		{
			//左、左上、上等八个方向做吃子处理	
			isCan=true;
			int cr,cc;
			int RowFind=RowPos,ColFind=ColPos;
			switch(i)
			{
				case 1:
					cr=1;
					cc=-1;
					break;
				case 2:
					cr=1;
					cc=0;
					break;
				case 3:
					cr=1;
					cc=1;
					break;
				case 4:
					cr=0;
					cc=-1;
					break;
				case 6:
					cr=0;
					cc=1;
					break;
				case 7:
					cr=-1;
					cc=-1;
					break;
				case 8:
					cr=-1;
					cc=0;
					break;
				case 9:
					cr=-1;
					cc=1;
					break;
			}
			while(1)
			{
				RowFind+=cr;
				ColFind+=cc;
				if(m_aGrid[RowFind][ColFind]==-color)
					m_aGrid[RowFind][ColFind]=color;
				else
					break;
			}
		}
	return isCan; 
}
bool Reversi::IfOneCanSet(int color, int RowPos, int ColPos,int direction)
{
	int cr,cc;
	int RowFind=RowPos,ColFind=ColPos;
	switch(direction)
	{
		case 1:
			cr=1;
			cc=-1;
			break;
		case 2:
			cr=1;
			cc=0;
			break;
		case 3:
			cr=1;
			cc=1;
			break;
		case 4:
			cr=0;
			cc=-1;
			break;
		case 6:
			cr=0;
			cc=1;
			break;
		case 7:
			cr=-1;
			cc=-1;
			break;
		case 8:
			cr=-1;
			cc=0;
			break;
		case 9:
			cr=-1;
			cc=1;
			break;
	}
	bool isFlag=false;
	while(1)
	{
		if((RowFind==0 && cr<0) || (RowFind==7 && cr>0) || (ColFind==0 && cc<0) || (ColFind==7 && cc>0))
		//到尽头
			return false;
		RowFind+=cr;
		ColFind+=cc;
		if(m_aGrid[RowFind][ColFind]==color&&isFlag)
		{
			return true;
		}
		if(m_aGrid[RowFind][ColFind]==color&&!isFlag)
		{
			return false;
		}
		if(m_aGrid[RowFind][ColFind]==-color)
		{
			isFlag=true;
		}
		if(m_aGrid[RowFind][ColFind]==0)
		{
			return false;
		}
	}
	return false;
}