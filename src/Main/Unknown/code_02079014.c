#include "Main/Unknown/code_02079014.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_0207a14c.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_0207ae58.h"

#pragma thumb on

void func_02079078(void *a, void *b, void *c, Unk020136f0 *d, Unk020136f0 *e, void *f) {
    u32 v2;
    u32 v3;
    void *v1;
    v2 = (u32) func_02084d3c(b, d, e);
    func_020849c0(b, 3);
    func_0207a14c((Unk0201290c *) v2, (u32) 1);
    func_0208823c(0, c, b, 1, a, NULL);
    v1 = func_02013a4c(func_02013a30(f), 0);
    v3 = func_0207b8dc(2);
    func_020881b0(c, 0, v1, v3, a);
    func_02087f84(c, 0);
}

void func_02079038(void *a, Unk020136f0 *b, Unk020136f0 *c) {
    int v1;
    u32 v2;
    v1 = (s32) func_02084d3c(a, b, c);
    func_020849c0(a, 3);
    func_0207a14c((Unk0201290c *) v1, (u32) 1);
    v2 = func_02013754((const void *) (v1 + *(s32 *) (v1 + 8) + 4), (const u32 *) (&data_02155098));
    func_02013468((Unk0201290c *) v1, v2, (u32) 0);
}

void func_02079014(void *a, Unk020136f0 *b, Unk020136f0 *c) {
    u32 v1;
    v1 = (u32) func_02084d3c(a, b, c);
    func_020849c0(a, 3);
    func_0207a14c((Unk0201290c *) v1, (u32) 1);
}

#pragma thumb off
