// LineDlg0237.cpp : 实现文件
//

#include "stdafx.h"
#include "Test0237.h"
#include "LineDlg0237.h"
#include "afxdialogex.h"


// CLineDlg0237 对话框

IMPLEMENT_DYNAMIC(CLineDlg0237, CDialog)

CLineDlg0237::CLineDlg0237(int lc,int fc,CWnd* pParent /*=NULL*/)
	: CDialog(CLineDlg0237::IDD, pParent)
{

	m_nEndX = 0;
	m_nEndY = 0;
	m_nWidthLine = 0;
	m_nStartX = 0;
	m_nStartY = 0;

	linecolor = lc;
	fillcolor = fc;
}

CLineDlg0237::~CLineDlg0237()
{
}

void CLineDlg0237::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_INPUTLINE_ENDX, m_nEndX);
	DDX_Text(pDX, IDC_INPUTLINE_ENDY, m_nEndY);
	DDX_Control(pDX, IDC_INPUTLINE_FILLCOLOR, m_ctrfillColor);
	DDX_Control(pDX, IDC_INPUTLINE_LINECOLOR, m_ctrlineColor);
	DDX_Text(pDX, IDC_INPUTLINE_LINEWIDTH, m_nWidthLine);
	DDX_Text(pDX, IDC_INPUTLINE_STARTX, m_nStartX);
	DDX_Text(pDX, IDC_INPUTLINE_STARTY, m_nStartY);
}


BEGIN_MESSAGE_MAP(CLineDlg0237, CDialog)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CLineDlg0237 消息处理程序


void CLineDlg0237::OnLButtonDown(UINT nFlags, CPoint point)
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


void CLineDlg0237::OnPaint()
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
	GetDlgItem(IDC_INPUTLINE_LINECOLOR)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_INPUTLINE_FILLCOLOR)->ShowWindow(SW_HIDE);
}
