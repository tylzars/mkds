#include "01/code_0218550c.h"
#include "Main/Unknown/code_02026120.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_0211e4e8.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_02026000.h"
#include "Main/Unknown/code_02027000.h"
#include "Main/Unknown/code_0211e000.h"
#include "01/code_021854d8.h"
#include "01/callees_0219b000.h"
#include "01/code_02185000.h"
#include "01/code_021857a4.h"
#include "01/code_0219b540.h"
#include "01/code_021a1000.h"
#include "01/code_021a11a4.h"
#include "Main/Unknown/code_02028000.h"
#include "Main/Unknown/code_020cc000.h"
#include "code_021488e8.h"
#include "code_02148950.h"
#include "registers.h"

#pragma optimize_for_size on

#pragma thumb off

void func_ov001_02185778(int a) {
    if (a != 0) {
        reg_G2_BG1CNT |= 0x40;
    } else {
        reg_G2_BG1CNT &= ~0x40;
    }
}

void func_ov001_02185740(u32 a, u32 b, u32 c, u32 d, u32 e) {
    reg_G2_BG1CNT = (reg_G2_BG1CNT & 0x43) | (a << 14) | (b << 7) | (c << 8) | (d << 2) | (e << 13);
}

#pragma thumb on

void func_ov001_021856ec(void) {
    if (func_020cccc0() != 0) {
        func_ov001_021856a8(0x19);
        func_02148950(1, 0, 0);
        func_ov001_021857c0(0, 0);
        func_ov001_021857a4(0);
        func_ov001_02185778(0);
        func_ov001_02185740(0, 0, 0xc, 0, 0);
        func_ov001_0218568c(0x1f);
        func_02148934(0);
    }
    func_ov001_0219b540();
}

void func_ov001_021856c0(void) {
    switch (AdvanceSelectGhost()) {
        case 1:
            func_020ccc74(29, 0x1f);
            break;
        case 2:
            func_020ccc74(25, 0x1f);
            break;
    }
}

#pragma thumb off

void func_ov001_021856a8(u32 a) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | (a << 8);
}

void func_ov001_0218568c(u32 a) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | (a << 8);
}

#pragma thumb on

void func_ov001_02185658(void) {
    if (func_020cccc0() != 0) {
        func_ov001_021856a8(0x19);
        func_02148950(1, 0, 0);
        func_ov001_0218568c(0x1e);
        func_02148934(0);
    }
    func_0211e4e8();
}

void func_ov001_0218562c(void) {
    switch (func_0211e51c()) {
        case 1:
            func_020ccc74(25, 0x1f);
            break;
        case 2:
            func_020ccc74(23, 0x1f);
            break;
    }
}

void func_ov001_021855f8(void) {
    if (func_020cccc0() != 0) {
        func_ov001_021854f4(0x1b);
        func_02148950(1, 0, 0);
        func_ov001_021854d8(0x16);
        func_02148934(0);
    }
    func_ov001_021a11a4();
}

void func_ov001_021855cc(void) {
    switch (func_ov001_021a11c4()) {
        case 1:
            func_020ccc74(5, 0x1f);
            break;
        case 2:
            func_020ccc74(0, 0x1f);
            break;
    }
}

void func_ov001_02185598(void) {
    if (func_020cccc0() != 0) {
        func_ov001_021854f4(0xb);
        func_02148950(1, 0, 1);
        func_ov001_021854d8(8);
        func_02148934(0);
    }
    func_02026058();
}

void func_ov001_0218556c(void) {
    switch (AdvanceSelectCharacter()) {
        case 1:
            func_020ccc74(6, 0x1f);
            break;
        case 2:
            func_020ccc74(4, 0x1f);
            break;
    }
}

void func_ov001_02185538(void) {
    if (func_020cccc0() != 0) {
        func_ov001_021854f4(9);
        func_02148950(1, 0, 1);
        func_ov001_021854d8(8);
        func_02148934(0);
    }
    func_02027e78();
}

void func_ov001_0218550c(void) {
    switch (AdvanceSelectKart()) {
        case 1:
            func_020ccc74(7, 0x1f);
            break;
        case 2:
            func_020ccc74(5, 0x1f);
            break;
    }
}
