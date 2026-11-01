#include "code_02148ca0.h"

#include "Main/Unknown/code_02148cd0.h"
#include "Main/Unknown/code_02148d24.h"

u32 func_02148d24(void) {
    u32 value0;
    value0 = (u32) &data_021802b0;
    value0 = (u32) * (const u16 *) ((value0) + (8));
    return value0;
}

u32 func_02148cd0(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 compareLeft0;
    u32 compareRight0;
    u32 compareLeft1;
    u32 compareRight1;
    u32 compareLeft2;
    u32 compareRight2;
    u32 compareLeft3;
    u32 compareRight3;
    u32 compareLeft4;
    u32 compareRight4;
    u32 compareLeft5;
    u32 compareRight5;
    u32 compareLeft6;
    u32 compareRight6;
    u32 compareLeft7;
    u32 compareRight7;
    u32 compareLeft8;
    u32 compareRight8;
    value2 = 0u;
    value1 = (value0) & (1u);
    compareLeft0 = value1;
    compareRight0 = 0u;
    if (compareLeft0 != compareRight0) {
        value2 = (value2) + (0x20000u);
    }
    value1 = (value0) & (2u);
    compareLeft1 = value1;
    compareRight1 = 0u;
    if (compareLeft1 != compareRight1) {
        value2 = (value2) + (0x20000u);
    }
    value1 = (value0) & (4u);
    compareLeft2 = value1;
    compareRight2 = 0u;
    if (compareLeft2 != compareRight2) {
        value2 = (value2) + (0x20000u);
    }
    value1 = (value0) & (8u);
    compareLeft3 = value1;
    compareRight3 = 0u;
    if (compareLeft3 != compareRight3) {
        value2 = (value2) + (0x20000u);
    }
    value1 = (value0) & (0x10u);
    compareLeft4 = value1;
    compareRight4 = 0u;
    if (compareLeft4 != compareRight4) {
        value2 = (value2) + (0x10000u);
    }
    value1 = (value0) & (0x20u);
    compareLeft5 = value1;
    compareRight5 = 0u;
    if (compareLeft5 != compareRight5) {
        value2 = (value2) + (0x4000u);
    }
    value1 = (value0) & (0x40u);
    compareLeft6 = value1;
    compareRight6 = 0u;
    if (compareLeft6 != compareRight6) {
        value2 = (value2) + (0x4000u);
    }
    value1 = (value0) & (0x80u);
    compareLeft7 = value1;
    compareRight7 = 0u;
    if (compareLeft7 != compareRight7) {
        value2 = (value2) + (0x8000u);
    }
    value0 = (value0) & (0x100u);
    compareLeft8 = value0;
    compareRight8 = 0u;
    if (compareLeft8 != compareRight8) {
        value2 = (value2) + (0x4000u);
    }
    value0 = value2;
    return value0;
}

u32 func_02148cb8(void) {
    u32 value0;
    u32 value12;
    value0 = (u32) &data_021802b0;
    value12 = (u32) &func_02148cd0;
    value0 = (u32) * (const u16 *) ((value0) + (4));
    value0 = (u32) func_02148cd0(value0);
    return value0;
}

u32 func_02148ca0(void) {
    u32 value0;
    u32 value12;
    value0 = (u32) &data_021802b0;
    value12 = (u32) &func_02148cd0;
    value0 = (u32) * (const u16 *) ((value0) + (20));
    value0 = (u32) func_02148cd0(value0);
    return value0;
}
