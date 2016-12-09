// Circle0237.cpp : 实现文件
//

#include "stdafx.h"
#include "Test0237.h"
#include "Circle0237.h"


// CCircle0237
IMPLEMENT_SERIAL(CCircle0237,CObject,1)

CCircle0237::CCircle0237()
{
}

CCircle0237::CCircle0237(CPoint c,CPoint p1)
{
	m_Center = c;

	int dx = c.x - p1.x;
	int dy = c.y - p1.y;
	m_Radius = (int)sqrt(1.0*dx*dx + 1.0*dy*dy);
}

CCircle0237::~CCircle0237()
{
}


// CCircle0237 成员函数

void CCircle0237::Draw()
{

	int x1=m_Center.x-m_Radius;
	int y1=m_Center.y-m_Radius;
	int x2=m_Center.x+m_Radius;
	int y2=m_Center.y+m_Radius;

	CPen pen(PS_SOLID,m_LineWidth,this->m_LineColor);
	
	CBrush brush(m_FillColor);

	CPen *pOldPen=m_pDC->SelectObject(&pen);
	CBrush *pOldBrush = m_pDC->SelectObject(&brush);

	m_pDC->Ellipse(x1,y1,x2,y2);
	
	m_pDC->SelectObject(pOldPen);
	m_pDC->SelectObject(pOldBrush);
}

void CCircle0237::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code
		ar<<this->m_Center;
		ar<<this->m_Radius;
		ar<<this->m_LineWidth;
		ar<<this->m_LineColor;
		ar<<this->m_FillColor;
	}
	else
	{	// loading code
		ar>>this->m_Center;
		ar>>this->m_Radius;
		ar>>this->m_LineWidth;
		ar>>this->m_LineColor;
		ar>>this->m_FillColor;
	}
}