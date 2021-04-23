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
	//�Բ���Ҫ�仯�����ݳ�ʼ��
	L = 100;   //���˳���
	W = 10;    //���˿��
	L1 = 25;   //�����鳤��
	W1 = 20;   //��������
	L2 = 50;   //�Ӷ��鳤��
	W2 = 40;   //�Ӷ�����
	Origin = CPoint(0,0);  //��ʱ��ʼ��Ϊ(0,0)�㣬һ��Ҫ���ݴ���ʵ������仯

	//dX��ʼʱΪ0��dX��Ҫ�仯��
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
//������������ο�ԭ��ľ���dX�������������������Ķ���ζ�������
void CHuaKuaiDoc::CalPosition()
{
	//�������������ĵ��λ��
	Gui1[0].x = (int)(Origin.x - L - 10 + 0.5);
	Gui1[0].y = (int)(Origin.y - W1/2 + 0.5);
	Gui1[1].x = (int)(Origin.x + L + 10 + 0.5);
	Gui1[1].y = (int)(Origin.y - W1/2 + 0.5);
	Gui1[2].x = (int)(Origin.x - L - 10 + 0.5);
	Gui1[2].y = (int)(Origin.y + W1/2 + 0.5);
	Gui1[3].x = (int)(Origin.x + L + 10 + 0.5);
	Gui1[3].y = (int)(Origin.y + W1/2 + 0.5);

	//����������λ��
	Kuai1[0].x = (int)(Origin.x +dX - L1/2 + 0.5);
	Kuai1[0].y = (int)(Origin.y - W1/2 + 0.5);
	Kuai1[1].x = (int)(Origin.x +dX + L1/2 + 0.5);
	Kuai1[1].y = (int)(Origin.y - W1/2 + 0.5);
	Kuai1[2].x = (int)(Origin.x +dX + L1/2 + 0.5);
	Kuai1[2].y = (int)(Origin.y + W1/2 + 0.5);
	Kuai1[3].x = (int)(Origin.x +dX - L1/2 + 0.5);
	Kuai1[3].y = (int)(Origin.y + W1/2 + 0.5);

	//����Ӷ������ĵ��λ��
	Gui2[0].x = (int)(Origin.x - W2/2.0);
	Gui2[0].y = (int)(Origin.y + 20);
	Gui2[1].x = (int)(Origin.x - W2/2.0);
	Gui2[1].y = (int)(Origin.y + L + L2);
	Gui2[2].x = (int)(Origin.x + W2/2.0);
	Gui2[2].y = (int)(Origin.y + 20);
	Gui2[3].x = (int)(Origin.x + W2/2.0);
	Gui2[3].y = (int)(Origin.y + L + L2);

	//����Ӷ���λ��
	Kuai2[0].x = (int)(Origin.x + W2/2.0);
	Kuai2[0].y = (int)(Origin.y + sqrt(L*L-dX*dX) + L2/2.0);
	Kuai2[1].x = (int)(Origin.x - W2/2.0);
	Kuai2[1].y = (int)(Origin.y + sqrt(L*L-dX*dX) + L2/2.0);
	Kuai2[2].x = (int)(Origin.x - W2/2.0);
	Kuai2[2].y = (int)(Origin.y + sqrt(L*L-dX*dX) - L2/2.0);
	Kuai2[3].x = (int)(Origin.x + W2/2.0);
	Kuai2[3].y = (int)(Origin.y + sqrt(L*L-dX*dX) - L2/2.0);

	//��������λ��
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