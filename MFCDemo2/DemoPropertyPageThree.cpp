// DemoPropertyPageThree.cpp : implementation file
//

#include "pch.h"
#include "MFCDemo2.h"
#include "DemoPropertyPageThree.h"


// DemoPropertyPageThree

IMPLEMENT_DYNAMIC(DemoPropertyPageThree, CMFCPropertyPage)

DemoPropertyPageThree::DemoPropertyPageThree(): CMFCPropertyPage(IDD)
{

}

DemoPropertyPageThree::~DemoPropertyPageThree()
{
}


BEGIN_MESSAGE_MAP(DemoPropertyPageThree, CMFCPropertyPage)
END_MESSAGE_MAP()



// DemoPropertyPageThree message handlers

BOOL DemoPropertyPageThree::OnSetActive()
{
	CPropertySheet *parentSheet = (CPropertySheet*)GetParent();
	parentSheet->SetFinishText(_T("完成"));
	return CMFCPropertyPage::OnSetActive();
}


BOOL DemoPropertyPageThree::OnWizardFinish()
{

	MessageBox(_T("使用向导已完成"));

	return CMFCPropertyPage::OnWizardFinish();
}

