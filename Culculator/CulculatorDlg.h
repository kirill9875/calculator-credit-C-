
// CulculatorDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CCulculatorDlg
class CCulculatorDlg : public CDialog
{
// Создание
public:
	CCulculatorDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CULCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	int SUMM;
	int TIME;
	double PROC;
	int TYPE;
	afx_msg void OnCbnSelchangeCombo1();
};
