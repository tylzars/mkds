#include "00/code_02199a0c.h"

u32 func_ov000_02199a0c(int param_1, int param_2, u32 param_3, u32 param_4) {
    int v1;
    *(short *) (param_1 + 0x66) = *(u16 *) (param_1 + 0x66) + 1;
    if (param_2 == 0) {
        v1 = func_ov000_02199dd0(param_1, param_3, param_4);
        if (v1 == 0) {
            return 0;
        }
    } else if (param_2 == 1) {
        v1 = func_ov000_02199d4c(param_1, param_3, (int) param_4);
        if (v1 == 0) {
            return 0;
        }
    } else if (param_2 == 2) {
        v1 = func_ov000_02199c98(param_1, (int) param_3, (int) param_4);
        if (v1 == 0) {
            return 0;
        }
    } else if (param_2 == 3) {
        v1 = func_ov000_02199bb4((u32 *) ((u32 *) (u32) param_1), (int) param_3, (int) param_4);
        if (v1 == 0) {
            return 0;
        }
    } else if (param_2 == 4) {
        v1 = func_ov000_02199b70((Unk02197fe8 *) param_1);
        if (v1 == 0) {
            return 0;
        }
    } else if (param_2 == 5) {
        v1 = func_ov000_02199b14(param_1, param_3, param_4);
        if (v1 == 0) {
            return 0;
        }
    } else if ((param_2 == 6) && (v1 = func_ov000_02199ad8((Unk02197fe8 *) param_1), v1 == 0)) {
        return 0;
    }
    return 1;
}
