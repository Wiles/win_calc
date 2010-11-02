// win_calc_mfcDlg.cpp : implementation file
//

#include "stdafx.h"
#include "win_calc_mfc.h"
#include "win_calc_mfcDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// makes finding errors SO MUCH EASIER!!!
#pragma warning (disable:4996)


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// Cwin_calc_mfcDlg dialog




Cwin_calc_mfcDlg::Cwin_calc_mfcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(Cwin_calc_mfcDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cwin_calc_mfcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cwin_calc_mfcDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BASE_10, &Cwin_calc_mfcDlg::OnBnClickedBase10)
	ON_BN_CLICKED(IDC_BASE_2, &Cwin_calc_mfcDlg::OnBnClickedBase2)
	ON_BN_CLICKED(IDC_BASE_16, &Cwin_calc_mfcDlg::OnBnClickedBase16)
	ON_BN_CLICKED(IDC_BUTTON_0, &Cwin_calc_mfcDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_1, &Cwin_calc_mfcDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_CE, &Cwin_calc_mfcDlg::OnBnClickedButtonCe)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &Cwin_calc_mfcDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_2, &Cwin_calc_mfcDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &Cwin_calc_mfcDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &Cwin_calc_mfcDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &Cwin_calc_mfcDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &Cwin_calc_mfcDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &Cwin_calc_mfcDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &Cwin_calc_mfcDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &Cwin_calc_mfcDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_A, &Cwin_calc_mfcDlg::OnBnClickedButtonA)
	ON_BN_CLICKED(IDC_BUTTON_B, &Cwin_calc_mfcDlg::OnBnClickedButtonB)
	ON_BN_CLICKED(IDC_BUTTON_C, &Cwin_calc_mfcDlg::OnBnClickedButtonC)
	ON_BN_CLICKED(IDC_BUTTON_D, &Cwin_calc_mfcDlg::OnBnClickedButtonD)
	ON_BN_CLICKED(IDC_BUTTON_E, &Cwin_calc_mfcDlg::OnBnClickedButtonE)
	ON_BN_CLICKED(IDC_BUTTON_F, &Cwin_calc_mfcDlg::OnBnClickedButtonF)
	ON_BN_CLICKED(IDC_BUTTON_SIGN, &Cwin_calc_mfcDlg::OnBnClickedButtonSign)
END_MESSAGE_MAP()


// Cwin_calc_mfcDlg message handlers

BOOL Cwin_calc_mfcDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	((CButton*)GetDlgItem(IDC_BASE_10))->SetCheck(1);
	((CEdit*)GetDlgItem(IDC_EDIT))->SetWindowTextW(_T("0"));
	SetDecimal();
	current_base = 10;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Cwin_calc_mfcDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Cwin_calc_mfcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Cwin_calc_mfcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cwin_calc_mfcDlg::SetBinary()
{
	((CButton*)GetDlgItem(IDC_BUTTON_2))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_BUTTON_3))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_BUTTON_4))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_BUTTON_5))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_BUTTON_6))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_BUTTON_7))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_BUTTON_8))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_BUTTON_9))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_BUTTON_A))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_BUTTON_B))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_BUTTON_C))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_BUTTON_D))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_BUTTON_E))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_BUTTON_F))->EnableWindow(FALSE);
}



void Cwin_calc_mfcDlg::SetDecimal()
{
	((CButton*)GetDlgItem(IDC_BUTTON_2))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_BUTTON_3))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_BUTTON_4))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_BUTTON_5))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_BUTTON_6))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_BUTTON_7))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_BUTTON_8))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_BUTTON_9))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_BUTTON_A))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_BUTTON_B))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_BUTTON_C))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_BUTTON_D))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_BUTTON_E))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_BUTTON_F))->EnableWindow(FALSE);
}



void Cwin_calc_mfcDlg::SetHexadecimal()
{
	((CButton*)GetDlgItem(IDC_BUTTON_2))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_BUTTON_3))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_BUTTON_4))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_BUTTON_5))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_BUTTON_6))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_BUTTON_7))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_BUTTON_8))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_BUTTON_9))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_BUTTON_A))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_BUTTON_B))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_BUTTON_C))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_BUTTON_D))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_BUTTON_E))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_BUTTON_F))->EnableWindow(TRUE);
}



void Cwin_calc_mfcDlg::AppendNumber(TCHAR *str)
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT);
	TCHAR edit[512];
	pEdit->GetWindowTextW(edit, ((sizeof edit) -1 ));
	if (wcscmp(edit, _T("0")) != 0)
	{
		wcscat(edit, str);
		pEdit->SetWindowTextW(edit);
	}
	else
	{
	// if the current value is zero, replace it with a number!
		pEdit->SetWindowTextW(str);
	}
}



void Cwin_calc_mfcDlg::OnBnClickedBase10()
{
	// TODO: Add your control notification handler code here
	SetDecimal();
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT);
	TCHAR edit[512];
	int n = 414;
	TCHAR value[512];
	pEdit->GetWindowTextW(edit, ((sizeof edit) -1 ));
	n = wcstol(edit, NULL, current_base);
	swprintf(value, ((sizeof value) - 1), _T("%d"), n);
	pEdit->SetWindowTextW(value);
	current_base = 10;
}

