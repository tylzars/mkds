#include "Main/Unknown/code_020f8148.h"

#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020f7c90.h"

#pragma thumb on

// non-matching: head byte reads: the original forms the address of the second byte as `adds r0, r5, #1` before `adds
// r5, r5, #2` and loads it afterwards; here the byte is read with the immediate offset (`ldrb r0, [r5, #1]`) before the
// pointer is advanced. Every other instruction matches.
u8 *func_020f8148(Unk0217bc6c *param_1, u8 *param_2) {
    u8 *p;
    s32 a;
    s32 b;
    s32 i;
    s32 j;
    u16(*tab)[0x12];

    p = param_2;
    a = p[0];
    b = p[1];
    p += 2;
    param_1->mUnk_00 = a;
    param_1->mUnk_04 = func_02036bec(func_020364e0(func_020364e8()), (a + 1) * 0x24);
    tab = param_1->mUnk_04;
    for (i = 0; i < b; i++) {
        for (j = 0; j < a; j++) {
            tab[j][i] = *p++;
        }
        tab[j][i] = 0xffff;
    }
    return p;
}

#pragma thumb off
