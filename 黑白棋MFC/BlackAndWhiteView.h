// BlackAndWhiteView.h : interface of the CBlackAndWhiteView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BLACKANDWHITEVIEW_H__2C41667F_6089_413C_866D_08688693DCA4__INCLUDED_)
#define AFX_BLACKANDWHITEVIEW_H__2C41667F_6089_413C_866D_08688693DCA4__INCLUDED_

#include "Reversi.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBlackAndWhiteView : public CView
{
protected: // create from serialization only
	CBlackAndWhiteView();
	DECLARE_DYNCREATE(CBlackAndWhiteView)

// Attributes
public:
	CBlackAndWhiteDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBlackAndWhiteView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBlackAndWhiteView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBlackAndWhiteView)
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnPtcBlack();
	afx_msg void OnPtcWhite();
	afx_msg void OnPtp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BlackAndWhiteView.cpp
inline CBlackAndWhiteDoc* CBlackAndWhiteView::GetDocument()
   { return (CBlackAndWhiteDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BLACKANDWHITEVIEW_H__2C41667F_6089_413C_866D_08688693DCA4__INCLUDED_)
