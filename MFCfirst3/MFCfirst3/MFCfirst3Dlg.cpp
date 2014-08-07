
// MFCfirst3Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCfirst3.h"
#include "MFCfirst3Dlg.h"
#include "afxdialogex.h"
#include <WinBase.h>

#include <string.h>

//#include "first3.h"

#define BFLEN 256

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//#pragma comment(lib,"first3.lib")

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32772();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_COMMAND(ID_32772, &CAboutDlg::On32772)
END_MESSAGE_MAP()


// CMFCfirst3Dlg 对话框




CMFCfirst3Dlg::CMFCfirst3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCfirst3Dlg::IDD, pParent)
	, iPartValue(-1)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	InputPath = _T("");
}

void CMFCfirst3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_RADIO1, iPartValue);
	DDX_Radio(pDX, IDC_RADIO1, iPartValue);
}

BEGIN_MESSAGE_MAP(CMFCfirst3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCfirst3Dlg::OnBnClickedButton1)
//	ON_BN_CLICKED(IDC_RADIO1, &CMFCfirst3Dlg::OnBnClickedRadio1)
ON_COMMAND(ID_32771, &CMFCfirst3Dlg::On32771)
//ON_WM_TIMER()
ON_WM_TIMER()
END_MESSAGE_MAP()


// CMFCfirst3Dlg 消息处理程序

BOOL CMFCfirst3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	//判断分割模板文件是否存在
	GetDlgItem(IDC_RADIO1)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO2)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO3)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO4)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO5)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO6)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO7)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO8)->EnableWindow(FALSE);
	CFileFind FindFile1;
	CString FilePath1 = "models_336_bin\\intref_thal\\L_Hipp.bmv";
	if(FindFile1.FindFile(FilePath1))
	{
		GetDlgItem(IDC_RADIO1)->EnableWindow(TRUE);
//	GetDlgItem(IDC_RADIO1)->SetCh
		CButton* radio=(CButton*)GetDlgItem(IDC_RADIO1); //默认设置为L_HIPP
		radio->SetCheck(1);
		iPartValue = 1;
	}
	FilePath1 = "models_336_bin\\intref_thal\\R_Hipp.bmv";
	if(FindFile1.FindFile(FilePath1))
	{
		GetDlgItem(IDC_RADIO5)->EnableWindow(TRUE);
	}
	FilePath1 = "models_336_bin\\intref_thal\\L_Caud.bmv";
	if(FindFile1.FindFile(FilePath1))
	{
		GetDlgItem(IDC_RADIO2)->EnableWindow(TRUE);
	}
	FilePath1 = "models_336_bin\\intref_thal\\R_Caud.bmv";
	if(FindFile1.FindFile(FilePath1))
	{
		GetDlgItem(IDC_RADIO6)->EnableWindow(TRUE);
	}
	FilePath1 = "models_336_bin\\intref_thal\\L_Amyg.bmv";
	if(FindFile1.FindFile(FilePath1))
	{
		GetDlgItem(IDC_RADIO3)->EnableWindow(TRUE);
	}
	FilePath1 = "models_336_bin\\intref_thal\\R_Amyg.bmv";
	if(FindFile1.FindFile(FilePath1))
	{
		GetDlgItem(IDC_RADIO7)->EnableWindow(TRUE);
	}
	FilePath1 = "models_336_bin\\intref_thal\\L_Late.bmv";
	if(FindFile1.FindFile(FilePath1))
	{
		GetDlgItem(IDC_RADIO4)->EnableWindow(TRUE);
	}
	FilePath1 = "models_336_bin\\intref_thal\\R_Late.bmv";
	if(FindFile1.FindFile(FilePath1))
	{
		GetDlgItem(IDC_RADIO8)->EnableWindow(TRUE);
	}
//	if（FindFile.）


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCfirst3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCfirst3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCfirst3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	UINT	WorkForce(LPVOID lpParameter);  //线程所用，全局函数


