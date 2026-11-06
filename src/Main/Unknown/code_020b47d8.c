#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0203c8c0.h"
#include "code_0200eddc.h"
#include "code_02021f6c.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02021e8c.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0203c5f8.h"

u16 func_020b4d9c(void) {
    Unk021759c0 *p = data_021759c0;

    return p->mUnk_00c == 1 ? p->mUnk_063 : p->mEntryIndex;
}

u16 func_020b4d2c(void) {
    u16 a;

    a = func_0203c8c0((u16) (data_021759c0->mUnk_00c == 1 ? data_021759c0->mUnk_063 : data_021759c0->mEntryIndex));
    if (IsKartEnded((u16) (data_021759c0->mUnk_00c == 1 ? data_021759c0->mUnk_063 : data_021759c0->mEntryIndex)) == 0) {
        a = a - 1;
    }
    return a;
}

void func_020b4cec(s32 *a, s32 b) {
    s32 v;

    if (b != 0) {
        v = FX_Div(0x1000, b);
    } else {
        v = 0x1000;
    }
    a[3] = v;
    a[0] = a[3];
    a[2] = 0;
    a[1] = a[2];
}

void func_020b4cb0(s32 *a, s32 b) {
    s32 s = gPairsByAngle[(b >> 4) * 2];
    s32 c = gPairsByAngle[(b >> 4) * 2 + 1];

    a[0] = c;
    a[1] = s;
    a[2] = -s;
    a[3] = c;
}

void func_020b4c74(s32 *a, s32 b) {
    s32 c = gPairsByAngle[(b >> 4) * 2 + 1];
    s32 s;

    a[0] = -c;
    s = gPairsByAngle[(b >> 4) * 2];
    a[1] = s;
    a[2] = s;
    a[3] = c;
}

void func_020b4bf8(s32 *a, s32 b, s32 c) {
    s32 i = c >> 4;
    s32 s = gPairsByAngle[i * 2];
    s32 v1 = gPairsByAngle[i * 2 + 1];
    s32 v;

    if (b != 0) {
        v = FX_Div(0x1000, b);
    } else {
        v = 0x1000;
    }
    a[0] = (s32) (((s64) v1 * v) >> 12);
    a[1] = (s32) (((s64) s * v) >> 12);
    a[2] = -a[1];
    a[3] = a[0];
}

BOOL func_020b4b98(s32 a) {
    switch (data_021759d0->mUnk_04) {
        case 0:
        case 1:
        case 3:
        case 4:
        case 5:
        default:
            if (a != 1) {
                return TRUE;
            }
            return FALSE;
        case 2:
            if (a != 1 && a != 0) {
                return TRUE;
            }
            return FALSE;
    }
}

BOOL func_020b4b54(void) {
    switch (data_021759d0->mUnk_04) {
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

s32 func_020b4b10(void) {
    switch (data_021759d0->mUnk_04) {
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

BOOL func_020b4acc(void) {
    switch (data_021759d0->mUnk_04) {
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

void LoadNclrData(Nclr **v1, void *a) {
    Unk02021fd0 *r;

    if (a != NULL) {
        r = FindPartByTag(a, 0x504c5454);
        if (r != NULL) {
            *v1 = (Nclr *) (r + 1);
            NNS_G2dUnpackNCL((NNSG2dPaletteData *) *v1);
        }
    }
    DC_FlushRange((*v1)->mData, (*v1)->mDataSize);
}

void LocateNclr(Nclr **v1, void *a) {
    Unk02021fd0 *r;

    if (a == NULL) {
        return;
    }
    r = FindPartByTag(a, 0x504c5454);
    if (r != NULL) {
        *v1 = (Nclr *) (r + 1);
    }
}

void LoadNcgrData2(Ncgr **v1, void *a) {
    Unk02021fd0 *r;

    if (a != NULL) {
        r = FindPartByTag(a, 0x43484152);
        if (r != NULL) {
            *v1 = (Ncgr *) (r + 1);
            NNS_G2dUnpackBGNCG((NNSG2dCharacterData *) *v1);
        }
    }
    DC_FlushRange((*v1)->mData, (*v1)->mDataSize);
}

void LocateNcgr2(Ncgr **v1, void *a) {
    Unk02021fd0 *r;

    if (a == NULL) {
        return;
    }
    r = FindPartByTag(a, 0x43484152);
    if (r != NULL) {
        *v1 = (Ncgr *) (r + 1);
    }
}

void LoadNcgrData(Ncgr **v1, void *a) {
    Unk02021fd0 *r;

    if (a != NULL) {
        r = FindPartByTag(a, 0x43484152);
        if (r != NULL) {
            *v1 = (Ncgr *) (r + 1);
            NNS_G2dUnpackNCG((NNSG2dCharacterData *) *v1);
        }
    }
    DC_FlushRange((*v1)->mData, (*v1)->mDataSize);
}

void LocateNcgr(Ncgr **v1, void *a) {
    Unk02021fd0 *r;

    if (a == NULL) {
        return;
    }
    r = FindPartByTag(a, 0x43484152);
    if (r != NULL) {
        *v1 = (Ncgr *) (r + 1);
    }
}

void LoadNcerData(Unk02021dc8 **v1, void *a) {
    Unk02021fd0 *r;

    if (a == NULL) {
        return;
    }
    r = FindPartByTag(a, 0x4345424b);
    if (r == NULL) {
        return;
    }
    *v1 = (Unk02021dc8 *) (r + 1);
    NNS_G2dUnpackNCE(*v1);
}

void LocateNcer(Unk02021dc8 **v1, void *a) {
    Unk02021fd0 *r;

    if (a == NULL) {
        return;
    }
    r = FindPartByTag(a, 0x4345424b);
    if (r != NULL) {
        *v1 = (Unk02021dc8 *) (r + 1);
    }
}

void LoadNanrData(Unk02021dc8 **v1, void *a) {
    Unk02021fd0 *r;

    if (a == NULL) {
        return;
    }
    r = FindPartByTag(a, 0x41424e4b);
    if (r == NULL) {
        return;
    }
    *v1 = (Unk02021dc8 *) (r + 1);
    NNS_G2dUnpackNAN(*v1);
}

void LoadNscrData(Nscr **v1, void *a) {
    Unk02021fd0 *r;

    if (a != NULL) {
        r = FindPartByTag(a, 0x5343524e);
        if (r != NULL) {
            *v1 = (Nscr *) (r + 1);
            NNS_G2dGetUnpackedScreenData(a, (Unk02021fd0 **) v1);
        }
    }
    DC_FlushRange((*v1)->mData, (*v1)->mDataSize);
}

void LocateNscr(Nscr **v1, void *a) {
    Unk02021fd0 *r;

    if (a == NULL) {
        return;
    }
    r = FindPartByTag(a, 0x5343524e);
    if (r != NULL) {
        *v1 = (Nscr *) (r + 1);
    }
}
