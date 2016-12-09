#pragma once

// CTriangle0237 ÃüÁîÄ¿±ê

class CTriangle0237 : public CObject
{
	DECLARE_SERIAL(CTriangle0237)
public:
	CPoint m_Point[3];
	int    m_LineColor;
	int    m_LineWidth;
	int    m_FillColor;
	CDC    *m_pDC;
public:
	CTriangle0237();
	CTriangle0237(CPoint p1,CPoint p2,CPoint p3)
	{
		m_Point[0] = p1;
		m_Point[1] = p2;
		m_Point[2] = p3;
	}
	CTriangle0237(CPoint p[3])
	{
		m_Point[0] = p[0];
		m_Point[1] = p[1];
		m_Point[2] = p[2];
	}

	void SetPoint1(CPoint p[3])
	{ 
		m_Point[0] = p[0];
		m_Point[1] = p[1];
		m_Point[2] = p[2];
	}

	void SetLineColor(int color ) { m_LineColor=color;}
	void SetFillColor(int color ) { m_FillColor=color;}
	void SetLineWidth(int lineWidth){ m_LineWidth = lineWidth; }
	void SetCDC(CDC *pDC)   { m_pDC=pDC;}

	int GetLineColor( ) {return  m_LineColor;}
	int GetFillColor( ) { return m_FillColor;}
	int GetLineWidth( ) { return m_LineWidth;}
	//CPoint GetPointArry() { return m_Point; }

	void Draw();
	virtual void Serialize(CArchive& ar);
	virtual ~CTriangle0237();
};


