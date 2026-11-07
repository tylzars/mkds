#include "code_0212ba68.h"
#include "snd_interface.h"
#include "snd_main.h"
#include "snd_command.h"
#include "code_0212b9ec.h"
#include "code_0212bcac.h"
#include "code_0212c9d4.h"
#include "sndarc_stream.h"
#include "pm.h"
#include "code_0201ec30.h"
#include "Main/Unknown/code_02021000.h"
#include "resource_mgr.h"

PMSleepCallbackInfo data_0217d42c;
PMSleepCallbackInfo data_0217d420;
u32 data_0217d418;
u32 data_0217d41c;
s8 data_0217d414;

// Sets up the sound driver, the sleep callbacks and the resource, capture and player state once.
void NNS_SndInit(void) {
    if (data_0217d41c != 0) {
        return;
    }
    data_0217d41c = 1;
    SND_Init();
    data_0217d420.mCallback = BeginSleep;
    data_0217d420.mArg = 0;
    data_0217d42c.mCallback = EndSleep;
    data_0217d42c.mArg = 0;
    PM_PrependPreSleepCallback(&data_0217d420);
    PM_AppendPostSleepCallback(&data_0217d42c);
    NNSi_SndInitResourceMgr();
    NNSi_SndCaptureInit();
    NNSi_SndPlayerInit();
    data_0217d414 = -1;
    data_0217d418 = 1;
}

// Handles the driver replies, then runs the player and capture updates and sends the queued commands.
void NNS_SndMain(void) {
    while (SND_RecvCommandReply(0) != 0) {
    }
    NNSi_SndPlayerMain();
    NNSi_SndCaptureMain();
    NNSi_SndArcStrmMain();
    SND_FlushCommand(0);
}

// Sets the master volume.
void NNS_SndSetMasterVolume(int volume) {
    SND_SetMasterVolume(volume);
}
