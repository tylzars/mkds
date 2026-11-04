#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0205c800.h"
#include "Main/Unknown/code_02056464.h"
#include "Main/Unknown/code_02056158.h"
#include "Main/Unknown/code_02120294.h"
#include "Main/Unknown/code_02120240.h"
#include "Main/Unknown/code_021201e4.h"
#include "Main/Unknown/code_021202f0.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

static inline void func_020446e0_inline(s32 f, u32 e, s32 d, u32 c, u32 b, s32 a) {
    func_020468b0(a, b, c, d, e, f);
}

static inline Unk0217aa00_45c *func_02045084_inline(Unk0217aa00 *q, s32 a) {
    u16 e;

    e = q->mUnk_1e8c[a];
    return e == 0xffff ? 0 : &q->mUnk_045c[e];
}

static inline BOOL func_02045084_inline2(void) {
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        return TRUE;
    }
    return FALSE;
}


void func_02045590(void) {
    u16 i;
    Unk020565e4 *e;

    data_021759c0->mUnk_1e8.mCourseId = 0x14;
    data_021759c0->mUnk_1e8.mUnk_04 = 0;
    data_021759c0->mUnk_1e8.mUnk_08 = 0;
    data_021759c0->mUnk_1e8.mUnk_0c = 0;
    data_021759c0->mUnk_1e8.mUnk_10 = 0;
    data_021759c0->mUnk_1e8.mUnk_14 = 0;
    data_021759c0->mUnk_1e8.mUnk_18 = 0;
    data_021759c0->mUnk_1e8.mUnk_1c = 0;
    data_021759c0->mUnk_1e8.mCourseListMode = 0;
    data_021759c0->mUnk_1e8.mUnk_24 = 0;
    MemFill(&data_021759c0->mUnk_1e8.mMissionFileRow, 0, 0x2c);
    data_021759c0->mUnk_1e8.mMissionTableRow = -1;
    data_021759c0->mUnk_1e8.mMissionTableColumn = -1;
    data_021759c0->mUnk_1e8.mUnk_56[0] = 0;
    data_021759c0->mUnk_1e8.mUnk_57 = 0;
    data_021759c0->mUnk_1e8.mUseTeams = 0;
    data_021759c0->mUnk_1e8.mUnk_5c = 0;
    data_021759c0->mUnk_1e8.mUnk_60 = 1;
    data_021759c0->mUnk_1e8.mUnk_62 = -1;
    data_021759c0->mUnk_1e8.mUnk_63 = 0;
    data_021759c0->mUnk_1e8.mUnk_64 = -1;
    for (i = 0; i < 8; i++) {
        data_021759c0->mUnk_250[i].mCharacterIndex = i;
        data_021759c0->mUnk_250[i].mKartIndex = i * 3;
        data_021759c0->mUnk_250[i].mUnk_08.mUnk_00 = i == 0 ? UNK_021759C0_70_KIND_0 : UNK_021759C0_70_KIND_1;
        data_021759c0->mUnk_250[i].mUnk_08.mTeamIndex = -1;
        data_021759c0->mUnk_250[i].mUnk_08.mUnk_08 = 3;
        data_021759c0->mUnk_250[i].mUnk_08.mUnk_0c = i;
        data_021759c0->mUnk_250[i].mUnk_08.mUnk_10 = 3;
        data_021759c0->mUnk_250[i].mUnk_08.mUnk_14 = 0;
        data_021759c0->mUnk_250[i].mUnk_08.mUnk_18 = NULL;
        data_021759c0->mUnk_250[i].mUnk_08.mUnk_24 = 0;
        data_021759c0->mUnk_250[i].mUnk_08.mUnk_25 = data_021759d0->mUnk_00;
        data_021759c0->mUnk_250[i].mUnk_08.mEmblemData = NULL;
        data_021759c0->mUnk_250[i].mUnk_08.mUnk_20 = 0;
    }
    data_021759c0->mUnk_250[7].mUnk_08.mUnk_08 = 0;
    data_021759c0->mUnk_250[6].mUnk_08.mUnk_08 = 1;
    data_021759c0->mKartCount = 0;
    data_021759c0->mUnk_3d1 = 0;
    for (i = 0; i < 2; i++) {
        data_021759c0->mTeamKartCounts[i] = 0;
    }
    data_021759c0->mUnk_3d4 = 0;
    for (i = 0; i < 2; i++) {
        data_021759c0->mUnk_3d5[i] = -1;
    }
    data_021759c0->mUnk_3d8 = 0;
    for (i = 0; i < 0x21; i++) {
        data_021759c0->mCourseList[i] = 0;
    }
    data_021759c0->mCourseListIndex = 0;
    e = &data_021759c0->mUnk_3e8;
    e->mUnk_02 = 0;
    e->mUnk_03 = 0;
    e->mUnk_00 = 0;
    for (i = 0; i < 5; i++) {
        e = &data_021759c0->mUnk_3ec[i];
        e->mUnk_02 = 0;
        e->mUnk_03 = 0;
        e->mUnk_00 = 0;
    }
    func_0205db50();
    func_0205d07c();
    func_02044940();
}

