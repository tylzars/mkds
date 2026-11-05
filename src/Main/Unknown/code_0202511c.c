#include "Main/Unknown/code_0202511c.h"

#include "Main/Unknown/code_021053e4.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_0211127c.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_021759c0.h"

Unk0215316c func_0202577c(u32 arg0) {
    return data_0215316c[arg0];
}

u32 func_0202553c(u32 a, void *c) {
    Unk0215316c *b = (Unk0215316c *) c;
    u32 r;

    r = 0x36;
    switch (a) {
        case COURSE_ID_CROSS:
            r = 7;
            break;
        case COURSE_ID_MARIO:
            r = 34;
            break;
        case COURSE_ID_OLD_LUIGI_GC:
            r = 8;
            break;
        case COURSE_ID_OLD_YOSHI_GC:
            r = 9;
            break;
        case COURSE_ID_BEACH:
            r = 10;
            break;
        case COURSE_ID_BANK:
            r = 11;
            break;
        case COURSE_ID_OLD_BABY_GC:
            r = 12;
            break;
        case COURSE_ID_OLD_MOMO_64:
            r = 13;
            break;
        case COURSE_ID_OLD_FRAPPE_64:
            r = 14;
            break;
        case COURSE_ID_TOWN:
            r = 15;
            break;
        case COURSE_ID_AIRSHIP:
            r = 16;
            break;
        case COURSE_ID_STADIUM:
            r = 17;
            break;
        case COURSE_ID_PINBALL:
            r = 32;
            break;
        case COURSE_ID_OLD_KINOKO_GC:
            r = 18;
            break;
        case COURSE_ID_GARDEN:
            r = 19;
            break;
        case COURSE_ID_MANSION:
            r = 20;
            break;
        case COURSE_ID_OLD_MARIO_SFC:
            r = 21;
            break;
        case COURSE_ID_OLD_NOKO_SFC:
            r = 22;
            break;
        case COURSE_ID_OLD_DONUT_SFC:
            r = 23;
            break;
        case COURSE_ID_OLD_CHOCO_SFC:
            r = 24;
            break;
        case COURSE_ID_OLD_PEACH_AGB:
            r = 25;
            break;
        case COURSE_ID_OLD_LUIGI_AGB:
            r = 26;
            break;
        case COURSE_ID_RIDGE:
            r = 27;
            break;
        case COURSE_ID_OLD_HYUDORO_64:
            r = 29;
            break;
        case COURSE_ID_OLD_CHOCO_64:
            r = 28;
            break;
        case COURSE_ID_SNOW:
            r = 30;
            break;
        case COURSE_ID_DESERT:
            r = 31;
            break;
        case COURSE_ID_CLOCK:
            r = 33;
            break;
        case COURSE_ID_KOOPA:
            r = 37;
            break;
        case COURSE_ID_RAINBOW:
            r = 35;
            break;
        case COURSE_ID_OLD_KOOPA_AGB:
            r = 36;
            break;
        case COURSE_ID_OLD_SKY_AGB:
            r = 38;
            break;
        case COURSE_ID_MINI_BLOCK:
        case COURSE_ID_MINI_BLOCK_64:
        case COURSE_ID_MINI_DOKAN_GC:
        case COURSE_ID_MINI_STAGE1:
        case COURSE_ID_MINI_STAGE2:
        case COURSE_ID_MINI_STAGE3:
        case COURSE_ID_MINI_STAGE4:
            r = 39;
            break;
        case COURSE_ID_MR_STAGE1:
        case COURSE_ID_MR_STAGE2:
        case COURSE_ID_MR_STAGE3:
        case COURSE_ID_MR_STAGE4:
            r = 40;
            break;
        case COURSE_ID_AWARD:
            r = 42;
            break;
        case COURSE_ID_STAFFROLL:
            r = 51;
            break;
    }
    if (b != NULL) {
        *b = data_0215316c[r];
    }
    return r;
}

