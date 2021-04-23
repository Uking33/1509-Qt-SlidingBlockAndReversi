// BlackAndWhiteDoc.h : interface of the CBlackAndWhiteDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BLACKANDWHITEDOC_H__53C17E42_2FF0_4054_A2F5_04AE6D425DF5__INCLUDED_)
#define AFX_BLACKANDWHITEDOC_H__53C17E42_2FF0_4054_A2F5_04AE6D425DF5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "reversi.h"
class CBlackAndWhiteDoc : public CDocument
{
protected: // create from serialization only
	CBlackAndWhiteDoc();
	DECLARE_DYNCREATE(CBlackAndWhiteDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBlackAndWhiteDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	Reversi m_Reversi;      //��ֶ���
    int  m_nR, m_nC;        //��굱ǰ�ڵڼ��С��ڼ���
	int  m_black_win;		//����ʤ��
	int  m_white_win;		//����ʤ��
	int m_ptp;	//0Ϊ���ˣ�1��Ϊ�ڣ�-1��Ϊ��
	virtual ~CBlackAndWhiteDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBlackAndWhiteDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BLACKANDWHITEDOC_H__53C17E42_2FF0_4054_A2F5_04AE6D425DF5__INCLUDED_)
