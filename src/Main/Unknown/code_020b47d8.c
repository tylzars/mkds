#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0203c8c0.h"
#include "code_0200eddc.h"
#include "code_02021f6c.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "g2d_NOB_load.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0203c5f8.h"

u16 GetFollowedKartOrEntryIndex(void) {
    RaceSetup *raceSetup = gRaceSetup;

    return raceSetup->mRaceKind == RACE_KIND_DEMO ? raceSetup->mFollowedKartIndex : raceSetup->mEntryIndex;
}

// Highest lap of the followed kart, one less while its race has not ended: the last lap that is over (0 = none).
u16 GetFollowedKartLastEndedLap(void) {
    u16 lap;

    lap = GetKartHighestLap(
        (u16) (gRaceSetup->mRaceKind == RACE_KIND_DEMO ? gRaceSetup->mFollowedKartIndex : gRaceSetup->mEntryIndex));
    if (IsKartEnded((u16) (gRaceSetup->mRaceKind == RACE_KIND_DEMO ? gRaceSetup->mFollowedKartIndex
                                                                   : gRaceSetup->mEntryIndex)) == 0) {
        lap = lap - 1;
    }
    return lap;
}

void Matrix2x2ReciprocalScale(s32 *matrix, s32 scale) {
    s32 reciprocal;

    if (scale != 0) {
        reciprocal = FX_Div(0x1000, scale);
    } else {
        reciprocal = 0x1000;
    }
    matrix[3] = reciprocal;
    matrix[0] = matrix[3];
    matrix[2] = 0;
    matrix[1] = matrix[2];
}

void Matrix2x2Rotation(s32 *matrix, s32 angle) {
    s32 anglePairFirst = gPairsByAngle[(angle >> 4) * 2];
    s32 anglePairSecond = gPairsByAngle[(angle >> 4) * 2 + 1];

    matrix[0] = anglePairSecond;
    matrix[1] = anglePairFirst;
    matrix[2] = -anglePairFirst;
    matrix[3] = anglePairSecond;
}

void Matrix2x2ReflectedRotation(s32 *matrix, s32 angle) {
    s32 anglePairSecond = gPairsByAngle[(angle >> 4) * 2 + 1];
    s32 anglePairFirst;

    matrix[0] = -anglePairSecond;
    anglePairFirst = gPairsByAngle[(angle >> 4) * 2];
    matrix[1] = anglePairFirst;
    matrix[2] = anglePairFirst;
    matrix[3] = anglePairSecond;
}

void Matrix2x2RotationReciprocalScale(s32 *matrix, s32 scale, s32 angle) {
    s32 angleIndex = angle >> 4;
    s32 anglePairFirst = gPairsByAngle[angleIndex * 2];
    s32 anglePairSecond = gPairsByAngle[angleIndex * 2 + 1];
    s32 reciprocal;

    if (scale != 0) {
        reciprocal = FX_Div(0x1000, scale);
    } else {
        reciprocal = 0x1000;
    }
    matrix[0] = ((s64) anglePairSecond * reciprocal) >> 12;
    matrix[1] = ((s64) anglePairFirst * reciprocal) >> 12;
    matrix[2] = -matrix[1];
    matrix[3] = matrix[0];
}

BOOL func_020b4b98(s32 number) {
    switch (data_021759d0->mLanguageIndex) {
        case 0:
        case 1:
        case 3:
        case 4:
        case 5:
        default:
            if (number != 1) {
                return TRUE;
            }
            return FALSE;
        case 2:
            if (number != 1 && number != 0) {
                return TRUE;
            }
            return FALSE;
    }
}

BOOL RaceStartIsLanguageJa(void) {
    switch (data_021759d0->mLanguageIndex) {
        case 0:
            return TRUE;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            return FALSE;
    }
}

s32 GetLanguageCharSpacing(void) {
    switch (data_021759d0->mLanguageIndex) {
        case 0:
            return 1;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            return -1;
    }
}

BOOL IsLanguageJa(void) {
    switch (data_021759d0->mLanguageIndex) {
        case 0:
            return TRUE;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            return FALSE;
    }
}

