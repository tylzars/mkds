#include "Main/Unknown/code_02151708.h"

#include "Main/Unknown/code_02151718.h"
#include "Main/Unknown/unk_02180000.h"
#include "code_020205b0.h"
#include "code_0214d018.h"
#include "code_021510a4.h"

#pragma thumb on

u32 func_02151830(u16 *a) {
    int v1;
    v1 = func_0215122c((u32) 0x20, (u32) 0x20, (void *) a);
    if (v1 == 0) {
        return 0;
    }
    *(s32 *) &data_0218049c = *a * 8 - 0x400;
    return 1;
}

u32 func_02151804(u32 a) {
    int v1;
    v1 = func_0215122c((u32) ((*(u32 *) &data_0218049c)), (u32) (((u32) 0x00000400u)), (void *) a);
    if (v1 != 0) {
        return 1;
    }
    return 0;
}

u32 func_02151794(int a, int *b, void *c) {
    int v1;
    int v2;
    int v3;
    int *v4;
    int v5;
    v2 = 0x100;
    v3 = *(s32 *) &data_0218049c;
    v5 = 0;
    v4 = b;
    do {
        if (*v4 != 0) {
            do {
                func_021511d8(v3, v2, (void *) a);
                v1 = func_0215119c((const u8 *) a, v3, v2, c);
            } while (v1 == 0);
        }
        v4 = v4 + 1;
        a = a + v2;
        v5 = v5 + 1;
        v3 = v3 + v2;
    } while (v5 < 4);
    v2 = func_02151154();
    if (v2 != 0) {
        return 1;
    }
    return 0;
}

u32 func_02151718(int a) {
    int v1;
    int v2;
    int v3;
    int v4;
    int v5;
    u16 v6;
    v4 = 0x100;
    v2 = *(s32 *) &data_0218049c;
    v1 = 0;
    v3 = a;
    do {
        v6 = func_020205e8((const u16 *) (a + 0x500), (const u8 *) v3, 0xfe);
        *(u16 *) (v3 + 0xfe) = v6;
        do {
            func_021511d8(v2, v4, (void *) v3);
            v5 = func_0215119c((const u8 *) v3, v2, v4, (const u8 *) (a + 0x400));
        } while (v5 == 0);
        v3 = v3 + v4;
        v1 = v1 + 1;
        v2 = v2 + v4;
    } while (v1 < 4);
    v4 = func_02151154();
    if (v4 != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on
void func_02151708(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value3;
    value1 = (u32) &data_021804a0;
    value2 = 14u;
    value3 = (u32) &func_0214d1fc;
    func_0214d1fc((const void *) value0, (void *) value1, value2);
}
#pragma thumb off
