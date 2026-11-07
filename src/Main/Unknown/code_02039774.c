#include "Main/Unknown/code_02039774.h"
#include "Main/Unknown/unk_02175000.h"
#include "wvr.h"
#include "code_0200fc8c.h"
#include "code_02148950.h"
#include "code_0214d018.h"
#include "registers.h"

static inline u32 func_020399a8_inline(void) {
    return data_02175614.mUnk_00 == 2;
}

void InitWvrState(void) {
    data_02175614.mUnk_00 = 1;
    data_02175614.mUnk_04 = NULL;
}

void ClearLcdcBanksByState(void) {
    switch (data_02175614.mUnk_00) {
        case 0:
            GX_SetBankForLCDC(0x1f7);
            MemFillWordsByBlock_inline((void *) 0x6800000, 0x60000);
            MemFillWordsByBlock_inline((void *) 0x6880000, 0x24000);
            break;
        case 2:
            break;
        case 1:
        case 3:
            GX_SetBankForLCDC(0x1ff);
            MemFillWordsByBlock_inline((void *) 0x6800000, 0xa4000);
            break;
    }
    GX_DisableBankForLCDC();
}

void SetBankForARM7ByState(u32 a) {
    switch (data_02175614.mUnk_00) {
        case 0:
        case 2:
            break;
        case 1:
        case 3:
            GX_SetBankForARM7(a);
            break;
    }
}

void DisableAllBanks(void) {
    GX_DisableBankForBG();
    GX_DisableBankForOBJ();
    GX_DisableBankForBGExtPltt();
    GX_DisableBankForOBJExtPltt();
    GX_DisableBankForTex();
    GX_DisableBankForTexPltt();
    GX_DisableBankForClearImage();
    GX_DisableBankForSubBG();
    GX_DisableBankForSubOBJ();
    GX_DisableBankForSubBGExtPltt();
    GX_DisableBankForSubOBJExtPltt();
    GX_DisableBankForLCDC();
    switch (data_02175614.mUnk_00) {
        case 0:
        case 2:
            break;
        case 1:
        case 3:
            GX_DisableBankForARM7();
            break;
    }
}

// Stores the state; for states 0 and 1 calls the stored callback with 0 or 1.
void WvrCallback(u32 a, s32 b) {
    if (b != 0) {
        OS_Terminate();
    }
    data_02175614.mUnk_00 = a;
    if (data_02175614.mUnk_04 == NULL) {
        return;
    }
    switch (a) {
        case 0:
            data_02175614.mUnk_04(0);
            break;
        case 1:
            data_02175614.mUnk_04(1);
            break;
    }
}

void ClearLcdcBankAndStartWvrAndWait(void) {
    if (data_02175614.mUnk_00 != 0 && data_02175614.mUnk_00 != 3) {
        data_02175614.mUnk_00 = 2;
        GX_SetBankForLCDC(8);
        MemFillWordsByBlock_inline((void *) 0x6860000, 0x20000);
        GX_DisableBankForLCDC();
        if (WVR_StartUpAsync(8, WvrCallback, 0) != 1) {
            OS_Terminate();
        }
    }
    while (func_020399a8_inline() != 0) {
    }
}

void StopWvrAndWait(void) {
    if (data_02175614.mUnk_00 != 1 && data_02175614.mUnk_00 != 3) {
        data_02175614.mUnk_00 = 2;
        if (WVR_TerminateAsync(WvrCallback, 1) != 1) {
            OS_Terminate();
        }
    }
    while (func_020399a8_inline() != 0) {
    }
}

s32 Vec3NormalizeAndGetLengthUnchecked(const Vec3 *v, Vec3 *v1) {
    s64 w;
    s32 r;
    s64 q;
    s64 t;
    w = (s64) v->x * v->x;
    w += (s64) v->y * v->y;
    w += (s64) v->z * v->z;
    reg_CP_DIVCNT = 2;
    reg_CP_DIV_NUMER = 0x1000000000000LL << 8;
    reg_CP_DIV_DENOM = w;
    reg_CP_SQRTCNT = 1;
    reg_CP_SQRT_PARAM = w << 2;
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    r = reg_CP_SQRT_RESULT;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    q = reg_CP_DIV_RESULT;
    t = q * r;
    v1->x = (t * v->x + 0x100000000000LL) >> 45;
    v1->y = (t * v->y + 0x100000000000LL) >> 45;
    v1->z = (t * v->z + 0x100000000000LL) >> 45;
    return (r + 1) >> 1;
}

s32 Vec3DotUnrounded(const Vec3 *a, const Vec3 *b) {
    return ((s64) a->x * b->x + (s64) a->y * b->y + (s64) a->z * b->z) >> 12;
}

void Vec3CrossUnrounded(const Vec3 *a, const Vec3 *b, Vec3 *v1) {
    s64 x;
    s64 y;
    s64 z;
    x = (s64) a->y * b->z - (s64) a->z * b->y;
    y = (s64) a->z * b->x - (s64) a->x * b->z;
    z = (s64) a->x * b->y - (s64) a->y * b->x;
    v1->x = x >> 12;
    v1->y = y >> 12;
    v1->z = z >> 12;
}

void func_02039774(void) {
    data_usa_021755e4.mUnk_08 = 0;
    data_usa_021755e4.mUnk_0a = 0;
    data_usa_021755e4.mUnk_0c = 0;
    data_usa_021755e4.mUnk_0e = 3;
    data_usa_021755e4.mUnk_00 = 0;
    data_usa_021755e4.mUnk_02 = 0;
    data_usa_021755e4.mUnk_04 = 0;
    data_usa_021755e4.mUnk_06 = 3;
}
