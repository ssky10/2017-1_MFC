
// CalDlg.h : ��� ����
//

#pragma once


// CCalDlg ��ȭ ����
class CCalDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CCalDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CAL_DIALOG };
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
	afx_msg void OnBnClicked1();
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked3();
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClicked5();
	afx_msg void OnBnClicked6();
	afx_msg void OnBnClicked7();
	afx_msg void OnBnClicked8();
	afx_msg void OnBnClicked9();
	afx_msg void OnBnClicked0();
	afx_msg void OnSetfocusN1();
	afx_msg void OnSetfocusN2();
	int Focus;
	void ClickedNum(CString val);
	afx_msg void OnBnClickedDot();
	afx_msg void OnBnClickedPlus();
	void DispCurVal(double val);
	afx_msg void OnBnClickedMinus();
	afx_msg void OnSetfocusN3();
};
