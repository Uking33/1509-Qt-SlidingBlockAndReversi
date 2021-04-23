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
	double dX;       //��������ο�ԭ��ľ���
	double L,W;      //���˵ĳ��ȺͿ��
	double L1,W1;    //������ĳ��ȺͿ��
	double L2,W2;    //�Ӷ���ĳ��ȺͿ��
	CPoint Gui1[4];  //���������������ߵ��ĸ���
	CPoint Gui2[4];  //���Ӷ����������ߵ��ĸ���
	CPoint Gan[4];     //�����ı��ε��ĵ�
	CPoint Kuai1[4]; //�������ı��ε��ĵ�
	CPoint Kuai2[4];  //�Ӷ����ı��ε��ĵ�
	CPoint Origin;   //����������е㣬��е�����Ĳο�ԭ�㣬�����ж�Ϊ������м䡢�����1/3��
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
