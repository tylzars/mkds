#include "Main/Unknown/code_02033dd0.h"
#include "Main/Unknown/code_02025ebc.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "registers.h"

// Reads the table of gCupRecords, a row chosen by one call and a column by another.
static inline Unk0217aa1c_00 *func_02033e6c_inline(u32 a) {
    return &gCupRecords->mUnk_000[GetCourseIndexInCup()][GetLowByte(a)];
}

#pragma thumb on

void func_02034244(void) {
    s16 a;
    u32 b;
    u32 c;
    s32 d;
    s32 e;

    a = func_02025ebc(&data_02174e64->mUnk_194);
    reg_G2_BG0OFS = (a << 16) & 0x1ff0000;
    d = -a;
    reg_G2S_DB_BG3OFS = (d << 16) & 0x1ff0000;
    switch (a) {
        default:
            reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffff1fff) | 0x2000;
            e = (reg_G2_WININ & ~0x3f) | 0x1f;
            reg_G2_WININ = e | 0x20;
            reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~0x3f) | 0xe) | 0x20;
            reg_G2_WIN0H = 0xff;
            reg_G2_WIN0V = ((d << 8) & 0xff00) | 0xc0;
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffff1fff) | 0x2000;
            c = (reg_G2S_DB_WININ & ~0x3f) | 0x1f;
            reg_G2S_DB_WININ = c | 0x20;
            b = (reg_G2S_DB_WINOUT & ~0x3f) | 7;
            reg_G2S_DB_WINOUT = b | 0x20;
            reg_G2S_DB_WIN0H = 0xff;
            reg_G2S_DB_WIN0V = (a + 0xc0) & 0xff;
            break;
        case 0:
            reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
            reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
            break;
    }
}

void func_02034188(void) {
    ResultsBattle *o;
    s32 r;
    s32 n;
    s32 i;

    r = 0;
    n = 0;
    for (i = 0; i < gResultsBattle->mUnk_0d8; i++) {
        if (gRaceSetup->mCurrentEntries[(u16) i].mPlayer.mTeamIndex == 0) {
            gResultsBattle->mUnk_0e4[i].mUnk_08 = r;
            r++;
        }
    }
    for (i = 0; i < gResultsBattle->mUnk_0d8; i++) {
        if (gRaceSetup->mCurrentEntries[(u16) i].mPlayer.mTeamIndex == 1) {
            n++;
        }
    }
    if (r < 4 && n <= 4) {
        r = 4;
    }
    for (i = 0; i < gResultsBattle->mUnk_0d8; i++) {
        if (gRaceSetup->mCurrentEntries[(u16) i].mPlayer.mTeamIndex == 1) {
            gResultsBattle->mUnk_0e4[i].mUnk_08 = r;
            r++;
        }
    }
}

void func_02034024(void) {
    ResultsBattle *o;
    s32 a[8];
    s32 b[8];
    s32 c[8];
    s32 m;
    s32 r;
    s32 k;
    s32 v1;
    s32 i;
    s32 v2;
    s32 j;
    s32 v;
    s32 d;
    s32 e;
    s32 f;

    r = 0;
    v1 = 0;
    v2 = 0;
    for (i = 0; i < (o = gResultsBattle)->mUnk_0d8; i++) {
        a[i] = o->mUnk_0e4[i].mUnk_04;
    }
    for (i = 0; i < (o = *(ResultsBattle **) &gResultsBattle)->mUnk_0d8; i++) {
        if (gRaceSetup->mCurrentEntries[(u16) i].mPlayer.mTeamIndex == 0) {
            b[v1] = i;
            v1 = v1 + 1;
        } else {
            c[v2] = i;
            v2 = v2 + 1;
        }
    }
    for (d = 0; d < v1; d++) {
        v = -1;
        m = -1;
        for (k = 0; k < v1; k++) {
            if (v < a[b[k]]) {
                v = a[b[k]];
                m = k;
            }
        }
        gResultsBattle->mUnk_0e4[b[m]].mUnk_08 = r++;
        a[b[m]] = -2;
    }
    if (r < 4 && v2 <= 4) {
        r = 4;
    }
    for (j = 0; j < v2; j++) {
        e = -1;
        f = -1;
        for (k = 0; k < v2; k++) {
            if (e < a[c[k]]) {
                e = a[c[k]];
                f = k;
            }
        }
        gResultsBattle->mUnk_0e4[c[f]].mUnk_08 = r++;
        a[c[f]] = -2;
    }
}

void func_02033e6c(void) {
    u16 j;
    u16 k;
    s32 n;

    for (k = 0; k < gResultsBattle->mUnk_0d8; k++) {
        if (gResultsBattle->mMode == 3 || gRaceSetup->mRuleKind == 2) {
            gResultsBattle->mUnk_0e4[k].mUnk_04 = func_02033e6c_inline(GetLowByte(k))->mUnk_00;
        } else {
            gResultsBattle->mUnk_0e4[k].mUnk_04 = func_02033e6c_inline(GetLowByte(k))->mUnk_05;
        }
    }
    for (j = 0; j < gResultsBattle->mUnk_0d8; j++) {
        n = 0;
        for (k = 0; k < gResultsBattle->mUnk_0d8; k++) {
            if (j != k && gResultsBattle->mUnk_0e4[j].mUnk_04 < gResultsBattle->mUnk_0e4[k].mUnk_04) {
                n++;
            }
        }
        gResultsBattle->mUnk_0e4[j].mUnk_00 = n;
    }
    if (gRaceSetup->mUseTeams != 0) {
        if (gRaceSetup->mMode == MODE_BATTLE && gRaceSetup->mRuleKind == 1) {
            func_02034188();
        } else {
            func_02034024();
        }
    } else if (gRaceSetup->mMode == MODE_BATTLE) {
        for (k = 0; k < gResultsBattle->mUnk_0d8; k++) {
            gResultsBattle->mUnk_0e4[k].mUnk_08 = data_0217b488->mUnk_ec[k];
        }
    } else {
        for (k = 0; k < gResultsBattle->mUnk_0d8; k++) {
            gResultsBattle->mUnk_0e4[k].mUnk_08 = GetKartCupRank(k) - 1;
        }
    }
}

s32 func_02033e24(void) {
    s32 r;
    s32 i;

    r = 1;
    i = 0;
    for (; i < gResultsBattle->mUnk_0d8; i++) {
        r &= gResultsBattle->mUnk_0e4[i].mUnk_00 == 0 ? 1 : 0;
    }
    return r;
}

s32 func_02033dfc(void) {
    BOOL r;

    r = FALSE;
    if (gResultsBattle->mUnk_148 != FALSE && gResultsBattle->mTimer == 0) {
        r = TRUE;
    }
    return r;
}

s32 func_02033dd0(void) {
    BOOL r;

    r = FALSE;
    if (gResultsBattle->mUnk_148 != FALSE && gResultsBattle->mTimer < 0x12c) {
        r = TRUE;
    }
    return r;
}

#pragma thumb off
