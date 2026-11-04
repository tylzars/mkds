#include "Main/Unknown/code_020091fc.h"
#include "code_02003024.h"
#include "code_0214d018.h"

#pragma thumb on

u32 func_020091fc(Unk02007ec4 *a) {
    if ((a->mUnk_4b & 2) == 0 || a->mUnk_40 != 1) {
        return 0;
    }
    return 1;
}

// non-matching: same size; 8 words differ in registers only: b, the data_0216fce0 address and v1 sit in r6, r7 and r4
// where the original has r7, r4 and r6
u32 func_0200921c(Unk02008f00Func a, u32 b, Unk02007ec4 *c) {
    s32 v1;
    u8 *v2;
    if (func_020091fc(c) == 0) {
        return 0;
    }
    MemCopyHalfwords(c, data_0216fce0, 0xc0);
    v2 = data_0216fce0;
    data_0216fc3c = data_0216fd30;
    if (func_020088dc((u16 *) ((u8 *) data_0216fc3c + 8), 0x68) != 0) {
        return 0;
    }
    v1 = func_02009098(v2, a);
    if (v1 < 0) {
        return 0;
    }
    func_02008e10(v2, v1, b);
    func_02008ff0(v1, a);
    return 1;
}

void func_020092a4(void) {
    MemFillWordsByBlock_inline((Unk0216fc40 *) data_0216fc40, 0x5910);
    ((Unk0216fc40 *) data_0216fc40)->mUnk_0c = 1;
}

// non-matching: 0x1d0 bytes, original 0x1c4; 189 lines differ; first: original `ldr r0, [pc, #376]`, ours `ldr r0, [pc,
// // #388]`
void func_020092d0(u32 a, u32 b, u32 c) {
    Unk0200b610 *v1;
    u32 v2;
    u32 v3;
    u8 *v4;
    s32 i;
    s32 j;
    u8 n;
    volatile u16 w;
    if (data_0216fc4c.mUnk_0e != data_0216fc4c.mUnk_04->mUnk_4b4) {
        func_02009494();
    }
    data_0216fc60.mUnk_04_0 = 2;
    v1 = data_0216fc4c.mUnk_04;
    data_0216fc60.mUnk_05 = v1->mUnk_4b3;
    data_0216fc60.mUnk_06 = data_0216fc4c.mUnk_0e;
    data_0216fc60.mUnk_00 = v1->mUnk_4b8;
    data_0216fc60.mUnk_04_2 = v1->mUnk_4b5 & 0x3f;
    data_0216fc60.mUnk_07 = data_0216fc4c.mUnk_11++;
    data_0216fc60.mUnk_0a = v1->mUnk_358;
    data_0216fc60.mUnk_0c = v1->mUnk_35a;
    data_0216fc60.mUnk_0e = v1->mUnk_35c;
    if (data_0216fc44 == 0 && data_0216fc48 != NULL) {
        data_0216fc48(v1->mUnk_4b8);
    }
    for (i = 0; i < 8; i++) {
        data_0216fc60.mUnk_68[i] = data_0216fc4c.mUnk_04->mUnk_4a8[i];
    }
    w = 0;
    MemFillHalfwords(w, data_0216fc60.mUnk_10, 0x58);
    n = 0;
    v2 = (u16) (data_0216fc4c.mUnk_04->mUnk_4b0 ^ data_0216fc4c.mUnk_04->mUnk_35a);
    v4 = data_0216fc60.mUnk_10;
    j = 0;
    for (i = 0; i < 15; i++) {
        v3 = 2 << i;
        if ((v2 & v3) != 0) {
            MemCopyHalfwords(data_0216fc4c.mUnk_04->mUnk_35e + j, v4, 0x16);
            data_0216fc4c.mUnk_04->mUnk_4b0 |= v3;
            v4 += 0x16;
            n++;
            if (n == 4) {
                break;
            }
        }
        j += 0x16;
    }
    if (n < 4) {
        data_0216fc60.mUnk_10[n * 0x16] &= ~0xf0;
    }
    data_0216fc60.mUnk_08 = 0;
    data_0216fc60.mUnk_08 = func_020088dc(&data_0216fc60.mUnk_08, 0x68);
    if (data_0216fc4c.mUnk_04->mUnk_4b0 == data_0216fc4c.mUnk_04->mUnk_35a) {
        data_0216fc4c.mUnk_0c = 1;
    }
    c |= 2;
    func_021455a0(NULL, &data_0216fc60, 0x70, a, b, c);
    if (data_0216fc44 == 1 && data_0216fc48 != NULL) {
        data_0216fc48(data_0216fc4c.mUnk_04->mUnk_4b8);
    }
}

