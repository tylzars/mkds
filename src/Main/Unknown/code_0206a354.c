#include "Main/Unknown/code_0206a354.h"
#include "01/code_0218155c.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02063b50.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02074854.h"
#include "Main/Unknown/code_020720dc.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b6b0.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0210a644.h"
#include "Main/Unknown/code_0210a664.h"
#include "Main/Unknown/code_0210f868.h"
#include "Main/Unknown/code_0210fa3c.h"
#include "Main/Unknown/code_0210fa40.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"

void func_0206a354(Unk0206bcb0 *p) {
    Unk0206ceb4 *q = &p->mUnk_538;

    if (q->mUnk_02 <= 0) {
        if (q->mUnk_04 == 0) {
            func_021090c4(&p->mUnk_00, 0xed, 0x7f, 0);
        }
        q->mUnk_04 = q->mUnk_04 + 1;
        if (q->mUnk_04 >= 0x19) {
            p->mUnk_428.x = 0x1000;
            p->mUnk_428.y = 0x1000;
            p->mUnk_428.z = 0x1000;
            p->mUnk_41c.x = 0x1000;
            p->mUnk_41c.y = 0x1000;
            p->mUnk_41c.z = 0x1000;
            p->mUnk_bc.x = (s32) (((s64) p->mUnk_428.x * p->mUnk_41c.x) >> 12);
            p->mUnk_bc.y = (s32) (((s64) p->mUnk_428.y * p->mUnk_41c.y) >> 12);
            p->mUnk_bc.z = (s32) (((s64) p->mUnk_428.z * p->mUnk_41c.z) >> 12);
            p->mUnk_bc.y = (s32) (((s64) p->mUnk_434 * p->mUnk_bc.y) >> 12);
            if (q->mUnk_04 > 0x19) {
                p->mUnk_4c &= ~0x80;
                if (!(p->mUnk_4c & 0x10080)) {
                    p->mUnk_394 = 0x1000;
                }
                if (p->mUnk_74 == data_021759c0->mUnk_62) {
                    func_0210fa74(0);
                }
                func_0210a664(p);
                return;
            }
            p->mUnk_4c |= 0x100;
            return;
        }
        p->mUnk_4c |= 0x100;
        p->mUnk_41c.x = data_usa_02154de4[q->mUnk_04];
        p->mUnk_41c.y = data_usa_02154e48[q->mUnk_04];
        p->mUnk_41c.z = data_usa_02154eac[q->mUnk_04];
        p->mUnk_428.x = 0x1000;
        p->mUnk_428.y = 0x1000;
        p->mUnk_428.z = 0x1000;
        p->mUnk_bc.x = (s32) (((s64) p->mUnk_428.x * p->mUnk_41c.x) >> 12);
        p->mUnk_bc.y = (s32) (((s64) p->mUnk_428.y * p->mUnk_41c.y) >> 12);
        p->mUnk_bc.z = (s32) (((s64) p->mUnk_428.z * p->mUnk_41c.z) >> 12);
        p->mUnk_bc.y = (s32) (((s64) p->mUnk_434 * p->mUnk_bc.y) >> 12);
        return;
    }
    q->mUnk_02 = q->mUnk_02 - 1;
    if (p->mUnk_428.y > 0x800) {
        s32 v = p->mUnk_428.y;

        if (v < 0x800) {
            v += 0x29;
            if (v > 0x800) {
                v = 0x800;
            }
        } else {
            v -= 0x29;
            if (v <= 0x800) {
                v = 0x800;
            }
        }
        p->mUnk_428.y = v;
        p->mUnk_428.z = p->mUnk_428.y;
        p->mUnk_428.x = p->mUnk_428.z;
        p->mUnk_bc.x = (s32) (((s64) p->mUnk_428.x * p->mUnk_41c.x) >> 12);
        p->mUnk_bc.y = (s32) (((s64) p->mUnk_428.y * p->mUnk_41c.y) >> 12);
        p->mUnk_bc.z = (s32) (((s64) p->mUnk_428.z * p->mUnk_41c.z) >> 12);
        p->mUnk_bc.y = (s32) (((s64) p->mUnk_434 * p->mUnk_bc.y) >> 12);
    }
    func_0210fa3c();
}