void CMFCfirst3Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
//	BOOL err;
//	LPDWORD ec;
	UpdateData(TRUE);
	int itmp1 = iPartValue;    //判断选择的分割部位
	if(iPartValue == -1)
	{
		MessageBox(_T("please select the mode"));
		return ;
	}



	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);    //禁用按钮，防止多次点击

	char **pcmd = NULL;
	pcmd = (char **)malloc(13*sizeof(char *));
	char cmd1[] = "first";
	char cmd2[] = "-i";
	char cmd3[BFLEN];// = "K:\\exercise\\first3\\HFH_001_to_std_sub.nii";
	memset(cmd3,0,BFLEN);
	memcpy(cmd3,InputPath,InputPath.GetLength());
	if(cmd3[0] == NULL)   //判断是否选择了输入文件，没有输入则提示并退出
	{
		MessageBox(_T("please select file."));
		GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
		return ;
	}
	char cmd4[] = "-l";

	char cmd5[BFLEN];   //设置输入矩阵的路径
	memset(cmd5,0,BFLEN);
	memcpy(cmd5,InputPath,InputPath.GetLength());
	if(cmd5[0] == NULL)
	{
		MessageBox(_T("can not find the matrix file."));
		GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
		return ;
	}
	int iSize1 = strlen(cmd5);
	cmd5[iSize1 - 3] = 'm';
	cmd5[iSize1 - 2] = 'a';
	cmd5[iSize1 - 1] = 't';

//	cmd5 = cmd5 + "mat";
//	char cmd5[] = "K:\\exercise\\first3\\HFH_001_to_std_sub.mat";

	char cmd6[] = "-m";
	char cmd9[BFLEN];
	memset(cmd9,0,BFLEN);
	memcpy(cmd9,InputPath,InputPath.GetLength());
	int iSize2 = strlen(cmd9);
	cmd9[iSize2 - 4] = '_';
	cmd9[iSize2 - 3] = '\0';
	char cmdtemp[10];
	memset(cmdtemp,0,10);
	//char cmd7[] = "K:\\exercise\\first3\\data\\first\\models_336_bin\\intref_thal\\L_Hipp.bmv";
	CString Stmp1;
	char cmd7[BFLEN];
	memset(cmd7,0,BFLEN);
	CString FilePath2 ="models_336_bin\\intref_thal\\L_Hipp.bmv";
	switch(iPartValue)     //设置输出路径位置和输入模板
	{
	case 0: memcpy(cmd7,FilePath2,FilePath2.GetLength());
		Stmp1 = FilePath2.Mid((FilePath2.GetLength() - 10),6);
		memcpy(cmdtemp,Stmp1,Stmp1.GetLength());
		strcat(cmd9,cmdtemp);
		break;

	case 1: FilePath2 ="models_336_bin\\intref_thal\\L_Caud.bmv";     //设置输入模板
		memcpy(cmd7,FilePath2,FilePath2.GetLength());              
		Stmp1 = FilePath2.Mid((FilePath2.GetLength() - 10),6);
		memcpy(cmdtemp,Stmp1,Stmp1.GetLength());
		strcat(cmd9,cmdtemp);break;                 //设置输出名字和路径

	case 2: FilePath2 ="models_336_bin\\intref_thal\\L_Amyg.bmv";
		memcpy(cmd7,FilePath2,FilePath2.GetLength());
		Stmp1 = FilePath2.Mid((FilePath2.GetLength() - 10),6);
		memcpy(cmdtemp,Stmp1,Stmp1.GetLength());
		strcat(cmd9,cmdtemp);break;

	case 3: FilePath2 ="models_336_bin\\intref_thal\\L_Late.bmv";
		memcpy(cmd7,FilePath2,FilePath2.GetLength());
		Stmp1 = FilePath2.Mid((FilePath2.GetLength() - 10),6);
		memcpy(cmdtemp,Stmp1,Stmp1.GetLength());
		strcat(cmd9,cmdtemp);break;

	case 4: ;FilePath2 ="models_336_bin\\intref_thal\\R_Hipp.bmv";
		memcpy(cmd7,FilePath2,FilePath2.GetLength());
		Stmp1 = FilePath2.Mid((FilePath2.GetLength() - 10),6);
		memcpy(cmdtemp,Stmp1,Stmp1.GetLength());
		strcat(cmd9,cmdtemp);break;

	case 5: FilePath2 ="models_336_bin\\intref_thal\\R_Caud.bmv";
		memcpy(cmd7,FilePath2,FilePath2.GetLength());
		Stmp1 = FilePath2.Mid((FilePath2.GetLength() - 10),6);
		memcpy(cmdtemp,Stmp1,Stmp1.GetLength());
		strcat(cmd9,cmdtemp);break;

	case 6: FilePath2 ="models_336_bin\\intref_thal\\R_Amyg.bmv";
		memcpy(cmd7,FilePath2,FilePath2.GetLength());
		Stmp1 = FilePath2.Mid((FilePath2.GetLength() - 10),6);
		memcpy(cmdtemp,Stmp1,Stmp1.GetLength());
		strcat(cmd9,cmdtemp);break;

	case 7: FilePath2 ="models_336_bin\\intref_thal\\R_Late.bmv";
		memcpy(cmd7,FilePath2,FilePath2.GetLength());
		Stmp1 = FilePath2.Mid((FilePath2.GetLength() - 10),6);
		memcpy(cmdtemp,Stmp1,Stmp1.GetLength());
		strcat(cmd9,cmdtemp);break;

	case -1: return ;
		break;

	default: FilePath2 ="models_336_bin\\intref_thal\\L_Hipp.bmv";
		memcpy(cmd7,FilePath2,FilePath2.GetLength());
		Stmp1 = FilePath2.Mid((FilePath2.GetLength() - 10),6);
		memcpy(cmdtemp,Stmp1,Stmp1.GetLength());
		strcat(cmd9,cmdtemp);break;


	}
