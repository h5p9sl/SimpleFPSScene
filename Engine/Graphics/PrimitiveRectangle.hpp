#ifndef PrimitiveRectangle_hpp
#define PrimitiveRectangle_hpp

#include "PrimitiveTriangle.hpp"
#include "../Drawable.hpp"
#include "../UDim.hpp"
#include <stdio.h>

class PrimitiveRectangle : public Drawable
{
private:
    PrimitiveVertex vertices[5];
public:
    PrimitiveRectangle();
    PrimitiveRectangle(UDim2f Position, UDim2f Size, DWORD Color = D3DCOLOR_XRGB(255,255,255));
    ~PrimitiveRectangle();
public:
    void SetColor(DWORD Color[5]);
    void SetColor(DWORD Color);
protected:
    void SetVertices(UDim2f Vertices[5]);
protected:
    void UpdateVertices();
    virtual void Initialize(LPDIRECT3DDEVICE9 D3DDevice);
public:
    virtual void Draw(LPDIRECT3DDEVICE9 D3DDevice);
};

#endif