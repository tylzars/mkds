#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_0202f764.h"
#include "Main/Unknown/code_0202f14c.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02030000.h"
#include "Main/Unknown/code_0203003c.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_02054000.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_02055000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_0212658c.h"
#include "Main/Unknown/code_021281b4.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "code_02148ca0.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02163000.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212d5e0.h"
#include "code_0212df7c.h"
#include "code_0213ecf8.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"

#pragma thumb on

// Fills with 0 through a halfword stack offset of its own.
static inline void func_0202f764_inline(void *p, s32 v1) {
    volatile u16 zero = 0;
    func_0214cfe4(zero, p, v1);
}

void func_0202fd2c(void) {
    s32 v1;
    Unk02174e50_24 *q;
    s32 v2;
    s32 v3;
    s32 v4;
    BOOL v5;
    s32 i;
    s32 j;
    Unk02174e4c_818_04 v6;

    q = &data_02174e50->mUnk_24;
    v1 = 0;
    switch (data_02174e50->mUnk_50) {
        case 0:
            if (func_0205579c(0, 0) == 1) {
                data_02174e50->mUnk_50 = 1;
            }
            return;
        case 1:
            if (data_02174e50->mUnk_88 != 0) {
                if (data_02174e50->mUnk_48 < 4) {
                    for (i = 0; i < 4; i++) {
                        if (func_0204ff14(i, &func_0202f14c()->mUnk_04[i]) != 0) {
                            func_0202f14c()->mUnk_04[i].mUnk_14 = 0;
                        } else {
                            func_0202f764_inline(&func_0202f14c()->mUnk_04[i], 0x16);
                        }
                    }
                    if (func_0204ff14(data_02174e50->mUnk_48, NULL) != 0) {
                        func_0202f14c()->mUnk_00 = data_02174e50->mUnk_48;
                        data_02174e50->mUnk_54 = 3;
                        data_02174e50->mUnk_50 = 0xb;
                        return;
                    }
                    data_02174e50->mUnk_58[data_02174e50->mUnk_48].mUnk_00 = 0;
                    return;
                }
                data_02174e50->mUnk_54 = 1;
                data_02174e50->mUnk_50 = 5;
                return;
            }
            if (data_02174e50->mUnk_4c != 1) {
                return;
            }
            for (i = 0; i < 4; i++) {
                v2 = data_02174e50->mUnk_58[i].mUnk_00;
                v3 = data_02174e50->mUnk_58[i].mUnk_08;
                v4 = data_02174e50->mUnk_58[i].mUnk_04;
                func_0202f764_inline(&v6, 0x16);
                data_02174e50->mUnk_58[i].mUnk_00 = func_0204ff14(i, &v6);
                if (data_02174e50->mUnk_58[i].mUnk_00 != 0) {
                    v6.mUnk_14 = 0;
                    func_0212426c(1, data_02153c58[i].mUnk_30, q->mUnk_14, &v6, q->mUnk_0c, q->mUnk_18);
                    data_02174e50->mUnk_58[i].mUnk_08 = func_0204fe1c(i);
                    data_02174e50->mUnk_58[i].mUnk_04 = func_0204fe90(i);
                } else {
                    func_0212426c(1, data_02153c58[i].mUnk_30, q->mUnk_14, GetBmgEntry(data_02174e50->mUnk_a0, 8),
                                  q->mUnk_0c, q->mUnk_18);
                    data_02174e50->mUnk_58[i].mUnk_08 = 0;
                    data_02174e50->mUnk_58[i].mUnk_04 = 0;
                }
                if (v2 == 0 && data_02174e50->mUnk_58[i].mUnk_00 != 0) {
                    v5 = TRUE;
                    for (j = 0; j < 4; j++) {
                        if (wcsncmp(v6.mUnk_00, func_0202f14c()->mUnk_04[j].mUnk_00, 0xb) == 0) {
                            v5 = FALSE;
                        }
                    }
                    if (v5 != FALSE) {
                        func_0212d5e0(&data_0217c868);
                        func_0212ecc0(&data_0217d068, 0, 4);
                        func_0212d5e0(&data_0217d0a0);
                    }
                } else if (v2 != 0 && data_02174e50->mUnk_58[i].mUnk_00 == 0) {
                    func_0212d5e0(&data_0217c868);
                    func_0212ecc0(&data_0217d068, 0, 5);
                    func_0212d5e0(&data_0217d0a0);
                }
                v1 |= v2 != data_02174e50->mUnk_58[i].mUnk_00 ? 1 : 0;
                v1 |= v3 != data_02174e50->mUnk_58[i].mUnk_08 ? 1 : 0;
                v1 |= v4 != data_02174e50->mUnk_58[i].mUnk_04 ? 1 : 0;
            }
            if (v1 != 0) {
                func_0203003c(1);
            }
            return;
        case 5:
        case 8:
            if (func_02054f58() == 1) {
                data_02174e50->mUnk_50 = 0xb;
            }
            return;
    }
}

