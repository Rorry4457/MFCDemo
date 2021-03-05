// DemoPropertyPage.cpp : implementation file
//

#include "pch.h"
#include "MFCDemo2.h"
#include "DemoPropertyPage.h"


// DemoPropertyPage

IMPLEMENT_DYNAMIC(DemoPropertyPage, CMFCPropertyPage)

DemoPropertyPage::DemoPropertyPage(): CMFCPropertyPage(IDD)
{

}

DemoPropertyPage::~DemoPropertyPage()
{
}


BEGIN_MESSAGE_MAP(DemoPropertyPage, CMFCPropertyPage)
END_MESSAGE_MAP()



// DemoPropertyPage message handlers




BOOL DemoPropertyPage::OnSetActive()
{

	CPropertySheet *parentSheet = (CPropertySheet*)GetParent();
	parentSheet->SetWizardButtons(PSWIZB_NEXT | PSWIZB_BACK);

	return CMFCPropertyPage::OnSetActive();
}
