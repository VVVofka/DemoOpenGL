#include "stdafx.h"
#include "OG.h"
#include "OGDoc.h"
IMPLEMENT_DYNCREATE(COGDoc, CDocument)

BEGIN_MESSAGE_MAP(COGDoc, CDocument)
	//{{AFX_MSG_MAP(COGDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COGDoc construction/destruction
COGDoc::COGDoc(){}
COGDoc::~COGDoc(){}

BOOL COGDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}
/////////////////////////////////////////////////////////////////////////////
// COGDoc serialization
void COGDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}
/////////////////////////////////////////////////////////////////////////////
// COGDoc diagnostics

#ifdef _DEBUG
void COGDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COGDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COGDoc commands
