
// MFCfirst3Dlg.h : ͷ�ļ�
//

#pragma once


// CMFCfirst3Dlg �Ի���
class CMFCfirst3Dlg : public CDialogEx
{
// ����
public:
	CMFCfirst3Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCFIRST3_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	// ѡ��ָ��
	int iPartValue;
	afx_msg void On32771();
	CString InputPath;
//	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
// ѡ��ָ��
