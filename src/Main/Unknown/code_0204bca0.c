#include "Main/Unknown/code_0204bca0.h"

#include "03/code_021b94b8.h"
#include "code_0200db4c.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02176000.h"
#include "Main/Unknown/unk_02179000.h"
#include "Main/Unknown/code_0204b714.h"
#include "Main/Unknown/code_0204c000.h"
#include "Main/Unknown/code_02006380.h"
#include "Main/Unknown/code_02006954.h"
#include "code_02003be0.h"
#include "code_02142eac.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0204b000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_0200692c.h"
#include "Main/Unknown/unk_02154000.h"
#include "code_02004d80.h"
#include "code_02004dc0.h"
#include "code_0200eddc.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0204db40.h"
#include "Main/Unknown/code_0204db48.h"
#include "Main/Unknown/unk_02165000.h"

typedef struct Unk0204d610_t {
    u8 *mUnk_00;
    u32 mUnk_04;
} Unk0204d610_t;

typedef struct Unk0204d6f4_hdr {
    u8 mUnk_00[0x40];
    u32 mUnk_40;
    u32 mUnk_44;
    u32 mUnk_48;
    u32 mUnk_4c;
    u32 mUnk_50;
    u32 mUnk_54;
    u32 mUnk_58;
    u32 mUnk_5c;
} Unk0204d6f4_hdr;

s32 func_0204dab8(Unk02003024 *a, u32 b) {
    switch (b) {
        case 0:
            if (data_02175ec0.mUnk_000c != 2) {
                return 5;
            }
            if (a->mUnk_30.p.mUnk_08 == 0) {
                return 0;
            }
            func_0204cf5c(a);
            return 6;
        case 1:
            return 4;
        default:
            return 8;
    }
}

void func_0204d6f4(Unk02003024 *a, s32 b) {
    Unk0204d6f4_hdr v2;
    Unk02003024 v1;
    Unk0204d610_t t[4];
    u32 v3[4];
    u32 *v4[4];
    u32 *v6;
    u32 v7;
    enum { K0 } v8;
    u32 v9;
    u32 v10;
    Unk0204d6f4_hdr *v5;
    u32 v11;
    u32 v12;
    u32 v13;
    BOOL v14;
    s32 i;
    BOOL k;

    v7 = 0;
    v14 = a == NULL;
    v8 = 0;
    v8 = (s32) v8;
    if (v14 == FALSE) {
        if (b != 0) {
            v8 = 1;
        }
    }
    FS_InitFile(&v1);
    FS_OpenFileDirect(&v1, FS_FindArchive(data_021651d8, 3), 0, 0x7fffffff, -1);
    if (v14 != FALSE) {
        v9 = 0;
        v10 = 0;
        v5 = (Unk0204d6f4_hdr *) 0x027ffe00;
    } else {
        i = a->mUnk_2c - a->mUnk_20.w.mUnk_04;
        v9 = i + a->mUnk_20.w.mUnk_04;
        v5 = &v2;
        v10 = v9;
        FS_ReadFile(a, v5, 0x60);
        FS_SeekFile(a, i, 0);
    }
    if (v8 == 0) {
        t[0] = *(Unk0204d610_t *) &v5->mUnk_48;
        t[1] = *(Unk0204d610_t *) &v5->mUnk_40;
        t[2] = *(Unk0204d610_t *) &v5->mUnk_50;
        t[3] = *(Unk0204d610_t *) &v5->mUnk_58;
    } else {
        t[0] = *(Unk0204d610_t *) 0x027ffe48;
        t[1] = *(Unk0204d610_t *) 0x027ffe40;
        v10 = 0;
        t[2].mUnk_00 = (u8 *) (v5->mUnk_50 + v9);
        t[2].mUnk_04 = v5->mUnk_54;
        t[3].mUnk_00 = (u8 *) (v5->mUnk_58 + v9);
        t[3].mUnk_04 = v5->mUnk_5c;
    }
    v7 = v7 + 4;
    for (i = 0; i < 4; i++) {
        v3[i] = (t[i].mUnk_04 + 0x1f) & ~0x1f;
        v7 = v7 + (v3[i] + 4);
    }
    if (v8 != 0) {
        for (i = 2; i < 4; i++) {
            v13 = (((t[i].mUnk_04 >> 5) << 3) + 0x1f) & ~0x1f;
            v3[0] = v3[0] + v13;
            v7 = v7 + v13;
        }
    }
    v13 = IrqDisable();
    v6 = (u32 *) data_02175ec0.mUnk_0014(data_02175ec0.mUnk_0018, v7, NULL);
    IrqRestore(v13);
    *v6 = v10;
    v11 = 0;
    k = FALSE;
    {
        u32 *v15 = v6 + 1;
        u32 *q;
        s32 j;
        for (j = 0; j < 4; j++) {
            v4[j] = v15;
            q = v4[j];
            *q = t[j].mUnk_04;
            FS_SeekFile(&v1, v10 + (u32) t[j].mUnk_00, v11);
            FS_ReadFile(&v1, q + 1, *q);
            v15 = (u32 *) ((u8 *) v15 + (v3[j] + 4));
        }
    }
    if (v8 != 0) {
        u32 *v16 = v4[0];
        u8 *v17 = (u8 *) (v16 + 1);
        s32 n = *v16 >> 3;
        Unk0204d28c_20 *q;
        s32 l;
        u32 *w = (u32 *) (v17 + (n << 3));
        u32 v18 = v9 + v5->mUnk_48;
        v12 = 8;
        for (i = 2; i < 4; i++) {
            u32 *v19 = v4[i];
            s32 v20;
            q = (Unk0204d28c_20 *) (v19 + 1);
            v20 = *v19 >> 5;
            for (l = 0; l < v20; l++) {
                FS_SeekFile(&v1, v18 + (q[l].mUnk_18 << 3), v11);
                FS_ReadFile(&v1, w, v12);
                *(u32 *) (v17 + ((u32) n * 8)) = *(u32 *) (v17 + ((u32) n * 8)) + v9;
                ((u32 *) (v17 + ((u32) n * 8)))[1] = ((u32 *) (v17 + ((u32) n * 8)))[1] + v9;
                q[l].mUnk_18 = n;
                n++;
                w += 2;
            }
        }
        *v4[0] = n << 3;
    }
    func_0200ee74(v6, v7);
    func_0200ee98();
    FS_CloseFile(&v1);
    data_02175ec0.mUnk_0020 = v6;
    data_02175ec0.mUnk_0024 = v7;
}