void func_02045084(s32 a) {
    Unk0217aa08 *p;
    Unk0217aa00 *q;
    void **b0;
    void **b1;
    u8 *b2;
    u8 *b3;
    u8 *b4;
    s32 *b5;
    BOOL f;
    BOOL g;
    BOOL t;
    s8 x;
    u8 v;

    p = data_0217aa08;
    b0 = &data_021759c0->mUnk_68[a].mUnk_08.mUnk_18;
    b1 = &data_021759c0->mUnk_68[a].mUnk_08.mEmblemData;
    b2 = &data_021759c0->mUnk_68[a].mUnk_08.mUnk_24;
    b3 = &data_021759c0->mUnk_68[a].mUnk_08.mUnk_25;
    b4 = &data_021759c0->mUnk_68[a].mUnk_08.mUnk_26;
    b5 = &data_021759c0->mUnk_68[a].mUnk_08.mUnk_20;
    f = FALSE;
    if (p->mUnk_04->mUnk_004 != 0) {
        f = p->mUnk_00->mUnk_31_3 == 0;
    }
    if (f != FALSE) {
        g = TRUE;
    } else {
        g = FALSE;
    }
    *b0 = NULL;
    *b1 = NULL;
    *b2 = 0;
    *b5 = 0;
    *b3 = data_021759d0->mUnk_00;
    *b4 = 0;
    if (a == data_021759c0->mUnk_62) {
        *b0 = &data_0217aa08->mUnk_00->mUnk_0c;
        *b1 = &data_0217aa08->mUnk_04->mUnk_008;
        *b2 = g != FALSE ? 1 : 0;
        *b3 = data_021759d0->mUnk_00;
        *b4 = func_02056208();
        return;
    }
    switch (data_021759c0->mUnk_68[a].mUnk_08.mUnk_00) {
        case 0:
            q = data_0217aa00;
            t = FALSE;
            if ((q == NULL ? 0 : q->mUnk_0000) != 0 && q->mUnk_0004 != 13) {
                t = TRUE;
            }
            if (t == FALSE) {
                return;
            }
            if (func_02045084_inline(q, a) == NULL) {
                return;
            }
            *b0 = func_02045084_inline(q, a);
            *b1 = &func_02045084_inline(data_0217aa00, a)->mUnk_014;
            *b2 = func_02045084_inline(data_0217aa00, a)->mUnk_214;
            *b3 = func_02045084_inline(data_0217aa00, a)->mUnk_228_0;
            *b5 = func_02045084_inline2() || (data_0217aa00->mUnk_0457 & (1 << data_0217aa00->mUnk_1e8c[a])) != 0
                      ? 0
                      : (s32) &func_02045084_inline(data_0217aa00, a)->mUnk_218;
            *b4 = func_02045084_inline(data_0217aa00, a)->mUnk_229;
            break;
        case 2:
            switch (data_021759c0->mUnk_68[a].mUnk_08.mUnk_10) {
                case 0:
                    *b0 = &data_0217aa08->mUnk_14[0]->mUnk_0c;
                    *b1 = &data_0217aa08->mUnk_04->mUnk_008;
                    *b2 = g != FALSE ? 1 : 0;
                    *b3 = data_0217aa08->mUnk_14[0]->mUnk_08_2;
                    *b4 = 0;
                    break;
                case 1:
                    *b0 = &data_0217aa08->mUnk_14[1]->mUnk_0c;
                    *b1 = &data_0217aa08->mUnk_14[1]->mUnk_30;
                    *b2 = data_0217aa08->mUnk_14[1]->mUnk_08_1;
                    *b3 = data_0217aa08->mUnk_14[1]->mUnk_08_2;
                    *b4 = data_0217aa08->mUnk_14[1]->mUnk_2f_0;
                    break;
                case 2:
                    *b0 = &data_0217aa08->mUnk_14[2]->mUnk_0c;
                    *b1 = &data_0217aa08->mUnk_14[2]->mUnk_30;
                    *b2 = 1;
                    *b3 = data_0217aa08->mUnk_14[2]->mUnk_08_2;
                    *b4 = 1;
                    break;
            }
            break;
        case 3:
            x = data_0217aa18->mUnk_00[(u8) a];
            if (x < 0) {
                return;
            }
            v = x;
            *b0 = func_021202b0(v);
            *b1 = func_02120294(v);
            *b2 = func_02120278(v);
            *b3 = func_021202cc(v);
            *b5 = func_021202f0(v);
            *b4 = func_021201e4(v);
            break;
    }
}

