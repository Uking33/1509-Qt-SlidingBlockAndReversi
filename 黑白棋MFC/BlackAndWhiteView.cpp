// BlackAndWhiteView.cpp : implementation of the CBlackAndWhiteView class
//

#include "stdafx.h"
#include "BlackAndWhite.h"

#include "BlackAndWhiteDoc.h"
#include "BlackAndWhiteView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBlackAndWhiteView

IMPLEMENT_DYNCREATE(CBlackAndWhiteView, CView)

BEGIN_MESSAGE_MAP(CBlackAndWhiteView, CView)
	//{{AFX_MSG_MAP(CBlackAndWhiteView)
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_PTC_BLACK, OnPtcBlack)
	ON_COMMAND(ID_PTC_WHITE, OnPtcWhite)
	ON_COMMAND(ID_PTP, OnPtp)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBlackAndWhiteView construction/destruction

CBlackAndWhiteView::CBlackAndWhiteView()
{
	// TODO: add construction code here

}

CBlackAndWhiteView::~CBlackAndWhiteView()
{
}

BOOL CBlackAndWhiteView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBlackAndWhiteView drawing

void CBlackAndWhiteView::OnDraw(CDC* pDC)
{
	CBlackAndWhiteDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for herenative data
	CRect rect;
	GetWindowRect(&rect);
	CPoint m_ptOrigin;
	m_ptOrigin.x=(rect.Width()-40*12)/2;
	m_ptOrigin.y=(rect.Height()-40*8)/2;
	CPen pen1,pen2,*oldpen;
	int i,j;
	CBrush brushB,brushW,*brush2,*oldBrush;
	//棋盘-纹理	
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);
	CBrush brush0(&bitmap);
	pDC->FillRect(CRect(m_ptOrigin,CPoint(m_ptOrigin.x+8*40,m_ptOrigin.y+8*40)),&brush0);
	//棋盘-线
	pen1.CreatePen(PS_DASH,2,RGB(125,42,42));
	oldpen=pDC->SelectObject(&pen1);
	for(i=0;i<9;i++)
	{
		pDC->MoveTo(m_ptOrigin.x,m_ptOrigin.y+i*40);
		pDC->LineTo(m_ptOrigin.x+8*40,m_ptOrigin.y+i*40);
	}
	for(i=0;i<9;i++)
	{
		pDC->MoveTo(m_ptOrigin.x+i*40,m_ptOrigin.y);
		pDC->LineTo(m_ptOrigin.x+i*40,m_ptOrigin.y+8*40);
	}
	//棋子	
	pDC->SelectObject(oldpen);	
	brushW.CreateSolidBrush(RGB(255,255,255));
	brushB.CreateSolidBrush(RGB(0,0,0));
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
		{
			if(pDoc->m_Reversi.m_aGrid[i][j]==-1)
				pDC->SelectObject(&brushW);
			if(pDoc->m_Reversi.m_aGrid[i][j]==1)
				pDC->SelectObject(&brushB);
			if(pDoc->m_Reversi.m_aGrid[i][j])
				pDC->Ellipse(m_ptOrigin.x+i*40,m_ptOrigin.y+j*40,m_ptOrigin.x+i*40+40,m_ptOrigin.y+j*40+40);
		}
	//光标
	pen2.CreatePen(PS_DASH,3,RGB(64,244,205));
	pDC->SelectObject(&pen2);
	brush2=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	oldBrush=pDC->SelectObject(brush2);	
	pDC->Rectangle(CRect(m_ptOrigin.x+pDoc->m_nR*40,m_ptOrigin.y+pDoc->m_nC*40,m_ptOrigin.x+pDoc->m_nR*40+40,m_ptOrigin.y+pDoc->m_nC*40+40));
	//文字-胜局
	int tip_x;
	int tip_y;
	int per;
	tip_x=m_ptOrigin.x+40*8+20;
	tip_y=m_ptOrigin.y+20;
	CString str;
	if(pDoc->m_ptp==0)
	{
		if(pDoc->m_Reversi.GetFlag()==1)		
			str.Format(" √ 黑方：胜 %d 局", pDoc->m_black_win);
		else
			str.Format("      黑方：胜 %d 局", pDoc->m_black_win);
	}
	else if(pDoc->m_ptp==-1)
	{
		if(pDoc->m_Reversi.GetFlag()==1)		
			str.Format(" √ 电脑：胜 %d 局", pDoc->m_black_win);
		else
			str.Format("      电脑：胜 %d 局", pDoc->m_black_win);
	}
	else if(pDoc->m_ptp==1)
	{
		if(pDoc->m_Reversi.GetFlag()==1)		
			str.Format(" √ 玩家：胜 %d 局", pDoc->m_black_win);
		else
			str.Format("      玩家：胜 %d 局", pDoc->m_black_win);
	}
	pDC->TextOut(tip_x,tip_y,str);

	per=(int)((double)(pDoc->m_black_win)/(pDoc->m_white_win+pDoc->m_black_win)*100);
	str.Format("      胜率：%d %%",per);
	tip_y+=25;
	pDC->TextOut(tip_x,tip_y,str);

	if(pDoc->m_ptp==0)
	{
		if(pDoc->m_Reversi.GetFlag()==-1)		
			str.Format(" √ 白方：胜 %d 局", pDoc->m_white_win);
		else
			str.Format("      白方：胜 %d 局", pDoc->m_white_win);
	}
	else if(pDoc->m_ptp==-1)
	{
		if(pDoc->m_Reversi.GetFlag()==-1)		
			str.Format(" √ 玩家：胜 %d 局", pDoc->m_white_win);
		else
			str.Format("      玩家：胜 %d 局", pDoc->m_white_win);
	}
	else if(pDoc->m_ptp==1)
	{
		if(pDoc->m_Reversi.GetFlag()==-1)		
			str.Format(" √ 电脑：胜 %d 局", pDoc->m_white_win);
		else
			str.Format("      电脑：胜 %d 局", pDoc->m_white_win);
	}
	tip_y+=40;	
	pDC->TextOut(tip_x,tip_y,str);

	tip_y+=25;
	per=(int)((double)(pDoc->m_white_win)/(pDoc->m_white_win+pDoc->m_black_win)*100);
	str.Format("      胜率：%d %%",per);
	pDC->TextOut(tip_x,tip_y,str);
	//文字-提示
	tip_y=m_ptOrigin.y+40*5+20;
	
	if(pDoc->m_ptp==0)
	{
		str="提示：黑棋用箭头键和";
		pDC->TextOut(tip_x,tip_y,str);
		tip_y+=25;
		str="回车键走棋；白棋用W";
		pDC->TextOut(tip_x,tip_y,str);
		tip_y+=25;
		str="ASD和空格键走棋。";
		pDC->TextOut(tip_x,tip_y,str);
	}
	else
	{
		str="提示：用箭头键和回车";
		pDC->TextOut(tip_x,tip_y,str);
		tip_y+=25;
		str="键走棋";
		pDC->TextOut(tip_x,tip_y,str);
	}
	//复原
	pDC->SelectObject(oldpen);
	pDC->SelectObject(oldBrush);
}

