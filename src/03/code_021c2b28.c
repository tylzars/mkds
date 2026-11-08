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
    InitMessagesPool();
    InitSelectionObjects();
    InitHlScr();
    func_ov003_021bf4d0();
    if (GetLanguageIndex() == 1 && func_ov003_021c20a8(2) != 0) {
        gMessages = LoadMessages(gUsaBmgName);
    } else {
        gMessages = LoadMessages(gLanguageBmgNames[GetLanguageIndex()]);
    }
    func_ov003_021d1cb0(1, BuildFilePathWithLanguage(gJtMainNceName));
    func_ov003_021d1cb0(0, BuildFilePathWithLanguage(gJbMainNceName));
    LoadFileToVram(gJtBgMainNcgName, GXS_LoadBG1Char);
    LoadFileToVram(gJtBgMainNclName, GXS_LoadBGPltt);
    LoadFileToVram(gJtObjMainNcgName, GXS_LoadOBJ);
    LoadFileToVram(gXtObjMainNclName, GXS_LoadOBJPltt);
    LoadFileToVram(gJbBgStep1NcgName, GX_LoadBG2Char);
    LoadFileToVram(gJbBgStep1NclName, GX_LoadBGPltt);
    LoadFileToVram(gJbObjMainNcgName, GX_LoadOBJ);
    LoadFileToVram(gYbObjMainNclName, GX_LoadOBJPltt);
    switch (GetMode()) {
        case 0:
            LoadFileToVram(gJtTopNscName, GXS_LoadBG1Scr);
            break;
        case 1:
            LoadFileToVram(gJtStep1NscName, GXS_LoadBG1Scr);
            break;
    }
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 3;
    CombineDispcntBits(1, 2);
    CombineDispcntBits(0, 2);
    SetUpdateFunction(func_ov003_021c2afc);
}
