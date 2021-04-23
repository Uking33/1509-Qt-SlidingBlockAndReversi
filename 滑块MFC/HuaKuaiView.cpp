// HuaKuaiView.cpp : implementation of the CHuaKuaiView class
//

#include "stdafx.h"
#include "HuaKuai.h"

#include "HuaKuaiDoc.h"
#include "HuaKuaiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHuaKuaiView

IMPLEMENT_DYNCREATE(CHuaKuaiView, CView)

BEGIN_MESSAGE_MAP(CHuaKuaiView, CView)
	//{{AFX_MSG_MAP(CHuaKuaiView)
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_BEGIN, OnBegin)
	ON_COMMAND(ID_STOP, OnStop)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHuaKuaiView construction/destruction

CHuaKuaiView::CHuaKuaiView()
{
	// TODO: add construction code here
	isStart=false;
}

CHuaKuaiView::~CHuaKuaiView()
{
}

BOOL CHuaKuaiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CHuaKuaiView drawing

void CHuaKuaiView::OnDraw(CDC* pDC)
{
	CPen penThick,pen1, *oldpen;
	CHuaKuaiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	//先确定参考原点的位置
	CRect recClient;
	GetClientRect(&recClient);
	pDoc->Origin.x = recClient.Width()/2;
	pDoc->Origin.y = recClient.Height()/3;
	
	if(isStart)
	{
		pDoc->dX=-pDoc->L+pDoc->L/50*m_pX;
	}
	//原点可能以变化，需重新计算各部件位置
	pDoc->CalPosition();
	//画主动导轨
	pDC->MoveTo(pDoc->Gui1[0]);
	pDC->LineTo(pDoc->Gui1[1]);
	pDC->MoveTo(pDoc->Gui1[2]);
	pDC->LineTo(pDoc->Gui1[3]);
	//画从动导轨
	pDC->MoveTo(pDoc->Gui2[0]);
	pDC->LineTo(pDoc->Gui2[1]);
	pDC->MoveTo(pDoc->Gui2[2]);
	pDC->LineTo(pDoc->Gui2[3]);
	//换笔
	penThick.CreatePen(PS_SOLID,3,RGB(0,0,0));
	oldpen = pDC->SelectObject(&penThick);
	//画主动块
	pDC->Polygon(pDoc->Kuai1,4);
	//画从动块
	pDC->Polygon(pDoc->Kuai2,4);
	//画连杆
	pDC->Polygon(pDoc->Gan,4);
	
	//换笔
	pen1.CreatePen(PS_SOLID,2,RGB(200,20,60));
	oldpen = pDC->SelectObject(&pen1);
	if(isStart)
	{
		if(add==1)
			for(int i=0;i<m_pX;i++)
			{
				pDC->MoveTo(pDoc->Path[i]);
				pDC->LineTo(pDoc->Path[i+1]);
			}
		if(add==-1)
			for(int i=100;i>m_pX;i--)
			{
				pDC->MoveTo(pDoc->Path[i]);
				pDC->LineTo(pDoc->Path[i-1]);
			}
	}

	pDC->SelectObject(oldpen);
}

/////////////////////////////////////////////////////////////////////////////
// CHuaKuaiView printing

BOOL CHuaKuaiView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CHuaKuaiView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CHuaKuaiView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CHuaKuaiView diagnostics

#ifdef _DEBUG
void CHuaKuaiView::AssertValid() const
{
	CView::AssertValid();
}

void CHuaKuaiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHuaKuaiDoc* CHuaKuaiView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHuaKuaiDoc)));
	return (CHuaKuaiDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHuaKuaiView message handlers

void CHuaKuaiView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	CHuaKuaiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if(nChar=='A')
	{
		if(pDoc->dX-2 >= (-pDoc->L+10)) pDoc->dX -= 2; //让主动块左移2像素
	}
	else if(nChar=='D')
	{
		if(pDoc->dX+2 <= (pDoc->L-10)) pDoc->dX += 2; //让主动块右移2像素
	}
	pDoc->CalPosition();  //重新计算各部件位置
	Invalidate();         //刷新客户区

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CHuaKuaiView::OnBegin() 
{
	// TODO: Add your command handler code here	
	isStart=true;
	m_pX=0;
	add=1;
	SetTimer(1,100,NULL);	
}

void CHuaKuaiView::OnStop() 
{
	// TODO: Add your command handler code here		
	isStart=false;
}

void CHuaKuaiView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default	
	if(m_pX>=100) 
		add=-1;
	if(m_pX<=0) 
		add=1;
	if(!isStart)
		KillTimer(nIDEvent);
	Invalidate(); 
	m_pX+=add;
	CView::OnTimer(nIDEvent);
}
