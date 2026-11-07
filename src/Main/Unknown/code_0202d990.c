#include "Main/Unknown/code_0202d990.h"
#include "Main/Unknown/code_0202dd9c.h"
#include "Main/Unknown/code_0202e43c.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020578fc.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/unk_02174000.h"

#pragma opt_arithtransformation off

#pragma thumb on

s32 func_0202dd80(s32 a) {
    return a < data_02174e44->mUnk_80c ? 0 : 1;
}

void func_0202dcf4(u32 a, void *b) {
    u32 e;
    u8 *p;
    s32 n;
    if (func_0202dd80(a) == 0) {
        e = func_0202e43c(data_02174e44->mUnk_814[a]);
        p = data_02174e44->mUnk_8bc;
        n = func_0204684c(e);
        GetGhostRecordTime(p + n * 0x30, b);
    } else {
        a -= data_02174e44->mUnk_80c;
        GetGhostRecordTime((u8) data_02174e44->mUnk_894[a] * 0x230 + data_02174e44->mUnk_8c0, b);
    }
}

void func_0202dc68(u32 a, void *b) {
    u32 e;
    u8 *p;
    s32 n;
    if (func_0202dd80(a) == 0) {
        e = func_0202e43c(data_02174e44->mUnk_814[a]);
        p = data_02174e44->mUnk_8bc;
        n = func_0204684c(e);
        GetGhostRecordName(p + n * 0x30, b);
    } else {
        a -= data_02174e44->mUnk_80c;
        GetGhostRecordName((u8) data_02174e44->mUnk_894[a] * 0x230 + data_02174e44->mUnk_8c0, b);
    }
}

u32 func_0202dbe8(u32 a) {
    u32 e;
    u8 *p;
    s32 n;
    if (func_0202dd80(a) == 0) {
        e = func_0202e43c(data_02174e44->mUnk_814[a]);
        p = data_02174e44->mUnk_8bc;
        n = func_0204684c(e);
        return GetGhostRecordCharacterIndex(p + n * 0x30);
    }
    a -= data_02174e44->mUnk_80c;
    return GetGhostRecordCharacterIndex((u8) data_02174e44->mUnk_894[a] * 0x230 + data_02174e44->mUnk_8c0);
}

u32 func_0202db68(u32 a) {
    u32 e;
    u8 *p;
    s32 n;
    if (func_0202dd80(a) == 0) {
        e = func_0202e43c(data_02174e44->mUnk_814[a]);
        p = data_02174e44->mUnk_8bc;
        n = func_0204684c(e);
        return GetGhostRecordKartIndex(p + n * 0x30);
    }
    a -= data_02174e44->mUnk_80c;
    return GetGhostRecordKartIndex((u8) data_02174e44->mUnk_894[a] * 0x230 + data_02174e44->mUnk_8c0);
}

u32 func_0202db04(u32 a) {
    u8 *p;
    if (func_0202dd80(a) == 0) {
        return func_0202e43c(data_02174e44->mUnk_814[a]);
    }
    a -= data_02174e44->mUnk_80c;
    p = data_02174e44->mUnk_8c0;
    return GetGhostRecordCourseId(p + (u8) data_02174e44->mUnk_894[a] * 0x230);
}

void func_0202daa4(s32 a) {
    s32 x;
    if (func_0202dd80(a) == 0) {
        x = data_02174e44->mUnk_814[a];
        func_0205798c(x, func_0202ddec());
    } else {
        x = data_02174e44->mUnk_894[a - func_0202ddb0()];
        func_020578fc((u8) x, (GhostRecord *) func_0202ddd8());
    }
}

s32 func_0202da44(s32 a) {
    s32 i;
    BOOL r;
    r = FALSE;
    for (i = 0; i < (s32) func_0202dd9c(); i++) {
        if (a == GetGhostRecordCourseId((u8) data_02174e44->mUnk_894[i] * 0x230 + data_02174e44->mUnk_8c0)) {
            r = TRUE;
            break;
        }
    }
    return r;
}

s32 func_0202d9fc(void) {
    s32 i;
    for (i = 0; i < 10; i++) {
        if (IsGhostRecordFilled(data_02174e44->mUnk_8c0 + (u8) i * 0x230) == FALSE) {
            return i;
        }
    }
    return -1;
}

s32 func_0202d990(s32 a) {
    s32 i;
    s32 r;
    r = -1;
    for (i = 0; i < (s32) func_0202dd9c(); i++) {
        if (a == GetGhostRecordCourseId((u8) data_02174e44->mUnk_894[i] * 0x230 + data_02174e44->mUnk_8c0)) {
            r = data_02174e44->mUnk_894[i];
            break;
        }
    }
    return r;
}

#pragma thumb off
