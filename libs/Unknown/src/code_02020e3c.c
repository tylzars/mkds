#include "code_02020e3c.h"

#include "code_0200e77c.h"
#include "code_0200edc0.h"
#include "code_02020eb0.h"
#include "code_02021784.h"

u32 data_021732ac;
Unk0200edc0 data_021732b0;

void func_02020e64(void) {
    if (data_021732ac != 0) {
        return;
    }
    data_021732ac = 1;
    func_0200edc0(&data_021732b0);
    func_020215bc();
    func_02021784();
}

void func_02020e50(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_0200ed34;
    value0 = (u32) &data_021732b0;
    func_0200ed34((void *) value0);
}

void func_02020e3c(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &func_0200ecc4;
    value0 = (u32) &data_021732b0;
    func_0200ecc4((void *) value0);
}
