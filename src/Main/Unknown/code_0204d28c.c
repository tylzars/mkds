#include "Main/Unknown/code_0204bfac.h"
#include "Main/Unknown/code_0204d28c.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/code_0204c000.h"
#include "Main/Unknown/code_0204db40.h"
#include "Main/Unknown/code_0204db48.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_02175000.h"
#include "code_02003be0.h"
#include "code_02004d80.h"
#include "code_02004dc0.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"

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
    if (p->mUnk_46d4 != 0) {
        return;
    }
    p->mUnk_46cc = p->mUnk_46cc & p->mUnk_46d8;
    p->mUnk_46d0 = p->mUnk_46d0 & p->mUnk_46d8;
    p->mUnk_46dc = p->mUnk_46dc & p->mUnk_46d8;
    p->mUnk_46e8 = p->mUnk_46e8 & p->mUnk_46d8;
    if (p->mUnk_46e0 != 0 && p->mUnk_46e4 == 0) {
        g = p->mUnk_46ec;
        n = data_02175ec0.mUnk_002c;
        p->mUnk_46e0 = 0;
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
        p->mUnk_46d4 = 1;
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
    p->mUnk_46d4 = 1;
    p->mUnk_46cc = p->mUnk_46cc & ~v4;
}

void func_0204d5bc(void) {
    Unk02175ec0 *p = &data_02175ec0;

    if (p->mUnk_000c == 0) {
        return;
    }
    if (p->mUnk_0000 == 0) {
        return;
    }
    p->mUnk_0440.mUnk_46d4 = 0;
    func_0204d28c();
}

typedef struct Unk0204d610_t {
    u8 *mUnk_00;
    u32 mUnk_04;
} Unk0204d610_t;

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

// non-matching: the inner loop's w and q trade r5/r7 (the original keeps w in r5, q in r7)
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
        u32 *w = (u32 *) (v17 + (n << 3));
        u32 v18 = v9 + v5->mUnk_48;
        v12 = 8;
        for (i = 2; i < 4; i++) {
            s32 l;
            u32 *v19 = v4[i];
            Unk0204d28c_20 *q = (Unk0204d28c_20 *) (v19 + 1);
            s32 v20 = *v19 >> 5;
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
