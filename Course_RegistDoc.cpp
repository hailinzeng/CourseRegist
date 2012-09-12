// Course_RegistDoc.cpp : implementation of the CCourse_RegistDoc class
//

#include "stdafx.h"
#include "Course_Regist.h"

#include "Course_RegistDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCourse_RegistDoc

IMPLEMENT_DYNCREATE(CCourse_RegistDoc, CDocument)

BEGIN_MESSAGE_MAP(CCourse_RegistDoc, CDocument)
	//{{AFX_MSG_MAP(CCourse_RegistDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCourse_RegistDoc construction/destruction

CCourse_RegistDoc::CCourse_RegistDoc()
{
	// TODO: add one-time construction code here

}

CCourse_RegistDoc::~CCourse_RegistDoc()
{
}

BOOL CCourse_RegistDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCourse_RegistDoc serialization

void CCourse_RegistDoc::Serialize(CArchive& ar)
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
// CCourse_RegistDoc diagnostics

#ifdef _DEBUG
void CCourse_RegistDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCourse_RegistDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCourse_RegistDoc commands
