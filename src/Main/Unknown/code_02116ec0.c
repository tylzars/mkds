#include "Main/Unknown/code_02116ec0.h"

#include "Main/Unknown/code_0203ba84.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/code_02029000.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_0203be48.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0202056c.h"
#include "Main/Unknown/code_02036820.h"

#pragma thumb on

void func_0211717c(void *a) {
    u32 v1;
    v1 = ((u32) HeapAlloc(a, 4));
    *(u32 *) &data_0217d358 = v1;
    v1 = (u32) func_0203bedc(a);
    *(u32 *) (*(u32 *) &data_0217d358) = v1;
}

#pragma thumb off

#pragma thumb on

void func_02117170(void) {
    data_0217d358 = NULL;
}

void func_021170f8(void) {
    int n;
    BOOL c;
    u32 a, b;

    func_0203bec0(data_0217d358->mUnk_00);
    if (data_021759d0->mUnk_20 == 0) {
        n = 1;
    } else {
        c = TRUE;
        if (data_0217aa00->mUnk_0004 != 8 && data_0217aa00->mUnk_0004 != 9) {
            c = FALSE;
        }
        n = (u8) (c != FALSE ? CountSetBits(data_0217aa00->mParticipantMask) : 0);
    }
    a = 0;
    b = ~0;
    for (; n < 8; n++) {
        SetCharacterIndex(n, b);
        func_020294ac(n, a);
    }
}

void func_02117060(void) {
    int i;
    int n;
    BOOL c;
    u32 a, b;

    func_0203bec0(data_0217d358->mUnk_00);
    if (data_021759d0->mUnk_20 == 0) {
        n = 1;
    } else {
        c = TRUE;
        if (data_0217aa00->mUnk_0004 != 8 && data_0217aa00->mUnk_0004 != 9) {
            c = FALSE;
        }
        n = (u8) (c != FALSE ? CountSetBits(data_0217aa00->mParticipantMask) : 0);
    }
    for (i = 0; i < 8; i++) {
        func_0203bea4(data_0217d358->mUnk_00, (u8) i, GetCharacterIndex(i));
    }
    a = 0;
    b = ~0;
    for (; n < 8; n++) {
        SetKartIndex(n, b);
        func_020294ac(n, a);
    }
}

void func_02116fb0(void) {
    int i;
    int n;
    BOOL c;
    u32 v;

    v = ~0;
    if (data_021759d0->mUnk_20 == 0) {
        n = 1;
    } else {
        c = TRUE;
        if (data_0217aa00->mUnk_0004 != 8 && data_0217aa00->mUnk_0004 != 9) {
            c = FALSE;
        }
        n = (u8) (c != FALSE ? CountSetBits(data_0217aa00->mParticipantMask) : 0);
    }
    for (i = 0; i < n; i++) {
        func_0203bea4(data_0217d358->mUnk_00, (u8) i, GetCharacterIndex(i));
    }
    PickRandomCharacters(data_0217d358->mUnk_00);
    for (; n < 8; n++) {
        func_0203be48(data_0217d358->mUnk_00, n, &v, NULL);
        SetCharacterIndex(n, v);
    }
}

void func_02116ef8(void) {
    int i;
    int n;
    BOOL c;
    u32 v;

    v = ~0;
    if (data_021759d0->mUnk_20 == 0) {
        n = 1;
    } else {
        c = TRUE;
        if (data_0217aa00->mUnk_0004 != 8 && data_0217aa00->mUnk_0004 != 9) {
            c = FALSE;
        }
        n = (u8) (c != FALSE ? CountSetBits(data_0217aa00->mParticipantMask) : 0);
    }
    for (i = 0; i < n; i++) {
        func_0203be88(data_0217d358->mUnk_00, (u8) i, GetKartIndex(i));
    }
    PickRandomKarts(data_0217d358->mUnk_00);
    for (; n < 8; n++) {
        func_0203be48(data_0217d358->mUnk_00, n, NULL, &v);
        SetKartIndex(n, v);
        func_020294ac(n, 1);
    }
}

void func_02116ec0(void) {
    int i;

    for (i = 0; i < 8; i++) {
        SetKartIndex(i, data_0215c5d8[GetCharacterIndex(i)]);
        func_020294ac(i, 1);
    }
}

#pragma thumb off
