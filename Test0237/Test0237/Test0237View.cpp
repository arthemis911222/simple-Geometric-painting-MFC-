
// Test0237View.cpp : CTest0237View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Test0237.h"
#endif

#include "Test0237Doc.h"
#include "Test0237View.h"
#include "Test0237Doc.h"
#include "CircleDlg0237.h"
#include "RectDlg0237.h"
#include "LineDlg0237.h"
#include "TriangleDlg0237.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTest0237View

//用于列表颜色的选择
int allColor[]={
	RGB(255,0,0),
	RGB(255,255,0),
	RGB(0,255,0),
	RGB(0,0,255),
	RGB(0,255,255),
};


IMPLEMENT_DYNCREATE(CTest0237View, CView)

BEGIN_MESSAGE_MAP(CTest0237View, CView)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND_RANGE(ID_SHAPE_CIRCLE, ID_SHAPE_ISO,&CTest0237View::OnShape)
	ON_UPDATE_COMMAND_UI_RANGE(ID_SHAPE_CIRCLE, ID_SHAPE_ISO,&CTest0237View::OnUpdateShape)

	ON_COMMAND_RANGE(ID_LINE_RED,ID_LINE_CYAN, &CTest0237View::OnLine)
	ON_UPDATE_COMMAND_UI_RANGE(ID_LINE_RED, ID_LINE_CYAN,&CTest0237View::OnUpdateLine)

	ON_COMMAND_RANGE(ID_FILL_RED,ID_FILL_CYAN, &CTest0237View::OnFill)
	ON_UPDATE_COMMAND_UI_RANGE(ID_FILL_RED,ID_FILL_CYAN, &CTest0237View::OnUpdateFill)

	ON_COMMAND(ID_LINE_OTHER, &CTest0237View::OnLineOther)
	ON_UPDATE_COMMAND_UI(ID_LINE_OTHER, &CTest0237View::OnUpdateLineOther)

	ON_COMMAND(ID_FILL_OTHER, &CTest0237View::OnFillOther)
	ON_UPDATE_COMMAND_UI(ID_FILL_OTHER, &CTest0237View::OnUpdateFillOther)

	ON_COMMAND(ID_MANUAL_INPUTCIRCLE, &CTest0237View::OnManualInputcircle)
	ON_COMMAND(ID_MANUAL_INPUTRECTANGLE, &CTest0237View::OnManualInputrectangle)
	ON_COMMAND(ID_MANUAL_INPUTLINE, &CTest0237View::OnManualInputline)
	ON_COMMAND(ID_MANUAL_INPUTTRIANGLE, &CTest0237View::OnManualInputtriangle)
END_MESSAGE_MAP()

// CTest0237View 构造/析构


CTest0237View::CTest0237View()
{
	// TODO: 在此处添加构造代码
	m_nWinExtX=1000;
	m_nWinExtY=1000;

	m_nWinOrgX=0;
	m_nWinOrgY=0;

	//画图操作
	m_bBegin = false;
	m_nShapeType = 0;

	m_nLineColor = RGB(0,0,0);//默认黑色
	m_nFillColor = RGB(255,255,255);//默认白色
	m_nLineWidth = 1;

	m_nNUM = 0;

	m_nlineID = ID_LINE_OTHER;
	m_nfillID = ID_FILL_OTHER;

}

CTest0237View::~CTest0237View()
{
}

BOOL CTest0237View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CTest0237View 绘制

void CTest0237View::OnDraw(CDC* /*pDC*/)
{
	CTest0237Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	SetupCoordinate();
	DrawAxisX(m_pDC);
	DrawAxisY(m_pDC);

	//画图
	DrawAllCircle();
	DrawAllRect();
	DrawAllLine();
	DrawAllTri();
}


// CTest0237View 诊断

#ifdef _DEBUG
void CTest0237View::AssertValid() const
{
	CView::AssertValid();
}

void CTest0237View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest0237Doc* CTest0237View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest0237Doc)));
	return (CTest0237Doc*)m_pDocument;
}
#endif //_DEBUG


