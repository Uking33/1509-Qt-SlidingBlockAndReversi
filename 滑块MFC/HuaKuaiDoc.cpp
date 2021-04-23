// HuaKuaiDoc.cpp : implementation of the CHuaKuaiDoc class
//

#include "stdafx.h"
#include "HuaKuai.h"

#include "HuaKuaiDoc.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHuaKuaiDoc

IMPLEMENT_DYNCREATE(CHuaKuaiDoc, CDocument)

BEGIN_MESSAGE_MAP(CHuaKuaiDoc, CDocument)
	//{{AFX_MSG_MAP(CHuaKuaiDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHuaKuaiDoc construction/destruction

CHuaKuaiDoc::CHuaKuaiDoc()
{
	// TODO: add one-time construction code here

}

CHuaKuaiDoc::~CHuaKuaiDoc()
{
}

BOOL CHuaKuaiDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	//对不需要变化的数据初始化
	L = 100;   //连杆长度
	W = 10;    //连杆宽度
	L1 = 25;   //主动块长度
	W1 = 20;   //主动块宽度
	L2 = 50;   //从动块长度
	W2 = 40;   //从动块宽度
	Origin = CPoint(0,0);  //暂时初始化为(0,0)点，一会要根据窗口实际情况变化

	//dX开始时为0，dX是要变化的
	dX = 0;
	

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CHuaKuaiDoc serialization

void CHuaKuaiDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CHuaKuaiDoc diagnostics

#ifdef _DEBUG
void CHuaKuaiDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHuaKuaiDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHuaKuaiDoc commands
//按照主动块与参考原点的距离dX，计算出代表各个部件的多边形顶点坐标
void CHuaKuaiDoc::CalPosition()
{
	//计算主动导轨四点的位置
	Gui1[0].x = (int)(Origin.x - L - 10 + 0.5);
	Gui1[0].y = (int)(Origin.y - W1/2 + 0.5);
	Gui1[1].x = (int)(Origin.x + L + 10 + 0.5);
	Gui1[1].y = (int)(Origin.y - W1/2 + 0.5);
	Gui1[2].x = (int)(Origin.x - L - 10 + 0.5);
	Gui1[2].y = (int)(Origin.y + W1/2 + 0.5);
	Gui1[3].x = (int)(Origin.x + L + 10 + 0.5);
	Gui1[3].y = (int)(Origin.y + W1/2 + 0.5);

	//计算主动块位置
	Kuai1[0].x = (int)(Origin.x +dX - L1/2 + 0.5);
	Kuai1[0].y = (int)(Origin.y - W1/2 + 0.5);
	Kuai1[1].x = (int)(Origin.x +dX + L1/2 + 0.5);
	Kuai1[1].y = (int)(Origin.y - W1/2 + 0.5);
	Kuai1[2].x = (int)(Origin.x +dX + L1/2 + 0.5);
	Kuai1[2].y = (int)(Origin.y + W1/2 + 0.5);
	Kuai1[3].x = (int)(Origin.x +dX - L1/2 + 0.5);
	Kuai1[3].y = (int)(Origin.y + W1/2 + 0.5);

	//计算从动导轨四点的位置
	Gui2[0].x = (int)(Origin.x - W2/2.0);
	Gui2[0].y = (int)(Origin.y + 20);
	Gui2[1].x = (int)(Origin.x - W2/2.0);
	Gui2[1].y = (int)(Origin.y + L + L2);
	Gui2[2].x = (int)(Origin.x + W2/2.0);
	Gui2[2].y = (int)(Origin.y + 20);
	Gui2[3].x = (int)(Origin.x + W2/2.0);
	Gui2[3].y = (int)(Origin.y + L + L2);

	//计算从动块位置
	Kuai2[0].x = (int)(Origin.x + W2/2.0);
	Kuai2[0].y = (int)(Origin.y + sqrt(L*L-dX*dX) + L2/2.0);
	Kuai2[1].x = (int)(Origin.x - W2/2.0);
	Kuai2[1].y = (int)(Origin.y + sqrt(L*L-dX*dX) + L2/2.0);
	Kuai2[2].x = (int)(Origin.x - W2/2.0);
	Kuai2[2].y = (int)(Origin.y + sqrt(L*L-dX*dX) - L2/2.0);
	Kuai2[3].x = (int)(Origin.x + W2/2.0);
	Kuai2[3].y = (int)(Origin.y + sqrt(L*L-dX*dX) - L2/2.0);

	//计算连杆位置
	Gan[0].x = (int)(Origin.x + dX - W*sqrt(L*L-dX*dX)/2.0/L);
	Gan[0].y = (int)(Origin.y - W*dX/2.0/L);
	Gan[1].x = (int)(Origin.x + dX + W*sqrt(L*L-dX*dX)/2.0/L);
	Gan[1].y = (int)(Origin.y + W*dX/2.0/L);
	Gan[2].x = (int)(Origin.x + W*sqrt(L*L-dX*dX)/2.0/L);
	Gan[2].y = (int)(Origin.y + sqrt(L*L-dX*dX) + W*dX/2.0/L);
	Gan[3].x = (int)(Origin.x - W*sqrt(L*L-dX*dX)/2.0/L);
	Gan[3].y = (int)(Origin.y + sqrt(L*L-dX*dX) - W*dX/2.0/L);

	
	for(int i=0;i<=100;i++)
	{
		double pX=-L+L/50.0*i;
		Path[i].x=(int)(pX+0+Origin.x*2)/2 ;
		Path[i].y=(int)(0+sqrt(L*L-pX*pX)+Origin.y*2)/2 ;
	}
}