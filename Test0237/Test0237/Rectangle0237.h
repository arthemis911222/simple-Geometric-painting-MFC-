#pragma once

// CRectangle0237 ÃüÁîÄ¿±ê

class CRectangle0237 : public CObject
{
	DECLARE_SERIAL(CRectangle0237)
public:
	CPoint m_Point1,m_Point2;
	int    m_nRwidth;
	int    m_nRheight;
	int    m_LineColor;
	int    m_LineWidth;
	int    m_FillColor;
	CDC    *m_pDC;
public:
	CRectangle0237();
	CRectangle0237(CPoint p1,CPoint p2):m_Point1(p1),m_Point2(p2)
	{

	}
	//CRectangle0237(int width,int height);

	void SetPoint1(CPoint p){ m_Point1 = p; }
	void SetPoint2(CPoint p){ m_Point2 = p; }
	void SetWidth(int w){ m_nRwidth = w; }
	void SetHeight(int h){ m_nRheight = h; }
	void SetLineColor(int color ) { m_LineColor=color;}
	void SetFillColor(int color ) { m_FillColor=color;}
	void SetLineWidth(int lineWidth){ m_LineWidth = lineWidth; }
	void SetCDC(CDC *pDC)   { m_pDC=pDC;}

	int GetLineColor( ) {return  m_LineColor;}
	int GetFillColor( ) { return m_FillColor;}
	int GetLineWidth( ) { return m_LineWidth;}
	CPoint GetPoint1() { return m_Point1; }
	CPoint GetPoint2() { return m_Point2; }

	void Draw();
	virtual void Serialize(CArchive& ar);

	virtual ~CRectangle0237();
};


