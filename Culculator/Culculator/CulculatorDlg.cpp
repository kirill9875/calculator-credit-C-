
// CulculatorDlg.cpp: файл реализации
//

#include "stdafx.h"
#include "Culculator.h"
#include "CulculatorDlg.h"
#include "afxdialogex.h"
#include <string>
#include <stdlib.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
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


// Диалоговое окно CCulculatorDlg



CCulculatorDlg::CCulculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_CULCULATOR_DIALOG, pParent)
	, SUMM()
	, TIME()
	, PROC()
	, TYPE()
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCulculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SUMM, SUMM);
	DDX_Text(pDX, IDC_EDIT_TIME, TIME);
	DDX_Text(pDX, IDC_EDIT_PROC, PROC);
	DDX_CBIndex(pDX, IDC_COMBO3, TYPE);
}

BEGIN_MESSAGE_MAP(CCulculatorDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CCulculatorDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CCulculatorDlg::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT_SUMM, &CCulculatorDlg::OnEnChangeEditSumm)
	ON_STN_CLICKED(IDB_BITMAP_FON, &CCulculatorDlg::OnStnClickedBitmapFon)
END_MESSAGE_MAP()


// Обработчики сообщений CCulculatorDlg

BOOL CCulculatorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	
	//Тип кредита
	CComboBox* pBox = static_cast<CComboBox*>(GetDlgItem(IDC_COMBO3));

	pBox->AddString(L"Аннуитетный");
	pBox->AddString(L"Дифференцированный");

	pBox->SetCurSel(0);
	//месяц
	CComboBox* pBox2 = static_cast<CComboBox*>(GetDlgItem(IDC_COMBO4));

	pBox2->AddString(L"Январь");
	pBox2->AddString(L"Февраль");
	pBox2->AddString(L"Март");
	pBox2->AddString(L"Апрель");
	pBox2->AddString(L"Май");
	pBox2->AddString(L"Июнь");
	pBox2->AddString(L"Июль");
	pBox2->AddString(L"Август");
	pBox2->AddString(L"Сентябрь");
	pBox2->AddString(L"Октябрь");
	pBox2->AddString(L"Ноябрь");
	pBox2->AddString(L"Декабрь");
	
	pBox2->SetCurSel(0);

	//год
	CComboBox* pBox3 = static_cast<CComboBox*>(GetDlgItem(IDC_COMBO5));
	CString s;
	for (int i = 2017; i < 2057; i++) {
		s.Format(_T("%d"),i);
		pBox3->AddString(s);
	}

	pBox3->SetCurSel(0);

	pBox->SetCurSel(0);
	return TRUE;



	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CCulculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CCulculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CCulculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCulculatorDlg::OnBnClickedOk()
{
	UpdateData();
	int time = TIME,
	type = TYPE;
	double proc = PROC,
		   summ = (double)SUMM,
		   ocdo,
		   napr,
		   summp;
	
	CString **mass = new CString*[time + 1];
	for (int i = 0; i < time + 1; i++)
	{
		mass[i] = new CString[5];
	}
	CString text;
	mass[0][0] = _T("№");
	mass[0][1] = _T("Задолженость");
	mass[0][2] = _T("Проценты");
	mass[0][3] = _T("Долг");
	mass[0][4] = _T("Сумма платежа");
	text = mass[0][0] + _T("   ") + mass[0][1] + _T("   ") + mass[0][2] + _T("   ") + mass[0][3] + _T("   ") + mass[0][4] + _T("\n");
	
	
	if (type == 0){
		summp = ((summ * proc/100.0/12.0) / (1-pow((1+proc/100.0/12.0),(-time))));
		for (int i = 0; i < time; i++) {
			napr = summ * proc / 100.0 / 12.0;
			ocdo = summp - napr;
			mass[i + 1][0].Format(_T("%3d"), i + 1);
			mass[i + 1][1].Format(_T("%8.2lf"), summ);
			mass[i + 1][2].Format(_T(" %8.2lf"), napr);
			mass[i + 1][3].Format(_T("  %8.2lf"), ocdo);
			mass[i + 1][4].Format(_T("  %8.2lf"), summp);
			text += mass[i + 1][0] + _T("   ") + mass[i + 1][1] + _T("      ") + mass[i + 1][2] + _T("       ") + mass[i + 1][3] + _T("         ") + mass[i + 1][4] + _T("\n");
			summ -= ocdo;
		}
	}else {
		ocdo = (double)summ / (double)time;

		for (int i = 0; i < time; i++) {
			napr = summ * proc / 100.0 / 12.0;
			summp = napr + ocdo;
			mass[i + 1][0].Format(_T("%3d"), i + 1);
			mass[i + 1][1].Format(_T("%8.2lf"), summ);
			mass[i + 1][2].Format(_T("%8.2lf"), napr);
			mass[i + 1][3].Format(_T("%8.2lf"), ocdo);
			mass[i + 1][4].Format(_T("%8.2lf"), summp);
			text += mass[i + 1][0] + _T("   ") + mass[i + 1][1] + _T("       ") + mass[i + 1][2] + _T("     ") + mass[i + 1][3] + _T("      ") + mass[i + 1][4] + _T("\n");
			summ -= ocdo;
		}
	}
	MessageBox(text, _T("Result!"));
}


void CCulculatorDlg::OnBnClickedCancel()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialog::OnCancel();
}


void CCulculatorDlg::OnEnChangeEditSumm()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


void CCulculatorDlg::OnStnClickedBitmapFon()
{
	// TODO: добавьте свой код обработчика уведомлений
}
