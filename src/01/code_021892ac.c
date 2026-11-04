#include "01/code_021892ac.h"

#include "01/code_02188e88.h"
#include "01/code_02188950.h"
#include "01/code_021857a4.h"
#include "01/code_0218c790.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020b4000.h"
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
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "01/code_0218c000.h"
#include "Main/Unknown/code_020a3000.h"
#include "01/code_0218b298.h"
#include "01/code_0218f900.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_020b85f0.h"
#include "Main/Unknown/code_020b8624.h"
#include "00/code_02181f98.h"
#include "code_0200eddc.h"

Unk0217b498 *data_ov001_021a9bc4;

#pragma thumb off

s32 func_ov001_02189d88(void) {
    return func_020c0c2c(&data_ov001_021a9bc4, 0x1fb);
}

void func_ov001_02189d74(void) {
    func_020c0b84(&data_ov001_021a9bc4);
}

void func_ov001_02189c10(void) {
    u32 var;
    s32 i;
    s32 count = 0;
    u32 arg;
    Unk0217b498_00 *obj;
    Vec3 *pos;

    var = func_020c0db0();
    for (i = 0; i < data_ov001_021a9bc4->mUnk_08; i++) {
        obj = data_ov001_021a9bc4->mUnk_00[i];
        if (!(obj->mUnk_02 & 1)) {
            pos = &obj->mUnk_04;
            if (func_020b5ae8(pos, &data_ov001_021a9bc4->mUnk_10[count].mUnk_00, var, 1, 1)) {
                if (func_ov001_0218f9c0((Unk02188950 *) obj)) {
                    arg = (obj->mUnk_02 & 0x400) ? 0xc8 : 0xc6;
                } else {
                    arg = (obj->mUnk_02 & 0x400) ? 0xc7 : 0xc5;
                }
                data_ov001_021a9bc4->mUnk_10[count].mUnk_08 = GetRaceSNcerEntry(arg);
                data_ov001_021a9bc4->mUnk_10[count].mUnk_0c = func_020b4e70(pos) ? 2 : 3;
                data_ov001_021a9bc4->mUnk_10[count].mUnk_0e = obj->mUnk_02 & 0x20;
                data_ov001_021a9bc4->mUnk_10[count].mUnk_10 = obj->mUnk_7e;
                count++;
            }
        }
    }
    data_ov001_021a9bc4->mUnk_04 = count;
}

void func_ov001_02189bf4(void *a) {
    func_020c092c(a, data_ov001_021a9bc4, 0);
}

s32 func_ov001_02189bd8(void) {
    return func_020c0c2c(&data_ov001_021a9bc0, 0x1f7);
}

void func_ov001_02189bc4(void) {
    func_020c0b84(&data_ov001_021a9bc0);
}

void func_ov001_021899e4(void) {
    u32 var;
    s32 i;
    s32 count = 0;
    s32 row;
    s32 k;
    Unk0217b498_00 *obj;
    u16 *dst;
    Nclr *nclr;
    Vec3 *pos;

    var = func_020c0db0();
    for (i = 0; i < data_ov001_021a9bc0->mUnk_08; i++) {
        obj = data_ov001_021a9bc0->mUnk_00[i];
        if (!(obj->mUnk_02 & 1)) {
            pos = &obj->mUnk_04;
            if (func_020b5ae8(pos, &data_ov001_021a9bc0->mUnk_10[count].mUnk_00, var, 1, 1)) {
                row = func_ov001_0218b2d4((Unk02188950 *) obj);
                dst = GetRaceNclrNcgr(6)->mNclr->mData;
                nclr = NULL;
                LocateNclr((Nclr **) (&nclr), (void *) (FindSceneFileWrapper("race_transfer_map_mr_s_o.NCLR")));
                for (k = 0; k < 16; k++) {
                    dst[0x50 + k] = nclr->mData[(row + 2) * 16 + k];
                }
                func_0200ee74(GetRaceNclrNcgr(6)->mNclr->mData, GetRaceNclrNcgr(6)->mNclr->mDataSize);
                data_ov001_021a9bc0->mUnk_10[count].mUnk_08 = GetRaceSNcerEntry(0xc5);
                data_ov001_021a9bc0->mUnk_10[count].mUnk_0c = func_020b4e70(pos) ? 2 : 3;
                data_ov001_021a9bc0->mUnk_10[count].mUnk_0e = obj->mUnk_02 & 0x20;
                data_ov001_021a9bc0->mUnk_10[count].mUnk_10 = obj->mUnk_7e;
                count++;
            }
        }
    }
    data_ov001_021a9bc0->mUnk_04 = count;
}

#pragma thumb on

Unk0217b498 *data_ov001_021a9bac;
Unk0217b498 *data_ov001_021a9bb0;
Unk0217b498 *data_ov001_021a9bb4;
Unk0217b498 *data_ov001_021a9bb8;
Unk0217b498 *data_ov001_021a9bbc;
Unk0217b498 *data_ov001_021a9bc0;

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
                GetRaceSNcerEntry(func_ov001_02185b50((MissionGateObject *) elem) ? 0x5a : 0x59);
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