// CTest0237View 消息处理程序


//void CTest0237View::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
//{
//	// TODO: 在此添加专用代码和/或调用基类
//}


double g_StepSize[]={0.00001,0.00005,0.0001,0.0005,0.001,0.005,0.01,0.05 ,0.1 ,0.5 , 1 , 5 , 10, 50, 100 ,500 ,1000, 5000 ,10000, 50000, 100000};
void Calculate(double xMin,double xMax,double yMin,double yMax,double &StepSize);
void Round(double &delta);

void CTest0237View::SetupCoordinate()
{
	CRect rect;
	GetClientRect(&rect);
	//把映射方式设置为MM_ISOTROPIC，即等比例缩放方式
	m_pDC->SetMapMode(MM_ISOTROPIC);
	//计算屏幕的宽与高比例
	
	float ratio  = 1.0*rect.Width()/rect.Height();

	m_pDC->SetWindowExt(m_nWinExtX*ratio,m_nWinExtX);
	
	m_pDC->SetWindowOrg(m_nWinOrgX,m_nWinOrgY);
	
	m_pDC->SetViewportExt(rect.Width(),-rect.Height()); 
	m_pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);
			
	m_pDC->DPtoLP(&rect);
	m_nMaxX = rect.right;
	m_nMaxY = rect.top;
	m_nMinX = rect.left;
	m_nMinY = rect.bottom;
	int xrange= m_nMaxX-m_nMinX;
	int yrange= m_nMaxY-m_nMinY;
	int max=( xrange)>( yrange)?( xrange):( yrange);
	m_nTickLength=  max/50;
	
	
	Calculate(m_nMinX,m_nMaxX,m_nMinY,m_nMaxY,m_StepSize);

}

void Calculate(double xMin,double xMax,double yMin,double yMax,double &StepSize)
{
	double step1= (xMax-xMin)/20;
	double step2=(yMax-yMin)/20;
	if(step1<step2)
		StepSize=step2;
	else
		StepSize=step1;

	Round(StepSize);
}

void Round(double &delta)
{
//0.00001 0.00005 0.0001 0.0005 0.001 0.005 0.01 0.05 0.1 0.5  1  5  10 50 100 500 1000 5000 10000 50000 100000
	int Count = sizeof(g_StepSize)/sizeof(double);
	
	if(delta<g_StepSize[0])
	{
		delta=g_StepSize[0];
		return ;
	}
	if(delta>g_StepSize[Count-1])
	{
		delta=g_StepSize[Count-1];
		return ;
	}
	for(int i=0;i<Count;i++)
	{
		if( fabs(delta-g_StepSize[i])/g_StepSize[i]  < 0.01)
		{
			delta=g_StepSize[i];
			return ;
		}
	}
	for(int i=0;i<Count-1;i++)
	{
		if(delta>g_StepSize[i] && delta<g_StepSize[i+1])
		{
			if( ( delta-g_StepSize[i])<(g_StepSize[i+1]-delta) )
			{
				delta=g_StepSize[i];
				return ;
			}
			else
			{
				delta=g_StepSize[i+1];
				return ;
			}
		}
	}

}

void  CTest0237View::DrawAxisX(CDC *pDC )
{
	int i;
	int step = 10;
	step=(int)(m_nMaxX/m_StepSize+0.99);
	int step1=(int)(m_nMinX/m_StepSize-0.99);
	int x1,y1;
	pDC->MoveTo(m_nMinX,0);
	pDC->LineTo(m_nMaxX,0);
	CString str;
	int align=pDC->GetTextAlign();
	pDC->SetTextAlign(TA_CENTER);
	pDC->SetBkMode(TRANSPARENT);
	for(i=step1;i<=step;i++)
	{
		if(i==0)
			continue;
		x1=m_StepSize * i;
		
		pDC->MoveTo(x1,0);
		pDC->LineTo(x1,m_nTickLength);
		str.Format("%d",i);
		pDC->TextOut(x1,0,str);
	}
	str.Format("X%.lf",m_StepSize);
	pDC->TextOut(m_nMaxX-m_nTickLength,m_nTickLength,str);
		
	pDC->SetTextAlign(align);
	
}

void  CTest0237View::DrawAxisY(CDC *pDC )
{
	int i;
	int step = 10;
	step=(int)(m_nMaxY/m_StepSize+0.99);
	int step1=(int)(m_nMinY/m_StepSize-0.99);
	int x1,y1=0;
	pDC->MoveTo(0,m_nMinY);
	pDC->LineTo(0,m_nMaxY);
	CString str;
	int align=pDC->GetTextAlign();
	pDC->SetTextAlign(TA_LEFT);
	for(i=step1;i<=step;i++)
	{
		if(i==0)
			continue;
		y1=m_StepSize*i;
		x1=m_nTickLength;
		pDC->MoveTo(0,y1);
		pDC->LineTo(x1,y1);
		str.Format("%d",i);
		pDC->TextOut(x1,y1,str);
	}

	pDC->SetTextAlign(TA_LEFT);
	str.Format("X%.lf",m_StepSize);

	pDC->TextOut(-m_nTickLength,m_nMaxY,str);
	pDC->SetTextAlign(align);
	
}




void CTest0237View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	switch(nChar)
	{
		case 33://Page up
			m_nWinExtX = m_nWinExtX*0.75;
			Invalidate();	
			break;   	
		case 34: //page down
				m_nWinExtX = m_nWinExtX*1.25;
				 Invalidate();
				break;
		case 37:  m_nWinOrgX+=10;
				Invalidate();
			break;

		case 39:  m_nWinOrgX-=10;
			Invalidate();
			break;
	
		case 38:  m_nWinOrgY-=10;
			Invalidate();
			break;
		case 40:  m_nWinOrgY+=10;
			Invalidate();
			break;
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CTest0237View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	this->m_bBegin = true;
	m_pDC->DPtoLP(&point);

	m_StartPoint = point;
	m_EndPoint = point;

	CView::OnLButtonDown(nFlags, point);
}


void CTest0237View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	if(m_bBegin)
	{
		int rop=m_pDC->SetROP2(R2_NOTXORPEN);//必须将SetROP2恢复原样，否则坐标显示会有问题
		
		CPen pen(PS_SOLID,1,RGB(0,0,0));
		CPen *pOldPen = m_pDC->SelectObject(&pen);
		//DrawCircle(m_StartPoint,m_EndPoint);
		//DrawTriangle(m_StartPoint,m_EndPoint);
		ChooseDraw(m_nShapeType);
		
		m_pDC->DPtoLP(&point);
		m_EndPoint=point;
		
		//DrawCircle(m_StartPoint,m_EndPoint);
		//DrawTriangle(m_StartPoint,m_EndPoint);
		ChooseDraw(m_nShapeType);

		m_pDC->SetROP2(rop);
		m_pDC->SelectObject(pOldPen);
	}

	CView::OnMouseMove(nFlags, point);
}


void CTest0237View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	m_pDC->DPtoLP(&point);
	m_EndPoint=point;

	CTest0237Doc* pDoc = GetDocument();
	ChooseSave(this->m_nShapeType,pDoc);
	
	CView::OnLButtonUp(nFlags, point);
}

void CTest0237View::DrawCircle(CPoint c,CPoint p)
{
	int dx = c.x - p.x;
	int dy = c.y - p.y;
	int radius = (int)sqrt(1.0*dx*dx + 1.0*dy*dy);

	CPoint p1,p2;
	p1.x = c.x - radius;
	p1.y = c.y - radius;
	p2.x = c.x + radius;
	p2.y = c.y + radius;

	m_pDC->Ellipse(CRect(p1,p2));
}

void CTest0237View::DrawAllCircle()
{
	CTypedPtrList<CObList ,CCircle0237 *> &CircleList = m_pDoc->GetCircleList();
	POSITION pos = CircleList.GetHeadPosition();

	while(pos != NULL)
	{
		CCircle0237 *c = CircleList.GetNext(pos);
		c->SetCDC(m_pDC);
		c->Draw();
	}
}

void CTest0237View::DrawAllRect()
{
	CTypedPtrList<CObList ,CRectangle0237 *> &RectList = m_pDoc->GetRectangleList();
	POSITION pos = RectList.GetHeadPosition();

	while(pos != NULL)
	{
		CRectangle0237 *r = RectList.GetNext(pos);
		r->SetCDC(m_pDC);
		r->Draw();
	}
}

void CTest0237View::DrawAllLine()
{
	CTypedPtrList<CObList ,CLine0237 *> &LineList = m_pDoc->GetLineList();
	POSITION pos = LineList.GetHeadPosition();

	while(pos != NULL)
	{
		CLine0237 *l = LineList.GetNext(pos);
		l->SetCDC(m_pDC);
		l->Draw();
	}
}

void CTest0237View::DrawAllTri()
{
	CTypedPtrList<CObList ,CTriangle0237 *> &TriList = m_pDoc->GetTriangleList();
	POSITION pos = TriList.GetHeadPosition();

	while(pos != NULL)
	{
		CTriangle0237 *tr = TriList.GetNext(pos);
		tr->SetCDC(m_pDC);
		tr->Draw();
	}
}

void CTest0237View::DrawIsoTri(CPoint c,CPoint p)
{
	//CPoint pt[3];
	//仿照word里等腰三角形的实现
	m_pt[0].x = c.x + (p.x - c.x)/2;//顶点x为起始终止点的中心
	m_pt[0].y = c.y > p.y ? c.y : p.y;//顶点的y取起始终止点的最大

	m_pt[1].x = p.x;
	m_pt[1].y = c.y < p.y ? c.y : p.y;

	m_pt[2].x = c.x;
	m_pt[2].y = m_pt[1].y;

	m_pDC->Polygon(m_pt,3);

}

void CTest0237View::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	m_pDC = new CClientDC(this);
	m_pDoc = GetDocument();
}


void CTest0237View::OnShape(UINT ID)
{
	// TODO: 在此添加命令处理程序代码
	m_nShapeType = ID - ID_SHAPE_CIRCLE;
}


void CTest0237View::OnUpdateShape(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_nShapeType == (pCmdUI->m_nID - ID_SHAPE_CIRCLE));
}


void CTest0237View::OnLine(UINT ID)
{
	// TODO: 在此添加命令处理程序代码
	m_nlineID = ID_LINE_RED;
	this->m_nLineColor = allColor[ID - ID_LINE_RED];
}


void CTest0237View::OnUpdateLine(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
		pCmdUI->SetCheck(m_nLineColor == allColor[pCmdUI->m_nID - ID_LINE_RED]);
}


void CTest0237View::OnFill(UINT ID)
{
	// TODO: 在此添加命令处理程序代码
	m_nfillID = ID_FILL_RED;
	this->m_nFillColor = allColor[ID - ID_FILL_RED];
}


void CTest0237View::OnUpdateFill(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_nFillColor == allColor[pCmdUI->m_nID - ID_FILL_RED]);
}


void CTest0237View::OnLineOther()
{
	// TODO: 在此添加命令处理程序代码
	CColorDialog colorDlg(m_nLineColor);
	colorDlg.m_cc.Flags |= CC_FULLOPEN | CC_RGBINIT;
	if(colorDlg.DoModal()==IDOK)
	{
		m_nLineColor=colorDlg.GetColor();
	}
	m_nlineID = ID_LINE_OTHER;
}


void CTest0237View::OnUpdateLineOther(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_nlineID == ID_LINE_OTHER);
}


void CTest0237View::OnFillOther()
{
	// TODO: 在此添加命令处理程序代码
	CColorDialog colorDlg(m_nFillColor);
	colorDlg.m_cc.Flags |= CC_FULLOPEN | CC_RGBINIT;
	if(colorDlg.DoModal()==IDOK)
	{
		m_nFillColor=colorDlg.GetColor();
	}
	m_nfillID = ID_FILL_OTHER;
}


