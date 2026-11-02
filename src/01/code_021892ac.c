#include "01/code_021892ac.h"
#include "01/code_02188e88.h"
#include "01/code_02188950.h"
#include "01/code_021857a4.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "01/code_0218c000.h"
#include "Main/Unknown/code_020a3000.h"

#pragma thumb off

void func_ov001_021899c8(void *a) {
    func_020c092c(a, data_ov001_021a9bc0, 0);
}

s32 func_ov001_021899b0(void) {
    return func_020c0c2c(&data_ov001_021a9bbc, 0x1f8);
}

void func_ov001_0218999c(void) {
    func_020c0b84(&data_ov001_021a9bbc);
}

void func_ov001_02189880(void) {
    s32 i;
    s32 count;
    u32 unk;
    Unk0217b498_00 *elem;
    Vec3 *pos;

    count = 0;
    unk = func_020c0db0();
    for (i = 0; i < data_ov001_021a9bbc->mUnk_08; i++) {
        elem = data_ov001_021a9bbc->mUnk_00[i];
        if (elem->mUnk_02 & 1) {
            continue;
        }
        pos = &elem->mUnk_04;
        if (func_020b5ae8(pos, &data_ov001_021a9bbc->mUnk_10[count].mUnk_00, unk, 1, 1)) {
            data_ov001_021a9bbc->mUnk_10[count].mUnk_08 = GetRaceSNcerEntry(0xc5);
            data_ov001_021a9bbc->mUnk_10[count].mUnk_0c = func_020b4e70(pos) ? 2 : 3;
            data_ov001_021a9bbc->mUnk_10[count].mUnk_0e = elem->mUnk_02 & 0x20;
            data_ov001_021a9bbc->mUnk_10[count].mUnk_10 = elem->mUnk_7e;
            count++;
        }
    }
    data_ov001_021a9bbc->mUnk_04 = count;
}

void func_ov001_02189864(void *a) {
    func_020c092c(a, data_ov001_021a9bbc, 0);
}

s32 func_ov001_02189848(void) {
    return func_020c0c2c(&data_ov001_021a9bb8, 0x1f5);
}

void func_ov001_02189834(void) {
    func_020c0b84(&data_ov001_021a9bb8);
}

void func_ov001_02189718(void) {
    s32 i;
    s32 count;
    u32 unk;
    Unk0217b498_00 *elem;
    Vec3 *pos;

    count = 0;
    unk = func_020c0db0();
    for (i = 0; i < data_ov001_021a9bb8->mUnk_08; i++) {
        elem = data_ov001_021a9bb8->mUnk_00[i];
        if (elem->mUnk_02 & 1) {
            continue;
        }
        pos = &elem->mUnk_04;
        if (func_020b5ae8(pos, &data_ov001_021a9bb8->mUnk_10[count].mUnk_00, unk, 1, 1)) {
            data_ov001_021a9bb8->mUnk_10[count].mUnk_08 = GetRaceSNcerEntry(0xc5);
            data_ov001_021a9bb8->mUnk_10[count].mUnk_0c = func_020b4e70(pos) ? 2 : 3;
            data_ov001_021a9bb8->mUnk_10[count].mUnk_0e = elem->mUnk_02 & 0x20;
            data_ov001_021a9bb8->mUnk_10[count].mUnk_10 = elem->mUnk_7e;
            count++;
        }
    }
    data_ov001_021a9bb8->mUnk_04 = count;
}

void func_ov001_021896fc(void *a) {
    func_020c092c(a, data_ov001_021a9bb8, 0);
}

s32 func_ov001_021896e0(void) {
    return func_020c0c2c(&data_ov001_021a9bb4, 0x159);
}

void func_ov001_021896cc(void) {
    func_020c0b84(&data_ov001_021a9bb4);
}

