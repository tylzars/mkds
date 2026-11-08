#include "03/code_021bf410.h"
#include "03/code_021c250c.h"
#include "03/unk_021da000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021d5000.h"

#include "03/unk_021d6000.h"
#include "code_0214b824.h"
#include "registers.h"

void func_ov003_021bf4d0(void) {
    *(u8 *) &data_ov003_021da10c = 0;
}

BOOL func_ov003_021bf43c(u32 index, s32 column, u32 value) {
    void *a;
    void *b;

    if (data_ov003_021da10c != 0) {
        return 0;
    }
    LoadFileToVram(data_ov003_021d697c, GXS_LoadBG0Scr);
    reg_G2S_DB_BG0OFS = 0x1920000;
    a = InitBgTextCanvas(1, 0);
    b = GetMessageEntryAndWriteDigit(gMessages, index, column, value);
    DrawCanvasTextRect(a, data_ov003_021d5efc[0], data_ov003_021d5efc[1], data_ov003_021d5efc[2],
                       data_ov003_021d5efc[3], 2, GetLanguageTextFlags(), b);
    RequestBgTextCanvasUpload(a);
    data_ov003_021da10c = 1;
    return 1;
}

BOOL func_ov003_021bf410(void) {
    if (data_ov003_021da10c == 0) {
        return 0;
    }
    ReleaseBgTextCanvasOfScreen(1);
    data_ov003_021da10c = 0;
    return 1;
}
