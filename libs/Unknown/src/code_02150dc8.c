#include "code_02150808.h"
#include "code_02150dc8.h"
#include "code_02150e1c.h"
#include "Main/Unknown/code_02150000.h"
#include "Main/Unknown/code_0214d000.h"

u32 data_02180490;

u32 func_02150dc8(u32 v) {
    u32 old;

    old = data_02180490;
    data_02180490 = v;
    if (v != 0) {
        data_0216f26c = func_02150994;
    } else {
        data_0216f26c = func_02150e1c;
    }
    return old;
}
