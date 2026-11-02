#include "Main/Unknown/code_0211f240.h"

#include "Main/Unknown/code_0211f2ac.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_0211f2b8.h"

#pragma thumb on

void func_0211f328(void) {
    void *v1;
    Unk020b4934 *v2;
    Unk02021dc8 *v3;
    Unk020b4a44 *v4[1];
    v2 = 0;
    v3 = 0;
    v4[0] = 0;
    v1 = FindSceneFile(data_0216e0a8);
    LoadNcgrData(&v2, v1);
    v1 = FindSceneFile(data_0216e0ac);
    LoadNcerData(&v3, v1);
    v1 = FindSceneFile(data_0216e0b4);
    LoadNclrData(v4, v1);
}

void func_0211f2b8(void *a) {
    int v1;
    void *v2;
    v1 = ((u32) func_02036bec(a, (u32) 0x10));
    *(s32 *) &data_0217d37c = v1;
    v2 = FindSceneFile(data_0216e0a8);
    LocateNcgr2(&data_0217d37c->mUnk_00, v2);
    v2 = FindSceneFile(data_0216e0ac);
    LocateNcer(&data_0217d37c->mUnk_04, v2);
    v2 = FindSceneFile(data_0216e0b4);
    LocateNclr(&data_0217d37c->mUnk_08, v2);
    v2 = FindSceneFile(data_0216e0b0);
    data_0217d37c->mUnk_0c = v2;
}

#pragma thumb off

#pragma thumb on

void func_0211f2ac(void) {
    data_0217d37c = 0;
}

#pragma thumb off

#pragma thumb on

void func_0211f244(int a, int b, void *c, void *d, u32 e, u16 f, int g) {
    u32 v1;
    u32 *v2;
    v1 = 0xe;
    if ((g != 0) && (g == 1)) {
        v1 = 0x1e;
    }
    v2 = (u32 *) data_0217d37c;
    func_02124748((u32) (*(u16 *) (((u32) ((u8 *) &data_0215d014)) + a * 2)), (void *) (v2[1]), (void *) (*v2),
                  (void *) (v2[3]), g, e, c, d);
    func_02016468(v1, (u32) ((u32) f << 5),
                  (void *) ((s32) data_0217d37c->mUnk_08->mUnk_0c + ((u16 *) &data_0215d00c)[b] * 0x20),
                  (u32) 0x20);
}

void func_0211f240(void) {}

#pragma thumb off