void func_0206a624(Unk0206bcb0 *p) {
    Unk0206ceb4 *q = &p->mUnk_538;

    if (p->mUnk_4c & 0x10000040) {
        return;
    }
    if (p->mUnk_7c & 0x402000) {
        return;
    }
    if (p->mUnk_48 & 0x10040) {
        return;
    }
    q->mUnk_02 = data_usa_02154a54[func_0203c8dc(p->mUnk_74) - 1];
    q->mUnk_04 = 0;
    p->mUnk_394 = 0xb33;
    p->mUnk_4c |= 0x80;
    func_0206bcb0(p, 2, 1);
    func_0210f9ac(p);
    func_020eff40(&(data_027e00c8)[p->mUnk_74]);
    if (data_021759c0->mUnk_08 == 4 && data_021759c0->mUnk_08 == 4) {
        func_ov001_0218173c();
    }
    p->mUnk_41c.x = 0x1000;
    p->mUnk_41c.y = 0x1000;
    p->mUnk_41c.z = 0x1000;
    func_0210a644(p);
    if (p->mUnk_74 == data_021759c0->mUnk_62) {
        func_0210fa74(1);
    }
    if (p->mUnk_7c & 0x200) {
        p->mUnk_514->mUnk_2c ^= 0x8000;
    }
}

void func_0206a784(Unk0206bcb0 *p) {
    s16 n;

    if (p->mUnk_318 == 0) {
        p->mUnk_260 = data_usa_0216550c;
    } else if (p->mUnk_44 & 0x10000) {
        if (p->mUnk_370 == 0) {
            p->mUnk_260 = data_usa_021654e4;
        }
        p->mUnk_370++;
    }
    if ((p->mUnk_318 > 0 ? p->mUnk_318 : -p->mUnk_318) <= 0x1fffe) {
        p->mUnk_318 = p->mUnk_318 + p->mUnk_360;
        if ((p->mUnk_318 > 0 ? p->mUnk_318 : -p->mUnk_318) > 0x1fffe) {
            p->mUnk_314 = 0;
            p->mUnk_4c &= ~0x1;
        } else {
            p->mUnk_314 = p->mUnk_314 + p->mUnk_360;
        }
        p->mUnk_360 = p->mUnk_360 - (p->mUnk_360 > 0 ? data_usa_021654d0 : -data_usa_021654d0);
        func_01ffd190(&p->mUnk_31c, p->mUnk_314, &p->mUnk_34c);
        func_01ffcf7c(&p->mUnk_34c, &p->mUnk_34c);
        return;
    }
    n = p->mUnk_35c;
    if (n == 0) {
        p->mUnk_48 |= 0x44000;
        p->mUnk_23a = n;
        p->mUnk_4c &= ~0x10;
    }
    p->mUnk_35c++;
    if (p->mUnk_35c < 10) {
        return;
    }
    p->mUnk_180 = 0;
    p->mUnk_4c &= ~0x30;
    p->mUnk_48 &= ~0x20000;
    func_02068a64(p, 0, 1);
    p->mUnk_44 |= 0x80000000;
    if ((p->mUnk_7c & 0x2) && data_021759c0->mUnk_08 == 2 && data_021759c0->mUnk_18 == 0) {
        func_02088c7c(p->mUnk_310);
    }
    if (p->mUnk_44 & 0x10) {
        p->mUnk_388 = 0;
    }
}

