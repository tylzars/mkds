#include "Main/Unknown/code_020019b0.h"
#include "registers.h"
#include "Main/Unknown/code_02001000.h"
#include "Main/Unknown/code_02001080.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02108e94.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_02125da0.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/unk_02154000.h"
#include "code_0200eddc.h"
#include "code_0214a390.h"
#include "code_0214b824.h"

void LoadBg1FromSceneFiles(Bg1Files *files, s32 mainScreen, const char *paletteFileName, const char *charsFileName,
                           const char *screenMapFileName) {
    LoadNclrData(&files->mPalette, FindSceneFile(paletteFileName));
    DC_StoreRange(files->mPalette->mData, files->mPalette->mDataSize);
    if (mainScreen != 0) {
        GX_LoadBGPltt(files->mPalette->mData, 0, files->mPalette->mDataSize);
    } else {
        GXS_LoadBGPltt(files->mPalette->mData, 0, files->mPalette->mDataSize);
    }
    LoadNcgrData2(&files->mChars, FindSceneFile(charsFileName));
    DC_StoreRange(files->mChars->mData, files->mChars->mDataSize);
    if (mainScreen != 0) {
        GX_LoadBG1Char(files->mChars->mData, 0, files->mChars->mDataSize);
    } else {
        GXS_LoadBG1Char(files->mChars->mData, 0, files->mChars->mDataSize);
    }
    LoadNscrData(&files->mScreenMap, FindSceneFile(screenMapFileName));
    DC_StoreRange(files->mScreenMap->mData, files->mScreenMap->mDataSize);
    if (mainScreen != 0) {
        GX_LoadBG1Scr(files->mScreenMap->mData, 0, files->mScreenMap->mDataSize);
    } else {
        GXS_LoadBG1Scr(files->mScreenMap->mData, 0, files->mScreenMap->mDataSize);
    }
}

void InitLogoScene(void *heap) {
    Unk02125de0Arg arg;
    u8 *displaySettings;
    gLogoScene = HeapAlloc(heap, 60);
    displaySettings = CreateDisplaySettings(heap, data_usa_021547c8);
    SetBg1Record(displaySettings + 0x28, 1, 0, 0, 0, 0, 1, 0);
    SetBg1Record(displaySettings + 0x70, 1, 0, 0, 0, 0, 2, 0);
    InitDisplayFromSettings(displaySettings);
    LoadBg1FromSceneFiles(&gLogoScene->mMainBg, 1, data_usa_ov001_021a768c, data_usa_ov001_021a76a8,
                          data_usa_ov001_021a76c4);
    LoadBg1FromSceneFiles(&gLogoScene->mSubBg, 0, data_usa_ov001_021a76dc, data_usa_ov001_021a76f4,
                          data_usa_ov001_021a770c);
    InitStateMachine(&gLogoScene->mStateMachine, gLogoStateTable, 12, NULL);
    gLogoScene->mUnk_2c_0 = 0;
    gLogoScene->mState0Frames = 0;
    gLogoScene->mCommonMessages = FindFileInLoadedArchives(data_usa_ov001_021a7720);
    arg.mUnk_00 = TRUE;
    arg.mUnk_04 = GetFontByIndex(1);
    arg.mUnk_08 = 0;
    arg.mUnk_10 = 0;
    arg.mUnk_14 = FALSE;
    arg.mUnk_18 = NULL;
    arg.mUnk_1c = FALSE;
    arg.mUnk_20 = FALSE;
    arg.mUnk_24 = 0;
    arg.mUnk_0c = 1;
    LoadTxtSystemAndSelectChoisesAndSelectReturnData();
    func_02125de0(heap, &arg);
}

void ApplySavedSoundMode(void) {
    s32 outputEffect;
    s32 soundMode;
    outputEffect = 0;
    gLogoScene = NULL;
    soundMode = data_0217aa08->mFirstBlock->mSoundMode;
    switch (soundMode) {
        case SOUND_MODE_STEREO:
            break;
        case SOUND_MODE_HEADPHONES:
            outputEffect = 2;
            break;
        case SOUND_MODE_SURROUND:
        default:
            outputEffect = 1;
            break;
    }
    SetSoundOutputEffect(outputEffect);
    func_02125da0();
}

void WriteLogoSceneRegisters(void) {
    s32 brightness;
    s32 frames;
    brightness = 0;
    func_021258f0();
    frames = gLogoScene->mState0Frames;
    if (frames > 90) {
        brightness = (-(frames - 90) * 16) / 30;
    }
    G2x_SetBlendBrightness_(&reg_G2_BLDCNT, 2, brightness);
    G2x_SetBlendBrightness_(&reg_G2S_DB_BLDCNT, 2, brightness);
}

void UpdateLogoScene(SceneNumbersView *sceneNumbers) {
    AdvanceStateMachine(&gLogoScene->mStateMachine);
    if (sceneNumbers != NULL && gLogoScene->mStateMachine.mState == 11) {
        sceneNumbers->mNextScene = 0;
    }
    func_02125928();
}

void EnterLogoState0(void) {
    StartReadBackupFirstBlockAndRecords();
    gLogoScene->mUnk_2c_1 = 0;
}

void UpdateLogoState0(void) {
    s32 slotIndex;
    StateMachine *stateMachine;
    gLogoScene->mState0Frames = gLogoScene->mState0Frames + 1;
    if (gLogoScene->mState0Frames > 120) {
        stateMachine = &gLogoScene->mStateMachine;
        stateMachine->mNextState = 1;
        stateMachine->mNextStateRequested = 1;
    }
    slotIndex = func_020435bc();
    if ((data_02175628[slotIndex].mBits & 0xf03) != 0xf03) {
        return;
    }
    gLogoScene->mUnk_2c_0 = 1;
}
