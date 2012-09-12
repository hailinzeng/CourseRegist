// Course_RegistDoc.h : interface of the CCourse_RegistDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_COURSE_REGISTDOC_H__316672E4_6D09_4C9A_8AF4_B31C3FC1704E__INCLUDED_)
#define AFX_COURSE_REGISTDOC_H__316672E4_6D09_4C9A_8AF4_B31C3FC1704E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCourse_RegistDoc : public CDocument
{
protected: // create from serialization only
	CCourse_RegistDoc();
	DECLARE_DYNCREATE(CCourse_RegistDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCourse_RegistDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCourse_RegistDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCourse_RegistDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COURSE_REGISTDOC_H__316672E4_6D09_4C9A_8AF4_B31C3FC1704E__INCLUDED_)
