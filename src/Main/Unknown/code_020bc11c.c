#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020b19b4.h"
#include "Main/Unknown/code_020bc11c.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0203c8c0.h"
#include "Main/Unknown/code_020d0280.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b1000.h"
#include "Main/Unknown/code_020b19f8.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020b85dc.h"
#include "code_020222ec.h"
#include "code_0212c6ac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_021759c0.h"

// Values of the first argument func_020bc208 passes to GetRaceTaMNcerEntry.
typedef enum { UNK_020B843C_ARG_0, UNK_020B843C_ARG_1 } Unk020b843c_Arg;

void func_020bc958(void) {
    Unk0217b3ec *d;
    Unk0212c400 **a;
    u32 v;

    if (data_021759c0->mUnk_08 == 2) {
        return;
    }
    if (data_021759c0->mUnk_08 == 4) {
        switch (data_021759c0->mUnk_2f) {
            case 2:
            case 4:
            case 6:
            case 10:
                break;
            default:
                return;
        }
    }
    data_0217b3d4->mUnk_04 = data_0217b3d4->mUnk_00;
    data_0217b3d4->mUnk_00 = func_0203c8c0(func_020b4d9c()) - 1;
    if (data_0217b3d4->mUnk_00 != data_0217b3d4->mUnk_04 && data_0217b3d4->mUnk_08 > 0) {
        if (data_0217b3d4->mUnk_00 < data_0217b3d4->mUnk_08) {
            v = 0x41;
            if (data_021759c0->mCourseId == 0x21) {
                v = 0x1c7;
            }
            if (data_0217c780 & 1) {
                a = func_0210e128(func_02108ea0(0));
                if (data_0217d084.mUnk_0c != 0) {
                    if (*a != NULL) {
                        func_0212c6f0(a, 0);
                    }
                    if (*a != NULL) {
                        func_0212c6f0(a, 0);
                    }
                    func_0212ecc0(a, 0, v);
                }
            }
        }
        data_0217b3d4->mUnk_0c = 1;
    }
    d = data_0217b3d4;
    if (d->mUnk_0c != 0) {
        if ((d->mUnk_0c - 1) % 12 < 8) {
            d->mUnk_10 = 1;
        } else {
            d->mUnk_10 = 0;
        }
        data_0217b3d4->mUnk_0c++;
        if (data_0217b3d4->mUnk_0c > 0x78) {
            data_0217b3d4->mUnk_0c = 0;
        }
    } else {
        d->mUnk_10 = 1;
    }
}

