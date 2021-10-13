#include "types.h"
#include "vars.h"

#include "win32_public.h"
#include <client/client_public.h>
#include <qcommon/qcommon_public.h>

WinConData s_wcd;

/*
==============
TRACK_win_syscon
==============
*/
void TRACK_win_syscon()
{
	UNIMPLEMENTED(__FUNCTION__);
}

/*
==============
ConWndProc
==============
*/
LRESULT ConWndProc(HWND__ *hWnd, unsigned int uMsg, unsigned int wParam, int lParam)
{
	char* cmdString;
	int cx, cy;
	float sx, sy;
	float x, y, w, h;

	switch (uMsg)
	{
	case WM_SIZE:
		cx = LOWORD(lParam);
		cy = HIWORD(lParam);

		x = 5;
		y = 70;
		w = cx - 15;
		h = cy - 100;
		SetWindowPos(s_wcd.hwndBuffer, NULL, x, y, w, h, 0);

		y = y + h + 8;
		h = 20;
		SetWindowPos(s_wcd.hwndInputLine, NULL, x, y, w, h, 0);

		s_wcd.windowWidth = cx;
		s_wcd.windowHeight = cy;

		return DefWindowProcA(hWnd, uMsg, wParam, lParam);
	case WM_ACTIVATE:
		if (LOWORD(wParam) != WA_INACTIVE)
		{
			SetFocus(s_wcd.hwndInputLine);
		}
		return DefWindowProcA(hWnd, uMsg, wParam, lParam);
	case WM_CLOSE:
		PostQuitMessage(0);

		return 0;
	}

	return DefWindowProcA(hWnd, uMsg, wParam, lParam);
}

/*
==============
InputLineWndProc
==============
*/
LRESULT InputLineWndProc(HWND__ *hWnd, unsigned int uMsg, unsigned int wParam, int lParam)
{
	char displayBuffer[1024];
	char inputBuffer[1024];

	if (uMsg == 8)
	{
		if ((HWND__*)wParam == s_wcd.hWnd)
		{
			SetFocus(hWnd);
			return 0;
		}
	}
	else if (uMsg == 258 && wParam == 13)
	{
		GetWindowTextA(s_wcd.hwndInputLine, inputBuffer, 1024);
		strncat(s_wcd.consoleText, inputBuffer, 507 - strlen(s_wcd.consoleText));
		strcat(s_wcd.consoleText, "\n");
		SetWindowTextA(s_wcd.hwndInputLine, "");
		Com_sprintf(displayBuffer, 1024, "]%s\n", inputBuffer);
		Sys_Print(displayBuffer);
		return 0;
	}
	return CallWindowProcA((WNDPROC)s_wcd.SysInputLineWndProc, hWnd, uMsg, wParam, lParam);
}

/*
==============
Conbuf_CleanText
==============
*/
int Conbuf_CleanText(const char *source, char *target, int sizeofTarget)
{
	char* start;
	const char* last;

	start = target;
	last = target + sizeofTarget - 3;
	while (*source && target <= last)
	{
		if (source[0] != '\n' || source[1] != '\r')
		{
			if (source[0] == '\r')
			{
				target[0] = '\r';
				target[1] = '\n';
				target += 2;
				++source;
			}
			else if (source[0] == '\n')
			{
				target[0] = '\r';
				target[1] = '\n';
				target += 2;
				++source;
			}
			else if (source && source[0] == '^' && source[1] && source[1] != '^' && source[1] >= 48 && source[1] <= 64)
			{
				source += 2;
			}
			else
			{
				*target++ = *source++;
			}
		}
		else
		{
			target[0] = '\r';
			target[1] = '\n';
			target += 2;
			source += 2;
		}
	}

	*target = 0;
	return target - start;
}

