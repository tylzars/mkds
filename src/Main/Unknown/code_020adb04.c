#include "Main/Unknown/code_020adb04.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/code_020add18.h"
#include "Main/Unknown/code_020add90.h"
#include "Main/Unknown/code_0205f000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02022aa8.h"

#pragma optimize_for_size on

void func_020adce0(u32 *a, Unk02022aa8 *b, u32 c) {
    GetFontGlyph(a, b, func_020add90(b, c));
}

#pragma thumb on

s32 func_020adc7c(const u16 *a, u16 *b) {
    s32 i;
    s32 v1;
    s32 t;
    u32 v[2];
    void *p;

    v1 = 0;
    p = func_020b403c(0);
    func_020addb8(b, 0, 0x14);
    for (i = 0; i < 10; i++) {
        if (a[i] == 0) {
            return i;
        }
        func_020adce0(v, p, a[i]);
        t = ((NNSG2dCharWidths *) v[0])->mCharWidth;
        if (v1 + t > 0x30) {
            return i;
        }
        v1 += t + 1;
        b[i] = a[i];
    }
    return 10;
}

s16 func_020adc64(s32 a) {
    if (a < 0) {
        a = 0;
    }
    if (a >= 6) {
        a = 5;
    }
    return data_02156868[a];
}

BOOL func_020adc24(MinuteSecondMillisecondTime *a, MinuteSecondMillisecondTime *b) {
    s32 x;
    s32 y;

    x = a->mMillisecond + (a->mSecond * 1000 + a->mMinute * 60000);
    y = b->mMillisecond + (b->mSecond * 1000 + b->mMinute * 60000);
    if (x < y) {
        return TRUE;
    }
    return FALSE;
}

s32 func_020adc04(void) {
    s32 v;
    s32 a;
    s32 b;

    a = func_020adbe4();
    b = func_020adbc4();
    return func_0205fd78(a, b, &v);
}

#pragma thumb off

s32 func_020adbe4(void) {
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        return gRaceSetup->mMissionTableRow;
    }
    return -1;
}

s32 func_020adbc4(void) {
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        return gRaceSetup->mMissionTableColumn;
    }
    return -1;
}

#pragma thumb on

BOOL func_020adb34(void) {
    s32 i;
    s32 j;
    s32 r;
    s32 v;

    if (func_020adbe4() < 1 || func_020adbe4() > 6 || func_020adbc4() < 1 || func_020adbc4() > 9) {
        return FALSE;
    }
    for (i = 1; i <= 6; i++) {
        for (j = 1; j <= 9; j++) {
            r = func_0205fd78(i, j, &v);
            if (i == func_020adbe4() && j == func_020adbc4()) {
                if (r != 0 && (u32) (v - 5) <= 2) {
                    return FALSE;
                }
            } else {
                if (r != 0) {
                    switch (v) {
                        case 5:
                        case 6:
                        case 7:
                            break;
                        default:
                            return FALSE;
                    }
                } else {
                    return FALSE;
                }
            }
        }
    }
    return TRUE;
}

void InitTitleStateHandlers(void) {
    s32 i;

    for (i = 0; i < 7; i++) {
        gTitleScene->mStateHandlers[i].mUnk_00 = gTitleStateHandlers[i].mUnk_00;
        gTitleScene->mStateHandlers[i].mUpdate = gTitleStateHandlers[i].mUpdate;
    }
}

#pragma thumb off
