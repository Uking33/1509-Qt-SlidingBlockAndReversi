; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CBlackAndWhiteView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "BlackAndWhite.h"
LastPage=0

ClassCount=5
Class1=CBlackAndWhiteApp
Class2=CBlackAndWhiteDoc
Class3=CBlackAndWhiteView
Class4=CMainFrame

ResourceCount=2
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX

[CLS:CBlackAndWhiteApp]
Type=0
HeaderFile=BlackAndWhite.h
ImplementationFile=BlackAndWhite.cpp
Filter=N

[CLS:CBlackAndWhiteDoc]
Type=0
HeaderFile=BlackAndWhiteDoc.h
ImplementationFile=BlackAndWhiteDoc.cpp
Filter=N

[CLS:CBlackAndWhiteView]
Type=0
HeaderFile=BlackAndWhiteView.h
ImplementationFile=BlackAndWhiteView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_PTP


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_PTC_WHITE




[CLS:CAboutDlg]
Type=0
HeaderFile=BlackAndWhite.cpp
ImplementationFile=BlackAndWhite.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_PTP
Command2=ID_PTC_BLACK
Command3=ID_PTC_WHITE
Command4=ID_APP_ABOUT
CommandCount=4

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
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

