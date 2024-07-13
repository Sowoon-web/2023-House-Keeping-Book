// CSpendGraphDlg.cpp: 구현 파일
//

#include "pch.h"
#include "FinalProjectB.h"
#include "afxdialogex.h"
#include "CSpendGraphDlg.h"
#include "FinalProjectBDlg.h"


// CSpendGraphDlg 대화 상자

IMPLEMENT_DYNAMIC(CSpendGraphDlg, CDialogEx)

CSpendGraphDlg::CSpendGraphDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SPEND_GRAPH, pParent)
{
	// 초기 데이터 설정
	m_data = { 30, 50, 80, 20, 40 };
}

CSpendGraphDlg::~CSpendGraphDlg()
{
}

void CSpendGraphDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSpendGraphDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CSpendGraphDlg 메시지 처리기


void CSpendGraphDlg::OnPaint()
{
    CPaintDC dc(this);
    CDC memDC;
    memDC.CreateCompatibleDC(&dc);

    CRect clientRect;
    GetClientRect(&clientRect);

    CBitmap bmp;
    bmp.CreateCompatibleBitmap(&dc, clientRect.Width(), clientRect.Height());
    memDC.SelectObject(&bmp);

    memDC.FillSolidRect(clientRect, RGB(0, 0, 0));

    int barCount = 12;  // 막대의 개수
    int barWidth = (clientRect.Width() - (barCount - 1) * 5) / barCount;  // 각 막대의 폭 및 간격
    int barGap = 5;  // 막대 간격

    for (int i = 0; i < barCount; i++)
    {
        CString strI;
        strI.Format(_T("%d"), i + 1);
        CString month = _T("2023-") + strI + _T("-");
        DrawGraphForMonth(memDC, i, month, barWidth, barGap);
    }

    dc.BitBlt(0, 0, clientRect.Width(), clientRect.Height(), &memDC, 0, 0, SRCCOPY);
}

void CSpendGraphDlg::DrawGraphForMonth(CDC& memDC, int xValue, const CString& targetMonth, int barWidth, int barGap)
{
    CRect clientRect;
    GetClientRect(&clientRect);

    int sum = 0;
    int itemCount = ((CFinalProjectBDlg*)GetParent())->m_listDetail.GetItemCount();
    for (int i = 0; i < itemCount; i++)
    {
        CString strTypeIncome = ((CFinalProjectBDlg*)GetParent())->m_listDetail.GetItemText(i, 2);
        CString strDate = ((CFinalProjectBDlg*)GetParent())->m_listDetail.GetItemText(i, 1);
        CString strSaving = ((CFinalProjectBDlg*)GetParent())->m_listDetail.GetItemText(i, 3);
        if ((strTypeIncome == "고정 지출" || strTypeIncome == "변동 지출") && strDate.Find(targetMonth) != -1
            && strSaving != "저축")
        {
            CString strMoney = ((CFinalProjectBDlg*)GetParent())->m_listDetail.GetItemText(i, 4);
            int intMoney = _ttoi(strMoney);
            sum += intMoney;
        }
    }

    CDC* pDC = &memDC;

    // 막대의 높이 계산 및 조정
    int barHeight = sum / 100000;

    // 막대의 위치 계산 수정
    CRect barRect(xValue * (barWidth + barGap), clientRect.bottom - barHeight, (xValue + 1) * barWidth + xValue * barGap, clientRect.bottom);
    pDC->FillSolidRect(barRect, RGB(0, 0, 255));
}