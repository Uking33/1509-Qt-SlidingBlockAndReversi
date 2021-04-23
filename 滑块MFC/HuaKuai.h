// HuaKuai.h : main header file for the HUAKUAI application
//

#if !defined(AFX_HUAKUAI_H__877621FB_CBE1_4AA4_AAA2_F9B76BC2DA65__INCLUDED_)
#define AFX_HUAKUAI_H__877621FB_CBE1_4AA4_AAA2_F9B76BC2DA65__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CHuaKuaiApp:
// See HuaKuai.cpp for the implementation of this class
//

class CHuaKuaiApp : public CWinApp
{
public:
	CHuaKuaiApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHuaKuaiApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CHuaKuaiApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HUAKUAI_H__877621FB_CBE1_4AA4_AAA2_F9B76BC2DA65__INCLUDED_)
