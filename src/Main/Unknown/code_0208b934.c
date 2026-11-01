#include "Main/Unknown/code_0208b934.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02047b08.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Unknown/code_02081f30.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0208bd04.h"
#include "Main/Unknown/code_0208d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02147cd8.h"

void func_0208b934(void *a) {
    s32 e = 0x78;
    s32 f = 0x28;
    void *c = a;
    void *g;
    void *h;
    void *t;
    u8 j;
    Vec3 w;
    Vec3 v;
    Unk021759c0 *d;
    Vec3 *q;

    *(u32 *) &data_0217b050 = (u32) func_0208b484;
    if (func_0205e0a0() == 2) {
        d = data_021759c0;
        if (d->mUnk_08 == 4) {
            *(u32 *) &data_0217b050 = (u32) func_0208b458;
            c = data_0217aa10->mUnk_a4;
            e = 0x96;
        }
        if (d->mUnk_00 == 0x34) {
            e = 0x12c;
            f = 0x32;
        }
    }
    data_0217b040 = c;
    data_0217b044 = func_02018d94((void *(*) (u32)) func_0208bd04, f, e, 3, 0xe, func_02061768());
    g = func_02047b08(data_usa_02166138);
    func_02018a1c(data_0217b044, g);
    func_02018888(data_0217b044);
    func_02018874(data_0217b044);
    func_02047220(g, *(u32 *) ((u8 *) g + 0x18));
    data_0217b04c = func_02018d94((void *(*) (u32)) func_0208bd04, 0x1e, 0x64, 3, 0xe, 0x1e);
    h = func_02047b08(data_usa_02166148);
    func_02018a1c(data_0217b04c, h);
    func_02018888(data_0217b04c);
    func_02018874(data_0217b04c);
    data_0217b03c = 0;
    data_0217b054 = 0;
    data_0217b048 = 0;
    if (func_0205e0a0() != 2) {
        return;
    }
    if (data_021759c0->mUnk_08 == 4) {
        t = 0;
        data_0217b03c = func_02018d94((void *(*) (u32)) func_0208bd04, 0x32, 0xc8, 3, 0xe, 0x1e);
        func_02048590(data_usa_02166168, (u32) c, &t);
        func_02018a1c(data_0217b03c, t);
        func_02018888(data_0217b03c);
        func_02018874(data_0217b03c);
        data_0217b03c->mUnk_3c = 0x8000;
    }
    data_0217b044->mUnk_38_24 = 1;
    data_0217b04c->mUnk_38_24 = 1;
    if (data_0217b03c != 0) {
        data_0217b03c->mUnk_38_24 = 1;
    }
    func_0208d758(a);
    if (data_021759c0->mUnk_00 != 0x1d) {
        data_0217b044->mUnk_3c = 0x8000;
    } else {
        data_0217b044->mUnk_3c = 0;
    }
    func_02082aec();
    switch (data_021759c0->mUnk_00) {
        case 0x22:
            w = data_usa_021660fc;
            data_0217b048 = func_02036bec(c, 0x64);
            for (j = 0; j < 6; j++) {
                data_0217b048->mUnk_48[j] = 0;
                func_021484d0(&data_usa_02155f78[j], &w, &v);
                q = &data_0217b048->mUnk_00[j];
                if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 0x10) {
                    func_02039860(&v, q);
                }
            }
            data_0217b048->mUnk_60 = 1;
            data_0217b054 = (UnkFunc *) func_0208b190;
            break;
        case 0x34:
            func_0208afe4();
            break;
    }
}
