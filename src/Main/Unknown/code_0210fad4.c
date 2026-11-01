#include "Main/Unknown/code_0210fad4.h"
#include "Main/Unknown/code_0210fb88.h"
#include "Main/Unknown/unk_0217d000.h"

void func_0210faf4(void) {
    func_0210fb88(&data_0217d244, &data_0217d07c);
}

u32 func_0210fad4(void) {
    if ((data_0217d244.mUnk_08 >> 2) & 1) {
        return 1;
    }
    return 0;
}