u32 func_0202511c(s32 a, void *c) {
    Unk0215316c *b = (Unk0215316c *) c;
    enum { K0 } r;
    BOOL f;
    s32 q;
    BOOL s;
    BOOL t;
    Unk0215316c v1;
    Unk021759c0_28 *p;

    r = 0x36;
    f = FALSE;
    switch (a) {
        case 2:
            switch (data_021759c0->mUnk_00c) {
                case 0:
                case 2:
                    q = data_021759c0->mMode;
                    r = func_0202553c(data_021759c0->mCourseId, b);
                    f = TRUE;
                    if (q == MODE_MISSION_RUN) {
                        p = &data_021759c0->mUnk_28_view;
                        s = FALSE;
                        if (p->mUnk_06 == 4) {
                            b->mUnk_00[1] = 0x2a;
                            s = TRUE;
                        }
                        if (s == FALSE) {
                            switch (p->mUnk_07) {
                                case 1:
                                    b->mUnk_00[1] = 0x2c;
                                    break;
                                case 2:
                                case 3:
                                case 10:
                                    break;
                            }
                        }
                        t = TRUE;
                        switch (p->mUnk_06) {
                            case 9:
                            case 10:
                                b->mUnk_00[2] = 0x25;
                                break;
                            case 0x32:
                                b->mUnk_00[2] = 0x26;
                                break;
                            case 0x15:
                                b->mUnk_00[2] = 0x27;
                                break;
                            case 0x33:
                                b->mUnk_00[2] = 0x28;
                                break;
                            case 0x11:
                                b->mUnk_00[2] = 0x29;
                                break;
                            case 0x31:
                                break;
                            default:
                                t = FALSE;
                                break;
                        }
                        if (t != FALSE) {
                            b->mUnk_00[3] = 0x22;
                        }
                    }
                    break;
                case 5:
                    r = 0x2a;
                    break;
                case 1:
                    r = 0x33;
                    break;
                case 3:
                    switch (data_021759c0->mCourseId) {
                        case COURSE_ID_OLD_LUIGI_GC:
                        case COURSE_ID_CROSS:
                        case COURSE_ID_MARIO:
                            r = 2;
                            break;
                        case COURSE_ID_STADIUM:
                            r = 3;
                            break;
                        case COURSE_ID_PINBALL:
                            r = 4;
                            break;
                        default:
                            r = 1;
                            break;
                    }
                    if (func_021054d0() != 0) {
                        r = 6;
                    } else {
                        *b = data_0215316c[r];
                        f = TRUE;
                        func_0202553c(data_021759c0->mCourseId, &v1);
                        b->mUnk_00[2] = v1.mUnk_00[2];
                    }
                    break;
                case 4:
                    r = 5;
                    break;
                case 6:
                    r = 0x33;
                    break;
            }
            break;
        case 12:
            r = 0x2d;
            break;
        case 4:
            r = 0x33;
            break;
        case 5:
            r = 0x33;
            break;
        case 6:
            if (*(u16 *) 0x027ffc40 == 2) {
                r = 0x33;
            } else {
                r = 0x2e;
            }
            break;
        case 1:
            r = 0x32;
            break;
        case 10:
            r = 0x29;
            *b = data_0215316c[r];
            f = TRUE;
            b->mUnk_00[1] = func_0211127c();
            break;
        case 8:
            r = 0x2f;
            break;
        case 13:
            r = 0x2e;
            break;
        case 9:
            r = 0x31;
            break;
        case 0:
            r = 0x33;
            break;
        case 3:
        case 7:
        case 11:
        case 14:
            r = 0x30;
            *b = data_0215316c[r];
            f = TRUE;
            if (data_0217d060 != NULL) {
                b->mUnk_00[1] = 0xff;
                b->mUnk_00[2] = 0xff;
                b->mUnk_00[3] = 0xff;
            }
            break;
        case 15:
            r = 0x33;
            break;
    }
    if (f == FALSE && b != NULL) {
        *b = data_0215316c[r];
    }
    return r;
}
