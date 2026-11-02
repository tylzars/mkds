#include "Main/Unknown/code_02008570.h"
#include "Main/Unknown/code_02008000.h"

#pragma thumb on

static inline u32 func_02008570_inline(u8 *a) {
    u32 b = *(u32 *) (a + 0x80);
    if (b == 0) {
        b = 0x01000000;
    }
    return b;
}

// non-matching: registers: the original keeps param_1, param_2 and the read pointer in r7, r6, r5 and holds 0x160
// in r4 for the add, the read size and the compare (here r5, r7, r6, 0x160 reloaded after the call); it also loads
// v1->mUnk_08 once before the length loop and reuses it for the copy (holding it in a local or an inline helper
// changes which locals are spilled), and reads v6[1] again in the body of the table loop.
int func_02008570(u8 *param_1, int param_2, u32 param_3) {
    Unk02003024 *v1;
    u8 *v2;
    u8 *v3;
    Unk02003024 v4;
    s32 v11;
    s32 v12;
    u32 v13;
    u32 v7;
    Unk0200adfc *v5;
    u32 *v6;
    u32 v8;
    u32 v9;
    s32 v10;
    u32 v14[4];
    v1 = (Unk02003024 *) param_1;
    v2 = (u8 *) param_2;
    v11 = 0;
    if (param_3 >= 0x164) {
        v12 = 0;
        v13 = param_3;
        v3 = v2;
        v5 = 0;
        v6 = 0;
        v3 += 0x160;
        v13 -= 0x160;
        if (v1 != 0) {
            v7 = v1->mUnk_2c - v1->mUnk_20.w.mUnk_04;
            if ((s32) func_020048ac(v1, v3, 0x160) < 0x160) {
                v13 = 0;
            }
            v9 = func_02008570_inline(v2);
        } else {
            v9 = func_02008570_inline((u8 *) 0x027ffe00);
            v12 = 1;
            func_02004d80(&v4);
            func_02004afc(&v4, FS_FindArchive(data_usa_0216178c, 3), 0, v9 + 0x88, -1);
            v1 = &v4;
            v7 = v4.mUnk_2c - v4.mUnk_20.w.mUnk_04;
            func_0214d1fc((const void *) 0x027ffe00, v2, 0x160);
            *(u32 *) (v2 + 0x60) |= 0x00406000;
        }
        if (v13 >= 0x88) {
            func_02004840(v1, v7 + v9, 0);
            func_020048ac(v1, v3, 0x88);
            v3 += 0x88;
            v13 -= 0x88;
        } else {
            v13 = 0;
        }
        if (v13 >= 0x70) {
            v5 = (Unk0200adfc *) v3;
            func_0200aea8((u32) v3);
            v3 += 0x70;
            v13 -= 0x70;
            func_0200ae60(v5, 0, 0x160, (u32) v2, 3);
            v10 = 0;
            while (v10 < 3 && ((s8 *) v1->mUnk_08)[v10] != 0) {
                v10++;
            }
            func_0214d1fc(v1->mUnk_08, v5->mUnk_10, v10);
            v5->mUnk_14 = v10;
        } else {
            v13 = 0;
        }
        if (v13 >= 0x10) {
            v6 = (u32 *) v3;
            v6[0] = 0;
            v6[1] = *(u32 *) (v2 + 0x20) + (v7 + v1->mUnk_20.w.mUnk_04);
            v6[2] = *(u32 *) (v2 + 0x30) + (v7 + v1->mUnk_20.w.mUnk_04);
            v3 += 0x10;
            v13 -= 0x10;
        } else {
            v13 = 0;
        }
        v8 = *(u32 *) (v2 + 0x2c) + *(u32 *) (v2 + 0x3c);
        if (v13 >= v8) {
            v10 = v1->mUnk_20.w.mUnk_04;
            func_02004840(v1, v6[1] - v10, 0);
            func_020048ac(v1, v3, *(u32 *) (v2 + 0x2c));
            func_0200ae60(v5, v6[1], *(u32 *) (v2 + 0x2c), (u32) v3, 3);
            v3 += *(u32 *) (v2 + 0x2c);
            func_02004840(v1, v6[2] - v10, 0);
            func_020048ac(v1, v3, *(u32 *) (v2 + 0x3c));
            func_0200ae60(v5, v6[2], *(u32 *) (v2 + 0x3c), (u32) v3, 3);
            v11 = 1;
        } else if (v13 >= 0xcc00) {
            v10 = v1->mUnk_20.w.mUnk_04;
            v8 = v6[1];
            func_02004840(v1, v8 - v10, 0);
            func_020048ac(v1, v3, 0x4400);
            func_0200ae60(v5, v8, 0x4400, (u32) v3, 3);
            func_02004840(v1, v8 + 0x4400 - v10, 0);
            func_020048ac(v1, v3 + 0x4400, 0x4400);
            func_0200ae60(v5, v8 + 0x4400, 0x4400, (u32) (v3 + 0x4400), 2);
            func_02004840(v1, v8 + 0x8800 - v10, 0);
            func_020048ac(v1, v3 + 0x8800, 0x4400);
            func_0200ae60(v5, v8 + 0x8800, 0x4400, (u32) (v3 + 0x8800), 2);
            v11 = 1;
        }
        func_02004840(v1, v7, 0);
        if (v12 != 0) {
            func_020049e8(&v4);
            if (v11 != 0) {
                v6 = data_usa_02161788;
                v14[0] = *(u32 *) (v2 + 0x20);
                v14[1] = *(u32 *) (v2 + 0x28) - *(u32 *) (v2 + 0x20);
                v14[2] = *(u32 *) ((u8 *) v5 + 0x48) - *(u32 *) (v2 + 0x20);
                v14[3] = param_3;
                func_0200850c(v14, 0x4000, 0x8000, 1);
                while (v6[1] != 0) {
                    func_0200850c(v14, v6[0], v6[0] + v6[1], 0);
                    v6 += 2;
                }
                *(u32 *) (*(u32 *) ((u8 *) v5 + 0x48) + (0x02000a58 - *(u32 *) (v2 + 0x28))) = 0xe12fff1e;
            }
        }
        if (v11 != 0) {
            func_0200ee74(v2, param_3);
        }
    }
    return v11;
}

#pragma thumb off
