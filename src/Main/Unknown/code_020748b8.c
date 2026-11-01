#include "Main/Unknown/code_020748b8.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_02076000.h"
#include "Main/Unknown/code_020b502c.h"
#include "code_02147cd8.h"

void func_020749a4(Unk02061808 *p, s32 a) {
    Unk020748b8_218 *q = p->mUnk_218;
    u16 n = data_02175620->mUnk_08[q->mUnk_40].mUnk_02;
    Unk02042044 *e0;
    Unk02042044 *e1;
    Vec3 v;
    Vec3 d;
    Vec3 s;
    s32 m;

    if (n >= 4) {
        func_0207bc9c(&p->mUnk_024, &p->mUnk_194, q, a);
        return;
    }
    if (n < 2) {
        return;
    }
    e0 = func_02042044(q->mUnk_40, 0);
    e1 = func_02042044(q->mUnk_40, 1);
    v = e0->mUnk_00;
    func_021484d0(&e1->mUnk_00, &e0->mUnk_00, &d);
    if ((s64) d.x * d.x + (s64) d.y * d.y + (s64) d.z * d.z < 0x10) {
        m = 0;
    } else {
        m = func_02039860(&d, &d);
    }
    p->mUnk_194.mUnk_30 += a;
    if (p->mUnk_194.mUnk_30 >= 0x1000) {
        p->mUnk_194.mUnk_30 = 0x1000;
    }
    m = (s32) (((s64) p->mUnk_194.mUnk_30 * m) >> 12);
    s.x = (s32) (((s64) d.x * m) >> 12);
    s.y = (s32) (((s64) d.y * m) >> 12);
    s.z = (s32) (((s64) d.z * m) >> 12);
    func_02148504(&v, &s, &p->mUnk_024);
}

void func_02074978(Unk02061808 *p) {
    func_020749a4(p, p->mUnk_218->mUnk_42);
    func_020748b8(p);
    func_02076ed4(p);
}

// non-matching: registers only (22 words, same size): the original keeps q in ip and q->mUnk_18.x in r2 and puts
// the x product in r4/lr; here q is in lr, mUnk_18.x in ip and the product in r2/r1, with the y/z registers shifted
void func_020748b8(Unk02061808 *p) {
    Unk020748b8_218 *q = p->mUnk_218;
    s32 a, b, c, d;
    s32 x, y, z;
    s32 t;

    if (q->mUnk_44 != 0) {
        t = p->mUnk_244;
        a = q->mUnk_18.x;
        d = q->mUnk_24.x - a;
        x = (s32) (((s64) d * t) >> 12);
        b = q->mUnk_18.y;
        d = q->mUnk_24.y - b;
        y = (s32) (((s64) d * t) >> 12);
        c = q->mUnk_18.z;
        d = q->mUnk_24.z - c;
        z = (s32) (((s64) d * t) >> 12);
        p->mUnk_018.x = a + x;
        p->mUnk_018.y = b + y;
        p->mUnk_018.z = c + z;
        p->mUnk_244 += q->mUnk_44;
        if (p->mUnk_244 > 0x1000) {
            p->mUnk_244 = 0x1000;
        }
    } else {
        p->mUnk_018.x = q->mUnk_18.x;
        p->mUnk_018.y = q->mUnk_18.y;
        p->mUnk_018.z = q->mUnk_18.z;
    }
}
