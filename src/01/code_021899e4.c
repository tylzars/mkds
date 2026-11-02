#include "01/code_021899e4.h"

#include "01/unk_021a6000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020b47b4.h"
#include "00/code_02182fdc.h"

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
    Unk020b4a44 *res;
    Vec3 *pos;

    var = func_020c0db0();
    for (i = 0; i < data_ov001_021a9bc0->mUnk_08; i++) {
        obj = data_ov001_021a9bc0->mUnk_00[i];
        if (!(obj->mUnk_02 & 1)) {
            pos = &obj->mUnk_04;
            if (func_020b5ae8(pos, &data_ov001_021a9bc0->mUnk_10[count].mUnk_00, var, 1, 1)) {
                row = func_ov001_0218b2d4((Unk02188950 *) obj);
                dst = GetRaceNclrNcgr(6)->mNclr->mUnk_0c;
                res = 0;
                LocateNclr((Unk020b4a44 **) (&res), (void *) (FindSceneFileWrapper("race_transfer_map_mr_s_o.NCLR")));
                for (k = 0; k < 16; k++) {
                    dst[0x50 + k] = res->mUnk_0c[(row + 2) * 16 + k];
                }
                func_0200ee74(GetRaceNclrNcgr(6)->mNclr->mUnk_0c, GetRaceNclrNcgr(6)->mNclr->mUnk_08);
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
