#include "Main/Unknown/code_0211de40.h"

#pragma thumb on

void func_0211ded0(u32 param_1, void *param_2, void *param_3, u32 param_4, u16 param_5, s32 param_6) {
    Unk0217d370 *p;
    u8 *dst;
    u32 v0 = 14;
    u32 id;
    u32 n;

    if (param_6 != 0) {
        if (param_6 == 1) {
            v0 = 30;
        }
    }
    id = ((u16 *) data_0215cee4)[param_1];
    p = data_0217d370;
    func_02124748(id, p->mUnk_04, p->mUnk_00, p->mUnk_0c, param_6, param_4, param_2, param_3);
    p = data_0217d370;
    dst = (u8 *) p->mUnk_08->mUnk_0c;
    n = func_02124a68(id, p->mUnk_04, p->mUnk_0c);
    func_02016468(v0, param_5 << 5, dst + (n << 5), 32);
}

void func_0211de98(void) {
    void *v1;
    Unk020b4934 *v2;
    Unk02021dc8 *v3[1];
    v2 = 0;
    v3[0] = 0;
    v1 = func_0204799c((const char *) ((*(u32 *) &data_0216de54)));
    func_020b49f4(&v2, v1);
    v1 = func_0204799c((const char *) ((*(u32 *) &data_0216de58)));
    func_020b48ec(v3, v1);
}

void func_0211de40(void *param_1) {
    int v1;
    u32 v2;
    v1 = ((u32) func_02036bec(param_1, (u32) 0xc));
    *(int *) &data_0217d36c = v1;
    v2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216de54))));
    func_020b49bc((Unk020b4934 **) ((int *) (u32) data_0217d36c), (void *) v2);
    v2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216de58))));
    func_020b48b4(&data_0217d36c->mUnk_04, (void *) v2);
    v2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216de50))));
    *(u32 *) ((int) data_0217d36c + 8) = v2;
}

#pragma thumb off
