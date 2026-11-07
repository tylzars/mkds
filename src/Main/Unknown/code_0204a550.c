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

void func_0204a798(KeyRecording *a, u16 b) {
    BOOL f;
    u8 n;
    u8 *e;
    u8 v;
    u16 i;
    s32 s;
    Unk02175650_buf *c;

    s = a->mStatus;
    if (s != 1) {
        return;
    }
    c = a->mBuffer;
    i = a->mPairIndex;
    e = &c->mUnk_04[i * 2];
    v = 0;
    v |= (b & 1) ? 1 : 0;
    v |= (b & 2) ? 2 : 0;
    v |= (b & 0x100) ? 4 : 0;
    v |= (b & 0x600) ? 8 : 0;
    v |= (b & 0x10) ? 0x10 : 0;
    v |= (b & 0x20) ? 0x20 : 0;
    v |= (b & 0x80) ? 0x40 : 0;
    v |= (b & 0x40) ? 0x80 : 0;
    n = e[1];
    f = FALSE;
    if (n != 0 && e[0] != v) {
        f = TRUE;
    } else if (n >= 0xff) {
        f = TRUE;
    }
    if (f != FALSE) {
        if (i >= 0x6e4) {
            if (s != 1) {
                return;
            }
            c->mUnk_00 = (u32) i * 2;
            a->mStatus = 3;
            DC_StoreRange(a->mBuffer, 0xdcc);
            return;
        }
        a->mPairIndex++;
        e += 2;
        e[1] = 0;
    }
    e[0] = v;
    e[1]++;
}

u16 func_0204a664(KeyRecording *a) {
    Unk02175650_buf *b;
    u8 *e;
    u16 i;
    u16 r;
    u8 v;

    if (a->mStatus != 2) {
        return 0;
    }
    b = a->mBuffer;
    i = a->mPairIndex;
    if (i >= b->mUnk_00) {
        a->mStatus = 0;
        return 0;
    }
    e = &b->mUnk_04[i * 2];
    v = e[0];
    r = 0;
    r |= (v & 1) ? 1 : 0;
    r |= (v & 2) ? 2 : 0;
    r |= (v & 4) ? 0x100 : 0;
    r |= (v & 8) ? 0x600 : 0;
    r |= (v & 0x10) ? 0x10 : 0;
    r |= (v & 0x20) ? 0x20 : 0;
    r |= (v & 0x80) ? 0x40 : 0;
    r |= (v & 0x40) ? 0x80 : 0;
    a->mRepeatCount++;
    if (a->mRepeatCount >= e[1]) {
        a->mPairIndex++;
        a->mRepeatCount = 0;
    }
    return r;
}

BOOL func_0204a650(KeyRecording *a) {
    return a->mStatus == 3;
}

BOOL func_0204a620(KeyRecording *a) {
    if (a->mStatus != 2) {
        return FALSE;
    }
    return ((u32) a->mPairIndex << 1) > 0xd1b;
}

void InitEmblemScene(void) {
    GetHeap(GetCurrentHeapCall());
    StopWvrAndWait();
    func_02043c14();
    func_ov001_021a23f4();
}

u32 func_0204a5f4(u32 p0) {
    return p0;
}

void func_0204a5e8(void) {
    func_ov001_021a23c0();
}

void UpdateEmblemScene(Unk0204a598 *a) {
    s32 r;

    r = func_ov001_021a23c8();
    if (a != NULL && r != 0) {
        switch (a->mUnk_00) {
            case 7:
                a->mUnk_04 = 7;
                break;
            default:
                a->mUnk_04 = 0;
                break;
        }
    }
}

s32 RunEmblemScene(void *a) {
    SceneCallbacks b = gEmblemSceneCallbacks;

    RunScene(a, &b);
    return 0;
}