void CTest0237View::OnUpdateFillOther(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_nfillID == ID_FILL_OTHER);
}


void CTest0237View::OnManualInputcircle()
{
	// TODO: 在此添加命令处理程序代码

	CircleDlg0237 dlg(m_nLineColor,m_nFillColor);
	if(dlg.DoModal()==IDOK)
	{
		m_StartPoint.x = dlg.m_nCenterX;
		m_StartPoint.y = dlg.m_nCenterY;

		m_EndPoint.x = m_StartPoint.x + dlg.m_nRadius;
		m_EndPoint.y = m_StartPoint.y + dlg.m_nRadius;

		CTest0237Doc* pDoc = GetDocument();
		CCircle0237 *pCircle  = new CCircle0237(m_StartPoint,m_EndPoint);//已经计算好半径长度
		pCircle->SetLineColor(dlg.linecolor);//假设线条的颜色为黑色，需要修改
		pCircle->SetFillColor(dlg.fillcolor); //假设圆的填充颜色为白色，需要修改
		pCircle->SetLineWidth(dlg.m_nLineWidth);//假设圆的边沿宽为1


		pDoc->AddCircle(pCircle);

		pCircle->SetCDC(m_pDC);
		pCircle->Draw();
	}
}

void CTest0237View::ChooseDraw(int index)
{
	switch(index)
	{
	case 0:
		DrawCircle(m_StartPoint,m_EndPoint);
		break;
	case 1:
		m_pDC->Rectangle(CRect(m_StartPoint,m_EndPoint));
		break;
	case 2:
		{
			m_pDC->MoveTo(m_StartPoint);
			m_pDC->LineTo(m_EndPoint);
		}
		break;
	case 3:
		{
			m_pDC->MoveTo(m_StartPoint);
			m_pDC->LineTo(m_EndPoint);
		}
		break;
	case 4:
		DrawIsoTri(m_StartPoint,m_EndPoint);
		break;
	}
}

void CTest0237View::ChooseSave(int index,CTest0237Doc *pDoc)
{
	switch(index)
	{
	case 0:
		{
			m_bBegin = false;
			CCircle0237 *pCircle  = new CCircle0237(m_StartPoint,m_EndPoint);//已经计算好半径长度
			pCircle->SetLineColor(m_nLineColor);//假设线条的颜色为黑色，需要修改
			pCircle->SetFillColor(m_nFillColor); //假设圆的填充颜色为白色，需要修改
			pCircle->SetLineWidth(m_nLineWidth);//假设圆的边沿宽为1

			pDoc->AddCircle(pCircle);

			pCircle->SetCDC(m_pDC);
			pCircle->Draw();
		}
		break;
	case 1:
		{
			m_bBegin = false;
			CRectangle0237 *pRect = new CRectangle0237(m_StartPoint,m_EndPoint);
			pRect->SetLineColor(m_nLineColor);
			pRect->SetFillColor(m_nFillColor); 
			pRect->SetLineWidth(m_nLineWidth);

			pDoc->AddRectangle(pRect);

			pRect->SetCDC(m_pDC);
			pRect->Draw();

		}
		break;
	case 2:
		{
			m_bBegin = false;
			CLine0237 *pLine = new CLine0237(m_StartPoint,m_EndPoint);
			pLine->SetLineColor(m_nLineColor);
			pLine->SetFillColor(m_nFillColor); 
			pLine->SetLineWidth(m_nLineWidth);

			pDoc->AddLine(pLine);

			pLine->SetCDC(m_pDC);
			pLine->Draw();
		}
		break;
	case 3:
		{
			m_pt[m_nNUM++] = m_EndPoint;
			if(m_nNUM == 3)
			{
				//m_pDC->MoveTo(m_EndPoint);
				//m_pDC->LineTo(m_pt[0]);

				CTriangle0237 *pTri = new CTriangle0237(m_pt[0],m_pt[1],m_pt[2]);
				pTri->SetLineColor(m_nLineColor);
				pTri->SetFillColor(m_nFillColor); 
				pTri->SetLineWidth(m_nLineWidth);
	
				pDoc->AddTriangle(pTri);

				pTri->SetCDC(m_pDC);
				pTri->Draw();

				m_nNUM = 0;
				m_bBegin= false;
			}
		}
		break;
	case 4:
		{
				CTriangle0237 *pTri = new CTriangle0237(m_pt[0],m_pt[1],m_pt[2]);
				pTri->SetLineColor(m_nLineColor);
				pTri->SetFillColor(m_nFillColor); 
				pTri->SetLineWidth(m_nLineWidth);
	
				pDoc->AddTriangle(pTri);

				pTri->SetCDC(m_pDC);
				pTri->Draw();

				m_bBegin= false;
		}
		break;
	}
}



