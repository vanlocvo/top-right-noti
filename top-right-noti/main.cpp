#include <Windows.h>
#include <string>
#include <iostream>

using namespace std;

#define SWP_NOMOVE 0X2
#define SWP_NOSIZE 1
#define SWP_NOZORDER 0X4
#define SWP_SHOWWINDOW 0x0040

int pos;

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, int iCmdShow)
{
    // get position form command line, if no command line, use default
    if (szCmdLine != NULL) {
        pos = atoi(szCmdLine);
	}
    else {
        pos = 100;
	}

    while (true) {
        //Windows System Notifications
        HWND hwnd = FindWindow(L"Windows.UI.Core.CoreWindow", L"New notification");

        //Get the current position of the notification window
        RECT NotifyRect;
        GetWindowRect(hwnd, &NotifyRect);

        NotifyRect.right = NotifyRect.right - NotifyRect.left;
        NotifyRect.bottom = NotifyRect.bottom - NotifyRect.top;
        
        SetWindowPos(hwnd, 0, GetSystemMetrics(SM_CXSCREEN) - NotifyRect.right, pos, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_SHOWWINDOW);

        Sleep(10);
    }

    return 0;
}
