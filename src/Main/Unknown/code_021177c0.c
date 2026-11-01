#include "Main/Unknown/code_021177c0.h"
#include "Main/Unknown/code_02118000.h"
#include "Main/Unknown/code_021185ec.h"
#include "Main/Unknown/code_02117db0.h"
#include "Main/Unknown/code_02118148.h"
#include "Main/Unknown/code_02127000.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/unk_0217d000.h"
#include "00/code_02182fdc.h"

#pragma thumb on

void func_021177c0(void) {
    s32 a;

    func_02118414();
    if (func_021277ac() != 0) {
        a = func_02127794();
        switch (a) {
            case 0:
                func_021185ec();
                data_0217d360->mUnk_88 = 1;
                func_02118024();
                func_021282c8();
                break;
            case -1:
            case 1:
                func_021181b8();
                break;
        }
    }
}

#pragma thumb off
