
// Ball1View.h: интерфейс класса CBall1View
//

#pragma once


class CBall1View : public CView
{
protected: // создать только из сериализации
	CBall1View() noexcept;
	DECLARE_DYNCREATE(CBall1View)

// Атрибуты
public:
	CBall1Doc* GetDocument() const;
	CRect m_rcCircle;
	int t = 5, l = 5, r = 5, b = 5;
	bool isCircMove = 1;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CBall1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // версия отладки в Ball1View.cpp
inline CBall1Doc* CBall1View::GetDocument() const
   { return reinterpret_cast<CBall1Doc*>(m_pDocument); }
#endif

