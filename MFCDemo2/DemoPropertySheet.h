#pragma once

#include "DemoPropertyPage.h"
#include "DemoPropertyPageTwo.h"
#include "DemoPropertyPageThree.h"

// DemoPropertySheet

class DemoPropertySheet : public CPropertySheet
{
	DECLARE_DYNAMIC(DemoPropertySheet)

public:
	DemoPropertySheet(UINT nIDCaption, CWnd* pParentWnd = nullptr, UINT iSelectPage = 0);
	DemoPropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd = nullptr, UINT iSelectPage = 0);
	virtual ~DemoPropertySheet();

protected:
	DECLARE_MESSAGE_MAP()
	
private:
	DemoPropertyPage firstPage;
	DemoPropertyPageTwo secondPage;
	DemoPropertyPageThree thirdPage;
};


