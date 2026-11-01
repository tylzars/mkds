#include "Main/Unknown/code_020ec504.h"

void func_020ec504(int param_1) {
    u16 v1;
    *(u16 *) (param_1 + 2) = *(u16 *) (param_1 + 2) | (*(u16 *) &data_02159578);
    v1 = func_020d5344((int) *(short *) (param_1 + 100));
    *(u16 *) (param_1 + 100) = v1;
}
