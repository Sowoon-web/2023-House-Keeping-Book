#pragma once
#include "afxdialogex.h"


// CCategoryDlg 대화 상자

class CCategoryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCategoryDlg)

public:
	CCategoryDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CCategoryDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CATEGORY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_treeControl;
	HTREEITEM m_hRoot;
	virtual BOOL OnInitDialog();
	CTreeCtrl m_spendTreeControl;
	HTREEITEM m_hSpendRoot;
};