void func_020bc208(Unk020d029c *a) {
    s32 t[2] = {0xf8, 0x10};
    s32 *p;
    Unk020ae7c4 *r;
    s32 q1[2];
    s32 q2[2];
    s32 q3[2];
    s32 q4[2];
    s32 v;
    Unk020224e0_c *c;

    if (data_021759c0->mUnk_00c == 4) {
        return;
    }
    if (data_021759c0->mUnk_00c == 1) {
        return;
    }
    if (data_021759c0->mUnk_08 == 4) {
        switch (data_021759c0->mUnk_2f) {
            case 2:
            case 4:
            case 6:
            case 10:
                if (data_0217b3d4->mUnk_08 < 2) {
                    return;
                }
                break;
            default:
                return;
        }
    }
    if (data_021759c0->mUnk_08 == 2) {
        return;
    }
    c = GetRaceMNcerEntry(0x20);
    q1[0] = t[0] << 12;
    q1[1] = t[1] << 12;
    a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q1, 0, 1);
    if (data_0217b3d4->mUnk_10 != 0) {
        c = GetRaceMNcerEntry(data_0217b3d4->mUnk_00 + 0x21);
        q2[0] = t[0] << 12;
        q2[1] = t[1] << 12;
        a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q2, 0, 1);
    }
    switch (data_0217b3d4->mUnk_08) {
        case 2:
            c = GetRaceMNcerEntry(0x26);
            q3[0] = t[0] << 12;
            q3[1] = t[1] << 12;
            a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q3, 0, 1);
            break;
        case 4:
            c = GetRaceMNcerEntry(0x27);
            q4[0] = t[0] << 12;
            q4[1] = t[1] << 12;
            a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q4, 0, 1);
            break;
    }
    if (func_020b19f8() == 0) {
        return;
    }
    if (func_020b1a20() == 0) {
        return;
    }
    v = func_020b1a0c();
    if (v % 0x24 >= 0x18) {
        return;
    }
    {
        s32 q5[2];
        s32 q6[2];
        s32 q7[2];
        s32 q8[2];
        s32 q9[2];
        s32 q10[2];
        s32 q11[2];
        s32 q12[2];
        s32 q13[2];
        s32 q14[2];
        s32 b[10] = {0x57, 0x61, 0x6a, 0x72, 0x7c, 0x85, 0x8e, 0x98, 0xa1, 0xaa};

        func_020b19b4(&p, &r);
        c = GetRaceTaMNcerEntry(*p != 0 ? UNK_020B843C_ARG_0 : UNK_020B843C_ARG_1);
        q5[0] = b[0] << 12;
        q5[1] = 0x58000;
        a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q5, 0, 1);
        if (r->mUnk_00[0] != 0) {
            c = GetRaceTaMNcerEntry(r->mUnk_00[0] + 2);
            q6[0] = b[1] << 12;
            q6[1] = 0x58000;
            a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q6, 0, 1);
        }
        c = GetRaceTaMNcerEntry(r->mUnk_00[1] + 2);
        q7[0] = b[2] << 12;
        q7[1] = 0x58000;
        a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q7, 0, 1);
        c = GetRaceTaMNcerEntry(0xc);
        q8[0] = b[3] << 12;
        q8[1] = 0x58000;
        a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q8, 0, 1);
        c = GetRaceTaMNcerEntry(r->mUnk_00[2] + 2);
        q9[0] = b[4] << 12;
        q9[1] = 0x58000;
        a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q9, 0, 1);
        c = GetRaceTaMNcerEntry(r->mUnk_00[3] + 2);
        q10[0] = b[5] << 12;
        q10[1] = 0x58000;
        a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q10, 0, 1);
        c = GetRaceTaMNcerEntry(0xc);
        q11[0] = b[6] << 12;
        q11[1] = 0x58000;
        a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q11, 0, 1);
        c = GetRaceTaMNcerEntry(r->mUnk_00[4] + 2);
        q12[0] = b[7] << 12;
        q12[1] = 0x58000;
        a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q12, 0, 1);
        c = GetRaceTaMNcerEntry(r->mUnk_00[5] + 2);
        q13[0] = b[8] << 12;
        q13[1] = 0x58000;
        a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q13, 0, 1);
        c = GetRaceTaMNcerEntry(r->mUnk_00[6] + 2);
        q14[0] = b[9] << 12;
        q14[1] = 0x58000;
        a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q14, 0, 1);
    }
}

void func_020bc11c(void) {
    s32 i;

    data_0217b3d0 = HeapAlloc(GetHeap(func_020364e8()), 0x38);
    data_0217b3d0->mUnk_00.mUnk_00[0] = 0;
    data_0217b3d0->mUnk_00.mUnk_00[1] = 0;
    data_0217b3d0->mUnk_00.mUnk_00[2] = 0;
    data_0217b3d0->mUnk_00.mUnk_00[3] = 0;
    data_0217b3d0->mUnk_00.mUnk_00[4] = 0;
    data_0217b3d0->mUnk_00.mUnk_00[5] = 0;
    data_0217b3d0->mUnk_00.mUnk_00[6] = 0;
    data_0217b3d0->mUnk_1c = 0;
    if (data_021759c0->mUnk_08 == 2) {
        if (data_021759c0->mUnk_18 == 1) {
            data_0217b3d0->mUnk_1c = 1;
        }
    }
    if (data_021759c0->mUnk_08 == 4) {
        if (data_021759c0->mUnk_2f != 6) {
            data_0217b3d0->mUnk_1c = 1;
        }
    }
    for (i = 0; i < 6; i++) {
        data_0217b3d0->mUnk_20[i] = 0;
    }
}
