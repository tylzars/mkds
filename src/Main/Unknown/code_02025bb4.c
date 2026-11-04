#include "Main/Unknown/code_02025bb4.h"
#include "code_0201ea30.h"
#include "code_0201ea58.h"

#pragma thumb on

void func_02025c94(int id, int x, int y, void *graphics) {
    short *entry = (func_0201ea30((Unk0201ea30 *) graphics, id));
    entry[0] = (entry[0] & 0xfffff000U) | (x & 0xfff);
    entry[1] = (entry[1] & 0xfffff000U) | (y & 0xfff);
}

void func_02025c6c(u32 a, u32 b, Unk0201ea30 *c) {
    u16 *v1;
    u16 *v2;
    v1 = func_0201ea30(c, a);
    v2 = func_0201ea30(c, b);
    *v1 = *v2;
    v1[1] = v2[1];
}

void func_02025c48(u32 a, u32 b, Unk0201ea30 *c) {
    int v1;
    int v2;
    v1 = (s32) func_0201ea30(c, a);
    v2 = (s32) func_0201ea30(c, b);
    *(u32 *) (v1 + 4) = *(u32 *) (v2 + 4);
}

void func_02025c1c(u32 a, void *b, void *c) {
    u8 *d = b;
    short *v1;
    v1 = func_0201ea30(c, a);
    *(u32 *) (d + 8) = 1;
    *(s16 *) (d + 0xc) = ((*v1 << 0x14) >> 0x14);
    *(s16 *) (d + 0xe) = ((v1[1] << 0x14) >> 0x14);
}

void func_02025bf0(u32 a, void *b, void *c) {
    u8 *d = b;
    short *v1;
    v1 = func_0201ea58(c, a);
    *(u32 *) (d + 8) = 1;
    *(s16 *) (d + 0xc) = ((*v1 << 0x14) >> 0x14);
    *(s16 *) (d + 0xe) = ((v1[1] << 0x14) >> 0x14);
}

void func_02025bb4(int id, int x, int y, void *graphics) {
    short *entry = (s16 *) RectTableGetEntry(graphics, id);
    entry[0] = (entry[0] & 0xfffff000U) | (x & 0xfff);
    entry[1] = (entry[1] & 0xfffff000U) | (y & 0xfff);
}

#pragma thumb off
