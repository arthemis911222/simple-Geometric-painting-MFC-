
// Test0237Doc.h : CTest0237Doc ��Ľӿ�
//


#pragma once
#include"Circle0237.h"
#include"Rectangle0237.h"
#include"Line0237.h"
#include"Triangle0237.h"


class CTest0237Doc : public CDocument
{
protected: // �������л�����
	CTest0237Doc();
	DECLARE_DYNCREATE(CTest0237Doc)

// ����
public:
	//����Բ���б�
	CTypedPtrList<CObList ,CCircle0237 *> m_CircleList;
	//������ε��б�
	CTypedPtrList<CObList ,CRectangle0237 *> m_RectangleList;
	//�����ߵ��б�
	CTypedPtrList<CObList ,CLine0237 *> m_LineList;
	//���������ε��б�
	CTypedPtrList<CObList ,CTriangle0237 *> m_TriangleList;

// ����
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

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CTest0237Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
