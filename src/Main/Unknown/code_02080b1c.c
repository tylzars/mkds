#include "Main/Unknown/code_02080b1c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0208537c.h"
#include "code_02147cd8.h"

s32 func_02080c64(Unk02080b1c *p, Vec3 *a) {
    Vec3 v;
    s32 d;
    BOOL r;
    Unk02080b1c_00 *n = p->mUnk_00;

    r = FALSE;
    d = n->mUnk_1c;
    Vec3Sub(n->mUnk_18, a, &v);
    v.y = r;
    if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z < (s64) d * d) {
        r = TRUE;
    }
    return r;
}

s32 func_02080bf4(Unk02080b1c *p, Vec3 *a) {
    Vec3 v;
    BOOL r;
    Vec3 *w = p->mUnk_00->mUnk_18;

    r = FALSE;
    if (p->mUnk_08.x != 0 || p->mUnk_08.y != 0 || p->mUnk_08.z != 0) {
        Vec3Sub(a, w, &v);
        if (func_02039828(&p->mUnk_08, &v) > 0) {
            r = TRUE;
        }
    }
    return r;
}

void func_02080b1c(Unk02080b1c *p) {
    u16 i = 0;
    u16 n;
    u32 v;
    Unk0217aebc_128 *q;

    if (!(func_0207a974(p->mUnk_1c)->mUnk_4c & 0x10000000)) {
        n = p->mUnk_00->mUnk_24;
        if (n > 1) {
            q = func_0208537c();
            if (n == 0) {
                v = 0;
            } else {
                q->mUnk_00 = (s64) q->mUnk_08 * (s64) q->mUnk_00 + q->mUnk_10;
                v = (n == 0) ? (u32) (q->mUnk_00 >> 32) : (u32) (((q->mUnk_00 >> 32) * (u32) n) >> 32);
            }
            i = (u16) v;
        }
    }
    p->mUnk_04 = p->mUnk_00;
    p->mUnk_00 = p->mUnk_00->mUnk_00[i];
    Vec3Sub(p->mUnk_00->mUnk_18, p->mUnk_04->mUnk_18, &p->mUnk_08);
    func_02039860(&p->mUnk_08, &p->mUnk_08);
}
