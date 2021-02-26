
// MFCDemo2Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCDemo2.h"
#include "MFCDemo2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDemo2Dlg dialog



CMFCDemo2Dlg::CMFCDemo2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ECHOBUTTONEVENT_DIALOG, pParent)
	, m_EchoText(_T(""))
	, m_VSliderEcho(_T(""))
	, mHSliderBarEcho(_T(""))
	, m_TImerEcho(_T(""))
	, m_MouseEcho(_T(""))
	, m_TimerCtrlSliders(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCDemo2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDD_ECHO_AREA, m_EchoText);
	DDX_Text(pDX, IDC_V_SLIDER_ECHO, m_VSliderEcho);
	DDX_Control(pDX, IDC_V_SLIDE_BAR, m_VSliderBar);
	DDX_Control(pDX, IDC_H_SLIDER_BAR, m_HSliderBar);
	DDX_Text(pDX, IDC_H_SLIDER_ECHO, mHSliderBarEcho);
	DDX_Text(pDX, IDC_TIMER_ECHO, m_TImerEcho);
	DDX_Text(pDX, IDC_MOUSE_POSITION_ECHO, m_MouseEcho);
	DDX_Check(pDX, IDC_TIMER_CONTROL_SLIDERS, m_TimerCtrlSliders);
}

BEGIN_MESSAGE_MAP(CMFCDemo2Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCDemo2Dlg::OnBnClickedButtonAdd)
	ON_STN_CLICKED(IDC_V_SLIDER_ECHO, &CMFCDemo2Dlg::OnStnClickedVSliderEcho)
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
	ON_WM_TIMER()
	ON_STN_CLICKED(IDC_TIMER_ECHO, &CMFCDemo2Dlg::OnStnClickedTimerEcho)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_TIMER_CONTROL_SLIDERS, &CMFCDemo2Dlg::OnBnClickedTimerControlSliders)
END_MESSAGE_MAP()


// CMFCDemo2Dlg message handlers

BOOL CMFCDemo2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_OkCount = 0;
	m_VSliderBar.SetRange(0, 100, true);
	m_VSliderBar.SetPos(0);

	m_HSliderBar.SetRange(0, 100, true);
	m_HSliderBar.SetPos(0);
	m_VSliderEcho.Format(_T("%d"), 0);

	m_Seconds = 0;
	SetTimer(0, 1000, NULL);

	m_TimerCtrlSliders = true;
	UpdateData(false);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCDemo2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCDemo2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCDemo2Dlg::OnBnClickedButtonAdd()
{
	m_OkCount++;
	m_EchoText.Format(_T("%d"), m_OkCount);
	UpdateData(false);
}


void CMFCDemo2Dlg::OnStnClickedVSliderEcho()
{
	// TODO: Add your control notification handler code here
}


void CMFCDemo2Dlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if (pScrollBar == (CScrollBar*) &m_VSliderBar) {
		int value = m_VSliderBar.GetPos();
		m_VSliderEcho.Format(_T("%d"), value);
		UpdateData(false);
	} 
	else {
		CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
	}
}


void CMFCDemo2Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if (pScrollBar == (CScrollBar*)&m_HSliderBar) {
		int value = m_HSliderBar.GetPos();
		mHSliderBarEcho.Format(_T("%d"), value);
		UpdateData(false);
	}
	else {
		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
	
}


void CMFCDemo2Dlg::OnTimer(UINT_PTR nIDEvent)
{
	m_Seconds++;
	m_TImerEcho.Format(_T("%d seconds have passed"), m_Seconds);
	UpdateData(false);

	if (m_TimerCtrlSliders) {

		int hValue = m_HSliderBar.GetPos();
		if (hValue > 0) {
			m_HSliderBar.SetPos(hValue - 1);
			mHSliderBarEcho.Format(_T("%d"), hValue - 1);
		}

		int vValue = m_VSliderBar.GetPos();
		if (vValue > 0) {
			m_VSliderBar.SetPos(vValue - 1);
			mHSliderBarEcho.Format(_T("%d"), vValue - 1);
		}

		if (hValue == 0 && vValue == 0) {
			m_TimerCtrlSliders = false;
		}
	}
}


void CMFCDemo2Dlg::OnStnClickedTimerEcho()
{
	// TODO: Add your control notification handler code here
}


void CMFCDemo2Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_MouseEcho.Format(_T("Left Mouse down at %d %d"), point.x, point.y);
	UpdateData(false);
}


void CMFCDemo2Dlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	m_MouseEcho.Format(_T("Right Mouse down at %d %d"), point.x, point.y);
	UpdateData(false);
}


void CMFCDemo2Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	m_MouseEcho.Format(_T("Mouse Move At %d %d"), point.x, point.y);
	UpdateData(false);
}


void CMFCDemo2Dlg::OnBnClickedTimerControlSliders()
{
	UpdateData(true);
}



