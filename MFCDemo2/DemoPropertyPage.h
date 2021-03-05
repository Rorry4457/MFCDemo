#pragma once


// DemoPropertyPage

class DemoPropertyPage : public CMFCPropertyPage
{
	DECLARE_DYNAMIC(DemoPropertyPage)


	enum { IDD = IDD_MAN_PAGE };

public:
	DemoPropertyPage();
	virtual ~DemoPropertyPage();

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
};