void CTest0237View::OnManualInputrectangle()
{
	// TODO: 在此添加命令处理程序代码
	CRectDlg0237 dlg(m_nLineColor,m_nFillColor);
	if(dlg.DoModal()==IDOK)
	{
		m_StartPoint.x = dlg.m_nStartX;
		m_StartPoint.y = dlg.m_nStartY;

		m_EndPoint.x = dlg.m_nEndX;
		m_EndPoint.y = dlg.m_nEndY;

		CTest0237Doc* pDoc = GetDocument();
		CRectangle0237 *pRect  = new CRectangle0237(m_StartPoint,m_EndPoint);//已经计算好半径长度
		pRect->SetLineColor(dlg.linecolor);//假设线条的颜色为黑色，需要修改
		pRect->SetFillColor(dlg.fillcolor); //假设圆的填充颜色为白色，需要修改
		pRect->SetLineWidth(dlg.m_nLineWidth);//假设圆的边沿宽为1


		pDoc->AddRectangle(pRect);

		pRect->SetCDC(m_pDC);
		pRect->Draw();
		
	}
}


void CTest0237View::OnManualInputline()
{
	// TODO: 在此添加命令处理程序代码
	CLineDlg0237 dlg(m_nLineColor,m_nFillColor);
	if(dlg.DoModal()==IDOK)
	{
		m_StartPoint.x = dlg.m_nStartX;
		m_StartPoint.y = dlg.m_nStartY;

		m_EndPoint.x = dlg.m_nEndX;
		m_EndPoint.y = dlg.m_nEndY;

		CTest0237Doc* pDoc = GetDocument();
		CLine0237 *pLine  = new CLine0237(m_StartPoint,m_EndPoint);//已经计算好半径长度
		pLine->SetLineColor(dlg.linecolor);//假设线条的颜色为黑色，需要修改
		pLine->SetFillColor(dlg.fillcolor); //假设圆的填充颜色为白色，需要修改
		pLine->SetLineWidth(dlg.m_nWidthLine);//假设圆的边沿宽为1


		pDoc->AddLine(pLine);

		pLine->SetCDC(m_pDC);
		pLine->Draw();
		
	}
}


void CTest0237View::OnManualInputtriangle()
{
	// TODO: 在此添加命令处理程序代码
	CTriangleDlg0237 dlg(m_nLineColor,m_nFillColor);
	if(dlg.DoModal()==IDOK)
	{
		
		m_pt[0] = CPoint(dlg.m_nP1X,dlg.m_nP1Y);
		m_pt[1] = CPoint(dlg.m_nP2X,dlg.m_nP2Y);
		m_pt[2] = CPoint(dlg.m_nP3X,dlg.m_nP3Y);

		CTest0237Doc* pDoc = GetDocument();
		CTriangle0237 *pTri  = new CTriangle0237(m_pt);//已经计算好半径长度
		pTri->SetLineColor(dlg.linecolor);//假设线条的颜色为黑色，需要修改
		pTri->SetFillColor(dlg.fillcolor); //假设圆的填充颜色为白色，需要修改
		pTri->SetLineWidth(dlg.m_nLineWidth);//假设圆的边沿宽为1


		pDoc->AddTriangle(pTri);

		pTri->SetCDC(m_pDC);
		pTri->Draw();
		
	}
}
