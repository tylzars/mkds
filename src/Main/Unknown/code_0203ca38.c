#include "Main/Unknown/code_0203ca38.h"
#include "Main/Unknown/code_0203c25c.h"
#include "Main/Unknown/code_0203c5f8.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_020401ac.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_020a02f8.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a1218.h"
#include "Main/Unknown/code_020a128c.h"
#include "Main/Unknown/code_020a12b8.h"
#include "Main/Unknown/code_020b3f64.h"
#include "Main/Unknown/code_021108bc.h"

static inline s32 func_0203ca38_inline(u32 i) {
    return func_020a1250(i) + 1;
}

void func_0203ca38(void) {
    u32 i;
    func_0203fed4();
    if (data_021759c0->mUnk_08 == 5) {
        for (i = 0; i < data_021759c0->mUnk_3d0; i = (u16) (i + 1)) {
            Unk0217561c_14 *p = (Unk0217561c_14 *) ((u8 *) &data_0217561c->mUnk_14[0] + i * 0x8c);
            if (p->mUnk_3c_8 != 0) {
                func_0203e9a0(p, p->mUnk_3c_8 == 1 ? 1 : 0);
                if (func_0203ef58() != 0) {
                    switch (data_021759c0->mUnk_08) {
                        case 1:
                            break;
                        case 2:
                            func_020a12b8();
                            break;
                        case 4:
                            func_0203eb38();
                            break;
                        case 5:
                            func_0203ecf0();
                            break;
                        default:
                            func_0203ee28();
                            break;
                    }
                }
                p->mUnk_3c_8 = 0;
            }
        }
    }
    if (gCourseMap->mUnk_44 != NULL) {
        func_0203d9d4();
    } else {
        BOOL t = FALSE;
        switch (data_021759c0->mUnk_00c) {
            case 1:
            case 2:
            case 6:
                t = TRUE;
                break;
            case 0:
                if (func_02040bc0() != 0) {
                    t = TRUE;
                }
                break;
        }
        data_0217561c->mUnk_4f0 = t;
    }
    if (data_021759c0->mUnk_08 == 2) {
        for (i = 0; i < data_021759c0->mUnk_3d0; i = (u16) (i + 1)) {
            u16 *q;
            u8 v = func_0203ca38_inline(i);
            q = (u16 *) ((u8 *) &data_0217561c->mUnk_000[0].mUnk_50 + i * 0x8c);
            *q = (*q & ~0xf) | (v & 0xf);
        }
        for (i = 0; i < 8; i = (u16) (i + 1)) {
            data_0217561c->mUnk_474[i] = -1;
        }
        func_0203d078();
        if (func_0203cfb4() != 0) {
            func_0203d21c();
        }
    }
    if (data_021759c0->mUnk_08 == 4) {
        func_0203cd14();
    }
    if (data_021759c0->mUnk_08 == 1) {
        BOOL f = FALSE;
        switch (data_0217561c->mUnk_000[0].mUnk_14) {
            case 1:
            case 2:
            case 3:
                f = TRUE;
                break;
        }
        if (f == FALSE) {
            return;
        }
        if (data_0217561c->mUnk_4cc == 0) {
            data_0217561c->mUnk_4cc = 1;
        }
        return;
    }
    if ((u32) data_0217561c->mUnk_000[0].mUnk_0e < data_021759c0->mUnk_3d0) {
        return;
    }
    if (data_0217561c->mUnk_4cc != 0) {
        return;
    }
    func_0203d21c();
}

void func_0203cd04(u16 a) {
    func_0203e788(a, 4);
}

static inline u16 func_0203cd14_inline(s32 v) {
    return (u16) v;
}

