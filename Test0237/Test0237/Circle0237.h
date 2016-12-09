#pragma once

// CCircle0237 ÃüÁîÄ¿±ê

class CCircle0237 : public CObject
{
	DECLARE_SERIAL(CCircle0237)
public:
	CPoint m_Center;
	int    m_Radius;
	int    m_LineColor;
	int    m_LineWidth;
	int    m_FillColor;
	CDC    *m_pDC;
public:
	CCircle0237();
	CCircle0237(CPoint pt,int r)
	{ 
		m_Center = pt;
		m_Radius = r;
	}
	CCircle0237(CPoint c,CPoint p1);

	void SetCenter(CPoint p) { m_Center = p;}
	void SetRadius(int r)  { m_Radius  = r;}
	void SetLineColor(int color ) { m_LineColor=color;}
	void SetFillColor(int color ) { m_FillColor=color;}
	void SetLineWidth(int lineWidth){ m_LineWidth = lineWidth; }
	void SetCDC(CDC *pDC)   { m_pDC=pDC;}

	int GetRadius()  { return m_Radius ;}
	int GetLineColor( ) {return  m_LineColor;}
	int GetFillColor( ) { return m_FillColor;}
	int GetLineWidth( ) { return m_LineWidth;}
	CPoint GetCenter() { return m_Center; }

	void Draw();
	virtual ~CCircle0237();
	virtual void Serialize(CArchive& ar);
};


