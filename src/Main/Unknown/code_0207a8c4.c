#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0207a8c4.h"
#include "Main/Unknown/code_0207a14c.h"
#include "Main/Unknown/code_0207a32c.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020638c0.h"
#include "Main/Unknown/code_02063b70.h"
#include "Main/Unknown/code_020649ec.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_0208c188.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_02086058.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020733ec.h"

void func_0207ad88(Unk0207adf8 *a, u32 b, u32 c) {
    if ((a->mUnk_70 & 1) != 0) {
        func_02084ad8(a, a->mUnk_6e);
        data_02155a20[a->mUnk_00.mUnk_58](a);
        func_02084a88(a, a->mUnk_6e, a->mUnk_6c);
        data_02155a20[a->mUnk_00.mUnk_58](a);
    }
}

void func_0207abec(u32 a) {
    u16 i;
    void *h = func_020364e0(func_020364e8());
    Unk0206cdd4_B *q;
    data_0217ad18 = func_02036bec(h, a * 0x5a8);
    data_usa_0217acf4 = a;
    q = func_02036bec(h, 0x1c);
    data_usa_0217acfc = q;
    data_0217ad10 = 0;
    data_0217ad20 = 0;
    data_usa_021658c0 = -1;
    q->mUnk_00 = 0;
    q->mUnk_04 = 0;
    q->mUnk_08 = 0;
    q->mUnk_0c = 0;
    q->mUnk_10 = 0;
    q->mUnk_14 = 0;
    q->mUnk_18 = 0;
    data_usa_021658bc = data_021759c0->mUnk_08 == 2 ? 1 : 2;
    func_02073630();
    func_0208c284();
    func_020845cc(a);
    data_0217ad24 = 0;
    if (data_021759c0->mUnk_08 == 4) {
        if (gCourseMap->mUnk_10f != 0) {
            data_0217ad24 = 1;
        }
    }
    for (i = 0; i < a; i++) {
        data_0217ad18[i].mIndex = i;
        data_0217ad18[i].mUnk_78 = data_021759c0->mUnk_68[i].mUnk_08.mUnk_0c;
        func_020649ec(&data_0217ad18[i], data_usa_021655e4);
    }
    data_0217ad28 = 0;
}

void func_0207aaec(void) {
    s32 i;
    Unk0206bcb0 *p = data_0217ad18;
    data_0217ad20 = 0;
    data_usa_021658c0 = -1;
    for (i = 0; i < data_usa_0217acf4; i++) {
        func_01ffcac0(p);
        p++;
    }
    func_0207a32c();
    p = data_0217ad18;
    for (i = 0; i < data_usa_0217acf4; i++) {
        p->mUnk_20c_fn[3](p);
        p++;
    }
    p = data_0217ad18;
    for (i = 0; i < data_usa_0217acf4; i++) {
        p->mUnk_20c_fn[4](p);
        p++;
    }
}

void func_0207aa7c(void) {
    Unk0206bcb0 *p = data_0217ad18;
    s16 i;
    for (i = 0; i < data_usa_0217acf4; i++) {
        p->mUnk_20c_fn[2](p);
        p++;
    }
}

void func_0207a9f4(void) {
    s32 i = 0;
    u16 *p = func_02086058();
    (data_0217ad18[data_021759c0->mUnk_62].mKartModelsEntry)->mUnk_060 = 1;
    for (; i < data_usa_0217acf4; i++) {
        func_02063cc4(&data_0217ad18[*p]);
        p++;
    }
}

void func_0207a990(void) {
    s32 i;
    for (i = 0; i < data_usa_0217acf4; i++) {
        func_020638c0(&data_0217ad18[i]);
    }
    data_0217ad18 = NULL;
}

Unk0206bcb0 *func_0207a974(s32 a) {
    return &data_0217ad18[a];
}

void func_0207a948(Vec3 *a, s32 b) {
    *a = *data_0217ad18[b].mUnk_508;
}

void func_0207a91c(Vec3 *a, u8 b) {
    *a = *data_0217ad18[b].mUnk_534;
}

void func_0207a8f0(Vec3 *a, s32 b) {
    *a = data_0217ad18[b].mUnk_8c;
}

void func_0207a8c4(Vec3 *a, s32 b) {
    *a = data_0217ad18[b].mUnk_bc;
}
