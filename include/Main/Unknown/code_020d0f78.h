#pragma once

#include "types.h"

typedef struct Ncgr Ncgr;
typedef struct Nscr Nscr;
typedef struct Nclr Nclr;

// Object behind gCupPicture: three pointers that LoadNclrData, LoadNcgrData and LoadNscrData fill from
// the three buffers at 0x10, 0x238 and 0x1038, then a word at 0xc.
typedef struct Unk0217b4a4 {
    /* 0000 */ Nclr *mCupPictureNclr;
    /* 0004 */ Ncgr *mCupPictureNcgr;
    /* 0008 */ Nscr *mCupPictureNscr;
    /* 000c */ s32 mCupPictureIndex;
    /* 0010 */ u8 mCupPictureNclrFile[0x228];
    /* 0238 */ u8 mCupPictureNcgrFile[0xe00];
    /* 1038 */ u8 mCupPictureNscrFile[0x824];
} Unk0217b4a4;

void ClearCupPicturePointer(void);
void LoadCupPictureNclr(void);
void LoadCupPictureNcgr(void);
void LoadCupPictureNscr(void);