void func_0203cd14(void) {
    BOOL g = FALSE;
    s32 k = 2;
    Unk021759c0 *d = data_021759c0;
    s32 v = d->mUnk_62;
    u16 w;
    u32 v1;
    Unk0217561c_14 *p;
    BOOL h;
    if (v < 0) {
        return;
    }
    w = v;
    v1 = w * 0x8c;
    p = (Unk0217561c_14 *) ((u8 *) &data_0217561c->mUnk_14[0] + v1);
    h = FALSE;
    switch (p->mUnk_00) {
        case 1:
        case 2:
        case 3:
            h = TRUE;
            break;
    }
    if (h != FALSE) {
        if ((p->mUnk_30 & 0x10) != 0) {
            data_0217561c->mUnk_4fa++;
            if (data_0217561c->mUnk_4fa <= data_021759c0->mUnk_038) {
                return;
            }
            func_020688a0(func_0207a974((u16) v));
            func_0207a828(func_0203cd14_inline(v));
            func_020b3f64();
            func_02110cc8(0);
            if (data_021759c0->mUnk_08 == 4) {
                func_020a0dbc();
            }
            p = (Unk0217561c_14 *) ((u8 *) &data_0217561c->mUnk_14[0] + v1);
            p->mUnk_30 &= ~0x10;
        } else if ((p->mUnk_30 & 0x20) != 0) {
            if (func_0207a218() != 0) {
                data_0217561c->mUnk_4fc++;
            }
            if (data_0217561c->mUnk_4fc <= 0x3c) {
                return;
            }
            func_020688a0(func_0207a974(v));
            func_0207a828((u16) v);
            func_02110cc8(0);
            if (data_021759c0->mUnk_08 == 4) {
                func_020a0dbc();
            }
            p = (Unk0217561c_14 *) ((u8 *) &data_0217561c->mUnk_14[0] + v1);
            p->mUnk_30 &= ~0x20;
        }
        return;
    }
    if ((d->mUnk_044 & 2) != 0) {
        if (func_0207a574() != 0) {
            g = TRUE;
        }
    }
    if (g == FALSE) {
        if ((data_021759c0->mUnk_044 & 4) != 0) {
            if (func_0207a538() != 0) {
                k = 3;
                g = TRUE;
            }
        }
    }
    if (g == FALSE) {
        if ((data_021759c0->mUnk_044 & 8) != 0) {
            if (func_0207a4fc() != 0) {
                g = TRUE;
            }
        }
    }
    if (g == FALSE) {
        if (func_0205e1c4() != 0) {
            k = 4;
            g = TRUE;
        }
    }
    if (g == FALSE) {
        return;
    }
    func_0203e788((u16) data_021759c0->mUnk_62, k);
}

// non-matching: the original (0xc4 bytes) reloads the byte at 0x3d0 through the same pointer register on every
// iteration and keeps the counter and index in r4 and r5; ours (0xb8 bytes) holds the byte in a register across the
// loop
s32 func_0203cfb4(void) {
    BOOL r = TRUE;
    Unk0217561c *d = data_0217561c;
    Unk021759c0 *e;
    if (d->mUnk_4cc != 0) {
        return 0;
    }
    e = data_021759c0;
    if (e->mUnk_08 == 2) {
        s32 c = 0;
        u32 i;
        for (i = 0; i < e->mUnk_3d0; i = (u16) (i + 1)) {
            if (d->mUnk_000[i].mUnk_14 == 0) {
                c++;
                if (c > 0) {
                    return 0;
                }
            }
        }
        return r;
    }
    return 0;
}

void func_0203d078(void) {
    u32 i;
    if (func_020a128c() != 0) {
        for (i = 0; i < data_021759c0->mUnk_3d0; i = (u16) (i + 1)) {
            Unk0217561c_14 *p = (Unk0217561c_14 *) ((u8 *) &data_0217561c->mUnk_14[0] + i * 0x8c);
            if (p->mUnk_00 == 0) {
                if (func_020a100c(i) != 0) {
                    p->mUnk_00 = 1;
                } else {
                    p->mUnk_00 = 2;
                }
                p->mUnk_30 |= 2;
            }
        }
        return;
    }
    for (i = 0; i < data_021759c0->mUnk_3d0; i = (u16) (i + 1)) {
        if (func_020a1084(i) != 0) {
            Unk0217561c_14 *p = (Unk0217561c_14 *) ((u8 *) &data_0217561c->mUnk_14[0] + i * 0x8c);
            if (p->mUnk_00 == 0) {
                if (func_020a100c(i) != 0) {
                    p->mUnk_00 = 1;
                } else {
                    p->mUnk_00 = 2;
                }
                p->mUnk_30 |= 2;
            }
        }
    }
    if (func_0203ef58() != 0) {
        switch (data_021759c0->mUnk_08) {
            case 1:
                break;
            case 2:
                func_020a12b8();
                break;
            case 4:
                func_0203eb38();
                break;
            case 5:
                func_0203ecf0();
                break;
            default:
                func_0203ee28();
                break;
        }
    }
}