void func_02044fc0(void) {
    u8 n;
    s8 j;

    n = 0;
    for (j = 0; j < 2; j++) {
        data_021759c0->mUnk_3d5[j] = -1;
    }
    for (j = 0; j < data_021759c0->mKartCount; j++) {
        if ((data_021759c0->mUnk_68[(u16) j].mUnk_08.mUnk_14 & 1) != 0) {
            data_021759c0->mUnk_3d5[(u8) data_021759c0->mUnk_68[j].mUnk_08.mUnk_08] = j;
            n++;
        }
    }
    data_021759c0->mUnk_3d4 = n;
}

s32 func_02044e9c(s32 a, s32 b) {
    u8 i;
    BOOL r;
    Unk0217aa08_14 *p;

    r = FALSE;
    if (data_021759c0->mUnk_1e8.mUnk_0c == 2) {
        return 1;
    }
    p = data_0217aa08->mUnk_14[0];
    if (p->mUnk_08_0 == 1) {
        func_020468b0(b, p->mUnk_04_0, p->mUnk_04_4, 2, -1, 3);
        data_021759c0->mUnk_250[b].mUnk_08.mUnk_10 = r;
        MemCopy(p->mUnk_30, data_02175650[b].mUnk_00, 0xdcc);
        r = TRUE;
        func_02056574(0, &data_021759c0->mUnk_3e8);
        for (i = 1; i <= 5; i++) {
            func_020565ac(0, i, &data_021759c0->mUnk_3ec[i - 1]);
        }
    }
    return r;
}

s32 func_02044d4c(s32 a, s32 b) {
    Unk0217aa08_14 *p;
    s32 r;
    u8 i;

    if (data_021759c0->mUnk_1e8.mUnk_0c == 2) {
        return 1;
    }
    p = data_0217aa08->mUnk_14[1];
    r = p->mUnk_08_0 == 1 ? 1 : 0;
    if (r != 0) {
        func_020468b0(b, p->mUnk_04_0, p->mUnk_04_4, 2, -1, 3);
        data_021759c0->mUnk_250[b].mUnk_08.mUnk_10 = 1;
        MemCopy(&p->mUnk_30[0x200], data_02175650[b].mUnk_00, 0xdcc);
        func_02056574(1, &data_021759c0->mUnk_3e8);
        for (i = 1; i <= 5; i++) {
            func_020565ac(1, i, &data_021759c0->mUnk_3ec[i - 1]);
        }
    } else {
        func_020468b0(b, 0, 0, 4, -1, 3);
    }
    return r;
}