void func_0202fbc8(void *a, void *b, void *c) {
    void *v1;
    u32 v2;
    Unk02174e50_24 *q;
    s32 i;
    Unk02153c1c *v3;
    void *v4;

    v1 = func_02036948(a);
    data_02174e50 = func_02036bec(v1, 0xa8);
    func_0214d05c_inline(data_02174e50, 0xa8);
    data_02174e50->mUnk_a4 = v1;
    data_02174e50->mUnk_40 = b;
    data_02174e50->mUnk_44 = c;
    data_02174e50->mUnk_a0 = FindSceneFile(data_021634c0);
    data_02174e50->mUnk_4c = 0;
    data_02174e50->mUnk_90 = -0xc0;
    func_020258d4(1, data_02174e50, data_021634cc, data_021634ec, data_0216350c, 3, FindSceneFile);
    v2 = func_02148ca0();
    q = &data_02174e50->mUnk_24;
    func_02025b20(q, data_02163530, data_02163558, data_02163580, data_021635a4, data_021635c8, data_021635ec,
                  FindSceneFile);
    func_02025a50(1, data_02174e50->mUnk_a4, q);
    for (i = 0, v3 = data_02153c1c; i < 5; v3++, i++) {
        v2 -= func_02025a00(1, data_02174e50->mUnk_a4, q, v3, v2);
        if (data_02153c1c[i].mUnk_08 < 0) {
            v4 = data_02163610;
        } else {
            v4 = GetBmgEntry(data_02174e50->mUnk_a0, data_02153c1c[i].mUnk_08);
        }
        func_0212426c(1, data_02153c1c[i].mUnk_00, q->mUnk_14, v4, q->mUnk_0c, q->mUnk_18);
    }
    func_0203003c(1);
    func_021281c8(0xf);
    data_021759d0->mUnk_20 = 2;
    func_02036820(data_02174e50->mUnk_a4);
}

