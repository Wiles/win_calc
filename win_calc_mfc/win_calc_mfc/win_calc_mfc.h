// win_calc_mfc.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Cwin_calc_mfcApp:
// See win_calc_mfc.cpp for the implementation of this class
//

class Cwin_calc_mfcApp : public CWinApp
{
public:
	Cwin_calc_mfcApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Cwin_calc_mfcApp theApp;