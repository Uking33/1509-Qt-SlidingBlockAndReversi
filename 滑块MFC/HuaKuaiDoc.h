// HuaKuaiDoc.h : interface of the CHuaKuaiDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HUAKUAIDOC_H__A2EAE8FE_7981_4985_8E15_52F8DA995E95__INCLUDED_)
#define AFX_HUAKUAIDOC_H__A2EAE8FE_7981_4985_8E15_52F8DA995E95__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHuaKuaiDoc : public CDocument
{
protected: // create from serialization only
	CHuaKuaiDoc();
	DECLARE_DYNCREATE(CHuaKuaiDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHuaKuaiDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	void CalPosition();
	double dX;       //主动块与参考原点的距离
	double L,W;      //连杆的长度和宽度
	double L1,W1;    //主动块的长度和宽度
	double L2,W2;    //从动块的长度和宽度
	CPoint Gui1[4];  //画主动导轨两条线的四个点
	CPoint Gui2[4];  //画从动导轨两条线的四个点
	CPoint Gan[4];     //连杆四边形的四点
	CPoint Kuai1[4]; //主动块四边形的四点
	CPoint Kuai2[4];  //从动块四边形的四点
	CPoint Origin;   //主动导轨的中点，机械机构的参考原点，程序中定为横向的中间、竖向的1/3处
	CPoint Path[101]; 
	virtual ~CHuaKuaiDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHuaKuaiDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HUAKUAIDOC_H__A2EAE8FE_7981_4985_8E15_52F8DA995E95__INCLUDED_)
