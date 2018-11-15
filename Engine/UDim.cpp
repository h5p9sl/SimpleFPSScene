#include "UDim.hpp"

UDim2::UDim2(UDim2f v)
{
    this->x = v.x;
    this->y = v.y;
}

UDim2::UDim2(unsigned x, unsigned y)
{
    this->x = x;
    this->y = y;
}
UDim2::UDim2(unsigned v)
{
    this->x = v;
    this->y = v;
}
UDim2::UDim2()
{
    this->x = 0;
    this->y = 0;
}

UDim2f::UDim2f(UDim2 v)
{
    this->x = v.x;
    this->y = v.y;
}

UDim2f::UDim2f(float x, float y)
{
    this->x = x;
    this->y = y;
}
UDim2f::UDim2f(float v)
{
    this->x = v;
    this->y = v;
}
UDim2f::UDim2f()
{
    this->x = 0;
    this->y = 0;
}

UDim3::UDim3(UDim3f v)
{
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
}

UDim3::UDim3(UDim2 v)
{
    this->x = v.x;
    this->y = v.y;
    this->z = 0;
}

UDim3::UDim3(unsigned x, unsigned y, unsigned z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
UDim3::UDim3(unsigned v)
{
    this->x = v;
    this->y = v;
    this->z = v;
}
UDim3::UDim3()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

UDim3f::UDim3f(UDim3 v)
{
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
}

UDim3f::UDim3f(UDim2f v)
{
    this->x = v.x;
    this->y = v.y;
    this->z = 0.f;
}

UDim3f::UDim3f(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
UDim3f::UDim3f(float v)
{
    this->x = v;
    this->y = v;
    this->z = v;
}
UDim3f::UDim3f()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}