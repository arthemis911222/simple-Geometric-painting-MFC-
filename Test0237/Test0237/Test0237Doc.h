
// Test0237Doc.h : CTest0237Doc 类的接口
//


#pragma once
#include"Circle0237.h"
#include"Rectangle0237.h"
#include"Line0237.h"
#include"Triangle0237.h"


class CTest0237Doc : public CDocument
{
protected: // 仅从序列化创建
	CTest0237Doc();
	DECLARE_DYNCREATE(CTest0237Doc)

// 特性
public:
	//保存圆的列表
	CTypedPtrList<CObList ,CCircle0237 *> m_CircleList;
	//保存矩形的列表
	CTypedPtrList<CObList ,CRectangle0237 *> m_RectangleList;
	//保存线的列表
	CTypedPtrList<CObList ,CLine0237 *> m_LineList;
	//保存三角形的列表
	CTypedPtrList<CObList ,CTriangle0237 *> m_TriangleList;

// 操作
public:
	CTypedPtrList<CObList ,CCircle0237 *>& GetCircleList(){ return m_CircleList; }
	void AddCircle(CCircle0237 *c)
	{ 
		m_CircleList.AddTail(c);
	}

	CTypedPtrList<CObList ,CRectangle0237 *>& GetRectangleList(){ return m_RectangleList; }
	void AddRectangle(CRectangle0237 *r)
	{ 
		m_RectangleList.AddTail(r);
	}

	CTypedPtrList<CObList ,CLine0237 *>& GetLineList(){ return m_LineList; }
	void AddLine(CLine0237 *l)
	{ 
		m_LineList.AddTail(l);
	}

	CTypedPtrList<CObList ,CTriangle0237 *>& GetTriangleList(){ return m_TriangleList; }
	void AddTriangle(CTriangle0237 *tr)
	{ 
		m_TriangleList.AddTail(tr);
	}

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CTest0237Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
