#include "Drawable.hpp"

Drawable::~Drawable()
{
    if (this->v_buffer) this->v_buffer->Release();
}
