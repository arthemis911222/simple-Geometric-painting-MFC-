// Rectangle0237.cpp : 实现文件
//

#include "stdafx.h"
#include "Test0237.h"
#include "Rectangle0237.h"


// CRectangle0237
IMPLEMENT_SERIAL(CRectangle0237,CObject,2)

CRectangle0237::CRectangle0237()
{
}


CRectangle0237::~CRectangle0237()
{
}


// CRectangle0237 成员函数
void CRectangle0237::Serialize(CArchive& ar)
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

void CRectangle0237::Draw()
{
	CPen pen(PS_SOLID,m_LineWidth,this->m_LineColor);
	
	CBrush brush(m_FillColor);

	CPen *pOldPen=m_pDC->SelectObject(&pen);
	CBrush *pOldBrush = m_pDC->SelectObject(&brush);

	m_pDC->Rectangle(CRect(m_Point1,m_Point2));
	
	m_pDC->SelectObject(pOldPen);
	m_pDC->SelectObject(pOldBrush);
}