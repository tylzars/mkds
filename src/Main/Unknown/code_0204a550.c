#include "Main/Unknown/code_0204a550.h"
#include "Main/Unknown/code_02039774.h"
#include "Main/Unknown/code_020435c4.h"

#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/unk_02165000.h"
#include "01/code_021a2398.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0200eddc.h"

void AppendKeysToKeyRecording(KeyRecording *keyRecording, u16 keys) {
    BOOL startsNewPair;
    u8 repeatCount;
    u8 *pair;
    u8 packedKeys;
    u16 pairIndex;
    s32 status;
    KeyRecordingBuffer *buffer;

    status = keyRecording->mStatus;
    if (status != 1) {
        return;
    }
    buffer = keyRecording->mBuffer;
    pairIndex = keyRecording->mPairIndex;
    pair = &buffer->mPairs[pairIndex * 2];
    packedKeys = 0;
    packedKeys |= (keys & 1) ? 1 : 0;
    packedKeys |= (keys & 2) ? 2 : 0;
    packedKeys |= (keys & 0x100) ? 4 : 0;
    packedKeys |= (keys & 0x600) ? 8 : 0;
    packedKeys |= (keys & 0x10) ? 0x10 : 0;
    packedKeys |= (keys & 0x20) ? 0x20 : 0;
    packedKeys |= (keys & 0x80) ? 0x40 : 0;
    packedKeys |= (keys & 0x40) ? 0x80 : 0;
    repeatCount = pair[1];
    startsNewPair = FALSE;
    if (repeatCount != 0 && pair[0] != packedKeys) {
        startsNewPair = TRUE;
    } else if (repeatCount >= 0xff) {
        startsNewPair = TRUE;
    }
    if (startsNewPair != FALSE) {
        if (pairIndex >= 0x6e4) {
            if (status != 1) {
                return;
            }
            buffer->mUnk_00 = (u32) pairIndex * 2;
            keyRecording->mStatus = 3;
            DC_StoreRange(keyRecording->mBuffer, 0xdcc);
            return;
        }
        keyRecording->mPairIndex++;
        pair += 2;
        pair[1] = 0;
    }
    pair[0] = packedKeys;
    pair[1]++;
}

u16 ReadKeysFromKeyRecording(KeyRecording *keyRecording) {
    KeyRecordingBuffer *buffer;
    u8 *pair;
    u16 pairIndex;
    u16 keys;
    u8 packedKeys;

    if (keyRecording->mStatus != 2) {
        return 0;
    }
    buffer = keyRecording->mBuffer;
    pairIndex = keyRecording->mPairIndex;
    if (pairIndex >= buffer->mUnk_00) {
        keyRecording->mStatus = 0;
        return 0;
    }
    pair = &buffer->mPairs[pairIndex * 2];
    packedKeys = pair[0];
    keys = 0;
    keys |= (packedKeys & 1) ? 1 : 0;
    keys |= (packedKeys & 2) ? 2 : 0;
    keys |= (packedKeys & 4) ? 0x100 : 0;
    keys |= (packedKeys & 8) ? 0x600 : 0;
    keys |= (packedKeys & 0x10) ? 0x10 : 0;
    keys |= (packedKeys & 0x20) ? 0x20 : 0;
    keys |= (packedKeys & 0x80) ? 0x40 : 0;
    keys |= (packedKeys & 0x40) ? 0x80 : 0;
    keyRecording->mRepeatCount++;
    if (keyRecording->mRepeatCount >= pair[1]) {
        keyRecording->mPairIndex++;
        keyRecording->mRepeatCount = 0;
    }
    return keys;
}

BOOL IsKeyRecordingFull(KeyRecording *keyRecording) {
    return keyRecording->mStatus == 3;
}

BOOL func_0204a620(KeyRecording *keyRecording) {
    if (keyRecording->mStatus != 2) {
        return FALSE;
    }
    return ((u32) keyRecording->mPairIndex << 1) > 0xd1b;
}

void InitEmblemScene(void) {
    GetHeap(GetCurrentHeapCall());
    StopWvrAndWait();
    ResetInputSlots();
    func_ov001_021a23f4();
}

u32 func_0204a5f4(u32 value) {
    return value;
}

void func_0204a5e8(void) {
    func_ov001_021a23c0();
}

void UpdateEmblemScene(EmblemSceneNumbersView *sceneNumbers) {
    s32 r;

    r = func_ov001_021a23c8();
    if (sceneNumbers != NULL && r != 0) {
        switch (sceneNumbers->mUnk_00) {
            case 7:
                sceneNumbers->mUnk_04 = 7;
                break;
            default:
                sceneNumbers->mUnk_04 = 0;
                break;
        }
    }
}

s32 RunEmblemScene(void *sceneNumbers) {
    SceneCallbacks emblemSceneCallbacks = gEmblemSceneCallbacks;

    RunScene(sceneNumbers, &emblemSceneCallbacks);
    return 0;
}