void func_ov001_021895b8(void) {
    s32 i;
    s32 count;
    u32 unk;
    Unk0217b498_00 *elem;
    Vec3 *pos;

    count = 0;
    unk = func_020c0db0();
    for (i = 0; i < data_ov001_021a9bb4->mUnk_08; i++) {
        elem = data_ov001_021a9bb4->mUnk_00[i];
        pos = &elem->mUnk_04;
        if (func_020b5ae8(pos, &data_ov001_021a9bb4->mUnk_10[count].mUnk_00, unk, 1, 1)) {
            data_ov001_021a9bb4->mUnk_10[count].mUnk_08 = GetRaceSNcerEntry(0x5b);
            data_ov001_021a9bb4->mUnk_10[count].mUnk_0c = func_020b4e70(pos) ? 2 : 3;
            data_ov001_021a9bb4->mUnk_10[count].mUnk_0e = 0;
            data_ov001_021a9bb4->mUnk_10[count].mUnk_10 = elem->mUnk_7e;
            count++;
        }
    }
    data_ov001_021a9bb4->mUnk_04 = count;
}

void func_ov001_0218959c(void *a) {
    func_020c092c(a, data_ov001_021a9bb4, 1);
}

s32 func_ov001_02189584(void) {
    return func_020c0c2c(&data_ov001_021a9bb0, 0x6e);
}

void func_ov001_02189570(void) {
    func_020c0b84(&data_ov001_021a9bb0);
}

void func_ov001_02189444(void) {
    s32 i;
    s32 count;
    u32 unk;
    Unk0217b498_00 *elem;
    Vec3 *pos;

    count = 0;
    unk = func_020c0db0();
    for (i = 0; i < data_ov001_021a9bb0->mUnk_08; i++) {
        elem = data_ov001_021a9bb0->mUnk_00[i];
        pos = &elem->mUnk_04;
        if (func_020b5ae8(pos, &data_ov001_021a9bb0->mUnk_10[count].mUnk_00, unk, 1, 1)) {
            data_ov001_021a9bb0->mUnk_10[count].mUnk_08 =
                GetRaceSNcerEntry(func_ov001_02185b50((Unk02185bb8 *) elem) ? 0x5a : 0x59);
            data_ov001_021a9bb0->mUnk_10[count].mUnk_0c = func_020b4e70(pos) ? 2 : 3;
            data_ov001_021a9bb0->mUnk_10[count].mUnk_0e = 0;
            data_ov001_021a9bb0->mUnk_10[count].mUnk_10 = elem->mUnk_7e;
            count++;
        }
    }
    data_ov001_021a9bb0->mUnk_04 = count;
}

void func_ov001_02189428(void *a) {
    func_020c092c(a, data_ov001_021a9bb0, 1);
}

s32 func_ov001_02189410(void) {
    return func_020c0c2c(&data_ov001_021a9bac, 0x1fc);
}

void func_ov001_021893fc(void) {
    func_020c0b84(&data_ov001_021a9bac);
}

void func_ov001_021892c8(void) {
    s32 i;
    s32 count;
    u32 unk;
    Unk0217b498_00 *elem;
    Vec3 *pos;

    count = 0;
    unk = func_020c0db0();
    for (i = 0; i < data_ov001_021a9bac->mUnk_08; i++) {
        elem = data_ov001_021a9bac->mUnk_00[i];
        if (elem->mUnk_02 & 1) {
            continue;
        }
        pos = &elem->mUnk_04;
        if (func_020b5ae8(pos, &data_ov001_021a9bac->mUnk_10[count].mUnk_00, unk, 1, 1)) {
            data_ov001_021a9bac->mUnk_10[count].mUnk_08 =
                GetRaceSNcerEntry(func_ov001_0218c790((Unk02188950 *) elem) >= 2 ? 0xc6 : 0xc5);
            data_ov001_021a9bac->mUnk_10[count].mUnk_0c = func_020b4e70(pos) ? 2 : 3;
            data_ov001_021a9bac->mUnk_10[count].mUnk_0e = elem->mUnk_02 & 0x20;
            data_ov001_021a9bac->mUnk_10[count].mUnk_10 = elem->mUnk_7e;
            count++;
        }
    }
    data_ov001_021a9bac->mUnk_04 = count;
}

void func_ov001_021892ac(void *a) {
    func_020c092c(a, data_ov001_021a9bac, 0);
}

#pragma thumb on
