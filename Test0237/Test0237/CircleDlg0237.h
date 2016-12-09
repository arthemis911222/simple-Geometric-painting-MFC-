#pragma once


// CircleDlg0237 对话框

class CircleDlg0237 : public CDialog
{
	DECLARE_DYNAMIC(CircleDlg0237)

public:
	CircleDlg0237(CWnd* pParent = NULL){}   // 标准构造函数
	CircleDlg0237(int lc,int fc,CWnd* pParent = NULL);
	virtual ~CircleDlg0237();

// 对话框数据
	enum { IDD = IDD_DIALOG_INPUTCIRCLE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_nCenterX;
	int m_nCenterY;
	int m_nLineWidth;
	int m_nRadius;
	CStatic m_ctrFillColor;
	CStatic m_ctrLineColor;

	//不能用类向导添加这两个变量，否则无法将值传递
	int fillcolor;
	int linecolor;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
};
