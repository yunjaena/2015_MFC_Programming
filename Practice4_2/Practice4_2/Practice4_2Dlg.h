
// Practice4_2Dlg.h : ��� ����
//

#pragma once
#include "ClockHelpDlg.h"


// CPractice4_2Dlg ��ȭ ����
class CPractice4_2Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CPractice4_2Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRACTICE4_2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strYear;
	CString m_strMonth;
	CString m_strDay;
	CString m_strAMPM;
	CString m_strHour;
	CString m_strMinute;
	CString m_strSecond;
	bool m_bRadioClockType;
	afx_msg void OnRadio12();
	afx_msg void OnRadio24();
	bool m_bCheckHour;
	afx_msg void OnClickedCheckYear();
	bool m_bCheckYear;
	afx_msg void OnClickedCheckHour();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	bool m_bVIewHelp;
	CClockHelpDlg m_dlgClockHelp;
	afx_msg void OnClickedButtonHelp();
};
