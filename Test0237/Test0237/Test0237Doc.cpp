
// Test0237Doc.cpp : CTest0237Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Test0237.h"
#endif

#include "Test0237Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTest0237Doc

IMPLEMENT_DYNCREATE(CTest0237Doc, CDocument)

BEGIN_MESSAGE_MAP(CTest0237Doc, CDocument)
END_MESSAGE_MAP()


// CTest0237Doc ����/����

CTest0237Doc::CTest0237Doc()
{
	// TODO: �ڴ����һ���Թ������

}

CTest0237Doc::~CTest0237Doc()
{
}

BOOL CTest0237Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	while(!m_CircleList.IsEmpty())
	{
		delete m_CircleList.RemoveHead();
	}

	while(!m_RectangleList.IsEmpty())
	{
		delete m_RectangleList.RemoveHead();
	}

	while(!m_LineList.IsEmpty())
	{
		delete m_LineList.RemoveHead();
	}

	while(!m_TriangleList.IsEmpty())
	{
		delete m_TriangleList.RemoveHead();
	}

	this->UpdateAllViews(NULL);

	return TRUE;
}




// CTest0237Doc ���л�

void CTest0237Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
	m_CircleList.Serialize(ar);
	m_RectangleList.Serialize(ar);
	m_LineList.Serialize(ar);
	m_TriangleList.Serialize(ar);
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CTest0237Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CTest0237Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CTest0237Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CTest0237Doc ���

#ifdef _DEBUG
void CTest0237Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTest0237Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CTest0237Doc ����
