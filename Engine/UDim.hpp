#ifndef UDim_hpp
#define UDim_hpp

struct UDim2;
struct UDim2f;
struct UDim3;
struct UDim3f;

struct UDim2
{
    UDim2(UDim2f v);
    UDim2(unsigned x, unsigned y);
    UDim2(unsigned v);
    UDim2();
    unsigned x, y;
};

struct UDim2f
{
    UDim2f(UDim2 v);
    UDim2f(float x, float y);
    UDim2f(float v);
    UDim2f();
    float x, y;
};

struct UDim3
{
    UDim3(UDim3f v);
    UDim3(UDim2 v);
    UDim3(unsigned x, unsigned y, unsigned z);
    UDim3(unsigned v);
    UDim3();
    unsigned x, y, z;
};

struct UDim3f
{
    UDim3f(UDim3 v);
    UDim3f(UDim2f v);
    UDim3f(float x, float y, float z);
    UDim3f(float v);
    UDim3f();
    float x, y, z;
};

#endif