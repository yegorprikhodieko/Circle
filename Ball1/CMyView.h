#pragma once
#include "afxcview.h"

// Просмотр CMyView

class CBall1Doc;

class CMyView : public CTreeView
{
	DECLARE_DYNCREATE(CMyView)

protected:
	CMyView();           // защищенный конструктор, используемый при динамическом создании
	virtual ~CMyView();

public:

	CBall1Doc* pDoc;

#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
};