u32 func_0204d610(u32 *a) {
    Unk0204d610_t t[4];
    u32 r;
    Unk02003a6c *p;
    s32 i;

    p = FS_FindArchive(data_021651d4, 3);
    FS_UnloadArchive(p);
    FS_SetArchiveProc(p, func_0204dab8, -1);
    r = *a++;
    for (i = 0; i < 4; i++) {
        t[i].mUnk_00 = (u8 *) (a + 1);
        t[i].mUnk_04 = *a;
        a = (u32 *) (t[i].mUnk_00 + ((t[i].mUnk_04 + 0x1f) & ~0x1f));
    }
    FS_LoadArchive(p, NULL, (u32) t[0].mUnk_00, t[0].mUnk_04, (u32) t[1].mUnk_00, t[1].mUnk_04, func_0204db48,
                   func_0204db40);
    FS_AttachOverlayTable(0, t[2].mUnk_00, t[2].mUnk_04);
    FS_AttachOverlayTable(1, t[3].mUnk_00, t[3].mUnk_04);
    return r;
}

void func_0204d5bc(void) {
    Unk02175ec0 *p = &data_02175ec0;

    if (p->mUnk_000c == 0) {
        return;
    }
    if (p->mUnk_0000 == 0) {
        return;
    }
    p->mUnk_0440.mUnk_46d4 = FALSE;
    func_0204d28c();
}

void func_0204d28c(void) {
    Unk02175ec0_msg v1;
    Unk02175ec0_msg v2;
    BOOL v6;
    Unk02175ec0_440 *v3;
    s32 v4;
    s32 i;
    s32 v5;
    s32 v7;
    Unk02175ec0_440 *e;
    u32 n;
    s32 g;
    Unk02175ec0 *q = &data_02175ec0;
    Unk02175ec0_440s *p = (Unk02175ec0_440s *) ((u32) q + 0x440);
    s32 a;

    if (q->mUnk_0000 == 0) {
        return;
    }
    if (p->mUnk_46d4 != FALSE) {
        return;
    }
    p->mUnk_46cc = p->mUnk_46cc & p->mUnk_46d8;
    p->mUnk_46d0 = p->mUnk_46d0 & p->mUnk_46d8;
    p->mUnk_46dc = p->mUnk_46dc & p->mUnk_46d8;
    p->mUnk_46e8 = p->mUnk_46e8 & p->mUnk_46d8;
    if (p->mUnk_46e0 != FALSE && p->mUnk_46e4 == 0) {
        g = p->mUnk_46ec;
        n = data_02175ec0.mUnk_002c;
        p->mUnk_46e0 = FALSE;
        data_02175ec0.mUnk_0028 = g;
        func_02006f14(g, n);
        g = p->mUnk_46e8;
        if (g == 0) {
            return;
        }
        v1.mUnk_00_0 = 1;
        v1.mUnk_00_8 = 0;
        v1.mUnk_04 = 0;
        v1.mUnk_00_4 = (data_02175ec0.mUnk_0028 >> 8) & 0xff;
        v1.mUnk_08 = data_02175ec0.mUnk_0028;
        if (func_02006d3c((u16) g, &v1, 9, func_0204d5bc) == 0) {
            return;
        }
        p->mUnk_46d4 = TRUE;
        p->mUnk_46e8 = 0;
        return;
    }
    v4 = p->mUnk_46cc;
    if (v4 == 0) {
        return;
    }
    v5 = p->mUnk_46d0;
    v3 = NULL;
    if (v5 != 0 && v5 == (v5 & v4)) {
        v6 = TRUE;
    } else {
        v6 = FALSE;
    }
    if (v6 != FALSE) {
        v4 = v5;
    } else {
        v4 = v4 & ~v5;
    }
    e = p->mUnk_0000;
    for (i = 0;; e++, i++) {
        v7 = 1 << i;
        if (v7 > v4) {
            break;
        }
        if ((v7 & v4) != 0) {
            if (v3 == NULL) {
                v3 = e;
            } else if (v3->mUnk_00_0 != e->mUnk_00_0 || v3->mUnk_04 != e->mUnk_04) {
                v4 = v4 & ~v7;
            }
        }
    }
    if (v6 != FALSE) {
        if (v4 != v5) {
            p->mUnk_46d0 = 0;
        }
    }
    if (v3 == NULL) {
        return;
    }
    switch (v3->mUnk_00_0) {
        case 0:
            v3->mUnk_00_0 = 1;
            break;
        case 2:
            v3->mUnk_00_0 = 3;
            p->mUnk_46dc = p->mUnk_46dc & ~v4;
            break;
    }
    a = *(volatile s32 *) &v3->mUnk_04;
    v2.mUnk_00_0 = (u8) v3->mUnk_00_0;
    v2.mUnk_04 = a;
    v2.mUnk_00_8 = 1;
    v2.mUnk_00_4 = (data_02175ec0.mUnk_0028 >> 8) & 0xff;
    v2.mUnk_08 = data_02175ec0.mUnk_0028;
    if (func_02006d3c((u16) v4, &v2, 9, func_0204d5bc) == 0) {
        return;
    }
    p->mUnk_46d4 = TRUE;
    p->mUnk_46cc = p->mUnk_46cc & ~v4;
}

