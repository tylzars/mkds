#include "03/code_021c2b28.h"

#include "03/unk_021da000.h"
#include "03/code_021d1c18.h"
#include "03/code_021bf410.h"
#include "03/code_021bf4dc.h"
#include "03/code_021bf698.h"
#include "03/code_021c209c.h"
#include "03/code_021c2530.h"
#include "03/code_021c2afc.h"
#include "03/code_021cb000.h"
#include "code_0201ec30.h"
#include "Main/Unknown/code_02151718.h"
#include "03/code_021cd2e0.h"
#include "03/code_021d1000.h"
#include "03/code_021d254c.h"
#include "code_0214b824.h"
#include "03/code_021bf8c0.h"
#include "registers.h"

void func_ov003_021c2b28(void) {
    func_ov003_021cdb90();
    func_ov003_021c25b4();
    InitSelectionObjects();
    InitHlScr();
    func_ov003_021bf4d0();
    if (func_ov003_021c20d0() == 1 && func_ov003_021c20a8(2) != 0) {
        data_ov003_021da19c = func_ov003_021c2564(data_ov003_021d6eb8);
    } else {
        data_ov003_021da19c = func_ov003_021c2564(data_ov003_021d6ea0[func_ov003_021c20d0()]);
    }
    func_ov003_021d1cb0(1, BuildFilePathWithLanguage(data_ov003_021d6ec8));
    func_ov003_021d1cb0(0, BuildFilePathWithLanguage(data_ov003_021d6edc));
    LoadFileToVram(data_ov003_021d6ef0, GXS_LoadBG1Char);
    LoadFileToVram(data_ov003_021d6f04, GXS_LoadBGPltt);
    LoadFileToVram(data_ov003_021d6f18, GXS_LoadOBJ);
    LoadFileToVram(data_ov003_021d6f30, GXS_LoadOBJPltt);
    LoadFileToVram(data_ov003_021d6f48, GX_LoadBG2Char);
    LoadFileToVram(data_ov003_021d6f60, GX_LoadBGPltt);
    LoadFileToVram(data_ov003_021d6f78, GX_LoadOBJ);
    LoadFileToVram(data_ov003_021d6f90, GX_LoadOBJPltt);
    switch (func_ov003_021c20c0()) {
        case 0:
            LoadFileToVram(data_ov003_021d6fa8, GXS_LoadBG1Scr);
            break;
        case 1:
            LoadFileToVram(data_ov003_021d6fbc, GXS_LoadBG1Scr);
            break;
    }
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 3;
    func_ov003_021d2784(1, 2);
    func_ov003_021d2784(0, 2);
    func_ov003_021c212c(func_ov003_021c2afc);
}
