#include <switch.h>

#include <utilities/results.hpp>

extern "C"
{
    void userAppInit()
    {
        /* network interface manager */
        R_ABORT_UNLESS(nifmInitialize(NifmServiceType_User));

        /* accounts */
        R_ABORT_UNLESS(accountInitialize(AccountServiceType_Application));

        /* settings */
        R_ABORT_UNLESS(setInitialize());

        /* system settings */
        R_ABORT_UNLESS(setsysInitialize());

        /* battery */
        R_ABORT_UNLESS(psmInitialize());

        /* wireless */
        R_ABORT_UNLESS(socketInitializeDefault());

        /* friends */
        R_ABORT_UNLESS(friendsInitialize(FriendsServiceType_Viewer));

        /* initialize controllers -- 4 players max */
        padConfigureInput(0x04, HidNpadStyleSet_NpadStandard);

        /* initialize touch screen */
        hidInitializeTouchScreen();
    }

    void userAppExit()
    {
        friendsExit();

        socketExit();

        psmExit();

        setsysExit();

        setExit();

        accountExit();

        nifmExit();
    }
}
