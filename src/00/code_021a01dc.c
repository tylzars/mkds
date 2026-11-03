#include "00/code_0219dabc.h"
#include "00/code_0219e134.h"
#include "00/code_0219e4e8.h"
#include "00/code_0219eaf4.h"
#include "00/code_0219fb48.h"
#include "00/code_021a01dc.h"
#include "00/code_0218d000.h"
#include "00/code_021a0958.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_0218dc44.h"
#include "00/code_0218cdc4.h"
#include "00/code_0218b434.h"
#include "00/code_0219887c.h"
#include "00/code_0219de4c.h"
#include "00/code_0218eb9c.h"
#include "00/unk_021b5000.h"
#include "00/code_021a0000.h"
#include "00/code_0219f4c4.h"
#include "00/code_0219f9bc.h"
#include "00/unk_021b4000.h"
#include "00/code_021a4784.h"
#include "code_0200f5ac.h"

s32 func_ov000_021a01dc(s32 a, u32 b, u32 c, u16 d, u32 *e, s32 f) {
    u32 *w;
    u32 z;
    Unk021a01dc s;
    u32 g[0x41];
    s32 i;
    s32 t;
    u16 y;
    s32 x;
    u32 u;
    u8 v;
    Unk021b566c *o;
    Unk021b566c *p;
    Unk021b5670 *q;
    u32 *n;

    i = 0;
    o = data_ov000_021b566c;
    if (o == NULL || o->mUnk_198 == 0) {
        return 1;
    }
    switch (a) {
        case 1:
        case 11:
            t = func_ov000_021a0064(b, e[0], a == 11 ? 1 : 0);
            if (t == 2) {
                if (data_ov000_021b566c->mUnk_15 != 0) {
                    c = e[1];
                    d = (u16) e[2];
                }
                if (func_ov000_0219fee4(func_ov000_0219ff54(b, c, d)) != 0) {
                    return 0;
                }
                p = data_ov000_021b566c;
                if (p->mUnk_15 == 2 && p->mUnk_454 != NULL) {
                    data_ov000_021b566c->mUnk_454(func_ov000_0219d5e4(b), p->mUnk_458);
                }
                g[0] = data_ov000_021b566c->mUnk_14;
                for (i = 1; i <= data_ov000_021b566c->mUnk_14; i++) {
                    g[i] = data_ov000_021b566c->mUnk_f4[i];
                }
                p = data_ov000_021b566c;
                g[i++] = (u32) p->mUnk_1c;
                g[i++] = p->mUnk_1a;
                p->mUnk_198 = 11;
            }
            if (t == 0xff) {
                break;
            }
            if (func_ov000_0219fee4(func_ov000_021a0ae8(t, b, c, d, (void *) g, i)) == 0) {
                break;
            }
            return 0;
        case 2:
            if (o->mUnk_198 != 4) {
                break;
            }
            if (b != o->mUnk_1ec) {
                break;
            }
            o->mUnk_1f0 = 0;
            data_ov000_021b566c->mUnk_19f = 0;
            data_ov000_021b566c->mUnk_1bc = 0;
            data_ov000_021b566c->mUnk_1b0 = 0;
            data_ov000_021b566c->mUnk_24[0] = (e + e[0])[1];
            data_ov000_021b566c->mUnk_a4[0] = (e + e[0])[2];
            data_ov000_021b566c->mUnk_1ac = (e + e[0])[1];
            data_ov000_021b566c->mUnk_1aa = (e + e[0])[2];
            if (data_ov000_021b566c->mUnk_15 == 1) {
                if (func_ov000_0219f4c4(e + 1, e[0]) != 0) {
                    if (data_ov000_021b566c->mUnk_0d != 0) {
                        func_ov000_0219ff0c(b, e);
                    }
                } else {
                    if (func_ov000_0219fee4(func_ov000_0219fb14(b)) != 0) {
                        return 0;
                    }
                    if (func_ov000_0219fee4(func_ov000_0219fbec(0, 0)) == 0) {
                        break;
                    }
                    return 0;
                }
            }
            if (data_ov000_021b566c->mUnk_15 == 0) {
                if (data_ov000_021b566c->mUnk_0d != 0) {
                    func_ov000_0219ff0c(b, e);
                    if (func_ov000_0219fee4(func_ov000_0219f8b0()) != 0) {
                        return 0;
                    }
                }
                data_ov000_021b566c->mUnk_198 = 6;
                if (func_ov000_0219e4a0(
                        func_ov000_021a0cac(0, 0, func_ov000_0218b480((u32) data_ov000_021b566c->mUnk_e4, 0))) == 0) {
                    break;
                }
                return 0;
            } else {
                data_ov000_021b566c->mUnk_198 = 5;
                if (func_ov000_0219e594(func_ov000_021a0f20(b)) == 0) {
                    break;
                }
                return 0;
            }
        case 3:
            if (o->mUnk_198 != 4) {
                break;
            }
            if (b != o->mUnk_1ec) {
                break;
            }
            return func_ov000_0219fb48();
        case 4:
            if (o->mUnk_198 != 4) {
                break;
            }
            if (b != o->mUnk_1ec) {
                break;
            }
            o->mUnk_1c0 = func_0200f5ac();
            if ((o->mUnk_1f0 != 0 && o->mUnk_19f < 0x10) || o->mUnk_15 == 3) {
                o->mUnk_1b0 = 1;
                p = data_ov000_021b566c;
                p->mUnk_1b4 = func_0200f5ac();
                if (p->mUnk_15 == 3) {
                    break;
                }
                p->mUnk_19f++;
                break;
            }
            o->mUnk_1f0 = 0;
            data_ov000_021b566c->mUnk_19f = 0;
            p = data_ov000_021b566c;
            if (p->mUnk_15 == 0) {
                p->mUnk_198 = 3;
                data_ov000_021b566c->mUnk_e8 = 1;
                data_ov000_021b566c->mUnk_ec = func_0200f5ac();
            } else if (p->mUnk_15 == 1) {
                func_ov000_0219fbec(1, 0);
            }
            break;
        case 5:
            if (o->mUnk_17 == 0) {
                break;
            }
            if (b != o->mUnk_20) {
                break;
            }
            if (o->mUnk_15 == 2 && o->mUnk_0d == 1 && o->mUnk_f4[1] == b) {
                func_ov000_021988e8(*o->mUnk_04);
            }
            if (func_ov000_0219f9bc(b) == 0) {
                return 0;
            }
            break;
        case 6:
            x = e[0];
            y = e[1];
            if (o->mUnk_198 == 1) {
                o->mUnk_198 = 6;
            } else {
                if (o->mUnk_198 != 6 && o->mUnk_198 != 11) {
                    break;
                }
                if (b != o->mUnk_20) {
                    break;
                }
            }
            data_ov000_021b566c->mUnk_3b4 = 0xff;
            p = data_ov000_021b566c;
            n = &p->mUnk_f4[p->mUnk_0d + 1];
            if (b != *n) {
                *n = b;
            }
            s.mUnk_04 = x;
            s.mUnk_02 = ((y >> 8) & 0xff) | ((y << 8) & 0xff00);
            data_ov000_021b566c->mUnk_18c[0] = 1;
            p = data_ov000_021b566c;
            func_ov000_0219db18(0, GetSocketDescriptor(*p->mUnk_04), (s32) &s, p->mUnk_18c);
            data_ov000_021b566c->mUnk_184 = 0;
            break;
        case 7:
            z = e[0];
            u = e[1];
            o->mUnk_f4[o->mUnk_14 + 1] = z;
            data_ov000_021b566c->mUnk_2b8[data_ov000_021b566c->mUnk_14 + 1] = u;
            func_ov000_021a4818(data_ov000_021b566c->mUnk_10);
            p = data_ov000_021b566c;
            if (p->mUnk_454 == NULL) {
                break;
            }
            data_ov000_021b566c->mUnk_454(func_ov000_0219d5e4(z), p->mUnk_458);
            break;
        case 8:
            x = e[0];
            z = x;
            if (x == 0) {
                u = e[1];
                o->mUnk_2b8[u] = e[2];
                data_ov000_021b566c->mUnk_f4[u] = data_ov000_021b566c->mUnk_1e8;
                func_ov000_0219f544(3);
                break;
            }
            u = e[1];
            v = e[2];
            w = &o->mUnk_f4[u];
            if (x == *w && u == o->mUnk_0d - 1) {
                if (func_ov000_0219fee4(func_ov000_021a0ae8(9, b, o->mUnk_24[0], o->mUnk_a4[0], &z, 1)) == 0) {
                    break;
                }
                return 0;
            }
            *w = x;
            data_ov000_021b566c->mUnk_2b8[u] = v;
            data_ov000_021b566c->mUnk_24[u] = e[3];
            data_ov000_021b566c->mUnk_a4[u] = e[4];
            data_ov000_021b566c->mUnk_1ac = e[3];
            data_ov000_021b566c->mUnk_1aa = e[4];
            data_ov000_021b566c->mUnk_198 = 5;
            if (func_ov000_0219e594(func_ov000_021a0f20(z)) != 0) {
                return 0;
            }
            data_ov000_021b566c->mUnk_1bc = 0;
            data_ov000_021b566c->mUnk_1b0 = 0;
            break;
        case 9:
            if (o->mUnk_198 != 13) {
                break;
            }
            if (e[0] != o->mUnk_f4[o->mUnk_19c + 1]) {
                break;
            }
            o->mUnk_19c++;
            func_ov000_0219f544(0);
            break;
        case 10:
            if (o->mUnk_15 == 0 || func_ov000_0219f4c4(e + 1, e[0]) != 0) {
                data_ov000_021b566c->mUnk_1f0 = e[1];
                data_ov000_021b566c->mUnk_19f = 0;
            } else {
                data_ov000_021b566c->mUnk_1f0 = 0;
            }
            p = data_ov000_021b566c;
            if (p->mUnk_0d != 0) {
                func_ov000_021988e8(*p->mUnk_04);
                break;
            }
            if (func_ov000_0219f184() == 0) {
                break;
            }
            return 0;
        case 12:
            if (o->mUnk_15 == 0 || o->mUnk_15 == 1) {
                if (func_ov000_0219f938(b) != 0) {
                    break;
                }
                return 0;
            }
            if (o->mUnk_15 == 3) {
                if (e[0] == 0) {
                    o->mUnk_1f4 = b;
                    func_ov000_0219f0f4();
                    func_ov000_0219f23c(0);
                } else {
                    func_ov000_0219f124(e[0]);
                }
            }
            break;
        case 13:
        case 14:
        case 15:
            if (func_ov000_0219ec44(b, a, e[0]) != 0) {
                break;
            }
            return 0;
        case 16:
            if (b != o->mUnk_f4[0]) {
                return 1;
            }
            for (i = 0; i < f; i++) {
                t = func_ov000_0219e948(e[i], 0);
                if (t != 0xff) {
                    func_ov000_0219bbac(t);
                }
            }
            break;
        case 17:
            q = data_ov000_021b5670;
            if (q != NULL && q->mUnk_00 != 0 && func_ov000_021a350c() - q->mUnk_10 >= q->mUnk_04) {
                g[0] = 1;
            } else {
                g[0] = 0;
            }
            if (func_ov000_0219fee4(func_ov000_021a0ae8(0x12, b, c, d, (void *) g, 1)) == 0) {
                break;
            }
            return 0;
        case 18:
            if (o->mUnk_198 != 0x13) {
                break;
            }
            t = func_ov000_0219e948(b, 0);
            if (t == 0xff) {
                break;
            }
            data_ov000_021b5670->mUnk_08 |= 1 << t;
            if (e[0] != 0) {
                data_ov000_021b5670->mUnk_0c |= 1 << t;
            }
            break;
        case 19:
            func_ov000_021a1a38(10, -80000);
            return 0;
    }
    return 1;
}
