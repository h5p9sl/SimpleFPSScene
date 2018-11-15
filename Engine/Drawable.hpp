#ifndef Drawable_hpp
#define Drawable_hpp

#include "UDim.hpp"
#include <d3d9.h>

class Window;

#define PrimitiveVertexFVF D3DFVF_XYZRHW | D3DFVF_DIFFUSE
struct PrimitiveVertex
{
    UDim3f vertex;
    float rhs = 1.f;
    DWORD color;
};

class Drawable
{
protected:
    LPDIRECT3DVERTEXBUFFER9 v_buffer = nullptr;
    bool initialized = false;
public:
    UDim2f Position;
    UDim3f Size;
public:
    ~Drawable();
protected:
    virtual void Initialize(LPDIRECT3DDEVICE9 D3DDevice) = 0;
public:
    virtual void Draw(LPDIRECT3DDEVICE9 D3DDevice) = 0;
};

#endif