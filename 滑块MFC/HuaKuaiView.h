// HuaKuaiView.h : interface of the CHuaKuaiView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HUAKUAIVIEW_H__FCDAFEF6_3FE1_4E31_8EC3_D31CEF80205C__INCLUDED_)
#define AFX_HUAKUAIVIEW_H__FCDAFEF6_3FE1_4E31_8EC3_D31CEF80205C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHuaKuaiView : public CView
{
protected: // create from serialization only
	CHuaKuaiView();
	DECLARE_DYNCREATE(CHuaKuaiView)

// Attributes
public:
	CHuaKuaiDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHuaKuaiView)
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
	int add;
	bool isStart;
	int m_pX;
	virtual ~CHuaKuaiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHuaKuaiView)
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnBegin();
	afx_msg void OnStop();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in HuaKuaiView.cpp
inline CHuaKuaiDoc* CHuaKuaiView::GetDocument()
   { return (CHuaKuaiDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HUAKUAIVIEW_H__FCDAFEF6_3FE1_4E31_8EC3_D31CEF80205C__INCLUDED_)