BOOL func_02044bf8(s32 a, s32 b) {
    Unk0217aa08_14 *p;
    u8 i;

    if (data_021759c0->mUnk_1e8.mUnk_0c == 2) {
        return TRUE;
    }
    p = data_0217aa08->mUnk_14[2];
    if (p != NULL && p->mUnk_08_0 == 1) {
        func_020468b0(b, p->mUnk_04_0, p->mUnk_04_4, 2, -1, 3);
        data_021759c0->mUnk_250[b].mUnk_08.mUnk_10 = 2;
        MemCopy(&p->mUnk_30[0x200], data_02175650[b].mUnk_00, 0xdcc);
        func_020565e4(p, &data_021759c0->mUnk_3e8);
        for (i = 1; i <= 5; i++) {
            func_0205660c(p, i, &data_021759c0->mUnk_3ec[i - 1]);
        }
        return TRUE;
    }
    func_020468b0(b, 0, 0, 4, -1, 3);
    return FALSE;
}

void func_02044940(void) {
    s16 h;
    Unk0217aa08_14 *e;
    Unk0217aa00 *q;
    u16 n;
    u16 r;
    u8 i;
    BOOL f;

    r = 0;
    switch (data_021759c0->mUnk_1e8.mUnk_08) {
        case 0:
        case 2:
        case 3:
            r = 8;
            break;
        case 5:
            r = 4;
            break;
        case 1:
            n = 1;
            e = data_0217aa08->mUnk_14[0];
            if (e->mUnk_08_0 == 1) {
                data_021759c0->mUnk_3e6 = 1;
                data_021759c0->mUnk_3e4 = e->mUnk_08_8;
                data_021759c0->mUnk_3e5 = e->mUnk_08_15;
                data_021759c0->mUnk_3e2 = e->mUnk_08_22;
            } else {
                data_021759c0->mUnk_3e6 = 0;
                data_021759c0->mUnk_3e4 = 0;
                data_021759c0->mUnk_3e5 = 0;
                data_021759c0->mUnk_3e2 = 0;
            }
            switch (data_021759c0->mUnk_1e8.mUnk_24) {
                case 0:
                    if (func_02044e9c(data_021759c0->mUnk_1e8.mCourseId, 1) != 0) {
                        n++;
                    }
                    break;
                case 1:
                    if (func_02044d4c(data_021759c0->mUnk_1e8.mCourseId, 1) != 0) {
                        n++;
                    }
                    break;
                case 2:
                    if (func_02044bf8(data_021759c0->mUnk_1e8.mCourseId, 1) != 0) {
                        n++;
                    }
                    break;
                case 3:
                    break;
            }
            r = n;
            break;
        case 4:
            r = 2;
            break;
    }
    switch (data_021759c0->mUnk_1e8.mUnk_0c) {
        case 1:
        case 5:
            data_021759c0->mUnk_1e8.mUnk_62 = data_021759c0->mUnk_1e8.mUnk_63;
            break;
        case 6:
            data_021759c0->mUnk_1e8.mUnk_62 = data_021759c0->mUnk_1e8.mUnk_63;
            r = 8;
            break;
        case 0:
        case 2:
        case 3:
        case 4:
            h = 0;
            for (i = 0; i < 8; i++) {
                if (data_021759c0->mUnk_250[i].mUnk_08.mUnk_00 == 0) {
                    h = i;
                    break;
                }
            }
            q = data_0217aa00;
            f = FALSE;
            if ((q == NULL ? 0 : q->mUnk_0000) != 0 && q->mUnk_0004 != 13) {
                f = TRUE;
            }
            if (f != FALSE) {
                h = (s16) q->mUnk_1e52[(u16) (q->mUnk_0000 == 2 ? q->mUnk_0432 : 0)].mUnk_00;
            }
            data_021759c0->mUnk_1e8.mUnk_62 = h;
            data_021759c0->mUnk_1e8.mUnk_63 = h;
            break;
    }
    *(Unk02044940_block *) data_021759c0 = *(Unk02044940_block *) &data_021759c0->mUnk_1e8;
    func_02046968(r);
    func_02044fc0();
    for (n = 0; n < 8; n++) {
        func_02045084(n);
    }
}

