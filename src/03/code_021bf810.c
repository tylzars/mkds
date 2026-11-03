#include "03/code_021bf810.h"
#include "03/code_021bf000.h"
#include "03/code_021b94b8.h"
#include "03/code_021cd4ac.h"
#include "03/code_021d1440.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf4dc.h"

#include "03/code_021d3488.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0200eddc.h"
#include "code_0214b824.h"
#include "03/code_021d1000.h"
#include "code_0214d018.h"
#include "03/code_021d27d8.h"

void func_ov003_021bf8b0(void) {
    func_ov003_021d2808(&data_ov003_021da154);
}

void func_ov003_021bf86c(int b) {
    void *a;

    a = func_ov003_021d14b8(func_ov003_021bf650(data_ov003_021d6b60[b]), NULL, 4);
    func_0214d0a8(a, data_ov003_021da154, 0xc0);
    func_ov003_021d1490(a);
    func_ov003_021d3544(1, func_ov003_021bf810, NULL, 0x78);
}

void func_ov003_021bf854(void) {
    u32 value0;
    value0 = (u32) func_ov003_021cdb6c();
    value0 = (value0) + 244u;
    value0 = (u32) * (const u8 *) ((value0) + 0u);
    value0 = (value0) + (5u);
    func_ov003_021bf86c(value0);
    return;
}

void func_ov003_021bf83c(void) {
    u32 value0;
    value0 = (u32) func_ov003_021cdb6c();
    value0 = (value0) + 244u;
    value0 = (u32) * (const u8 *) ((value0) + 0u);
    value0 = (value0) + (2u);
    func_ov003_021bf86c(value0);
    return;
}

void func_ov003_021bf810(u32 a) {
    func_0200ee74(data_ov003_021da154, 0xc0);
    func_0214bd6c(data_ov003_021da154, 0, 0xc0);
    func_ov003_021d34c8(1, a);
}
