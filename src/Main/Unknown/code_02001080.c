#include "Main/Unknown/code_02001080.h"
#include "Main/Unknown/code_02001000.h"
#include "Main/Unknown/code_02001290.h"
#include "Main/Unknown/code_02001294.h"
#include "Main/Unknown/code_020019ac.h"
#include "Main/Unknown/code_020019b0.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02126230.h"

// Initialized data kept in .text between two functions (as in the original).
#pragma define_section MAIN_TEXT ".text"                                                                               \
                                 ".bss" abs32 RWX
#pragma section MAIN_TEXT begin

UnkFunc *data_02001080[24] = {
    func_02001a44, func_020019b0, func_020019ac, func_02001878, func_02001830, func_020017cc,
    func_02001770, func_020016ac, func_0200165c, func_020015f0, func_02001598, func_02001500,
    func_0200148c, func_02001350, func_02001300, func_02001294, func_02001290, func_02001238,
    func_020011f0, func_0200118c, func_02001144, func_020010e0, NULL,          NULL,
};

#pragma section MAIN_TEXT end

void func_02001238(void) {
    Unk021a99c0_18 *v1;
    if (data_usa_02174e54 == 3) {
        v1 = &data_usa_ov001_021a99c0->mUnk_18;
        v1->mUnk_10 = 9;
        v1->mUnk_12 = 1;
        return;
    }
    v1 = &data_usa_ov001_021a99c0->mUnk_18;
    v1->mUnk_10 = 11;
    v1->mUnk_12 = 1;
}

void func_020011f0(void) {
    void *v1;
    v1 = GetBmgEntry(data_usa_ov001_021a99c0->mUnk_38, 137);
    SetupTxtSystemSubTextButton(v1, GetBmgEntry(data_usa_ov001_021a99c0->mUnk_38, 6));
}

void func_0200118c(void) {
    Unk021a99c0_18 *v1;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() == 0) {
        return;
    }
    v1 = &data_usa_ov001_021a99c0->mUnk_18;
    v1->mUnk_10 = 10;
    v1->mUnk_12 = 1;
}

void func_02001144(void) {
    void *v1;
    v1 = GetBmgEntry(data_usa_ov001_021a99c0->mUnk_38, 138);
    SetupTxtSystemSubTextButton(v1, GetBmgEntry(data_usa_ov001_021a99c0->mUnk_38, 4));
}

void func_020010e0(void) {
    Unk021a99c0_18 *v1;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() == 0) {
        return;
    }
    v1 = &data_usa_ov001_021a99c0->mUnk_18;
    v1->mUnk_10 = 11;
    v1->mUnk_12 = 1;
}
