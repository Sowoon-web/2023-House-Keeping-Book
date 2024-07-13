// CCategoryDlg.cpp: 구현 파일
//

#include "pch.h"
#include "FinalProjectB.h"
#include "afxdialogex.h"
#include "CCategoryDlg.h"
#include "FinalProjectBDlg.h"


// CCategoryDlg 대화 상자

IMPLEMENT_DYNAMIC(CCategoryDlg, CDialogEx)

CCategoryDlg::CCategoryDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_CATEGORY, pParent)
{

}

CCategoryDlg::~CCategoryDlg()
{
}

void CCategoryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE_CONTROL, m_treeControl);
	DDX_Control(pDX, IDC_SPEND_TREE_CONTROL, m_spendTreeControl);
}


BEGIN_MESSAGE_MAP(CCategoryDlg, CDialogEx)
//	ON_COMMAND(IDC_BUTTON_CATEGORY, &CCategoryDlg::OnButtonCategory)
//ON_NOTIFY(NM_CUSTOMDRAW, IDC_SPEND_TREE_CONTROL, &CCategoryDlg::OnCustomdrawSpendTreeControl)
END_MESSAGE_MAP()


// CCategoryDlg 메시지 처리기


BOOL CCategoryDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	HTREEITEM incomeRoot, janIncome, febIncome, marIncome, aprIncome, mayIncome, junIncome, julIncome, augIncome,
		sepIncome, octIncome, novIncome, decIncome;
	HTREEITEM spendRoot, fixSpend, variableSpend;
	HTREEITEM janFix, febFix, marFix, aprFix, mayFix, junFix, julFix, augFix, sepFix, octFix, novFix, decFix;
	HTREEITEM janVar, febVar, marVar, aprVar, mayVar, junVar, julVar, augVar, sepVar, octVar, novVar, decVar;

	// 수입 카테고리
	int nCount = ((CFinalProjectBDlg*)GetParent())->m_listDetail.GetItemCount();
	int sum = 0; int janSum = 0; int febSum = 0; int marSum = 0; int aprSum = 0; int maySum = 0; int junSum = 0;
	int julSum = 0; int augSum = 0; int sepSum = 0; int octSum = 0; int novSum = 0; int decSum = 0;

	int totalSpendSum = 0; int fixSpendSum = 0; int variableSpendSum = 0;
	int janFixSum = 0; int febFixSum = 0; int marFixSum = 0; int aprFixSum = 0; int mayFixSum = 0; int junFixSum = 0; int julFixSum = 0;
	int augFixSum = 0; int sepFixSum = 0; int octFixSum = 0; int novFixSum = 0; int decFixSum = 0;

	int janVarSum = 0; int febVarSum = 0; int marVarSum = 0; int aprVarSum = 0; int mayVarSum = 0; int junVarSum = 0; int julVarSum = 0;
	int augVarSum = 0; int sepVarSum = 0; int octVarSum = 0; int novVarSum = 0; int decVarSum = 0;

	CString strJanSum, strFebSum, strMarSum, strAprSum, strMaySum, strJunSum, strJulSum, strAugSum, strSepSum, strOctSum,
		strNovSum, strDecSum;

	CString strFixSpendSum, strVariableSpendSum;

	CString strJanFixSpendSum, strFebFixSpendSum, strMarFixSpendSum, strAprFixSpendSum, strMayFixSpendSum, strJunFixSpendSum,
		strJulFixSpendSum, strAugFixSpendSum, strSepFixSpendSum, strOctFixSpendSum, strNovFixSpendSum, strDecFixSpendSum;

	CString strJanVarSpendSum, strFebVarSpendSum, strMarVarSpendSum, strAprVarSpendSum, strMayVarSpendSum, strJunVarSpendSum,
		strJulVarSpendSum, strAugVarSpendSum, strSepVarSpendSum, strOctVarSpendSum, strNovVarSpendSum, strDecVarSpendSum;

	int etcSum = 0; int pocketMSum = 0; int salarySum = 0; int fundSum = 0;
	int etcFebSum = 0; int pocketMFebSum = 0; int salaryFebSum = 0; int fundFebSum = 0;
	int etcMarSum = 0; int pocketMMarSum = 0; int salaryMarSum = 0; int fundMarSum = 0;
	int etcAprSum = 0; int pocketMAprSum = 0; int salaryAprSum = 0; int fundAprSum = 0;
	int etcMaySum = 0; int pocketMMaySum = 0; int salaryMaySum = 0; int fundMaySum = 0;
	int etcJunSum = 0; int pocketMJunSum = 0; int salaryJunSum = 0; int fundJunSum = 0;
	int etcJulSum = 0; int pocketMJulSum = 0; int salaryJulSum = 0; int fundJulSum = 0;
	int etcAugSum = 0; int pocketMAugSum = 0; int salaryAugSum = 0; int fundAugSum = 0;
	int etcSepSum = 0; int pocketMSepSum = 0; int salarySepSum = 0; int fundSepSum = 0;
	int etcOctSum = 0; int pocketMOctSum = 0; int salaryOctSum = 0; int fundOctSum = 0;
	int etcNovSum = 0; int pocketMNovSum = 0; int salaryNovSum = 0; int fundNovSum = 0;
	int etcDecSum = 0; int pocketMDecSum = 0; int salaryDecSum = 0; int fundDecSum = 0;
	
	int utilitySum = 0; int studySum = 0; int etcFixSum = 0; int loanSum = 0; int insuSum = 0;
	int savingSum = 0; int cardSum = 0; int postageSum = 0; int membershipSum = 0;

	int utilityFebSum = 0; int studyFebSum = 0; int etcFebFixSum = 0; int loanFebSum = 0; int insuFebSum = 0;
	int savingFebSum = 0; int cardFebSum = 0; int postageFebSum = 0; int membershipFebSum = 0;

	int utilityMarSum = 0; int studyMarSum = 0; int etcMarFixSum = 0; int loanMarSum = 0; int insuMarSum = 0;
	int savingMarSum = 0; int cardMarSum = 0; int postageMarSum = 0; int membershipMarSum = 0;

	int utilityAprSum = 0; int studyAprSum = 0; int etcAprFixSum = 0; int loanAprSum = 0; int insuAprSum = 0;
	int savingAprSum = 0; int cardAprSum = 0; int postageAprSum = 0; int membershipAprSum = 0;

	int utilityMaySum = 0; int studyMaySum = 0; int etcMayFixSum = 0; int loanMaySum = 0; int insuMaySum = 0;
	int savingMaySum = 0; int cardMaySum = 0; int postageMaySum = 0; int membershipMaySum = 0;

	int utilityJunSum = 0; int studyJunSum = 0; int etcJunFixSum = 0; int loanJunSum = 0; int insuJunSum = 0;
	int savingJunSum = 0; int cardJunSum = 0; int postageJunSum = 0; int membershipJunSum = 0;

	int utilityJulSum = 0; int studyJulSum = 0; int etcJulFixSum = 0; int loanJulSum = 0; int insuJulSum = 0;
	int savingJulSum = 0; int cardJulSum = 0; int postageJulSum = 0; int membershipJulSum = 0;

	int utilityAugSum = 0; int studyAugSum = 0; int etcAugFixSum = 0; int loanAugSum = 0; int insuAugSum = 0;
	int savingAugSum = 0; int cardAugSum = 0; int postageAugSum = 0; int membershipAugSum = 0;

	int utilitySepSum = 0; int studySepSum = 0; int etcSepFixSum = 0; int loanSepSum = 0; int insuSepSum = 0;
	int savingSepSum = 0; int cardSepSum = 0; int postageSepSum = 0; int membershipSepSum = 0;

	int utilityOctSum = 0; int studyOctSum = 0; int etcOctFixSum = 0; int loanOctSum = 0; int insuOctSum = 0;
	int savingOctSum = 0; int cardOctSum = 0; int postageOctSum = 0; int membershipOctSum = 0;

	int utilityNovSum = 0; int studyNovSum = 0; int etcNovFixSum = 0; int loanNovSum = 0; int insuNovSum = 0;
	int savingNovSum = 0; int cardNovSum = 0; int postageNovSum = 0; int membershipNovSum = 0;

	int utilityDecSum = 0; int studyDecSum = 0; int etcDecFixSum = 0; int loanDecSum = 0; int insuDecSum = 0;
	int savingDecSum = 0; int cardDecSum = 0; int postageDecSum = 0; int membershipDecSum = 0;

	int familySum = 0; int studyVarSum = 0; int transSum = 0; int etcVarSum = 0; int enjoySum = 0;
	int beautySum = 0; int necessariesSum = 0; int foodSum = 0; int medicalSum = 0; int clothingSum = 0;

	int familyFebSum = 0; int studyFebVarSum = 0; int transFebSum = 0; int etcFebVarSum = 0; int enjoyFebSum = 0;
	int beautyFebSum = 0; int necessariesFebSum = 0; int foodFebSum = 0; int medicalFebSum = 0; int clothingFebSum = 0;

	int familyMarSum = 0; int studyMarVarSum = 0; int transMarSum = 0; int etcMarVarSum = 0; int enjoyMarSum = 0;
	int beautyMarSum = 0; int necessariesMarSum = 0; int foodMarSum = 0; int medicalMarSum = 0; int clothingMarSum = 0;

	int familyAprSum = 0; int studyAprVarSum = 0; int transAprSum = 0; int etcAprVarSum = 0; int enjoyAprSum = 0;
	int beautyAprSum = 0; int necessariesAprSum = 0; int foodAprSum = 0; int medicalAprSum = 0; int clothingAprSum = 0;

	int familyMaySum = 0; int studyMayVarSum = 0; int transMaySum = 0; int etcMayVarSum = 0; int enjoyMaySum = 0;
	int beautyMaySum = 0; int necessariesMaySum = 0; int foodMaySum = 0; int medicalMaySum = 0; int clothingMaySum = 0;

	int familyJunSum = 0; int studyJunVarSum = 0; int transJunSum = 0; int etcJunVarSum = 0; int enjoyJunSum = 0;
	int beautyJunSum = 0; int necessariesJunSum = 0; int foodJunSum = 0; int medicalJunSum = 0; int clothingJunSum = 0;

	int familyJulSum = 0; int studyJulVarSum = 0; int transJulSum = 0; int etcJulVarSum = 0; int enjoyJulSum = 0;
	int beautyJulSum = 0; int necessariesJulSum = 0; int foodJulSum = 0; int medicalJulSum = 0; int clothingJulSum = 0;

	int familyAugSum = 0; int studyAugVarSum = 0; int transAugSum = 0; int etcAugVarSum = 0; int enjoyAugSum = 0;
	int beautyAugSum = 0; int necessariesAugSum = 0; int foodAugSum = 0; int medicalAugSum = 0; int clothingAugSum = 0;

	int familySepSum = 0; int studySepVarSum = 0; int transSepSum = 0; int etcSepVarSum = 0; int enjoySepSum = 0;
	int beautySepSum = 0; int necessariesSepSum = 0; int foodSepSum = 0; int medicalSepSum = 0; int clothingSepSum = 0;

	int familyOctSum = 0; int studyOctVarSum = 0; int transOctSum = 0; int etcOctVarSum = 0; int enjoyOctSum = 0;
	int beautyOctSum = 0; int necessariesOctSum = 0; int foodOctSum = 0; int medicalOctSum = 0; int clothingOctSum = 0;

	int familyNovSum = 0; int studyNovVarSum = 0; int transNovSum = 0; int etcNovVarSum = 0; int enjoyNovSum = 0;
	int beautyNovSum = 0; int necessariesNovSum = 0; int foodNovSum = 0; int medicalNovSum = 0; int clothingNovSum = 0;

	int familyDecSum = 0; int studyDecVarSum = 0; int transDecSum = 0; int etcDecVarSum = 0; int enjoyDecSum = 0;
	int beautyDecSum = 0; int necessariesDecSum = 0; int foodDecSum = 0; int medicalDecSum = 0; int clothingDecSum = 0;

	CString strEtcSum, strPocketMSum, strSalarySum, strFundSum,
		strFebEtcSum, strFebPocketMSum, strFebSalarySum, strFebFundSum,
		strMarEtcSum, strMarPocketMSum, strMarSalarySum, strMarFundSum,
		strAprEtcSum, strAprPocketMSum, strAprSalarySum, strAprFundSum,
		strMayEtcSum, strMayPocketMSum, strMaySalarySum, strMayFundSum,
		strJunEtcSum, strJunPocketMSum, strJunSalarySum, strJunFundSum,
		strJulEtcSum, strJulPocketMSum, strJulSalarySum, strJulFundSum,
		strAugEtcSum, strAugPocketMSum, strAugSalarySum, strAugFundSum,
		strSepEtcSum, strSepPocketMSum, strSepSalarySum, strSepFundSum,
		strOctEtcSum, strOctPocketMSum, strOctSalarySum, strOctFundSum,
		strNovEtcSum, strNovPocketMSum, strNovSalarySum, strNovFundSum,
		strDecEtcSum, strDecPocketMSum, strDecSalarySum, strDecFundSum;

	CString strUtilitySum, strStudySum, strEtcFixSum, strLoanSum, strInsuSum, strSavingSum,
		strCardSum, strPostageSum, strMembershipSum,
		strFebUtilitySum, strFebStudySum, strFebEtcFixSum, strFebLoanSum, strFebInsuSum, strFebSavingSum,
		strFebCardSum, strFebPostageSum, strFebMembershipSum,
		strMarUtilitySum, strMarStudySum, strMarEtcFixSum, strMarLoanSum, strMarInsuSum, strMarSavingSum,
		strMarCardSum, strMarPostageSum, strMarMembershipSum,
		strAprUtilitySum, strAprStudySum, strAprEtcFixSum, strAprLoanSum, strAprInsuSum, strAprSavingSum,
		strAprCardSum, strAprPostageSum, strAprMembershipSum,
		strMayUtilitySum, strMayStudySum, strMayEtcFixSum, strMayLoanSum, strMayInsuSum, strMaySavingSum,
		strMayCardSum, strMayPostageSum, strMayMembershipSum,
		strJunUtilitySum, strJunStudySum, strJunEtcFixSum, strJunLoanSum, strJunInsuSum, strJunSavingSum,
		strJunCardSum, strJunPostageSum, strJunMembershipSum,
		strJulUtilitySum, strJulStudySum, strJulEtcFixSum, strJulLoanSum, strJulInsuSum, strJulSavingSum,
		strJulCardSum, strJulPostageSum, strJulMembershipSum,
		strAugUtilitySum, strAugStudySum, strAugEtcFixSum, strAugLoanSum, strAugInsuSum, strAugSavingSum,
		strAugCardSum, strAugPostageSum, strAugMembershipSum,
		strSepUtilitySum, strSepStudySum, strSepEtcFixSum, strSepLoanSum, strSepInsuSum, strSepSavingSum,
		strSepCardSum, strSepPostageSum, strSepMembershipSum,
		strOctUtilitySum, strOctStudySum, strOctEtcFixSum, strOctLoanSum, strOctInsuSum, strOctSavingSum,
		strOctCardSum, strOctPostageSum, strOctMembershipSum,
		strNovUtilitySum, strNovStudySum, strNovEtcFixSum, strNovLoanSum, strNovInsuSum, strNovSavingSum,
		strNovCardSum, strNovPostageSum, strNovMembershipSum,
		strDecUtilitySum, strDecStudySum, strDecEtcFixSum, strDecLoanSum, strDecInsuSum, strDecSavingSum,
		strDecCardSum, strDecPostageSum, strDecMembershipSum;
		
	CString strFamilySum, strStudyVarSum, strTransSum, strEtcVarSum, strEnjoySum, strBeautySum,
		strNecessariesSum, strFoodSum, strMedicalSum, strClothingSum,
		strFebFamilySum, strFebStudyVarSum, strFebTransSum, strFebEtcVarSum, strFebEnjoySum, strFebBeautySum,
		strFebNecessariesSum, strFebFoodSum, strFebMedicalSum, strFebClothingSum,
		strMarFamilySum, strMarStudyVarSum, strMarTransSum, strMarEtcVarSum, strMarEnjoySum, strMarBeautySum,
		strMarNecessariesSum, strMarFoodSum, strMarMedicalSum, strMarClothingSum,
		strAprFamilySum, strAprStudyVarSum, strAprTransSum, strAprEtcVarSum, strAprEnjoySum, strAprBeautySum,
		strAprNecessariesSum, strAprFoodSum, strAprMedicalSum, strAprClothingSum,
		strMayFamilySum, strMayStudyVarSum, strMayTransSum, strMayEtcVarSum, strMayEnjoySum, strMayBeautySum,
		strMayNecessariesSum, strMayFoodSum, strMayMedicalSum, strMayClothingSum,
		strJunFamilySum, strJunStudyVarSum, strJunTransSum, strJunEtcVarSum, strJunEnjoySum, strJunBeautySum,
		strJunNecessariesSum, strJunFoodSum, strJunMedicalSum, strJunClothingSum,
		strJulFamilySum, strJulStudyVarSum, strJulTransSum, strJulEtcVarSum, strJulEnjoySum, strJulBeautySum,
		strJulNecessariesSum, strJulFoodSum, strJulMedicalSum, strJulClothingSum,
		strAugFamilySum, strAugStudyVarSum, strAugTransSum, strAugEtcVarSum, strAugEnjoySum, strAugBeautySum,
		strAugNecessariesSum, strAugFoodSum, strAugMedicalSum, strAugClothingSum,
		strSepFamilySum, strSepStudyVarSum, strSepTransSum, strSepEtcVarSum, strSepEnjoySum, strSepBeautySum,
		strSepNecessariesSum, strSepFoodSum, strSepMedicalSum, strSepClothingSum,
		strOctFamilySum, strOctStudyVarSum, strOctTransSum, strOctEtcVarSum, strOctEnjoySum, strOctBeautySum,
		strOctNecessariesSum, strOctFoodSum, strOctMedicalSum, strOctClothingSum,
		strNovFamilySum, strNovStudyVarSum, strNovTransSum, strNovEtcVarSum, strNovEnjoySum, strNovBeautySum,
		strNovNecessariesSum, strNovFoodSum, strNovMedicalSum, strNovClothingSum,
		strDecFamilySum, strDecStudyVarSum, strDecTransSum, strDecEtcVarSum, strDecEnjoySum, strDecBeautySum,
		strDecNecessariesSum, strDecFoodSum, strDecMedicalSum, strDecClothingSum;

	for (int i = 0; i < nCount; i++)
	{
		CString strMoney = ((CFinalProjectBDlg*)GetParent())->m_listDetail.GetItemText(i, 4);
		CString txtRadioType = ((CFinalProjectBDlg*)GetParent())->m_listDetail.GetItemText(i, 2);
		CString listDate = ((CFinalProjectBDlg*)GetParent())->m_listDetail.GetItemText(i, 1);
		CString listType = ((CFinalProjectBDlg*)GetParent())->m_listDetail.GetItemText(i, 3);

		if (txtRadioType == "수입") 
		{
			int intMoney = _ttoi(strMoney);
			sum += intMoney;

			if (listDate.Find(_T("2023-1-")) != -1) 
			{
				int intJanMoney = _ttoi(strMoney);
				janSum += intJanMoney;

				if (listType == "기타")
				{
					int intEtcMoney = _ttoi(strMoney);
					etcSum += intEtcMoney;
				}
				
				if (listType == "용돈")
				{
					int intPocketMMoney = _ttoi(strMoney);
					pocketMSum += intPocketMMoney;
				}

				if (listType == "월급")
				{
					int intSalaryMoney = _ttoi(strMoney);
					salarySum += intSalaryMoney;
				}

				if (listType == "투자")
				{
					int intFundMoney = _ttoi(strMoney);
					fundSum += intFundMoney;
				}
			}

			if (listDate.Find(_T("2023-2-")) != -1)
			{
				int intFebMoney = _ttoi(strMoney);
				febSum += intFebMoney;

				if (listType == "기타")
				{
					int intFebEtcMoney = _ttoi(strMoney);
					etcFebSum += intFebEtcMoney;
				}

				if (listType == "용돈")
				{
					int intFebPocketMMoney = _ttoi(strMoney);
					pocketMFebSum += intFebPocketMMoney;
				}

				if (listType == "월급")
				{
					int intFebSalaryMoney = _ttoi(strMoney);
					salaryFebSum += intFebSalaryMoney;
				}

				if (listType == "투자")
				{
					int intFebFundMoney = _ttoi(strMoney);
					fundFebSum += intFebFundMoney;
				}
			}

			if (listDate.Find(_T("2023-3-")) != -1)
			{
				int intMarMoney = _ttoi(strMoney);
				marSum += intMarMoney;

				if (listType == "기타")
				{
					int intMarEtcMoney = _ttoi(strMoney);
					etcMarSum += intMarEtcMoney;
				}

				if (listType == "용돈")
				{
					int intMarPocketMMoney = _ttoi(strMoney);
					pocketMMarSum += intMarPocketMMoney;
				}

				if (listType == "월급")
				{
					int intMarSalaryMoney = _ttoi(strMoney);
					salaryMarSum += intMarSalaryMoney;
				}

				if (listType == "투자")
				{
					int intMarFundMoney = _ttoi(strMoney);
					fundMarSum += intMarFundMoney;
				}
			}

			if (listDate.Find(_T("2023-4-")) != -1)
			{
				int intAprMoney = _ttoi(strMoney);
				aprSum += intAprMoney;

				if (listType == "기타")
				{
					int intAprEtcMoney = _ttoi(strMoney);
					etcAprSum += intAprEtcMoney;
				}

				if (listType == "용돈")
				{
					int intAprPocketMMoney = _ttoi(strMoney);
					pocketMAprSum += intAprPocketMMoney;
				}

				if (listType == "월급")
				{
					int intAprSalaryMoney = _ttoi(strMoney);
					salaryAprSum += intAprSalaryMoney;
				}

				if (listType == "투자")
				{
					int intAprFundMoney = _ttoi(strMoney);
					fundAprSum += intAprFundMoney;
				}
			}

			if (listDate.Find(_T("2023-5-")) != -1)
			{
				int intMayMoney = _ttoi(strMoney);
				maySum += intMayMoney;

				if (listType == "기타")
				{
					int intMayEtcMoney = _ttoi(strMoney);
					etcMaySum += intMayEtcMoney;
				}

				if (listType == "용돈")
				{
					int intMayPocketMMoney = _ttoi(strMoney);
					pocketMMaySum += intMayPocketMMoney;
				}

				if (listType == "월급")
				{
					int intMaySalaryMoney = _ttoi(strMoney);
					salaryMaySum += intMaySalaryMoney;
				}

				if (listType == "투자")
				{
					int intMayFundMoney = _ttoi(strMoney);
					fundMaySum += intMayFundMoney;
				}
			}

			if (listDate.Find(_T("2023-6-")) != -1)
			{
				int intJunMoney = _ttoi(strMoney);
				junSum += intJunMoney;

				if (listType == "기타")
				{
					int intJunEtcMoney = _ttoi(strMoney);
					etcJunSum += intJunEtcMoney;
				}

				if (listType == "용돈")
				{
					int intJunPocketMMoney = _ttoi(strMoney);
					pocketMJunSum += intJunPocketMMoney;
				}

				if (listType == "월급")
				{
					int intJunSalaryMoney = _ttoi(strMoney);
					salaryJunSum += intJunSalaryMoney;
				}

				if (listType == "투자")
				{
					int intJunFundMoney = _ttoi(strMoney);
					fundJunSum += intJunFundMoney;
				}
			}

			if (listDate.Find(_T("2023-7-")) != -1)
			{
				int intJulMoney = _ttoi(strMoney);
				julSum += intJulMoney;

				if (listType == "기타")
				{
					int intJulEtcMoney = _ttoi(strMoney);
					etcJulSum += intJulEtcMoney;
				}

				if (listType == "용돈")
				{
					int intJulPocketMMoney = _ttoi(strMoney);
					pocketMJulSum += intJulPocketMMoney;
				}

				if (listType == "월급")
				{
					int intJulSalaryMoney = _ttoi(strMoney);
					salaryJulSum += intJulSalaryMoney;
				}

				if (listType == "투자")
				{
					int intJulFundMoney = _ttoi(strMoney);
					fundJulSum += intJulFundMoney;
				}
			}

			if (listDate.Find(_T("2023-8-")) != -1)
			{
				int intAugMoney = _ttoi(strMoney);
				augSum += intAugMoney;

				if (listType == "기타")
				{
					int intAugEtcMoney = _ttoi(strMoney);
					etcAugSum += intAugEtcMoney;
				}

				if (listType == "용돈")
				{
					int intAugPocketMMoney = _ttoi(strMoney);
					pocketMAugSum += intAugPocketMMoney;
				}

				if (listType == "월급")
				{
					int intAugSalaryMoney = _ttoi(strMoney);
					salaryAugSum += intAugSalaryMoney;
				}

				if (listType == "투자")
				{
					int intAugFundMoney = _ttoi(strMoney);
					fundAugSum += intAugFundMoney;
				}
			}

			if (listDate.Find(_T("2023-9-")) != -1)
			{
				int intSepMoney = _ttoi(strMoney);
				sepSum += intSepMoney;

				if (listType == "기타")
				{
					int intSepEtcMoney = _ttoi(strMoney);
					etcSepSum += intSepEtcMoney;
				}

				if (listType == "용돈")
				{
					int intSepPocketMMoney = _ttoi(strMoney);
					pocketMSepSum += intSepPocketMMoney;
				}

				if (listType == "월급")
				{
					int intSepSalaryMoney = _ttoi(strMoney);
					salarySepSum += intSepSalaryMoney;
				}

				if (listType == "투자")
				{
					int intSepFundMoney = _ttoi(strMoney);
					fundSepSum += intSepFundMoney;
				}
			}

			if (listDate.Find(_T("2023-10-")) != -1)
			{
				int intOctMoney = _ttoi(strMoney);
				octSum += intOctMoney;

				if (listType == "기타")
				{
					int intOctEtcMoney = _ttoi(strMoney);
					etcOctSum += intOctEtcMoney;
				}

				if (listType == "용돈")
				{
					int intOctPocketMMoney = _ttoi(strMoney);
					pocketMOctSum += intOctPocketMMoney;
				}

				if (listType == "월급")
				{
					int intOctSalaryMoney = _ttoi(strMoney);
					salaryOctSum += intOctSalaryMoney;
				}

				if (listType == "투자")
				{
					int intOctFundMoney = _ttoi(strMoney);
					fundOctSum += intOctFundMoney;
				}
			}

			if (listDate.Find(_T("2023-11-")) != -1)
			{
				int intNovMoney = _ttoi(strMoney);
				novSum += intNovMoney;

				if (listType == "기타")
				{
					int intNovEtcMoney = _ttoi(strMoney);
					etcNovSum += intNovEtcMoney;
				}

				if (listType == "용돈")
				{
					int intNovPocketMMoney = _ttoi(strMoney);
					pocketMNovSum += intNovPocketMMoney;
				}

				if (listType == "월급")
				{
					int intNovSalaryMoney = _ttoi(strMoney);
					salaryNovSum += intNovSalaryMoney;
				}

				if (listType == "투자")
				{
					int intNovFundMoney = _ttoi(strMoney);
					fundNovSum += intNovFundMoney;
				}
			}

			if (listDate.Find(_T("2023-12-")) != -1)
			{
				int intDecMoney = _ttoi(strMoney);
				decSum += intDecMoney;

				if (listType == "기타")
				{
					int intDecEtcMoney = _ttoi(strMoney);
					etcDecSum += intDecEtcMoney;
				}

				if (listType == "용돈")
				{
					int intDecPocketMMoney = _ttoi(strMoney);
					pocketMDecSum += intDecPocketMMoney;
				}

				if (listType == "월급")
				{
					int intDecSalaryMoney = _ttoi(strMoney);
					salaryDecSum += intDecSalaryMoney;
				}

				if (listType == "투자")
				{
					int intDecFundMoney = _ttoi(strMoney);
					fundDecSum += intDecFundMoney;
				}
			}
		}
		if (txtRadioType == "고정 지출" || txtRadioType == "변동 지출")
		{
			if (listType != "저축")
			{
				int intSpendTotalMoney = _ttoi(strMoney);
				totalSpendSum += intSpendTotalMoney;
			}

			if (txtRadioType == "고정 지출")
			{
				if (listType != "저축")
				{
					int intFixSpendMoney = _ttoi(strMoney);
					fixSpendSum += intFixSpendMoney;
				}
				
				if (listDate.Find(_T("2023-1-")) != -1)
				{
					if (listType != "저축")
					{
						int intJanFixMoney = _ttoi(strMoney);
						janFixSum += intJanFixMoney;
					}
					if (listType == "공과금")
					{
						int intUtilityMoney = _ttoi(strMoney);
						utilitySum += intUtilityMoney;
					}

					if (listType == "교육")
					{
						int intStudyMoney = _ttoi(strMoney);
						studySum += intStudyMoney;
					}

					if (listType == "기타")
					{
						int intEtcFixMoney = _ttoi(strMoney);
						etcFixSum += intEtcFixMoney;
					}

					if (listType == "대출")
					{
						int intLoanMoney = _ttoi(strMoney);
						loanSum += intLoanMoney;
					}
					
					if (listType == "보험")
					{
						int intInsuMoney = _ttoi(strMoney);
						insuSum += intInsuMoney;
					}

					if (listType == "저축")
					{
						int intSavingMoney = _ttoi(strMoney);
						savingSum += intSavingMoney;
					}

					if (listType == "카드대금")
					{
						int intCardMoney = _ttoi(strMoney);
						cardSum += intCardMoney;
					}

					if (listType == "통신비")
					{
						int intPostageMoney = _ttoi(strMoney);
						postageSum += intPostageMoney;
					}

					if (listType == "회비")
					{
						int intFamilyMoney = _ttoi(strMoney);
						familySum += intFamilyMoney;
					}
				}

				// 2월
				if (listDate.Find(_T("2023-2-")) != -1)
				{
					if (listType != "저축")
					{
						int intFebFixMoney = _ttoi(strMoney);
						febFixSum += intFebFixMoney;
					}
					if (listType == "공과금")
					{
						int intFebUtilityMoney = _ttoi(strMoney);
						utilityFebSum += intFebUtilityMoney;
					}

					if (listType == "교육")
					{
						int intFebStudyMoney = _ttoi(strMoney);
						studyFebSum += intFebStudyMoney;
					}

					if (listType == "기타")
					{
						int intFebEtcFixMoney = _ttoi(strMoney);
						etcFebFixSum += intFebEtcFixMoney;
					}

					if (listType == "대출")
					{
						int intFebLoanMoney = _ttoi(strMoney);
						loanFebSum += intFebLoanMoney;
					}

					if (listType == "보험")
					{
						int intFebInsuMoney = _ttoi(strMoney);
						insuFebSum += intFebInsuMoney;
					}

					if (listType == "저축")
					{
						int intFebSavingMoney = _ttoi(strMoney);
						savingFebSum += intFebSavingMoney;
					}

					if (listType == "카드대금")
					{
						int intFebCardMoney = _ttoi(strMoney);
						cardFebSum += intFebCardMoney;
					}

					if (listType == "통신비")
					{
						int intFebPostageMoney = _ttoi(strMoney);
						postageFebSum += intFebPostageMoney;
					}

					if (listType == "회비")
					{
						int intFebFamilyMoney = _ttoi(strMoney);
						familyFebSum += intFebFamilyMoney;
					}
				}

				if (listDate.Find(_T("2023-3-")) != -1)
				{
					if (listType != "저축")
					{
						int intMarFixMoney = _ttoi(strMoney);
						marFixSum += intMarFixMoney;
					}
					if (listType == "공과금")
					{
						int intMarUtilityMoney = _ttoi(strMoney);
						utilityMarSum += intMarUtilityMoney;
					}

					if (listType == "교육")
					{
						int intMarStudyMoney = _ttoi(strMoney);
						studyMarSum += intMarStudyMoney;
					}

					if (listType == "기타")
					{
						int intMarEtcFixMoney = _ttoi(strMoney);
						etcMarFixSum += intMarEtcFixMoney;
					}

					if (listType == "대출")
					{
						int intMarLoanMoney = _ttoi(strMoney);
						loanMarSum += intMarLoanMoney;
					}

					if (listType == "보험")
					{
						int intMarInsuMoney = _ttoi(strMoney);
						insuMarSum += intMarInsuMoney;
					}

					if (listType == "저축")
					{
						int intMarSavingMoney = _ttoi(strMoney);
						savingMarSum += intMarSavingMoney;
					}

					if (listType == "카드대금")
					{
						int intMarCardMoney = _ttoi(strMoney);
						cardMarSum += intMarCardMoney;
					}

					if (listType == "통신비")
					{
						int intMarPostageMoney = _ttoi(strMoney);
						postageMarSum += intMarPostageMoney;
					}

					if (listType == "회비")
					{
						int intMarFamilyMoney = _ttoi(strMoney);
						familyMarSum += intMarFamilyMoney;
					}
				}

				if (listDate.Find(_T("2023-4-")) != -1)
				{
					if (listType != "저축")
					{
						int intAprFixMoney = _ttoi(strMoney);
						aprFixSum += intAprFixMoney;
					}
					if (listType == "공과금")
					{
						int intAprUtilityMoney = _ttoi(strMoney);
						utilityAprSum += intAprUtilityMoney;
					}

					if (listType == "교육")
					{
						int intAprStudyMoney = _ttoi(strMoney);
						studyAprSum += intAprStudyMoney;
					}

					if (listType == "기타")
					{
						int intAprEtcFixMoney = _ttoi(strMoney);
						etcAprFixSum += intAprEtcFixMoney;
					}

					if (listType == "대출")
					{
						int intAprLoanMoney = _ttoi(strMoney);
						loanAprSum += intAprLoanMoney;
					}

					if (listType == "보험")
					{
						int intAprInsuMoney = _ttoi(strMoney);
						insuAprSum += intAprInsuMoney;
					}

					if (listType == "저축")
					{
						int intAprSavingMoney = _ttoi(strMoney);
						savingAprSum += intAprSavingMoney;
					}

					if (listType == "카드대금")
					{
						int intAprCardMoney = _ttoi(strMoney);
						cardAprSum += intAprCardMoney;
					}

					if (listType == "통신비")
					{
						int intAprPostageMoney = _ttoi(strMoney);
						postageAprSum += intAprPostageMoney;
					}

					if (listType == "회비")
					{
						int intAprFamilyMoney = _ttoi(strMoney);
						familyAprSum += intAprFamilyMoney;
					}
				}

				if (listDate.Find(_T("2023-5-")) != -1)
				{
					if (listType != "저축")
					{
						int intMayFixMoney = _ttoi(strMoney);
						mayFixSum += intMayFixMoney;
					}
					if (listType == "공과금")
					{
						int intMayUtilityMoney = _ttoi(strMoney);
						utilityMaySum += intMayUtilityMoney;
					}

					if (listType == "교육")
					{
						int intMayStudyMoney = _ttoi(strMoney);
						studyMaySum += intMayStudyMoney;
					}

					if (listType == "기타")
					{
						int intMayEtcFixMoney = _ttoi(strMoney);
						etcMayFixSum += intMayEtcFixMoney;
					}

					if (listType == "대출")
					{
						int intMayLoanMoney = _ttoi(strMoney);
						loanMaySum += intMayLoanMoney;
					}

					if (listType == "보험")
					{
						int intMayInsuMoney = _ttoi(strMoney);
						insuMaySum += intMayInsuMoney;
					}

					if (listType == "저축")
					{
						int intMaySavingMoney = _ttoi(strMoney);
						savingMaySum += intMaySavingMoney;
					}

					if (listType == "카드대금")
					{
						int intMayCardMoney = _ttoi(strMoney);
						cardMaySum += intMayCardMoney;
					}

					if (listType == "통신비")
					{
						int intMayPostageMoney = _ttoi(strMoney);
						postageMaySum += intMayPostageMoney;
					}

					if (listType == "회비")
					{
						int intMayFamilyMoney = _ttoi(strMoney);
						familyMaySum += intMayFamilyMoney;
					}
				}

				if (listDate.Find(_T("2023-6-")) != -1)
				{
					if (listType != "저축")
					{
						int intJunFixMoney = _ttoi(strMoney);
						junFixSum += intJunFixMoney;
					}
					if (listType == "공과금")
					{
						int intJunUtilityMoney = _ttoi(strMoney);
						utilityJunSum += intJunUtilityMoney;
					}

					if (listType == "교육")
					{
						int intJunStudyMoney = _ttoi(strMoney);
						studyJunSum += intJunStudyMoney;
					}

					if (listType == "기타")
					{
						int intJunEtcFixMoney = _ttoi(strMoney);
						etcJunFixSum += intJunEtcFixMoney;
					}

					if (listType == "대출")
					{
						int intJunLoanMoney = _ttoi(strMoney);
						loanJunSum += intJunLoanMoney;
					}

					if (listType == "보험")
					{
						int intJunInsuMoney = _ttoi(strMoney);
						insuJunSum += intJunInsuMoney;
					}

					if (listType == "저축")
					{
						int intJunSavingMoney = _ttoi(strMoney);
						savingJunSum += intJunSavingMoney;
					}

					if (listType == "카드대금")
					{
						int intJunCardMoney = _ttoi(strMoney);
						cardJunSum += intJunCardMoney;
					}

					if (listType == "통신비")
					{
						int intJunPostageMoney = _ttoi(strMoney);
						postageJunSum += intJunPostageMoney;
					}

					if (listType == "회비")
					{
						int intJunFamilyMoney = _ttoi(strMoney);
						familyJunSum += intJunFamilyMoney;
					}
				}

				if (listDate.Find(_T("2023-7-")) != -1)
				{
					if (listType != "저축")
					{
						int intJulFixMoney = _ttoi(strMoney);
						julFixSum += intJulFixMoney;
					}
					if (listType == "공과금")
					{
						int intJulUtilityMoney = _ttoi(strMoney);
						utilityJulSum += intJulUtilityMoney;
					}

					if (listType == "교육")
					{
						int intJulStudyMoney = _ttoi(strMoney);
						studyJulSum += intJulStudyMoney;
					}

					if (listType == "기타")
					{
						int intJulEtcFixMoney = _ttoi(strMoney);
						etcJulFixSum += intJulEtcFixMoney;
					}

					if (listType == "대출")
					{
						int intJulLoanMoney = _ttoi(strMoney);
						loanJulSum += intJulLoanMoney;
					}

					if (listType == "보험")
					{
						int intJulInsuMoney = _ttoi(strMoney);
						insuJulSum += intJulInsuMoney;
					}

					if (listType == "저축")
					{
						int intJulSavingMoney = _ttoi(strMoney);
						savingJulSum += intJulSavingMoney;
					}

					if (listType == "카드대금")
					{
						int intJulCardMoney = _ttoi(strMoney);
						cardJulSum += intJulCardMoney;
					}

					if (listType == "통신비")
					{
						int intJulPostageMoney = _ttoi(strMoney);
						postageJulSum += intJulPostageMoney;
					}

					if (listType == "회비")
					{
						int intJulFamilyMoney = _ttoi(strMoney);
						familyJulSum += intJulFamilyMoney;
					}
				}

				if (listDate.Find(_T("2023-8-")) != -1)
				{
					if (listType != "저축")
					{
						int intAugFixMoney = _ttoi(strMoney);
						augFixSum += intAugFixMoney;
					}
					if (listType == "공과금")
					{
						int intAugUtilityMoney = _ttoi(strMoney);
						utilityAugSum += intAugUtilityMoney;
					}

					if (listType == "교육")
					{
						int intAugStudyMoney = _ttoi(strMoney);
						studyAugSum += intAugStudyMoney;
					}

					if (listType == "기타")
					{
						int intAugEtcFixMoney = _ttoi(strMoney);
						etcAugFixSum += intAugEtcFixMoney;
					}

					if (listType == "대출")
					{
						int intAugLoanMoney = _ttoi(strMoney);
						loanAugSum += intAugLoanMoney;
					}

					if (listType == "보험")
					{
						int intAugInsuMoney = _ttoi(strMoney);
						insuAugSum += intAugInsuMoney;
					}

					if (listType == "저축")
					{
						int intAugSavingMoney = _ttoi(strMoney);
						savingAugSum += intAugSavingMoney;
					}

					if (listType == "카드대금")
					{
						int intAugCardMoney = _ttoi(strMoney);
						cardAugSum += intAugCardMoney;
					}

					if (listType == "통신비")
					{
						int intAugPostageMoney = _ttoi(strMoney);
						postageAugSum += intAugPostageMoney;
					}

					if (listType == "회비")
					{
						int intAugFamilyMoney = _ttoi(strMoney);
						familyAugSum += intAugFamilyMoney;
					}
				}

				if (listDate.Find(_T("2023-9-")) != -1)
				{
					if (listType != "저축")
					{
						int intSepFixMoney = _ttoi(strMoney);
						sepFixSum += intSepFixMoney;
					}
					if (listType == "공과금")
					{
						int intSepUtilityMoney = _ttoi(strMoney);
						utilitySepSum += intSepUtilityMoney;
					}

					if (listType == "교육")
					{
						int intSepStudyMoney = _ttoi(strMoney);
						studySepSum += intSepStudyMoney;
					}

					if (listType == "기타")
					{
						int intSepEtcFixMoney = _ttoi(strMoney);
						etcSepFixSum += intSepEtcFixMoney;
					}

					if (listType == "대출")
					{
						int intSepLoanMoney = _ttoi(strMoney);
						loanSepSum += intSepLoanMoney;
					}

					if (listType == "보험")
					{
						int intSepInsuMoney = _ttoi(strMoney);
						insuSepSum += intSepInsuMoney;
					}

					if (listType == "저축")
					{
						int intSepSavingMoney = _ttoi(strMoney);
						savingSepSum += intSepSavingMoney;
					}

					if (listType == "카드대금")
					{
						int intSepCardMoney = _ttoi(strMoney);
						cardSepSum += intSepCardMoney;
					}

					if (listType == "통신비")
					{
						int intSepPostageMoney = _ttoi(strMoney);
						postageSepSum += intSepPostageMoney;
					}

					if (listType == "회비")
					{
						int intSepFamilyMoney = _ttoi(strMoney);
						familySepSum += intSepFamilyMoney;
					}
				}

				if (listDate.Find(_T("2023-10-")) != -1)
				{
					if (listType != "저축")
					{
						int intOctFixMoney = _ttoi(strMoney);
						octFixSum += intOctFixMoney;
					}
					if (listType == "공과금")
					{
						int intOctUtilityMoney = _ttoi(strMoney);
						utilityOctSum += intOctUtilityMoney;
					}

					if (listType == "교육")
					{
						int intOctStudyMoney = _ttoi(strMoney);
						studyOctSum += intOctStudyMoney;
					}

					if (listType == "기타")
					{
						int intOctEtcFixMoney = _ttoi(strMoney);
						etcOctFixSum += intOctEtcFixMoney;
					}

					if (listType == "대출")
					{
						int intOctLoanMoney = _ttoi(strMoney);
						loanOctSum += intOctLoanMoney;
					}

					if (listType == "보험")
					{
						int intOctInsuMoney = _ttoi(strMoney);
						insuOctSum += intOctInsuMoney;
					}

					if (listType == "저축")
					{
						int intOctSavingMoney = _ttoi(strMoney);
						savingOctSum += intOctSavingMoney;
					}

					if (listType == "카드대금")
					{
						int intOctCardMoney = _ttoi(strMoney);
						cardOctSum += intOctCardMoney;
					}

					if (listType == "통신비")
					{
						int intOctPostageMoney = _ttoi(strMoney);
						postageOctSum += intOctPostageMoney;
					}

					if (listType == "회비")
					{
						int intOctFamilyMoney = _ttoi(strMoney);
						familyOctSum += intOctFamilyMoney;
					}
				}

				if (listDate.Find(_T("2023-11-")) != -1)
				{
					if (listType != "저축")
					{
						int intNovFixMoney = _ttoi(strMoney);
						novFixSum += intNovFixMoney;
					}
					if (listType == "공과금")
					{
						int intNovUtilityMoney = _ttoi(strMoney);
						utilityNovSum += intNovUtilityMoney;
					}

					if (listType == "교육")
					{
						int intNovStudyMoney = _ttoi(strMoney);
						studyNovSum += intNovStudyMoney;
					}

					if (listType == "기타")
					{
						int intNovEtcFixMoney = _ttoi(strMoney);
						etcNovFixSum += intNovEtcFixMoney;
					}

					if (listType == "대출")
					{
						int intNovLoanMoney = _ttoi(strMoney);
						loanNovSum += intNovLoanMoney;
					}

					if (listType == "보험")
					{
						int intNovInsuMoney = _ttoi(strMoney);
						insuNovSum += intNovInsuMoney;
					}

					if (listType == "저축")
					{
						int intNovSavingMoney = _ttoi(strMoney);
						savingNovSum += intNovSavingMoney;
					}

					if (listType == "카드대금")
					{
						int intNovCardMoney = _ttoi(strMoney);
						cardNovSum += intNovCardMoney;
					}

					if (listType == "통신비")
					{
						int intNovPostageMoney = _ttoi(strMoney);
						postageNovSum += intNovPostageMoney;
					}

					if (listType == "회비")
					{
						int intNovFamilyMoney = _ttoi(strMoney);
						familyNovSum += intNovFamilyMoney;
					}
				}

				if (listDate.Find(_T("2023-12-")) != -1)
				{
					if (listType != "저축")
					{
						int intDecFixMoney = _ttoi(strMoney);
						decFixSum += intDecFixMoney;
					}
					if (listType == "공과금")
					{
						int intDecUtilityMoney = _ttoi(strMoney);
						utilityDecSum += intDecUtilityMoney;
					}

					if (listType == "교육")
					{
						int intDecStudyMoney = _ttoi(strMoney);
						studyDecSum += intDecStudyMoney;
					}

					if (listType == "기타")
					{
						int intDecEtcFixMoney = _ttoi(strMoney);
						etcDecFixSum += intDecEtcFixMoney;
					}

					if (listType == "대출")
					{
						int intDecLoanMoney = _ttoi(strMoney);
						loanDecSum += intDecLoanMoney;
					}

					if (listType == "보험")
					{
						int intDecInsuMoney = _ttoi(strMoney);
						insuDecSum += intDecInsuMoney;
					}

					if (listType == "저축")
					{
						int intDecSavingMoney = _ttoi(strMoney);
						savingDecSum += intDecSavingMoney;
					}

					if (listType == "카드대금")
					{
						int intDecCardMoney = _ttoi(strMoney);
						cardDecSum += intDecCardMoney;
					}

					if (listType == "통신비")
					{
						int intDecPostageMoney = _ttoi(strMoney);
						postageDecSum += intDecPostageMoney;
					}

					if (listType == "회비")
					{
						int intDecFamilyMoney = _ttoi(strMoney);
						familyDecSum += intDecFamilyMoney;
					}
				}
			}

			if (txtRadioType == "변동 지출")
			{
				int intVariableSpendMoney = _ttoi(strMoney);
				variableSpendSum += intVariableSpendMoney;
				
				if (listDate.Find(_T("2023-1-")) != -1)
				{
					int intJanVarMoney = _ttoi(strMoney);
					janVarSum += intJanVarMoney;

					if (listType == "경조사")
					{
						int intFamilyMoney = _ttoi(strMoney);
						familySum += intFamilyMoney;
					}

					if (listType == "교육")
					{
						int intStudyVarMoney = _ttoi(strMoney);
						studyVarSum += intStudyVarMoney;
					}

					if (listType == "교통비")
					{
						int intTransMoney = _ttoi(strMoney);
						transSum += intTransMoney;
					}

					if (listType == "기타")
					{
						int intEtcVarMoney = _ttoi(strMoney);
						etcVarSum += intEtcVarMoney;
					}
					
					if (listType == "문화생활")
					{
						int intEnjoyMoney = _ttoi(strMoney);
						enjoySum += intEnjoyMoney;
					}

					if (listType == "미용")
					{
						int intBeautyMoney = _ttoi(strMoney);
						beautySum += intBeautyMoney;
					}

					if (listType == "생필품")
					{
						int intNecessariesMoney = _ttoi(strMoney);
						necessariesSum += intNecessariesMoney;
					}
					
					if (listType == "식비")
					{
						int intFoodMoney = _ttoi(strMoney);
						foodSum += intFoodMoney;
					}

					if (listType == "의료")
					{
						int intMedicalMoney = _ttoi(strMoney);
						medicalSum += intMedicalMoney;
					}

					if (listType == "의류")
					{
						int intClothingMoney = _ttoi(strMoney);
						clothingSum += intClothingMoney;
					}
				}

				if (listDate.Find(_T("2023-2-")) != -1)
				{
					int intFebVarMoney = _ttoi(strMoney);
					febVarSum += intFebVarMoney;

					if (listType == "경조사")
					{
						int intFebFamilyMoney = _ttoi(strMoney);
						familyFebSum += intFebFamilyMoney;
					}

					if (listType == "교육")
					{
						int intFebStudyVarMoney = _ttoi(strMoney);
						studyFebVarSum += intFebStudyVarMoney;
					}

					if (listType == "교통비")
					{
						int intFebTransMoney = _ttoi(strMoney);
						transFebSum += intFebTransMoney;
					}

					if (listType == "기타")
					{
						int intFebEtcVarMoney = _ttoi(strMoney);
						etcFebVarSum += intFebEtcVarMoney;
					}

					if (listType == "문화생활")
					{
						int intFebEnjoyMoney = _ttoi(strMoney);
						enjoyFebSum += intFebEnjoyMoney;
					}

					if (listType == "미용")
					{
						int intFebBeautyMoney = _ttoi(strMoney);
						beautyFebSum += intFebBeautyMoney;
					}

					if (listType == "생필품")
					{
						int intFebNecessariesMoney = _ttoi(strMoney);
						necessariesFebSum += intFebNecessariesMoney;
					}

					if (listType == "식비")
					{
						int intFebFoodMoney = _ttoi(strMoney);
						foodFebSum += intFebFoodMoney;
					}

					if (listType == "의료")
					{
						int intFebMedicalMoney = _ttoi(strMoney);
						medicalFebSum += intFebMedicalMoney;
					}

					if (listType == "의류")
					{
						int intFebClothingMoney = _ttoi(strMoney);
						clothingFebSum += intFebClothingMoney;
					}
				}

				if (listDate.Find(_T("2023-3-")) != -1)
				{
					int intMarVarMoney = _ttoi(strMoney);
					marVarSum += intMarVarMoney;

					if (listType == "경조사")
					{
						int intMarFamilyMoney = _ttoi(strMoney);
						familyMarSum += intMarFamilyMoney;
					}

					if (listType == "교육")
					{
						int intMarStudyVarMoney = _ttoi(strMoney);
						studyMarVarSum += intMarStudyVarMoney;
					}

					if (listType == "교통비")
					{
						int intMarTransMoney = _ttoi(strMoney);
						transMarSum += intMarTransMoney;
					}

					if (listType == "기타")
					{
						int intMarEtcVarMoney = _ttoi(strMoney);
						etcMarVarSum += intMarEtcVarMoney;
					}

					if (listType == "문화생활")
					{
						int intMarEnjoyMoney = _ttoi(strMoney);
						enjoyMarSum += intMarEnjoyMoney;
					}

					if (listType == "미용")
					{
						int intMarBeautyMoney = _ttoi(strMoney);
						beautyMarSum += intMarBeautyMoney;
					}

					if (listType == "생필품")
					{
						int intMarNecessariesMoney = _ttoi(strMoney);
						necessariesMarSum += intMarNecessariesMoney;
					}

					if (listType == "식비")
					{
						int intMarFoodMoney = _ttoi(strMoney);
						foodMarSum += intMarFoodMoney;
					}

					if (listType == "의료")
					{
						int intMarMedicalMoney = _ttoi(strMoney);
						medicalMarSum += intMarMedicalMoney;
					}

					if (listType == "의류")
					{
						int intMarClothingMoney = _ttoi(strMoney);
						clothingMarSum += intMarClothingMoney;
					}
				}

				if (listDate.Find(_T("2023-4-")) != -1)
				{
					int intAprVarMoney = _ttoi(strMoney);
					aprVarSum += intAprVarMoney;

					if (listType == "경조사")
					{
						int intAprFamilyMoney = _ttoi(strMoney);
						familyAprSum += intAprFamilyMoney;
					}

					if (listType == "교육")
					{
						int intAprStudyVarMoney = _ttoi(strMoney);
						studyAprVarSum += intAprStudyVarMoney;
					}

					if (listType == "교통비")
					{
						int intAprTransMoney = _ttoi(strMoney);
						transAprSum += intAprTransMoney;
					}

					if (listType == "기타")
					{
						int intAprEtcVarMoney = _ttoi(strMoney);
						etcAprVarSum += intAprEtcVarMoney;
					}

					if (listType == "문화생활")
					{
						int intAprEnjoyMoney = _ttoi(strMoney);
						enjoyAprSum += intAprEnjoyMoney;
					}

					if (listType == "미용")
					{
						int intAprBeautyMoney = _ttoi(strMoney);
						beautyAprSum += intAprBeautyMoney;
					}

					if (listType == "생필품")
					{
						int intAprNecessariesMoney = _ttoi(strMoney);
						necessariesAprSum += intAprNecessariesMoney;
					}

					if (listType == "식비")
					{
						int intAprFoodMoney = _ttoi(strMoney);
						foodAprSum += intAprFoodMoney;
					}

					if (listType == "의료")
					{
						int intAprMedicalMoney = _ttoi(strMoney);
						medicalAprSum += intAprMedicalMoney;
					}

					if (listType == "의류")
					{
						int intAprClothingMoney = _ttoi(strMoney);
						clothingAprSum += intAprClothingMoney;
					}
				}

				if (listDate.Find(_T("2023-5-")) != -1)
				{
					int intMayVarMoney = _ttoi(strMoney);
					mayVarSum += intMayVarMoney;

					if (listType == "경조사")
					{
						int intMayFamilyMoney = _ttoi(strMoney);
						familyMaySum += intMayFamilyMoney;
					}

					if (listType == "교육")
					{
						int intMayStudyVarMoney = _ttoi(strMoney);
						studyMayVarSum += intMayStudyVarMoney;
					}

					if (listType == "교통비")
					{
						int intMayTransMoney = _ttoi(strMoney);
						transMaySum += intMayTransMoney;
					}

					if (listType == "기타")
					{
						int intMayEtcVarMoney = _ttoi(strMoney);
						etcMayVarSum += intMayEtcVarMoney;
					}

					if (listType == "문화생활")
					{
						int intMayEnjoyMoney = _ttoi(strMoney);
						enjoyMaySum += intMayEnjoyMoney;
					}

					if (listType == "미용")
					{
						int intMayBeautyMoney = _ttoi(strMoney);
						beautyMaySum += intMayBeautyMoney;
					}

					if (listType == "생필품")
					{
						int intMayNecessariesMoney = _ttoi(strMoney);
						necessariesMaySum += intMayNecessariesMoney;
					}

					if (listType == "식비")
					{
						int intMayFoodMoney = _ttoi(strMoney);
						foodMaySum += intMayFoodMoney;
					}

					if (listType == "의료")
					{
						int intMayMedicalMoney = _ttoi(strMoney);
						medicalMaySum += intMayMedicalMoney;
					}

					if (listType == "의류")
					{
						int intMayClothingMoney = _ttoi(strMoney);
						clothingMaySum += intMayClothingMoney;
					}
				}

				if (listDate.Find(_T("2023-6-")) != -1)
				{
					int intJunVarMoney = _ttoi(strMoney);
					junVarSum += intJunVarMoney;

					if (listType == "경조사")
					{
						int intJunFamilyMoney = _ttoi(strMoney);
						familyJunSum += intJunFamilyMoney;
					}

					if (listType == "교육")
					{
						int intJunStudyVarMoney = _ttoi(strMoney);
						studyJunVarSum += intJunStudyVarMoney;
					}

					if (listType == "교통비")
					{
						int intJunTransMoney = _ttoi(strMoney);
						transJunSum += intJunTransMoney;
					}

					if (listType == "기타")
					{
						int intJunEtcVarMoney = _ttoi(strMoney);
						etcJunVarSum += intJunEtcVarMoney;
					}

					if (listType == "문화생활")
					{
						int intJunEnjoyMoney = _ttoi(strMoney);
						enjoyJunSum += intJunEnjoyMoney;
					}

					if (listType == "미용")
					{
						int intJunBeautyMoney = _ttoi(strMoney);
						beautyJunSum += intJunBeautyMoney;
					}

					if (listType == "생필품")
					{
						int intJunNecessariesMoney = _ttoi(strMoney);
						necessariesJunSum += intJunNecessariesMoney;
					}

					if (listType == "식비")
					{
						int intJunFoodMoney = _ttoi(strMoney);
						foodJunSum += intJunFoodMoney;
					}

					if (listType == "의료")
					{
						int intJunMedicalMoney = _ttoi(strMoney);
						medicalJunSum += intJunMedicalMoney;
					}

					if (listType == "의류")
					{
						int intJunClothingMoney = _ttoi(strMoney);
						clothingJunSum += intJunClothingMoney;
					}
				}

				if (listDate.Find(_T("2023-7-")) != -1)
				{
					int intJulVarMoney = _ttoi(strMoney);
					julVarSum += intJulVarMoney;

					if (listType == "경조사")
					{
						int intJulFamilyMoney = _ttoi(strMoney);
						familyJulSum += intJulFamilyMoney;
					}

					if (listType == "교육")
					{
						int intJulStudyVarMoney = _ttoi(strMoney);
						studyJulVarSum += intJulStudyVarMoney;
					}

					if (listType == "교통비")
					{
						int intJulTransMoney = _ttoi(strMoney);
						transJulSum += intJulTransMoney;
					}

					if (listType == "기타")
					{
						int intJulEtcVarMoney = _ttoi(strMoney);
						etcJulVarSum += intJulEtcVarMoney;
					}

					if (listType == "문화생활")
					{
						int intJulEnjoyMoney = _ttoi(strMoney);
						enjoyJulSum += intJulEnjoyMoney;
					}

					if (listType == "미용")
					{
						int intJulBeautyMoney = _ttoi(strMoney);
						beautyJulSum += intJulBeautyMoney;
					}

					if (listType == "생필품")
					{
						int intJulNecessariesMoney = _ttoi(strMoney);
						necessariesJulSum += intJulNecessariesMoney;
					}

					if (listType == "식비")
					{
						int intJulFoodMoney = _ttoi(strMoney);
						foodJulSum += intJulFoodMoney;
					}

					if (listType == "의료")
					{
						int intJulMedicalMoney = _ttoi(strMoney);
						medicalJulSum += intJulMedicalMoney;
					}

					if (listType == "의류")
					{
						int intJulClothingMoney = _ttoi(strMoney);
						clothingJulSum += intJulClothingMoney;
					}
				}

				if (listDate.Find(_T("2023-8-")) != -1)
				{
					int intAugVarMoney = _ttoi(strMoney);
					augVarSum += intAugVarMoney;

					if (listType == "경조사")
					{
						int intAugFamilyMoney = _ttoi(strMoney);
						familyAugSum += intAugFamilyMoney;
					}

					if (listType == "교육")
					{
						int intAugStudyVarMoney = _ttoi(strMoney);
						studyAugVarSum += intAugStudyVarMoney;
					}

					if (listType == "교통비")
					{
						int intAugTransMoney = _ttoi(strMoney);
						transAugSum += intAugTransMoney;
					}

					if (listType == "기타")
					{
						int intAugEtcVarMoney = _ttoi(strMoney);
						etcAugVarSum += intAugEtcVarMoney;
					}

					if (listType == "문화생활")
					{
						int intAugEnjoyMoney = _ttoi(strMoney);
						enjoyAugSum += intAugEnjoyMoney;
					}

					if (listType == "미용")
					{
						int intAugBeautyMoney = _ttoi(strMoney);
						beautyAugSum += intAugBeautyMoney;
					}

					if (listType == "생필품")
					{
						int intAugNecessariesMoney = _ttoi(strMoney);
						necessariesAugSum += intAugNecessariesMoney;
					}

					if (listType == "식비")
					{
						int intAugFoodMoney = _ttoi(strMoney);
						foodAugSum += intAugFoodMoney;
					}

					if (listType == "의료")
					{
						int intAugMedicalMoney = _ttoi(strMoney);
						medicalAugSum += intAugMedicalMoney;
					}

					if (listType == "의류")
					{
						int intAugClothingMoney = _ttoi(strMoney);
						clothingAugSum += intAugClothingMoney;
					}
				}

				if (listDate.Find(_T("2023-9-")) != -1)
				{
					int intSepVarMoney = _ttoi(strMoney);
					sepVarSum += intSepVarMoney;

					if (listType == "경조사")
					{
						int intSepFamilyMoney = _ttoi(strMoney);
						familySepSum += intSepFamilyMoney;
					}

					if (listType == "교육")
					{
						int intSepStudyVarMoney = _ttoi(strMoney);
						studySepVarSum += intSepStudyVarMoney;
					}

					if (listType == "교통비")
					{
						int intSepTransMoney = _ttoi(strMoney);
						transSepSum += intSepTransMoney;
					}

					if (listType == "기타")
					{
						int intSepEtcVarMoney = _ttoi(strMoney);
						etcSepVarSum += intSepEtcVarMoney;
					}

					if (listType == "문화생활")
					{
						int intSepEnjoyMoney = _ttoi(strMoney);
						enjoySepSum += intSepEnjoyMoney;
					}

					if (listType == "미용")
					{
						int intSepBeautyMoney = _ttoi(strMoney);
						beautySepSum += intSepBeautyMoney;
					}

					if (listType == "생필품")
					{
						int intSepNecessariesMoney = _ttoi(strMoney);
						necessariesSepSum += intSepNecessariesMoney;
					}

					if (listType == "식비")
					{
						int intSepFoodMoney = _ttoi(strMoney);
						foodSepSum += intSepFoodMoney;
					}

					if (listType == "의료")
					{
						int intSepMedicalMoney = _ttoi(strMoney);
						medicalSepSum += intSepMedicalMoney;
					}

					if (listType == "의류")
					{
						int intSepClothingMoney = _ttoi(strMoney);
						clothingSepSum += intSepClothingMoney;
					}
				}

				if (listDate.Find(_T("2023-10-")) != -1)
				{
					int intOctVarMoney = _ttoi(strMoney);
					octVarSum += intOctVarMoney;

					if (listType == "경조사")
					{
						int intOctFamilyMoney = _ttoi(strMoney);
						familyOctSum += intOctFamilyMoney;
					}

					if (listType == "교육")
					{
						int intOctStudyVarMoney = _ttoi(strMoney);
						studyOctVarSum += intOctStudyVarMoney;
					}

					if (listType == "교통비")
					{
						int intOctTransMoney = _ttoi(strMoney);
						transOctSum += intOctTransMoney;
					}

					if (listType == "기타")
					{
						int intOctEtcVarMoney = _ttoi(strMoney);
						etcOctVarSum += intOctEtcVarMoney;
					}

					if (listType == "문화생활")
					{
						int intOctEnjoyMoney = _ttoi(strMoney);
						enjoyOctSum += intOctEnjoyMoney;
					}

					if (listType == "미용")
					{
						int intOctBeautyMoney = _ttoi(strMoney);
						beautyOctSum += intOctBeautyMoney;
					}

					if (listType == "생필품")
					{
						int intOctNecessariesMoney = _ttoi(strMoney);
						necessariesOctSum += intOctNecessariesMoney;
					}

					if (listType == "식비")
					{
						int intOctFoodMoney = _ttoi(strMoney);
						foodOctSum += intOctFoodMoney;
					}

					if (listType == "의료")
					{
						int intOctMedicalMoney = _ttoi(strMoney);
						medicalOctSum += intOctMedicalMoney;
					}

					if (listType == "의류")
					{
						int intOctClothingMoney = _ttoi(strMoney);
						clothingOctSum += intOctClothingMoney;
					}
				}

				if (listDate.Find(_T("2023-11-")) != -1)
				{
					int intNovVarMoney = _ttoi(strMoney);
					novVarSum += intNovVarMoney;

					if (listType == "경조사")
					{
						int intNovFamilyMoney = _ttoi(strMoney);
						familyNovSum += intNovFamilyMoney;
					}

					if (listType == "교육")
					{
						int intNovStudyVarMoney = _ttoi(strMoney);
						studyNovVarSum += intNovStudyVarMoney;
					}

					if (listType == "교통비")
					{
						int intNovTransMoney = _ttoi(strMoney);
						transNovSum += intNovTransMoney;
					}

					if (listType == "기타")
					{
						int intNovEtcVarMoney = _ttoi(strMoney);
						etcNovVarSum += intNovEtcVarMoney;
					}

					if (listType == "문화생활")
					{
						int intNovEnjoyMoney = _ttoi(strMoney);
						enjoyNovSum += intNovEnjoyMoney;
					}

					if (listType == "미용")
					{
						int intNovBeautyMoney = _ttoi(strMoney);
						beautyNovSum += intNovBeautyMoney;
					}

					if (listType == "생필품")
					{
						int intNovNecessariesMoney = _ttoi(strMoney);
						necessariesNovSum += intNovNecessariesMoney;
					}

					if (listType == "식비")
					{
						int intNovFoodMoney = _ttoi(strMoney);
						foodNovSum += intNovFoodMoney;
					}

					if (listType == "의료")
					{
						int intNovMedicalMoney = _ttoi(strMoney);
						medicalNovSum += intNovMedicalMoney;
					}

					if (listType == "의류")
					{
						int intNovClothingMoney = _ttoi(strMoney);
						clothingNovSum += intNovClothingMoney;
					}
				}
				
				if (listDate.Find(_T("2023-12-")) != -1)
				{
					int intDecVarMoney = _ttoi(strMoney);
					decVarSum += intDecVarMoney;

					if (listType == "경조사")
					{
						int intDecFamilyMoney = _ttoi(strMoney);
						familyDecSum += intDecFamilyMoney;
					}

					if (listType == "교육")
					{
						int intDecStudyVarMoney = _ttoi(strMoney);
						studyDecVarSum += intDecStudyVarMoney;
					}

					if (listType == "교통비")
					{
						int intDecTransMoney = _ttoi(strMoney);
						transDecSum += intDecTransMoney;
					}

					if (listType == "기타")
					{
						int intDecEtcVarMoney = _ttoi(strMoney);
						etcDecVarSum += intDecEtcVarMoney;
					}
					
					if (listType == "문화생활")
					{
						int intDecEnjoyMoney = _ttoi(strMoney);
						enjoyDecSum += intDecEnjoyMoney;
					}

					if (listType == "미용")
					{
						int intDecBeautyMoney = _ttoi(strMoney);
						beautyDecSum += intDecBeautyMoney;
					}

					if (listType == "생필품")
					{
						int intDecNecessariesMoney = _ttoi(strMoney);
						necessariesDecSum += intDecNecessariesMoney;
					}

					if (listType == "식비")
					{
						int intDecFoodMoney = _ttoi(strMoney);
						foodDecSum += intDecFoodMoney;
					}

					if (listType == "의료")
					{
						int intDecMedicalMoney = _ttoi(strMoney);
						medicalDecSum += intDecMedicalMoney;
					}

					if (listType == "의류")
					{
						int intDecClothingMoney = _ttoi(strMoney);
						clothingDecSum += intDecClothingMoney;
					}
				}
			}
		}
	}

	// 수입 카테고리
	CString strSum;
	strSum.Format(_T("%d"), sum);
	incomeRoot = m_treeControl.InsertItem(_T("수입 ") + strSum + _T("원"), 0, 0, TVI_ROOT, TVI_LAST);

	strJanSum.Format(_T("1월 %d원"), janSum);
	janIncome = m_treeControl.InsertItem(strJanSum, 0, 0, incomeRoot, TVI_LAST);

	strFebSum.Format(_T("2월 %d원"), febSum);
	febIncome = m_treeControl.InsertItem(strFebSum, 0, 0, incomeRoot, TVI_LAST);

	strMarSum.Format(_T("3월 %d원"), marSum);
	marIncome = m_treeControl.InsertItem(strMarSum, 0, 0, incomeRoot, TVI_LAST);

	strAprSum.Format(_T("4월 %d원"), aprSum);
	aprIncome = m_treeControl.InsertItem(strAprSum, 0, 0, incomeRoot, TVI_LAST);

	strMaySum.Format(_T("5월 %d원"), maySum);
	mayIncome = m_treeControl.InsertItem(strMaySum, 0, 0, incomeRoot, TVI_LAST);

	strJunSum.Format(_T("6월 %d원"), junSum);
	junIncome = m_treeControl.InsertItem(strJunSum, 0, 0, incomeRoot, TVI_LAST);

	strJulSum.Format(_T("7월 %d원"), julSum);
	julIncome = m_treeControl.InsertItem(strJulSum, 0, 0, incomeRoot, TVI_LAST);

	strAugSum.Format(_T("8월 %d원"), augSum);
	augIncome = m_treeControl.InsertItem(strAugSum, 0, 0, incomeRoot, TVI_LAST);

	strSepSum.Format(_T("9월 %d원"), sepSum);
	sepIncome = m_treeControl.InsertItem(strSepSum, 0, 0, incomeRoot, TVI_LAST);

	strOctSum.Format(_T("10월 %d원"), octSum);
	octIncome = m_treeControl.InsertItem(strOctSum, 0, 0, incomeRoot, TVI_LAST);

	strNovSum.Format(_T("11월 %d원"), novSum);
	novIncome = m_treeControl.InsertItem(strNovSum, 0, 0, incomeRoot, TVI_LAST);

	strDecSum.Format(_T("12월 %d원"), decSum);
	decIncome = m_treeControl.InsertItem(strDecSum, 0, 0, incomeRoot, TVI_LAST);

	// 1월
	strEtcSum.Format(_T("기타 %d원"), etcSum);
	m_treeControl.InsertItem(strEtcSum, 0, 0, janIncome, TVI_LAST);

	strPocketMSum.Format(_T("용돈 %d원"), pocketMSum);
	m_treeControl.InsertItem(strPocketMSum, 0, 0, janIncome, TVI_LAST);

	strSalarySum.Format(_T("월급 %d원"), salarySum);
	m_treeControl.InsertItem(strSalarySum, 0, 0, janIncome, TVI_LAST);

	strFundSum.Format(_T("투자 %d원"), fundSum);
	m_treeControl.InsertItem(strFundSum, 0, 0, janIncome, TVI_LAST);

	// 2월
	strFebEtcSum.Format(_T("기타 %d원"), etcFebSum);
	m_treeControl.InsertItem(strFebEtcSum, 0, 0, febIncome, TVI_LAST);

	strFebPocketMSum.Format(_T("용돈 %d원"), pocketMFebSum);
	m_treeControl.InsertItem(strFebPocketMSum, 0, 0, febIncome, TVI_LAST);

	strFebSalarySum.Format(_T("월급 %d원"), salaryFebSum);
	m_treeControl.InsertItem(strFebSalarySum, 0, 0, febIncome, TVI_LAST);

	strFebFundSum.Format(_T("투자 %d원"), fundFebSum);
	m_treeControl.InsertItem(strFebFundSum, 0, 0, febIncome, TVI_LAST);

	// 3월
	strMarEtcSum.Format(_T("기타 %d원"), etcMarSum);
	m_treeControl.InsertItem(strMarEtcSum, 0, 0, marIncome, TVI_LAST);

	strMarPocketMSum.Format(_T("용돈 %d원"), pocketMMarSum);
	m_treeControl.InsertItem(strMarPocketMSum, 0, 0, marIncome, TVI_LAST);

	strMarSalarySum.Format(_T("월급 %d원"), salaryMarSum);
	m_treeControl.InsertItem(strMarSalarySum, 0, 0, marIncome, TVI_LAST);

	strMarFundSum.Format(_T("투자 %d원"), fundMarSum);
	m_treeControl.InsertItem(strMarFundSum, 0, 0, marIncome, TVI_LAST);

	// 4월
	strAprEtcSum.Format(_T("기타 %d원"), etcAprSum);
	m_treeControl.InsertItem(strAprEtcSum, 0, 0, aprIncome, TVI_LAST);

	strAprPocketMSum.Format(_T("용돈 %d원"), pocketMAprSum);
	m_treeControl.InsertItem(strAprPocketMSum, 0, 0, aprIncome, TVI_LAST);

	strAprSalarySum.Format(_T("월급 %d원"), salaryAprSum);
	m_treeControl.InsertItem(strAprSalarySum, 0, 0, aprIncome, TVI_LAST);

	strAprFundSum.Format(_T("투자 %d원"), fundAprSum);
	m_treeControl.InsertItem(strAprFundSum, 0, 0, aprIncome, TVI_LAST);

	// 5월
	strMayEtcSum.Format(_T("기타 %d원"), etcMaySum);
	m_treeControl.InsertItem(strMayEtcSum, 0, 0, mayIncome, TVI_LAST);

	strMayPocketMSum.Format(_T("용돈 %d원"), pocketMMaySum);
	m_treeControl.InsertItem(strMayPocketMSum, 0, 0, mayIncome, TVI_LAST);

	strMaySalarySum.Format(_T("월급 %d원"), salaryMaySum);
	m_treeControl.InsertItem(strMaySalarySum, 0, 0, mayIncome, TVI_LAST);

	strMayFundSum.Format(_T("투자 %d원"), fundMaySum);
	m_treeControl.InsertItem(strMayFundSum, 0, 0, mayIncome, TVI_LAST);

	// 6월
	strJunEtcSum.Format(_T("기타 %d원"), etcJunSum);
	m_treeControl.InsertItem(strJunEtcSum, 0, 0, junIncome, TVI_LAST);

	strJunPocketMSum.Format(_T("용돈 %d원"), pocketMJunSum);
	m_treeControl.InsertItem(strJunPocketMSum, 0, 0, junIncome, TVI_LAST);

	strJunSalarySum.Format(_T("월급 %d원"), salaryJunSum);
	m_treeControl.InsertItem(strJunSalarySum, 0, 0, junIncome, TVI_LAST);

	strJunFundSum.Format(_T("투자 %d원"), fundJunSum);
	m_treeControl.InsertItem(strJunFundSum, 0, 0, junIncome, TVI_LAST);

	// 7월
	strJulEtcSum.Format(_T("기타 %d원"), etcJulSum);
	m_treeControl.InsertItem(strJulEtcSum, 0, 0, julIncome, TVI_LAST);

	strJulPocketMSum.Format(_T("용돈 %d원"), pocketMJulSum);
	m_treeControl.InsertItem(strJulPocketMSum, 0, 0, julIncome, TVI_LAST);

	strJulSalarySum.Format(_T("월급 %d원"), salaryJulSum);
	m_treeControl.InsertItem(strJulSalarySum, 0, 0, julIncome, TVI_LAST);

	strJulFundSum.Format(_T("투자 %d원"), fundJulSum);
	m_treeControl.InsertItem(strJulFundSum, 0, 0, julIncome, TVI_LAST);

	// 8월
	strAugEtcSum.Format(_T("기타 %d원"), etcAugSum);
	m_treeControl.InsertItem(strAugEtcSum, 0, 0, augIncome, TVI_LAST);

	strAugPocketMSum.Format(_T("용돈 %d원"), pocketMAugSum);
	m_treeControl.InsertItem(strAugPocketMSum, 0, 0, augIncome, TVI_LAST);

	strAugSalarySum.Format(_T("월급 %d원"), salaryAugSum);
	m_treeControl.InsertItem(strAugSalarySum, 0, 0, augIncome, TVI_LAST);

	strAugFundSum.Format(_T("투자 %d원"), fundAugSum);
	m_treeControl.InsertItem(strAugFundSum, 0, 0, augIncome, TVI_LAST);

	// 9월
	strSepEtcSum.Format(_T("기타 %d원"), etcSepSum);
	m_treeControl.InsertItem(strSepEtcSum, 0, 0, sepIncome, TVI_LAST);

	strSepPocketMSum.Format(_T("용돈 %d원"), pocketMSepSum);
	m_treeControl.InsertItem(strSepPocketMSum, 0, 0, sepIncome, TVI_LAST);

	strSepSalarySum.Format(_T("월급 %d원"), salarySepSum);
	m_treeControl.InsertItem(strSepSalarySum, 0, 0, sepIncome, TVI_LAST);

	strSepFundSum.Format(_T("투자 %d원"), fundSepSum);
	m_treeControl.InsertItem(strSepFundSum, 0, 0, sepIncome, TVI_LAST);

	// 10월
	strOctEtcSum.Format(_T("기타 %d원"), etcOctSum);
	m_treeControl.InsertItem(strOctEtcSum, 0, 0, octIncome, TVI_LAST);

	strOctPocketMSum.Format(_T("용돈 %d원"), pocketMOctSum);
	m_treeControl.InsertItem(strOctPocketMSum, 0, 0, octIncome, TVI_LAST);

	strOctSalarySum.Format(_T("월급 %d원"), salaryOctSum);
	m_treeControl.InsertItem(strOctSalarySum, 0, 0, octIncome, TVI_LAST);

	strOctFundSum.Format(_T("투자 %d원"), fundOctSum);
	m_treeControl.InsertItem(strOctFundSum, 0, 0, octIncome, TVI_LAST);

	// 11월
	strNovEtcSum.Format(_T("기타 %d원"), etcNovSum);
	m_treeControl.InsertItem(strNovEtcSum, 0, 0, novIncome, TVI_LAST);

	strNovPocketMSum.Format(_T("용돈 %d원"), pocketMNovSum);
	m_treeControl.InsertItem(strNovPocketMSum, 0, 0, novIncome, TVI_LAST);

	strNovSalarySum.Format(_T("월급 %d원"), salaryNovSum);
	m_treeControl.InsertItem(strNovSalarySum, 0, 0, novIncome, TVI_LAST);

	strNovFundSum.Format(_T("투자 %d원"), fundNovSum);
	m_treeControl.InsertItem(strNovFundSum, 0, 0, novIncome, TVI_LAST);

	// 12월
	strDecEtcSum.Format(_T("기타 %d원"), etcDecSum);
	m_treeControl.InsertItem(strDecEtcSum, 0, 0, decIncome, TVI_LAST);

	strDecPocketMSum.Format(_T("용돈 %d원"), pocketMDecSum);
	m_treeControl.InsertItem(strDecPocketMSum, 0, 0, decIncome, TVI_LAST);

	strDecSalarySum.Format(_T("월급 %d원"), salaryDecSum);
	m_treeControl.InsertItem(strDecSalarySum, 0, 0, decIncome, TVI_LAST);

	strDecFundSum.Format(_T("투자 %d원"), fundDecSum);
	m_treeControl.InsertItem(strDecFundSum, 0, 0, decIncome, TVI_LAST);
	

	// 지출 카테고리
	CString strTotalSpendSum;
	strTotalSpendSum.Format(_T("%d"), totalSpendSum);
	spendRoot = m_spendTreeControl.InsertItem(_T("지출 ") + strTotalSpendSum + _T("원"), 0, 0, TVI_ROOT, TVI_LAST);

	// 고정 지출
	strFixSpendSum.Format(_T("고정 지출 %d원"), fixSpendSum);
	fixSpend = m_spendTreeControl.InsertItem(strFixSpendSum, 0, 0, spendRoot, TVI_LAST);
	
	strJanFixSpendSum.Format(_T("1월 %d원"), janFixSum);
	janFix = m_spendTreeControl.InsertItem(strJanFixSpendSum, 0, 0, fixSpend, TVI_LAST);

	strFebFixSpendSum.Format(_T("2월 %d원"), febFixSum);
	febFix = m_spendTreeControl.InsertItem(strFebFixSpendSum, 0, 0, fixSpend, TVI_LAST);

	strMarFixSpendSum.Format(_T("3월 %d원"), marFixSum);
	marFix = m_spendTreeControl.InsertItem(strMarFixSpendSum, 0, 0, fixSpend, TVI_LAST);

	strAprFixSpendSum.Format(_T("4월 %d원"), aprFixSum);
	aprFix = m_spendTreeControl.InsertItem(strAprFixSpendSum, 0, 0, fixSpend, TVI_LAST);

	strMayFixSpendSum.Format(_T("5월 %d원"), mayFixSum);
	mayFix = m_spendTreeControl.InsertItem(strMayFixSpendSum, 0, 0, fixSpend, TVI_LAST);

	strJunFixSpendSum.Format(_T("6월 %d원"), junFixSum);
	junFix = m_spendTreeControl.InsertItem(strJunFixSpendSum, 0, 0, fixSpend, TVI_LAST);

	strJulFixSpendSum.Format(_T("7월 %d원"), julFixSum);
	julFix = m_spendTreeControl.InsertItem(strJulFixSpendSum, 0, 0, fixSpend, TVI_LAST);

	strAugFixSpendSum.Format(_T("8월 %d원"), augFixSum);
	augFix = m_spendTreeControl.InsertItem(strAugFixSpendSum, 0, 0, fixSpend, TVI_LAST);

	strSepFixSpendSum.Format(_T("9월 %d원"), sepFixSum);
	sepFix = m_spendTreeControl.InsertItem(strSepFixSpendSum, 0, 0, fixSpend, TVI_LAST);

	strOctFixSpendSum.Format(_T("10월 %d원"), octFixSum);
	octFix = m_spendTreeControl.InsertItem(strOctFixSpendSum, 0, 0, fixSpend, TVI_LAST);

	strNovFixSpendSum.Format(_T("11월 %d원"), novFixSum);
	novFix = m_spendTreeControl.InsertItem(strNovFixSpendSum, 0, 0, fixSpend, TVI_LAST);

	strDecFixSpendSum.Format(_T("12월 %d원"), decFixSum);
	decFix = m_spendTreeControl.InsertItem(strDecFixSpendSum, 0, 0, fixSpend, TVI_LAST);

	// 1월
	strUtilitySum.Format(_T("공과금 %d원"), utilitySum);
	m_spendTreeControl.InsertItem(strUtilitySum, 0, 0, janFix, TVI_LAST);

	strStudySum.Format(_T("교육 %d원"), studySum);
	m_spendTreeControl.InsertItem(strStudySum, 0, 0, janFix, TVI_LAST);

	strEtcFixSum.Format(_T("기타 %d원"), etcFixSum);
	m_spendTreeControl.InsertItem(strEtcFixSum, 0, 0, janFix, TVI_LAST);

	strLoanSum.Format(_T("대출 %d원"), loanSum);
	m_spendTreeControl.InsertItem(strLoanSum, 0, 0, janFix, TVI_LAST);

	strInsuSum.Format(_T("보험 %d원"), insuSum);
	m_spendTreeControl.InsertItem(strInsuSum, 0, 0, janFix, TVI_LAST);

	strSavingSum.Format(_T("저축 %d원 💚"), savingSum);
	m_spendTreeControl.InsertItem(strSavingSum, 0, 0, janFix, TVI_LAST);

	strCardSum.Format(_T("카드대금 %d원"), cardSum);
	m_spendTreeControl.InsertItem(strCardSum, 0, 0, janFix, TVI_LAST);

	strPostageSum.Format(_T("통신비 %d원"), postageSum);
	m_spendTreeControl.InsertItem(strPostageSum, 0, 0, janFix, TVI_LAST);

	strMembershipSum.Format(_T("회비 %d원"), membershipSum);
	m_spendTreeControl.InsertItem(strMembershipSum, 0, 0, janFix, TVI_LAST);

	// 2월
	strFebUtilitySum.Format(_T("공과금 %d원"), utilityFebSum);
	m_spendTreeControl.InsertItem(strFebUtilitySum, 0, 0, febFix, TVI_LAST);

	strFebStudySum.Format(_T("교육 %d원"), studyFebSum);
	m_spendTreeControl.InsertItem(strFebStudySum, 0, 0, febFix, TVI_LAST);

	strFebEtcFixSum.Format(_T("기타 %d원"), etcFebFixSum);
	m_spendTreeControl.InsertItem(strFebEtcFixSum, 0, 0, febFix, TVI_LAST);

	strFebLoanSum.Format(_T("대출 %d원"), loanFebSum);
	m_spendTreeControl.InsertItem(strFebLoanSum, 0, 0, febFix, TVI_LAST);

	strFebInsuSum.Format(_T("보험 %d원"), insuFebSum);
	m_spendTreeControl.InsertItem(strFebInsuSum, 0, 0, febFix, TVI_LAST);

	strFebSavingSum.Format(_T("저축 %d원 💚"), savingFebSum);
	m_spendTreeControl.InsertItem(strFebSavingSum, 0, 0, febFix, TVI_LAST);

	strFebCardSum.Format(_T("카드대금 %d원"), cardFebSum);
	m_spendTreeControl.InsertItem(strFebCardSum, 0, 0, febFix, TVI_LAST);

	strFebPostageSum.Format(_T("통신비 %d원"), postageFebSum);
	m_spendTreeControl.InsertItem(strFebPostageSum, 0, 0, febFix, TVI_LAST);

	strFebMembershipSum.Format(_T("회비 %d원"), membershipFebSum);
	m_spendTreeControl.InsertItem(strFebMembershipSum, 0, 0, febFix, TVI_LAST);

	// 3월
	strMarUtilitySum.Format(_T("공과금 %d원"), utilityMarSum);
	m_spendTreeControl.InsertItem(strMarUtilitySum, 0, 0, marFix, TVI_LAST);

	strMarStudySum.Format(_T("교육 %d원"), studyMarSum);
	m_spendTreeControl.InsertItem(strMarStudySum, 0, 0, marFix, TVI_LAST);

	strMarEtcFixSum.Format(_T("기타 %d원"), etcMarFixSum);
	m_spendTreeControl.InsertItem(strMarEtcFixSum, 0, 0, marFix, TVI_LAST);

	strMarLoanSum.Format(_T("대출 %d원"), loanMarSum);
	m_spendTreeControl.InsertItem(strMarLoanSum, 0, 0, marFix, TVI_LAST);

	strMarInsuSum.Format(_T("보험 %d원"), insuMarSum);
	m_spendTreeControl.InsertItem(strMarInsuSum, 0, 0, marFix, TVI_LAST);

	strMarSavingSum.Format(_T("저축 %d원 💚"), savingMarSum);
	m_spendTreeControl.InsertItem(strMarSavingSum, 0, 0, marFix, TVI_LAST);

	strMarCardSum.Format(_T("카드대금 %d원"), cardMarSum);
	m_spendTreeControl.InsertItem(strMarCardSum, 0, 0, marFix, TVI_LAST);

	strMarPostageSum.Format(_T("통신비 %d원"), postageMarSum);
	m_spendTreeControl.InsertItem(strMarPostageSum, 0, 0, marFix, TVI_LAST);

	strMarMembershipSum.Format(_T("회비 %d원"), membershipMarSum);
	m_spendTreeControl.InsertItem(strMarMembershipSum, 0, 0, marFix, TVI_LAST);

	// 4월
	strAprUtilitySum.Format(_T("공과금 %d원"), utilityAprSum);
	m_spendTreeControl.InsertItem(strAprUtilitySum, 0, 0, aprFix, TVI_LAST);

	strAprStudySum.Format(_T("교육 %d원"), studyAprSum);
	m_spendTreeControl.InsertItem(strAprStudySum, 0, 0, aprFix, TVI_LAST);

	strAprEtcFixSum.Format(_T("기타 %d원"), etcAprFixSum);
	m_spendTreeControl.InsertItem(strAprEtcFixSum, 0, 0, aprFix, TVI_LAST);

	strAprLoanSum.Format(_T("대출 %d원"), loanAprSum);
	m_spendTreeControl.InsertItem(strAprLoanSum, 0, 0, aprFix, TVI_LAST);

	strAprInsuSum.Format(_T("보험 %d원"), insuAprSum);
	m_spendTreeControl.InsertItem(strAprInsuSum, 0, 0, aprFix, TVI_LAST);

	strAprSavingSum.Format(_T("저축 %d원 💚"), savingAprSum);
	m_spendTreeControl.InsertItem(strAprSavingSum, 0, 0, aprFix, TVI_LAST);

	strAprCardSum.Format(_T("카드대금 %d원"), cardAprSum);
	m_spendTreeControl.InsertItem(strAprCardSum, 0, 0, aprFix, TVI_LAST);

	strAprPostageSum.Format(_T("통신비 %d원"), postageAprSum);
	m_spendTreeControl.InsertItem(strAprPostageSum, 0, 0, aprFix, TVI_LAST);

	strAprMembershipSum.Format(_T("회비 %d원"), membershipAprSum);
	m_spendTreeControl.InsertItem(strAprMembershipSum, 0, 0, aprFix, TVI_LAST);

	// 5월
	strMayUtilitySum.Format(_T("공과금 %d원"), utilityMaySum);
	m_spendTreeControl.InsertItem(strMayUtilitySum, 0, 0, mayFix, TVI_LAST);

	strMayStudySum.Format(_T("교육 %d원"), studyMaySum);
	m_spendTreeControl.InsertItem(strMayStudySum, 0, 0, mayFix, TVI_LAST);

	strMayEtcFixSum.Format(_T("기타 %d원"), etcMayFixSum);
	m_spendTreeControl.InsertItem(strMayEtcFixSum, 0, 0, mayFix, TVI_LAST);

	strMayLoanSum.Format(_T("대출 %d원"), loanMaySum);
	m_spendTreeControl.InsertItem(strMayLoanSum, 0, 0, mayFix, TVI_LAST);

	strMayInsuSum.Format(_T("보험 %d원"), insuMaySum);
	m_spendTreeControl.InsertItem(strMayInsuSum, 0, 0, mayFix, TVI_LAST);

	strMaySavingSum.Format(_T("저축 %d원 💚"), savingMaySum);
	m_spendTreeControl.InsertItem(strMaySavingSum, 0, 0, mayFix, TVI_LAST);

	strMayCardSum.Format(_T("카드대금 %d원"), cardMaySum);
	m_spendTreeControl.InsertItem(strMayCardSum, 0, 0, mayFix, TVI_LAST);

	strMayPostageSum.Format(_T("통신비 %d원"), postageMaySum);
	m_spendTreeControl.InsertItem(strMayPostageSum, 0, 0, mayFix, TVI_LAST);

	strMayMembershipSum.Format(_T("회비 %d원"), membershipMaySum);
	m_spendTreeControl.InsertItem(strMayMembershipSum, 0, 0, mayFix, TVI_LAST);

	// 6월
	strJunUtilitySum.Format(_T("공과금 %d원"), utilityJunSum);
	m_spendTreeControl.InsertItem(strJunUtilitySum, 0, 0, junFix, TVI_LAST);

	strJunStudySum.Format(_T("교육 %d원"), studyJunSum);
	m_spendTreeControl.InsertItem(strJunStudySum, 0, 0, junFix, TVI_LAST);

	strJunEtcFixSum.Format(_T("기타 %d원"), etcJunFixSum);
	m_spendTreeControl.InsertItem(strJunEtcFixSum, 0, 0, junFix, TVI_LAST);

	strJunLoanSum.Format(_T("대출 %d원"), loanJunSum);
	m_spendTreeControl.InsertItem(strJunLoanSum, 0, 0, junFix, TVI_LAST);

	strJunInsuSum.Format(_T("보험 %d원"), insuJunSum);
	m_spendTreeControl.InsertItem(strJunInsuSum, 0, 0, junFix, TVI_LAST);

	strJunSavingSum.Format(_T("저축 %d원 💚"), savingJunSum);
	m_spendTreeControl.InsertItem(strJunSavingSum, 0, 0, junFix, TVI_LAST);

	strJunCardSum.Format(_T("카드대금 %d원"), cardJunSum);
	m_spendTreeControl.InsertItem(strJunCardSum, 0, 0, junFix, TVI_LAST);

	strJunPostageSum.Format(_T("통신비 %d원"), postageJunSum);
	m_spendTreeControl.InsertItem(strJunPostageSum, 0, 0, junFix, TVI_LAST);

	strJunMembershipSum.Format(_T("회비 %d원"), membershipJunSum);
	m_spendTreeControl.InsertItem(strJunMembershipSum, 0, 0, junFix, TVI_LAST);

	// 7월
	strJulUtilitySum.Format(_T("공과금 %d원"), utilityJulSum);
	m_spendTreeControl.InsertItem(strJulUtilitySum, 0, 0, julFix, TVI_LAST);

	strJulStudySum.Format(_T("교육 %d원"), studyJulSum);
	m_spendTreeControl.InsertItem(strJulStudySum, 0, 0, julFix, TVI_LAST);

	strJulEtcFixSum.Format(_T("기타 %d원"), etcJulFixSum);
	m_spendTreeControl.InsertItem(strJulEtcFixSum, 0, 0, julFix, TVI_LAST);

	strJulLoanSum.Format(_T("대출 %d원"), loanJulSum);
	m_spendTreeControl.InsertItem(strJulLoanSum, 0, 0, julFix, TVI_LAST);

	strJulInsuSum.Format(_T("보험 %d원"), insuJulSum);
	m_spendTreeControl.InsertItem(strJulInsuSum, 0, 0, julFix, TVI_LAST);

	strJulSavingSum.Format(_T("저축 %d원 💚"), savingJulSum);
	m_spendTreeControl.InsertItem(strJulSavingSum, 0, 0, julFix, TVI_LAST);

	strJulCardSum.Format(_T("카드대금 %d원"), cardJulSum);
	m_spendTreeControl.InsertItem(strJulCardSum, 0, 0, julFix, TVI_LAST);

	strJulPostageSum.Format(_T("통신비 %d원"), postageJulSum);
	m_spendTreeControl.InsertItem(strJulPostageSum, 0, 0, julFix, TVI_LAST);

	strJulMembershipSum.Format(_T("회비 %d원"), membershipJulSum);
	m_spendTreeControl.InsertItem(strJulMembershipSum, 0, 0, julFix, TVI_LAST);

	// 8월
	strAugUtilitySum.Format(_T("공과금 %d원"), utilityAugSum);
	m_spendTreeControl.InsertItem(strAugUtilitySum, 0, 0, augFix, TVI_LAST);

	strAugStudySum.Format(_T("교육 %d원"), studyAugSum);
	m_spendTreeControl.InsertItem(strAugStudySum, 0, 0, augFix, TVI_LAST);

	strAugEtcFixSum.Format(_T("기타 %d원"), etcAugFixSum);
	m_spendTreeControl.InsertItem(strAugEtcFixSum, 0, 0, augFix, TVI_LAST);

	strAugLoanSum.Format(_T("대출 %d원"), loanAugSum);
	m_spendTreeControl.InsertItem(strAugLoanSum, 0, 0, augFix, TVI_LAST);

	strAugInsuSum.Format(_T("보험 %d원"), insuAugSum);
	m_spendTreeControl.InsertItem(strAugInsuSum, 0, 0, augFix, TVI_LAST);

	strAugSavingSum.Format(_T("저축 %d원 💚"), savingAugSum);
	m_spendTreeControl.InsertItem(strAugSavingSum, 0, 0, augFix, TVI_LAST);

	strAugCardSum.Format(_T("카드대금 %d원"), cardAugSum);
	m_spendTreeControl.InsertItem(strAugCardSum, 0, 0, augFix, TVI_LAST);

	strAugPostageSum.Format(_T("통신비 %d원"), postageAugSum);
	m_spendTreeControl.InsertItem(strAugPostageSum, 0, 0, augFix, TVI_LAST);

	strAugMembershipSum.Format(_T("회비 %d원"), membershipAugSum);
	m_spendTreeControl.InsertItem(strAugMembershipSum, 0, 0, augFix, TVI_LAST);

	// 9월
	strSepUtilitySum.Format(_T("공과금 %d원"), utilitySepSum);
	m_spendTreeControl.InsertItem(strSepUtilitySum, 0, 0, sepFix, TVI_LAST);

	strSepStudySum.Format(_T("교육 %d원"), studySepSum);
	m_spendTreeControl.InsertItem(strSepStudySum, 0, 0, sepFix, TVI_LAST);

	strSepEtcFixSum.Format(_T("기타 %d원"), etcSepFixSum);
	m_spendTreeControl.InsertItem(strSepEtcFixSum, 0, 0, sepFix, TVI_LAST);

	strSepLoanSum.Format(_T("대출 %d원"), loanSepSum);
	m_spendTreeControl.InsertItem(strSepLoanSum, 0, 0, sepFix, TVI_LAST);

	strSepInsuSum.Format(_T("보험 %d원"), insuSepSum);
	m_spendTreeControl.InsertItem(strSepInsuSum, 0, 0, sepFix, TVI_LAST);

	strSepSavingSum.Format(_T("저축 %d원 💚"), savingSepSum);
	m_spendTreeControl.InsertItem(strSepSavingSum, 0, 0, sepFix, TVI_LAST);

	strSepCardSum.Format(_T("카드대금 %d원"), cardSepSum);
	m_spendTreeControl.InsertItem(strSepCardSum, 0, 0, sepFix, TVI_LAST);

	strSepPostageSum.Format(_T("통신비 %d원"), postageSepSum);
	m_spendTreeControl.InsertItem(strSepPostageSum, 0, 0, sepFix, TVI_LAST);

	strSepMembershipSum.Format(_T("회비 %d원"), membershipSepSum);
	m_spendTreeControl.InsertItem(strSepMembershipSum, 0, 0, sepFix, TVI_LAST);

	// 10월
	strOctUtilitySum.Format(_T("공과금 %d원"), utilityOctSum);
	m_spendTreeControl.InsertItem(strOctUtilitySum, 0, 0, octFix, TVI_LAST);

	strOctStudySum.Format(_T("교육 %d원"), studyOctSum);
	m_spendTreeControl.InsertItem(strOctStudySum, 0, 0, octFix, TVI_LAST);

	strOctEtcFixSum.Format(_T("기타 %d원"), etcOctFixSum);
	m_spendTreeControl.InsertItem(strOctEtcFixSum, 0, 0, octFix, TVI_LAST);

	strOctLoanSum.Format(_T("대출 %d원"), loanOctSum);
	m_spendTreeControl.InsertItem(strOctLoanSum, 0, 0, octFix, TVI_LAST);

	strOctInsuSum.Format(_T("보험 %d원"), insuOctSum);
	m_spendTreeControl.InsertItem(strOctInsuSum, 0, 0, octFix, TVI_LAST);

	strOctSavingSum.Format(_T("저축 %d원 💚"), savingOctSum);
	m_spendTreeControl.InsertItem(strOctSavingSum, 0, 0, octFix, TVI_LAST);

	strOctCardSum.Format(_T("카드대금 %d원"), cardOctSum);
	m_spendTreeControl.InsertItem(strOctCardSum, 0, 0, octFix, TVI_LAST);

	strOctPostageSum.Format(_T("통신비 %d원"), postageOctSum);
	m_spendTreeControl.InsertItem(strOctPostageSum, 0, 0, octFix, TVI_LAST);

	strOctMembershipSum.Format(_T("회비 %d원"), membershipOctSum);
	m_spendTreeControl.InsertItem(strOctMembershipSum, 0, 0, octFix, TVI_LAST);

	// 11월
	strNovUtilitySum.Format(_T("공과금 %d원"), utilityNovSum);
	m_spendTreeControl.InsertItem(strNovUtilitySum, 0, 0, novFix, TVI_LAST);

	strNovStudySum.Format(_T("교육 %d원"), studyNovSum);
	m_spendTreeControl.InsertItem(strNovStudySum, 0, 0, novFix, TVI_LAST);

	strNovEtcFixSum.Format(_T("기타 %d원"), etcNovFixSum);
	m_spendTreeControl.InsertItem(strNovEtcFixSum, 0, 0, novFix, TVI_LAST);

	strNovLoanSum.Format(_T("대출 %d원"), loanNovSum);
	m_spendTreeControl.InsertItem(strNovLoanSum, 0, 0, novFix, TVI_LAST);

	strNovInsuSum.Format(_T("보험 %d원"), insuNovSum);
	m_spendTreeControl.InsertItem(strNovInsuSum, 0, 0, novFix, TVI_LAST);

	strNovSavingSum.Format(_T("저축 %d원 💚"), savingNovSum);
	m_spendTreeControl.InsertItem(strNovSavingSum, 0, 0, novFix, TVI_LAST);

	strNovCardSum.Format(_T("카드대금 %d원"), cardNovSum);
	m_spendTreeControl.InsertItem(strNovCardSum, 0, 0, novFix, TVI_LAST);

	strNovPostageSum.Format(_T("통신비 %d원"), postageNovSum);
	m_spendTreeControl.InsertItem(strNovPostageSum, 0, 0, novFix, TVI_LAST);

	strNovMembershipSum.Format(_T("회비 %d원"), membershipNovSum);
	m_spendTreeControl.InsertItem(strNovMembershipSum, 0, 0, novFix, TVI_LAST);

	// 12월
	strDecUtilitySum.Format(_T("공과금 %d원"), utilityDecSum);
	m_spendTreeControl.InsertItem(strDecUtilitySum, 0, 0, decFix, TVI_LAST);

	strDecStudySum.Format(_T("교육 %d원"), studyDecSum);
	m_spendTreeControl.InsertItem(strDecStudySum, 0, 0, decFix, TVI_LAST);

	strDecEtcFixSum.Format(_T("기타 %d원"), etcDecFixSum);
	m_spendTreeControl.InsertItem(strDecEtcFixSum, 0, 0, decFix, TVI_LAST);

	strDecLoanSum.Format(_T("대출 %d원"), loanDecSum);
	m_spendTreeControl.InsertItem(strDecLoanSum, 0, 0, decFix, TVI_LAST);

	strDecInsuSum.Format(_T("보험 %d원"), insuDecSum);
	m_spendTreeControl.InsertItem(strDecInsuSum, 0, 0, decFix, TVI_LAST);

	strDecSavingSum.Format(_T("저축 %d원 💚"), savingDecSum);
	m_spendTreeControl.InsertItem(strDecSavingSum, 0, 0, decFix, TVI_LAST);

	strDecCardSum.Format(_T("카드대금 %d원"), cardDecSum);
	m_spendTreeControl.InsertItem(strDecCardSum, 0, 0, decFix, TVI_LAST);

	strDecPostageSum.Format(_T("통신비 %d원"), postageDecSum);
	m_spendTreeControl.InsertItem(strDecPostageSum, 0, 0, decFix, TVI_LAST);

	strDecMembershipSum.Format(_T("회비 %d원"), membershipDecSum);
	m_spendTreeControl.InsertItem(strDecMembershipSum, 0, 0, decFix, TVI_LAST);

	// 변동 지출
	strVariableSpendSum.Format(_T("변동 지출 %d원"), variableSpendSum);
	variableSpend = m_spendTreeControl.InsertItem(strVariableSpendSum, 0, 0, spendRoot, TVI_LAST);

	strJanVarSpendSum.Format(_T("1월 %d원"), janVarSum);
	janVar = m_spendTreeControl.InsertItem(strJanVarSpendSum, 0, 0, variableSpend, TVI_LAST);

	strFebVarSpendSum.Format(_T("2월 %d원"), febVarSum);
	febVar = m_spendTreeControl.InsertItem(strFebVarSpendSum, 0, 0, variableSpend, TVI_LAST);

	strMarVarSpendSum.Format(_T("3월 %d원"), marVarSum);
	marVar = m_spendTreeControl.InsertItem(strMarVarSpendSum, 0, 0, variableSpend, TVI_LAST);

	strAprVarSpendSum.Format(_T("4월 %d원"), aprVarSum);
	aprVar = m_spendTreeControl.InsertItem(strAprVarSpendSum, 0, 0, variableSpend, TVI_LAST);

	strMayVarSpendSum.Format(_T("5월 %d원"), mayVarSum);
	mayVar = m_spendTreeControl.InsertItem(strMayVarSpendSum, 0, 0, variableSpend, TVI_LAST);

	strJunVarSpendSum.Format(_T("6월 %d원"), junVarSum);
	junVar = m_spendTreeControl.InsertItem(strJunVarSpendSum, 0, 0, variableSpend, TVI_LAST);

	strJulVarSpendSum.Format(_T("7월 %d원"), julVarSum);
	julVar = m_spendTreeControl.InsertItem(strJulVarSpendSum, 0, 0, variableSpend, TVI_LAST);

	strAugVarSpendSum.Format(_T("8월 %d원"), augVarSum);
	augVar = m_spendTreeControl.InsertItem(strAugVarSpendSum, 0, 0, variableSpend, TVI_LAST);

	strSepVarSpendSum.Format(_T("9월 %d원"), sepVarSum);
	sepVar = m_spendTreeControl.InsertItem(strSepVarSpendSum, 0, 0, variableSpend, TVI_LAST);

	strOctVarSpendSum.Format(_T("10월 %d원"), octVarSum);
	octVar = m_spendTreeControl.InsertItem(strOctVarSpendSum, 0, 0, variableSpend, TVI_LAST);

	strNovVarSpendSum.Format(_T("11월 %d원"), novVarSum);
	novVar = m_spendTreeControl.InsertItem(strNovVarSpendSum, 0, 0, variableSpend, TVI_LAST);

	strDecVarSpendSum.Format(_T("12월 %d원"), decVarSum);
	decVar = m_spendTreeControl.InsertItem(strDecVarSpendSum, 0, 0, variableSpend, TVI_LAST);

	// 1월
	strFamilySum.Format(_T("경조사 %d원"), familySum);
	m_spendTreeControl.InsertItem(strFamilySum, 0, 0, janVar, TVI_LAST);

	strStudyVarSum.Format(_T("교육 %d원"), studyVarSum);
	m_spendTreeControl.InsertItem(strStudyVarSum, 0, 0, janVar, TVI_LAST);

	strTransSum.Format(_T("교통비 %d원"), transSum);
	m_spendTreeControl.InsertItem(strTransSum, 0, 0, janVar, TVI_LAST);

	strEtcVarSum.Format(_T("기타 %d원"), etcVarSum);
	m_spendTreeControl.InsertItem(strEtcVarSum, 0, 0, janVar, TVI_LAST);

	strEnjoySum.Format(_T("문화생활 %d원"), enjoySum);
	m_spendTreeControl.InsertItem(strEnjoySum, 0, 0, janVar, TVI_LAST);

	strBeautySum.Format(_T("미용 %d원"), beautySum);
	m_spendTreeControl.InsertItem(strBeautySum, 0, 0, janVar, TVI_LAST);

	strNecessariesSum.Format(_T("생필품 %d원"), necessariesSum);
	m_spendTreeControl.InsertItem(strNecessariesSum, 0, 0, janVar, TVI_LAST);

	strFoodSum.Format(_T("식비 %d원"), foodSum);
	m_spendTreeControl.InsertItem(strFoodSum, 0, 0, janVar, TVI_LAST);

	strMedicalSum.Format(_T("의료 %d원"), medicalSum);
	m_spendTreeControl.InsertItem(strMedicalSum, 0, 0, janVar, TVI_LAST);

	strClothingSum.Format(_T("의류 %d원"), clothingSum);
	m_spendTreeControl.InsertItem(strClothingSum, 0, 0, janVar, TVI_LAST);

	// 2월
	strFebFamilySum.Format(_T("경조사 %d원"), familyFebSum);
	m_spendTreeControl.InsertItem(strFebFamilySum, 0, 0, febVar, TVI_LAST);

	strFebStudyVarSum.Format(_T("교육 %d원"), studyFebVarSum);
	m_spendTreeControl.InsertItem(strFebStudyVarSum, 0, 0, febVar, TVI_LAST);

	strFebTransSum.Format(_T("교통비 %d원"), transFebSum);
	m_spendTreeControl.InsertItem(strFebTransSum, 0, 0, febVar, TVI_LAST);

	strFebEtcVarSum.Format(_T("기타 %d원"), etcFebVarSum);
	m_spendTreeControl.InsertItem(strFebEtcVarSum, 0, 0, febVar, TVI_LAST);

	strFebEnjoySum.Format(_T("문화생활 %d원"), enjoyFebSum);
	m_spendTreeControl.InsertItem(strFebEnjoySum, 0, 0, febVar, TVI_LAST);

	strFebBeautySum.Format(_T("미용 %d원"), beautyFebSum);
	m_spendTreeControl.InsertItem(strFebBeautySum, 0, 0, febVar, TVI_LAST);

	strFebNecessariesSum.Format(_T("생필품 %d원"), necessariesFebSum);
	m_spendTreeControl.InsertItem(strFebNecessariesSum, 0, 0, febVar, TVI_LAST);

	strFebFoodSum.Format(_T("식비 %d원"), foodFebSum);
	m_spendTreeControl.InsertItem(strFebFoodSum, 0, 0, febVar, TVI_LAST);

	strFebMedicalSum.Format(_T("의료 %d원"), medicalFebSum);
	m_spendTreeControl.InsertItem(strFebMedicalSum, 0, 0, febVar, TVI_LAST);

	strFebClothingSum.Format(_T("의류 %d원"), clothingFebSum);
	m_spendTreeControl.InsertItem(strFebClothingSum, 0, 0, febVar, TVI_LAST);

	// 3월
	strMarFamilySum.Format(_T("경조사 %d원"), familyMarSum);
	m_spendTreeControl.InsertItem(strMarFamilySum, 0, 0, marVar, TVI_LAST);

	strMarStudyVarSum.Format(_T("교육 %d원"), studyMarVarSum);
	m_spendTreeControl.InsertItem(strMarStudyVarSum, 0, 0, marVar, TVI_LAST);

	strMarTransSum.Format(_T("교통비 %d원"), transMarSum);
	m_spendTreeControl.InsertItem(strMarTransSum, 0, 0, marVar, TVI_LAST);

	strMarEtcVarSum.Format(_T("기타 %d원"), etcMarVarSum);
	m_spendTreeControl.InsertItem(strMarEtcVarSum, 0, 0, marVar, TVI_LAST);

	strMarEnjoySum.Format(_T("문화생활 %d원"), enjoyMarSum);
	m_spendTreeControl.InsertItem(strMarEnjoySum, 0, 0, marVar, TVI_LAST);

	strMarBeautySum.Format(_T("미용 %d원"), beautyMarSum);
	m_spendTreeControl.InsertItem(strMarBeautySum, 0, 0, marVar, TVI_LAST);

	strMarNecessariesSum.Format(_T("생필품 %d원"), necessariesMarSum);
	m_spendTreeControl.InsertItem(strMarNecessariesSum, 0, 0, marVar, TVI_LAST);

	strMarFoodSum.Format(_T("식비 %d원"), foodMarSum);
	m_spendTreeControl.InsertItem(strMarFoodSum, 0, 0, marVar, TVI_LAST);

	strMarMedicalSum.Format(_T("의료 %d원"), medicalMarSum);
	m_spendTreeControl.InsertItem(strMarMedicalSum, 0, 0, marVar, TVI_LAST);

	strMarClothingSum.Format(_T("의류 %d원"), clothingMarSum);
	m_spendTreeControl.InsertItem(strMarClothingSum, 0, 0, marVar, TVI_LAST);

	// 4월
	strAprFamilySum.Format(_T("경조사 %d원"), familyAprSum);
	m_spendTreeControl.InsertItem(strAprFamilySum, 0, 0, aprVar, TVI_LAST);

	strAprStudyVarSum.Format(_T("교육 %d원"), studyAprVarSum);
	m_spendTreeControl.InsertItem(strAprStudyVarSum, 0, 0, aprVar, TVI_LAST);

	strAprTransSum.Format(_T("교통비 %d원"), transAprSum);
	m_spendTreeControl.InsertItem(strAprTransSum, 0, 0, aprVar, TVI_LAST);

	strAprEtcVarSum.Format(_T("기타 %d원"), etcAprVarSum);
	m_spendTreeControl.InsertItem(strAprEtcVarSum, 0, 0, aprVar, TVI_LAST);

	strAprEnjoySum.Format(_T("문화생활 %d원"), enjoyAprSum);
	m_spendTreeControl.InsertItem(strAprEnjoySum, 0, 0, aprVar, TVI_LAST);

	strAprBeautySum.Format(_T("미용 %d원"), beautyAprSum);
	m_spendTreeControl.InsertItem(strAprBeautySum, 0, 0, aprVar, TVI_LAST);

	strAprNecessariesSum.Format(_T("생필품 %d원"), necessariesAprSum);
	m_spendTreeControl.InsertItem(strAprNecessariesSum, 0, 0, aprVar, TVI_LAST);

	strAprFoodSum.Format(_T("식비 %d원"), foodAprSum);
	m_spendTreeControl.InsertItem(strAprFoodSum, 0, 0, aprVar, TVI_LAST);

	strAprMedicalSum.Format(_T("의료 %d원"), medicalAprSum);
	m_spendTreeControl.InsertItem(strAprMedicalSum, 0, 0, aprVar, TVI_LAST);

	strAprClothingSum.Format(_T("의류 %d원"), clothingAprSum);
	m_spendTreeControl.InsertItem(strAprClothingSum, 0, 0, aprVar, TVI_LAST);

	// 5월
	strMayFamilySum.Format(_T("경조사 %d원"), familyMaySum);
	m_spendTreeControl.InsertItem(strMayFamilySum, 0, 0, mayVar, TVI_LAST);

	strMayStudyVarSum.Format(_T("교육 %d원"), studyMayVarSum);
	m_spendTreeControl.InsertItem(strMayStudyVarSum, 0, 0, mayVar, TVI_LAST);

	strMayTransSum.Format(_T("교통비 %d원"), transMaySum);
	m_spendTreeControl.InsertItem(strMayTransSum, 0, 0, mayVar, TVI_LAST);

	strMayEtcVarSum.Format(_T("기타 %d원"), etcMayVarSum);
	m_spendTreeControl.InsertItem(strMayEtcVarSum, 0, 0, mayVar, TVI_LAST);

	strMayEnjoySum.Format(_T("문화생활 %d원"), enjoyMaySum);
	m_spendTreeControl.InsertItem(strMayEnjoySum, 0, 0, mayVar, TVI_LAST);

	strMayBeautySum.Format(_T("미용 %d원"), beautyMaySum);
	m_spendTreeControl.InsertItem(strMayBeautySum, 0, 0, mayVar, TVI_LAST);

	strMayNecessariesSum.Format(_T("생필품 %d원"), necessariesMaySum);
	m_spendTreeControl.InsertItem(strMayNecessariesSum, 0, 0, mayVar, TVI_LAST);

	strMayFoodSum.Format(_T("식비 %d원"), foodMaySum);
	m_spendTreeControl.InsertItem(strMayFoodSum, 0, 0, mayVar, TVI_LAST);

	strMayMedicalSum.Format(_T("의료 %d원"), medicalMaySum);
	m_spendTreeControl.InsertItem(strMayMedicalSum, 0, 0, mayVar, TVI_LAST);

	strMayClothingSum.Format(_T("의류 %d원"), clothingMaySum);
	m_spendTreeControl.InsertItem(strMayClothingSum, 0, 0, mayVar, TVI_LAST);

	// 6월
	strJunFamilySum.Format(_T("경조사 %d원"), familyJunSum);
	m_spendTreeControl.InsertItem(strJunFamilySum, 0, 0, junVar, TVI_LAST);

	strJunStudyVarSum.Format(_T("교육 %d원"), studyJunVarSum);
	m_spendTreeControl.InsertItem(strJunStudyVarSum, 0, 0, junVar, TVI_LAST);

	strJunTransSum.Format(_T("교통비 %d원"), transJunSum);
	m_spendTreeControl.InsertItem(strJunTransSum, 0, 0, junVar, TVI_LAST);

	strJunEtcVarSum.Format(_T("기타 %d원"), etcJunVarSum);
	m_spendTreeControl.InsertItem(strJunEtcVarSum, 0, 0, junVar, TVI_LAST);

	strJunEnjoySum.Format(_T("문화생활 %d원"), enjoyJunSum);
	m_spendTreeControl.InsertItem(strJunEnjoySum, 0, 0, junVar, TVI_LAST);

	strJunBeautySum.Format(_T("미용 %d원"), beautyJunSum);
	m_spendTreeControl.InsertItem(strJunBeautySum, 0, 0, junVar, TVI_LAST);

	strJunNecessariesSum.Format(_T("생필품 %d원"), necessariesJunSum);
	m_spendTreeControl.InsertItem(strJunNecessariesSum, 0, 0, junVar, TVI_LAST);

	strJunFoodSum.Format(_T("식비 %d원"), foodJunSum);
	m_spendTreeControl.InsertItem(strJunFoodSum, 0, 0, junVar, TVI_LAST);

	strJunMedicalSum.Format(_T("의료 %d원"), medicalJunSum);
	m_spendTreeControl.InsertItem(strJunMedicalSum, 0, 0, junVar, TVI_LAST);

	strJunClothingSum.Format(_T("의류 %d원"), clothingJunSum);
	m_spendTreeControl.InsertItem(strJunClothingSum, 0, 0, junVar, TVI_LAST);

	// 7월
	strJulFamilySum.Format(_T("경조사 %d원"), familyJulSum);
	m_spendTreeControl.InsertItem(strJulFamilySum, 0, 0, julVar, TVI_LAST);

	strJulStudyVarSum.Format(_T("교육 %d원"), studyJulVarSum);
	m_spendTreeControl.InsertItem(strJulStudyVarSum, 0, 0, julVar, TVI_LAST);

	strJulTransSum.Format(_T("교통비 %d원"), transJulSum);
	m_spendTreeControl.InsertItem(strJulTransSum, 0, 0, julVar, TVI_LAST);

	strJulEtcVarSum.Format(_T("기타 %d원"), etcJulVarSum);
	m_spendTreeControl.InsertItem(strJulEtcVarSum, 0, 0, julVar, TVI_LAST);

	strJulEnjoySum.Format(_T("문화생활 %d원"), enjoyJulSum);
	m_spendTreeControl.InsertItem(strJulEnjoySum, 0, 0, julVar, TVI_LAST);

	strJulBeautySum.Format(_T("미용 %d원"), beautyJulSum);
	m_spendTreeControl.InsertItem(strJulBeautySum, 0, 0, julVar, TVI_LAST);

	strJulNecessariesSum.Format(_T("생필품 %d원"), necessariesJulSum);
	m_spendTreeControl.InsertItem(strJulNecessariesSum, 0, 0, julVar, TVI_LAST);

	strJulFoodSum.Format(_T("식비 %d원"), foodJulSum);
	m_spendTreeControl.InsertItem(strJulFoodSum, 0, 0, julVar, TVI_LAST);

	strJulMedicalSum.Format(_T("의료 %d원"), medicalJulSum);
	m_spendTreeControl.InsertItem(strJulMedicalSum, 0, 0, julVar, TVI_LAST);

	strJulClothingSum.Format(_T("의류 %d원"), clothingJulSum);
	m_spendTreeControl.InsertItem(strJulClothingSum, 0, 0, julVar, TVI_LAST);

	// 8월
	strAugFamilySum.Format(_T("경조사 %d원"), familyAugSum);
	m_spendTreeControl.InsertItem(strAugFamilySum, 0, 0, augVar, TVI_LAST);

	strAugStudyVarSum.Format(_T("교육 %d원"), studyAugVarSum);
	m_spendTreeControl.InsertItem(strAugStudyVarSum, 0, 0, augVar, TVI_LAST);

	strAugTransSum.Format(_T("교통비 %d원"), transAugSum);
	m_spendTreeControl.InsertItem(strAugTransSum, 0, 0, augVar, TVI_LAST);

	strAugEtcVarSum.Format(_T("기타 %d원"), etcAugVarSum);
	m_spendTreeControl.InsertItem(strAugEtcVarSum, 0, 0, augVar, TVI_LAST);

	strAugEnjoySum.Format(_T("문화생활 %d원"), enjoyAugSum);
	m_spendTreeControl.InsertItem(strAugEnjoySum, 0, 0, augVar, TVI_LAST);

	strAugBeautySum.Format(_T("미용 %d원"), beautyAugSum);
	m_spendTreeControl.InsertItem(strAugBeautySum, 0, 0, augVar, TVI_LAST);

	strAugNecessariesSum.Format(_T("생필품 %d원"), necessariesAugSum);
	m_spendTreeControl.InsertItem(strAugNecessariesSum, 0, 0, augVar, TVI_LAST);

	strAugFoodSum.Format(_T("식비 %d원"), foodAugSum);
	m_spendTreeControl.InsertItem(strAugFoodSum, 0, 0, augVar, TVI_LAST);

	strAugMedicalSum.Format(_T("의료 %d원"), medicalAugSum);
	m_spendTreeControl.InsertItem(strAugMedicalSum, 0, 0, augVar, TVI_LAST);

	strAugClothingSum.Format(_T("의류 %d원"), clothingAugSum);
	m_spendTreeControl.InsertItem(strAugClothingSum, 0, 0, augVar, TVI_LAST);

	// 9월
	strSepFamilySum.Format(_T("경조사 %d원"), familySepSum);
	m_spendTreeControl.InsertItem(strSepFamilySum, 0, 0, sepVar, TVI_LAST);

	strSepStudyVarSum.Format(_T("교육 %d원"), studySepVarSum);
	m_spendTreeControl.InsertItem(strSepStudyVarSum, 0, 0, sepVar, TVI_LAST);

	strSepTransSum.Format(_T("교통비 %d원"), transSepSum);
	m_spendTreeControl.InsertItem(strSepTransSum, 0, 0, sepVar, TVI_LAST);

	strSepEtcVarSum.Format(_T("기타 %d원"), etcSepVarSum);
	m_spendTreeControl.InsertItem(strSepEtcVarSum, 0, 0, sepVar, TVI_LAST);

	strSepEnjoySum.Format(_T("문화생활 %d원"), enjoySepSum);
	m_spendTreeControl.InsertItem(strSepEnjoySum, 0, 0, sepVar, TVI_LAST);

	strSepBeautySum.Format(_T("미용 %d원"), beautySepSum);
	m_spendTreeControl.InsertItem(strSepBeautySum, 0, 0, sepVar, TVI_LAST);

	strSepNecessariesSum.Format(_T("생필품 %d원"), necessariesSepSum);
	m_spendTreeControl.InsertItem(strSepNecessariesSum, 0, 0, sepVar, TVI_LAST);

	strSepFoodSum.Format(_T("식비 %d원"), foodSepSum);
	m_spendTreeControl.InsertItem(strSepFoodSum, 0, 0, sepVar, TVI_LAST);

	strSepMedicalSum.Format(_T("의료 %d원"), medicalSepSum);
	m_spendTreeControl.InsertItem(strSepMedicalSum, 0, 0, sepVar, TVI_LAST);

	strSepClothingSum.Format(_T("의류 %d원"), clothingSepSum);
	m_spendTreeControl.InsertItem(strSepClothingSum, 0, 0, sepVar, TVI_LAST);

	// 10월
	strOctFamilySum.Format(_T("경조사 %d원"), familyOctSum);
	m_spendTreeControl.InsertItem(strOctFamilySum, 0, 0, octVar, TVI_LAST);

	strOctStudyVarSum.Format(_T("교육 %d원"), studyOctVarSum);
	m_spendTreeControl.InsertItem(strOctStudyVarSum, 0, 0, octVar, TVI_LAST);

	strOctTransSum.Format(_T("교통비 %d원"), transOctSum);
	m_spendTreeControl.InsertItem(strOctTransSum, 0, 0, octVar, TVI_LAST);

	strOctEtcVarSum.Format(_T("기타 %d원"), etcOctVarSum);
	m_spendTreeControl.InsertItem(strOctEtcVarSum, 0, 0, octVar, TVI_LAST);

	strOctEnjoySum.Format(_T("문화생활 %d원"), enjoyOctSum);
	m_spendTreeControl.InsertItem(strOctEnjoySum, 0, 0, octVar, TVI_LAST);

	strOctBeautySum.Format(_T("미용 %d원"), beautyOctSum);
	m_spendTreeControl.InsertItem(strOctBeautySum, 0, 0, octVar, TVI_LAST);

	strOctNecessariesSum.Format(_T("생필품 %d원"), necessariesOctSum);
	m_spendTreeControl.InsertItem(strOctNecessariesSum, 0, 0, octVar, TVI_LAST);

	strOctFoodSum.Format(_T("식비 %d원"), foodOctSum);
	m_spendTreeControl.InsertItem(strOctFoodSum, 0, 0, octVar, TVI_LAST);

	strOctMedicalSum.Format(_T("의료 %d원"), medicalOctSum);
	m_spendTreeControl.InsertItem(strOctMedicalSum, 0, 0, octVar, TVI_LAST);

	strOctClothingSum.Format(_T("의류 %d원"), clothingOctSum);
	m_spendTreeControl.InsertItem(strOctClothingSum, 0, 0, octVar, TVI_LAST);

	// 11월
	strNovFamilySum.Format(_T("경조사 %d원"), familyNovSum);
	m_spendTreeControl.InsertItem(strNovFamilySum, 0, 0, novVar, TVI_LAST);

	strNovStudyVarSum.Format(_T("교육 %d원"), studyNovVarSum);
	m_spendTreeControl.InsertItem(strNovStudyVarSum, 0, 0, novVar, TVI_LAST);

	strNovTransSum.Format(_T("교통비 %d원"), transNovSum);
	m_spendTreeControl.InsertItem(strNovTransSum, 0, 0, novVar, TVI_LAST);

	strNovEtcVarSum.Format(_T("기타 %d원"), etcNovVarSum);
	m_spendTreeControl.InsertItem(strNovEtcVarSum, 0, 0, novVar, TVI_LAST);

	strNovEnjoySum.Format(_T("문화생활 %d원"), enjoyNovSum);
	m_spendTreeControl.InsertItem(strNovEnjoySum, 0, 0, novVar, TVI_LAST);

	strNovBeautySum.Format(_T("미용 %d원"), beautyNovSum);
	m_spendTreeControl.InsertItem(strNovBeautySum, 0, 0, novVar, TVI_LAST);

	strNovNecessariesSum.Format(_T("생필품 %d원"), necessariesNovSum);
	m_spendTreeControl.InsertItem(strNovNecessariesSum, 0, 0, novVar, TVI_LAST);

	strNovFoodSum.Format(_T("식비 %d원"), foodNovSum);
	m_spendTreeControl.InsertItem(strNovFoodSum, 0, 0, novVar, TVI_LAST);

	strNovMedicalSum.Format(_T("의료 %d원"), medicalNovSum);
	m_spendTreeControl.InsertItem(strNovMedicalSum, 0, 0, novVar, TVI_LAST);

	strNovClothingSum.Format(_T("의류 %d원"), clothingNovSum);
	m_spendTreeControl.InsertItem(strNovClothingSum, 0, 0, novVar, TVI_LAST);

	// 12월
	strDecFamilySum.Format(_T("경조사 %d원"), familyDecSum);
	m_spendTreeControl.InsertItem(strDecFamilySum, 0, 0, decVar, TVI_LAST);

	strDecStudyVarSum.Format(_T("교육 %d원"), studyDecVarSum);
	m_spendTreeControl.InsertItem(strDecStudyVarSum, 0, 0, decVar, TVI_LAST);

	strDecTransSum.Format(_T("교통비 %d원"), transDecSum);
	m_spendTreeControl.InsertItem(strDecTransSum, 0, 0, decVar, TVI_LAST);

	strDecEtcVarSum.Format(_T("기타 %d원"), etcDecVarSum);
	m_spendTreeControl.InsertItem(strDecEtcVarSum, 0, 0, decVar, TVI_LAST);

	strDecEnjoySum.Format(_T("문화생활 %d원"), enjoyDecSum);
	m_spendTreeControl.InsertItem(strDecEnjoySum, 0, 0, decVar, TVI_LAST);

	strDecBeautySum.Format(_T("미용 %d원"), beautyDecSum);
	m_spendTreeControl.InsertItem(strDecBeautySum, 0, 0, decVar, TVI_LAST);

	strDecNecessariesSum.Format(_T("생필품 %d원"), necessariesDecSum);
	m_spendTreeControl.InsertItem(strDecNecessariesSum, 0, 0, decVar, TVI_LAST);

	strDecFoodSum.Format(_T("식비 %d원"), foodDecSum);
	m_spendTreeControl.InsertItem(strDecFoodSum, 0, 0, decVar, TVI_LAST);

	strDecMedicalSum.Format(_T("의료 %d원"), medicalDecSum);
	m_spendTreeControl.InsertItem(strDecMedicalSum, 0, 0, decVar, TVI_LAST);

	strDecClothingSum.Format(_T("의류 %d원"), clothingDecSum);
	m_spendTreeControl.InsertItem(strDecClothingSum, 0, 0, decVar, TVI_LAST);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}