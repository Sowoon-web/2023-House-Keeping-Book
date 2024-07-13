
// FinalProjectBDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "FinalProjectB.h"
#include "FinalProjectBDlg.h"
#include "afxdialogex.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CFinalProjectBDlg 대화 상자



CFinalProjectBDlg::CFinalProjectBDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FINALPROJECTB_DIALOG, pParent)
	, m_strIncome(_T(""))
	, m_strSalary(_T(""))
	, m_strSpend(_T(""))
	, m_strSpendTarget(_T(""))
	, m_strWon(_T(""))
	, m_timeMonthCalendar(COleDateTime::GetCurrentTime())
	, m_strComboType(_T(""))
	, m_markedSalary(_T(""))
	, m_markedSpendTarget(_T(""))
	, m_nTimerID(1)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bIncomeComparison = false;
	m_bCategory = false;
	m_bSpendComparison = false;
}

void CFinalProjectBDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_TYPE, m_comboType);
	DDX_Text(pDX, IDC_EDIT_INCOME, m_strIncome);
	DDX_Text(pDX, IDC_EDIT_SALARY, m_strSalary);
	DDX_Text(pDX, IDC_EDIT_SPEND, m_strSpend);
	DDX_Text(pDX, IDC_EDIT_SPEND_TARGET, m_strSpendTarget);
	DDX_Text(pDX, IDC_EDIT_WON, m_strWon);
	DDX_Control(pDX, IDC_LIST_DETAIL, m_listDetail);
	DDX_MonthCalCtrl(pDX, IDC_MONTHCALENDAR1, m_timeMonthCalendar);
	DDX_CBString(pDX, IDC_COMBO_TYPE, m_strComboType);
	DDX_Text(pDX, IDC_EDIT_MARKED_SALARY, m_markedSalary);
	DDX_Text(pDX, IDC_EDIT_MARKED_SPEND_TARGET, m_markedSpendTarget);
}

BEGIN_MESSAGE_MAP(CFinalProjectBDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(IDC_RADIO_PLUS, &CFinalProjectBDlg::OnRadioPlus)
	ON_COMMAND(IDC_RADIO_FIX, &CFinalProjectBDlg::OnRadioFix)
	ON_COMMAND(IDC_RADIO_VARIABLE, &CFinalProjectBDlg::OnRadioVariable)
	ON_CBN_EDITUPDATE(IDC_COMBO_TYPE, &CFinalProjectBDlg::OnEditupdateComboType)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CFinalProjectBDlg::OnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &CFinalProjectBDlg::OnClickedButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_SPEND_TARGET, &CFinalProjectBDlg::OnClickedButtonSpendTarget)
	ON_BN_CLICKED(IDC_BUTTON_SALARY, &CFinalProjectBDlg::OnClickedButtonSalary)
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_INCOME_COMPARISON, &CFinalProjectBDlg::OnClickedButtonIncomeComparison)
	ON_BN_CLICKED(IDC_BUTTON_CATEGORY, &CFinalProjectBDlg::OnClickedButtonCategory)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_SPEND_COMPARISON, &CFinalProjectBDlg::OnClickedButtonSpendComparison)
END_MESSAGE_MAP()


// CFinalProjectBDlg 메시지 처리기