//	char cmd7[] = "models_336_bin\\intref_thal\\L_Hipp.bmv";
	char cmd8[] = "-k";
//	char cmd9[] = "HFH_001_to_std_sub03";
	char cmd10[] = "-n";
	char cmd11[] = "30";
	char cmd12[] = "-p";
	char cmd13[BFLEN];
	memset(cmd13,0,BFLEN);
	CString FilePath4 = "models_336_bin\\05mm\\L_Thal_05mm.bmv";   //左右模板
	if((iPartValue < 4) && (iPartValue >= 0))
	{
		memcpy(cmd13,FilePath4,FilePath4.GetLength());
	}
	else if((iPartValue >= 4)&&(iPartValue < 8))
	{
		 FilePath4 = "models_336_bin\\05mm\\R_Thal_05mm.bmv";
		memcpy(cmd13,FilePath4,FilePath4.GetLength());
	}

	*pcmd = cmd1;
	*(pcmd + 1) = cmd2;
	*(pcmd + 2) = cmd3;
	*(pcmd + 3) = cmd4;
	*(pcmd + 4) = cmd5;
	*(pcmd + 5) = cmd6;
	*(pcmd + 6) = cmd7;
	*(pcmd + 7) = cmd8;
	*(pcmd + 8) = cmd9;
	*(pcmd + 9) = cmd10;
	*(pcmd + 10) = cmd11;
	*(pcmd + 11) = cmd12;
	*(pcmd + 12) = cmd13;

	CWinThread* mythread;
	mythread = AfxBeginThread(WorkForce,(LPVOID) pcmd,THREAD_PRIORITY_NORMAL,0,0,NULL);
//	WaitForSingleObject(mythread,INFINITE);


//	HANDLE hThread1;

//	hThread1 = CreateThread(NULL,0,THFslmain,(LPVOID) pcmd ,0,NULL);
/*	while(hThread1 != 0)
	{
		Sleep(1000);
	}*/

	Sleep(1000);

	SetTimer(1,1000,NULL);
//	CloseHandle(THFslmain);


//	*(pcmd + 1) = cmd2;


