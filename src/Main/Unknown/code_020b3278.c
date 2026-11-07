#include "Main/Unknown/code_020b3278.h"
#include "Main/Unknown/code_020b252c.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_020b1de4.h"

#pragma thumb on
#pragma optimize_for_size on
void func_020b3278(void) {
    if (func_020b252c() == 5) {
        func_02105b64(4);
    } else {
        switch (gChoisesS->mSelectedValue) {
            case 0:
            case 8:
                func_02105b64(0);
                break;
            case 1:
            case 3:
                func_02105b64(1);
                break;
            case 2:
            case 7:
            case 10:
                func_02105b64(5);
                break;
            case 4:
            case 5:
            case 6:
                func_02105b64(2);
                break;
            case 9:
                func_02105b64(3);
                break;
        }
    }
}
#pragma thumb off
