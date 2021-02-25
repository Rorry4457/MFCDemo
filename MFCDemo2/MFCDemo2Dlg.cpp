
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
}

BEGIN_MESSAGE_MAP(CMFCDemo2Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCDemo2Dlg::OnBnClickedButtonAdd)
	ON_STN_CLICKED(IDC_V_SLIDER_ECHO, &CMFCDemo2Dlg::OnStnClickedVSliderEcho)
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
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
	m_VSliderEcho.Format(_T("%d"), 0);

	m_HSliderBar.SetRange(0, 100, true);
	m_HSliderBar.SetPos(0);
	m_VSliderEcho.Format(_T("%d"), 0);

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
