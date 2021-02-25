
// MFCDemo2Dlg.h : header file
//

#pragma once


// CMFCDemo2Dlg dialog
class CMFCDemo2Dlg : public CDialogEx
{
// Construction
public:
	CMFCDemo2Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ECHOBUTTONEVENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonAdd();

private: 
	int m_OkCount;
	CString m_EchoText;
public:
	afx_msg void OnStnClickedVSliderEcho();
private:
	CString m_VSliderEcho;
public:
	CSliderCtrl m_VSliderBar;
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CSliderCtrl m_HSliderBar;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CString mHSliderBarEcho;
};