BOOL CFinalProjectBDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_listDetail.InsertColumn(0, _T("순번"), LVCFMT_CENTER, 60);
	m_listDetail.InsertColumn(1, _T("날짜"), LVCFMT_CENTER, 150);
	m_listDetail.InsertColumn(2, _T("종류1"), LVCFMT_CENTER, 100);
	m_listDetail.InsertColumn(3, _T("종류2"), LVCFMT_CENTER, 100);
	m_listDetail.InsertColumn(4, _T("금액"), LVCFMT_CENTER, 120);

	m_listDetail.SetExtendedStyle(m_listDetail.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	((CComboBox*)GetDlgItem(IDC_COMBO_TYPE))->SetCurSel(0);

	// 초기값 설정
	//m_strWon = _T("숫자만 입력");
	m_strSpendTarget = _T("숫자만 입력");
	m_strSalary = _T("일(숫자)만 입력");
	m_markedSpendTarget = _T("0");

	// 금액과 하루 목표 지출액, 설정된 하루 목표 지출액, 월급날 입력란에 초기값 설정
	//GetDlgItem(IDC_EDIT_WON)->SetWindowTextW(m_strWon);
	GetDlgItem(IDC_EDIT_SPEND_TARGET)->SetWindowTextW(m_strSpendTarget);
	GetDlgItem(IDC_EDIT_SALARY)->SetWindowTextW(m_strSalary);
	GetDlgItem(IDC_EDIT_MARKED_SPEND_TARGET)->SetWindowTextW(m_markedSpendTarget);

	SetTimer(m_nTimerID, 10000, nullptr);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CFinalProjectBDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CFinalProjectBDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CFinalProjectBDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CFinalProjectBDlg::OnRadioPlus()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	OnEditupdateComboType();
}


void CFinalProjectBDlg::OnRadioFix()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	OnEditupdateComboType();
}


void CFinalProjectBDlg::OnRadioVariable()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	OnEditupdateComboType();
}


void CFinalProjectBDlg::OnEditupdateComboType()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CComboBox* pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_TYPE);

	// 콤보 박스를 초기화하고 새로운 데이터를 추가합니다.
	pComboBox->ResetContent();

	// 선택한 라디오 버튼의 상태에 따라 다른 데이터를 추가합니다.
	int radioID = GetCheckedRadioButton(IDC_RADIO_PLUS, IDC_RADIO_VARIABLE);

	switch (radioID) {
	case IDC_RADIO_PLUS:
		// 수입에 해당하는 데이터 추가
		pComboBox->AddString(_T("월급"));
		pComboBox->AddString(_T("용돈"));
		pComboBox->AddString(_T("투자"));
		pComboBox->AddString(_T("기타"));
		break;
	case IDC_RADIO_FIX:
		// 고정 지출에 해당하는 데이터 추가
		pComboBox->AddString(_T("교육"));
		pComboBox->AddString(_T("통신비"));
		pComboBox->AddString(_T("회비"));
		pComboBox->AddString(_T("저축"));
		pComboBox->AddString(_T("공과금"));
		pComboBox->AddString(_T("보험"));
		pComboBox->AddString(_T("대출"));
		pComboBox->AddString(_T("카드대금"));
		pComboBox->AddString(_T("기타"));
		break;
	case IDC_RADIO_VARIABLE:
		// 변동 지출에 해당하는 데이터 추가
		pComboBox->AddString(_T("식비"));
		pComboBox->AddString(_T("교통비"));
		pComboBox->AddString(_T("문화생활"));
		pComboBox->AddString(_T("생필품"));
		pComboBox->AddString(_T("의류"));
		pComboBox->AddString(_T("미용"));
		pComboBox->AddString(_T("의료"));
		pComboBox->AddString(_T("교육"));
		pComboBox->AddString(_T("경조사"));
		pComboBox->AddString(_T("기타"));
		break;
	}
}


