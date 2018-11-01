
// Practice4_2Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Practice4_2.h"
#include "Practice4_2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPractice4_2Dlg ��ȭ ����



CPractice4_2Dlg::CPractice4_2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PRACTICE4_2_DIALOG, pParent)
	, m_strYear(_T(""))
	, m_strMonth(_T(""))
	, m_strDay(_T(""))
	, m_strAMPM(_T(""))
	, m_strHour(_T(""))
	, m_strMinute(_T(""))
	, m_strSecond(_T(""))
	, m_bRadioClockType(false)
	, m_bCheckHour(false)
	, m_bCheckYear(false)
	, m_bVIewHelp(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPractice4_2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_YEAR, m_strYear);
	DDX_Text(pDX, IDC_EDIT_MONTH, m_strMonth);
	DDX_Text(pDX, IDC_EDIT_DAY, m_strDay);
	DDX_Text(pDX, IDC_EDIT_AMPM, m_strAMPM);
	DDX_Text(pDX, IDC_EDIT_HOUR, m_strHour);
	DDX_Text(pDX, IDC_EDIT_MINUTE, m_strMinute);
	DDX_Text(pDX, IDC_EDIT_SECOND, m_strSecond);
}

BEGIN_MESSAGE_MAP(CPractice4_2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(IDC_RADIO_12, &CPractice4_2Dlg::OnRadio12)
	ON_COMMAND(IDC_RADIO_24, &CPractice4_2Dlg::OnRadio24)
	ON_BN_CLICKED(IDC_CHECK_YEAR, &CPractice4_2Dlg::OnClickedCheckYear)
	ON_BN_CLICKED(IDC_CHECK_HOUR, &CPractice4_2Dlg::OnClickedCheckHour)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_HELP, &CPractice4_2Dlg::OnClickedButtonHelp)
END_MESSAGE_MAP()


// CPractice4_2Dlg �޽��� ó����

BOOL CPractice4_2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.




	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	//Radio Button�� Check Box �ʱ�ȭ
	((CButton*)GetDlgItem(IDC_RADIO_12))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_CHECK_HOUR))->SetCheck(TRUE);

	// ��, ��, �� Edit Control �ʱ�ȭ
	GetDlgItem(IDC_EDIT_YEAR)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_MONTH)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_DAY)->ShowWindow(SW_HIDE);

	// ��, ��, �� Static Text �ʱ�ȭ
	GetDlgItem(IDC_STATIC_YEAR)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_MONTH)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_DAY)->ShowWindow(SW_HIDE);

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	//��� ���� �ʱ�ȭ
	m_bRadioClockType = true;
	m_bCheckHour = true;
	m_bCheckYear = false;

	SetTimer(0, 1000, NULL);
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CPractice4_2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CPractice4_2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CPractice4_2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPractice4_2Dlg::OnRadio12()
{
	m_bRadioClockType = true;
}


void CPractice4_2Dlg::OnRadio24()
{
	m_bRadioClockType = false;
}


void CPractice4_2Dlg::OnClickedCheckYear()
{
	if (m_bCheckYear == false)
	{
		GetDlgItem(IDC_EDIT_YEAR)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_MONTH)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_DAY)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_YEAR)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_YEAR)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_YEAR)->ShowWindow(SW_SHOW);

		m_bCheckYear = true;
	}
	else
	{
		GetDlgItem(IDC_EDIT_YEAR)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_MONTH)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_DAY)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_YEAR)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_YEAR)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_YEAR)->ShowWindow(SW_HIDE);

		m_bCheckYear = false;
	}

}


void CPractice4_2Dlg::OnClickedCheckHour()
{
	if (m_bCheckHour == false)
	{
		GetDlgItem(IDC_EDIT_HOUR)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_MINUTE)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_SECOND)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_AMPM)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_HOUR)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_MINUTE)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_SECOND)->ShowWindow(SW_SHOW);

		m_bCheckHour = true;
	}
	else
	{
		GetDlgItem(IDC_EDIT_HOUR)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_MINUTE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_SECOND)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_AMPM)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_HOUR)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_MINUTE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_SECOND)->ShowWindow(SW_HIDE);

		m_bCheckHour = false;
	}
}


void CPractice4_2Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	int hour;
	CTime timer;
	timer = CTime::GetCurrentTime();

	m_strYear.Format(_T("%d"), timer.GetYear());
	m_strMonth.Format(_T("%d"), timer.GetMonth());
	m_strDay.Format(_T("%d"), timer.GetDay());


	hour = timer.GetHour();
	if (m_bRadioClockType) {

		if (hour >= 12)
		{
			m_strAMPM = _T("PM");
			if (hour >= 13)
				hour = hour - 12;
		}
		else
		{
			m_strAMPM = _T("AM");
		}
	}
	else
	{
		m_strAMPM.Empty();
	}

	m_strHour.Format(_T("%d"), hour);
	m_strMinute.Format(_T("%d"), timer.GetMinute());
	m_strSecond.Format(_T("%d"), timer.GetSecond());
	UpdateData(FALSE);

	CDialogEx::OnTimer(nIDEvent);
}


void CPractice4_2Dlg::OnClickedButtonHelp()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_bVIewHelp == false)
	{
		m_dlgClockHelp.Create(IDD_DIALOG_HELP, this);

		CRect rectMain, rectHelp;
		GetWindowRect(&rectMain);

		m_dlgClockHelp.GetWindowRect(&rectHelp);
		m_dlgClockHelp.MoveWindow(rectMain.right, rectMain.top, rectHelp.Width(), rectHelp.Height());
		m_dlgClockHelp.ShowWindow(SW_SHOW);
		m_bVIewHelp = true;

	}
	else
	{
		m_dlgClockHelp.ShowWindow(SW_HIDE);
		m_dlgClockHelp.DestroyWindow();
		m_bVIewHelp = false;
	}
}
