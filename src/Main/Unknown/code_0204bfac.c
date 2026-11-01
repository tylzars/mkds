#include "Main/Unknown/code_0204bfac.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/code_02006c2c.h"
#include "Main/Unknown/code_02006f14.h"
#include "Main/Unknown/code_02006380.h"
#include "Main/Unknown/code_0200692c.h"
#include "Main/Unknown/code_0204d28c.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02176000.h"
#include "Main/Unknown/unk_02179000.h"
#include "code_02003be0.h"
#include "code_02004270.h"
#include "Main/Unknown/code_02004d80.h"
#include "code_02004dc0.h"
#include "code_0200fd1c.h"
#include "code_0214d018.h"
#include "code_02142eac.h"
#include "Main/Unknown/code_0204bca0.h"

void func_0204bfac(u32 a, u32 b, u32 c, u32 d) {
    u32 v1;
    Unk02175ec0 *v2;
    Unk0204bfac *v3;
    s32 i;

    v1 = func_0200fca0();
    if (data_usa_02175e84 != 0) {
        return;
    }
    data_usa_02175e84 = 1;
    func_0204c28c(a, b, c, d);
    func_0200fcb4(v1);
    v2 = &data_02175ec0;
    v2->mUnk_0000 = 0;
    v3 = (Unk0204bfac *) ((u8 *) v2 + 0x440);
    func_0200ee74(v3, 0xb0c);
    func_0200ee98();
    for (i = 0; i < 16; i++) {
        v3->mUnk_000[i] = &v3->mUnk_0c0[i];
        v3->mUnk_040[i] = 0;
        v3->mUnk_080[i] = 0;
    }
    v3->mUnk_afc = 0;
    v3->mUnk_b04 = 0;
    v3->mUnk_b08 = 0;
    func_0200ee74(v3, 0xb0c);
    func_0200ee98();
    func_02006a10((void (*)(Unk0216f3dc_9c *)) func_0204c320);
    v2->mUnk_000c = 1;
}

// non-matching: size matches (0x1fc); 14 words differ: before the node loop the end pointer, the copy of the first node
// and the zero sit in r7, r8 and r6 where the original has r8, r6 and r7, and five instructions there are in another
// order
void func_0204c090(u32 a, u32 b, u32 c, u32 d, u32 e, Unk02003024 *f, s32 g) {
    u32 v1;
    Unk02175ec0 *v2;
    Unk02175ec0_440s *v3;
    Unk0204c090 *v4;
    Unk0204c090 *v6;
    Unk0204c090 *v5;
    Unk0204c090 *v7;

    v1 = func_0200fca0();
    if (data_usa_02175e84 != 0) {
        return;
    }
    data_usa_02175e84 = 1;
    func_0204c28c(a, b, c, d);
    func_0200fcb4(v1);
    v2 = &data_02175ec0;
    v2->mUnk_0000 = 1;
    v3 = (Unk02175ec0_440s *) ((u8 *) v2 + 0x440);
    func_0200ee74(v3, 0x46f0);
    func_0200ee98();
    v4 = (Unk0204c090 *) ((u8 *) v3 + 0xc0);
    v5 = (Unk0204c090 *) ((u8 *) v3 + 0x46c0);
    v3->mUnk_46c0 = v4;
    if (v4 + 1 < v5) {
        v6 = v4;
        do {
            v4->mUnk_000 = v4 + 1;
            func_02004d80(&v4->mUnk_038);
            v4->mUnk_084 = 0;
            v4->mUnk_080 = 0;
            v4->mUnk_08c = (v4 + 0x10001) - v6;
            v4++;
        } while (v4 + 1 < v5);
    }
    v4->mUnk_000 = 0;
    v3->mUnk_46d0 = 0;
    v3->mUnk_46cc = 0;
    v3->mUnk_46d4 = 0;
    v3->mUnk_46c4 = 0;
    v3->mUnk_46c8 = 0;
    v2->mUnk_0028 = e;
    v3->mUnk_46d8 = 1;
    v3->mUnk_46dc = 0;
    v3->mUnk_46e0 = 0;
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
    func_0214d168(v7, 0, 0x8c0);
    func_02006e74(&v7->mUnk_004, 0x20000, data_usa_0215470c, v2->mUnk_0020, data_02175ec0.mUnk_0024, 0);
    v2->mUnk_000c = 1;
    func_0204bad8();
}

