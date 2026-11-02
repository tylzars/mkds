#include "01/code_021a6430.h"

#include "types.h"
#include "01/code_021a5140.h"
#include "01/code_02184000.h"
#include "01/code_02185000.h"
#include "01/code_02180ce8.h"
#include "01/code_02180cb4.h"
#include "01/unk_021ca000.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "01/unk_021a7000.h"
#include "code_0212df7c.h"

void func_ov001_021a651c(void) {
    void *v1;
    Unk020b4934 *v2;
    Unk02021dc8 *v3;
    Unk020b4a44 *v4[1];
    v2 = 0;
    v3 = 0;
    v4[0] = 0;
    v1 = FindSceneFile(data_ov001_021a993c);
    LoadNcgrData(&v2, v1);
    v1 = FindSceneFile(data_ov001_021a9938);
    LoadNcerData(&v3, v1);
    v1 = FindSceneFile(data_ov001_021a9944);
    LoadNclrData(v4, v1);
    return;
}

void func_ov001_021a64ac(void *a) {
    data_ov001_021ca424 = func_02036bec(a, 0x10);
    LocateNcgr2(&data_ov001_021ca424->mUnk_00, FindSceneFile(data_ov001_021a993c));
    LocateNcer(&data_ov001_021ca424->mUnk_04, FindSceneFile(data_ov001_021a9938));
    LocateNclr((Unk020b4a44 **) &data_ov001_021ca424->mUnk_08, FindSceneFile(data_ov001_021a9944));
    data_ov001_021ca424->mUnk_0c = FindSceneFile(data_ov001_021a9940);
}

void func_ov001_021a64a0(void) {
    *(u32 *) &data_ov001_021ca424 = 0;
    return;
}

void func_ov001_021a6430(s32 a, s32 flagB, void *c, void *d, u32 e, u16 f, s32 flagG) {
    s32 v0 = 14;
    Unk021ca424 *p;
    u8 *dst;
    s32 v1;

    if (flagG != 0) {
        if (flagG == 1) {
            v0 = 30;
        }
    }
    p = data_ov001_021ca424;
    func_02124748((u32) (data_ov001_021a7664[a]), (void *) p->mUnk_04, (void *) p->mUnk_00, (void *) p->mUnk_0c,
                  (s32) (flagG), (u32) (e), (void *) (c), (void *) (d));
    dst = data_ov001_021ca424->mUnk_08->mUnk_0c;
    if (flagB != 0) {
        v1 = data_ov001_021a7674[a];
    } else {
        v1 = 7;
    }
    func_02016468(v0, f << 5, dst + (v1 << 5), 32);
}
