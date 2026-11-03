#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_021171a0.h"

#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02016468.h"
#include "Main/Unknown/code_02117218.h"
#include "Main/Unknown/code_02117224.h"
#include "Main/Unknown/code_021172a8.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_0216d000.h"
#include "Main/Unknown/code_0211732c.h"
#include "Main/Unknown/code_020472a8.h"

#pragma thumb on

void func_02117388(void) {
    void *v1;
    int v2;
    const char **v3;
    Unk020b4934 *v4;
    Unk02021dc8 *v5;
    Unk020b4a44 *v6[2];
    v4 = NULL;
    v5 = NULL;
    v6[0] = NULL;
    v1 = FindSceneFile(data_0216d534);
    LoadNcgrData(&v4, v1);
    v1 = FindSceneFile(data_0216d538);
    LoadNcerData(&v5, v1);
    v2 = 0;
    v3 = data_0216d53c;
    do {
        v1 = FindSceneFile(*v3);
        LoadNclrData(v6, v1);
        v3 = v3 + 1;
        v2 = v2 + 1;
    } while (v2 < 3);
}

void func_0211732c(void) {
    void *v1;
    int v2;
    const char **v3;
    Unk020b4934 *v4;
    Unk02021dc8 *v5;
    Unk020b4a44 *v6[2];
    v4 = NULL;
    v5 = NULL;
    v6[0] = NULL;
    v1 = FindSceneFile(data_0216d524);
    LoadNcgrData(&v4, v1);
    v1 = FindSceneFile(data_0216d528);
    LoadNcerData(&v5, v1);
    v2 = 0;
    v3 = data_0216d548;
    do {
        v1 = FindSceneFile(*v3);
        LoadNclrData(v6, v1);
        v3 = v3 + 1;
        v2 = v2 + 1;
    } while (v2 < 3);
}

#pragma thumb off

#pragma thumb on

void func_021172a8(void *a) {
    int i;

    data_0217d35c = func_02036bec(a, 0x18);
    LocateNcgr2(&data_0217d35c->mUnk_00, FindSceneFile(data_0216d534));
    LocateNcer(&data_0217d35c->mUnk_04, FindSceneFile(data_0216d538));
    for (i = 0; i < 3; i++) {
        LocateNclr(&data_0217d35c->mUnk_08[i], FindSceneFile(data_0216d53c[i]));
    }
    data_0217d35c->mUnk_14 = FindSceneFile(data_0216d52c);
}

#pragma thumb off

#pragma thumb on

void func_02117224(void *heap) {
    s32 i;

    data_0217d35c = func_02036bec(heap, 0x18);
    LocateNcgr2(&data_0217d35c->mUnk_00, FindSceneFile(data_0216d524));
    LocateNcer(&data_0217d35c->mUnk_04, FindSceneFile(data_0216d528));
    for (i = 0; i < 3; i++) {
        LocateNclr(&data_0217d35c->mUnk_08[i], FindSceneFile(data_0216d548[i]));
    }
    data_0217d35c->mUnk_14 = FindSceneFile(data_0216d530);
}

#pragma thumb off

#pragma thumb on
void func_02117218(void) {
    u32 value0;
    u32 value1;
    value1 = 0u;
    value0 = (u32) &data_0217d35c;
    *(u32 *) ((value0) + 0u) = value1;
}
#pragma thumb off

#pragma thumb on

void func_021171a0(s32 a, void *b, void *c, u32 d, u16 e, s32 f) {
    int n;

    n = 0x12;
    switch (f) {
        case 0:
            n = 0xe;
            break;
        case 1:
            n = 0x1e;
            break;
    }
    func_02124748(data_0215c60c[a].mUnk_00, data_0217d35c->mUnk_04, data_0217d35c->mUnk_00, data_0217d35c->mUnk_14, f,
                  d, b, c);
    func_02016468(n, e * 32, data_0217d35c->mUnk_08[data_0215c60c[a].mUnk_04]->mUnk_0c + data_0215c60c[a].mUnk_08 * 16,
                  0x20);
}

#pragma thumb off
