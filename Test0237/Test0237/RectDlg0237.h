#pragma once


// CRectDlg0237 �Ի���

class CRectDlg0237 : public CDialog
{
	DECLARE_DYNAMIC(CRectDlg0237)

public:
	CRectDlg0237(CWnd* pParent = NULL){}   // ��׼���캯��
	CRectDlg0237(int lc,int fc,CWnd* pParent = NULL); 
	virtual ~CRectDlg0237();

// �Ի�������
	enum { IDD = IDD_DIALOG_INPUTRECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_ctrfillColor;
	CStatic m_ctrlineColor;
	int m_nEndX;
	int m_nEndY;
	int m_nLineWidth;
	int m_nStartX;
	int m_nStartY;

	int fillcolor;
	int linecolor;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
};
