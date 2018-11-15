#ifndef DirectX9_hpp
#define DirectX9_hpp
#include <d3d9.h>
#include "UDim.hpp"

#pragma comment(lib, "d3d9.lib")

class Window;

class DirectX9
{
protected:
    LPDIRECT3D9 d3d;
    LPDIRECT3DDEVICE9 d3ddev;
    UDim2 Position; // Defaults to center of screen
    UDim2 Size; // Defaults to 640x480
public:
    DirectX9();
    ~DirectX9();
protected:
    bool InitD3D(HWND hWnd);
private:
    void CleanupD3D();
};

#endif