s32 func_0202f764(Unk0202f764 *a) {
    Unk02174e50_24 *q;
    s32 v1;
    u16 v2;
    s32 i;
    s32 v3;
    s32 v4;
    BOOL v5;
    BOOL v6;
    u16 v;
    s32 x;
    s32 y;
    s32 v7;

    v1 = -1;
    v2 = func_020435bc();
    q = &data_02174e50->mUnk_24;
    if (data_02174e50->mUnk_9c == 0) {
        data_02174e50->mUnk_94++;
        if (data_02174e50->mUnk_94 > 0x78) {
            for (i = 0; i < 4; i++) {
                func_0202f764_inline(&func_0202f14c()->mUnk_04[i], 0x16);
            }
            data_02174e50->mUnk_9c = 1;
        }
    }
    if (data_02174e50->mUnk_4c != -1) {
        func_0202fd2c();
    }
    switch (data_02174e50->mUnk_4c) {
        case 0:
            if (func_02036c5c() == 0) {
                break;
            }
            if (data_02174e50->mUnk_8c == 0) {
                func_02128374();
                func_02126638(GetBmgEntry(data_02174e50->mUnk_a0, 7), 0, 0, 1, 0, 0, 0);
            }
            data_02174e50->mUnk_8c++;
            if (data_02174e50->mUnk_8c < 10) {
                data_02174e50->mUnk_90 = func_020ae4c0(1, -0xc0, 0, data_02174e50->mUnk_8c, 10);
            } else {
                data_02174e50->mUnk_8c = 0;
                data_02174e50->mUnk_90 = 0;
                data_02174e50->mUnk_4c = 1;
            }
            func_02030200();
            break;
        case 1:
            v3 = 0;
            v4 = -1;
            v5 = FALSE;
            v6 = FALSE;
            v = data_02175628[v2].mHasPair;
            if (v == 0 && data_02175628[v2].mNoPairCount < 5) {
                v6 = TRUE;
            }
            if (v6 == FALSE && data_02175628[v2].mPrevHasPair == 0 && v != 0) {
                v5 = TRUE;
            }
            if (v5 != FALSE) {
                x = data_02175628[v2].mUnk_48;
                y = data_02175628[v2].mUnk_4a;
                v3 = IsSelectReturnState2NoState3Or4RequestAndInRect(x, y);
                v4 = func_0201ea84(q->mUnk_10, x, y);
            }
            v = data_02175628[v2].mUnk_00;
            if ((u16) (v & 1) != 0) {
                if (func_0203023c() != 0) {
                    data_02174e50->mUnk_88 = 1;
                    data_02174e50->mUnk_4c = 2;
                    data_02174e50->mUnk_98 = 0;
                    func_0203003c(0);
                    if (data_02174e50->mUnk_48 == 4) {
                        func_0212ecc0(&data_0217d068, 0, 0x4e);
                    } else {
                        if ((data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000) == 2) {
                            data_0217aa00->mUnk_0436 |= 1;
                        }
                        func_0212d5e0(&data_0217c868);
                        func_0212ecc0(&data_0217d068, 0, 2);
                        func_0212d5e0(&data_0217d0a0);
                    }
                } else {
                    func_0212ecc0(&data_0217d068, 0, 0x4f);
                }
            } else if ((u16) (v & 2) != 0 || v3 != 0) {
                if (a != NULL) {
                    a->mUnk_04 = 0;
                }
                data_02174e50->mUnk_4c = 3;
                func_02128310(1);
            } else if (func_020ae408(v2, 0x40) != 0) {
                data_02174e50->mUnk_48--;
                if (data_02174e50->mUnk_48 < 0) {
                    data_02174e50->mUnk_48 = 4;
                }
                func_0203003c(1);
                func_0212ecc0(&data_0217d068, 0, 0);
            } else if (func_020ae408(v2, 0x80) != 0) {
                data_02174e50->mUnk_48++;
                if (data_02174e50->mUnk_48 > 4) {
                    data_02174e50->mUnk_48 = 0;
                }
                func_0203003c(1);
                func_0212ecc0(&data_0217d068, 0, 0);
            } else if (v4 == 0xc) {
                func_0212ecc0(&data_0217d068, 0, 0x4e);
                func_0203003c(data_02174e50->mUnk_48 != 4 ? 1 : 0);
                data_02174e50->mUnk_98 = 0;
                data_02174e50->mUnk_4c = 2;
                data_02174e50->mUnk_48 = 4;
                data_02174e50->mUnk_88 = 1;
            } else {
                for (i = 0; i < 4; i++) {
                    if (func_02030274(v4, i) != 0) {
                        v7 = data_02174e50->mUnk_48 != i ? 1 : 0;
                        if (data_02174e50->mUnk_58[i].mUnk_00 != 0 && data_02174e50->mUnk_58[i].mUnk_08 < 7) {
                            func_0212d5e0(&data_0217c868);
                            func_0212ecc0(&data_0217d068, 0, 2);
                            func_0212d5e0(&data_0217d0a0);
                            data_02174e50->mUnk_48 = i;
                            func_0203003c(v7);
                            data_02174e50->mUnk_98 = 0;
                            data_02174e50->mUnk_4c = 2;
                            data_02174e50->mUnk_88 = 1;
                        } else {
                            func_0212ecc0(&data_0217d068, 0, 0x4f);
                        }
                    }
                }
            }
            break;
        case 2:
            data_02174e50->mUnk_98++;
            if (data_02174e50->mUnk_98 >= 5) {
                data_02174e50->mUnk_98 = 0;
                func_0203003c(1);
                if (data_02174e50->mUnk_48 < 4 && data_02174e50->mUnk_58[data_02174e50->mUnk_48].mUnk_00 == 0) {
                    data_02174e50->mUnk_4c = 1;
                } else {
                    data_02174e50->mUnk_4c = 3;
                    func_02125fc0();
                }
            }
            break;
        case 3:
            data_02174e50->mUnk_8c++;
            if (data_02174e50->mUnk_8c < 10) {
                data_02174e50->mUnk_90 = func_020ae4c0(1, 0, -0xc0, data_02174e50->mUnk_8c, 10);
            } else {
                data_02174e50->mUnk_8c = 0;
                data_02174e50->mUnk_90 = 0;
                data_02174e50->mUnk_4c = 4;
            }
            func_02030200();
            break;
        case 4:
            if (data_02174e50->mUnk_50 == 0xb) {
                v1 = data_02174e50->mUnk_54;
            }
            break;
    }
    if (data_02174e50->mUnk_4c != 4) {
        func_02124c30(q->mUnk_0c, q->mUnk_08, q->mUnk_14, data_02174e50->mUnk_44, q->mUnk_18);
    }
    return v1;
}

#pragma thumb off
