#pragma once
#include "afxdialogex.h"
#include <vector>


// CSpendGraphDlg 대화 상자

class CSpendGraphDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSpendGraphDlg)

public:
	CSpendGraphDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSpendGraphDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SPEND_GRAPH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	void DrawGraphForMonth(CDC& memDC, int xValue, const CString& targetMonth, int barWidth, int barGap);
	std::vector<int> m_data;
};
