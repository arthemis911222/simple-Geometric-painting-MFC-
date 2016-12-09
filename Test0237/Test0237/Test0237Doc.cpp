
// Test0237Doc.cpp : CTest0237Doc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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


// CTest0237Doc 构造/析构

CTest0237Doc::CTest0237Doc()
{
	// TODO: 在此添加一次性构造代码

}

CTest0237Doc::~CTest0237Doc()
{
}

BOOL CTest0237Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

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




// CTest0237Doc 序列化

void CTest0237Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
	m_CircleList.Serialize(ar);
	m_RectangleList.Serialize(ar);
	m_LineList.Serialize(ar);
	m_TriangleList.Serialize(ar);
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CTest0237Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
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

// 搜索处理程序的支持
void CTest0237Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
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

// CTest0237Doc 诊断

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


// CTest0237Doc 命令
