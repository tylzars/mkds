#include "Main/Unknown/code_020d0f78.h"
#include "Main/Unknown/code_02048000.h"
#include "code_02135014.h"
#include "Main/Unknown/unk_0216a000.h"

#pragma opt_propagation off

#pragma thumb on
void func_020d10fc(void) {
    gCupPicture = 0;
}

void LoadCupPictureNclr(void) {
    char buf[0x100];
    s32 i;
    s32 a;
    s32 b;

    i = gCupPicture->mUnk_0c;
    a = data_0216aea8[i * 2];
    b = data_0216aeac[i * 2];
    snprintf(buf, 0x100, "%s%s%02d%s", gCupPicturePrefix, a == 0 ? gCupPictureNitro : gCupPictureRetro, b, "_m_b.NCLR");
    func_02048684(buf, gCupPicture->mUnk_10, 0x228);
    LoadNclrData(&gCupPicture->mUnk_00, gCupPicture->mUnk_10);
}

void LoadCupPictureNcgr(void) {
    char buf[0x100];
    s32 i;
    s32 a;
    s32 b;

    i = gCupPicture->mUnk_0c;
    a = data_0216aea8[i * 2];
    b = data_0216aeac[i * 2];
    snprintf(buf, 0x100, "%s%s%02d%s", gCupPicturePrefix, a == 0 ? gCupPictureNitro : gCupPictureRetro, b, "_m_b.NCGR");
    func_02048684(buf, gCupPicture->mUnk_238, 0xe00);
    LoadNcgrData(&gCupPicture->mUnk_04, gCupPicture->mUnk_238);
}

void LoadCupPictureNscr(void) {
    char buf[0x100];
    s32 i;
    s32 a;
    s32 b;

    i = gCupPicture->mUnk_0c;
    a = data_0216aea8[i * 2];
    b = data_0216aeac[i * 2];
    snprintf(buf, 0x100, "%s%s%02d%s", gCupPicturePrefix, a == 0 ? gCupPictureNitro : gCupPictureRetro, b,
             "_m_picture.NSCR");
    func_02048684(buf, gCupPicture->mUnk_1038, 0x824);
    LoadNscrData(&gCupPicture->mUnk_08, gCupPicture->mUnk_1038);
}
#pragma thumb off
