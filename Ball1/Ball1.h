
// Ball1.h: основной файл заголовка для приложения Ball1
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CBall1App:
// Сведения о реализации этого класса: Ball1.cpp
//

class CBall1App : public CWinApp
{
public:
	CBall1App() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CBall1App theApp;
