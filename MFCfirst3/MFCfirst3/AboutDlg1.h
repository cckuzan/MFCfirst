#pragma once


// CAboutDlg1 对话框

class CAboutDlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(CAboutDlg1)

public:
	CAboutDlg1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAboutDlg1();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void On32772();
};
