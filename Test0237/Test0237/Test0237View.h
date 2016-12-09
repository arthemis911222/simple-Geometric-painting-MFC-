
// Test0237View.h : CTest0237View ��Ľӿ�
//

#pragma once


class CTest0237View : public CView
{
protected: // �������л�����
	CTest0237View();
	DECLARE_DYNCREATE(CTest0237View)

// ����
public:
	CTest0237Doc* GetDocument() const;

// ����
public:
	///�������
	double  m_nWinExtX;//���ƴ��ڵ��߼������С
	double  m_nWinExtY;//���ƴ��ڵ��߼������С
	int		m_nWinOrgX;//���ƴ��ڵ��߼�����ԭ��
	int		m_nWinOrgY;
	int		m_nMinX;//x�����Сֵ(�߼�)
	int     m_nMinY;//y�����Сֵ(�߼�)
	int		m_nMaxX;//x������ֵ(�߼�)
	int		m_nMaxY;//x������ֵ(�߼�)

	int     m_nTickLength;

	//int		m_xViewOrg;
	//int		m_yViewOrg;

	CClientDC  *m_pDC;//�豸������
	CTest0237Doc *m_pDoc;

	CSize  m_TickParam;//����������ʱ���̶ȳ���
	double m_StepSize;//����������ʱ�ļ����С

	///��ͼ����
	int m_bBegin;
	int m_nShapeType;
	CPoint m_StartPoint;
	CPoint m_EndPoint;

	//������������
	int m_nNUM;
	CPoint m_pt[3];

	int m_nfillID;//����˵�fillotherID
	int m_nlineID;//
	int m_nLineColor;//�ߵ���ɫ
	int m_nFillColor;//�����ɫRGB
	int m_nLineWidth;

public:
	//������
	void  SetupCoordinate();
	void  DrawAxisX(CDC *pDC );
	void  DrawAxisY(CDC *pDC );

	////
	void DrawCircle(CPoint c,CPoint p);//����ƶ�ʱ�Ļ�Բ
	void DrawAllCircle();//������Բ��ͬʱҲ���ڻ�Բ���ֵġ�ˢ�¡�

	//void DrawRectangle(CPoint c,CPoint p);
	///������ͼ�εĺ���
	void DrawAllRect();
	void DrawAllLine();
	void DrawAllTri();
	//void DrawLine(CPoint c,CPoint p);
	//����word������������
	void DrawIsoTri(CPoint c,CPoint p);

	void ChooseDraw(int index);//����ѡ������϶�ʱ�Ļ�ͼ
	void ChooseSave(int index,CTest0237Doc *pDoc);//ѡ�񱣴��ͼ��
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CTest0237View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // Test0237View.cpp �еĵ��԰汾
inline CTest0237Doc* CTest0237View::GetDocument() const
   { return reinterpret_cast<CTest0237Doc*>(m_pDocument); }
#endif