s32 func_0206a980(Unk0206bcb0 *p, const Vec3 *a, s32 b) {
    Vec3 v;
    Vec3 w;
    s32 r;
    s32 x;
    s32 y;
    s32 z;

    func_0206bf88(p, 5);
    v = *a;
    v.y = 0;
    if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 16) {
        r = func_02039860(&v, &v);
    } else {
        r = 0;
    }
    if (r == 0) {
        v = data_02154f88;
    }
    p->mUnk_4c |= 0x10;
    p->mUnk_314 = 0;
    p->mUnk_318 = 0;
    p->mUnk_360 = data_usa_021654e0;
    p->mUnk_370 = 0;
    p->mUnk_35c = 0;
    w = data_02154f7c;
    func_020397a8(&w, &v, &p->mUnk_31c);
    if (!(p->mUnk_7c & 0x400)) {
        x = (s32) (((s64) v.x << 14) >> 12);
        y = (s32) (((s64) v.y << 14) >> 12);
        z = (s32) (((s64) v.z << 14) >> 12);
        p->mUnk_2d8.x += x;
        p->mUnk_2d8.z += z;
        p->mUnk_260 += y;
        r = func_02039828(&p->mUnk_50, &v);
        if (r <= 0) {
            p->mUnk_2a8 = 0;
        } else {
            p->mUnk_2a8 = (s32) (((s64) p->mUnk_2a8 * r) >> 12) >> 2;
        }
    }
    func_01ffd190(&p->mUnk_31c, p->mUnk_314, &p->mUnk_34c);
    func_020eff40(&(data_027e00c8)[p->mUnk_74]);
    if (data_021759c0->mUnk_08 == 4 && data_021759c0->mUnk_08 == 4) {
        func_ov001_0218173c();
    }
    if (p->mUnk_590->mUnk_058 == 0) {
        func_0208b7bc(0xc, &p->mUnk_80);
        func_0208b7bc(0xd, &p->mUnk_80);
        func_0208b7bc(0xe, &p->mUnk_80);
    }
    if (!(p->mUnk_48 & 0x840)) {
        func_0210af40(p, p->mUnk_3cc, 2);
    }
    p->mUnk_4c |= 0x1;
    if (b != 0) {
        if (p->mUnk_7c & 0x200) {
            p->mUnk_514->mUnk_2c ^= 0x40;
        }
        if (p->mUnk_7c & 0x200) {
            p->mUnk_514->mUnk_98 = *a;
            p->mUnk_514->mUnk_a4 = 5;
        }
    }
    return 1;
}

void func_0206ac10(Unk0206bcb0 *p) {
    s16 n;

    if (p->mUnk_318 == 0) {
        p->mUnk_260 = data_usa_0216550c;
    }
    if ((p->mUnk_318 > 0 ? p->mUnk_318 : -p->mUnk_318) <= 0xffff) {
        p->mUnk_318 = p->mUnk_318 + p->mUnk_360;
        if ((p->mUnk_318 > 0 ? p->mUnk_318 : -p->mUnk_318) > 0xffff) {
            p->mUnk_314 = 0;
            p->mUnk_4c &= ~0x1;
        } else {
            p->mUnk_314 = p->mUnk_314 + p->mUnk_360;
        }
        p->mUnk_360 = p->mUnk_360 - (p->mUnk_360 > 0 ? data_usa_021654d0 : -data_usa_021654d0);
        func_01ffd190(&p->mUnk_31c, p->mUnk_314, &p->mUnk_34c);
        func_01ffcf7c(&p->mUnk_34c, &p->mUnk_34c);
        return;
    }
    n = p->mUnk_35c;
    if (n == 0) {
        p->mUnk_48 |= 0x44000;
        p->mUnk_23a = n;
        p->mUnk_4c &= ~0x10;
    }
    p->mUnk_35c++;
    if (p->mUnk_35c < 0x1e) {
        return;
    }
    p->mUnk_180 = 0;
    p->mUnk_4c &= ~0x30;
    p->mUnk_48 &= ~0x20000;
    func_02068a64(p, 0, 1);
    p->mUnk_44 |= 0x80000000;
    if ((p->mUnk_7c & 0x2) && data_021759c0->mUnk_08 == 2 && data_021759c0->mUnk_18 == 0) {
        func_02088c7c(p->mUnk_310);
    }
    if (p->mUnk_44 & 0x10) {
        p->mUnk_388 = 0;
    }
}

