#include "Pixel.hpp"

Pixel::Pixel()
{
    Pixel(UDim2f(), DWORD());
}

Pixel::Pixel(UDim2f v, DWORD c)
{
    this->SetColor(c);
    this->SetPosition(v);
}

Pixel::~Pixel()
{
    /*I had to add this line because of some weird bug caused
    during Noise class initialization, which causes the Pixel's
    destructor to get called... TODO: Investigate this meme.*/
    if (this->initialized)
        this->v_buffer->Release();
}

void Pixel::SetColor(DWORD color)
{
    this->vertices.color = color;
    this->vertices.rhs = 1.f;
}

void Pixel::SetPosition(UDim2f position)
{
    this->vertices.vertex.x = position.x;
    this->vertices.vertex.y = position.y;
    this->vertices.vertex.z = 0.f;
}

void Pixel::Initialize(LPDIRECT3DDEVICE9 dev)
{
    this->initialized = true;

    dev->CreateVertexBuffer(
        sizeof(PrimitiveVertex),
        0,
        PrimitiveVertexFVF,
        D3DPOOL_MANAGED,
        &this->v_buffer,
        NULL
    );
}

void Pixel::UpdateVertices()
{
    if (v_buffer) {
        void* pBuffer;
        v_buffer->Lock(0, sizeof(vertices), &pBuffer, 0);
        memcpy(pBuffer, &vertices, sizeof(vertices));
        v_buffer->Unlock();
    }
}

void Pixel::Draw(LPDIRECT3DDEVICE9 dev)
{
    if (!this->initialized)
        this->Initialize(dev);
    
    UpdateVertices();

    dev->SetFVF(PrimitiveVertexFVF);

    dev->SetStreamSource(0, this->v_buffer, 0, sizeof(PrimitiveVertex));

    dev->DrawPrimitive(D3DPT_POINTLIST, 0, 1);
}