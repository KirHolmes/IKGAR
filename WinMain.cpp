#include<windows.h>
#include<stdio.h>

LRESULT CALLBACK WinSunProc(
    HWND hwnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam
);

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
){
    WNDCLASS    wndcls;
    wndcls.cbClsExtra = 0;
    wndcls.cbWndExtra = 0;
    wndcls.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wndcls.hCursor = LoadCursor(NULL, IDC_CROSS);
    wndcls.hIcon = LoadIcon(NULL, IDI_ERROR);
    wndcls.hInstance = hInstance;
    wndcls.lpfnWndProc = WinSunProc;
    wndcls.lpszClassName = "sample161026";
    wndcls.lpszMenuName = NULL;
    wndcls.style = CS_HREDRAW | CS_VREDRAW;
    RegisterClass(&wndcls);

    //create a new window
    HWND hwnd;
    hwnd = CreateWindow("sample161026", "http://www.baidu.com",
        WS_OVERLAPPEDWINDOW, 0, 0, 600, 400, NULL, NULL, hInstance, NULL);
    
    //refresh the windows
    ShowWindow(hwnd, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    //define message structrue, start message loop
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)){
        TranslateMessage(&msg);
        Dispatchmessage(&msg);
    }
    return msg.wParam;
}

//window process method
LRESULT CALLBACK WinSunProc(
    HWND    hwnd;
    UINT    uMsg;
    WPARAM  wParam;
    LPARAM  lParam;
){
    switch(uMsg){
        case    WM_CHAR:
            char    szChar[20];
            sprintf(szChar, "char code is %d", wParam);
            MessageBox(hwnd, szChar, "char", 0);
            break;
        case    WM_LBUTTONDOWN:
            MessageBox(hwnd, "mouse clicked", "message", 0);
            HDC hdc;
            hdc = GetDC(hwnd); 
            TextOut(hdc, 0, 50, "welcome", strlen("welcome") );
            //ReleaseDC(hwnd, hdc);
            break;
        case    WM_PAINT:
            HDC hDC;
            PAINTSTRUCT ps;
            hDC = BeginPaint(hwnd, &ps);
            TextOut(hDC, 0, 0, "http://www.baidu.com");
            EndPaint(hwnd, &ps);
        case    WM_CLOSE:
            if(IDYES == MessageBox(hwnd, "Do you want to quit?", "message", MB_YESNO));
            {
                DestroyWindow(hwnd);
            }
            break;
        case    WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return  0;
}