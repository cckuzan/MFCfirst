#pragma once


// CAboutDlg1 �Ի���

class CAboutDlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(CAboutDlg1)

public:
	CAboutDlg1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAboutDlg1();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void On32772();
};
