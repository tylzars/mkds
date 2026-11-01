#include "Main/Unknown/code_02070398.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02061808.h"
#include "Main/Unknown/code_020a1e40.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_02070f8c.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_0208b748.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0212c6ac.h"
#include "code_02146d78.h"
#include "code_02147288.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "code_0212df7c.h"

void func_020705fc(Unk0206bcb0 *p, u32 b) {
    Vec3 a;
    Vec3 e;
    s32 m[9];
    Vec3 v;
    Vec3 w;
    Unk0212c400 **h;
    u16 i;
    s32 k;

    func_020710b0(p, 1);
    p->mUnk_260 = 0x3000;
    i = data_02175620->mUnk_fc[b];
    a.x = data_02175620->mUnk_34[i].mUnk_00.x;
    a.y = data_02175620->mUnk_34[i].mUnk_00.y;
    a.z = data_02175620->mUnk_34[i].mUnk_00.z;
    k = (u16) (((s64) data_02175620->mUnk_34[data_02175620->mUnk_fc[b]].mUnk_0c.y * 0xb60b60b60bLL + 0x80000000LL) >>
               44) >>
        4;
    func_02146d44(m, data_0215d4b4[k * 2], data_0215d4b4[k * 2 + 1]);
    func_02146d78(&data_02154f70, m, &e);
    if (data_021759c0->mUnk_08 == 2) {
        func_021484d0(&a, &p->mUnk_80, &v);
        func_020a21bc(p->mUnk_74, (s32) &v);
    }
    p->mUnk_80 = a;
    p->mUnk_8c = p->mUnk_80;
    p->mUnk_98 = p->mUnk_8c;
    p->mUnk_2a8 = 0x5000;
    p->mUnk_50 = e;
    p->mUnk_68 = p->mUnk_50;
    p->mUnk_236 = (s32) (((s64) func_02148538(e.x, e.z) * 0x28be60dLL) >> 12) >> 12;
    w = data_02165524;
    func_01ffd190(&w, p->mUnk_236, (Vec4 *) &p->mUnk_e0);
    if (p->mUnk_7c & 1) {
        func_02076a5c();
        if (data_0217c780 & 1) {
            h = (Unk0212c400 **) func_0210e128((void *) func_02108ea0(0));
            if (data_0217d084.mUnk_0c != 0) {
                if (h[0] != 0) {
                    func_0212c6f0(h, 0);
                }
                if (h[0] != 0) {
                    func_0212c6f0(h, 0);
                }
                func_0212ecc0(h, 0, 0x159);
            }
        }
    }
    if (!(p->mUnk_7c & 2)) {
        return;
    }
    if (data_021759c0->mUnk_08 != 2) {
        return;
    }
    func_02089754(p->mUnk_310, func_02040da8(b));
}

void func_02070484(Unk0206bcb0 *p, Vec4 *q) {
    Unk02012f58 m1;
    Unk02012f58 m2;
    Vec3 v1;
    Vec3 v2;
    s32 d;
    u16 k;
    u16 t;

    if (p->mUnk_2a4 < 0x1000) {
        return;
    }
    if (func_02039828(&p->mUnk_12c, &data_02154f7c) <= 0) {
        return;
    }
    p->mUnk_234 = p->mUnk_234 + p->mUnk_3e8;
    k = p->mUnk_236;
    t = (u16) p->mUnk_234;
    func_02147250(&m1, data_0215d4b4[(k >> 4) * 2], data_0215d4b4[(k >> 4) * 2 + 1]);
    func_02147288(&data_02154f88, &m1, &v1);
    func_021478f0(&m2, &v1, data_0215d4b4[(t >> 4) * 2], data_0215d4b4[(t >> 4) * 2 + 1]);
    func_02147288(&data_02154f7c, &m2, &v2);
    func_01ffd0e8(q, &data_02154f7c, &v2);
    if (p->mUnk_48 & 0x80000000) {
        q->x = -q->x;
        q->y = -q->y;
        q->z = -q->z;
        q->w = -q->w;
    }
    if (p->mUnk_44 & 2) {
        return;
    }
    d = func_02039828(&p->mUnk_b0, &p->mUnk_138);
    if (d <= 0) {
        d = -d;
    }
    p->mUnk_3f8 = d;
    if (p->mUnk_3f8 < 0xb33) {
        p->mUnk_3f8 = 0xb33;
    }
}

s32 func_02070398(Unk0206bcb0 *p, u32 b, void *c) {
    u32 w;

    w = p->mUnk_44;
    if (!(w & 0xc2200) && !(p->mUnk_7c & 0x400)) {
        if (!(w & 0xc0000) && !(p->mUnk_4c & 0x100) && p->mUnk_1fc.x == 0 && p->mUnk_1fc.y == 0 && p->mUnk_1fc.z == 0 &&
            p->mUnk_274 == 0 && p->mUnk_4d0 >= 0x64) {
            p->mUnk_80.x = p->mUnk_8c.x;
            p->mUnk_80.z = p->mUnk_8c.z;
        } else {
            func_020d5aa0(c, b, (Unk020e04b0 *) p->mUnk_208, &p->mUnk_80, 0);
        }
        p->mUnk_a4 = data_02154f94;
        p->mUnk_2a4 = 0;
        p->mUnk_44 |= 0x1000;
        return 1;
    }
    return 0;
}
