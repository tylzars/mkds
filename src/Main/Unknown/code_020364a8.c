#include "Main/Unknown/code_020364a8.h"
#include "registers.h"

void func_020364a8(int a, int b, int c, int d, int e) {
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | (a << 14) | (b << 7) | (c << 8) | (d << 2) | (e << 13);
}