void func_0204d18c(Unk02175ec0_440s *a, Unk0204c090 *b, s32 c) {
    u32 v1;
    s32 v2;
    s32 v6;
    s32 v3;
    s32 v4;
    Unk02175ec0_440 *v5;

    v1 = IrqDisable();
    if (data_02175ec0.mUnk_000c != 0) {
        v2 = b->mUnk_088;
        b->mUnk_088 = 0;
        a->mUnk_46cc = a->mUnk_46cc | v2;
        if (b->mUnk_084 <= 0) {
            v4 = b->mUnk_038.mUnk_20.w.mUnk_08 - b->mUnk_038.mUnk_20.w.mUnk_04;
            v6 = b->mUnk_08c;
            func_02006e74(&b->mUnk_004, v6, data_usa_0215470c, v4 <= 0x400u ? b->mUnk_0c0[0] : 0, v4, 0);
            func_0204d110(&a->mUnk_46c8, &a->mUnk_46c4, b);
            b->mUnk_080 = 2;
        }
        v5 = (Unk02175ec0_440 *) a;
        for (v3 = 0;; v3++) {
            if ((1 << v3) > v2) {
                break;
            }
            if (((1 << v3) & v2) != 0) {
                b->mUnk_084 = b->mUnk_084 + 1;
                v5->mUnk_04 = b->mUnk_08c;
            }
            v5++;
        }
    }
    IrqRestore(v1);
}

void func_0204d110(Unk0204c090 **a, Unk0204c090 **b, Unk0204c090 *c) {
    u32 v1;
    Unk0204c090 *v2;
    Unk0204c090 *v3;

    v1 = IrqDisable();
    v2 = *a;
    if (v2 == c) {
        *a = c->mUnk_000;
        c->mUnk_000 = *b;
        *b = c;
    } else if (v2 != NULL) {
        do {
            v3 = v2->mUnk_000;
            if (v3 == c) {
                v2->mUnk_000 = c->mUnk_000;
                c->mUnk_000 = *b;
                *b = c;
                break;
            }
            v2 = v3;
        } while (v3 != NULL);
    }
    IrqRestore(v1);
}

void func_0204d0bc(Unk02175ec0_440s *a, Unk0204c090 *b) {
    func_0204d110(&a->mUnk_46c8, &a->mUnk_46c0, b);
    b->mUnk_080 = 0;
    a->mUnk_46e4 = a->mUnk_46e4 - 1;
}

void func_0204cf5c(Unk02003024 *a) {
    Unk02175ec0_msg v1;
    s32 v2;
    u32 v3;
    void *v4;
    u32 v5;
    Unk0204bfac *s;
    void *v6;
    u32 v7;
    s32 b;

    v2 = a->mUnk_30.p.mUnk_08;
    s = (Unk0204bfac *) &data_usa_021762e0;
    if (v2 < 0) {
        v2 = s->mUnk_b04;
        s->mUnk_b04 = 0;
    }
    if (s->mUnk_b04 < v2) {
        s->mUnk_b04 = v2;
        v4 = s->mUnk_afc;
        if (v4 != NULL) {
            v5 = IrqDisable();
            data_02175ec0.mUnk_0014(data_02175ec0.mUnk_0018, 0, v4);
            IrqRestore(v5);
        }
        v3 = (s->mUnk_b04 + (data_02175ec0.mUnk_0028 - 0xe) - 1) / (data_02175ec0.mUnk_0028 - 0xe);
        v3 = ((v3 + 0x1f) >> 2) << 4;
        v7 = IrqDisable();
        v6 = data_02175ec0.mUnk_0014(data_02175ec0.mUnk_0018, v3, NULL);
        IrqRestore(v7);
        s->mUnk_afc = v6;
        s->mUnk_080[0] = s->mUnk_afc;
    }
    data_02175ec0.mUnk_001c = a;
    b = *(volatile s32 *) &a->mUnk_30.p.mUnk_08;
    v1.mUnk_04 = s->mUnk_b00 + a->mUnk_2c;
    v1.mUnk_00_0 = 0;
    v1.mUnk_00_8 = b;
    v1.mUnk_00_4 = (data_02175ec0.mUnk_0028 >> 8) & 0xff;
    v1.mUnk_08 = data_02175ec0.mUnk_0028;
    if (func_02006d3c(1, &v1, 9, func_0204d5bc) != 0) {
        return;
    }
    IrqDisableLoopForever();
}