// non-matching: registers only, in the first loop of case 2: the counter b is in r2 (original r0) and the
// data_0217561c base and the 0x3d0 count byte are in r0 (original r2)
void func_0203d21c(void) {
    u32 b;
    s32 v = -1;
    Unk021759c0 *d = data_021759c0;
    s32 m = d->mUnk_08;
    u32 a;
    BOOL f = FALSE;
    switch (m) {
        case 2:
        case 3:
            if (d->mUnk_58 != 0) {
                f = TRUE;
            }
            break;
    }
    switch (m) {
        case 0:
        case 3:
        case 5: {
            for (a = 0; a < d->mUnk_3d0; a = (u16) (a + 1)) {
                u32 t;
                u8 w;
                u32 z = 0;
                if (d->mUnk_08 == 5) {
                    t = data_0217aa14->mUnk_104[data_0217aa18->mUnk_00[a & 0xff]].mUnk_86_1;
                } else {
                    t = data_0217561c->mUnk_14[a].mUnk_3c_0;
                }
                w = t;
                if (data_0217561c->mUnk_000[a].mUnk_14 != 4) {
                    z = func_0203c4d0(w);
                }
                func_0205d9d4(a, w, z);
                func_0205d818(a, &data_0217561c->mUnk_14[a].mUnk_0c[5]);
                if (data_021759c0->mUnk_08 == 5) {
                    if (data_0217561c->mUnk_000[a].mUnk_14 == 4) {
                        func_0205d974(a);
                    }
                }
                if (f != FALSE) {
                    if (w == 1) {
                        v = data_021759c0->mUnk_68[a].mUnk_08.mUnk_04;
                    }
                }
                d = data_021759c0;
            }
            break;
        }
        case 2: {
            s32 e;
            if (f != FALSE) {
                for (b = 0; b < d->mUnk_3d0; b = (u16) (b + 1)) {
                    if (data_0217561c->mUnk_000[b].mUnk_14 == 1) {
                        if (f != FALSE) {
                            if (v == -1) {
                                d = data_021759c0;
                                v = d->mUnk_68[b].mUnk_08.mUnk_04;
                            }
                        }
                    }
                }
            }
            for (a = 0; a < data_021759c0->mUnk_3d0; a = (u16) (a + 1)) {
                data_0217561c->mUnk_000[a].mUnk_44 |= 2;
                if (data_0217561c->mUnk_000[a].mUnk_14 == 1) {
                    if (f != FALSE) {
                        e = v == data_021759c0->mUnk_68[a].mUnk_08.mUnk_04 ? 1 : 0;
                    } else {
                        e = 1;
                    }
                    func_0205d88c(a, 1);
                } else {
                    if (f != FALSE) {
                        e = v == data_021759c0->mUnk_68[a].mUnk_08.mUnk_04 ? 1 : 0;
                    } else {
                        e = 0;
                    }
                    func_0205d88c(a, 0);
                    if (data_0217561c->mUnk_000[a].mUnk_14 == 0) {
                        data_0217561c->mUnk_000[a].mUnk_14 = 2;
                    }
                }
                func_02068640(func_0207a974(a), e);
            }
            func_02110cc8(0);
            break;
        }
    }
    if (f != FALSE) {
        func_0205d558(v);
    }
    data_0217561c->mUnk_4cc = 1;
}