void CFinalProjectBDlg::OnClickedButtonAdd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nCount = m_listDetail.GetItemCount();
	CString strCount;
	CString strDate;
	CString strComboData;

	UpdateData(TRUE);

	strDate.Format(_T("%d-%d-%d"), m_timeMonthCalendar.GetYear(), m_timeMonthCalendar.GetMonth(), m_timeMonthCalendar.GetDay());
	int radioID = GetCheckedRadioButton(IDC_RADIO_PLUS, IDC_RADIO_VARIABLE);


	if (m_comboType.GetCurSel() != CB_ERR && !m_strWon.IsEmpty())
	{
		// 순번
		strCount.AppendFormat(_T("%d"), nCount + 1);
		m_listDetail.InsertItem(nCount, strCount);

		// 날짜
		m_listDetail.SetItem(nCount, 1, LVIF_TEXT, strDate, 0, 0, 0, 0); 

		// 종류1: 수입 or 고정지출 or 변동지출
		if (radioID == IDC_RADIO_PLUS)
		{
			CString strRadio;
			strRadio = "수입";
			m_listDetail.SetItem(nCount, 2, LVIF_TEXT, strRadio, 0, 0, 0, 0);
		}
		else if (radioID == IDC_RADIO_FIX)
		{
			CString strRadio;
			strRadio = "고정 지출";
			m_listDetail.SetItem(nCount, 2, LVIF_TEXT, strRadio, 0, 0, 0, 0);
		}
		else
		{
			CString strRadio;
			strRadio = "변동 지출";
			m_listDetail.SetItem(nCount, 2, LVIF_TEXT, strRadio, 0, 0, 0, 0);
		}
		
		// 종류2: 라디오버튼 선택에 따른 수입이나 지출의 종류
		m_comboType.GetLBText(m_comboType.GetCurSel(), strComboData);
		m_listDetail.SetItem(nCount, 3, LVIF_TEXT, strComboData, 0, 0, 0, 0);

		// 금액
		m_listDetail.SetItem(nCount, 4, LVIF_TEXT, m_strWon, 0, 0, 0, 0); 

		
		// 하루 지출액이 목표액을 초과했을 시 경고 메시지 출력
		SuccessFail();
		/*int intMarkedSpendTarget;
		int intWon;

		intMarkedSpendTarget = _tstoi(m_markedSpendTarget);
		intWon = _tstoi(m_strWon);

		if (intMarkedSpendTarget < intWon)
		{
			MessageBox(_T("절약 실패:\n하루 목표 지출액 초과"), _T("경고"), MB_ICONWARNING);
		}*/


		// 누적 수입 표기 plus
		int radioID = GetCheckedRadioButton(IDC_RADIO_PLUS, IDC_RADIO_VARIABLE);
		int intWon = _tstoi(m_strWon);
		int intIncome = _tstoi(m_strIncome);
		int intSpend = _tstoi(m_strSpend);

		if (radioID == IDC_RADIO_PLUS)
		{
			intWon = intIncome + intWon;
			m_strWon.Format(_T("%d"), intWon);
			m_strIncome = m_strWon;
		}

		// 누적 지출 표기 plus
		if ((radioID == IDC_RADIO_FIX || radioID == IDC_RADIO_VARIABLE) && strComboData.Compare(_T("저축")) != 0)
		{
			intWon = intSpend + intWon;
			m_strWon.Format(_T("%d"), intWon);
			m_strSpend = m_strWon;
		}

		m_strWon.Empty();

		UpdateData(FALSE);
	}
	else
	{
		MessageBox(_T("모든 항목을 채워주세요."), _T("안내"), MB_OK);
	}
}


