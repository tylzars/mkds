#include "01/code_021a2034.h"

#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_020b4000.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"

void func_ov001_021a2300(Unk021a2300 *p) {
    s32 i;
    Unk021a2048 *o;
    Unk0217561c *d;
    Unk020f41c4_B *b;

    if (p != NULL) {
        i = 0;
        while (i < p->mUnk_04 && (o = p->mUnk_00[i]) != NULL) {
            d = data_0217561c;
            b = &d->mUnk_498;
            b->mUnk_00 = (s64) b->mUnk_08 * (s64) b->mUnk_00 + b->mUnk_10;
            o->mUnk_a0 = (u16) (((s64) (b->mUnk_00 >> 32) * 0x46) >> 32);
            o->mUnk_02 &= ~2;
            o->mUnk_02 &= ~8;
            o->mUnk_66 = 0x1f;
            i++;
        }
    }
}

void func_ov001_021a2284(void *p0, Unk021a2048 *p1) {
    Unk0217561c *d;
    Unk020f41c4_B *b;

    p1->mUnk_a0 -= 1;
    if (p1->mUnk_a0 < 0) {
        d = data_0217561c;
        b = &d->mUnk_498;
        b->mUnk_00 = (s64) b->mUnk_08 * (s64) b->mUnk_00 + b->mUnk_10;
        p1->mUnk_a0 = (u16) (((s64) (b->mUnk_00 >> 32) * 0x46) >> 32) + 0x46;
        if (!(p1->mUnk_02 & 0x12)) {
            func_0208b7bc(0x435, &p1->mUnk_04);
        }
    }
}

void *func_ov001_021a226c(void) {
    return (void *) func_0209bf48(func_ov001_021a2300, func_ov001_021a2284, NULL);
}

void func_ov001_021a2218(Unk021a2048 *o, Camera *g, Vec3 *out) {
    out->x = g->mPos.x + (s32) (((s64) g->mForward.x * 0x58000) >> 12);
    out->y = o->mUnk_04.y;
    out->z = g->mPos.z + (s32) (((s64) g->mForward.z * 0x58000) >> 12);
}

void func_ov001_021a2048(void *p0, Unk021a2048 *p1) {
    Camera *g;
    Vec3 v = {0, 0, 0};

    g = GetCurrentCamera();
    switch (p1->mUnk_a0) {
        case 0:
            p1->mUnk_a0 = 1;
            switch (p1->mUnk_9c->mUnk_28) {
                case 0:
                    func_0208b7bc(0x400, &v);
                    func_0208b7bc(0x3ff, &v);
                    func_0208b7bc(0x402, &v);
                    func_0208b7bc(0x403, &v);
                    func_0208b7bc(0x404, &v);
                    func_0208b7bc(0x405, &v);
                    func_0208b7bc(0x406, &v);
                    func_0208b7bc(0x407, &v);
                    func_0208b7bc(0x408, &v);
                    func_0208b7bc(0x409, &v);
                    func_0208b7bc(0x40a, &v);
                    func_0208b7bc(0x40b, &v);
                    p1->mUnk_a4 = func_0208b7bc(0x42f, &g->mPos);
                    break;
                case 1:
                    break;
                case 2:
                    func_0208b7bc(0x43c, &v);
                    func_0208b7bc(0x439, &v);
                    func_0208b7bc(0x43a, &v);
                    func_0208b7bc(0x43b, &v);
                    func_0208b7bc(0x438, &v);
                    func_0208b7bc(0x43d, &v);
                    func_0208b7bc(0x43e, &v);
                    func_0208b7bc(0x43f, &v);
                    func_ov001_021a2218(p1, g, &v);
                    p1->mUnk_a4 = func_0208b7bc(0x437, &v);
                    break;
            }
            break;
        case 1:
            switch (p1->mUnk_9c->mUnk_28) {
                case 0:
                    func_0208b5b0(p1->mUnk_a4, &g->mPos);
                    break;
                case 1:
                    break;
                case 2:
                    func_ov001_021a2218(p1, g, &v);
                    func_0208b5b0(p1->mUnk_a4, &v);
                    break;
            }
            break;
    }
}

void *func_ov001_021a2034(void) {
    return (void *) func_0209bf48(NULL, func_ov001_021a2048, NULL);
}
