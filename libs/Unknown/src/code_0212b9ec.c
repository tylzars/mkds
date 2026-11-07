#include "code_0212b9ec.h"
#include "snd_interface.h"
#include "snd_command.h"
#include "code_0212c9d4.h"
#include "code_0201ec30.h"
#include "Main/Unknown/code_02021000.h"

// Sleep callback: stops the capture and the sound timers and waits for the sound commands to finish.
void BeginSleep(void *arg) {
    u32 tag;

    NNSi_SndCaptureBeginSleep();
    SND_StopTimer(0, 0, 0, 0);
    tag = SND_GetCurrentCommandTag();
    SND_FlushCommand(1);
    SND_WaitForCommandProc(tag);
}

// Wake-up callback: restarts the capture.
void EndSleep(void *arg) {
    NNSi_SndCaptureEndSleep();
}