void CFinalProjectBDlg::OnClickedButtonDel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nItem;
	POSITION pos;
	pos = m_listDetail.GetFirstSelectedItemPosition();
	if (pos != NULL)
	{
		nItem = m_listDetail.GetNextSelectedItem(pos);


		// 누적 수입 표기 minus
		CString strType = m_listDetail.GetItemText(nItem, 2);
		CString strType2 = m_listDetail.GetItemText(nItem, 3);
		
		if(strType.Compare(_T("수입")) == 0)
		{
			// 삭제된 항목의 금액 가져오기
			CString strAmount = m_listDetail.GetItemText(nItem, 4);
			int nAmount = _tstoi(strAmount);

			// 현재 누적 수입 값 가져오기
			CString strIncomeText;
			GetDlgItemText(IDC_EDIT_INCOME, strIncomeText);
			int nTotalIncome = _tstoi(strIncomeText);

			// 누적 수입에서 삭제된 항목의 금액을 뺀 값 계산
			nTotalIncome -= nAmount;

			// 누적 수입 값을 업데이트
			SetDlgItemText(IDC_EDIT_INCOME, _T("")); // Edit Control을 초기화하여 새로운 값을 설정하기 위해
			SetDlgItemInt(IDC_EDIT_INCOME, nTotalIncome);
		}

		// 누적 지출 표기 minus
		if ((strType.Compare(_T("고정 지출")) == 0 || strType.Compare(_T("변동 지출")) == 0) && strType2.Compare(_T("저축")) != 0)
		{
			// 삭제된 항목의 금액 가져오기
			CString strAmount = m_listDetail.GetItemText(nItem, 4);
			int nAmount = _tstoi(strAmount);

			// 현재 누적 값 가져오기
			CString strSpendText;
			GetDlgItemText(IDC_EDIT_SPEND, strSpendText);
			int nTotalSpend = _tstoi(strSpendText);

			// 누적에서 삭제된 항목의 금액을 뺀 값 계산
			nTotalSpend -= nAmount;

			// 누적 값을 업데이트
			SetDlgItemText(IDC_EDIT_SPEND, _T("")); // Edit Control을 초기화하여 새로운 값을 설정하기 위해
			SetDlgItemInt(IDC_EDIT_SPEND, nTotalSpend);
		}


		m_listDetail.DeleteItem(nItem);

		// 삭제된 항목 이후의 모든 항목의 순번을 재정렬
		int nItemCount = m_listDetail.GetItemCount();
		for (int i = nItem; i < nItemCount; ++i)
		{
			CString strItem;
			strItem.Format(_T("%d"), i + 1);

			m_listDetail.SetItemText(i, 0, strItem);
		}
	}
	else
	{
		MessageBox(_T("삭제할 항목을 선택해주세요."), _T("안내"), MB_OK);
	}
}


void CFinalProjectBDlg::OnClickedButtonSpendTarget()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	m_markedSpendTarget = m_strSpendTarget;

	UpdateData(FALSE);
}


void CFinalProjectBDlg::SuccessFail()
{
	// TODO: 여기에 구현 코드 추가.
	int intMarkedSpendTarget;
	int intWon;

	intMarkedSpendTarget = _tstoi(m_markedSpendTarget);
	intWon = _tstoi(m_strWon);

	int radioID = GetCheckedRadioButton(IDC_RADIO_FIX, IDC_RADIO_VARIABLE);

	switch (radioID) {
	case IDC_RADIO_FIX:
		if (intMarkedSpendTarget < intWon && m_strComboType != "저축")
		{
			MessageBox(_T("절약 실패:\n하루 목표 지출액 초과"), _T("경고"), MB_ICONWARNING);
		}
		break;
	case IDC_RADIO_VARIABLE:
		if(intMarkedSpendTarget < intWon)
		{
			MessageBox(_T("절약 실패:\n하루 목표 지출액 초과"), _T("경고"), MB_ICONWARNING);
		}
		break;
	}
}


void CFinalProjectBDlg::OnClickedButtonSalary()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	//m_markedSalary = m_strSalary;

	int intInputSalary = _ttoi(m_strSalary);
	if (intInputSalary > 31 || intInputSalary < 1)
	{
		MessageBox(_T("1부터 31 사이의 숫자만 입력 가능합니다.\n다시 입력해 주세요."), _T("안내"), MB_OK);
	}
	else
	{
		m_markedSalary = m_strSalary;
	}

	UpdateData(FALSE);
}

void CFinalProjectBDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == m_nTimerID)
	{
		CTime currentTime = CTime::GetCurrentTime();
		int intMarkedSalary = _ttoi(m_markedSalary);
		if (currentTime.GetDay() == intMarkedSalary)
		{
			MessageBox(_T("오늘은 월급날입니다 :D"), _T("알림"), MB_OK);

			KillTimer(m_nTimerID);
		}
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CFinalProjectBDlg::OnClickedButtonIncomeComparison()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (!m_bIncomeComparison)
	{
		m_dlgIncomeGraph.Create(IDD_DIALOG_INCOME_GRAPH, this);

		CRect rectMain, rectIncomeGraph;
		GetWindowRect(&rectMain);

		m_dlgIncomeGraph.GetWindowRect(&rectIncomeGraph);
		m_dlgIncomeGraph.MoveWindow(rectMain.right, rectMain.top, rectIncomeGraph.Width(),
			rectIncomeGraph.Height());
		m_dlgIncomeGraph.ShowWindow(SW_SHOW);
		m_bIncomeComparison = TRUE;
	}
	else
	{
		m_dlgIncomeGraph.ShowWindow(SW_HIDE);
		m_dlgIncomeGraph.DestroyWindow();
		m_bIncomeComparison = FALSE;
	}
	
	/* 그래프 다이얼로그의 그래프 y축 높이에 따라 윈도우 크기 변경
	if (!m_bIncomeComparison)
	{
		m_dlgIncomeGraph.Create(IDD_DIALOG_INCOME_GRAPH, this);

		// 그래프의 y축 높이에 따라 다이얼로그 크기를 조절
		m_dlgIncomeGraph.AdjustDialogSize();

		m_dlgIncomeGraph.ShowWindow(SW_SHOW);
		m_bIncomeComparison = TRUE;
	}
	else
	{
		m_dlgIncomeGraph.ShowWindow(SW_HIDE);
		m_dlgIncomeGraph.DestroyWindow();
		m_bIncomeComparison = FALSE;
	}
	*/
}


void CFinalProjectBDlg::OnClickedButtonCategory()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (!m_bCategory)
	{
		m_dlgCategory.Create(IDD_DIALOG_CATEGORY, this);

		CRect rectMain, rectCategory;
		GetWindowRect(&rectMain);

		m_dlgCategory.GetWindowRect(&rectCategory);
		m_dlgCategory.MoveWindow(rectMain.right, rectMain.top, rectCategory.Width(),
			rectCategory.Height());
		m_dlgCategory.ShowWindow(SW_SHOW);
		m_bCategory = TRUE;
	}
	else
	{
		m_dlgCategory.ShowWindow(SW_HIDE);
		m_dlgCategory.DestroyWindow();
		m_bCategory = FALSE;
	}
}


HBRUSH CFinalProjectBDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.

	if (pWnd->GetDlgCtrlID() == IDC_STATIC_CAUTION || pWnd->GetDlgCtrlID() == IDC_STATIC_CAUTION2 
		|| pWnd->GetDlgCtrlID() == IDC_STATIC_NUM_CAUTION)
	{
		pDC->SetTextColor(RGB(255, 0, 0));
	}

	return hbr;
}

void CFinalProjectBDlg::OnClickedButtonSpendComparison()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (!m_bSpendComparison)
	{
		m_dlgSpendGraph.Create(IDD_DIALOG_SPEND_GRAPH, this);

		CRect rectMain, rectSpendGraph, rectIncomeGraph;
		GetWindowRect(&rectMain);

		m_dlgSpendGraph.GetWindowRect(&rectSpendGraph);
		m_dlgSpendGraph.GetWindowRect(&rectIncomeGraph);
		m_dlgSpendGraph.MoveWindow(rectMain.right, rectIncomeGraph.bottom, rectSpendGraph.Width(),
			rectSpendGraph.Height());
		m_dlgSpendGraph.ShowWindow(SW_SHOW);
		m_bSpendComparison = TRUE;
	}
	else
	{
		m_dlgSpendGraph.ShowWindow(SW_HIDE);
		m_dlgSpendGraph.DestroyWindow();
		m_bSpendComparison = FALSE;
	}
}
