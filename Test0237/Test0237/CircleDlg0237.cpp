// CircleDlg0237.cpp : 实现文件
//

#include "stdafx.h"
#include "Test0237.h"
#include "CircleDlg0237.h"
#include "afxdialogex.h"


// CircleDlg0237 对话框

IMPLEMENT_DYNAMIC(CircleDlg0237, CDialog)

CircleDlg0237::CircleDlg0237(int lc,int fc,CWnd* pParent /*=NULL*/)
	: CDialog(CircleDlg0237::IDD, pParent)
{

	m_nCenterX = 0;
	m_nCenterY = 0;
	m_nLineWidth = 0;
	m_nRadius = 0;

	linecolor = lc;
	fillcolor = fc;
}

CircleDlg0237::~CircleDlg0237()
{
}

void CircleDlg0237::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CENTERX, m_nCenterX);
	DDX_Text(pDX, IDC_EDIT_CENTERY, m_nCenterY);
	DDX_Text(pDX, IDC_EDIT_LINEWIDTH, m_nLineWidth);
	DDX_Text(pDX, IDC_EDIT_RADIUS, m_nRadius);
	DDX_Control(pDX, IDC_FILLCOLOR, m_ctrFillColor);
	DDX_Control(pDX, IDC_LINECOLOR, m_ctrLineColor);
}


BEGIN_MESSAGE_MAP(CircleDlg0237, CDialog)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CircleDlg0237 消息处理程序


void CircleDlg0237::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CRect rect;

	m_ctrLineColor.GetWindowRect(&rect);	
	ScreenToClient(&rect);

	if(rect.PtInRect(point))
	{	

		long LineColor=linecolor;

		CColorDialog dlg(LineColor);

		dlg.m_cc.Flags |= CC_FULLOPEN | CC_RGBINIT;
		dlg.m_cc.rgbResult = LineColor;

		if(dlg.DoModal()==IDOK)
		{
			LineColor = dlg.GetColor();	

			linecolor = LineColor;
			InvalidateRect(&rect,FALSE);	
		}
	}		

	m_ctrFillColor.GetWindowRect(&rect);	
	ScreenToClient(&rect);
	if(rect.PtInRect(point))
	{ 
		long FillColor = fillcolor;
		CColorDialog dlg(FillColor);
		dlg.m_cc.Flags |= CC_FULLOPEN | CC_RGBINIT;
		dlg.m_cc.rgbResult = FillColor;
		if(dlg.DoModal()==IDOK)
		{
			FillColor = dlg.GetColor();	

			fillcolor = FillColor;

			InvalidateRect(&rect,FALSE);	
		}
	}		

	CDialog::OnLButtonDown(nFlags, point);
}


void CircleDlg0237::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()

	CRect rect;
	m_ctrLineColor.GetWindowRect(&rect);	
	ScreenToClient(&rect);
	
	CBrush BrushLine(linecolor);

	dc.FillRect(&rect,&BrushLine);


	m_ctrFillColor.GetWindowRect(&rect);	
	ScreenToClient(&rect);
	
	CBrush BrushFill(fillcolor);
	
	dc.FillRect(&rect,&BrushFill);

	//没有这两句，颜色矩形将被控件覆盖
	GetDlgItem(IDC_LINECOLOR)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_FILLCOLOR)->ShowWindow(SW_HIDE);

	//UpdateWindow();
}