void func_0204ce60(void) {
    Unk02175ec0 *p;
    s32 v1;
    u16 v2;
    u16 v3;
    u8 *v4;

    p = &data_02175ec0;
    if (p->mUnk_000c == 0) {
        return;
    }
    p->mUnk_0004 = TRUE;
    func_0204d28c();
    p = &data_02175ec0;
    v1 = p->mUnk_0000;
    if (v1 != 0) {
        v2 = p->mUnk_0028;
    } else {
        v2 = p->mUnk_002c;
    }
    if (p->mUnk_0004 == FALSE) {
        return;
    }
    v4 = p->mUnk_0040;
    if (v1 != 0) {
        v3 = ((u32(*)(s32, s32)) func_02006954)((s32) v4, v2);
    } else {
        v3 = ((u32(*)(s32, s32)) func_02006914)((s32) v4, v2);
    }
    p->mUnk_0008 = func_02144048(func_0204ce60, NULL, v4, v3, 0xffff, p->mUnk_0030, 3) == 2;
    p->mUnk_0004 = data_02175ec0.mUnk_0008 == FALSE;
}

void func_0204cc94(Unk0204cc94 *a) {
    Unk02175ec0 *p;
    Unk02175ec0_440s *z;
    s32 v1;
    u16 v2;
    u16 v3;
    u8 *v4;
    const u8 *s;
    u16 n;
    u16 m;

    p = &data_02175ec0;
    z = (Unk02175ec0_440s *) ((u8 *) p + 0x440);
    if (p->mUnk_000c == 0) {
        return;
    }
    switch (a->mUnk_04) {
        case 7:
            v1 = p->mUnk_0000;
            if (v1 == 0) {
                return;
            }
            if (p->mUnk_0008 != FALSE) {
                return;
            }
            if (v1 != 0) {
                v2 = p->mUnk_0028;
            } else {
                v2 = p->mUnk_002c;
            }
            if (p->mUnk_0004 == FALSE) {
                return;
            }
            v4 = p->mUnk_0040;
            if (v1 != 0) {
                v3 = ((u32(*)(s32, s32)) func_02006954)((s32) v4, v2);
            } else {
                v3 = ((u32(*)(s32, s32)) func_02006914)((s32) v4, v2);
            }
            p->mUnk_0008 = func_02144048(func_0204ce60, NULL, v4, v3, 0xffff, p->mUnk_0030, 3) == 2;
            p->mUnk_0004 = data_02175ec0.mUnk_0008 == FALSE;
            return;
        case 9:
            if (p->mUnk_0000 == 0) {
                return;
            }
            z->mUnk_46d8 = z->mUnk_46d8 & ~(1 << a->mUnk_12);
            return;
        case 21:
            s = a->mUnk_0c;
            n = a->mUnk_10;
            if (p->mUnk_0000 != 0) {
                m = a->mUnk_12;
                z->mUnk_46d8 = z->mUnk_46d8 | (1 << m);
                func_0200692c(s, n, m);
            } else {
                func_020068f4(s, n);
            }
            return;
    }
}

