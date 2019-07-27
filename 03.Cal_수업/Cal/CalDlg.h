
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
	int PreVal;
	int PreOp;
	int CurVal;
	int CurOp;
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
	afx_msg void OnBnClicked00();
	afx_msg void OnBnClickedDot();
	afx_msg void OnBnClickedPlus();
	afx_msg void OnBnClickedMinus();
	// ���ڹ�ư Ŭ���� �̺�Ʈ �Լ�
	void ClickedNum(int val);
	// ���ڰ��� ȭ�鿡 ���
	void DispCurVal(int val);
	void Operate0();
	afx_msg void OnBnClickedBack();
	afx_msg void OnBnClickedMul();
	afx_msg void OnBnClickedDivide();
	float CurValReal;
	int AfterDotCnt;
	// �Ǽ� ���ڸ� ȭ�鿡 ���
	void DispValDot(int val1, float val2, int dot_cut);
	// �Ҽ��� ���Ͽ��� ���ڸ� �Է¹޾��� ��
	void ClickedNumReal(int val);
	// 0.1�� ������ ��ȯ
	float PowerOf(int cut);
	afx_msg void OnBnClickedEqual();
};
