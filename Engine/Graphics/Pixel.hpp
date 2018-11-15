#ifndef Pixel_hpp
#define Pixel_hpp

#include "../Drawable.hpp"
#include "../UDim.hpp"

class Pixel : public Drawable
{
private:
    LPDIRECT3DVERTEXBUFFER9 v_buffer;
    PrimitiveVertex vertices;
public:
    Pixel();
    Pixel(UDim2f v, DWORD c);
    ~Pixel();
public:
    void SetColor(DWORD color);
    void SetPosition(UDim2f position);
protected:
    virtual void Initialize(LPDIRECT3DDEVICE9 D3DDevice);
    virtual void UpdateVertices();
public:
    virtual void Draw(LPDIRECT3DDEVICE9 D3DDevice);
};

#endif