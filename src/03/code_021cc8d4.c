#include "03/code_021cc8d4.h"
#include "03/code_021d3000.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0214b824.h"

#include "03/code_021d3488.h"
#include "03/unk_021da000.h"
#include "code_0214cfe4.h"
#include "03/code_021d27d8.h"
#include "code_0214d018.h"

void func_ov003_021cca30(const void *b) {
    Unk021da25c *a = func_ov003_021d283c(0x608, 4);
    data_ov003_021da25c = a;
    func_0214d0a8(b, a->mUnk_004, 0x600);
    data_ov003_021da25c->mUnk_000 = func_ov003_021d3544(1, func_ov003_021cc97c, 0, 0x78);
}

void func_ov003_021cca10(void) {
    func_ov003_021d34c0(1, *(u32 *) ((u8 *) data_ov003_021da25c + 0x0));
    func_ov003_021d2808(&data_ov003_021da25c);
}

void func_ov003_021cc9fc(void) {
    data_ov003_021da25c->mUnk_604 = 1;
}

void func_ov003_021cc9c0(int a, int b, int c, int d) {
    int v1;
    int v2;
    v1 = (int) data_ov003_021da25c + 4 + b * 2;
    v2 = 0;
    if (d > 0) {
        do {
            func_0214cffc((const void *) a, (void *) v1, (u32) (c << 1));
            v2 = v2 + 1;
            a = a + 0x40;
            v1 = v1 + 0x40;
        } while (v2 < d);
    }
}

void func_ov003_021cc97c(void) {
    if (data_ov003_021da25c->mUnk_604 != 0) {
        func_0200ee74((const void *) data_ov003_021da25c->mUnk_004, (int) (((u32) 0x00000600u)));
        func_0214bc9c((const void *) data_ov003_021da25c->mUnk_004, 0, (u32) (((u32) 0x00000600u)));
        data_ov003_021da25c->mUnk_604 = 0;
    }
}

void func_ov003_021cc948(u8 *a, u32 b, u32 c) {
    ((u8 **) data_ov003_021da260)[0] = a + (b << 5);
    ((u8 **) data_ov003_021da260)[1] = (u8 *) 0x5000000 + (c << 5);
    func_ov003_021d3544(1, func_ov003_021cc924, 0, 0x78);
}

void func_ov003_021cc924(u32 a) {
    func_0214cffc(((const void **) data_ov003_021da260)[0], ((void **) data_ov003_021da260)[1], 0x20);
    func_ov003_021d34c8(1, a);
}

void func_ov003_021cc900(u32 a) {
    *(u32 *) &data_ov003_021da260 = a;
    func_ov003_021d3544((u32) 1, &func_ov003_021cc8d4, 0, (u32) 0x78);
}

void func_ov003_021cc8d4(u32 a) {
    func_0214cffc((const void *) ((*(u32 *) &data_ov003_021da260)), (void *) (((u32) 0x05000000u)),
                  (u32) (((u32) 0x00000200u)));
    func_ov003_021d34c8(1, a);
}
