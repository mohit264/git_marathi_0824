#include<stdio.h>
#include<Windows.h>

// Global Function Declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void UserRegistration()
{
    printf("Implementing User Registration \n");
    
}

// Entry Point Function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
    // variable declarations
    WNDCLASSEX wndClass;
    HWND hwnd;
    MSG msg;
    TCHAR szAppName[] = TEXT("My Window");

    // code
    // Initialization of WNDCLASS wndClass structure
    wndClass.cbSize = sizeof(WNDCLASSEX);
    wndClass.style = CS_HREDRAW | CS_VREDRAW;
    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.lpfnWndProc = WndProc;
    wndClass.hInstance = hInstance;
    wndClass.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
    wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.lpszClassName = szAppName;
    wndClass.lpszMenuName = NULL;
    wndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    // Registering above WndClass
    RegisterClassEx(&wndClass);

    // Create the window
    hwnd = CreateWindow(szAppName, 
                        TEXT("Mohit Vilasrao Dharmadhikari"),
                        WS_OVERLAPPEDWINDOW,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        NULL,
                        NULL,
                        hInstance,
                        NULL
                        );

    // Show Window
    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);

    // Message Loop
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return((int) msg.wParam);
}

// Callback function
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    // code
    switch (iMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    
    default:
        break;
    }

    return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}

