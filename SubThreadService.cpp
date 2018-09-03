#include "stdafx.h"

extern TCHAR szWindowClass[100];
static BOOL bThreadStop = TRUE;
static HANDLE hThread = 0;

DWORD WINAPI St_ThreadRoutine(PVOID /*pArgs*/)
{
	while(!bThreadStop)
	{
		HWND hWnd = ::FindWindow(L"SubWindow1", NULL);
		if (hWnd <= 0)
		{
			Sleep(1000);
			continue;
		}
		TCHAR* pMsgContent = new TCHAR[1024];
		memset(pMsgContent, 0x0, 1024 * sizeof(TCHAR));
		PostMessage(hWnd, WM_USER+1, 0, (LPARAM) pMsgContent);
		Sleep(1000);
	}
	ExitThread(0);
}

void __stdcall InitService()
{
	bThreadStop = FALSE;
	hThread = CreateThread(NULL, 0, St_ThreadRoutine, NULL, 0, NULL);
}

void __stdcall FiniService()
{
	bThreadStop = TRUE;
	WaitForSingleObject(hThread, INFINITE);
}