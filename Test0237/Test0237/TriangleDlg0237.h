#pragma once


// CTriangleDlg0237 �Ի���

class CTriangleDlg0237 : public CDialog
{
	DECLARE_DYNAMIC(CTriangleDlg0237)

public:
	CTriangleDlg0237(CWnd* pParent = NULL){}  // ��׼���캯��
	CTriangleDlg0237(int lc,int fc,CWnd* pParent = NULL);
	virtual ~CTriangleDlg0237();

// �Ի�������
	enum { IDD = IDD_DIALOG_INPUTTRIANGLE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_ctrfillColor;
	CStatic m_ctrlineColor;
	int m_nLineWidth;
	int m_nP1X;
	int m_nP1Y;
	int m_nP2X;
	int m_nP2Y;
	int m_nP3X;
	int m_nP3Y;

	int fillcolor;
	int linecolor;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
};
