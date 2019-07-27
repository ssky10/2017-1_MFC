
// CalDlg.h : 헤더 파일
//

#pragma once


// CCalDlg 대화 상자
class CCalDlg : public CDialogEx
{
// 생성입니다.
public:
	CCalDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CAL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	double PreVal;
	int Op;
	CString CurVal;
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
	// 숫자버튼 클릭시 이벤트 함수
	void ClickedNum(CString val);
	void Operate0();
	afx_msg void OnBnClickedBack();
	afx_msg void OnBnClickedMul();
	afx_msg void OnBnClickedDivide();
	afx_msg void OnBnClickedEqual();
	//실수의 값을 화면에 출력
	void DispCurVal(double val);
};
