#pragma once


// CircleDlg0237 �Ի���

class CircleDlg0237 : public CDialog
{
	DECLARE_DYNAMIC(CircleDlg0237)

public:
	CircleDlg0237(CWnd* pParent = NULL){}   // ��׼���캯��
	CircleDlg0237(int lc,int fc,CWnd* pParent = NULL);
	virtual ~CircleDlg0237();

// �Ի�������
	enum { IDD = IDD_DIALOG_INPUTCIRCLE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_nCenterX;
	int m_nCenterY;
	int m_nLineWidth;
	int m_nRadius;
	CStatic m_ctrFillColor;
	CStatic m_ctrLineColor;

	//������������������������������޷���ֵ����
	int fillcolor;
	int linecolor;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
};
