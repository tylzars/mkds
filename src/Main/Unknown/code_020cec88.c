#include "Main/Unknown/code_020cec88.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_02032000.h"

#pragma optimize_for_size on
#pragma thumb on
void func_020cec88(void) {
    switch (func_02032280()) {
        case 1:
            switch (func_02029930()->mUnk_c8) {
                case 3:
                    func_020ccc74(8, 0x1f);
                    break;
                case 2:
                    func_020ccc74(0xf, 0x1f);
                    break;
            }
            break;
        case 2:
            func_020ccc74(0, 0x1f);
            break;
        case 3:
            func_020ccc74(0x1b, 0x1f);
            break;
    }
}
#pragma thumb off
