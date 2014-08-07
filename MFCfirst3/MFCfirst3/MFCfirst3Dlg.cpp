
// MFCfirst3Dlg.cpp : ʵ���ļ�
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

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFCfirst3Dlg �Ի���




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


// CMFCfirst3Dlg ��Ϣ�������

BOOL CMFCfirst3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	//�жϷָ�ģ���ļ��Ƿ����
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
		CButton* radio=(CButton*)GetDlgItem(IDC_RADIO1); //Ĭ������ΪL_HIPP
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
//	if��FindFile.��


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCfirst3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCfirst3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



	UINT	WorkForce(LPVOID lpParameter);  //�߳����ã�ȫ�ֺ���


void CMFCfirst3Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	BOOL err;
//	LPDWORD ec;
	UpdateData(TRUE);
	int itmp1 = iPartValue;    //�ж�ѡ��ķָλ
	if(iPartValue == -1)
	{
		MessageBox(_T("please select the mode"));
		return ;
	}



	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);    //���ð�ť����ֹ��ε��

	char **pcmd = NULL;
	pcmd = (char **)malloc(13*sizeof(char *));
	char cmd1[] = "first";
	char cmd2[] = "-i";
	char cmd3[BFLEN];// = "K:\\exercise\\first3\\HFH_001_to_std_sub.nii";
	memset(cmd3,0,BFLEN);
	memcpy(cmd3,InputPath,InputPath.GetLength());
	if(cmd3[0] == NULL)   //�ж��Ƿ�ѡ���������ļ���û����������ʾ���˳�
	{
		MessageBox(_T("please select file."));
		GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
		return ;
	}
	char cmd4[] = "-l";

	char cmd5[BFLEN];   //������������·��
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
	switch(iPartValue)     //�������·��λ�ú�����ģ��
	{
	case 0: memcpy(cmd7,FilePath2,FilePath2.GetLength());
		Stmp1 = FilePath2.Mid((FilePath2.GetLength() - 10),6);
		memcpy(cmdtemp,Stmp1,Stmp1.GetLength());
		strcat(cmd9,cmdtemp);
		break;

	case 1: FilePath2 ="models_336_bin\\intref_thal\\L_Caud.bmv";     //��������ģ��
		memcpy(cmd7,FilePath2,FilePath2.GetLength());              
		Stmp1 = FilePath2.Mid((FilePath2.GetLength() - 10),6);
		memcpy(cmdtemp,Stmp1,Stmp1.GetLength());
		strcat(cmd9,cmdtemp);break;                 //����������ֺ�·��

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
	CString FilePath4 = "models_336_bin\\05mm\\L_Thal_05mm.bmv";   //����ģ��
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
	memset(&si,0,sizeof(STARTUPINFO)); //��ʼ��si���ڴ���е�ֵ�����memset������
	si.cb = sizeof(STARTUPINFO);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_HIDE;
	PROCESS_INFORMATION pi; //�ر��������ý���
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
	// TODO: �ڴ���������������
	CAboutDlg *pDlg = new CAboutDlg;
	pDlg->Create(IDD_ABOUTBOX,this);
	pDlg->ShowWindow(SW_SHOW);
}


void CMFCfirst3Dlg::On32771()  //���ļ�����    //Ĭ�ϴ��ļ�λ��Ϊ�ָ������ļ�λ��
{
	// TODO: �ڴ���������������
	CString sz=_T("MyType Files (*.nii)|*.nii|All File(*.*)|*.*||");
	CFileDialog dlg(true,_T(".*"),NULL,OFN_FILEMUSTEXIST|OFN_HIDEREADONLY,sz,this);
	if(IDOK==dlg.DoModal())
	{
	InputPath = dlg.GetPathName();
	}
}

UINT Rethread = 0;   //����һ��ȫ�ֱ������Խ����̵߳ķ���ֵ���Ա����ж��߳�ִ�����

UINT      WorkForce(LPVOID lpParameter)
{
	HINSTANCE hInst;
	hInst = LoadLibrary(_TEXT("first3.dll"));    //���ö�̬���ӿ�
	typedef int (*FSLMAIN)(int a,char **b);
	FSLMAIN Fslmain = (FSLMAIN)GetProcAddress(hInst,"?fslmain@@YAHHPAPAD@Z");
	Fslmain(13,(char **)lpParameter);
	Rethread = 34;

	return 0;
}





void CMFCfirst3Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ


		if(Rethread == 34)
		{
			Rethread = 0;
		GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
		KillTimer(1);
		}
//	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	CDialogEx::OnTimer(nIDEvent);
}
