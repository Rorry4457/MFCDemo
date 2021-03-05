// DemoPropertySheet.cpp : implementation file
//

#include "pch.h"
#include "MFCDemo2.h"
#include "DemoPropertySheet.h"


// DemoPropertySheet

IMPLEMENT_DYNAMIC(DemoPropertySheet, CPropertySheet)

DemoPropertySheet::DemoPropertySheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	AddPage(&firstPage);
	AddPage(&secondPage);
	AddPage(&thirdPage);
}

DemoPropertySheet::DemoPropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage(&firstPage);
	AddPage(&secondPage);
	AddPage(&thirdPage);
}

DemoPropertySheet::~DemoPropertySheet()
{
}


BEGIN_MESSAGE_MAP(DemoPropertySheet, CPropertySheet)
END_MESSAGE_MAP()


// DemoPropertySheet message handlers