// non-matching: size 0xa0 against 0x94; the original loads the address of data_02175ec0 into r4 before the call to
// func_02004dc0 and keeps the first parameter in r8 (push of r4-r8, no stack word); ours loads it after the call and
// pushes r4-r7 with a stack word
void func_0204c28c(u32 a, u32 b, u32 c, u32 d) {
    Unk02175ec0 *v1;
    u16 v2;

    v1 = &data_02175ec0;
    func_02004dc0(-1);
    v2 = a;
    v1->mUnk_0030 = v2;
    v1->mUnk_0004 = 0;
    v1->mUnk_0008 = 0;
    v1->mUnk_000c = 0;
    v1->mUnk_0010 = (void (*)(s32)) b;
    v1->mUnk_0014 = (void *(*) (s32, u32, void *) ) c;
    v1->mUnk_0018 = d;
    v1->mUnk_001c = 0;
    v1->mUnk_0024 = 0;
    v1->mUnk_0020 = 0;
    v1->mUnk_0028 = 0;
    v1->mUnk_002c = 0xe;
    data_usa_02175e80 = 0;
    if (func_0214358c(v2, func_0204cc94, 0) != 0) {
        func_0200fd1c();
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
            if (data_02175ec0.mUnk_0020 == 0) {
                func_02006db0(1, 0, s, (void (*)(Unk0216f3dc_9c *)) func_0204c320);
                return;
            }
            if (data_02175ec0.mUnk_001c == 0) {
                return;
            }
            v1 = s->mUnk_b04;
            s->mUnk_b04 = 0;
            if (s->mUnk_b04 < v1) {
                s->mUnk_b04 = v1;
                v4 = s->mUnk_afc;
                if (v4 != 0) {
                    v5 = func_0200fca0();
                    data_02175ec0.mUnk_0014(data_02175ec0.mUnk_0018, 0, v4);
                    func_0200fcb4(v5);
                }
                v3 = (s->mUnk_b04 + (data_02175ec0.mUnk_0028 - 0xe) - 1) / (data_02175ec0.mUnk_0028 - 0xe);
                v3 = ((v3 + 0x1f) >> 2) << 4;
                v10 = func_0200fca0();
                v11 = data_02175ec0.mUnk_0014(data_02175ec0.mUnk_0018, v3, 0);
                func_0200fcb4(v10);
                s->mUnk_afc = v11;
                s->mUnk_080[0] = s->mUnk_afc;
            }
            func_0204cf5c(data_02175ec0.mUnk_001c);
            return;
        case 6:
            v2 = s->mUnk_000[i]->mUnk_04;
            data_02175ec0.mUnk_0024 = v2;
            v5 = func_0200fca0();
            v4 = data_02175ec0.mUnk_0014(data_02175ec0.mUnk_0018, v2, 0);
            func_0200fcb4(v5);
            data_02175ec0.mUnk_0020 = v4;
            v2 = data_02175ec0.mUnk_0024;
            if (v2 < 0) {
                v2 = s->mUnk_b04;
                s->mUnk_b04 = 0;
            }
            if (s->mUnk_b04 < v2) {
                s->mUnk_b04 = v2;
                v4 = s->mUnk_afc;
                if (v4 != 0) {
                    v5 = func_0200fca0();
                    data_02175ec0.mUnk_0014(data_02175ec0.mUnk_0018, 0, v4);
                    func_0200fcb4(v5);
                }
                v3 = (s->mUnk_b04 + (data_02175ec0.mUnk_0028 - 0xe) - 1) / (data_02175ec0.mUnk_0028 - 0xe);
                v3 = ((v3 + 0x1f) >> 2) << 4;
                v10 = func_0200fca0();
                v11 = data_02175ec0.mUnk_0014(data_02175ec0.mUnk_0018, v3, 0);
                func_0200fcb4(v10);
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
                if (data_02175ec0.mUnk_0010 == 0) {
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
            func_0200fd1c();
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
                    data_02175ec0.mUnk_001c = 0;
                    v7->mUnk_2c = v7->mUnk_2c + v7->mUnk_30.w.mUnk_08;
                    func_02003be0(v9, 0);
                    return;
            }
            return;
    }
}

// non-matching: size matches (0x4b0); 118 words differ, only in register numbers: the original keeps the parameter in
// r5, the index in r4, the table in r6, the first word in r7 and the pointer to the payload in r8; ours uses r7, r6,
// r5, r8 and r4
void func_0204c7e4(Unk0204c320 *a) {
    s32 i;
    Unk02175ec0_440s *z;
    Unk0204c320_14 *p;
    Unk0204c090 *v1;
    Unk0204c090 *v2;
    Unk0204c090 *v3;
    Unk0204c090 *v4;
    u32 v5;
    u32 v6;
    s32 v7;
    s32 v8;
    s32 v9;
    s32 v10;
    s32 v11;
    u32 v12;
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
                    v5 = (a->mUnk_14.mUnk_m.mUnk_00_4 << 8) | p->mUnk_m.mUnk_08;
                    v6 = a->mUnk_14.mUnk_m.mUnk_00_8;
                    v7 = p->mUnk_m.mUnk_04;
                    if (z->mUnk_46e0 != 0 || v5 != data_02175ec0.mUnk_0028) {
                        z->mUnk_46e0 = 1;
                        z->mUnk_46e8 = z->mUnk_46e8 | (1 << i);
                        z->mUnk_46dc = z->mUnk_46dc | (1 << i);
                        return;
                    }
                    for (v1 = z->mUnk_46c4; v1 != 0; v1 = v1->mUnk_000) {
                        if (v1->mUnk_080 == 2 && v7 == v1->mUnk_038.mUnk_20.w.mUnk_04) {
                            v16 = &v1->mUnk_038;
                            if (v6 == v16->mUnk_20.w.mUnk_08 - v16->mUnk_20.w.mUnk_04) {
                                break;
                            }
                        }
                    }
                    if (v1 != 0) {
                        z->mUnk_46cc = z->mUnk_46cc | (1 << i);
                        z->mUnk_0000[i].mUnk_04 = v1->mUnk_08c;
                        v1->mUnk_084 = v1->mUnk_084 + 1;
                    } else {
                        for (v2 = z->mUnk_46c8; v2 != 0; v2 = v2->mUnk_000) {
                            if (v2->mUnk_080 == 1 && v2->mUnk_090 == v7 && v2->mUnk_094 == v6) {
                                break;
                            }
                        }
                        if (v2 == 0) {
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
                    v12 = func_0200fca0();
                    z->mUnk_46cc = z->mUnk_46cc | (1 << i);
                    v15 = p->mUnk_m.mUnk_04;
                    for (v3 = z->mUnk_46c4; v3 != 0; v3 = v3->mUnk_000) {
                        if (v3->mUnk_080 == 2 && v3->mUnk_004.mUnk_00 == v15) {
                            break;
                        }
                    }
                    if (v3 != 0) {
                        v3->mUnk_084 = v3->mUnk_084 - 1;
                        if (v3->mUnk_084 <= 0) {
                            v3->mUnk_088 = 0;
                            func_02006df8(p->mUnk_m.mUnk_04);
                            func_0204d110(&z->mUnk_46c4, &z->mUnk_46c8, v3);
                            v3->mUnk_080 = 3;
                            func_0204bca0();
                        }
                    }
                    func_0200fcb4(v12);
                    return;
            }
            return;
        case 13:
            p = &a->mUnk_14;
            v5 = p->mUnk_w;
            p->mUnk_0e.mUnk_08 = 0;
            for (v4 = data_02179ec0.mUnk_b04; v4 != 0; v4 = v4->mUnk_000) {
                if (v4->mUnk_080 == 2 && v4->mUnk_004.mUnk_00 == v5) {
                    break;
                }
            }
            if (v4 == 0) {
                return;
            }
            v8 = a->mUnk_20;
            v9 = v4->mUnk_098;
            v10 = p->mUnk_0e.mUnk_04;
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
                    break;
                }
                v14 = v11 - v4->mUnk_0a4[v7];
                if (v14 < 0) {
                    continue;
                }
                if (v14 + v8 > 0x400) {
                    continue;
                }
                p->mUnk_0e.mUnk_04 = v9;
                p->mUnk_0e.mUnk_08 = (s32) (v4->mUnk_0c0[v7] + v14);
                break;
            }
            if (v4->mUnk_09c != 2) {
                return;
            }
            v11 = v8 * v10;
            for (v13 = 0; v13 < 2; v13++) {
                v14 = v11 - v4->mUnk_0a4[v13];
                if (v14 < 0) {
                    continue;
                }
                if (v14 + v8 <= 0x400) {
                    break;
                }
            }
            if (v13 < 2) {
                return;
            }
            v13 = v4->mUnk_0a0;
            do {
                v13++;
                if (v13 >= 2) {
                    v13 = 0;
                }
            } while (v13 == v7);
            v4->mUnk_0a0 = v13;
            v4->mUnk_09c = v13;
            v4->mUnk_0a4[v13] = v11 & -0x200;
            func_02004840(&v4->mUnk_038, v11 & -0x200, 0);
            func_020048bc(&v4->mUnk_038, v4->mUnk_0c0[v13], 0x400);
            return;
    }
}

