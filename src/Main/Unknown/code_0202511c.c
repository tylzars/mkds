#include "Main/Unknown/code_0202511c.h"

#include "Main/Unknown/code_021053e4.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_0211127c.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_021759c0.h"

SoundRow GetSoundRow(u32 rowIndex) {
    return gSoundRowTable[rowIndex];
}

u32 GetCourseSoundRowIndex(u32 courseId, void *outputPointer) {
    SoundRow *output = outputPointer;
    u32 rowIndex;

    rowIndex = 0x36;
    switch (courseId) {
        case COURSE_ID_CROSS:
            rowIndex = 7;
            break;
        case COURSE_ID_MARIO:
            rowIndex = 34;
            break;
        case COURSE_ID_OLD_LUIGI_GC:
            rowIndex = 8;
            break;
        case COURSE_ID_OLD_YOSHI_GC:
            rowIndex = 9;
            break;
        case COURSE_ID_BEACH:
            rowIndex = 10;
            break;
        case COURSE_ID_BANK:
            rowIndex = 11;
            break;
        case COURSE_ID_OLD_BABY_GC:
            rowIndex = 12;
            break;
        case COURSE_ID_OLD_MOMO_64:
            rowIndex = 13;
            break;
        case COURSE_ID_OLD_FRAPPE_64:
            rowIndex = 14;
            break;
        case COURSE_ID_TOWN:
            rowIndex = 15;
            break;
        case COURSE_ID_AIRSHIP:
            rowIndex = 16;
            break;
        case COURSE_ID_STADIUM:
            rowIndex = 17;
            break;
        case COURSE_ID_PINBALL:
            rowIndex = 32;
            break;
        case COURSE_ID_OLD_KINOKO_GC:
            rowIndex = 18;
            break;
        case COURSE_ID_GARDEN:
            rowIndex = 19;
            break;
        case COURSE_ID_MANSION:
            rowIndex = 20;
            break;
        case COURSE_ID_OLD_MARIO_SFC:
            rowIndex = 21;
            break;
        case COURSE_ID_OLD_NOKO_SFC:
            rowIndex = 22;
            break;
        case COURSE_ID_OLD_DONUT_SFC:
            rowIndex = 23;
            break;
        case COURSE_ID_OLD_CHOCO_SFC:
            rowIndex = 24;
            break;
        case COURSE_ID_OLD_PEACH_AGB:
            rowIndex = 25;
            break;
        case COURSE_ID_OLD_LUIGI_AGB:
            rowIndex = 26;
            break;
        case COURSE_ID_RIDGE:
            rowIndex = 27;
            break;
        case COURSE_ID_OLD_HYUDORO_64:
            rowIndex = 29;
            break;
        case COURSE_ID_OLD_CHOCO_64:
            rowIndex = 28;
            break;
        case COURSE_ID_SNOW:
            rowIndex = 30;
            break;
        case COURSE_ID_DESERT:
            rowIndex = 31;
            break;
        case COURSE_ID_CLOCK:
            rowIndex = 33;
            break;
        case COURSE_ID_KOOPA:
            rowIndex = 37;
            break;
        case COURSE_ID_RAINBOW:
            rowIndex = 35;
            break;
        case COURSE_ID_OLD_KOOPA_AGB:
            rowIndex = 36;
            break;
        case COURSE_ID_OLD_SKY_AGB:
            rowIndex = 38;
            break;
        case COURSE_ID_MINI_BLOCK:
        case COURSE_ID_MINI_BLOCK_64:
        case COURSE_ID_MINI_DOKAN_GC:
        case COURSE_ID_MINI_STAGE1:
        case COURSE_ID_MINI_STAGE2:
        case COURSE_ID_MINI_STAGE3:
        case COURSE_ID_MINI_STAGE4:
            rowIndex = 39;
            break;
        case COURSE_ID_MR_STAGE1:
        case COURSE_ID_MR_STAGE2:
        case COURSE_ID_MR_STAGE3:
        case COURSE_ID_MR_STAGE4:
            rowIndex = 40;
            break;
        case COURSE_ID_AWARD:
            rowIndex = 42;
            break;
        case COURSE_ID_STAFFROLL:
            rowIndex = 51;
            break;
    }
    if (output != NULL) {
        *output = gSoundRowTable[rowIndex];
    }
    return rowIndex;
}