/////////////////////////////////////////////////////////////////////////////
// CBlackAndWhiteView printing

BOOL CBlackAndWhiteView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBlackAndWhiteView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBlackAndWhiteView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CBlackAndWhiteView diagnostics

#ifdef _DEBUG
void CBlackAndWhiteView::AssertValid() const
{
	CView::AssertValid();
}

void CBlackAndWhiteView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBlackAndWhiteDoc* CBlackAndWhiteView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBlackAndWhiteDoc)));
	return (CBlackAndWhiteDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBlackAndWhiteView message handlers

void CBlackAndWhiteView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	CBlackAndWhiteDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	int color;
	if(!pDoc->m_ptp)
	{
		if(('A'==nChar && -1==pDoc->m_Reversi.GetFlag() || VK_LEFT==nChar && 1==pDoc->m_Reversi.GetFlag()) && pDoc->m_nR>0)
			pDoc->m_nR--;
		else if(('D'==nChar && -1==pDoc->m_Reversi.GetFlag() || VK_RIGHT==nChar && 1==pDoc->m_Reversi.GetFlag()) && pDoc->m_nR<7)
			pDoc->m_nR++;
		else if(('W'==nChar && -1==pDoc->m_Reversi.GetFlag() || VK_UP==nChar && 1==pDoc->m_Reversi.GetFlag()) && pDoc->m_nC>0)
			pDoc->m_nC--;
		else if(('S'==nChar && -1==pDoc->m_Reversi.GetFlag() || VK_DOWN==nChar && 1==pDoc->m_Reversi.GetFlag()) && pDoc->m_nC<7)
			pDoc->m_nC++;
		else if(32==nChar && -1==pDoc->m_Reversi.GetFlag())
			color=-1;
		else if(13==nChar && 1==pDoc->m_Reversi.GetFlag())
			color=1;
	}
	else 
	{
		if(pDoc->m_ptp==1)
			color=1;
		if(pDoc->m_ptp==-1)
			color=-1;
		if(VK_LEFT==nChar && color==pDoc->m_Reversi.GetFlag() && pDoc->m_nR>0)
			pDoc->m_nR--;
		else if(VK_RIGHT==nChar && color==pDoc->m_Reversi.GetFlag() && pDoc->m_nR<7)
			pDoc->m_nR++;
		else if(VK_UP==nChar && color==pDoc->m_Reversi.GetFlag() && pDoc->m_nC>0)
			pDoc->m_nC--;
		else if(VK_DOWN==nChar && color==pDoc->m_Reversi.GetFlag() && pDoc->m_nC<7)
			pDoc->m_nC++;
	}
	//下子
	if((13==nChar && color==pDoc->m_Reversi.GetFlag()) || (32==nChar && -1==pDoc->m_Reversi.GetFlag()))
		if(pDoc->m_Reversi.Set(color,pDoc->m_nR,pDoc->m_nC))
		{
			Invalidate();
			if(int win=pDoc->m_Reversi.Judge())//判断胜负
			{
				if(win==1)
				{
					pDoc->m_black_win++;
					MessageBox("黑棋胜利");
				}
				if(win==-1)
				{
					pDoc->m_white_win++;
					MessageBox("白棋胜利");
				}
				if(win==2)
					MessageBox("平局");
				pDoc->m_Reversi.init();
			}
			//电脑下
			if(pDoc->m_ptp)
			{
				color=-color;
				pDoc->m_Reversi.SetAuto(color);
				Invalidate();
				if(int win=pDoc->m_Reversi.Judge())//判断胜负
				{
					if(win==1)
					{
						pDoc->m_black_win++;
						MessageBox("黑棋胜利");
					}
					if(win==-1)
					{
						pDoc->m_white_win++;
						MessageBox("白棋胜利");
					}
					if(win==2)
						MessageBox("平局");
					pDoc->m_Reversi.init();
				}
			}
		}
	Invalidate();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CBlackAndWhiteView::OnPtcBlack() 
{
	// TODO: Add your command handler code here	
	CBlackAndWhiteDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->m_ptp=1;
	pDoc->m_black_win=0;
	pDoc->m_white_win=0;
	pDoc->m_Reversi.init();
	Invalidate();
}

void CBlackAndWhiteView::OnPtcWhite() 
{
	// TODO: Add your command handler code here
	CBlackAndWhiteDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->m_ptp=-1;
	pDoc->m_black_win=0;
	pDoc->m_white_win=0;
	pDoc->m_Reversi.init();
	//电脑下
	pDoc->m_Reversi.SetAuto(1);
	Invalidate();
}

void CBlackAndWhiteView::OnPtp() 
{
	// TODO: Add your command handler code here	
	CBlackAndWhiteDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->m_ptp=0;
	pDoc->m_black_win=0;
	pDoc->m_white_win=0;
	pDoc->m_Reversi.init();
	Invalidate();
}
