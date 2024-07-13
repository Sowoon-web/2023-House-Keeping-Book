#pragma once
#include "afxdialogex.h"
#include <vector>


// CIncomeGraphDlg 대화 상자

class CIncomeGraphDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CIncomeGraphDlg)

public:
	CIncomeGraphDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CIncomeGraphDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_INCOME_GRAPH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
//	virtual BOOL OnInitDialog();
	std::vector<int> m_data;  // 차트에 표시할 데이터
	afx_msg void OnPaint();
	int CalculateSumForMonth(const CString& targetMonth);
	void DrawGraphForMonth(CDC& memDC, int xValue, const CString& targetMonth, int barWidth, int barGap, int maxBarHeight);
	void DrawGraphForMonth(CDC& memDC, int xValue, const CString& targetMonth, int barWidth, int barGap);
	void DrawGraphForMonth(CDC& memDC, int xValue, const CString& targetMonth);
//	void DrawGraphForMonth();
	int GetGraphHeight();
	void AdjustDialogSize();
	int m_maxIncome;
//	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
