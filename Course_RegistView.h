// Course_RegistView.h : interface of the CCourse_RegistView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_COURSE_REGISTVIEW_H__534CA6E2_AB20_489D_8344_8639DE918866__INCLUDED_)
#define AFX_COURSE_REGISTVIEW_H__534CA6E2_AB20_489D_8344_8639DE918866__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCourse_RegistView : public CView
{
protected: // create from serialization only
	CCourse_RegistView();
	DECLARE_DYNCREATE(CCourse_RegistView)

// Attributes
public:
	CCourse_RegistDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCourse_RegistView)
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
	virtual ~CCourse_RegistView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCourse_RegistView)
		afx_msg void OnLogin();
	afx_msg void OnInformation();
	afx_msg void OnMPassWord();
	afx_msg void OnAddStu();
	afx_msg void OnLogout();
	afx_msg void OnDelStu();
	afx_msg void OnMStu();
	afx_msg void OnAddPro();
	afx_msg void OnDelPro();
	afx_msg void OnMPro();
	afx_msg void OnAddCS();
	afx_msg void OnDelCS();
	afx_msg void OnMcs();
	afx_msg void OnUpdateLogin(CCmdUI* pCmdUI);
	afx_msg void OnUpdateLogout(CCmdUI* pCmdUI);
	afx_msg void OnUpdateAddStu(CCmdUI* pCmdUI);
	afx_msg void OnUpdateAddPro(CCmdUI* pCmdUI);
	afx_msg void OnUpdateAddCS(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDelCS(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDelPro(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDelStu(CCmdUI* pCmdUI);
	afx_msg void OnUpdateMcs(CCmdUI* pCmdUI);
	afx_msg void OnUpdateMPro(CCmdUI* pCmdUI);
	afx_msg void OnUpdateMStu(CCmdUI* pCmdUI);
	afx_msg void OnUpdateMPassWord(CCmdUI* pCmdUI);
	afx_msg void OnUpdateInformation(CCmdUI* pCmdUI);
	afx_msg void OnTsc();
	afx_msg void OnSeekCIF();
	afx_msg void OnUpdateTsc(CCmdUI* pCmdUI);
	afx_msg void OnSsc();
	afx_msg void OnUpdateSsc(CCmdUI* pCmdUI);
	afx_msg void OnGrade();
	afx_msg void OnUpdateGrade(CCmdUI* pCmdUI);
	afx_msg void OnMscore();
	afx_msg void OnUpdateMscore(CCmdUI* pCmdUI);
	afx_msg void OnNextStep();
	afx_msg void OnUpdateNextStep(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Course_RegistView.cpp
inline CCourse_RegistDoc* CCourse_RegistView::GetDocument()
   { return (CCourse_RegistDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COURSE_REGISTVIEW_H__534CA6E2_AB20_489D_8344_8639DE918866__INCLUDED_)
