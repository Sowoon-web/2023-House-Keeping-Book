
// FinalProjectBDlg.h: 헤더 파일
//

#pragma once
#include "CIncomeGraphDlg.h"
#include "CCategoryDlg.h"
#include "CSpendGraphDlg.h"


// CFinalProjectBDlg 대화 상자
class CFinalProjectBDlg : public CDialogEx
{
// 생성입니다.
public:
	CFinalProjectBDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FINALPROJECTB_DIALOG };
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
	CComboBox m_comboType;
	CString m_strIncome;
	CString m_strSalary;
	CString m_strSpend;
	CString m_strSpendTarget;
//	CString m_strWon;
	CListCtrl m_listDetail;
	COleDateTime m_timeMonthCalendar;
	CString m_incomeSpendSelect;
	afx_msg void OnRadioPlus();
	afx_msg void OnRadioFix();
	afx_msg void OnRadioVariable();
	afx_msg void OnEditupdateComboType();
	afx_msg void OnClickedButtonAdd();
	afx_msg void OnClickedButtonDel();
	CString m_strComboType;
//	int m_nWon;
	CString m_strWon;
//	afx_msg void OnClickedButtonSpendTarget();
	CString m_markedSalary;
	CString m_markedSpendTarget;
	afx_msg void OnClickedButtonSpendTarget();
//	afx_msg void OnUpdateEditMarkedSpendTarget();
//	void SuccFail();
	void SuccessFail();
	afx_msg void OnClickedButtonSalary();
//	afx_msg void OnGetdaystateMonthcalendar1(NMHDR* pNMHDR, LRESULT* pResult);
//	afx_msg void OnTimer(UINT_PTR nIDEvent);
//	void SetMonthlyTimer();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
//	afx_msg void OnDestroy();
	bool m_bIncomeComparison;
	CIncomeGraphDlg m_dlgIncomeGraph;
//	afx_msg void OnDoubleclickedButtonIncomeComparison();
	afx_msg void OnClickedButtonIncomeComparison();
	bool m_bCategory;
	CCategoryDlg m_dlgCategory;
	afx_msg void OnClickedButtonCategory();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
//	void janSum();

private:
	UINT_PTR m_nTimerID;
public:
	void AdjustDialogSize();
	bool m_bSpendComparison;
	CSpendGraphDlg m_dlgSpendGraph;
	afx_msg void OnClickedButtonSpendComparison();
};
