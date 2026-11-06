#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f1104.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/unk_027e0000.h"
#include "code_02147cd8.h"

void func_020f1150(int arg0, int arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    u32 value3;
    u32 value12;
    value3 = ((u32) &gKartItems);
    value2 = 0x210u;
    value12 = (u32) * (const u32 *) ((value3) + (0));
    value3 = 0u;
    value2 = (value1) * (value2) + (value12);
    *(u32 *) ((value0) + (552)) = value2;
    *(u32 *) ((value0) + (556)) = value3;
    *(u32 *) ((value0) + (560)) = value3;
    *(u32 *) ((value0) + (564)) = value3;
    *(u32 *) ((value0) + (568)) = value3;
}

void func_020f112c(ItemKouraR *a, int b) {
    a->mKartItems = &gKartItems[b];
    a->mUnk_238 = 0;
}

void func_020f1104(ItemKouraR *a) {
    VEC_Add(&a->mUnk_22c, &a->mUnk_000.mUnk_000.mUnk_000.mVelocity, &a->mUnk_000.mUnk_000.mUnk_000.mVelocity);
    func_020f29e8(a);
}
