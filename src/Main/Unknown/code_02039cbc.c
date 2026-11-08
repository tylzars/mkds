#include "Main/Unknown/code_02039cbc.h"
#include "Main/Unknown/code_02039e08.h"
#include "Main/Unknown/code_02039e00.h"
#include "Main/Unknown/code_020364e0.h"
#include "code_02146af4.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_0212030c.h"
#include "Main/Unknown/code_02057524.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_02108e94.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_02057ed8.h"
#include "Main/Unknown/code_02057ed4.h"
#include "Main/Unknown/code_02059bc0.h"
#include "Main/Unknown/code_020cefa0.h"
#include "Main/Unknown/code_020cef1c.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0212b0b8.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02045000.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "code_0200e77c.h"
#include "code_0214d93c.h"
#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020483e4.h"
#include "Main/Unknown/code_0204984c.h"
#include "Main/Unknown/code_0204ad44.h"
#include "Main/Unknown/code_0204b714.h"

void func_02039cbc(void) {
    void *backHeap;
    void *firstFrontHeap;
    void *secondFrontHeap;
    void *thirdFrontHeap;
    void *soundBuffer;
    u32 soundBufferSize;
    soundBufferSize = func_02039e08(GetHeap(GetCurrentHeapCall()), &backHeap, &soundBuffer, &firstFrontHeap,
                                    &secondFrontHeap, &thirdFrontHeap);
    CARD_SetPulledOutCallback(func_02039e00);
    func_0205e180(backHeap);
    InitSceneRunState(backHeap);
    InitArchiveSlots(backHeap);
    func_0204af70(backHeap);
    InitConnection(backHeap);
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        InitWiFiSession(backHeap);
    }
    func_02046a3c(backHeap);
    InitBackupBuffers(backHeap);
    InitSound(soundBuffer, soundBufferSize, ((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2);
    SetSoundOutputEffect(1);
    if (OS_IsRunOnEmulator() == 0) {
        RTC_Init();
    }
    func_02043d10(backHeap);
    CreateBackupAccess(backHeap);
    func_02057ed8(backHeap);
    InitOverlayTable(backHeap);
    func_020cefa0(backHeap);
    func_020471b0(backHeap);
    InitMessageScreen(backHeap);
    func_02057ed4();
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        InitArchiveBuffers(firstFrontHeap, secondFrontHeap, thirdFrontHeap);
    }
    ResetRaceSetup();
    InitBackupAccess();
    ResetCurrentOverlay();
    func_020cef1c();
}
