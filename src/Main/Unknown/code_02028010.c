#include "Main/Unknown/code_02028010.h"
#include "registers.h"

void func_02028010(u32 a) {
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | a;
}

void func_0202802c(u32 a, u32 b) {
    reg_G2S_DB_BG3OFS = (a & 0x1ff) | ((b << 16) & 0x1ff0000);
}
