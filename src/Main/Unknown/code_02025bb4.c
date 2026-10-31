#include "Main/Unknown/code_02025bb4.h"
#include "code_0201ea30.h"
#include "code_0201ea58.h"

#pragma thumb on

void func_02025c94(int id, int x, int y, void *graphics) {
    short *entry = ((short *) func_0201ea30((Unk0201ea30 *) graphics, id));
    entry[0] = (entry[0] & 0xfffff000U) | (x & 0xfff);
    entry[1] = (entry[1] & 0xfffff000U) | (y & 0xfff);
}

void func_02025c6c(u32 param_1, u32 param_2, Unk0201ea30 *param_3) {
    u16 *v1;
    u16 *v2;
    v1 = (u16 *) func_0201ea30(param_3, (int) param_1);
    v2 = (u16 *) func_0201ea30(param_3, (int) param_2);
    *v1 = *v2;
    v1[1] = v2[1];
}

void func_02025c48(u32 param_1, u32 param_2, Unk0201ea30 *param_3) {
    int v1;
    int v2;
    v1 = (int) func_0201ea30(param_3, (int) param_1);
    v2 = (int) func_0201ea30(param_3, (int) param_2);
    *(u32 *) (v1 + 4) = *(u32 *) (v2 + 4);
}

void func_02025c1c(u32 param_1, int param_2, u32 param_3) {
    short *v1;
    v1 = (short *) func_0201ea30((Unk0201ea30 *) param_3, (int) param_1);
    *(u32 *) (param_2 + 8) = 1;
    *(short *) (param_2 + 0xc) = (short) (((int) *v1 << 0x14) >> 0x14);
    *(short *) (param_2 + 0xe) = (short) (((int) v1[1] << 0x14) >> 0x14);
}

void func_02025bf0(u32 param_1, int param_2, u32 param_3) {
    short *v1;
    v1 = (short *) func_0201ea58((Unk0201ea30 *) param_3, (int) param_1);
    *(u32 *) (param_2 + 8) = 1;
    *(short *) (param_2 + 0xc) = (short) (((int) *v1 << 0x14) >> 0x14);
    *(short *) (param_2 + 0xe) = (short) (((int) v1[1] << 0x14) >> 0x14);
}

void func_02025bb4(int id, int x, int y, void *graphics) {
    short *entry = (short *) func_0201eb54(graphics, id);
    entry[0] = (entry[0] & 0xfffff000U) | (x & 0xfff);
    entry[1] = (entry[1] & 0xfffff000U) | (y & 0xfff);
}

#pragma thumb off
