#include "Window.hpp"

unsigned int WindowCount = 0;

Window::Window(const TCHAR* WndName, 
        UDim2 Size)
    : Window::DirectX9()
{
    // General variables
    this->WndName = WndName;
    this->Objects.clear();
    WindowCount++;

    // Set window size
    this->Size = Size;

    // Set window position to center of screen
    UDim2 MonitorSize = {(unsigned int)GetSystemMetrics(SM_CXSCREEN), (unsigned int)GetSystemMetrics(SM_CYSCREEN)}; // Primary monitor dimensions
    this->Position = {MonitorSize.x / 2 - this->Size.x / 2, MonitorSize.y / 2 - this->Size.y / 2};

    if (this->InitWindow() != true || this->InitD3D(this->hWnd) != true) {
        delete this; // commit suicide
    }
}

Window::~Window()
{
    WindowCount--;
}

UDim2 Window::GetCursorPos()
{
    POINT p = { 0, 0 };
    if (ScreenToClient(this->hWnd, &p)) {
        // p is always equal to { -328, 302 } for some fuckin reason
        // TODO: Fix this
        printf("%04i, %04i\n", p.x, p.y);
        return UDim2(p.x, p.y);
    }
    return UDim2();
}

bool Window::IsOpen()
{
    return IsWindowVisible(this->hWnd) == TRUE;
    //return this->Shown;
}

bool Window::PollEvent(WndEvent& event)
{
    // Perform message translating & dispatching
    MSG msg;
    if (PeekMessage(&msg, this->hWnd, 0u, 0u, PM_REMOVE))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Iterate through event queue.
    for (std::vector<WndEventMngr::WindowEventInfo>::iterator a = WndEventMngr::EventQueue.begin();
        a != WndEventMngr::EventQueue.end();
        ++a)
    {
        auto i = *a;
        if (i.hwnd == this->hWnd) {
            event = i.event;
            WndEventMngr::EventQueue.erase(a);
            return true;
        }
    }

    return false;
}

void Window::Show(bool Show)
{
    int nCmdShow = (Show == true) ? SW_SHOW : SW_HIDE;
    ShowWindow(this->hWnd, nCmdShow);
    UpdateWindow(this->hWnd);
    this->Shown = Show;
}

void Window::Draw(Drawable* Obj)
{
    if (Obj != nullptr) {
        this->Objects.push_back(Obj);
    }
}

void Window::Draw(Drawable** ObjArray, unsigned count)
{
    for (unsigned i = 0; i < count; i++)
    {
        if (ObjArray[i] != nullptr) {
            this->Objects.push_back(ObjArray[i]);
        }
    }
}

void Window::Render()
{
    this->d3ddev->Clear(1, nullptr, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0,0,0), 1.f, 0);
    this->d3ddev->BeginScene();

    for (std::vector<Drawable*>::iterator Obj = this->Objects.begin(); Obj != this->Objects.end(); Obj++)
    {
        (*Obj)->Draw(this->d3ddev);
    }

    this->d3ddev->EndScene();
    this->d3ddev->Present(NULL, NULL, NULL, NULL);

    // Clear object list for new frame
    this->Objects.clear();
}

void Window::Close()
{
    this->Show(false);
}

bool Window::InitWindow()
{
    TCHAR* ClassName_t = new TCHAR[_tcslen(WndClassName) + 3];
    wsprintf(ClassName_t, _T("%s%03u"), WndClassName, WindowCount);
    this->ClassName = ClassName_t;

    printf("Intializing window class \"%s\"\n", this->ClassName);

    WNDCLASSEX wc;
    memset(&wc, 0, sizeof(WNDCLASSEX));
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = WndEventMngr::GlobalWindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = this->ClassName;
    wc.hbrBackground = NULL;

    if (RegisterClassEx(&wc) == 0) {
        return false;
    }

    this->hWnd = CreateWindowEx(
        0,
        this->ClassName,
        this->WndName,
        WS_OVERLAPPEDWINDOW,
        this->Position.x,
        this->Position.y,
        this->Size.x,
        this->Size.y,
        NULL,
        NULL,
        GetModuleHandle(NULL),
        NULL
    );
    
    if (this->hWnd == NULL) {
        return false;
    }

    return true;
}