// non-matching: size 0x1d0 against 0x1cc; in the last case the original loads the word at 0xc and the halfword at 0x10
// of the parameter into r12 and r1 before it tests the first word of data_02175ec0, ours loads them again in each
// branch
void func_0204cc94(Unk0204cc94 *a) {
    Unk02175ec0 *p;
    Unk02175ec0_440s *z;
    s32 v1;
    u16 v2;
    u16 v3;
    u8 *v4;

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
            if (p->mUnk_0008 != 0) {
                return;
            }
            if (v1 != 0) {
                v2 = p->mUnk_0028;
            } else {
                v2 = p->mUnk_002c;
            }
            if (p->mUnk_0004 == 0) {
                return;
            }
            v4 = p->mUnk_0040;
            if (v1 != 0) {
                v3 = ((u32(*)(s32, s32)) func_02006954)((s32) v4, v2);
            } else {
                v3 = ((u32(*)(s32, s32)) func_02006914)((s32) v4, v2);
            }
            p->mUnk_0008 = func_02144048(func_0204ce60, 0, v4, v3, 0xffff, p->mUnk_0030, 3) == 2;
            p->mUnk_0004 = data_02175ec0.mUnk_0008 == 0;
            return;
        case 9:
            if (p->mUnk_0000 == 0) {
                return;
            }
            z->mUnk_46d8 = z->mUnk_46d8 & ~(1 << a->mUnk_12);
            return;
        case 21:
            if (p->mUnk_0000 != 0) {
                z->mUnk_46d8 = z->mUnk_46d8 | (1 << a->mUnk_12);
                func_0200692c(a->mUnk_0c, a->mUnk_10, a->mUnk_12);
            } else {
                func_020068f4(a->mUnk_0c, a->mUnk_10);
            }
            return;
    }
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
    p->mUnk_0004 = 1;
    func_0204d28c();
    p = &data_02175ec0;
    v1 = p->mUnk_0000;
    if (v1 != 0) {
        v2 = p->mUnk_0028;
    } else {
        v2 = p->mUnk_002c;
    }
    if (p->mUnk_0004 == 0) {
        return;
    }
    v4 = p->mUnk_0040;
    if (v1 != 0) {
        v3 = ((u32(*)(s32, s32)) func_02006954)((s32) v4, v2);
    } else {
        v3 = ((u32(*)(s32, s32)) func_02006914)((s32) v4, v2);
    }
    p->mUnk_0008 = func_02144048(func_0204ce60, 0, v4, v3, 0xffff, p->mUnk_0030, 3) == 2;
    p->mUnk_0004 = data_02175ec0.mUnk_0008 == 0;
}

