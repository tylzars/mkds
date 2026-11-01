#include "Main/Unknown/code_0204bcec.h"

static inline void func_0204bcec_inline(Unk02175ec0 *a, void *p) {
    u32 t;
    if (p != 0) {
        t = func_0200fca0();
        a->mUnk_0014(a->mUnk_0018, 0, p);
        func_0200fcb4(t);
    }
}

void func_0204be0c(void) {
    Unk021762e0 *w;
    Unk02175ec0 *g;
    u8 *q;
    u16 h;
    u16 r;
    s32 z;
    data_02175ec0.mUnk_0004 = 1;
    if (data_02175ec0.mUnk_0000 == 0) {
        w = (Unk021762e0 *) &data_usa_021762e0;
        func_02143520(w->mUnk_0340);
        func_02007008(w->mUnk_04c4);
        func_02006ddc(1, (void (*)(Unk0216f3dc_9c *)) func_0204c320);
    } else {
        data_02175ec0.mUnk_000c = 2;
        if (data_02175ec0.mUnk_0010 != 0) {
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
    if (g->mUnk_0004 == 0) {
        return;
    }
    q = g->mUnk_0040;
    if (z != 0) {
        r = func_02006954((s32) q, h);
    } else {
        r = func_02006914((s32) q, h);
    }
    g->mUnk_0008 = func_02144048(func_0204ce60, 0, q, r, 0xffff, g->mUnk_0030, 3) == 2;
    g->mUnk_0004 = data_02175ec0.mUnk_0008 == 0;
}

void func_0204bcec(void) {
    Unk02175ec0 *g;
    Unk02175ec0_440s *q;
    u32 s;
    void *p;
    Unk02003a6c *u;
    g = (Unk02175ec0 *) &data_02175ec0;
    s = func_0200fca0();
    if (data_usa_02175e84 != 0) {
        p = g->mUnk_0020;
        if (p != 0) {
            func_0204bcec_inline(&data_02175ec0, p);
            g->mUnk_0020 = 0;
            g->mUnk_0024 = 0;
        }
        g->mUnk_000c = 0;
        if (data_02175ec0.mUnk_0000 == 0) {
            q = &g->mUnk_0440;
            if (g->mUnk_001c != 0) {
                u = g->mUnk_001c->mUnk_08;
                g->mUnk_001c = 0;
                func_02003be0(u, 5);
            }
            func_0204bcec_inline(&data_02175ec0, q->mUnk_0afc);
        } else {
            func_0204ba8c();
        }
        func_02006974();
        func_0214358c(data_02175ec0.mUnk_0030, 0, 0);
        data_usa_02175e84 = 0;
    }
    func_0200fcb4(s);
}
