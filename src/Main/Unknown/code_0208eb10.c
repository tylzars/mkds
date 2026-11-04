#include "Main/Unknown/code_0208eb10.h"
#include "Main/Unknown/code_02017000.h"

#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_020172d0.h"

s32 func_0208ec64(u32 a) {
    Unk0208ec64 *p;
    p = ListGetNth(&data_0217b08c->mUnk_00[1], 0);
    if (p != NULL) {
        p->mUnk_14 = a;
        p->mUnk_18 = 0;
        p->mUnk_1c = 0x400;
        ListRemove(&data_0217b08c->mUnk_00[1], p);
        ListAppend(&data_0217b08c->mUnk_00[0], p);
    }
    return (s32) p;
}

Unk0208ec64 *func_0208eb1c(s32 a) {
    Unk0208ec64 *p;
    Unk0206bcb0 *o;
    Unk0206bcb0_590 *t;
    Vec3 v;
    s32 h;

    if (data_021759c0->mUnk_00c == 5) {
        p = ListGetNth(&data_0217b08c->mUnk_00[1], 0);
        if (p != NULL) {
            o = func_0207a974(a);
            t = o->mKartModelsEntry;
            v = ((Vec3 *) &t->mUnk_020->mUnk_44)[t->mUnk_000];
            p->mUnk_14 = (u32) &o->mUnk_80;
            p->mUnk_18 = 0;
            p->mUnk_1c = 0x400;
            p->mUnk_20 = a;
            h = (v.y + (data_02166418[t->mUnk_000][0] >> 4) - data_02166480[t->mUnk_004]) / 2;
            p->mUnk_1c = h;
            p->mUnk_24 = v.x << 4;
            p->mUnk_28 = (data_02166480[t->mUnk_004] + h) << 4;
            p->mUnk_2c = data_0216641c[t->mUnk_000][0] + (v.z << 4);
            ListRemove(&data_0217b08c->mUnk_00[1], p);
            ListAppend(&data_0217b08c->mUnk_00[0], p);
        }
        return p;
    }
    return NULL;
}

void func_0208eb10(u32 p0) {
    *(u32 *) ((u8 *) p0 + 24) = (u32) 0x1u;
}
