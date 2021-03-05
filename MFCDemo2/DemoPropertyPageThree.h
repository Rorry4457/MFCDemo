#pragma once


// DemoPropertyPageThree

class DemoPropertyPageThree : public CMFCPropertyPage
{
	DECLARE_DYNAMIC(DemoPropertyPageThree)

	enum {IDD = IDD_MAN_PAGE3};

public:
	DemoPropertyPageThree();
	virtual ~DemoPropertyPageThree();

	BOOL OnSetActive();

	BOOL OnWizardFinish();

protected:
	DECLARE_MESSAGE_MAP()
};


