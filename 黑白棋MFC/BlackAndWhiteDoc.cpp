// BlackAndWhiteDoc.cpp : implementation of the CBlackAndWhiteDoc class
//

#include "stdafx.h"
#include "BlackAndWhite.h"

#include "BlackAndWhiteDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBlackAndWhiteDoc

IMPLEMENT_DYNCREATE(CBlackAndWhiteDoc, CDocument)

BEGIN_MESSAGE_MAP(CBlackAndWhiteDoc, CDocument)
	//{{AFX_MSG_MAP(CBlackAndWhiteDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBlackAndWhiteDoc construction/destruction

CBlackAndWhiteDoc::CBlackAndWhiteDoc()
{
	// TODO: add one-time construction code here
	m_nR=3;
	m_nC=3;
	m_black_win=0;
	m_white_win=0;
	m_ptp=0;
}

CBlackAndWhiteDoc::~CBlackAndWhiteDoc()
{
}

BOOL CBlackAndWhiteDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBlackAndWhiteDoc serialization

void CBlackAndWhiteDoc::Serialize(CArchive& ar)
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
// CBlackAndWhiteDoc diagnostics

#ifdef _DEBUG
void CBlackAndWhiteDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBlackAndWhiteDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBlackAndWhiteDoc commands