void func_0206add0(Unk0206bcb0 *p, const Vec3 *a, s32 b) {
    Vec3 v;
    s32 r;
    s32 x;
    s32 y;
    s32 z;

    func_0206bf88(p, 4);
    p->mUnk_4c |= 0x10;
    p->mUnk_314 = 0;
    p->mUnk_318 = 0;
    p->mUnk_360 = data_usa_021654d4;
    p->mUnk_370 = 0;
    p->mUnk_35c = 0;
    v = data_02154f7c;
    func_020397a8(&v, a, &p->mUnk_31c);
    func_020eff40(&(data_027e00c8)[p->mUnk_74]);
    if (data_021759c0->mUnk_08 == 4 && data_021759c0->mUnk_08 == 4) {
        func_ov001_0218173c();
    }
    if (!(p->mUnk_7c & 0x400)) {
        x = (s32) (((s64) a->x * 0x1b33) >> 12);
        y = (s32) (((s64) a->y * 0x1b33) >> 12);
        z = (s32) (((s64) a->z * 0x1b33) >> 12);
        p->mUnk_2d8.x += x;
        p->mUnk_2d8.z += z;
        p->mUnk_260 += y;
        r = func_02039828(&p->mUnk_50, a);
        if (r <= 0) {
            p->mUnk_2a8 = 0;
        } else {
            p->mUnk_2a8 = (s32) (((s64) p->mUnk_2a8 * r) >> 12) >> 2;
        }
    }
    func_01ffd190(&p->mUnk_31c, p->mUnk_314, &p->mUnk_34c);
    if (p->mUnk_590->mUnk_058 == 0) {
        func_0208b7bc(0xc, &p->mUnk_80);
        func_0208b7bc(0xd, &p->mUnk_80);
        func_0208b7bc(0xe, &p->mUnk_80);
    }
    p->mUnk_4c |= 0x1;
    if (!(p->mUnk_48 & 0x840)) {
        func_0210af40(p, p->mUnk_3cc, 2);
    }
    if (b == 0) {
        return;
    }
    if (p->mUnk_7c & 0x200) {
        p->mUnk_514->mUnk_2c ^= 0x20;
    }
    if (p->mUnk_7c & 0x200) {
        p->mUnk_514->mUnk_98 = *a;
        p->mUnk_514->mUnk_a4 = 4;
    }
}

BOOL func_0206b020(Unk0206bcb0 *p, Unk0206b020 *a) {
    Vec3 t;
    Vec3 u;
    Vec3 w;
    BOOL v1;
    BOOL v2;
    BOOL c;
    int v;
    u32 f = p->mUnk_4c;

    if (f & 0x400000) {
        v1 = FALSE;
    } else if (p->mUnk_7c & 0x200) {
        if (p->mUnk_180 == 0 && !(p->mUnk_48 & 0x1800) && !(f & 0x10000040)) {
            v1 = TRUE;
        } else {
            v1 = FALSE;
        }
    } else {
        v2 = TRUE;
        if (!(f & 0x10000040) && !(p->mUnk_48 & 0x1800)) {
            v = p->mUnk_180;
            c = FALSE;
            if (v != 0 && v != 1 && v != 2) {
                c = TRUE;
            }
            if (c == FALSE) {
                v2 = FALSE;
            }
        }
        v1 = v2 == FALSE;
    }
    if (!v1) {
        return FALSE;
    }
    t = a->mUnk_28;
    func_021484d0(&p->mUnk_80, &a->mUnk_04, &u);
    func_021483a0(&a->mUnk_40, &u, &w);
    if (func_0214848c(&w, &a->mUnk_34) < 0) {
        t.x = -t.x;
        t.y = -t.y;
        t.z = -t.z;
    }
    func_0206add0(p, &t, 0);
    return TRUE;
}

