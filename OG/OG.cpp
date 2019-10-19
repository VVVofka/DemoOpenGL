#include "stdafx.h"
#include "OG.h"
#include "MainFrm.h"
#include "OGDoc.h"
#include "OGView.h"

BEGIN_MESSAGE_MAP(COGApp, CWinApp)
	//{{AFX_MSG_MAP(COGApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

COGApp::COGApp(){}
COGApp theApp;

#pragma warning(push)
#pragma warning(disable : 6031 26451) 

BOOL COGApp::InitInstance()
{
	//Enable3dControls();
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(COGDoc),
		RUNTIME_CLASS(CMainFrame),
		RUNTIME_CLASS(COGView));
	AddDocTemplate(pDocTemplate);

	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}

void COGApp::OnAppAbout()
{
	CDialog(IDD_ABOUTBOX).DoModal();
}

#pragma warning(pop)