void func_0204c7e4(Unk0204c320 *a) {
    s32 i;
    Unk0204c320_14 *p;
    s32 v7;
    u32 v6;
    Unk02175ec0_440s *z;
    Unk0204c090 *v2;
    u32 v12;
    Unk0204c090 *v3;
    Unk0204c090 *v1;
    u32 v5;
    Unk0204c320_14 *q;
    s32 j;
    s32 k;
    Unk0204c090 *v4;
    s32 v8;
    s32 v9;
    s32 v10;
    s32 v11;
    s32 v13;
    s32 v14;
    Unk02003024 *v16;
    s32 v15;
    s32 v17;

    i = func_02006fdc(a->mUnk_0a);
    if (a->mUnk_00 != 0xc) {
        return;
    }
    switch (a->mUnk_04) {
        case 2:
            break;
        case 8:
            break;
        case 10:
            z = &data_usa_021762e0;
            p = &a->mUnk_14;
            z->mUnk_0000[i] = p->mUnk_0e;
            switch (a->mUnk_14.mUnk_m.mUnk_00_0) {
                case 0:
                    v6 = a->mUnk_14.mUnk_m.mUnk_00_8;
                    v5 = (a->mUnk_14.mUnk_m.mUnk_00_4 << 8) | p->mUnk_m.mUnk_08;
                    v7 = p->mUnk_m.mUnk_04;
                    if (z->mUnk_46e0 != FALSE || v5 != data_02175ec0.mUnk_0028) {
                        z->mUnk_46e0 = TRUE;
                        z->mUnk_46e8 = z->mUnk_46e8 | (1 << i);
                        z->mUnk_46dc = z->mUnk_46dc | (1 << i);
                        return;
                    }
                    for (v1 = z->mUnk_46c4; v1 != NULL; v1 = v1->mUnk_000) {
                        if (v1->mUnk_080 == 2 && v7 == v1->mUnk_038.mUnk_20.w.mUnk_04) {
                            v16 = &v1->mUnk_038;
                            if (v6 == v16->mUnk_20.w.mUnk_08 - v16->mUnk_20.w.mUnk_04) {
                                break;
                            }
                        }
                    }
                    if (v1 != NULL) {
                        z->mUnk_46cc = z->mUnk_46cc | (1 << i);
                        z->mUnk_0000[i].mUnk_04 = v1->mUnk_08c;
                        v1->mUnk_084 = v1->mUnk_084 + 1;
                    } else {
                        for (v2 = z->mUnk_46c8; v2 != NULL; v2 = v2->mUnk_000) {
                            if (v2->mUnk_080 == 1 && v2->mUnk_090 == v7 && v2->mUnk_094 == v6) {
                                break;
                            }
                        }
                        if (v2 == NULL) {
                            v2 = z->mUnk_46c0;
                            func_0204d110(&z->mUnk_46c0, &z->mUnk_46c8, v2);
                            v2->mUnk_080 = 1;
                            z->mUnk_46e4 = z->mUnk_46e4 + 1;
                            v2->mUnk_084 = 0;
                            v2->mUnk_090 = v7;
                            v2->mUnk_094 = v6;
                            func_0204bca0();
                        }
                        v2->mUnk_088 = v2->mUnk_088 | (1 << i);
                    }
                    z->mUnk_46dc = z->mUnk_46dc | (1 << i);
                    return;
                case 2:
                    v12 = IrqDisable();
                    z->mUnk_46cc = z->mUnk_46cc | (1 << i);
                    v15 = p->mUnk_m.mUnk_04;
                    for (v3 = z->mUnk_46c4; v3 != NULL; v3 = v3->mUnk_000) {
                        if (v3->mUnk_080 == 2 && v3->mUnk_004.mUnk_00 == v15) {
                            break;
                        }
                    }
                    if (v3 != NULL) {
                        v3->mUnk_084 = v3->mUnk_084 - 1;
                        if (v3->mUnk_084 <= 0) {
                            v3->mUnk_088 = 0;
                            func_02006df8(p->mUnk_m.mUnk_04);
                            func_0204d110(&z->mUnk_46c4, &z->mUnk_46c8, v3);
                            v3->mUnk_080 = 3;
                            func_0204bca0();
                        }
                    }
                    IrqRestore(v12);
                    return;
            }
            return;
        case 13:
            q = &a->mUnk_14;
            v5 = q->mUnk_w;
            q->mUnk_0e.mUnk_08 = 0;
            for (v4 = data_02179ec0.mUnk_b04; v4 != NULL; v4 = v4->mUnk_000) {
                if (v4->mUnk_080 == 2 && v4->mUnk_004.mUnk_00 == v5) {
                    break;
                }
            }
            if (v4 == NULL) {
                return;
            }
            v8 = ((Unk0204c320 *) ((u8 *) q - 0x14))->mUnk_20;
            v9 = v4->mUnk_098;
            v10 = q->mUnk_0e.mUnk_04;
            if (v4->mUnk_09c != 2) {
                v17 = (v4->mUnk_038.mUnk_0c & 1) != 0 ? 1 : 0;
                if (v17 == 0) {
                    v4->mUnk_09c = 2;
                }
            }
            v11 = v8 * v9;
            v4->mUnk_098 = v10;
            v13 = v4->mUnk_09c;
            for (v7 = 0; v7 < 2; v7++) {
                if (v7 == v13) {
                    continue;
                }
                v14 = v11 - v4->mUnk_0a4[v7];
                if (v14 < 0) {
                    continue;
                }
                if (v14 + v8 > 0x400) {
                    continue;
                }
                q->mUnk_0e.mUnk_04 = v9;
                q->mUnk_0e.mUnk_08 = (s32) (v4->mUnk_0c0[v7] + v14);
                break;
            }
            if (v4->mUnk_09c != 2) {
                return;
            }
            v11 = v8 * v10;
            for (j = 0; j < 2; j++) {
                v14 = v11 - v4->mUnk_0a4[j];
                if (v14 < 0) {
                    continue;
                }
                if (v14 + v8 <= 0x400) {
                    break;
                }
            }
            if (j < 2) {
                return;
            }
            k = v4->mUnk_0a0;
            do {
                k++;
                if (k >= 2) {
                    k = 0;
                }
            } while (k == v7);
            v4->mUnk_0a0 = k;
            v4->mUnk_09c = k;
            v4->mUnk_0a4[k] = v11 & -0x200;
            FS_SeekFile(&v4->mUnk_038, v11 & -0x200, 0);
            FS_ReadFileAsync(&v4->mUnk_038, v4->mUnk_0c0[k], 0x400);
            break;
    }
}

