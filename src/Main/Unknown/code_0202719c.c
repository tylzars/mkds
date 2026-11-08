#include "Main/Unknown/code_0202719c.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025bb4.h"
#include "Main/Unknown/code_0202b000.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_02025edc.h"
#include "Main/Unknown/code_0202b604.h"
#include "Main/Unknown/code_02077bc0.h"

#pragma thumb on

void func_02027be0(void) {
    Unk02174e14 *selectCharacter;

    selectCharacter = gSelectCharacter;
    switch (selectCharacter->mUnk_060) {
        case 0:
            selectCharacter->mTableIndexByKey[0] = data_usa_0215377c[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_0215377c[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_0215377c[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_0215377c[3];
            break;
        case 1:
            if (selectCharacter->mUnk_064 == 4) {
                selectCharacter->mTableIndexByKey[0] = data_usa_02153784[0];
                selectCharacter->mTableIndexByKey[1] = data_usa_02153784[1];
                selectCharacter->mTableIndexByKey[2] = data_usa_02153784[2];
                selectCharacter->mTableIndexByKey[3] = data_usa_02153784[3];
            } else {
                selectCharacter->mTableIndexByKey[0] = data_usa_0215378c[0];
                selectCharacter->mTableIndexByKey[1] = data_usa_0215378c[1];
                selectCharacter->mTableIndexByKey[2] = data_usa_0215378c[2];
                selectCharacter->mTableIndexByKey[3] = data_usa_0215378c[3];
            }
            break;
        case 2:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153794[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153794[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153794[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153794[3];
            break;
        case 3:
            if (selectCharacter->mUnk_064 == 1 || selectCharacter->mUnk_064 == 6) {
                selectCharacter->mTableIndexByKey[0] = data_usa_0215379c[0];
                selectCharacter->mTableIndexByKey[1] = data_usa_0215379c[1];
                selectCharacter->mTableIndexByKey[2] = data_usa_0215379c[2];
                selectCharacter->mTableIndexByKey[3] = data_usa_0215379c[3];
            } else {
                selectCharacter->mTableIndexByKey[0] = data_usa_021537a4[0];
                selectCharacter->mTableIndexByKey[1] = data_usa_021537a4[1];
                selectCharacter->mTableIndexByKey[2] = data_usa_021537a4[2];
                selectCharacter->mTableIndexByKey[3] = data_usa_021537a4[3];
            }
            break;
        case 4:
            if (selectCharacter->mUnk_064 == 2 || selectCharacter->mUnk_064 == 7) {
                selectCharacter->mTableIndexByKey[0] = data_usa_021537ac[0];
                selectCharacter->mTableIndexByKey[1] = data_usa_021537ac[1];
                selectCharacter->mTableIndexByKey[2] = data_usa_021537ac[2];
                selectCharacter->mTableIndexByKey[3] = data_usa_021537ac[3];
            } else {
                selectCharacter->mTableIndexByKey[0] = data_usa_021537b4[0];
                selectCharacter->mTableIndexByKey[1] = data_usa_021537b4[1];
                selectCharacter->mTableIndexByKey[2] = data_usa_021537b4[2];
                selectCharacter->mTableIndexByKey[3] = data_usa_021537b4[3];
            }
            break;
        case 5:
            selectCharacter->mTableIndexByKey[0] = data_usa_021537bc[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_021537bc[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_021537bc[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_021537bc[3];
            break;
        case 6:
            if (selectCharacter->mUnk_064 == 4) {
                selectCharacter->mTableIndexByKey[0] = data_usa_021537c4[0];
                selectCharacter->mTableIndexByKey[1] = data_usa_021537c4[1];
                selectCharacter->mTableIndexByKey[2] = data_usa_021537c4[2];
                selectCharacter->mTableIndexByKey[3] = data_usa_021537c4[3];
            } else {
                selectCharacter->mTableIndexByKey[0] = data_usa_021537cc[0];
                selectCharacter->mTableIndexByKey[1] = data_usa_021537cc[1];
                selectCharacter->mTableIndexByKey[2] = data_usa_021537cc[2];
                selectCharacter->mTableIndexByKey[3] = data_usa_021537cc[3];
            }
            break;
        case 7:
            selectCharacter->mTableIndexByKey[0] = data_usa_021537d4[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_021537d4[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_021537d4[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_021537d4[3];
            break;
    }
}

void func_02027a58(void) {
    Unk02174e14 *selectCharacter;

    selectCharacter = gSelectCharacter;
    switch (selectCharacter->mUnk_060) {
        case 0:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153734[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153734[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153734[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153734[3];
            break;
        case 1:
            selectCharacter->mTableIndexByKey[0] = data_usa_0215373c[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_0215373c[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_0215373c[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_0215373c[3];
            break;
        case 2:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153744[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153744[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153744[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153744[3];
            break;
        case 3:
            selectCharacter->mTableIndexByKey[0] = data_usa_0215374c[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_0215374c[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_0215374c[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_0215374c[3];
            break;
        case 4:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153754[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153754[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153754[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153754[3];
            break;
        case 5:
            selectCharacter->mTableIndexByKey[0] = data_usa_0215375c[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_0215375c[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_0215375c[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_0215375c[3];
            break;
        case 6:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153764[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153764[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153764[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153764[3];
            break;
        case 7:
            selectCharacter->mTableIndexByKey[0] = data_usa_0215376c[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_0215376c[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_0215376c[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_0215376c[3];
            break;
        case 8:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153774[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153774[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153774[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153774[3];
            break;
    }
}

void func_02027850(void) {
    Unk02174e14 *selectCharacter;

    selectCharacter = gSelectCharacter;
    switch (selectCharacter->mUnk_060) {
        case 0:
            selectCharacter->mTableIndexByKey[0] = data_usa_021536d4[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_021536d4[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_021536d4[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_021536d4[3];
            break;
        case 1:
            if (selectCharacter->mUnk_064 == 5) {
                selectCharacter->mTableIndexByKey[0] = data_usa_021536dc[0];
                selectCharacter->mTableIndexByKey[1] = data_usa_021536dc[1];
                selectCharacter->mTableIndexByKey[2] = data_usa_021536dc[2];
                selectCharacter->mTableIndexByKey[3] = data_usa_021536dc[3];
            } else {
                selectCharacter->mTableIndexByKey[0] = data_usa_021536e4[0];
                selectCharacter->mTableIndexByKey[1] = data_usa_021536e4[1];
                selectCharacter->mTableIndexByKey[2] = data_usa_021536e4[2];
                selectCharacter->mTableIndexByKey[3] = data_usa_021536e4[3];
            }
            break;
        case 2:
            selectCharacter->mTableIndexByKey[0] = data_usa_021536ec[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_021536ec[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_021536ec[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_021536ec[3];
            break;
        case 3:
            selectCharacter->mTableIndexByKey[0] = data_usa_021536f4[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_021536f4[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_021536f4[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_021536f4[3];
            break;
        case 4:
            selectCharacter->mTableIndexByKey[0] = data_usa_021536fc[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_021536fc[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_021536fc[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_021536fc[3];
            break;
        case 5:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153704[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153704[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153704[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153704[3];
            break;
        case 6:
            selectCharacter->mTableIndexByKey[0] = data_usa_0215370c[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_0215370c[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_0215370c[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_0215370c[3];
            break;
        case 7:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153714[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153714[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153714[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153714[3];
            break;
        case 8:
            if (selectCharacter->mUnk_064 == 5) {
                selectCharacter->mTableIndexByKey[0] = data_usa_0215371c[0];
                selectCharacter->mTableIndexByKey[1] = data_usa_0215371c[1];
                selectCharacter->mTableIndexByKey[2] = data_usa_0215371c[2];
                selectCharacter->mTableIndexByKey[3] = data_usa_0215371c[3];
            } else {
                selectCharacter->mTableIndexByKey[0] = data_usa_02153724[0];
                selectCharacter->mTableIndexByKey[1] = data_usa_02153724[1];
                selectCharacter->mTableIndexByKey[2] = data_usa_02153724[2];
                selectCharacter->mTableIndexByKey[3] = data_usa_02153724[3];
            }
            break;
        case 9:
            selectCharacter->mTableIndexByKey[0] = data_usa_0215372c[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_0215372c[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_0215372c[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_0215372c[3];
            break;
    }
}

void func_02027648(void) {
    Unk02174e14 *selectCharacter;

    selectCharacter = gSelectCharacter;
    switch (selectCharacter->mUnk_060) {
        case 0:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153674[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153674[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153674[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153674[3];
            break;
        case 1:
            selectCharacter->mTableIndexByKey[0] = data_usa_0215367c[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_0215367c[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_0215367c[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_0215367c[3];
            break;
        case 2:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153684[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153684[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153684[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153684[3];
            break;
        case 3:
            selectCharacter->mTableIndexByKey[0] = data_usa_0215368c[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_0215368c[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_0215368c[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_0215368c[3];
            break;
        case 4:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153694[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153694[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153694[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153694[3];
            break;
        case 5:
            if (selectCharacter->mUnk_064 == 2 || selectCharacter->mUnk_064 == 9) {
                selectCharacter->mTableIndexByKey[0] = data_usa_0215369c[0];
                selectCharacter->mTableIndexByKey[1] = data_usa_0215369c[1];
                selectCharacter->mTableIndexByKey[2] = data_usa_0215369c[2];
                selectCharacter->mTableIndexByKey[3] = data_usa_0215369c[3];
            } else {
                selectCharacter->mTableIndexByKey[0] = data_usa_021536a4[0];
                selectCharacter->mTableIndexByKey[1] = data_usa_021536a4[1];
                selectCharacter->mTableIndexByKey[2] = data_usa_021536a4[2];
                selectCharacter->mTableIndexByKey[3] = data_usa_021536a4[3];
            }
            break;
        case 6:
            selectCharacter->mTableIndexByKey[0] = data_usa_021536ac[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_021536ac[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_021536ac[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_021536ac[3];
            break;
        case 7:
            selectCharacter->mTableIndexByKey[0] = data_usa_021536b4[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_021536b4[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_021536b4[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_021536b4[3];
            break;
        case 8:
            selectCharacter->mTableIndexByKey[0] = data_usa_021536bc[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_021536bc[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_021536bc[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_021536bc[3];
            break;
        case 9:
            selectCharacter->mTableIndexByKey[0] = data_usa_021536c4[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_021536c4[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_021536c4[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_021536c4[3];
            break;
        case 10:
            selectCharacter->mTableIndexByKey[0] = data_usa_021536cc[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_021536cc[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_021536cc[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_021536cc[3];
            break;
    }
}

void func_02027448(void) {
    Unk02174e14 *selectCharacter;

    selectCharacter = gSelectCharacter;
    switch (selectCharacter->mUnk_060) {
        case 0:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153614[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153614[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153614[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153614[3];
            break;
        case 1:
            selectCharacter->mTableIndexByKey[0] = data_usa_0215361c[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_0215361c[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_0215361c[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_0215361c[3];
            break;
        case 2:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153624[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153624[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153624[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153624[3];
            break;
        case 3:
            selectCharacter->mTableIndexByKey[0] = data_usa_0215362c[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_0215362c[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_0215362c[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_0215362c[3];
            break;
        case 4:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153634[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153634[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153634[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153634[3];
            break;
        case 5:
            selectCharacter->mTableIndexByKey[0] = data_usa_0215363c[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_0215363c[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_0215363c[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_0215363c[3];
            break;
        case 6:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153644[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153644[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153644[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153644[3];
            break;
        case 7:
            selectCharacter->mTableIndexByKey[0] = data_usa_0215364c[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_0215364c[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_0215364c[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_0215364c[3];
            break;
        case 8:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153654[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153654[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153654[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153654[3];
            break;
        case 9:
            selectCharacter->mTableIndexByKey[0] = data_usa_0215365c[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_0215365c[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_0215365c[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_0215365c[3];
            break;
        case 10:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153664[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153664[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153664[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153664[3];
            break;
        case 11:
            selectCharacter->mTableIndexByKey[0] = data_usa_0215366c[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_0215366c[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_0215366c[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_0215366c[3];
            break;
    }
}

void func_02027424(s32 mode) {
    if (gSelectCharacter->mUnk_128 != FALSE) {
        func_0202b7c0(mode);
    }
}

void StartSelectCharacterReturn(void) {
    gSelectCharacter->mUnk_068 = 0;
    gSelectCharacter->mUnk_08c = 2;
    gSelectCharacter->mUnk_06c = 8;
    RequestSelectReturnState3WithSound(0);
    func_02027424(3);
    func_02025f14(&gSelectCharacter->mInterpolations[0], 2);
    func_02025f14(&gSelectCharacter->mInterpolations[1], 2);
    func_02025f14(&gSelectCharacter->mInterpolations[2], 2);
    StartKartModelMenuBg0Decrease();
}

void func_0202734c(s32 value) {
    Unk02174e14 *selectCharacter;
    s32 i;
    CellFileSet *sParts;

    selectCharacter = gSelectCharacter;
    sParts = &selectCharacter->mUnk_01c;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        for (i = 0; i < gSelectCharacter->mUnk_07c; i++) {
            sParts->mCellTable[data_usa_02153554[i].mUnk_04].mUnk_00 = value;
            sParts->mCellTable[data_usa_02153554[i].mUnk_02].mUnk_00 =
                sParts->mCellTable[data_usa_02153554[i].mUnk_04].mUnk_00;
            sParts->mCellTable[data_usa_02153554[i].mUnk_00].mUnk_00 =
                sParts->mCellTable[data_usa_02153554[i].mUnk_02].mUnk_00;
        }
        sParts->mCellTable[25].mUnk_00 = value;
    }
}

void func_020272ec(void) {
    s32 i;
    CellFileSet *sParts;
    Unk02153554 *tableRow;

    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        sParts = &gSelectCharacter->mUnk_01c;
        sParts->mCellTable[24].mUnk_00 = 0;
        sParts->mCellTable[25].mUnk_00 = 1;
        tableRow = data_usa_02153554;
        for (i = 0; i < 12; i++) {
            sParts->mCellTable[tableRow->mUnk_02].mUnk_04 = 0;
            sParts->mCellTable[tableRow->mUnk_02].mUnk_06 = 0;
            tableRow++;
        }
    }
}

void func_020272c0(s16 firstValue, s16 secondValue) {
    Unk02174e14 *selectCharacter;

    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        selectCharacter = gSelectCharacter;
        if (selectCharacter->mUnk_128 == FALSE) {
            selectCharacter->mUnk_000.mCellTable[0].mUnk_06 = firstValue;
            selectCharacter->mUnk_000.mCellTable[3].mUnk_06 = secondValue;
        }
    }
}

void func_0202728c(s16 value) {
    Unk02174e14 *selectCharacter;

    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        selectCharacter = gSelectCharacter;
        if (selectCharacter->mUnk_128 == FALSE) {
            selectCharacter->mUnk_000.mCellTable[1].mUnk_04 = value;
            selectCharacter->mUnk_000.mCellTable[2].mUnk_04 = selectCharacter->mUnk_000.mCellTable[1].mUnk_04;
        }
    }
}

void func_0202721c(void) {
    Unk02174e14 *selectCharacter;
    CellFileSet *nameParts;

    selectCharacter = gSelectCharacter;
    if (selectCharacter->mUnk_128 == FALSE) {
        nameParts = &selectCharacter->mUnk_038;
        func_02124748(*(s16 *) &selectCharacter->mUnk_090[selectCharacter->mUnk_060].mUnk_04, nameParts->mCells,
                      selectCharacter->mUnk_038.mChars, nameParts->mCellLayout, 0, 2, selectCharacter->mUnk_000.mCells,
                      selectCharacter->mUnk_000.mCellLayout);
        func_02124748(*(s16 *) &gSelectCharacter->mUnk_090[gSelectCharacter->mUnk_060].mUnk_04, nameParts->mCells,
                      selectCharacter->mUnk_038.mChars, nameParts->mCellLayout, 0, 1, selectCharacter->mUnk_000.mCells,
                      selectCharacter->mUnk_000.mCellLayout);
    }
}

void func_020271e8(void) {
    Unk02174e14 *selectCharacter;
    CellFileSet *sParts;
    s32 tableIndex;

    selectCharacter = gSelectCharacter;
    sParts = &selectCharacter->mUnk_01c;
    tableIndex = selectCharacter->mUnk_060;
    func_02025c6c(0x18, data_usa_02153554[tableIndex].mUnk_00, sParts->mCellLayout);
    func_02025c6c(0x19, data_usa_02153554[tableIndex].mUnk_00, sParts->mCellLayout);
}

void func_0202719c(void) {
    Unk02174e14 *selectCharacter;
    CellFileSet *sParts;
    Unk02153554 *tableRow;

    selectCharacter = gSelectCharacter;
    sParts = &selectCharacter->mUnk_01c;
    tableRow = &data_usa_02153554[selectCharacter->mUnk_060];
    sParts->mCellTable[24].mUnk_00 = 1;
    sParts->mCellTable[25].mUnk_00 = 0;
    sParts->mCellTable[tableRow->mUnk_02].mUnk_04 = 1;
    sParts->mCellTable[tableRow->mUnk_02].mUnk_06 = 1;
}

#pragma thumb off
