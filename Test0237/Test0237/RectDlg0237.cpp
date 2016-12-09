// RectDlg0237.cpp : 实现文件
//

#include "stdafx.h"
#include "Test0237.h"
#include "RectDlg0237.h"
#include "afxdialogex.h"


// CRectDlg0237 对话框

IMPLEMENT_DYNAMIC(CRectDlg0237, CDialog)

CRectDlg0237::CRectDlg0237(int lc,int fc,CWnd* pParent /*=NULL*/)
	: CDialog(CRectDlg0237::IDD, pParent)
{

	m_nEndX = 0;
	m_nEndY = 0;
	m_nLineWidth = 0;
	m_nStartX = 0;
	m_nStartY = 0;

	linecolor = lc;
	fillcolor = fc;
}

CRectDlg0237::~CRectDlg0237()
{
}

void CRectDlg0237::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC__RECT_FILLCOLOR, m_ctrfillColor);
	DDX_Control(pDX, IDC__RECT_LINECOLOR, m_ctrlineColor);
	DDX_Text(pDX, IDC_EDIT_ENDX, m_nEndX);
	DDX_Text(pDX, IDC_EDIT_ENDY, m_nEndY);
	DDX_Text(pDX, IDC_EDIT_RECT_LINEWIDTH, m_nLineWidth);
	DDX_Text(pDX, IDC_EDIT_STARTX, m_nStartX);
	DDX_Text(pDX, IDC_EDIT_STARTY, m_nStartY);
}


BEGIN_MESSAGE_MAP(CRectDlg0237, CDialog)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CRectDlg0237 消息处理程序


void CRectDlg0237::OnLButtonDown(UINT nFlags, CPoint point)
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


void CRectDlg0237::OnPaint()
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
	GetDlgItem(IDC__RECT_LINECOLOR)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC__RECT_FILLCOLOR)->ShowWindow(SW_HIDE);
}