u32 GetSceneSoundRowIndex(s32 sceneNumber, void *outputPointer) {
    SoundRow *output = outputPointer;
    enum { K0 } rowIndex;
    BOOL rowWritten;
    s32 raceMode;
    BOOL s;
    BOOL t;
    SoundRow courseRow;
    Unk021759c0_28 *mission;

    rowIndex = 0x36;
    rowWritten = FALSE;
    switch (sceneNumber) {
        case 2:
            switch (gRaceSetup->mRaceKind) {
                case RACE_KIND_NORMAL:
                case 2:
                    raceMode = gRaceSetup->mMode;
                    rowIndex = GetCourseSoundRowIndex(gRaceSetup->mCourseId, output);
                    rowWritten = TRUE;
                    if (raceMode == MODE_MISSION_RUN) {
                        mission = &gRaceSetup->mUnk_28_view;
                        s = FALSE;
                        if (mission->mMissionTableValue == 4) {
                            output->mUnk_00[1] = 0x2a;
                            s = TRUE;
                        }
                        if (s == FALSE) {
                            switch (mission->mMissionKind) {
                                case 1:
                                    output->mUnk_00[1] = 0x2c;
                                    break;
                                case 2:
                                case 3:
                                case 10:
                                    break;
                            }
                        }
                        t = TRUE;
                        switch (mission->mMissionTableValue) {
                            case 9:
                            case 10:
                                output->mUnk_00[2] = 0x25;
                                break;
                            case 0x32:
                                output->mUnk_00[2] = 0x26;
                                break;
                            case 0x15:
                                output->mUnk_00[2] = 0x27;
                                break;
                            case 0x33:
                                output->mUnk_00[2] = 0x28;
                                break;
                            case 0x11:
                                output->mUnk_00[2] = 0x29;
                                break;
                            case 0x31:
                                break;
                            default:
                                t = FALSE;
                                break;
                        }
                        if (t != FALSE) {
                            output->mUnk_00[3] = 0x22;
                        }
                    }
                    break;
                case RACE_KIND_AWARD:
                    rowIndex = 0x2a;
                    break;
                case RACE_KIND_DEMO:
                    rowIndex = 0x33;
                    break;
                case RACE_KIND_START_GP:
                    switch (gRaceSetup->mCourseId) {
                        case COURSE_ID_OLD_LUIGI_GC:
                        case COURSE_ID_CROSS:
                        case COURSE_ID_MARIO:
                            rowIndex = 2;
                            break;
                        case COURSE_ID_STADIUM:
                            rowIndex = 3;
                            break;
                        case COURSE_ID_PINBALL:
                            rowIndex = 4;
                            break;
                        default:
                            rowIndex = 1;
                            break;
                    }
                    if (func_021054d0() != 0) {
                        rowIndex = 6;
                    } else {
                        *output = gSoundRowTable[rowIndex];
                        rowWritten = TRUE;
                        GetCourseSoundRowIndex(gRaceSetup->mCourseId, &courseRow);
                        output->mUnk_00[2] = courseRow.mUnk_00[2];
                    }
                    break;
                case 4:
                    rowIndex = 5;
                    break;
                case RACE_KIND_STAFF_ROLL:
                    rowIndex = 0x33;
                    break;
            }
            break;
        case 12:
            rowIndex = 0x2d;
            break;
        case 4:
            rowIndex = 0x33;
            break;
        case 5:
            rowIndex = 0x33;
            break;
        case 6:
            if (*(u16 *) 0x027ffc40 == 2) {
                rowIndex = 0x33;
            } else {
                rowIndex = 0x2e;
            }
            break;
        case 1:
            rowIndex = 0x32;
            break;
        case 10:
            rowIndex = 0x29;
            *output = gSoundRowTable[rowIndex];
            rowWritten = TRUE;
            output->mUnk_00[1] = func_0211127c();
            break;
        case 8:
            rowIndex = 0x2f;
            break;
        case 13:
            rowIndex = 0x2e;
            break;
        case 9:
            rowIndex = 0x31;
            break;
        case 0:
            rowIndex = 0x33;
            break;
        case 3:
        case 7:
        case 11:
        case 14:
            rowIndex = 0x30;
            *output = gSoundRowTable[rowIndex];
            rowWritten = TRUE;
            if (data_0217d060 != NULL) {
                output->mUnk_00[1] = 0xff;
                output->mUnk_00[2] = 0xff;
                output->mUnk_00[3] = 0xff;
            }
            break;
        case 15:
            rowIndex = 0x33;
            break;
    }
    if (rowWritten == FALSE && output != NULL) {
        *output = gSoundRowTable[rowIndex];
    }
    return rowIndex;
}