void func_0206b16c(Unk0206bcb0 *p) {
    s16 n;

    if (p->mUnk_318 == 0) {
        p->mUnk_260 = data_usa_021654e8;
    } else if (p->mUnk_44 & 0x10000) {
        switch (p->mUnk_370) {
            case 0:
                p->mUnk_260 = data_usa_021654f0;
                break;
            case 1:
                p->mUnk_260 = data_usa_02165508;
                break;
        }
        p->mUnk_370++;
    }
    if ((p->mUnk_318 > 0 ? p->mUnk_318 : -p->mUnk_318) <= 0xffff) {
        p->mUnk_318 = p->mUnk_318 + p->mUnk_360;
        if ((p->mUnk_318 > 0 ? p->mUnk_318 : -p->mUnk_318) > 0xffff) {
            p->mUnk_314 = 0;
        } else {
            p->mUnk_314 = p->mUnk_314 + p->mUnk_360;
        }
        p->mUnk_360 = p->mUnk_360 - 0xa;
        func_01ffd190(&p->mUnk_31c, p->mUnk_314, &p->mUnk_34c);
        func_01ffcf7c(&p->mUnk_34c, &p->mUnk_34c);
        return;
    }
    n = p->mUnk_35c;
    if (n == 0) {
        p->mUnk_48 |= 0x44000;
        p->mUnk_23a = n;
        p->mUnk_4c &= ~0x10;
    }
    p->mUnk_35c++;
    if (p->mUnk_35c < data_usa_021654c4) {
        return;
    }
    p->mUnk_180 = 0;
    p->mUnk_4c &= ~0x30;
    p->mUnk_48 &= ~0x20000;
    func_02068a64(p, 0, 1);
    p->mUnk_44 |= 0x80000000;
    if ((p->mUnk_7c & 0x2) && data_021759c0->mUnk_08 == 2 && data_021759c0->mUnk_18 == 0) {
        func_02088c7c(p->mUnk_310);
    }
}

void func_0206b358(Unk0206bcb0 *p) {
    Vec3 v;

    func_0206bf88(p, 3);
    p->mUnk_4c |= 0x10;
    p->mUnk_314 = 0;
    p->mUnk_360 = 0x666;
    p->mUnk_370 = 0;
    p->mUnk_35c = 0;
    p->mUnk_318 = 0;
    p->mUnk_2a8 = p->mUnk_2a8 + 0x800;
    func_02063b50((u32) p, (u32) &p->mUnk_31c);
    func_02063b10(p, &v);
    func_02147fd8(0x2e2, &v, &p->mUnk_31c, &p->mUnk_31c);
    func_02039860(&p->mUnk_31c, &p->mUnk_31c);
    func_01ffd190(&p->mUnk_31c, p->mUnk_314, &p->mUnk_34c);
    p->mUnk_2a8 = (s32) (((s64) p->mUnk_2a8 * 0x99a) >> 12);
    if (p->mUnk_590->mUnk_058 == 0) {
        func_0208b7bc(0xc, &p->mUnk_80);
        func_0208b7bc(0xd, &p->mUnk_80);
        func_0208b7bc(0xe, &p->mUnk_80);
    }
    if (!(p->mUnk_48 & 0x840)) {
        func_0210af40(p, p->mUnk_3cc, 2);
    }
    func_020efea4(&(data_027e00c8)[p->mUnk_74]);
    if (data_021759c0->mUnk_08 == 4 && data_021759c0->mUnk_08 == 4) {
        func_ov001_0218173c();
    }
}

BOOL func_0206b4d0(Unk0206bcb0 *p) {
    BOOL v1;
    BOOL v2;
    BOOL c;
    int v;
    u32 f = p->mUnk_4c;

    if (f & 0x400000) {
        v1 = FALSE;
    } else if (p->mUnk_7c & 0x200) {
        if (p->mUnk_180 == 0 && !(p->mUnk_48 & 0x1800) && !(f & 0x10000040)) {
            v1 = TRUE;
        } else {
            v1 = FALSE;
        }
    } else {
        v2 = TRUE;
        if (!(f & 0x10000040) && !(p->mUnk_48 & 0x1800)) {
            v = p->mUnk_180;
            c = FALSE;
            if (v != 0 && v != 1 && v != 2) {
                c = TRUE;
            }
            if (c == FALSE) {
                v2 = FALSE;
            }
        }
        v1 = v2 == FALSE;
    }
    if (!v1) {
        return FALSE;
    }
    func_0206b358(p);
    if (p->mUnk_7c & 0x200) {
        p->mUnk_514->mUnk_2c ^= 0x10;
    }
    return TRUE;
}

