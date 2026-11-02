#include "Main/Unknown/code_0211db90.h"

#pragma thumb on

void func_0211dd44(void) {
    void *v1;
    Unk020b4934 *v2;
    Unk02021dc8 *v3;
    Unk020b4a44 *v4;
    Unk020b4934 *v5;
    Unk020b47d8 *v6;
    Unk020b4a44 *v7[1];
    v2 = 0;
    v3 = 0;
    v4 = 0;
    v5 = 0;
    v6 = 0;
    v7[0] = 0;
    v1 = func_0204799c((const char *) ((*(u32 *) &data_0216dbe4)));
    func_020b496c(&v5, v1);
    v1 = func_0204799c((const char *) ((*(u32 *) &data_0216dbf0)));
    func_020b4810(&v6, v1);
    v1 = func_0204799c((const char *) ((*(u32 *) &data_0216dbd8)));
    func_020b4a7c(v7, v1);
    v1 = func_0204799c((const char *) ((*(u32 *) &data_0216dc08)));
    func_020b496c(&v5, v1);
    v1 = func_0204799c((const char *) ((*(u32 *) &data_0216dbdc)));
    func_020b4810(&v6, v1);
    v1 = func_0204799c((const char *) ((*(u32 *) &data_0216dbf8)));
    func_020b49f4(&v2, v1);
    v1 = func_0204799c((const char *) ((*(u32 *) &data_0216dc04)));
    func_020b48ec(&v3, v1);
    v1 = func_0204799c((const char *) ((*(u32 *) &data_0216dbec)));
    func_020b4a7c(&v4, v1);
    func_02116e70();
}

void func_0211db90(void) {
    u32 v1;
    int v2;
    int v3;
    int v4[1];
    v2 = 0;
    v3 = 0;
    v4[0] = 0;
    if (data_0217d368->mUnk_2c == 3) {
        v1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dc08))));
        func_020b4934((Unk020b4934 **) (&v3), (void *) v1);
        v1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dbdc))));
        func_020b47d8((Unk020b47d8 **) ((int *) (u32) ((int) data_0217d368 + 0x20)), (void *) v1);
        v1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dbe0))));
        data_0217d368->mUnk_04 = (Unk0201ea30 *) v1;
        v1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dc00))));
        data_0217d368->mUnk_08 = (Unk0201ea30 *) v1;
        v1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dbfc))));
        data_0217d368->mUnk_0c = (void *) v1;
    } else {
        v1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dbe4))));
        func_020b4934((Unk020b4934 **) (&v3), (void *) v1);
        v1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dbf0))));
        func_020b47d8((Unk020b47d8 **) ((int *) (u32) ((int) data_0217d368 + 0x20)), (void *) v1);
        v1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dbf4))));
        data_0217d368->mUnk_04 = (Unk0201ea30 *) v1;
        v1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dbd4))));
        data_0217d368->mUnk_08 = (Unk0201ea30 *) v1;
        v1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dbe8))));
        data_0217d368->mUnk_0c = (void *) v1;
    }
    v1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dbd8))));
    func_020b4a44((Unk020b4a44 **) v4, (void *) v1);
    v1 = ((u32) func_02036bec((void *) data_0217d368->mUnk_28, (u32) (((u32) 0x00000800u))));
    data_0217d368->mUnk_24 = v1;
    v1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dbf8))));
    func_020b49bc((Unk020b4934 **) (&v2), (void *) v1);
    v1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dc04))));
    func_020b48b4(&data_0217d368->mUnk_00, (void *) v1);
    v1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dbec))));
    func_020b4a44((Unk020b4a44 **) ((int *) (u32) ((int) data_0217d368 + 0x10)), (void *) v1);
    func_02016468((u32) 0x14, (u32) 0, (void *) (*(u32 *) (v3 + 0x14)), (u32) (*(u32 *) (v3 + 0x10)));
    func_02016468((u32) 0x1b, (u32) 0, (void *) &data_0217d368->mUnk_20->mUnk_0c,
                  (u32) (*(u32 *) ((int) data_0217d368->mUnk_20 + 8)));
    func_02016468((u32) 0x1b, (u32) (((u32) 0x00000800u)), (void *) (data_0217d368->mUnk_24),
                  (u32) (((u32) 0x00000800u)));
    func_02016468((u32) 0x1f, (u32) 0, (void *) (*(u32 *) (v4[0] + 0xc)), (u32) 0x80);
    func_02016468((u32) 0x23, (u32) 0, (void *) (*(u32 *) (v2 + 0x14)), (u32) (*(u32 *) (v2 + 0x10)));
    func_02016468((u32) 0x1e, (u32) 0, (void *) (*(u32 *) ((int) data_0217d368->mUnk_10 + 0xc)),
                  (u32) (*(u32 *) ((int) data_0217d368->mUnk_10 + 8)));
}

#pragma thumb off
