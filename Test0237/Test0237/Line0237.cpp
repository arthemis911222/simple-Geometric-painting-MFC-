// Line0237.cpp : 实现文件
//

#include "stdafx.h"
#include "Test0237.h"
#include "Line0237.h"


// CLine0237
IMPLEMENT_SERIAL(CLine0237,CObject,3)

CLine0237::CLine0237()
{
}

CLine0237::~CLine0237()
{
}


// CLine0237 成员函数

void CLine0237::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code
		ar<<this->m_Point1;
		ar<<this->m_Point2;
		ar<<this->m_LineWidth;
		ar<<this->m_LineColor;
		ar<<this->m_FillColor;
	}
	else
	{	// loading code
		ar>>this->m_Point1;
		ar>>this->m_Point2;
		ar>>this->m_LineWidth;
		ar>>this->m_LineColor;
		ar>>this->m_FillColor;
	}
}

void CLine0237::Draw()
{
	CPen pen(PS_SOLID,m_LineWidth,this->m_LineColor);
	
	CBrush brush(m_FillColor);

	CPen *pOldPen=m_pDC->SelectObject(&pen);
	CBrush *pOldBrush = m_pDC->SelectObject(&brush);

	m_pDC->MoveTo(m_Point1);
	m_pDC->LineTo(m_Point2);
	
	m_pDC->SelectObject(pOldPen);
	m_pDC->SelectObject(pOldBrush);
}