/*	STARTUPINFO si;
	memset(&si,0,sizeof(STARTUPINFO)); //初始化si在内存块中的值（详见memset函数）
	si.cb = sizeof(STARTUPINFO);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_HIDE;
	PROCESS_INFORMATION pi; //必备参数设置结束
//	EnableProcessToken(SE_DEBUG_NAME);
	SECURITY_ATTRIBUTES SAfsl1,SAfsl2;
	SAfsl1.nLength = sizeof(SAfsl1);
	SAfsl1.bInheritHandle = TRUE;
	SAfsl1.lpSecurityDescriptor = NULL;
	SAfsl2.nLength = sizeof(SAfsl2);
	SAfsl2.bInheritHandle = TRUE;
	SAfsl2.lpSecurityDescriptor = NULL;
//	LPSECURITY_ATTRIBUTES LAfsl(sizeof(LAfsl),,true);
//	LAfsl.nLength = sizeof(LAfsl);
//	LAfsl.bInheritHandle = true;]
	LPTSTR szCmdline = _tcsdup(TEXT("K:\\exercise\\MFCfirst3\\MFCfirst3\\first3.exe -i K:\\exercise\\first3\\HFH_001_to_std_sub.nii -l K:\\exercise\\first3\\HFH_001_to_std_sub.mat -m K:\\exercise\\first3\\data\\first\\models_336_bin\\intref_thal\\L_Hipp.bmv  -k HFH_001_to_std_sub -n 30  -p K:\\exercise\\first3\\data\\first\\models_336_bin\\05mm\\L_Thal_05mm.bmv"));
	if(!CreateProcess(NULL,//TEXT("K:\\exercise\\MFCfirst3\\MFCfirst3\\first3.exe"),
	szCmdline,
//	NULL,
	&SAfsl1,
	&SAfsl2,
	TRUE,
	0,
	NULL,
	NULL,
	&si,
	&pi
	)) {
		MessageBox(_T("fail!"));
	exit(1);
	}else{
	//	MessageBox(_T("suc!"));
	}
	WaitForSingleObject(pi.hProcess,-1);
//	GetExitCodeProcess(pi.hProcess,&ec);
	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);
	MessageBox(_T("Complete!"));
	*/
//	LPTSTR szCmdline = _tcsdup(TEXT("K:\\exercise\\MFCfirst3\\MFCfirst3\\first3.exe -i K:\\exercise\\first3\\HFH_001_to_std_sub.nii -l K:\\exercise\\first3\\HFH_001_to_std_sub.mat -m K:\\exercise\\first3\\data\\first\\models_336_bin\\intref_thal\\L_Hipp.bmv  -k HFH_001_to_std_sub -n 30  -p K:\\exercise\\first3\\data\\first\\models_336_bin\\05mm\\L_Thal_05mm.bmv"));
//	Fslmain(13,szCmdline);
	free(pcmd);
	pcmd = NULL;
//	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
}





void CAboutDlg::On32772()
{
	// TODO: 在此添加命令处理程序代码
	CAboutDlg *pDlg = new CAboutDlg;
	pDlg->Create(IDD_ABOUTBOX,this);
	pDlg->ShowWindow(SW_SHOW);
}


void CMFCfirst3Dlg::On32771()  //打开文件代码    //默认打开文件位置为分割后输出文件位置
{
	// TODO: 在此添加命令处理程序代码
	CString sz=_T("MyType Files (*.nii)|*.nii|All File(*.*)|*.*||");
	CFileDialog dlg(true,_T(".*"),NULL,OFN_FILEMUSTEXIST|OFN_HIDEREADONLY,sz,this);
	if(IDOK==dlg.DoModal())
	{
	InputPath = dlg.GetPathName();
	}
}

UINT Rethread = 0;   //定义一个全局变量，以接收线程的返回值，以便于判断线程执行完毕

UINT      WorkForce(LPVOID lpParameter)
{
	HINSTANCE hInst;
	hInst = LoadLibrary(_TEXT("first3.dll"));    //调用动态链接库
	typedef int (*FSLMAIN)(int a,char **b);
	FSLMAIN Fslmain = (FSLMAIN)GetProcAddress(hInst,"?fslmain@@YAHHPAPAD@Z");
	Fslmain(13,(char **)lpParameter);
	Rethread = 34;

	return 0;
}





void CMFCfirst3Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值


		if(Rethread == 34)
		{
			Rethread = 0;
		GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
		KillTimer(1);
		}
//	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	CDialogEx::OnTimer(nIDEvent);
}
