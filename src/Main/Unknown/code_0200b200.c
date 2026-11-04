#include "Main/Unknown/code_0200b200.h"
#include "Main/Unknown/code_0200bae0.h"
#include "code_0214d018.h"

#pragma thumb on

// non-matching: same size; one instruction at +0x5c differs in encoding: `adds r0, r0, #3` here, `adds r0, #3` in the
// original
void func_0200b200(void) {
    Unk0200c16c v1;
    Unk0200c12c v2;
    switch (data_0216fde8->mUnk_5f0e) {
        case 5:
            v2.mUnk_00 = data_0216fde8->mUnk_5f08;
            v2.mUnk_1a = 1;
            v2.mUnk_1c = data_0216fde8->mUnk_5f0c;
            MemCopy(data_0216fde8->mUnk_05c4, v2.mUnk_04, 0x16);
            v1.mUnk_00 = 7;
            *(u8 *) &v1.mUnk_02 = func_0200c12c((u8 *) &v1 + 3, &v2);
            if (func_0200c16c(&v1, data_0216fde8->mUnk_04a0) != NULL) {
                func_0200bc78(8, 0xffff, data_0216fde8->mUnk_04a0);
            }
            break;
        case 7:
            v1.mUnk_00 = 8;
            func_0200c16c(&v1, data_0216fde8->mUnk_04a0);
            func_0200bc78(8, 0xffff, data_0216fde8->mUnk_04a0);
            break;
        case 8:
            break;
        case 9:
            v1.mUnk_00 = 10;
            func_0200c16c(&v1, data_0216fde8->mUnk_04a0);
            func_0200bc78(8, 0xffff, data_0216fde8->mUnk_04a0);
            break;
        case 10:
            v1.mUnk_00 = 11;
            func_0200c16c(&v1, data_0216fde8->mUnk_04a0);
            func_0200bc78(8, 0xffff, data_0216fde8->mUnk_04a0);
            break;
        default:
            v1.mUnk_00 = 0;
            func_0200c16c(&v1, data_0216fde8->mUnk_04a0);
            func_0200bc78(8, 0xffff, data_0216fde8->mUnk_04a0);
            break;
    }
}

void func_0200b344(Unk021425e8 *a) {
    Unk0200c0d8 v1;
    func_0200c0d8(&v1, a->mUnk_0c);
    switch (v1.mUnk_00) {
        case 1:
            if (data_0216fde8->mUnk_5f0e == 2) {
                func_0200ba44(5, 0);
            }
            break;
        case 2:
            if (data_0216fde8->mUnk_5f0e == 5) {
                func_0200ba44(6, 0);
            }
            break;
        case 6:
            if (data_0216fde8->mUnk_5f0e == 5) {
                func_0200ba44(0xe, 0);
            }
            break;
        case 3:
            if (data_0216fde8->mUnk_5f0e == 5) {
                func_0200ba44(7, 0);
            }
            break;
        case 4:
            if (data_0216fde8->mUnk_5f0e == 7) {
                func_0200ba44(8, 0);
            }
            if (data_0216fde8->mUnk_5f0e == 8) {
                func_0200ba44(9, 0);
            }
            break;
        case 5:
            if (data_0216fde8->mUnk_5f0e == 9) {
                func_0200ba44(10, 0);
            } else if (data_0216fde8->mUnk_5f0e == 10) {
                func_0200be00();
            }
            break;
    }
}

void func_0200b43c(s32 a, Unk021425e8 *b) {
    u16 v1;
    u16 v2;
    u16 t;
    switch (a) {
        case 7:
        case 8:
            break;
        case 11:
            func_0200ba44(3, 0);
            break;
        case 6:
            func_0200ba44(2, (u32) b);
            func_0200bef8(data_0216fde8, data_0216fde8->mUnk_0020);
            break;
        case 10:
            func_0200ba44(4, (u32) b);
            break;
        case 25:
            func_0200b200();
            break;
        case 9:
            func_0200b344(b);
            break;
        case 15:
            if (data_0216fde8->mUnk_5f0e == 10) {
                func_0200ba44(11, 0);
            } else {
                func_0200ba44(12, 0);
            }
            if (data_0216fde8->mUnk_5f04 != 0) {
                func_0200bab0();
            }
            break;
        case 0xff:
            t = b->mUnk_02;
            if (data_0216fde8->mUnk_05e0 != NULL) {
                switch (t) {
                    case 1:
                    case 4:
                    case 5:
                    case 6:
                    case 8:
                    case 9:
                        t = 9;
                        break;
                    case 15:
                    default:
                        t = 8;
                        break;
                }
                v1 = t;
                data_0216fde8->mUnk_05e0(0x13, &v1);
            }
            break;
        case 0x100:
            t = b->mUnk_00;
            if (data_0216fde8->mUnk_05e0 != NULL) {
                switch (t) {
                    case 0:
                    case 7:
                    case 8:
                    case 13:
                    case 14:
                    case 15:
                    case 17:
                    case 18:
                    case 21:
                    case 25:
                    case 29:
                        t = 9;
                        break;
                    case 1:
                    default:
                        t = 8;
                        break;
                }
                v2 = t;
                data_0216fde8->mUnk_05e0(0x13, &v2);
            }
            break;
        case 0x29:
            break;
    }
}

u32 func_0200b610(u32 a) {
    Unk02008934 *v1;
    v1 = func_02008934(a);
    if (v1 == NULL) {
        return 0;
    }
    data_0216fde8->mUnk_5f08 = v1->mUnk_4b8;
    data_0216fde8->mUnk_5f0c = v1->mUnk_4b5;
    func_0200c0ac((u32) data_0216fde8->mUnk_05a0);
    func_0200c090((u32) func_0200b43c);
    func_0200ba44(1, 0);
    MemCopy(v1->mUnk_4c0, data_0216fde8->mUnk_04c0, 0xc0);
    func_0200c008(data_0216fde8->mUnk_04c0);
    return 1;
}

void func_0200b698(Unk021425e8 *a) {
    if (a->mUnk_02 != 0) {
        func_0200b820(0xb, a->mUnk_02);
        return;
    }
    data_0216fde8->mUnk_5efc = 0;
    if (data_0216fde8->mUnk_5f04 != 0) {
        func_0200bab0();
        return;
    }
    func_0200b850(3, NULL, 0);
}

#pragma thumb off
