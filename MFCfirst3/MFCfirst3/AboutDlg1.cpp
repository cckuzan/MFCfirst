// AboutDlg1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCfirst3.h"
#include "AboutDlg1.h"
#include "afxdialogex.h"


// CAboutDlg1 �Ի���

IMPLEMENT_DYNAMIC(CAboutDlg1, CDialogEx)

CAboutDlg1::CAboutDlg1(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAboutDlg1::IDD, pParent)
{

}

CAboutDlg1::~CAboutDlg1()
{
}

void CAboutDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAboutDlg1, CDialogEx)
//	ON_COMMAND(ID_32772, &CAboutDlg1::On32772)
END_MESSAGE_MAP()


// CAboutDlg1 ��Ϣ�������


//void CAboutDlg1::On32772()
//{
//	// TODO: �ڴ���������������
//	CAboutDlg1 *pDlg = new CAboutDlg1;
//	pDlg->Create(IDD_ABOUTBOX,this);
//	pDlg->ShowWindow(SW_SHOW);
//}