void Cwin_calc_mfcDlg::OnBnClickedBase2()
{
	// TODO: Add your control notification handler code here
	SetBinary();
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT);
	TCHAR edit[512];
	int n = 0;
	int i = 0;
	TCHAR value[512];
	wcscpy(value, _T(""));
	// copy string into edit
	pEdit->GetWindowTextW(edit, ((sizeof edit) -1 ));
	// convert edit into integer
	n = wcstol(edit, NULL, current_base);
	// move integer into edit, as a hex
	if (n < 0)
	{
		n *= -1;
		swprintf(edit, ((sizeof edit) - 1), _T("-%X"), n);
	}
	else
	{
		swprintf(edit, ((sizeof edit) - 1), _T("%X"), n);
	}

	// break down the hex value into a binary number!
	while(edit[i] != '\0')
	{
		switch (edit[i])
		{
		case '-':
			wcscat(value, _T("-"));
			break;

		case '0':
			wcscat(value, _T("0000"));
			break;

		case '1':
			wcscat(value, _T("0001"));
			break;

		case '2':
			wcscat(value, _T("0010"));
			break;

		case '3':
			wcscat(value, _T("0011"));
			break;

		case '4':
			wcscat(value, _T("0100"));
			break;

		case '5':
			wcscat(value, _T("0101"));
			break;

		case '6':
			wcscat(value, _T("0110"));
			break;

		case '7':
			wcscat(value, _T("0111"));
			break;

		case '8':
			wcscat(value, _T("1000"));
			break;

		case '9':
			wcscat(value, _T("1001"));
			break;

		case 'A':
			wcscat(value, _T("1010"));
			break;

		case 'B':
			wcscat(value, _T("1011"));
			break;

		case 'C':
			wcscat(value, _T("1100"));
			break;

		case 'D':
			wcscat(value, _T("1101"));
			break;

		case 'E':
			wcscat(value, _T("1110"));
			break;

		case 'F':
			wcscat(value, _T("1111"));
			break;
		}
		i++;
	}

	// output the new string!
	pEdit->SetWindowTextW(value);
	current_base = 2;
}

void Cwin_calc_mfcDlg::OnBnClickedBase16()
{
	// TODO: Add your control notification handler code here
	SetHexadecimal();
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT);
	TCHAR edit[512];
	int n = 414;
	TCHAR value[512];
	pEdit->GetWindowTextW(edit, ((sizeof edit) -1 ));
	n = wcstol(edit, NULL, current_base);
	if (n < 0)
	{
		n *= -1;
		swprintf(value, ((sizeof value) - 1), _T("-%X"), n);
	}
	else
	{
		swprintf(value, ((sizeof value) - 1), _T("%X"), n);
	}
	pEdit->SetWindowTextW(value);
	current_base = 16;
}

void Cwin_calc_mfcDlg::OnBnClickedButtonCe()
{
	// TODO: Add your control notification handler code here
	((CEdit*)GetDlgItem(IDC_EDIT))->SetWindowTextW(_T("0"));
}

void Cwin_calc_mfcDlg::OnBnClickedButtonClear()
{
	// TODO: Add your control notification handler code here
	((CEdit*)GetDlgItem(IDC_EDIT))->SetWindowTextW(_T("0"));
}

void Cwin_calc_mfcDlg::OnBnClickedButton0()
{
	// TODO: Add your control notification handler code here
	AppendNumber(_T("0"));
}

void Cwin_calc_mfcDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	AppendNumber(_T("1"));
}

void Cwin_calc_mfcDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	AppendNumber(_T("2"));
}

void Cwin_calc_mfcDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	AppendNumber(_T("3"));
	
}

void Cwin_calc_mfcDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	AppendNumber(_T("4"));
}

void Cwin_calc_mfcDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	AppendNumber(_T("5"));
}

void Cwin_calc_mfcDlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
	AppendNumber(_T("6"));
}

void Cwin_calc_mfcDlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here
	AppendNumber(_T("7"));
}

void Cwin_calc_mfcDlg::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here
	AppendNumber(_T("8"));
}

void Cwin_calc_mfcDlg::OnBnClickedButton9()
{
	// TODO: Add your control notification handler code here
	AppendNumber(_T("9"));
}

void Cwin_calc_mfcDlg::OnBnClickedButtonA()
{
	// TODO: Add your control notification handler code here
	AppendNumber(_T("A"));
}

void Cwin_calc_mfcDlg::OnBnClickedButtonB()
{
	// TODO: Add your control notification handler code here
	AppendNumber(_T("B"));
}

void Cwin_calc_mfcDlg::OnBnClickedButtonC()
{
	// TODO: Add your control notification handler code here
	AppendNumber(_T("C"));
}

void Cwin_calc_mfcDlg::OnBnClickedButtonD()
{
	// TODO: Add your control notification handler code here
	AppendNumber(_T("D"));
}

void Cwin_calc_mfcDlg::OnBnClickedButtonE()
{
	// TODO: Add your control notification handler code here
	AppendNumber(_T("E"));
}

void Cwin_calc_mfcDlg::OnBnClickedButtonF()
{
	// TODO: Add your control notification handler code here
	AppendNumber(_T("F"));
}

void Cwin_calc_mfcDlg::OnBnClickedButtonSign()
{
	// TODO: Add your control notification handler code here
	TCHAR edit[512];
	TCHAR *pChar = edit;
	TCHAR value[512];
	wcscpy(value, _T("\0\0\0\0\0\0\0\0\0\0"));
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT);
	pEdit->GetWindowTextW(edit, ((sizeof edit) - 1));
	// if number is negative, switch to positive
	if (edit[0] == '-')
	{
		pChar++;
		pEdit->SetWindowTextW(pChar);
	}
	// otherwise, do something completely different...
	else
	{
		wcscat(value, _T("-"));
		wcscat(value, edit);
		pEdit->SetWindowTextW(value);
	}

}
