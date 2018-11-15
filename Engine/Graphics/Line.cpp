#include "Line.hpp"

Line::Line(UDim3f v[2], DWORD c)
{
    for (unsigned i = 0; i < 2; i++) {
        this->vertices[i].color = c;
        this->vertices[i].vertex = v[i];
    }
}

Line::~Line()
{
    this->v_buffer->Release();
}

void Line::Initialize(LPDIRECT3DDEVICE9 dev)
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

    if (v_buffer) {
        void* pBuffer;
        v_buffer->Lock(0, sizeof(vertices), &pBuffer, 0);
        memcpy(pBuffer, vertices, sizeof(vertices));
        v_buffer->Unlock();
    }
}

void Line::Draw(LPDIRECT3DDEVICE9 dev)
{
    if (!this->initialized) {
        this->Initialize(dev);
    }

    dev->SetFVF(PrimitiveVertexFVF);

    dev->SetStreamSource(0, this->v_buffer, 0, sizeof(PrimitiveVertex));

    dev->DrawPrimitive(D3DPT_LINELIST, 0, 1);
}