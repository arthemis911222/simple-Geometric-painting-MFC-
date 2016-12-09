// Triangle0237.cpp : 实现文件
//

#include "stdafx.h"
#include "Test0237.h"
#include "Triangle0237.h"


// CTriangle0237
IMPLEMENT_SERIAL(CTriangle0237,CObject,4)

CTriangle0237::CTriangle0237()
{
}

CTriangle0237::~CTriangle0237()
{
}


// CTriangle0237 成员函数

void CTriangle0237::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code
		ar<<this->m_Point[0];
		ar<<this->m_Point[1];
		ar<<this->m_Point[2];
		ar<<this->m_LineWidth;
		ar<<this->m_LineColor;
		ar<<this->m_FillColor;
	}
	else
	{	// loading code
		ar>>this->m_Point[0];
		ar>>this->m_Point[1];
		ar>>this->m_Point[2];
		ar>>this->m_LineWidth;
		ar>>this->m_LineColor;
		ar>>this->m_FillColor;
	}
}

void CTriangle0237::Draw()
{
	CPen pen(PS_SOLID,m_LineWidth,this->m_LineColor);
	
	CBrush brush(m_FillColor);

	CPen *pOldPen=m_pDC->SelectObject(&pen);
	CBrush *pOldBrush = m_pDC->SelectObject(&brush);

	/*m_pDC->MoveTo(m_Point1);
	m_pDC->LineTo(m_Point2);

	m_pDC->MoveTo(m_Point2);
	m_pDC->LineTo(m_Point3);

	m_pDC->MoveTo(m_Point3);
	m_pDC->LineTo(m_Point1);
	*/
	m_pDC->Polygon(m_Point,3);
	m_pDC->SelectObject(pOldPen);
	m_pDC->SelectObject(pOldBrush);
}
