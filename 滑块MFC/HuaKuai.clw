; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CHuaKuaiView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "HuaKuai.h"
LastPage=0

ClassCount=5
Class1=CHuaKuaiApp
Class2=CHuaKuaiDoc
Class3=CHuaKuaiView
Class4=CMainFrame

ResourceCount=2
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX

[CLS:CHuaKuaiApp]
Type=0
HeaderFile=HuaKuai.h
ImplementationFile=HuaKuai.cpp
Filter=N

[CLS:CHuaKuaiDoc]
Type=0
HeaderFile=HuaKuaiDoc.h
ImplementationFile=HuaKuaiDoc.cpp
Filter=N

[CLS:CHuaKuaiView]
Type=0
HeaderFile=HuaKuaiView.h
ImplementationFile=HuaKuaiView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_STOP


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_BEGIN




[CLS:CAboutDlg]
Type=0
HeaderFile=HuaKuai.cpp
ImplementationFile=HuaKuai.cpp
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
Command1=ID_BEGIN
Command2=ID_STOP
Command3=ID_APP_ABOUT
CommandCount=3

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