void func_02009494(void) {
    data_0216fc4c.mUnk_04->mUnk_4b0 = 1;
    data_0216fc4c.mUnk_0e = data_0216fc4c.mUnk_04->mUnk_4b4;
    data_0216fc4c.mUnk_0c = 5;
}

// non-matching: 0x114 bytes, original 0x10c; 117 lines differ; first: original `adds r7, r1, #0`, ours `adds r5, r1, //
// #0`
void func_020094b8(u32 a, u32 b, u32 c) {
    Unk0200b610 *v1;
    u8 *v2;
    u8 *v3;
    volatile u16 w;
    v3 = (u8 *) data_0216fc4c.mUnk_04 + 0x358;
    v2 = data_0216fc4c.mUnk_08;
    if (v2 + 0x62 > v3) {
        data_0216fc60.mUnk_0c_b = v3 - v2;
        w = 0;
        MemFillHalfwords(w, (u8 *) &data_0216fc60.mUnk_0e + data_0216fc60.mUnk_0c_b, 0x62 - data_0216fc60.mUnk_0c_b);
    } else {
        data_0216fc60.mUnk_0c_b = 0x62;
    }
    MemCopyHalfwords(data_0216fc4c.mUnk_08, &data_0216fc60.mUnk_0e, data_0216fc60.mUnk_0c_b);
    data_0216fc60.mUnk_0a = data_0216fc4c.mUnk_0f;
    data_0216fc60.mUnk_0b = data_0216fc4c.mUnk_10;
    v1 = data_0216fc4c.mUnk_04;
    data_0216fc60.mUnk_04_0 = v1->mUnk_4b2 & 3;
    data_0216fc60.mUnk_05 = v1->mUnk_4b3;
    data_0216fc60.mUnk_06 = data_0216fc4c.mUnk_0e;
    data_0216fc60.mUnk_00 = v1->mUnk_4b8;
    data_0216fc60.mUnk_04_2 = v1->mUnk_4b5 & 0x3f;
    data_0216fc60.mUnk_07 = data_0216fc4c.mUnk_11++;
    data_0216fc60.mUnk_08 = 0;
    data_0216fc60.mUnk_08 = func_020088dc(&data_0216fc60.mUnk_08, 0x68);
    data_0216fc4c.mUnk_0f++;
    if (data_0216fc4c.mUnk_0f < data_0216fc4c.mUnk_10) {
        data_0216fc4c.mUnk_08 += 0x62;
    } else {
        data_0216fc4c.mUnk_0c = 4;
    }
    c |= 2;
    func_021455a0(NULL, &data_0216fc60, 0x70, a, b, c);
}

void func_020095c4(void) {
    Unk0200b610 *v1;
    if (data_0216fc4c.mUnk_0c == 2) {
        v1 = data_0216fc4c.mUnk_04;
        if (v1->mUnk_4b2 == 0) {
            data_0216fc4c.mUnk_10 = 9;
            data_0216fc4c.mUnk_08 = (u8 *) v1;
        } else {
            data_0216fc4c.mUnk_10 = 4;
            data_0216fc4c.mUnk_08 = (u8 *) v1 + 0x220;
        }
        data_0216fc4c.mUnk_0c = 3;
    }
}

u32 func_020095fc(void) {
    Unk0200b610 *v1;
    v1 = data_0216fc4c.mUnk_00;
    if (v1 == NULL) {
        return 0;
    }
    if (data_0216fc4c.mUnk_04 != NULL) {
        if (data_0216fc4c.mUnk_04->mUnk_4bc != NULL) {
            v1 = data_0216fc4c.mUnk_04->mUnk_4bc;
        }
    }
    data_0216fc4c.mUnk_04 = v1;
    func_020096c0();
    data_0216fc4c.mUnk_0e = data_0216fc4c.mUnk_04->mUnk_4b4;
    data_0216fc4c.mUnk_0c = 2;
    return 1;
}