/*
==============
Sys_CreateConsole
==============
*/
void Sys_CreateConsole(HINSTANCE__ *hInstance)
{
	HWND DesktopWindow;
	HDC DC;
	HWND__* Window;
	HANDLE ImageA;
	HWND__* ImageWindow;
	void(__stdcall * m_SendMessage)(HWND, UINT, WPARAM, LPARAM);
	WNDCLASSA WndClass;
	int DeviceCaps;
	HDC hDC;
	tagRECT Rect;
	char text[16384];
	char target[16384];

	WndClass.style = 0;
	WndClass.lpfnWndProc = (WNDPROC)ConWndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIconA(hInstance, (LPCSTR)1);
	WndClass.hCursor = LoadCursorA(0, (LPCSTR)0x7F00);
	WndClass.hbrBackground = (HBRUSH__*)5;
	WndClass.lpszMenuName = 0;
	WndClass.lpszClassName = "CoD Black Ops II WinConsole";
	if (RegisterClass(&WndClass))
	{
		Rect.left = 0;
		Rect.right = 620;
		Rect.top = 0;
		Rect.bottom = 450;
		AdjustWindowRect(&Rect, 0x80CA0000, 0);
		DesktopWindow = GetDesktopWindow();
		DC = GetDC(DesktopWindow);
		hDC = (HDC)GetDeviceCaps(DC, 8);
		DeviceCaps = GetDeviceCaps(DC, 10);
		ReleaseDC(DesktopWindow, DC);
		s_wcd.windowWidth = Rect.right - Rect.left + 1;
		s_wcd.windowHeight = Rect.bottom - Rect.top + 1;
		Window = CreateWindowEx(0, "CoD Black Ops II WinConsole", "CoD Black Ops II", 0x80CA0000, (int)(hDC - 150) / 2, (DeviceCaps - 450) / 2, Rect.right - Rect.left + 1, Rect.bottom - Rect.top + 1, 0, 0, hInstance, 0);
		s_wcd.hWnd = Window;
		if (Window)
		{
			hDC = GetDC(Window);
			s_wcd.hfBufferFont = CreateFont(-(MulDiv(8, GetDeviceCaps(hDC, 90), 72)), 0, 0, 0, 300, 0, 0, 0, 1u, 0, 0, 0, 0x31u, "Courier New");
			ReleaseDC(s_wcd.hWnd, hDC);
			ImageA = LoadImage(0, "codlogo.bmp", 0, 0, 0, 0x10u);
			if (ImageA)
			{
				ImageWindow = CreateWindowEx(0, "Static", 0, 0x5000000Eu, 5, 5, 0, 0, s_wcd.hWnd, (HMENU)1, hInstance, 0);
				m_SendMessage = (void(__stdcall*)(HWND, UINT, WPARAM, LPARAM))SendMessageA;
				s_wcd.codLogo = ImageWindow;
				SendMessage(ImageWindow, 0x172u, 0, (LPARAM)ImageA);
			}
			else
			{
				m_SendMessage = (void(__stdcall*)(HWND, UINT, WPARAM, LPARAM))SendMessageA;
			}
			s_wcd.hwndInputLine = CreateWindowExA(0, "edit", 0, 0x50800080u, 6, 400, 608, 20, s_wcd.hWnd, (HMENU)0x65, hInstance, 0);
			s_wcd.hwndBuffer = CreateWindowExA(0, "edit", 0, 0x50A00844u, 6, 70, 606, 324, s_wcd.hWnd, (HMENU)0x64, hInstance, 0);
			m_SendMessage(s_wcd.hwndBuffer, 0x30u, (WPARAM)s_wcd.hfBufferFont, 0);
			s_wcd.SysInputLineWndProc = (int(__stdcall*)(HWND__*, unsigned int, unsigned int, int))SetWindowLongA(s_wcd.hwndInputLine, -4, (LONG)InputLineWndProc);
			m_SendMessage(s_wcd.hwndInputLine, 0x30u, (WPARAM)s_wcd.hfBufferFont, 0);
			SetFocus(s_wcd.hwndInputLine);
			Con_GetTextCopy(text, 0x4000);
			Conbuf_CleanText(text, target, 0x4000);
			SetWindowTextA(s_wcd.hwndBuffer, target);
		}
	}
}

/*
==============
Sys_DestroyConsole
==============
*/
void Sys_DestroyConsole()
{
	if (s_wcd.hWnd)
	{
		ShowWindow(s_wcd.hWnd, SW_HIDE);
		CloseWindow(s_wcd.hWnd);
		DestroyWindow(s_wcd.hWnd);
		s_wcd.hWnd = 0;
	}
}

/*
==============
Sys_ShowConsole
==============
*/
void Sys_ShowConsole()
{
	if (!s_wcd.hWnd)
	{
		Sys_CreateConsole(GetModuleHandleA(NULL));
		//assert(s_wcd.hWnd);
	}

	ShowWindow(s_wcd.hWnd, SW_SHOWNORMAL);
	SendMessage(s_wcd.hwndBuffer, EM_LINESCROLL, 0, 0xFFFF);
	ShowCursor(TRUE);
}

/*
==============
Sys_ConsoleInput
==============
*/
char *Sys_ConsoleInput()
{
	if (!s_wcd.consoleText[0])
	{
		return 0;
	}

	strcpy(s_wcd.returnedText, s_wcd.consoleText);
	s_wcd.consoleText[0] = 0;

	return s_wcd.returnedText;
}

/*
==============
Conbuf_AppendText
==============
*/
void Conbuf_AppendText(const char *pMsg)
{
#define CONSOLE_BUFFER_SIZE     16384
	char buffer[CONSOLE_BUFFER_SIZE * 2];
	const char* msg;
	int bufLen;
	static unsigned long s_totalChars;

	assert(s_wcd.hwndBuffer);

	//
	// if the message is REALLY long, use just the last portion of it
	//
	if (strlen(pMsg) > CONSOLE_BUFFER_SIZE - 1)
	{
		msg = pMsg + strlen(pMsg) - CONSOLE_BUFFER_SIZE + 1;
	}
	else
	{
		msg = pMsg;
	}

	//
	// copy into an intermediate buffer
	//
	bufLen = Conbuf_CleanText(msg, buffer, 0x8000);
	s_totalChars += bufLen;

	//
	// replace selection instead of appending if we're overflowing
	//
	if (s_totalChars > CONSOLE_BUFFER_SIZE)
	{
		SendMessage(s_wcd.hwndBuffer, EM_SETSEL, 0, -1);
		s_totalChars = bufLen;
	}
	else
	{
		SendMessage(s_wcd.hwndBuffer, EM_SETSEL, 0xFFFF, 0xFFFF);
	}

	//
	// put this text into the windows console
	//
	SendMessage(s_wcd.hwndBuffer, EM_LINESCROLL, 0, 0xffff);
	SendMessage(s_wcd.hwndBuffer, EM_SCROLLCARET, 0, 0);
	SendMessage(s_wcd.hwndBuffer, EM_REPLACESEL, 0, (LPARAM)buffer);
}

/*
==============
Conbuf_AppendTextInMainThread
==============
*/
void Conbuf_AppendTextInMainThread(const char *msg)
{
	if (s_wcd.hwndBuffer)
	{
		if (Sys_IsMainThread())
			Conbuf_AppendText(msg);
	}
}

/*
==============
Sys_SetErrorText
==============
*/
void Sys_SetErrorText(const char *buf)
{
	I_strncpyz(s_wcd.errorString, buf, sizeof(s_wcd.errorString));
	DestroyWindow(s_wcd.hwndInputLine);
	s_wcd.hwndInputLine = NULL;
	MessageBoxA(GetActiveWindow(), buf, "Error", 0x10u);
}

