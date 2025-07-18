#include "driver/display/deko.hpp"

#include "driver/graphics/StreamBuffer.hpp"

namespace love
{
    template<>
    size_t StreamBuffer<Vertex>::unmap(size_t)
    {
        d3d.bindBuffer(this->mode, this->memory);
        return this->index;
    }

    template<>
    size_t StreamBuffer<uint16_t>::unmap(size_t)
    {
        d3d.bindBuffer(this->mode, this->memory);
        return this->index;
    }
} // namespace love
