#include "Main/Unknown/code_02001000.h"
#include "Main/Unknown/code_020019b0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02037a04.h"
#include "Main/Unknown/code_02038c94.h"
#include "Main/Unknown/code_02046ad0.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02108e94.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_02125da0.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/unk_02154000.h"
#include "code_0200eddc.h"
#include "code_0214a390.h"
#include "code_0214b824.h"

void func_02001d30(Unk02001d30 *a, s32 b, const char *c, const char *d, const char *e) {
    LoadNclrData(&a->mUnk_00, FindSceneFile(c));
    func_0200ee58(a->mUnk_00->mData, a->mUnk_00->mDataSize);
    if (b != 0) {
        func_0214c160(a->mUnk_00->mData, 0, a->mUnk_00->mDataSize);
    } else {
        func_0214c0f8(a->mUnk_00->mData, 0, a->mUnk_00->mDataSize);
    }
    LoadNcgrData2(&a->mUnk_04, FindSceneFile(d));
    func_0200ee58(a->mUnk_04->mData, a->mUnk_04->mDataSize);
    if (b != 0) {
        MemCopyWordsToG2Bg1CntBits2To5Address(a->mUnk_04->mData, 0, a->mUnk_04->mDataSize);
    } else {
        MemCopyWordsToG2sBg1CntBits2To5Address(a->mUnk_04->mData, 0, a->mUnk_04->mDataSize);
    }
    LoadNscrData(&a->mUnk_08, FindSceneFile(e));
    func_0200ee58(a->mUnk_08->mData, a->mUnk_08->mDataSize);
    if (b != 0) {
        MemCopyHalfwordsToG2Bg1CntBits8To12Address(a->mUnk_08->mData, 0, a->mUnk_08->mDataSize);
    } else {
        MemCopyHalfwordsToG2sBg1CntBits8To12Address(a->mUnk_08->mData, 0, a->mUnk_08->mDataSize);
    }
}

void func_02001ba0(void *a) {
    Unk02125de0Arg v1;
    u8 *v2;
    data_usa_ov001_021a99c0 = HeapAlloc(a, 60);
    v2 = func_02038d88(a, data_usa_021547c8);
    func_02038d28(v2 + 0x28, 1, 0, 0, 0, 0, 1, 0);
    func_02038d28(v2 + 0x70, 1, 0, 0, 0, 0, 2, 0);
    func_02037abc(v2);
    func_02001d30(&data_usa_ov001_021a99c0->mUnk_00, 1, data_usa_ov001_021a768c, data_usa_ov001_021a76a8,
                  data_usa_ov001_021a76c4);
    func_02001d30(&data_usa_ov001_021a99c0->mUnk_0c, 0, data_usa_ov001_021a76dc, data_usa_ov001_021a76f4,
                  data_usa_ov001_021a770c);
    func_02046be8(&data_usa_ov001_021a99c0->mUnk_18, (UnkFunc *const *) 0x02001080, 12, NULL);
    data_usa_ov001_021a99c0->mUnk_2c_0 = 0;
    data_usa_ov001_021a99c0->mUnk_30 = 0;
    data_usa_ov001_021a99c0->mUnk_38 = func_02047a28(data_usa_ov001_021a7720);
    v1.mUnk_00 = 1;
    v1.mUnk_04 = func_020b403c(1);
    v1.mUnk_08 = 0;
    v1.mUnk_10 = 0;
    v1.mUnk_14 = 0;
    v1.mUnk_18 = 0;
    v1.mUnk_1c = 0;
    v1.mUnk_20 = 0;
    v1.mUnk_24 = 0;
    v1.mUnk_0c = 1;
    LoadTxtSystemAndSelectChoisesAndSelectReturnData();
    func_02125de0(a, &v1);
}

void func_02001b38(void) {
    s32 v1;
    s32 v2;
    v1 = 0;
    data_usa_ov001_021a99c0 = NULL;
    v2 = data_0217aa08->mUnk_00->mUnk_31_1;
    switch (v2) {
        case 1:
            break;
        case 2:
            v1 = 2;
            break;
        case 0:
        default:
            v1 = 1;
            break;
    }
    func_02108e94(v1);
    func_02125da0();
}

void func_02001abc(void) {
    s32 v1;
    s32 v2;
    v1 = 0;
    func_021258f0();
    v2 = data_usa_ov001_021a99c0->mUnk_30;
    if (v2 > 90) {
        v1 = (-(v2 - 90) * 16) / 30;
    }
    func_0214a3e8((u16 *) 0x04000050, 2, v1);
    func_0214a3e8((u16 *) 0x04001050, 2, v1);
}

void func_02001a74(Unk02001a74 *a) {
    func_02046b40(&data_usa_ov001_021a99c0->mUnk_18);
    if (a != NULL && data_usa_ov001_021a99c0->mUnk_18.mUnk_0e == 11) {
        a->mUnk_04 = 0;
    }
    func_02125928();
}

void func_02001a44(void) {
    func_02056f98();
    data_usa_ov001_021a99c0->mUnk_2c_1 = 0;
}

void func_020019b0(void) {
    s32 v1;
    Unk021a99c0_18 *v2;
    data_usa_ov001_021a99c0->mUnk_30 = data_usa_ov001_021a99c0->mUnk_30 + 1;
    if (data_usa_ov001_021a99c0->mUnk_30 > 120) {
        v2 = &data_usa_ov001_021a99c0->mUnk_18;
        v2->mUnk_10 = 1;
        v2->mUnk_12 = 1;
    }
    v1 = func_020435bc();
    if ((data_02175628[v1].mBits & 0xf03) != 0xf03) {
        return;
    }
    data_usa_ov001_021a99c0->mUnk_2c_0 = 1;
}