void func_0204c320(Unk0204c320 *a) {
    Unk0204bfac *s;
    s32 i;
    u32 v1;
    s32 v2;
    u32 v3;
    void *v4;
    u32 v5;
    Unk02175ec0_msg v6;
    Unk02003024 *v7;
    Unk02175ec0_msg *v8;
    Unk02003a6c *v9;
    u32 v10;
    void *v11;

    i = func_02006fdc(a->mUnk_0a);
    s = (Unk0204bfac *) &data_usa_021762e0;
    switch (a->mUnk_00) {
        case 2:
            if (a->mUnk_08 != 0) {
                return;
            }
            data_02175ec0.mUnk_0028 = a->mUnk_14.h.mUnk_16 + 0xe;
            data_02175ec0.mUnk_002c = a->mUnk_14.h.mUnk_18 + 0xe;
            if (data_02175ec0.mUnk_0020 == NULL) {
                func_02006db0(1, 0, s, (void (*)(Unk0216f3dc_9c *)) func_0204c320);
                return;
            }
            if (data_02175ec0.mUnk_001c == NULL) {
                return;
            }
            v1 = s->mUnk_b04;
            s->mUnk_b04 = 0;
            if (s->mUnk_b04 < v1) {
                s->mUnk_b04 = v1;
                v4 = s->mUnk_afc;
                if (v4 != NULL) {
                    v5 = IrqDisable();
                    data_02175ec0.mUnk_0014(data_02175ec0.mUnk_0018, 0, v4);
                    IrqRestore(v5);
                }
                v3 = (s->mUnk_b04 + (data_02175ec0.mUnk_0028 - 0xe) - 1) / (data_02175ec0.mUnk_0028 - 0xe);
                v3 = ((v3 + 0x1f) >> 2) << 4;
                v10 = IrqDisable();
                v11 = data_02175ec0.mUnk_0014(data_02175ec0.mUnk_0018, v3, NULL);
                IrqRestore(v10);
                s->mUnk_afc = v11;
                s->mUnk_080[0] = s->mUnk_afc;
            }
            func_0204cf5c(data_02175ec0.mUnk_001c);
            return;
        case 6:
            v2 = s->mUnk_000[i]->mUnk_04;
            data_02175ec0.mUnk_0024 = v2;
            v5 = IrqDisable();
            v4 = data_02175ec0.mUnk_0014(data_02175ec0.mUnk_0018, v2, NULL);
            IrqRestore(v5);
            data_02175ec0.mUnk_0020 = v4;
            v2 = data_02175ec0.mUnk_0024;
            if (v2 < 0) {
                v2 = s->mUnk_b04;
                s->mUnk_b04 = 0;
            }
            if (s->mUnk_b04 < v2) {
                s->mUnk_b04 = v2;
                v4 = s->mUnk_afc;
                if (v4 != NULL) {
                    v5 = IrqDisable();
                    data_02175ec0.mUnk_0014(data_02175ec0.mUnk_0018, 0, v4);
                    IrqRestore(v5);
                }
                v3 = (s->mUnk_b04 + (data_02175ec0.mUnk_0028 - 0xe) - 1) / (data_02175ec0.mUnk_0028 - 0xe);
                v3 = ((v3 + 0x1f) >> 2) << 4;
                v10 = IrqDisable();
                v11 = data_02175ec0.mUnk_0014(data_02175ec0.mUnk_0018, v3, NULL);
                IrqRestore(v10);
                s->mUnk_afc = v11;
                s->mUnk_080[0] = s->mUnk_afc;
            }
            s->mUnk_040[i] = (u32) data_02175ec0.mUnk_0020;
            func_02006d78(1, 0x20000, s->mUnk_040, data_02175ec0.mUnk_0024, s->mUnk_080,
                          (void (*)(Unk0216f3dc_9c *)) func_0204c320);
            return;
        case 4:
            if (a->mUnk_08 != 0) {
                return;
            }
            if (data_02175ec0.mUnk_000c != 2) {
                func_0200ee74(data_02175ec0.mUnk_0020, data_02175ec0.mUnk_0024);
                s->mUnk_b00 = func_0204d610(data_02175ec0.mUnk_0020);
                data_02175ec0.mUnk_000c = 2;
                if (data_02175ec0.mUnk_0010 == NULL) {
                    return;
                }
                data_02175ec0.mUnk_0010(0);
                return;
            }
            v6.mUnk_04 = s->mUnk_b08;
            v6.mUnk_00_0 = 2;
            v6.mUnk_00_8 = 1;
            v6.mUnk_00_4 = (data_02175ec0.mUnk_0028 >> 8) & 0xff;
            v6.mUnk_08 = data_02175ec0.mUnk_0028;
            if (func_02006d3c(1, &v6, 9, func_0204d5bc) != 0) {
                return;
            }
            IrqDisableLoopForever();
            return;
        case 12:
            if (a->mUnk_04 != 0xa) {
                return;
            }
            v8 = &a->mUnk_14.mUnk_m;
            switch (v8->mUnk_00_0) {
                case 1:
                    if (v8->mUnk_00_8 == 0) {
                        func_02006ddc(1, (void (*)(Unk0216f3dc_9c *)) func_0204c320);
                        return;
                    }
                    s->mUnk_b08 = v8->mUnk_04;
                    s->mUnk_040[i] = data_02175ec0.mUnk_001c->mUnk_30.w.mUnk_00;
                    func_02006d78(1, s->mUnk_b08, s->mUnk_040, data_02175ec0.mUnk_001c->mUnk_30.w.mUnk_08, s->mUnk_080,
                                  (void (*)(Unk0216f3dc_9c *)) func_0204c320);
                    return;
                case 3:
                    v7 = data_02175ec0.mUnk_001c;
                    v9 = v7->mUnk_08;
                    data_02175ec0.mUnk_001c = NULL;
                    v7->mUnk_2c = v7->mUnk_2c + v7->mUnk_30.w.mUnk_08;
                    FS_NotifyArchiveAsyncEnd(v9, 0);
                    return;
            }
            return;
    }
}

