#include "Main/Unknown/code_0208ab00.h"
#include "ITCM/code_01ff8000.h"

void func_0208ab4c(u16 *colorPtr) {
    u32 color;
    u32 colorWithBit30;
    color = *colorPtr;
    func_01ff9048(0x33, (void *) ((u32) (&color)), 1);
    colorWithBit30 = *colorPtr | 0x40000000;
    func_01ff9048(0x33, (void *) ((u32) (&colorWithBit30)), 1);
}

void func_0208ab00(void) {
    u32 color;
    u32 colorWithBit30[1];
    color = (0x00007fffu);
    func_01ff9048(0x33, (void *) ((u32) (&color)), 1);
    colorWithBit30[0] = (0x40007fffu);
    func_01ff9048(0x33, colorWithBit30, 1);
}
