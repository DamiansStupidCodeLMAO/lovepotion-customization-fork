#pragma once

#include <common/luax.hpp>
#include <objects/channel/channel.hpp>

namespace Wrap_Channel
{
    int Push(lua_State* L);

    int Supply(lua_State* L);

    int Pop(lua_State* L);

    int Demand(lua_State* L);

    int Peek(lua_State* L);

    int GetCount(lua_State* L);

    int HasRead(lua_State* L);

    int GetCount(lua_State* L);

    int PerformAtomic(lua_State* L);

    int Clear(lua_State* L);

    love::Channel* CheckChannel(lua_State* L, int index);

    int Register(lua_State* L);
} // namespace Wrap_Channel
