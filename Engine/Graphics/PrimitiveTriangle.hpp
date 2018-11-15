#ifndef PrimitveTriangle_hpp
#define PrimitveTriangle_hpp

#include "../Drawable.hpp"
#include "../UDim.hpp"
#include <stdio.h>

class PrimitiveTriangle : public Drawable
{
private:
    PrimitiveVertex vertices[3];
public:
    PrimitiveTriangle();
    PrimitiveTriangle(UDim2f Position, UDim2f Size, DWORD Color = D3DCOLOR_XRGB(255,255,255));
    ~PrimitiveTriangle();
public:
    void SetColor(DWORD Color[3]);
    void SetColor(DWORD Color);
protected:
    void SetVertices(UDim2f Vertices[3]);
protected:
    void UpdateVertices();
    virtual void Initialize(LPDIRECT3DDEVICE9 D3DDevice);
public:
    virtual void Draw(LPDIRECT3DDEVICE9 D3DDevice);
};

#endif