void LoadNclrData(Nclr **outNclr, void *file) {
    Unk02021fd0 *part;

    if (file != NULL) {
        part = FindPartByTag(file, 0x504c5454);
        if (part != NULL) {
            *outNclr = (Nclr *) (part + 1);
            NNS_G2dUnpackNCL((NNSG2dPaletteData *) *outNclr);
        }
    }
    DC_FlushRange((*outNclr)->mData, (*outNclr)->mDataSize);
}

void LocateNclr(Nclr **outNclr, void *file) {
    Unk02021fd0 *part;

    if (file == NULL) {
        return;
    }
    part = FindPartByTag(file, 0x504c5454);
    if (part != NULL) {
        *outNclr = (Nclr *) (part + 1);
    }
}

void LoadNcgrData2(Ncgr **outNcgr, void *file) {
    Unk02021fd0 *part;

    if (file != NULL) {
        part = FindPartByTag(file, 0x43484152);
        if (part != NULL) {
            *outNcgr = (Ncgr *) (part + 1);
            NNS_G2dUnpackBGNCG((NNSG2dCharacterData *) *outNcgr);
        }
    }
    DC_FlushRange((*outNcgr)->mData, (*outNcgr)->mDataSize);
}

void LocateNcgr2(Ncgr **outNcgr, void *file) {
    Unk02021fd0 *part;

    if (file == NULL) {
        return;
    }
    part = FindPartByTag(file, 0x43484152);
    if (part != NULL) {
        *outNcgr = (Ncgr *) (part + 1);
    }
}

void LoadNcgrData(Ncgr **outNcgr, void *file) {
    Unk02021fd0 *part;

    if (file != NULL) {
        part = FindPartByTag(file, 0x43484152);
        if (part != NULL) {
            *outNcgr = (Ncgr *) (part + 1);
            NNS_G2dUnpackNCG((NNSG2dCharacterData *) *outNcgr);
        }
    }
    DC_FlushRange((*outNcgr)->mData, (*outNcgr)->mDataSize);
}

void LocateNcgr(Ncgr **outNcgr, void *file) {
    Unk02021fd0 *part;

    if (file == NULL) {
        return;
    }
    part = FindPartByTag(file, 0x43484152);
    if (part != NULL) {
        *outNcgr = (Ncgr *) (part + 1);
    }
}

void LoadNcerData(Unk02021dc8 **outNcer, void *file) {
    Unk02021fd0 *part;

    if (file == NULL) {
        return;
    }
    part = FindPartByTag(file, 0x4345424b);
    if (part == NULL) {
        return;
    }
    *outNcer = (Unk02021dc8 *) (part + 1);
    NNS_G2dUnpackNCE(*outNcer);
}

void LocateNcer(Unk02021dc8 **outNcer, void *file) {
    Unk02021fd0 *part;

    if (file == NULL) {
        return;
    }
    part = FindPartByTag(file, 0x4345424b);
    if (part != NULL) {
        *outNcer = (Unk02021dc8 *) (part + 1);
    }
}

void LoadNanrData(Unk02021dc8 **outNanr, void *file) {
    Unk02021fd0 *part;

    if (file == NULL) {
        return;
    }
    part = FindPartByTag(file, 0x41424e4b);
    if (part == NULL) {
        return;
    }
    *outNanr = (Unk02021dc8 *) (part + 1);
    NNS_G2dUnpackNAN(*outNanr);
}

void LoadNscrData(Nscr **outNscr, void *file) {
    Unk02021fd0 *part;

    if (file != NULL) {
        part = FindPartByTag(file, 0x5343524e);
        if (part != NULL) {
            *outNscr = (Nscr *) (part + 1);
            NNS_G2dGetUnpackedScreenData(file, (Unk02021fd0 **) outNscr);
        }
    }
    DC_FlushRange((*outNscr)->mData, (*outNscr)->mDataSize);
}

void LocateNscr(Nscr **outNscr, void *file) {
    Unk02021fd0 *part;

    if (file == NULL) {
        return;
    }
    part = FindPartByTag(file, 0x5343524e);
    if (part != NULL) {
        *outNscr = (Nscr *) (part + 1);
    }
}
