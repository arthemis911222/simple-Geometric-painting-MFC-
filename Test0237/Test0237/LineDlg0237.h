#pragma once


// CLineDlg0237 �Ի���

class CLineDlg0237 : public CDialog
{
	DECLARE_DYNAMIC(CLineDlg0237)

public:
	CLineDlg0237(CWnd* pParent = NULL){}   // ��׼���캯��
	CLineDlg0237(int lc,int fc,CWnd* pParent = NULL);
	virtual ~CLineDlg0237();

// �Ի�������
	enum { IDD = IDD_DIALOG_INPUTLINE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_nEndX;
	int m_nEndY;
	CStatic m_ctrfillColor;
	CStatic m_ctrlineColor;
	int m_nWidthLine;
	int m_nStartX;
	int m_nStartY;

	int fillcolor;
	int linecolor;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
};