void func_0204c28c(u32 a, u32 b, u32 c, u32 d) {
    Unk02175ec0 *const v1 = &data_02175ec0;
    u16 v2;

    FS_Init(-1);
    v2 = a;
    v1->mUnk_0030 = v2;
    v1->mUnk_0004 = FALSE;
    v1->mUnk_0008 = FALSE;
    v1->mUnk_000c = 0;
    v1->mUnk_0010 = (void (*)(s32)) b;
    v1->mUnk_0014 = (void *(*) (s32, u32, void *) ) c;
    v1->mUnk_0018 = d;
    v1->mUnk_001c = NULL;
    v1->mUnk_0024 = 0;
    v1->mUnk_0020 = NULL;
    v1->mUnk_0028 = 0;
    v1->mUnk_002c = 0xe;
    data_usa_02175e80 = 0;
    if (func_0214358c(v2, func_0204cc94, NULL) != 0) {
        IrqDisableLoopForever();
    }
}

void func_0204c090(u32 a, u32 b, u32 c, u32 d, u32 e, Unk02003024 *f, s32 g) {
    u32 v1;
    Unk02175ec0 *v2;
    Unk02175ec0_440s *v3;
    Unk0204c090 *v4;
    Unk0204c090 *v7;

    v1 = IrqDisable();
    if (data_usa_02175e84 != 0) {
        return;
    }
    data_usa_02175e84 = 1;
    func_0204c28c(a, b, c, d);
    IrqRestore(v1);
    v2 = &data_02175ec0;
    v2->mUnk_0000 = 1;
    v3 = (Unk02175ec0_440s *) ((u8 *) v2 + 0x440);
    func_0200ee74(v3, 0x46f0);
    func_0200ee98();
    v4 = (Unk0204c090 *) ((u8 *) v3 + 0xc0);
    v3->mUnk_46c0 = v4;
    if (v4 + 1 < (Unk0204c090 *) &v3->mUnk_46c0) {
        do {
            v4->mUnk_000 = v4 + 1;
            FS_InitFile(&v4->mUnk_038);
            v4->mUnk_084 = 0;
            v4->mUnk_080 = 0;
            v4->mUnk_08c = (v4 + 0x10001) - (Unk0204c090 *) ((u8 *) v3 + 0xc0);
            v4++;
        } while (v4 + 1 < (Unk0204c090 *) &v3->mUnk_46c0);
    }
    v4->mUnk_000 = NULL;
    v3->mUnk_46d0 = 0;
    v3->mUnk_46cc = 0;
    v3->mUnk_46d4 = FALSE;
    v3->mUnk_46c4 = NULL;
    v3->mUnk_46c8 = NULL;
    v2->mUnk_0028 = e;
    v3->mUnk_46d8 = 1;
    v3->mUnk_46dc = 0;
    v3->mUnk_46e0 = FALSE;
    v3->mUnk_46e8 = 0;
    v3->mUnk_46e4 = 0;
    v3->mUnk_46ec = v2->mUnk_0028;
    func_0200ee74(v3, 0x46f0);
    func_0200ee98();
    func_02006aac(v2->mUnk_0028, v2->mUnk_002c, (void (*)(Unk0216f3dc_9c *)) func_0204c7e4);
    func_0204d6f4(f, g);
    v7 = v3->mUnk_46c0;
    v3->mUnk_46c0 = v7->mUnk_000;
    v7->mUnk_000 = v3->mUnk_46c4;
    v3->mUnk_46c4 = v7;
    v7->mUnk_084 = 1;
    MemFill(v7, 0, 0x8c0);
    func_02006e74(&v7->mUnk_004, 0x20000, data_usa_0215470c, v2->mUnk_0020, data_02175ec0.mUnk_0024, 0);
    v2->mUnk_000c = 1;
    func_0204bad8();
}