void func_020446e0(void) {
    u8 i;
    u32 k;
    u8 m;
    u8 n;
    Unk021759c0_1e8 *a;
    s32 b;
    u8 c;
    s32 d;

    switch (data_021759c0->mUnk_1e8.mUnk_08) {
        case 0:
            if (data_021759c0->mUnk_1e8.mCourseId == 0x34) {
                data_021759c0->mUnk_1e8.mCourseId = 0x34;
                data_021759c0->mUnk_1e8.mUnk_0c = 5;
                for (i = 3; i < 8; i++) {
                    func_020468b0(i, i, i * 3, 4, -1, 3);
                }
                data_021759c0->mUnk_1e8.mUnk_63 = 0;
            } else if ((u32) (data_021759c0->mUnk_1e8.mCourseId - 0x35) <= 1) {
                data_021759c0->mUnk_1e8.mUnk_0c = 6;
                data_021759c0->mUnk_1e8.mUnk_10 = 1;
                for (c = 0; c < 8; c++) {
                    s8 j;
                    for (j = 0; j < data_021759c0->mKartCount; j++) {
                        if (c + 1 == func_0205d4e8((u16) j)) {
                            break;
                        }
                    }
                    d = c * 3;
                    if (data_021759c0->mUnk_1e8.mCourseId != 0x36) {
                        func_020446e0_inline(3, -1, 1, d, c, c);
                    }
                }
                data_021759c0->mUnk_1e8.mUnk_63 = 0;
            } else {
                for (k = 0; k < 32; k++) {
                    m = (s32) k / 4;
                    n = (s32) k % 4;
                    b = data_02154128[m][n];
                    if (data_021759c0->mUnk_1e8.mCourseId == b) {
                        break;
                    }
                    if (k == 31) {
                        m = 0;
                        n = 3;
                    }
                }
                data_021759c0->mUnk_1e8.mUnk_60 = (u8) (n + 1);
                a = &data_021759c0->mUnk_1e8;
                data_021759c0->mUnk_1e8.mUnk_0c = 3;
                data_021759c0->mUnk_1e8.mUnk_04 = m;
            }
            break;
        case 2:
            if (data_021759d0->mUnk_1c_2 != 0) {
                data_021759c0->mUnk_1e8.mUnk_0c = 0;
            } else {
                data_021759c0->mUnk_1e8.mUnk_0c = 4;
            }
            break;
        case 4:
            break;
        default:
            data_021759c0->mUnk_1e8.mUnk_0c = 0;
            break;
    }
}

void func_0204465c(void) {
    u16 i;

    if (data_021759c0->mUnk_1e8.mUnk_08 != 1) {
        return;
    }
    data_021759c0->mUnk_1e8.mUnk_0c = 0;
    for (i = 1; i < 8; i++) {
        data_021759c0->mUnk_250[i].mCharacterIndex = i;
        data_021759c0->mUnk_250[i].mKartIndex = i;
        data_021759c0->mUnk_250[i].mUnk_08.mUnk_00 = 4;
        data_021759c0->mUnk_250[i].mUnk_08.mUnk_0c = i;
    }
}

u16 func_02044618(void) {
    Unk021759c0 *p;
    u16 r;

    r = 1;
    p = data_021759c0;
    if (p->mUnk_08 != 2) {
        if (p->mUnk_064 <= 0) {
            r = gCourseMap->mUnk_018->mUnk_02;
        } else {
            r = (u16) p->mUnk_064;
        }
    }
    return r;
}