// non-matching: size matches (0x160); 24 words differ: in the original the three stores to the stack object come after
// the sum of the word at 0xb00 and the word at 0x2c is loaded and computed, ours stores each part as soon as it is
// built
void func_0204cf5c(Unk02003024 *a) {
    Unk02175ec0_msg v1;
    s32 v2;
    u32 v3;
    void *v4;
    u32 v5;
    Unk0204bfac *s;
    void *v6;
    u32 v7;

    v2 = a->mUnk_30.p.mUnk_08;
    s = (Unk0204bfac *) &data_usa_021762e0;
    if (v2 < 0) {
        v2 = s->mUnk_b04;
        s->mUnk_b04 = 0;
    }
    if (s->mUnk_b04 < v2) {
        s->mUnk_b04 = v2;
        v4 = s->mUnk_afc;
        if (v4 != 0) {
            v5 = func_0200fca0();
            data_02175ec0.mUnk_0014(data_02175ec0.mUnk_0018, 0, v4);
            func_0200fcb4(v5);
        }
        v3 = (s->mUnk_b04 + (data_02175ec0.mUnk_0028 - 0xe) - 1) / (data_02175ec0.mUnk_0028 - 0xe);
        v3 = ((v3 + 0x1f) >> 2) << 4;
        v7 = func_0200fca0();
        v6 = data_02175ec0.mUnk_0014(data_02175ec0.mUnk_0018, v3, 0);
        func_0200fcb4(v7);
        s->mUnk_afc = v6;
        s->mUnk_080[0] = s->mUnk_afc;
    }
    data_02175ec0.mUnk_001c = a;
    v1.mUnk_00_0 = 0;
    v1.mUnk_00_8 = a->mUnk_30.p.mUnk_08;
    v1.mUnk_00_4 = (data_02175ec0.mUnk_0028 >> 8) & 0xff;
    v1.mUnk_04 = s->mUnk_b00 + a->mUnk_2c;
    v1.mUnk_08 = data_02175ec0.mUnk_0028;
    if (func_02006d3c(1, &v1, 9, func_0204d5bc) != 0) {
        return;
    }
    func_0200fd1c();
}

