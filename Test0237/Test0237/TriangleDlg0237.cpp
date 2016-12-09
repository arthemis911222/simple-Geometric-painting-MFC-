// TriangleDlg0237.cpp : 实现文件
//

#include "stdafx.h"
#include "Test0237.h"
#include "TriangleDlg0237.h"
#include "afxdialogex.h"


// CTriangleDlg0237 对话框

IMPLEMENT_DYNAMIC(CTriangleDlg0237, CDialog)

CTriangleDlg0237::CTriangleDlg0237(int lc,int fc,CWnd* pParent /*=NULL*/)
	: CDialog(CTriangleDlg0237::IDD, pParent)
{
	m_nLineWidth = 0;
	m_nP1X = 0;
	m_nP1Y = 0;
	m_nP2X = 0;
	m_nP2Y = 0;
	m_nP3X = 0;
	m_nP3Y = 0;

	linecolor = lc;
	fillcolor = fc;
}

CTriangleDlg0237::~CTriangleDlg0237()
{
}

void CTriangleDlg0237::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_INPUTTRI_FILLCOLOR, m_ctrfillColor);
	DDX_Control(pDX, IDC_INPUTTRI_LINECOLOR, m_ctrlineColor);
	DDX_Text(pDX, IDC_INPUTTRI_LINEWIDTH, m_nLineWidth);
	DDX_Text(pDX, IDC_INPUTTRI_P1X, m_nP1X);
	DDX_Text(pDX, IDC_INPUTTRI_P1Y, m_nP1Y);
	DDX_Text(pDX, IDC_INPUTTRI_P2X, m_nP2X);
	DDX_Text(pDX, IDC_INPUTTRI_P2Y, m_nP2Y);
	DDX_Text(pDX, IDC_INPUTTRI_P3X, m_nP3X);
	DDX_Text(pDX, IDC_INPUTTRI_P3Y, m_nP3Y);
}


BEGIN_MESSAGE_MAP(CTriangleDlg0237, CDialog)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CTriangleDlg0237 消息处理程序


void CTriangleDlg0237::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CRect rect;

	m_ctrlineColor.GetWindowRect(&rect);	
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

	m_ctrfillColor.GetWindowRect(&rect);	
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


void CTriangleDlg0237::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()

	CRect rect;
	m_ctrlineColor.GetWindowRect(&rect);	
	ScreenToClient(&rect);
	
	CBrush BrushLine(linecolor);

	dc.FillRect(&rect,&BrushLine);


	m_ctrfillColor.GetWindowRect(&rect);	
	ScreenToClient(&rect);
	
	CBrush BrushFill(fillcolor);
	
	dc.FillRect(&rect,&BrushFill);

	//没有这两句，颜色矩形将被控件覆盖
	GetDlgItem(IDC_INPUTTRI_LINECOLOR)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_INPUTTRI_FILLCOLOR)->ShowWindow(SW_HIDE);
}
