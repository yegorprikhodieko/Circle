
// Ball1View.cpp: реализация класса CBall1View
//
#include <ctime>
#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Ball1.h"
#endif

#include "Ball1Doc.h"
#include "Ball1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBall1View

IMPLEMENT_DYNCREATE(CBall1View, CView)

BEGIN_MESSAGE_MAP(CBall1View, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Создание или уничтожение CBall1View

CBall1View::CBall1View() noexcept
{
	// TODO: добавьте код создания

}

CBall1View::~CBall1View()
{
}

BOOL CBall1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Рисование CBall1View

void CBall1View::OnDraw(CDC* pDC)
{
	CBall1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CPen pen;
	pen.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	pDC->Ellipse(m_rcCircle);

	// TODO: добавьте здесь код отрисовки для собственных данных
}


// Печать CBall1View

BOOL CBall1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CBall1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CBall1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// Диагностика CBall1View

#ifdef _DEBUG
void CBall1View::AssertValid() const
{
	CView::AssertValid();
}

void CBall1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBall1Doc* CBall1View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBall1Doc)));
	return (CBall1Doc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CBall1View

CPoint KD;
CPoint c;
CPoint Def;

void CBall1View::OnTimer(UINT_PTR nIDEvent)
{
	srand(time(0));
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	int radius = 50;
	
	if (nIDEvent == 2)
	{
		m_rcCircle.MoveToXY(Def+m_rcCircle.TopLeft());
		Invalidate(TRUE);
		if (KD == m_rcCircle.TopLeft())
		{
			KillTimer(2);
			SetTimer(1, 50, NULL);

		}
		Invalidate(TRUE);
	}
	if (nIDEvent == 1)
	{
		CRect rc;
		GetClientRect(&rc);
		if (m_rcCircle.IsRectNull())
		{
			// центр
			m_rcCircle.left = rc.Width() / 2 - radius;
			m_rcCircle.bottom = rc.Height() / 2 - radius;
			m_rcCircle.top = rc.Height() / 2 + radius;
			m_rcCircle.right = rc.Width() / 2 + radius;
		}

		if (m_rcCircle.bottom > rc.Height() - radius * 2)
		{
			b *= -1;
			t *= -1;
		}
		if (m_rcCircle.right > rc.Width())
		{
			l *= -1;
			r *= -1;
		}
		if (m_rcCircle.top <= radius * 2)
		{
			b *= -1;
			t *= -1;
		}
		if (m_rcCircle.left <= 0)
		{			
			l *= -1;
			r *= -1;
		}
		/*b *= pow(-1, k);
		t *= pow(-1, k+1.0);
		l *= pow(-1, k + 1.0);
		r *= pow(-1, k );*/
		KD = CPoint(10 + rand() % 500, 10 + rand() % 500);
		c = m_rcCircle.CenterPoint();
		Def = (KD-c);
		Def.x /= 10;
		Def.y /= 10;
		m_rcCircle.MoveToXY(Def);
		KillTimer(1);
		SetTimer(2,50,NULL);
		/*m_rcCircle.bottom += b;
		m_rcCircle.top += t;
		m_rcCircle.right += r;
		m_rcCircle.left += l;*/
	}
	Invalidate(TRUE);
	CRect rect;
	GetClientRect(&rect);

	CView::OnTimer(nIDEvent);
}


void CBall1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	if (point.x >= m_rcCircle.left && point.x <= m_rcCircle.right && point.y <= m_rcCircle.top && point.y >= m_rcCircle.bottom)
	{
		if (isCircMove) KillTimer(1);
		else SetTimer(1, 50, NULL);
		isCircMove = !isCircMove;
		int k = 1 + rand() % 10;
		b *= pow(-1, k);
		t *= pow(-1, k);
		r *= pow(-1, k);
		l *= pow(-1, k);
		CView::OnLButtonDown(nFlags, point);
	}
}
