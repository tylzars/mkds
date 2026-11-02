#include "Main/Unknown/code_0205a548.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f830c.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_0214d000.h"
#include "00/code_0219bb50.h"

// non-matching: 0x6c bytes, original 0x68; 22 lines differ; first: original `push {r4, lr}`, ours `stmfd sp!, {lr}`
void func_0205a548(s32 a, s32 b, s32 c) {
    Unk0217aa14_104 *e;

    e = &data_0217aa14->mUnk_104[a];
    e->mUnk_68 = b;
    e->mUnk_6c = b;
    func_020f40dc(&data_027e00c8[(u16) data_0217aa18->mUnk_06[a]].mUnk_030, b, c);
}

void func_0205a5b0(u32 a) {
    Unk0217aa14_104_68 *e;

    e = &data_0217aa14->mUnk_104[a].mUnk_68_view;
    if (e->mUnk_0c != 0) {
        return;
    }
    e->mUnk_04 = 0x13;
    func_020f4718(&data_027e00c8[(u16) data_0217aa18->mUnk_06[a]].mUnk_030);
}

s32 func_0205a630(s32 a) {
    BOOL r;
    s32 t;

    t = data_0217aa14->mUnk_104[a].mUnk_6c;
    r = FALSE;
    if (func_020efd84(&data_027e00c8[(u8) data_0217aa18->mUnk_06[a]], t) != 0) {
        data_0217aa14->mUnk_104[a].mUnk_6c = 0x13;
        r = TRUE;
    }
    return r;
}

// non-matching: 0x5c bytes, original 0x68; 27 lines differ; first: original `push {r4, r5, lr}`, ours `push {r4, lr}`
void func_0205a6b4(void) {
    u16 i;
    Unk0217aa14_104 *e;

    for (i = 0; i < 4;) {
        e = &data_0217aa14->mUnk_104[i];
        i++;
        e->mUnk_68 = 0x13;
        e->mUnk_6c = 0x13;
        e->mUnk_70 = 0;
        e->mUnk_74 = 0;
        e->mUnk_78 = 0x13;
        e->mUnk_7c = 0;
    }
}

void func_0205a71c(s32 a) {
    func_020f86c4(&data_027e00c8[(u8) data_0217aa18->mUnk_06[a]]);
}

// non-matching: 0x58 bytes, original 0x5c; 20 lines differ; first: original `mov r1, #136`, ours `ldr r2, [pc, #64]`
void func_0205a750(s32 a) {
    Unk0217aa14_104 *e;

    e = &data_0217aa14->mUnk_104[func_ov000_0219bb50()];
    e->mUnk_76 = 0;
    e->mUnk_74 = 2;
    e->mUnk_68 = a;
    e->mUnk_70 = data_0217aa14->mUnk_728 + 0x78;
    e->mUnk_6c = 0x13;
}

void func_0205a7ac(s32 a) {
    Unk0217aa14_754_04 *p = (void *) &data_0217aa14->mUnk_754->mUnk_04;
    func_0214d168(&p->mUnk_20[a], 0, 2);
}

void func_0205a7dc(s32 a, u16 b, s32 c, s32 d) {
    Unk0217aa14_754_04_20 *e;

    e = &((Unk0217aa14_754_04 *) (void *) &data_0217aa14->mUnk_754->mUnk_04)->mUnk_20[a];
    e->mUnk_00_0 = b;
    e->mUnk_00_7 = c;
    e->mUnk_00_12 = d;
}

void func_0205a858(u32 a, u32 b, void *c, u8 d) {
    Unk0217aa14_324 *e;
    u16 i;

    for (i = 0; i < 16; i++) {
        e = &data_0217aa14->mUnk_324[i];
        if (e->mUnk_08 == 0) {
            goto found;
        }
    }
    e = NULL;
found:
    e->mUnk_09 = a;
    e->mUnk_0a = b;
    e->mUnk_08 = 1;
    e->mUnk_00 = data_0217aa14->mUnk_728 + 0x28;
    func_0214d168(e->mUnk_04, 0, 20);
    if (d == 0) {
        e->mUnk_0b = 0;
        return;
    }
    func_0214d1fc(c, e->mUnk_04, d);
    e->mUnk_0b = d;
}
