#include <common/luax.hpp>

#include <modules/love/love.hpp>

#include <coreinit/core.h>
#include <coreinit/exit.h>
#include <coreinit/filesystem.h>
#include <coreinit/foreground.h>

#include <proc_ui/procui.h>

#include <padscore/kpad.h>
#include <padscore/wpad.h>
#include <sysapp/launch.h>
#include <vpad/input.h>

#include <whb/gfx.h>

#include <coreinit/bsp.h>
#include <nn/ac/ac_c.h>

#include <utilities/driver/hid_ext.hpp>
#include <utilities/result.hpp>

using namespace love;

template<>
void love::PreInit<Console::CAFE>()
{
    ProcUIInit(OSSavesDone_ReadyToRelease);

    WHBGfxInit();

    VPADInit();

    KPADInit();

    ACInitialize();

    FSInit();

    bspInitializeShimInterface();

    Console::SetMainCore(OSGetCoreId());
}

static bool isRunning()
{

    if (Console::GetMainCoreId() != OSGetMainCoreId())
    {
        ProcUISubProcessMessages(true);
        return true;
    }

    ProcUIStatus status = ProcUIProcessMessages(true);

    switch (status)
    {
        case PROCUI_STATUS_IN_FOREGROUND:
        {
            HID<Console::Which>::Instance().SendFocus(true);
            break;
        }
        case PROCUI_STATUS_RELEASE_FOREGROUND:
        {
            HID<Console::Which>::Instance().SendFocus(false);
            ProcUIDrawDoneRelease();
            break;
        }
        case PROCUI_STATUS_EXITING:
        {
            HID<Console::Which>::Instance().SendQuit();
            return false;
        }
        default:
            break;
    }

    return true;
}

static bool sShutdown = false;

template<>
bool love::MainLoop<Console::CAFE>(lua_State* L, int numArgs)
{
    if (!sShutdown)
    {
        const auto yielding = (luax::Resume(L, numArgs) == LUA_YIELD);

        if (!yielding)
        {
            SYSLaunchMenu();
            sShutdown = true;
        }
    }

    return isRunning();
}

template<>
void love::OnExit<Console::CAFE>()
{
    FSShutdown();

    ACFinalize();

    KPADShutdown();

    VPADShutdown();

    WHBGfxShutdown();

    ProcUIShutdown();
}
