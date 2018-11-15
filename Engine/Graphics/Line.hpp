#ifndef Line_hpp
#define Line_hpp

#include "../Drawable.hpp"
#include "../UDim.hpp"

class Line : public Drawable
{
private:
    LPDIRECT3DVERTEXBUFFER9 v_buffer;
    PrimitiveVertex vertices[2];
public:
    Line(UDim3f v[2], DWORD c);
    ~Line();
protected:
    virtual void Initialize(LPDIRECT3DDEVICE9 D3DDevice);
public:
    virtual void Draw(LPDIRECT3DDEVICE9 D3DDevice);
};

#endif