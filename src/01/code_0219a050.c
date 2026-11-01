#include "01/code_0219a050.h"
#include "01/unk_021a6000.h"

void func_ov001_0219a1a4(void) {
    s32 i;
    s16 v;
    data_ov001_021a9bf0->mUnk_38++;
    v = func_020ae4c0(1, 0xe0, 0, data_ov001_021a9bf0->mUnk_38, 10);
    for (i = 0; i < 3; i++) {
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6ab4[i]].mUnk_04 = v;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6ac4[i]].mUnk_04 = v;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6a9c[i]].mUnk_04 = v;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6aa4[i]].mUnk_04 = v;
    }
    if (data_ov001_021a9bf0->mUnk_38 >= 10) {
        func_ov001_0219ae44();
    }
}

void func_ov001_0219a0e8(void) {
    Unk021a9bf0 *p;
    data_ov001_021a9bf0->mUnk_30 = data_ov001_021a9bf0->mUnk_34;
    switch (data_ov001_021a9bf0->mUnk_30) {
        case 0:
            func_ov001_0219a938();
            break;
        case 1:
            func_ov001_0219a80c();
            break;
        case 2:
            func_ov001_0219a77c();
            break;
        case 3:
            func_ov001_0219a764();
            break;
        case 4:
            func_ov001_0219a5bc();
            break;
        case 5:
            func_ov001_0219a4fc();
            break;
        case 6:
            func_ov001_0219a3a0();
            break;
        case 7:
            func_ov001_0219a304();
            break;
        case 8:
            func_ov001_0219a2ec();
            break;
        case 9:
            func_ov001_0219a258();
            break;
        case 10:
            func_ov001_0219a240();
            break;
        case 11:
            func_ov001_0219a1a4();
            break;
    }
    p = data_ov001_021a9bf0;
    func_02124c30(p->mUnk_04, p->mUnk_00, p->mUnk_08, func_02111318(), p->mUnk_18);
    p = data_ov001_021a9bf0;
    func_02124c30(p->mUnk_10, p->mUnk_0c, 0, func_0211130c(), p->mUnk_1c);
}

void func_ov001_0219a0c0(void) {
    *(vu32 *) 0x4000010 = (-data_ov001_021a9bf0->mUnk_3c << 16) & 0x1ff0000;
    func_02111428();
}

void func_ov001_0219a078(void) {
    u32 a;
    u32 b;
    a = (*(vu32 *) 0x4000000 & 0x1f00) >> 8;
    *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | ((a | 0x11) << 8);
    b = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | ((b | 0x1) << 8);
}

void func_ov001_0219a050(void) {
    UnkFunc *tbl[5] = {func_ov001_0219a9a0, func_ov001_0219a950, func_ov001_0219a0e8, func_ov001_0219a0c0,
                       func_ov001_0219a078};
    func_02111494(tbl);
}