void func_0204bfac(u32 a, u32 b, u32 c, u32 d) {
    u32 v1;
    Unk02175ec0 *v2;
    Unk0204bfac *v3;
    s32 i;

    v1 = IrqDisable();
    if (data_usa_02175e84 != 0) {
        return;
    }
    data_usa_02175e84 = 1;
    func_0204c28c(a, b, c, d);
    IrqRestore(v1);
    v2 = &data_02175ec0;
    v2->mUnk_0000 = 0;
    v3 = (Unk0204bfac *) ((u8 *) v2 + 0x440);
    func_0200ee74(v3, 0xb0c);
    func_0200ee98();
    for (i = 0; i < 16; i++) {
        v3->mUnk_000[i] = &v3->mUnk_0c0[i];
        v3->mUnk_040[i] = 0;
        v3->mUnk_080[i] = NULL;
    }
    v3->mUnk_afc = NULL;
    v3->mUnk_b04 = 0;
    v3->mUnk_b08 = 0;
    func_0200ee74(v3, 0xb0c);
    func_0200ee98();
    func_02006a10((void (*)(Unk0216f3dc_9c *)) func_0204c320);
    v2->mUnk_000c = 1;
}

void func_0204bf48(int a, u32 b, u32 c, void *d, void *e, u32 f) {
    if (a != 0) {
        func_0204c090(b, (u32) d, (u32) e, f, c, NULL, 1);
        return;
    }
    func_0204bfac(b, (u32) d, (u32) e, f);
}

static inline void func_0204bcec_inline(Unk02175ec0 *a, void *p) {
    u32 t;
    if (p != NULL) {
        t = IrqDisable();
        a->mUnk_0014(a->mUnk_0018, 0, p);
        IrqRestore(t);
    }
}

void func_0204be0c(void) {
    Unk021762e0 *w;
    Unk02175ec0 *g;
    u8 *q;
    u16 h;
    u16 r;
    s32 z;
    data_02175ec0.mUnk_0004 = TRUE;
    if (data_02175ec0.mUnk_0000 == 0) {
        w = (Unk021762e0 *) &data_usa_021762e0;
        func_02143520(w->mUnk_0340);
        func_02007008(w->mUnk_04c4);
        func_02006ddc(1, (void (*)(Unk0216f3dc_9c *)) func_0204c320);
    } else {
        data_02175ec0.mUnk_000c = 2;
        if (data_02175ec0.mUnk_0010 != NULL) {
            data_02175ec0.mUnk_0010(0);
        }
    }
    g = (Unk02175ec0 *) &data_02175ec0;
    z = g->mUnk_0000;
    if (z != 0) {
        h = g->mUnk_0028;
    } else {
        h = g->mUnk_002c;
    }
    if (g->mUnk_0004 == FALSE) {
        return;
    }
    q = g->mUnk_0040;
    if (z != 0) {
        r = func_02006954((s32) q, h);
    } else {
        r = func_02006914((s32) q, h);
    }
    g->mUnk_0008 = func_02144048(func_0204ce60, NULL, q, r, 0xffff, g->mUnk_0030, 3) == 2;
    g->mUnk_0004 = data_02175ec0.mUnk_0008 == FALSE;
}

void func_0204bcec(void) {
    Unk02175ec0 *g;
    Unk02175ec0_440s *q;
    u32 s;
    void *p;
    Unk02003a6c *u;
    g = (Unk02175ec0 *) &data_02175ec0;
    s = IrqDisable();
    if (data_usa_02175e84 != 0) {
        p = g->mUnk_0020;
        if (p != NULL) {
            func_0204bcec_inline(&data_02175ec0, p);
            g->mUnk_0020 = NULL;
            g->mUnk_0024 = 0;
        }
        g->mUnk_000c = 0;
        if (data_02175ec0.mUnk_0000 == 0) {
            q = &g->mUnk_0440;
            if (g->mUnk_001c != NULL) {
                u = g->mUnk_001c->mUnk_08;
                g->mUnk_001c = NULL;
                FS_NotifyArchiveAsyncEnd(u, 5);
            }
            func_0204bcec_inline(&data_02175ec0, q->mUnk_0afc);
        } else {
            func_0204ba8c();
        }
        func_02006974();
        func_0214358c(data_02175ec0.mUnk_0030, NULL, NULL);
        data_usa_02175e84 = 0;
    }
    IrqRestore(s);
}

u32 func_0204bcdc(void) {
    u32 value0;
    value0 = (u32) &data_02175ec0;
    value0 = (u32) * (const u32 *) ((value0) + (12));
    return value0;
}

u32 func_0204bcb4(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value4;
    value4 = value0;
    value0 = (u32) IrqDisable();
    value1 = (u32) &data_02179ec0;
    value2 = (value4) & ~(1u);
    *(u32 *) ((value1) + (2832)) = value2;
    value0 = (u32) IrqRestore(value0);
    return value0;
}

void func_0204bca0(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &ThreadSetRunnable;
    value0 = (u32) &data_02175dd8;
    ThreadSetRunnable((Thread *) value0);
}
