#include "code_0200cd1c.h"
#include "code_02148a58.h"
#include "code_0200fd1c.h"
#include "code_0214c778.h"
#include "Main/Unknown/code_0200c000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/unk_02180000.h"
#include "00/code_02188720.h"

// Zeroes the 13 halfwords at data_021802b0, the word at 0x4000240, the bytes at 0x4000244-0x4000246 and the halfword
// at 0x4000248.
void func_02148c20(void) {
    ((u16 *) data_021802b0)[0] = 0;
    ((u16 *) data_021802b0)[1] = 0;
    ((u16 *) data_021802b0)[2] = 0;
    ((u16 *) data_021802b0)[3] = 0;
    ((u16 *) data_021802b0)[4] = 0;
    ((u16 *) data_021802b0)[5] = 0;
    ((u16 *) data_021802b0)[6] = 0;
    ((u16 *) data_021802b0)[7] = 0;
    ((u16 *) data_021802b0)[8] = 0;
    ((u16 *) data_021802b0)[9] = 0;
    ((u16 *) data_021802b0)[10] = 0;
    ((u16 *) data_021802b0)[11] = 0;
    ((u16 *) data_021802b0)[12] = 0;
    *(vu32 *) 0x4000240 = 0;
    *(vu8 *) 0x4000244 = 0;
    *(vu8 *) 0x4000245 = 0;
    *(vu8 *) 0x4000246 = 0;
    *(vu16 *) 0x4000248 = 0;
}

// Updates the halfword at 0x4000304, calls func_02148c20, then calls func_0200cd28 until data_021802a8 is nonzero
// (calling func_0200fd1c when it returns -3). Zeroes 0x4000004 and 0x4000000, then passes 0 with the ranges
// 0x4000008 (size 0x60) and 0x4001000 (size 0x70) to func_0214cc04 when data_0216f074[0] is not -1 and to
// func_0214d018 otherwise, with the halfword at 0x400006c zeroed in between. Finally stores 0x100 in the halfwords
// at 0x4000020, 0x4000026, 0x4000030, 0x4000036 and the same offsets from 0x4001000.
void func_02148a88(void) {
    s32 r;

    *(vu16 *) 0x4000304 |= 0x8000;
    *(vu16 *) 0x4000304 = (*(vu16 *) 0x4000304 & ~0x20e) | 0x20e;
    *(vu16 *) 0x4000304 |= 0x1;
    func_02148c20();
    while (*(vu16 *) &data_021802a8 == 0) {
        r = func_0200cd28();
        if (r == -3) {
            func_0200fd1c();
        }
        *(vu16 *) &data_021802a8 = r;
    }
    *(vu16 *) 0x4000004 = 0;
    *(vu32 *) 0x4000000 = 0;
    if (data_0216f074[0] != -1) {
        func_0214cc04(data_0216f074[0], (void *) 0x4000008, 0, 0x60);
        *(vu16 *) 0x400006c = 0;
        func_0214cc04(data_0216f074[0], (void *) 0x4001000, 0, 0x70);
    } else {
        volatile u32 z0 = 0;
        volatile u32 z1;

        func_0214d018(z0, (void *) 0x4000008, 0x60);
        *(vu16 *) 0x400006c = 0;
        z1 = 0;
        func_0214d018(z1, (void *) 0x4001000, 0x70);
    }
    *(vu16 *) 0x4000020 = 0x100;
    *(vu16 *) 0x4000026 = 0x100;
    *(vu16 *) 0x4000030 = 0x100;
    *(vu16 *) 0x4000036 = 0x100;
    *(vu16 *) 0x4001020 = 0x100;
    *(vu16 *) 0x4001026 = 0x100;
    *(vu16 *) 0x4001030 = 0x100;
    *(vu16 *) 0x4001036 = 0x100;
}

// Sets (a != 0) or clears bit 3 of the halfword at 0x4000004 and returns its previous value (0 or 8).
u32 func_02148a58(s32 a) {
    u32 old;

    old = *(vu16 *) 0x4000004 & 0x8;
    if (a != 0) {
        *(vu16 *) 0x4000004 |= 0x8;
    } else {
        *(vu16 *) 0x4000004 &= ~0x8;
    }
    return old;
}
