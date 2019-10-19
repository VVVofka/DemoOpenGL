; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPropDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "OG.h"
LastPage=0

ClassCount=6
Class1=COGApp
Class2=COGDoc
Class3=COGView
Class4=CMainFrame

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Resource3=IDR_MAINFRAME (English (U.S.))
Resource4=IDD_ABOUTBOX (English (U.S.))
Class6=CPropDlg
Resource5=IDD_PROP (English (U.S.))

[CLS:COGApp]
Type=0
HeaderFile=OG.h
ImplementationFile=OG.cpp
Filter=N

[CLS:COGDoc]
Type=0
HeaderFile=OGDoc.h
ImplementationFile=OGDoc.cpp
Filter=N

[CLS:COGView]
Type=0
HeaderFile=OGView.h
ImplementationFile=OGView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=OG.cpp
ImplementationFile=OG.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
CommandCount=16
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command16=ID_APP_ABOUT

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
CommandCount=14
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE


[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_VIEW_FILL
Command5=ID_VIEW_QUAD
Command6=ID_APP_ABOUT
Command7=ID_EDIT_PROP
Command8=ID_EDIT_BACKGROUND
CommandCount=8

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_EDIT_PROP
Command8=ID_EDIT_BACKGROUND
Command9=ID_VIEW_TOOLBAR
Command10=ID_VIEW_STATUS_BAR
Command11=ID_VIEW_FILL
Command12=ID_VIEW_QUAD
Command13=ID_APP_ABOUT
CommandCount=13

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PROP (English (U.S.))]
Type=1
Class=CPropDlg
ControlCount=37
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,button,1342177287
Control8=IDC_STATIC,button,1342177287
Control9=IDC_STATIC,static,1342308352
Control10=IDC_AMB_TEXT,static,1342308865
Control11=IDC_DIFFUSE_TEXT,static,1342308865
Control12=IDC_SPECULAR_TEXT,static,1342308865
Control13=IDC_XPOS_TEXT,static,1342308865
Control14=IDC_YPOS_TEXT,static,1342308865
Control15=IDC_ZPOS_TEXT,static,1342308865
Control16=IDC_FILENAME,button,1342242816
Control17=IDC_AMBIENT,msctls_trackbar32,1342242840
Control18=IDC_DIFFUSE,msctls_trackbar32,1342242840
Control19=IDC_SPECULAR,msctls_trackbar32,1342242840
Control20=IDC_SHINE,msctls_trackbar32,1342242840
Control21=IDC_XPOS,msctls_trackbar32,1342242840
Control22=IDC_YPOS,msctls_trackbar32,1342242840
Control23=IDC_ZPOS,msctls_trackbar32,1342242840
Control24=IDC_STATIC,static,1342308352
Control25=IDC_STATIC,static,1342308352
Control26=IDC_STATIC,static,1342308352
Control27=IDC_STATIC,button,1342177287
Control28=IDC_AMBMAT_TEXT,static,1342308865
Control29=IDC_DIFFMAT_TEXT,static,1342308865
Control30=IDC_SPECMAT_TEXT,static,1342308865
Control31=IDC_AMBMAT,msctls_trackbar32,1342242840
Control32=IDC_DIFFMAT,msctls_trackbar32,1342242840
Control33=IDC_SPECMAT,msctls_trackbar32,1342242840
Control34=IDC_SHINE_TEXT,static,1342308865
Control35=IDC_STATIC,static,1342308352
Control36=IDC_EMISSION,msctls_trackbar32,1342242840
Control37=IDC_EMISSION_TEXT,static,1342308865

[CLS:CPropDlg]
Type=0
HeaderFile=PropDlg.h
ImplementationFile=PropDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CPropDlg
VirtualFilter=dWC

