#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f1104.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/unk_027e0000.h"
#include "code_02147cd8.h"

void func_020f1150(int object, int kartIndex) {
    u32 objectAddress = object;
    u32 kartIndexValue = kartIndex;
    u32 value2;
    u32 value3;
    u32 kartItemsBase;
    value3 = ((u32) &gKartItems);
    value2 = 0x210u;
    kartItemsBase = *(const u32 *) ((value3) + (0));
    value3 = 0u;
    value2 = (kartIndexValue) * (value2) + (kartItemsBase);
    *(u32 *) ((objectAddress) + (552)) = value2;
    *(u32 *) ((objectAddress) + (556)) = value3;
    *(u32 *) ((objectAddress) + (560)) = value3;
    *(u32 *) ((objectAddress) + (564)) = value3;
    *(u32 *) ((objectAddress) + (568)) = value3;
}

void SetItemKouraRKartItems(ItemKouraR *item, int kartIndex) {
    item->mKartItems = &gKartItems[kartIndex];
    item->mUnk_238 = 0;
}

void func_020f1104(ItemKouraR *item) {
    VEC_Add(&item->mUnk_22c, &item->mUnk_000.mUnk_000.mUnk_000.mVelocity, &item->mUnk_000.mUnk_000.mUnk_000.mVelocity);
    func_020f29e8(item);
}
