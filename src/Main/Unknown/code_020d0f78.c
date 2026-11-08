#include "Main/Unknown/code_020d0f78.h"
#include "Main/Unknown/code_020483e4.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_02048000.h"
#include "code_02134398.h"
#include "Main/Unknown/unk_0216a000.h"

#pragma opt_propagation off

#pragma thumb on
void ClearCupPicturePointer(void) {
    gCupPicture = NULL;
}

void LoadCupPictureNclr(void) {
    char buf[0x100];
    s32 pictureIndex;
    s32 nitroOrRetro;
    s32 pictureNumber;

    pictureIndex = gCupPicture->mCupPictureIndex;
    nitroOrRetro = data_0216aea8[pictureIndex * 2];
    pictureNumber = data_0216aeac[pictureIndex * 2];
    snprintf(buf, 0x100, "%s%s%02d%s", gCupPicturePrefix, nitroOrRetro == 0 ? gCupPictureNitro : gCupPictureRetro,
             pictureNumber, "_m_b.NCLR");
    ReadWholeFile(buf, gCupPicture->mCupPictureNclrFile, 0x228);
    LoadNclrData(&gCupPicture->mCupPictureNclr, gCupPicture->mCupPictureNclrFile);
}

void LoadCupPictureNcgr(void) {
    char buf[0x100];
    s32 pictureIndex;
    s32 nitroOrRetro;
    s32 pictureNumber;

    pictureIndex = gCupPicture->mCupPictureIndex;
    nitroOrRetro = data_0216aea8[pictureIndex * 2];
    pictureNumber = data_0216aeac[pictureIndex * 2];
    snprintf(buf, 0x100, "%s%s%02d%s", gCupPicturePrefix, nitroOrRetro == 0 ? gCupPictureNitro : gCupPictureRetro,
             pictureNumber, "_m_b.NCGR");
    ReadWholeFile(buf, gCupPicture->mCupPictureNcgrFile, 0xe00);
    LoadNcgrData(&gCupPicture->mCupPictureNcgr, gCupPicture->mCupPictureNcgrFile);
}

void LoadCupPictureNscr(void) {
    char buf[0x100];
    s32 pictureIndex;
    s32 nitroOrRetro;
    s32 pictureNumber;

    pictureIndex = gCupPicture->mCupPictureIndex;
    nitroOrRetro = data_0216aea8[pictureIndex * 2];
    pictureNumber = data_0216aeac[pictureIndex * 2];
    snprintf(buf, 0x100, "%s%s%02d%s", gCupPicturePrefix, nitroOrRetro == 0 ? gCupPictureNitro : gCupPictureRetro,
             pictureNumber, "_m_picture.NSCR");
    ReadWholeFile(buf, gCupPicture->mCupPictureNscrFile, 0x824);
    LoadNscrData(&gCupPicture->mCupPictureNscr, gCupPicture->mCupPictureNscrFile);
}
#pragma thumb off
