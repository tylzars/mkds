#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02077eb4.h"
#include "Main/Unknown/code_02017000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/unk_0217a000.h"

#include "code_020176c0.h"
#include "code_021488e8.h"

#pragma thumb on

void func_02077f48(u32 p0) {
    *(u32 *) ((u8 *) (u32) (((u32) data_0217ad08)) + 0 + (0x1d8u)) = p0;
}

void func_02077f0c(u16 *a, int b, u32 c) {
    u16 v1;
    int v2;
    int v3;
    v1 = *a;
    v3 = b - (u32) v1;
    if (v3 < 0) {
        v3 = 0xffff - v3;
    }
    v2 = MulFixed12(v3, c);
    *a = *a + v2;
    if (((*a + 100) - b) < 0) {
        *a = (u16) (*a + 100);
        return;
    }
    *a = v1;
}

#pragma thumb off

#pragma thumb on

Nclr *func_02077f00(void) {
    return data_usa_0217ace4;
}

#pragma thumb off

#pragma thumb on

void func_02077eb4(void *a, u32 *b) {
    u32 v1;
    u32 v2;
    v1 = ((u32) HeapAlloc(a, (u32) (((u32) 0x0000f000u))));
    v2 = (u32) ExpHeapCreate((void *) ((void *) v1), (u32) ((u32) (((u32) 0x0000f000u))), (u32) 0);
    b[1] = v2;
    *b = v1;
    b[4] = 0;
    b[3] = b[4];
    b[2] = b[3];
    b[7] = 0;
    b[6] = b[7];
    b[5] = b[6];
    b[10] = 0;
    b[9] = b[10];
    b[8] = b[9];
    b[0xb] = 0;
    *(u16 *) (b + 0xc) = 0;
}

#pragma thumb off
