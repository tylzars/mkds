#include "01/code_021a2398.h"
#include "01/code_021a2408.h"
#include "01/code_021a2a40.h"
#include "01/code_021a401c.h"
#include "01/code_021a5140.h"
#include "01/code_02185000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_020ac000.h"

void func_ov001_021a23f4(void) {
    InitEmblem();
    func_ov001_021a401c();
}

BOOL func_ov001_021a23c8(void) {
    func_ov001_021a2a40();
    if (gEmblem->mUnk_1090 == 0xc) {
        return TRUE;
    }
    return FALSE;
}

void func_ov001_021a23c0(void) {
    func_ov001_021a2408();
}

u16 *func_ov001_021a23ac(void) {
    return gEmblem->mEmblemSBNclr->mUnk_0c;
}

u8 *func_ov001_021a2398(void) {
    return gEmblem->mUnk_087c;
}
