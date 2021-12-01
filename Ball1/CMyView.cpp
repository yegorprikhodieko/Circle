// CMyView.cpp: файл реализации
//

#include "pch.h"
#include "Ball1.h"
#include "CMyView.h"


// CMyView

IMPLEMENT_DYNCREATE(CMyView, CTreeView)

CMyView::CMyView()
{

}

CMyView::~CMyView()
{
}

BEGIN_MESSAGE_MAP(CMyView, CTreeView)
END_MESSAGE_MAP()


// Диагностика CMyView

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// Обработчики сообщений CMyView