void func_0206b5b4(Unk0206bcb0 *p) {
    Vec3 a;
    s32 c;
    u16 i;

    if (p->mUnk_35c == 0) {
        Unk02146dfc m;

        p->mUnk_2a8 = 0;
        if ((p->mUnk_318 > 0 ? p->mUnk_318 : -p->mUnk_318) < 0x1ffff) {
            p->mUnk_314 = p->mUnk_314 - p->mUnk_360;
            p->mUnk_318 = p->mUnk_318 + p->mUnk_360;
            c = p->mUnk_360;
            if (c <= 0xc8) {
                p->mUnk_360 = 0xc8;
            } else {
                p->mUnk_360 = (s32) (((s64) c * 0xf85) >> 12);
            }
        } else {
            p->mUnk_314 = 0;
        }
        if (p->mUnk_44 & 0x10000) {
            if (p->mUnk_318 < 0x13000) {
                p->mUnk_260 += 0x1800;
            }
        }
        if ((p->mUnk_33c > 0 ? p->mUnk_33c : -p->mUnk_33c) >= 0xffff) {
            p->mUnk_338 = 0;
            p->mUnk_334 = 0;
        } else {
            p->mUnk_338 += 0x3e8;
            p->mUnk_33c += 0x3e8;
            p->mUnk_334 = data_0215d4b4[(p->mUnk_338 >> 4) * 2];
        }
        i = (u16) (((s64) p->mUnk_334 * 0xce4) >> 12);
        func_02146f98((Unk02012f58 *) &m, &p->mUnk_328, data_0215d4b4[(i >> 4) * 2], data_0215d4b4[(i >> 4) * 2 + 1]);
        func_02146d78(&p->mUnk_31c, m.mUnk_00, &a);
        func_01ffd190(&a, p->mUnk_314, &p->mUnk_34c);
    } else {
        Vec4 q;

        q = data_usa_0216556c;
        func_01ffce48(&p->mUnk_34c, &q, &p->mUnk_34c, 0x266);
    }
    func_01ffcf7c(&p->mUnk_34c, &p->mUnk_34c);
    if (!(p->mUnk_4c & 0x80000000)) {
        if ((u32) p->mUnk_348 > 2 && (p->mUnk_340 >= p->mUnk_80.y || (p->mUnk_44 & 0x10))) {
            if (p->mUnk_7c & 0x1) {
                func_020747f4(0);
            }
            if (p->mUnk_35c != 0) {
                return;
            }
            p->mUnk_4d0 = 0x46;
            c = p->mUnk_35c;
            p->mUnk_48 |= 0x44000;
            p->mUnk_23a = c;
            p->mUnk_4c |= 0x80000000;
            return;
        }
        p->mUnk_348 = p->mUnk_348 + 1;
        return;
    }
    p->mUnk_35c++;
    if (p->mUnk_35c < 0x1e) {
        return;
    }
    p->mUnk_180 = 0;
    p->mUnk_4c &= ~0x30;
    p->mUnk_48 &= ~0x20000;
    func_02068a64(p, 0, 1);
    p->mUnk_44 |= 0x80000000;
    if ((p->mUnk_7c & 0x2) && data_021759c0->mUnk_08 == 2 && data_021759c0->mUnk_18 == 0) {
        func_02088c7c(p->mUnk_310);
    }
    p->mUnk_4c &= ~0x80000010;
    if (p->mUnk_44 & 0x10) {
        p->mUnk_388 = 0;
    }
}

void func_0206b914(Unk0206bcb0 *p) {
    p->mUnk_2a8 = 0;
    p->mUnk_388 = 0;
    p->mUnk_48 &= 0xdfe77fdf;
    p->mUnk_238 = 0;
    p->mUnk_538.mUnk_00 = 0;
    p->mUnk_23c = 0;
    if (p->mUnk_7c & 0x1) {
        if (!(p->mUnk_4c & 0x10000000) && !(p->mUnk_48 & 0x4000000)) {
            func_02074854();
        }
        func_02055c5c();
    }
    if (p->mUnk_4c & 0x2000) {
        p->mUnk_4c &= ~0x2000;
        p->mUnk_d8 = 0x1000;
        if (!(p->mUnk_4c & 0x8000000)) {
            func_0207b0d0(p);
        }
        func_02080ee4(p);
    }
    p->mUnk_180 = 6;
    p->mUnk_4c |= 0x10;
    p->mUnk_260 = 0x6000;
    p->mUnk_318 = 0;
    p->mUnk_314 = 0;
    p->mUnk_360 = 0xfa0;
    p->mUnk_35c = 0;
    func_02063b50((u32) p, (u32) &p->mUnk_31c);
    func_02063b10(p, &p->mUnk_328);
    p->mUnk_334 = 0;
    p->mUnk_338 = 0;
    p->mUnk_33c = 0;
    p->mUnk_344 = 0;
    p->mUnk_340 = p->mUnk_80.y;
    p->mUnk_348 = 0;
    func_020eff40(&(data_027e00c8)[p->mUnk_74]);
    if (data_021759c0->mUnk_08 == 4 && data_021759c0->mUnk_08 == 4) {
        func_ov001_0218173c();
    }
    if (!(p->mUnk_48 & 0x840)) {
        func_0210af40(p, p->mUnk_3cc, 2);
    }
    p->mUnk_4c &= ~0x80000000;
    if (p->mUnk_7c & 0x1) {
        func_020747f4(1);
    }
}

BOOL func_0206bab8(Unk0206bcb0 *p) {
    if (!func_0206be54(p, 6)) {
        return FALSE;
    }
    func_0206b914(p);
    if (p->mUnk_7c & 0x200) {
        p->mUnk_514->mUnk_2c ^= 0x20000;
    }
    return TRUE;
}

void func_0206bb04(Unk0206bcb0 *p) {
    if (p->mUnk_4c & 0x20) {
        return;
    }
    p->mUnk_48 |= 0x44000;
    p->mUnk_23a = 0xa;
    p->mUnk_180 = 0;
    p->mUnk_4c &= ~0x30;
    p->mUnk_48 &= ~0x20000;
    func_02068a64(p, 0, 1);
    p->mUnk_44 |= 0x80000000;
    if ((p->mUnk_7c & 0x2) && data_021759c0->mUnk_08 == 2 && data_021759c0->mUnk_18 == 0) {
        func_02088c7c(p->mUnk_310);
    }
}

void func_0206bbb4(Unk0206bcb0 *p, int a, int b) {
    int d = 1;

    func_0206bf88(p, 2);
    if (p->mUnk_44 & 0xa) {
        if (p->mUnk_2c4 == 1) {
            d = -1;
        }
    } else if (p->mUnk_2d4 < 0) {
        d = -1;
    }
    p->mUnk_36c = 0x750;
    p->mUnk_36c = p->mUnk_36c * d;
    p->mUnk_364 = 0;
    p->mUnk_368 = 0;
    p->mUnk_366 = a;
    p->mUnk_4c |= 0x20;
    func_020efea4(&(data_027e00c8)[p->mUnk_74]);
    if (data_021759c0->mUnk_08 == 4 && data_021759c0->mUnk_08 == 4) {
        func_ov001_0218173c();
    }
    if (b != 0) {
        return;
    }
    if (p->mUnk_48 & 0x840) {
        return;
    }
    func_0210af40(p, p->mUnk_3cc, 1);
}
