
// Test0237View.h : CTest0237View 类的接口
//

#pragma once


class CTest0237View : public CView
{
protected: // 仅从序列化创建
	CTest0237View();
	DECLARE_DYNCREATE(CTest0237View)

// 特性
public:
	CTest0237Doc* GetDocument() const;

// 操作
public:
	///界面操作
	double  m_nWinExtX;//绘制窗口的逻辑坐标大小
	double  m_nWinExtY;//绘制窗口的逻辑坐标大小
	int		m_nWinOrgX;//绘制窗口的逻辑坐标原点
	int		m_nWinOrgY;
	int		m_nMinX;//x轴的最小值(逻辑)
	int     m_nMinY;//y轴的最小值(逻辑)
	int		m_nMaxX;//x轴的最大值(逻辑)
	int		m_nMaxY;//x轴的最大值(逻辑)

	int     m_nTickLength;

	//int		m_xViewOrg;
	//int		m_yViewOrg;

	CClientDC  *m_pDC;//设备上下文
	CTest0237Doc *m_pDoc;

	CSize  m_TickParam;//绘制坐标轴时，刻度长度
	double m_StepSize;//绘制坐标轴时的间隔大小

	///画图操作
	int m_bBegin;
	int m_nShapeType;
	CPoint m_StartPoint;
	CPoint m_EndPoint;

	//用来画三角形
	int m_nNUM;
	CPoint m_pt[3];

	int m_nfillID;//保存菜单fillotherID
	int m_nlineID;//
	int m_nLineColor;//线的颜色
	int m_nFillColor;//填充颜色RGB
	int m_nLineWidth;

public:
	//画坐标
	void  SetupCoordinate();
	void  DrawAxisX(CDC *pDC );
	void  DrawAxisY(CDC *pDC );

	////
	void DrawCircle(CPoint c,CPoint p);//鼠标移动时的画圆
	void DrawAllCircle();//画所有圆，同时也用于画圆部分的“刷新”

	//void DrawRectangle(CPoint c,CPoint p);
	///画所有图形的函数
	void DrawAllRect();
	void DrawAllLine();
	void DrawAllTri();
	//void DrawLine(CPoint c,CPoint p);
	//仿照word画等腰三角形
	void DrawIsoTri(CPoint c,CPoint p);

	void ChooseDraw(int index);//用来选择鼠标拖动时的绘图
	void ChooseSave(int index,CTest0237Doc *pDoc);//选择保存的图形
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CTest0237View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
//	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	virtual void OnInitialUpdate();

	afx_msg void OnShape(UINT ID);
	afx_msg void OnUpdateShape(CCmdUI *pCmdUI);

	afx_msg void OnLine(UINT ID);
	afx_msg void OnUpdateLine(CCmdUI *pCmdUI);

	afx_msg void OnFill(UINT ID);
	afx_msg void OnUpdateFill(CCmdUI *pCmdUI);
	afx_msg void OnLineOther();
	afx_msg void OnUpdateLineOther(CCmdUI *pCmdUI);
	afx_msg void OnFillOther();
	afx_msg void OnUpdateFillOther(CCmdUI *pCmdUI);
	afx_msg void OnManualInputcircle();
	afx_msg void OnManualInputrectangle();
	afx_msg void OnManualInputline();
	afx_msg void OnManualInputtriangle();
};

#ifndef _DEBUG  // Test0237View.cpp 中的调试版本
inline CTest0237Doc* CTest0237View::GetDocument() const
   { return reinterpret_cast<CTest0237Doc*>(m_pDocument); }
#endif

