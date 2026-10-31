#include "01/code_02187074.h"

int func_ov001_02187074(int param_1, int param_2, int param_3) {
    int v1;
    if (param_3 < param_1) {
        v1 = param_3 + param_2;
        if (param_3 + param_2 >= param_1) {
            v1 = param_1;
        }
        return v1;
    }
    if (param_3 > param_1) {
        v1 = param_3 - param_2;
        if (param_3 - param_2 <= param_1) {
            v1 = param_1;
        }
        return v1;
    }
    return param_3;
}
