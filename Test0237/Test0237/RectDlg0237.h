#pragma once


// CRectDlg0237 对话框

class CRectDlg0237 : public CDialog
{
	DECLARE_DYNAMIC(CRectDlg0237)

public:
	CRectDlg0237(CWnd* pParent = NULL){}   // 标准构造函数
	CRectDlg0237(int lc,int fc,CWnd* pParent = NULL); 
	virtual ~CRectDlg0237();

// 对话框数据
	enum { IDD = IDD_DIALOG_INPUTRECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
