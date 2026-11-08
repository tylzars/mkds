#include "Main/Unknown/code_0203be88.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_0203ba84.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02056444.h"
#include "Main/Unknown/code_020ada2c.h"
#include "Main/Unknown/code_020adb04.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"
#include "code_0214d93c.h"
#include "Main/Unknown/code_0203d568.h"
#include "Main/Unknown/code_020ad32c.h"
#include "Main/Unknown/code_020ada94.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_02039000.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_02039774.h"
#include "Main/Unknown/code_0204a550.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020ad344.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_021759c0.h"
#include "01/code_0218155c.h"
#include "Main/Unknown/code_0203e74c.h"

void func_0203c1a8(Vec3 *position, u32 kartIndex) {
    s32 v;
    if (func_0204176c(position, &v) == 0) {
        return;
    }
    if (v != 0) {
        if (gRaceSetup->mMode == MODE_MISSION_RUN) {
            func_ov001_021816fc();
        }
        if (gRaceSetup->mMode != MODE_MISSION_RUN) {
            return;
        }
        FinishRaceProgressKartWithEndKind(kartIndex, 0);
    } else {
        FinishRaceProgressKartWithEndKind(kartIndex, 6);
    }
}

BOOL IsFramesSinceFinishPastWait(void) {
    return gRaceProgress->mFramesSinceFinish > gRaceSetup->mFinishWaitFrameCount;
}

u32 func_0203c0bc(void) {
    u32 framesSinceEntryEnd;
    s32 entryIndex = gRaceSetup->mEntryIndex;
    if (entryIndex == -1) {
        return 0;
    }
    if (gRaceProgress->mUnk_000[0].mUnk_0a >= 7) {
        return 1;
    }
    if (func_0204a620((KeyRecording *) &data_02175628[entryIndex].mUnk_28) != FALSE) {
        return 1;
    }
    if (TryGetRaceUpdateFramesSinceEntryEnd(&framesSinceEntryEnd) != 0) {
        if (framesSinceEntryEnd > 0x384) {
            return 1;
        }
    }
    return 0;
}

void InitTitleScene(void) {
    GetHeap(GetCurrentHeapCall());
    ClearLcdcBankAndStartWvrAndWait();
    CreateTitleScene();
    ResetInputSlots();
}

void ReleaseTitleScene(void) {
    u32 unused;
    func_020ad32c();
}

void func_0203c07c(void) {
    u32 unused;
    func_020ada94();
}

void UpdateTitleScene(s32 a) {
    PrepareDisplayFrame();
    AdvanceTitleStates(a);
}

u32 RunTitleScene(SceneNumbers *sceneNumbers) {
    SceneCallbacks callbacks = gTitleSceneCallbacks;
    RunScene(sceneNumbers, &callbacks);
    return 0;
}

void GetClockDateOrDefault(s32 *date) {
    if (RTC_GetDate((RTCDate *) date) != 0) {
        date[0] = 5;
        date[1] = 1;
        date[2] = 1;
    }
}

void GetClockTimeOrZero(RTCTime *time) {
    if (RTC_GetTime(time) != 0) {
        time->mHour = 0;
        time->mMinute = 0;
        time->mSecond = 0;
    }
}

void func_0203bf04(Unk0203bf04_a *courseGhost, Unk0203bf04_b *slotGhost) {
    MI_CpuCopy8(courseGhost, slotGhost, 0x30);
    MI_CpuCopy8(courseGhost->mUnk_030, slotGhost->mUnk_230, 0xdcc);
    if (data_0217aa08->mEmblemRecord->mFilled != 0 && data_0217aa08->mUnk_00->mUnk_31_3 == 0) {
        MI_CpuCopy8(data_0217aa08->mEmblemRecord->mEmblemData, slotGhost->mUnk_030, 0x200);
        slotGhost->mUnk_008 |= 2;
    } else {
        MI_CpuFill8(slotGhost->mUnk_030, 0, 0x200);
        slotGhost->mUnk_008 &= ~2;
    }
    slotGhost->mUnk_02f_0 = func_02056208();
}

#pragma thumb on

u8 *func_0203bedc(void *heap) {
    CharacterKartPicks *picks;
    void *kartAppear;
    picks = HeapAlloc(heap, 0x48);
    kartAppear = CreateKartAppear(heap);
    picks->mKartAppear = kartAppear;
    InitCharacterKartPicks((u8 *) picks);
    return (u8 *) picks;
}

void InitCharacterKartPicks(u8 *rawPicks) {
    CharacterKartPicks *picks = (CharacterKartPicks *) rawPicks;
    u8 entryIndex;
    picks->mKartGivenBits = 0;
    picks->mCharacterGivenBits = 0;
    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        picks->mCharacterIndices[entryIndex] = -1;
        picks->mKartIndices[entryIndex] = -1;
    }
}

void SetGivenCharacter(u8 *rawPicks, u32 entryIndex, u32 characterIndex) {
    CharacterKartPicks *picks = (CharacterKartPicks *) rawPicks;
    picks->mCharacterGivenBits |= 1 << entryIndex;
    picks->mCharacterIndices[entryIndex] = characterIndex;
}

void SetGivenKart(u8 *rawPicks, u32 entryIndex, u32 kartIndex) {
    CharacterKartPicks *picks = (CharacterKartPicks *) rawPicks;
    picks->mKartGivenBits |= 1 << entryIndex;
    picks->mKartIndices[entryIndex] = kartIndex;
}