void func_0204d0bc(Unk02175ec0_440s *a, Unk0204c090 *b) {
    func_0204d110(&a->mUnk_46c8, &a->mUnk_46c0, b);
    b->mUnk_080 = 0;
    a->mUnk_46e4 = a->mUnk_46e4 - 1;
}

void func_0204d110(Unk0204c090 **a, Unk0204c090 **b, Unk0204c090 *c) {
    u32 v1;
    Unk0204c090 *v2;
    Unk0204c090 *v3;

    v1 = func_0200fca0();
    v2 = *a;
    if (v2 == c) {
        *a = c->mUnk_000;
        c->mUnk_000 = *b;
        *b = c;
    } else if (v2 != 0) {
        do {
            v3 = v2->mUnk_000;
            if (v3 == c) {
                v2->mUnk_000 = c->mUnk_000;
                c->mUnk_000 = *b;
                *b = c;
                break;
            }
            v2 = v3;
        } while (v3 != 0);
    }
    func_0200fcb4(v1);
}

void func_0204d18c(Unk02175ec0_440s *a, Unk0204c090 *b, s32 c) {
    u32 v1;
    s32 v2;
    s32 v6;
    s32 v3;
    s32 v4;
    Unk02175ec0_440 *v5;

    v1 = func_0200fca0();
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
    func_0200fcb4(v1);
}
