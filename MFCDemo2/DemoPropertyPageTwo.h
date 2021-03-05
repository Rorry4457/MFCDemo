#pragma once


// DemoPropertyPageTwo

class DemoPropertyPageTwo : public CMFCPropertyPage
{
	DECLARE_DYNAMIC(DemoPropertyPageTwo)

	enum 
	{ IDD = IDD_MAN_PAGE2};

public:
	DemoPropertyPageTwo();
	virtual ~DemoPropertyPageTwo();

protected:
	DECLARE_MESSAGE_MAP()
};


