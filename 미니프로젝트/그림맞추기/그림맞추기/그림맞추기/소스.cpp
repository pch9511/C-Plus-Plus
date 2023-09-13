#include <windows.h>
#include <time.h>
#include "resource.h"
#pragma warning (disable:4996)
LRESULT CALLBACK ChildProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK ChildRightProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
HWND hWndMain, hC1, hC2, r[49];
typedef struct rct {
	int num;
	RECT rt;
}RCT;
RCT rct[49],copy[49];
LPCTSTR lpszClass = TEXT("First");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
	, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpfnWndProc = ChildProc;
	WndClass.lpszClassName = TEXT("Child");
	RegisterClass(&WndClass);

	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpfnWndProc = ChildRightProc;
	WndClass.lpszClassName = TEXT("ChildRight");
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);
	hWndMain = hWnd;

	while (GetMessage(&Message, NULL, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}
int MoveCheck(HWND,int);

BOOL Start = FALSE, Move = FALSE, UP, DOWN, LEFT, RIGHT, END = FALSE;
int Left, Top, Stage, Line = 0;
RECT crt, brt,rtp;
TCHAR NUM[255];
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	TCHAR str[256];
	int i, j, cnt = 0, check = 0;

	switch (iMessage) {
	case WM_CREATE:
		GetClientRect(hWnd, &crt);
		for (i = 0; i < 49; i++) {
			rct[i].rt = crt;
			rct[i].rt.left = 300;
		}
		hC1 = CreateWindow(TEXT("Child"), NULL, WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN,
			0, 0, 0, 0, hWnd, (HMENU)0, g_hInst, NULL);
		hC2 = CreateWindow(TEXT("ChildRight"), NULL, WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN,
			0, 0, 0, 0, hWnd, (HMENU)0, g_hInst, NULL);
		return 0;
	case WM_SIZE:
		if (wParam != SIZE_MINIMIZED) {
			MoveWindow(hC1, crt.left, crt.top, 300, crt.bottom, TRUE);
			MoveWindow(hC2, 300, crt.top, crt.right, crt.bottom, TRUE);
		}
		return 0;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case ID_40002:
			Stage = Line;
			Line = 3;
			while (cnt != Line*Line - 1) {
				rct[cnt].num = rand() % (Line*Line - 1) + 1;
				for (j = 0; j < cnt; j++) {
					if (rct[cnt].num == rct[j].num) {
						check = -1;
						break;
					}
					else {
						check = 0;
					}
				}
				if (check != -1) {
					cnt++;
				}
			}
			Move = FALSE;
			Start = TRUE;
			break;
		case ID_40003:
			Stage = Line;
			Line = 5;
			while (cnt != Line*Line - 1) {
				rct[cnt].num = rand() % (Line*Line - 1) + 1;
				for (j = 0; j < cnt; j++) {
					if (rct[cnt].num == rct[j].num) {
						check = -1;
						break;
					}
					else {
						check = 0;
					}
				}
				if (check != -1) {
					cnt++;
				}
			}
			Move = FALSE;
			Start = TRUE;
			break;
		case ID_40004:
			Stage = Line;
			Line = 7;
			while (cnt != Line*Line - 1) {
				rct[cnt].num = rand() % (Line*Line - 1) + 1;
				for (j = 0; j < cnt; j++) {
					if (rct[cnt].num == rct[j].num) {
						check = -1;
						break;
					}
					else {
						check = 0;
					}
				}
				if (check != -1) {
					cnt++;
				}
			}
			Move = FALSE;
			Start = TRUE;
			break;
		}
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		for (i = 0; i < 3; i++) {
			Rectangle(hdc, crt.left + i, crt.top + i, crt.right - i, crt.bottom - i);
		}
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

LRESULT CALLBACK ChildProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{

	HDC hdc;
	PAINTSTRUCT ps;
	int i;

	switch (iMessage) {
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		for (i = 0; i < 5; i++) {
			MoveToEx(hdc, 300 - i, rct[0].rt.top, NULL);
			LineTo(hdc, 300 - i, rct[0].rt.bottom);
		}
		EndPaint(hWnd, &ps);
		return 0;
	}

	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

LRESULT CALLBACK ChildRightProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{

	HDC hdc;
	PAINTSTRUCT ps;
	TCHAR str[255];
	RECT rtp;
	int i = 0, j = 0, cnt = 0,num;
	static int x, y, m, c = 0;
	switch (iMessage) {
	case WM_CREATE:
		srand((unsigned int)time(NULL));
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		if (Start == TRUE) {
			InvalidateRect(hWnd, NULL, TRUE);
			for (i = 0; i < 49; i++) {
				rct[i].rt = crt;
				rct[i].rt.left = 500;
				rct[i].rt.top += 200;
			}
			Left = rct[0].rt.left;
			Top = rct[0].rt.top;
			for (i = 0; i < Stage*Stage - 1; i++) {
				SendMessage(r[i], WM_CLOSE, 0, 0);
			}
			for (i = 0; i < Line*Line; i++) {
				if (i == Line*Line - 1)	break;
				wsprintf(str, TEXT("%d"), rct[cnt].num);
				r[i] = CreateWindow(TEXT("button"), str, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
					rct[cnt].rt.left, rct[cnt].rt.top, 70, 70, hWnd, (HMENU)i, g_hInst, NULL);
				cnt++;
				if ((Line%cnt == 0 || cnt%Line == 0) && cnt != 1) {
					for (j = 0; j < Line; j++) {
						rct[cnt + j].rt.top = rct[cnt - Line].rt.top + 70;
					}
				}
				else {
					rct[cnt].rt.left = rct[cnt - 1].rt.left + 70;
				}
			}
			for (i = 0; i < Line*Line - 1; i++) {
				copy[i] = rct[i];
			}
			Start = FALSE;
		}
		EndPaint(hWnd, &ps);
		return 0;
	case WM_TIMER:
		switch (wParam) {
		case 1:
			if (Move == TRUE) {
				if (c == 70) {
					c = 0;
					KillTimer(hWnd, 1);
					Move = FALSE;
					for (i = 0; i < Line*Line; i++) {
						if (i == Line*Line - 1)	break;
						for (j = 0; j < Line*Line - 1; j++) {
							GetClientRect(r[j], &rtp);
							MapWindowPoints(r[j], hWnd, (POINT *)&rtp, 2);
							InflateRect(&rtp, 0, 0);
							GetWindowText(r[j], NUM, 256);
							num = _wtoi(NUM);
							if (copy[i].rt.left == rtp.left&&copy[i].rt.top == rtp.top&&num == i + 1) {
								cnt++;
							}
						}
					}
					if (cnt == Line*Line - 1) {
						Stage = Line;
						if (Line == 7) {
							MessageBox(hWnd, TEXT("모든 난이도를 클리어했습니다. 첫단계로 돌아갑니다."), TEXT("TEST"), MB_OK);
							Line = 3;
						}
						else {
							MessageBox(hWnd, TEXT("다음 단계로 이동합니다."), TEXT("TEST"), MB_OK);
							Line += 2;
						}
						Start = TRUE;
					}
					break;
				}
				else if (UP == TRUE) {
					MoveWindow(r[m], rct[m].rt.left, rct[m].rt.top -= 1, 70, 70, TRUE);
					c++;
				}
				else if (DOWN == TRUE) {
					MoveWindow(r[m], rct[m].rt.left, rct[m].rt.top += 1, 70, 70, TRUE);
					c++;
				}
				else if (LEFT == TRUE) {
					MoveWindow(r[m], rct[m].rt.left -= 1, rct[m].rt.top, 70, 70, TRUE);
					c++;
				}
				else if (RIGHT == TRUE) {
					MoveWindow(r[m], rct[m].rt.left += 1, rct[m].rt.top, 70, 70, TRUE);
					c++;
				}
			}
			break;
		}
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	case WM_COMMAND:
		if (Move != TRUE) {
			RIGHT = TRUE;
			LEFT = TRUE;
			DOWN = TRUE;
			UP = TRUE;
			switch (LOWORD(wParam)) {
			case 0:
				m = MoveCheck(hWnd, 0);
				break;
			case 1:
				m = MoveCheck(hWnd, 1);
				break;
			case 2:
				m = MoveCheck(hWnd, 2);
				break;
			case 3:
				m = MoveCheck(hWnd, 3);
				break;
			case 4:
				m = MoveCheck(hWnd, 4);
				break;
			case 5:
				m = MoveCheck(hWnd, 5);
				break;
			case 6:
				m = MoveCheck(hWnd, 6);
				break;
			case 7:
				m = MoveCheck(hWnd, 7);
				break;
			case 8:
				m = MoveCheck(hWnd, 8);
				break;
			case 9:
				m = MoveCheck(hWnd, 9);
				break;
			case 10:
				m = MoveCheck(hWnd, 10);
				break;
			case 11:
				m = MoveCheck(hWnd, 11);
				break;
			case 12:
				m = MoveCheck(hWnd, 12);
				break;
			case 13:
				m = MoveCheck(hWnd, 13);
				break;
			case 14:
				m = MoveCheck(hWnd, 14);
				break;
			case 15:
				m = MoveCheck(hWnd, 15);
				break;
			case 16:
				m = MoveCheck(hWnd, 16);
				break;
			case 17:
				m = MoveCheck(hWnd, 17);
				break;
			case 18:
				m = MoveCheck(hWnd, 18);
				break;
			case 19:
				m = MoveCheck(hWnd, 19);
				break;
			case 20:
				m = MoveCheck(hWnd, 20);
				break;
			case 21:
				m = MoveCheck(hWnd, 21);
				break;
			case 22:
				m = MoveCheck(hWnd, 22);
				break;
			case 23:
				m = MoveCheck(hWnd, 23);
				break;
			case 24:
				m = MoveCheck(hWnd, 24);
				break;
			case 25:
				m = MoveCheck(hWnd, 25);
				break;
			case 26:
				m = MoveCheck(hWnd, 26);
				break;
			case 27:
				m = MoveCheck(hWnd, 27);
				break;
			case 28:
				m = MoveCheck(hWnd, 28);
				break;
			case 29:
				m = MoveCheck(hWnd, 29);
				break;
			case 30:
				m = MoveCheck(hWnd, 30);
				break;
			case 31:
				m = MoveCheck(hWnd, 31);
				break;
			case 32:
				m = MoveCheck(hWnd, 32);
				break;
			case 33:
				m = MoveCheck(hWnd, 33);
				break;
			case 34:
				m = MoveCheck(hWnd, 34);
				break;
			case 35:
				m = MoveCheck(hWnd, 35);
				break;
			case 36:
				m = MoveCheck(hWnd, 36);
				break;
			case 37:
				m = MoveCheck(hWnd, 37);
				break;
			case 38:
				m = MoveCheck(hWnd, 38);
				break;
			case 39:
				m = MoveCheck(hWnd, 39);
				break;
			case 40:
				m = MoveCheck(hWnd, 40);
				break;
			case 41:
				m = MoveCheck(hWnd, 41);
				break;
			case 42:
				m = MoveCheck(hWnd, 42);
				break;
			case 43:
				m = MoveCheck(hWnd, 43);
				break;
			case 44:
				m = MoveCheck(hWnd, 44);
				break;
			case 45:
				m = MoveCheck(hWnd, 45);
				break;
			case 46:
				m = MoveCheck(hWnd, 46);
				break;
			case 47:
				m = MoveCheck(hWnd, 47);
				break;
			case 48:
				m = MoveCheck(hWnd, 48);
				break;
			}
			if (LEFT == TRUE || RIGHT == TRUE || UP == TRUE || DOWN == TRUE) {
				Move = TRUE;
				SetTimer(hWnd, 1, 10, NULL);
			}
			InvalidateRect(hWnd, NULL, FALSE);
		}
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

int MoveCheck(HWND hWnd, int m)
{
	int j;
	GetClientRect(r[m], &rtp);
	MapWindowPoints(r[m], hWnd, (POINT *)&rtp, 2);
	InflateRect(&rtp, 0, 0);
	//wsprintf(str, TEXT("%d %d %d"), m,rtp.top,rct[0].rt.top);
	//MessageBox(hWndMain, str, TEXT("OK"), MB_OK);
	for (j = 0; j < Line*Line - 1; j++) {
		if ((rtp.left + 70 == rct[j].rt.left&&rtp.top == rct[j].rt.top) || rtp.left + 70 >= Left + (70 * Line)) {
			//MessageBox(hWndMain, TEXT("RIGHT"), TEXT("TEST"), MB_OK);
			RIGHT = FALSE;
		}
		if ((rtp.left - 70 == rct[j].rt.left&&rtp.top == rct[j].rt.top) || rtp.left - 70 <Left) {
			//MessageBox(hWndMain, TEXT("LEFT"), TEXT("TEST"), MB_OK);
			LEFT = FALSE;
		}
		if ((rtp.top + 70 == rct[j].rt.top&&rtp.left == rct[j].rt.left) || rtp.top + 70 >= Top + (70 * Line)) {
			//MessageBox(hWndMain, TEXT("DOWN"), TEXT("TEST"), MB_OK);
			DOWN = FALSE;
		}
		if ((rtp.top - 70 == rct[j].rt.top&&rtp.left == rct[j].rt.left) || rtp.top - 70 < Top) {
			//MessageBox(hWndMain, TEXT("UP"), TEXT("TEST"), MB_OK);
			UP = FALSE;
		}
	}
	return m;
}