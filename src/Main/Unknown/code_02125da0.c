#include "Main/Unknown/code_02125da0.h"

#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_021274ec.h"
#include "Main/Unknown/code_02128000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "01/code_02198854.h"

#pragma thumb on

void func_02125de0(void *a, void *b) {
    Unk021274ec t;

    data_0217d3ec = func_02036bec(a, 0x814);
    data_0217d3ec->mUnk_810 = 0x5800;
    data_0217d3ec->mUnk_00 = 0;
    data_0217d3ec->mUnk_04 = 0;
    data_0217d3ec->mUnk_08 = 0;
    if (((Unk02125de0Arg *) b)->mUnk_00 != 0) {
        t.mUnk_00 = (u32) ((Unk02125de0Arg *) b)->mUnk_04;
        t.mUnk_04 = ((Unk02125de0Arg *) b)->mUnk_08;
        t.mUnk_08 = ((Unk02125de0Arg *) b)->mUnk_0c;
        t.mUnk_0c = ((Unk02125de0Arg *) b)->mUnk_10;
        t.mUnk_10 = data_0217d3ec->mUnk_810;
        data_0217d3ec->mUnk_00 = 1;
        data_0217d3ec->mUnk_810 = func_021274ec(a, &t);
    }
    if (((Unk02125de0Arg *) b)->mUnk_14 != 0) {
        data_0217d3ec->mUnk_04 = 1;
        data_0217d3ec->mUnk_810 = func_02128058(a, ((Unk02125de0Arg *) b)->mUnk_18, data_0217d3ec->mUnk_810);
    }
    if (((Unk02125de0Arg *) b)->mUnk_1c != 0) {
        data_0217d3ec->mUnk_08 = 1;
        data_0217d3ec->mUnk_810 = func_021287cc(a, data_0217d3ec->mUnk_810);
    }
    if (((Unk02125de0Arg *) b)->mUnk_20 != 0) {
        data_0217d3ec->mUnk_0c = ((Unk02125de0Arg *) b)->mUnk_24;
        func_02125ba4();
        data_0217d3ec->mUnk_810 = func_02125960(data_0217d3ec->mUnk_810);
    }
}

#pragma thumb off

#pragma thumb on

void func_02125da0(void) {
    if (data_0217d3ec->mUnk_00 != 0) {
        func_021274e0();
    }
    if (data_0217d3ec->mUnk_04 != 0) {
        func_0212804c();
    }
    if (data_0217d3ec->mUnk_08 != 0) {
        func_021287c0();
    }
    *&data_0217d3ec = NULL;
}

#pragma thumb off
