#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020c4780.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0200eddc.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "code_0214c778.h"
#include "Main/Unknown/code_020c4bec.h"

const Vec3 data_02156880 = {0, 0, 0};

void func_020c4ae8(void) {
    Unk020c06c4 *p;
    Unk02021e40 *c;
    s32 v[2];

    gRaceStartGp->mUnk_18.mUnk_400 = 0;
    c = gRaceStartGp->mRaceStartGpMNcerEntries[0];
    p = &gRaceStartGp->mUnk_18;
    v[0] = 0x80000;
    v[1] = 0x60000;
    p->mUnk_400 += func_020224e0((Unk020224e0_o *) &p->mUnk_000.mUnk_00[p->mUnk_400], 0x80 - p->mUnk_400,
                                 (Unk020224e0_c *) c, NULL, v, 0, 1);
    func_0200ee74(&gRaceStartGp->mUnk_18, 0x400);
    func_0214cc04(3, &gRaceStartGp->mUnk_18.mUnk_000.mUnk_00[gRaceStartGp->mUnk_18.mUnk_400], 0xc0,
                  (0x80 - gRaceStartGp->mUnk_18.mUnk_400) * 8);
}

void func_020c4ab8(s32 a) {
    if (data_021759c0->mUnk_08 == 1) {
        data_0217b3e4->mUnk_004[a] = 0;
    }
}

void func_020c4a04(s32 a) {
    s32 i;
    s32 j;

    if (data_021759c0->mUnk_08 != 1) {
        return;
    }
    for (i = 0; i < 0x28; i++) {
        data_0217b3e4->mUnk_010[a][i].mUnk_10 = 0;
    }
    for (j = 0; j < data_0217b3e4->mUnk_790[a].mUnk_00; j++) {
        data_0217b3e4->mUnk_790[a].mUnk_34[j] = 0x28;
    }
    data_0217b3e4->mUnk_004[a] = 1;
}

void func_020c4780(void) {
    s32 a;
    s32 j;
    Vec3 v;

    if (data_021759c0->mUnk_08 != 1) {
        return;
    }
    data_0217b3e4 = HeapAlloc(GetHeap(func_020364e8()), 0x910);
    data_0217b3e4->mUnk_000 = 1;
    for (a = 0; a < data_021759c0->mKartCount; a++) {
        data_0217b3e4->mUnk_004[a] = 1;
    }
    data_0217b3e4->mUnk_00c = 0;
    for (a = 0; a < data_021759c0->mKartCount; a++) {
        u16 w = (u32) func_020b6338(a);
        func_0207a91c(&v, a);
        for (j = 0; j < 0x28; j++) {
            data_0217b3e4->mUnk_010[a][j].mUnk_00 = v;
            data_0217b3e4->mUnk_010[a][j].mUnk_0c = w;
            data_0217b3e4->mUnk_010[a][j].mUnk_10 = 0;
            data_0217b3e4->mUnk_010[a][j].mUnk_14 = 3;
        }
    }
    a = 0;
    if (a < data_021759c0->mKartCount) {
        Vec3 z = data_02156880;
        do {
            data_0217b3e4->mUnk_790[a].mUnk_00 = 0;
            for (j = 0; j < 3; j++) {
                data_0217b3e4->mUnk_790[a].mUnk_04[j] = z;
                data_0217b3e4->mUnk_790[a].mUnk_34[j] = -1;
                data_0217b3e4->mUnk_790[a].mUnk_28[j] = 3;
            }
            a++;
        } while (a < data_021759c0->mKartCount);
    }
    for (a = 0; a < 16; a++) {
        s32 s = data_0215d4b4[((u16) (a * 0x10000 / 16) >> 4) * 2];
        s32 c = data_0215d4b4[((u16) (a * 0x10000 / 16) >> 4) * 2 + 1];
        data_0217b3e4->mUnk_810[a].mUnk_00 = c;
        data_0217b3e4->mUnk_810[a].mUnk_04 = s;
        data_0217b3e4->mUnk_810[a].mUnk_08 = -s;
        data_0217b3e4->mUnk_810[a].mUnk_0c = c;
    }
}
