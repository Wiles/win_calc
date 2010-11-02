// win_calc_mfcDlg.h : header file
//

#pragma once


// Cwin_calc_mfcDlg dialog
class Cwin_calc_mfcDlg : public CDialog
{
// Construction
public:
	Cwin_calc_mfcDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_WIN_CALC_MFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void SetBinary();
	afx_msg void SetDecimal();
	afx_msg void SetHexadecimal();
	afx_msg void AppendNumber(TCHAR *str);

	afx_msg void OnBnClickedBase10();
	afx_msg void OnBnClickedBase2();
	afx_msg void OnBnClickedBase16();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonCe();
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButtonA();
	afx_msg void OnBnClickedButtonB();
	afx_msg void OnBnClickedButtonC();
	afx_msg void OnBnClickedButtonD();
	afx_msg void OnBnClickedButtonE();
	afx_msg void OnBnClickedButtonF();

private:
	int current_base;
public:
	afx_msg void OnBnClickedButtonSign();
};
