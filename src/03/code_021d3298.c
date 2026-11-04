#include "03/code_021d3298.h"
#include "03/unk_021da000.h"
#include "code_0214d018.h"
#include "code_0214f4a4.h"
#include "code_02148950.h"

void func_ov003_021d3298(void) {
    vu32 c;
    vu32 e;
    vu32 a;
    vu32 b;
    vu32 d;
    vu32 f;

    func_021492d8(0x1f3);
    a = 0;
    MemFillWordsByBlock(a, (void *) 0x6800000, 0x40000);
    b = 0;
    MemFillWordsByBlock(b, (void *) 0x6880000, 0x24000);
    func_02148dac();
    c = 0x200;
    MemFillWordsByBlock(c, (void *) 0x7000000, 0x400);
    d = 0;
    MemFillWordsByBlock(d, (void *) 0x5000000, 0x400);
    e = 0x200;
    MemFillWordsByBlock(e, (void *) 0x7000400, 0x400);
    f = 0;
    MemFillWordsByBlock(f, (void *) 0x5000400, 0x400);
}

void func_ov003_021d332c(void) {
    func_02148e6c();
    func_02148e58();
    func_02148d98();
    func_02148d84();
    func_ov003_021d3298();
    func_02149b20(data_ov003_021da2f8[0]);
    func_021499b4(data_ov003_021da2f8[1]);
    func_021498a0(data_ov003_021da2f8[2]);
    func_021497e8(data_ov003_021da2f8[3]);
    func_021495e4(data_ov003_021da2f8[4]);
    func_021494f0(data_ov003_021da2f8[5]);
    func_021493b0(data_ov003_021da2f8[6]);
    func_0214922c(data_ov003_021da2f8[7]);
    func_021491b0(data_ov003_021da2f8[8]);
    func_02149124(data_ov003_021da2f8[9]);
    func_02149098(data_ov003_021da2f8[10]);
    func_021492d8(data_ov003_021da2f8[12]);
    *(u16 *) 0x4000050 = 0;
    *(u16 *) 0x4001050 = 0;
    *(u32 *) 0x4000010 = 0;
    *(u32 *) 0x4000014 = 0;
    *(u32 *) 0x4000018 = 0;
    *(u32 *) 0x400001c = 0;
    *(u32 *) 0x4001010 = 0;
    *(u32 *) 0x4001014 = 0;
    *(u32 *) 0x4001018 = 0;
    *(u32 *) 0x400101c = 0;
    func_0214f72c(1);
}

void func_ov003_021d3408(void) {
    data_ov003_021da2f8[0] = func_02148e6c();
    data_ov003_021da2f8[1] = func_02148e58();
    data_ov003_021da2f8[2] = func_02148e34();
    data_ov003_021da2f8[3] = func_02148e10();
    data_ov003_021da2f8[4] = func_02148dfc();
    data_ov003_021da2f8[5] = func_02148de8();
    data_ov003_021da2f8[6] = func_02148dd4();
    data_ov003_021da2f8[7] = func_02148d98();
    data_ov003_021da2f8[8] = func_02148d84();
    data_ov003_021da2f8[9] = func_02148d5c();
    data_ov003_021da2f8[10] = func_02148d34();
    data_ov003_021da2f8[11] = func_02148dc0();
    data_ov003_021da2f8[12] = func_02148dac();
    func_021492f8(data_ov003_021da2f8[11]);
    func_ov003_021d3298();
}
