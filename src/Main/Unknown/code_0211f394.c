#include "Main/Unknown/code_0211f394.h"

#include "Main/Unknown/code_0211f4b0.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02116a4c.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_0211f498.h"
#include "Main/Unknown/code_0211f61c.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02116dd4.h"
#include "code_02148ca0.h"
#include "Main/Unknown/code_020472a8.h"

#pragma thumb on

void func_0211f61c(void) {
    void *v1;
    int v2;
    int v3[1];
    v2 = 0;
    v3[0] = 0;
    v1 = FindSceneFile((const char *) ((*(u32 *) &data_0216e128)));
    func_020b48b4(&data_0217d380->mUnk_00, v1);
    v1 = FindSceneFile((const char *) ((*(u32 *) &data_0216e134)));
    func_020b49bc((Unk020b4934 **) (&v2), v1);
    v1 = FindSceneFile((const char *) ((*(u32 *) &data_0216e130)));
    func_020b4a44((Unk020b4a44 **) v3, v1);
    v1 = FindSceneFile((const char *) ((*(u32 *) &data_0216e124)));
    data_0217d380->mUnk_04 = v1;
    v1 = FindSceneFile((const char *) ((*(u32 *) &data_0216e12c)));
    data_0217d380->mUnk_0c = v1;
    func_02016468((u32) 0x23, (u32) 0, (void *) (*(u32 *) (v2 + 0x14)), (u32) (*(u32 *) (v2 + 0x10)));
    func_02016468((u32) 0x1e, (u32) 0, (void *) (*(u32 *) (v3[0] + 0xc)), (u32) (*(u32 *) (v3[0] + 8)));
}

#pragma thumb off

#pragma thumb on

void func_0211f5e4(void) {
    u16 a;

    data_0217d380->mUnk_20 = 0;
    data_0217d380->mUnk_24 = 0;
    a = data_0217d380->mUnk_04->mUnk_06;
    data_0217d380->mUnk_10[0x2a].mUnk_06 = 0xc0;
    data_0217d380->mUnk_10[a + 0xe].mUnk_06 = 0xc0;
}

void func_0211f5d0(void) {
    data_0217d380->mUnk_20 = 1;
    data_0217d380->mUnk_24 = 0;
}

void func_0211f598(void) {
    u16 a;

    data_0217d380->mUnk_20 = 2;
    data_0217d380->mUnk_24 = 0;
    a = data_0217d380->mUnk_04->mUnk_06;
    data_0217d380->mUnk_10[0x2a].mUnk_06 = 0;
    data_0217d380->mUnk_10[a + 0xe].mUnk_06 = 0;
}

void func_0211f4b0(void *a, void *b) {
    Unk0217d380 *p;
    s32 i;
    u16 n;
    u32 v;

    data_0217d380 = func_02036bec(a, 0x28);
    data_0217d380->mUnk_1c = 1;
    data_0217d380->mUnk_18 = b;
    func_0211f61c();
    func_02124ed0(a, data_0217d380->mUnk_04, data_0217d380->mUnk_0c, &data_0217d380->mUnk_10);
    data_0217d380->mUnk_14 = func_02047a28("common.bmg");
    v = func_02148ca0();
    func_021243ac(a, 0xe, data_0217d380->mUnk_0c, 0xc8, 0xd, 0, data_0217d380->mUnk_00, data_0217d380->mUnk_04,
                  data_0217d380->mUnk_10, v);
    p = data_0217d380;
    func_0212426c(1, 0xe, data_0217d380->mUnk_0c, func_020b3f7c(p->mUnk_14, 0x79), p->mUnk_04, p->mUnk_10);
    i = 0;
    n = data_0217d380->mUnk_04->mUnk_06;
    for (; i < n; i++) {
        data_0217d380->mUnk_10[i].mUnk_00 = 0;
    }
    data_0217d380->mUnk_10[0x2a].mUnk_00 = 1;
    func_02116dd4(a, data_0217d380->mUnk_00, data_0217d380->mUnk_04, 0x2a, 0xe, 1);
    func_0211f5e4();
    func_0211f5d0();
    func_0211f39c();
}

#pragma thumb off

#pragma thumb on

void func_0211f498(void) {
    func_02116dc8();
    *(u32 *) &data_0217d380 = 0;
}

#pragma thumb off

#pragma thumb on

void func_0211f440(void) {
    u16 a;
    s16 v;

    a = data_0217d380->mUnk_04->mUnk_06;
    data_0217d380->mUnk_24++;
    v = func_020ae4c0(1, 0xc0, 0, data_0217d380->mUnk_24, 10);
    data_0217d380->mUnk_10[0x2a].mUnk_06 = v;
    data_0217d380->mUnk_10[a + 0xe].mUnk_06 = v;
    if (data_0217d380->mUnk_24 >= 10) {
        func_0211f5d0();
    }
}

void func_0211f3e8(void) {
    u16 a;
    s16 v;

    a = data_0217d380->mUnk_04->mUnk_06;
    data_0217d380->mUnk_24++;
    v = func_020ae4c0(1, 0, 0xc0, data_0217d380->mUnk_24, 10);
    data_0217d380->mUnk_10[0x2a].mUnk_06 = v;
    data_0217d380->mUnk_10[a + 0xe].mUnk_06 = v;
    if (data_0217d380->mUnk_24 >= 10) {
        func_0211f5d0();
    }
}

void func_0211f39c(void) {
    data_0217d380->mUnk_1c = data_0217d380->mUnk_20;
    switch (data_0217d380->mUnk_1c) {
        case 0:
            func_0211f440();
            break;
        case 1:
            break;
        case 2:
            func_0211f3e8();
            break;
    }
    func_02116d24();
    func_02124c30(data_0217d380->mUnk_04, data_0217d380->mUnk_00, data_0217d380->mUnk_0c, data_0217d380->mUnk_18,
                  data_0217d380->mUnk_10);
}

void func_0211f394(void) {
    func_0211f5e4();
}

#pragma thumb off
