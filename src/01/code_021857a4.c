#include "01/code_0218550c.h"
#include "01/code_021857a4.h"
#include "01/code_02185ef4.h"
#include "01/code_0219e000.h"
#include "01/code_0219eab4.h"
#include "01/code_0219f8ec.h"
#include "01/code_ov001_02197b34.h"
#include "Main/Unknown/code_02026000.h"
#include "Main/Unknown/code_02025f80.h"
#include "Main/Unknown/code_02027e78.h"
#include "Main/Unknown/code_02028130.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020eb000.h"
#include "Main/Unknown/code_02117000.h"
#include "Main/Unknown/code_021173e4.h"
#include "Main/Unknown/code_02117418.h"
#include "Main/Unknown/code_02118000.h"
#include "Main/Unknown/code_021189f4.h"
#include "Main/Unknown/code_0211e000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_0211e0c4.h"
#include "code_021488e8.h"
#include "code_02148950.h"

#pragma optimize_for_size on

u16 func_ov001_02185b50(MissionGateObject *a) {
    return a->mUnk_0a8 != 0;
}

void func_ov001_02185b1c(void) {
    if (func_020cccc0()) {
        func_ov001_02185ad8(0x19);
        func_02148950(1, 0, 0);
        func_ov001_02185abc(0x16);
        GxsDispCntBits0To2Write(0);
    }
    func_ov001_0219eab4();
}

void func_ov001_02185af0(void) {
    switch (AdvanceMissionRunLVsel()) {
        case 1:
            func_020ccc74(0x13, 0x1f);
            break;
        case 2:
            func_020ccc74(0, 0x1f);
            break;
    }
}

#pragma thumb off
void func_ov001_02185ad8(u32 a) {
    vu32 *r = (vu32 *) 0x4000000;
    *r = (*r & ~0x1f00) | (a << 8);
}

void func_ov001_02185abc(u32 a) {
    vu32 *r = (vu32 *) 0x4001000;
    *r = (*r & ~0x1f00) | (a << 8);
}
#pragma thumb on

void func_ov001_02185a88(void) {
    if (func_020cccc0()) {
        func_ov001_02185ad8(0x1b);
        func_02148950(1, 0, 0);
        func_ov001_02185abc(0x16);
        GxsDispCntBits0To2Write(0);
    }
    func_ov001_0219f8ec();
}

void func_ov001_02185a5c(void) {
    switch (AdvanceMissionRunMSsel()) {
        case 1:
            func_020ccc74(0x1d, 0x1f);
            break;
        case 2:
            func_020ccc74(0x12, 0x1f);
            break;
    }
}

void func_ov001_02185a28(void) {
    if (func_020cccc0()) {
        func_ov001_021856a8(0x19);
        func_02148950(1, 0, 0);
        func_ov001_0218568c(0x16);
        GxsDispCntBits0To2Write(0);
    }
    func_ov001_02197b34();
}

#pragma thumb off
void func_ov001_02185a14(s32 a) {
    data_0217b488->mUnk_0c = a;
}
#pragma thumb on

void func_ov001_021859b8(void) {
    switch (AdvanceTimeAttackTopMenu()) {
        case 1:
            func_020ccc74(0x15, 0x1f);
            break;
        case 2:
            func_020ccc74(0x1c, 0x1f);
            func_ov001_02185a14(0);
            break;
        case 3:
            func_020ccc74(0x1c, 0x1f);
            func_ov001_02185a14(1);
            break;
        case 4:
            func_020ccc74(0, 0x1f);
            break;
    }
}

void func_ov001_02185980(void) {
    if (func_020cccc0()) {
        func_ov001_021856a8(0xb);
        func_02148950(1, 0, 1);
        func_ov001_0218568c(8);
        GxsDispCntBits0To2Write(0);
    }
    func_ov001_0218568c(0x12);
    func_02026058();
}

void func_ov001_02185954(void) {
    switch (AdvanceSelectCharacter()) {
        case 1:
            func_020ccc74(0x16, 0x1f);
            break;
        case 2:
            func_020ccc74(0x14, 0x1f);
            break;
    }
}

void func_ov001_02185928(void) {
    if (func_020cccc0()) {
        func_ov001_021856a8(0xb);
        func_02148950(1, 0, 1);
    }
    func_ov001_0218568c(0x12);
    func_02027e78();
}

void func_ov001_021858fc(void) {
    switch (AdvanceSelectKart()) {
        case 1:
            func_020ccc74(0x17, 0x1f);
            break;
        case 2:
            func_020ccc74(0x15, 0x1f);
            break;
    }
}

void func_ov001_021858c8(void) {
    if (func_020cccc0()) {
        func_ov001_021856a8(0x19);
        func_02148950(1, 0, 0);
        func_ov001_0218568c(0x16);
        GxsDispCntBits0To2Write(0);
    }
    func_021173e4();
}

#pragma thumb off
void func_ov001_021858b4(s32 a) {
    data_0217b488->mUnk_08 = a;
}

void func_ov001_021858a0(s32 a) {
    data_0217b488->mUnk_04 = a;
}
#pragma thumb on

void func_ov001_0218585c(void) {
    switch (func_02117418()) {
        case 1:
            func_020ccc74(0x18, 0x1f);
            break;
        case 2:
            func_020ccc74(0x16, 0x1f);
            break;
        case 3:
            func_020ccc74(0, 0x1f);
            func_ov001_021858b4(0);
            func_ov001_021858a0(1);
            break;
    }
}

void func_ov001_02185828(void) {
    if (func_020cccc0()) {
        func_ov001_021856a8(0x19);
        func_02148950(1, 0, 0);
        func_ov001_0218568c(0x1e);
        GxsDispCntBits0To2Write(0);
    }
    func_02118e30();
}

void func_ov001_021857ec(void) {
    switch (AdvanceSelectCup()) {
        case 1:
            if (func_0211e130()) {
                func_020ccc74(0x1d, 0x1f);
            } else {
                func_020ccc74(0x1a, 0x1f);
            }
            break;
        case 2:
            func_020ccc74(0x18, 0x1f);
            break;
    }
}

#pragma thumb off
void func_ov001_021857c0(u32 a, u32 b) {
    *(vu32 *) 0x4000014 = (a & 0x1ff) | ((b << 16) & 0x1ff0000);
}

void func_ov001_021857a4(u32 a) {
    vu16 *r = (vu16 *) 0x400000a;
    *r = (*r & ~3) | a;
}
#pragma thumb on