void func_0200964c(u32 a, u32 b, u32 c) {
    while (1) {
        switch (data_0216fc4c.mUnk_0c) {
            case 0:
            case 1:
                if (func_020095fc() == 0) {
                    return;
                }
                break;
            case 2:
                func_020095c4();
                break;
            case 3:
                func_020094b8(a, b, c);
                return;
            case 4:
                func_02009494();
                break;
            case 5:
                func_020092d0(a, b, c);
                return;
            case 6:
                break;
        }
    }
}

void func_020096c0(void) {
    data_0216fc4c.mUnk_0d = 0;
    data_0216fc4c.mUnk_0e = 0;
    data_0216fc4c.mUnk_0f = 0;
    data_0216fc4c.mUnk_10 = 0;
    data_0216fc4c.mUnk_11 = 0;
}

void func_020096d4(void) {
    data_0216fc4c.mUnk_00 = NULL;
    data_0216fc4c.mUnk_04 = NULL;
    data_0216fc4c.mUnk_0c = 1;
    data_0216fc48 = NULL;
    func_020096c0();
}

void func_020096f4(Unk0200b610 *a) {
    Unk0200b610 *v1;
    Unk0200b610 *v2;
    if (data_0216fc4c.mUnk_00 == NULL) {
        data_0216fc4c.mUnk_00 = a;
    } else {
        v1 = data_0216fc4c.mUnk_00;
        v2 = v1->mUnk_4bc;
        if (v2 != NULL) {
            do {
                v1 = v2;
                v2 = v2->mUnk_4bc;
            } while (v2 != NULL);
        }
        v1->mUnk_4bc = a;
    }
    a->mUnk_4bc = NULL;
}

u32 func_02009724(const u16 *a) {
    u32 n;
    for (n = 0; *a++ != 0; n++) {
    }
    return n;
}

void func_0200973c(Unk0200b610 *a, const void *b, u32 c, u32 d) {
    u8 v1;
    s32 i;
    v1 = 1;
    MemCopyHalfwords(b, a->mUnk_35e, 0x14a);
    for (i = 0; i < 15; i++) {
        if ((c & (2 << i)) != 0) {
            v1++;
        }
    }
    a->mUnk_358 = v1;
    a->mUnk_35a = c | 1;
    a->mUnk_35c = d;
    a->mUnk_4b4++;
}

u32 func_020097ac(const u8 *a, u8 *b, u32 c) {
    Unk02003024 v1;
    u32 v2;
    if (c != 0) {
        v2 = 0x200;
    } else {
        v2 = 0x20;
    }
    if (c != 0) {
        b += 0x20;
    }
    if (a == NULL) {
        return 0;
    }
    FS_InitFile(&v1);
    if (FS_OpenFile(&v1, a) == 0) {
        return 0;
    }
    if (v2 != v1.mUnk_20.w.mUnk_08 - v1.mUnk_20.w.mUnk_04) {
        FS_CloseFile(&v1);
        return 0;
    }
    FS_ReadFile(&v1, b, v2);
    FS_CloseFile(&v1);
    return 1;
}

void func_02009828(Unk0200b610 *a, Unk02009828 *b, const u8 *c) {
    u32 v1;
    u32 v2;
    volatile u16 w;
    w = 0;
    MemFillHalfwords(w, a, 0x4c0);
    a->mUnk_4b2 = 0;
    v1 = func_020097ac(b->mUnk_0c, (u8 *) a, 1) == 0;
    v2 = func_020097ac(b->mUnk_10, (u8 *) a, 0) == 0;
    if ((v1 | v2) != 0) {
        a->mUnk_4b2 = 1;
        MemFillWordsByBlock_inline(a, 0x220);
    }
    a->mUnk_4b8 = b->mUnk_14;
    if (c != NULL) {
        MemCopyHalfwords(c, a->mUnk_220, 0x16);
    }
    a->mUnk_236 = b->mUnk_18;
    v1 = func_02009724(b->mUnk_04) * 2;
    MemCopyHalfwords(b->mUnk_04, a->mUnk_238, (u16) v1);
    MemCopyHalfwords(b->mUnk_08, a->mUnk_298, 0xc0);
    a->mUnk_358 = 1;
    a->mUnk_35a = 1;
    a->mUnk_4b0 = 1;
}

#pragma thumb off
