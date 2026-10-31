#include "03/code_021c7050.h"

void func_ov003_021c7050(void) {
    int v1;
    int v2;
    int v3;
    int v4;
    u8 v5;
    u8 v6;
    v1 = 0;
    v4 = 0;
    do {
        v2 = (int) data_ov003_021da1fc + 8 + v4;
        v3 = 0;
        do {
            v6 = *(s8 *) (v2 + v3);
            if (((v6 != '0') && (v6 != ' ')) && (v6 != 0)) {
                break;
            }
            if (v3 == 2) {
                v5 = 0x30;
            } else {
                v5 = 0x20;
            }
            *(u8 *) (v2 + v3) = v5;
            v3 = v3 + 1;
        } while (v3 < 3);
        v4 = v4 + 3;
        v1 = v1 + 1;
        if (4 <= v1) {
            func_ov003_021c71a0();
            return;
        }
    } while (1);
}
