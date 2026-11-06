#include "01/code_0218155c.h"

#include "01/code_02188950.h"
#include "01/code_02188e88.h"
#include "01/unk_021a9000.h"
#include "01/code_02181000.h"
#include "03/code_021b94b8.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0203e74c.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Unknown/code_020a02f8.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_02108edc.h"
#include "Main/Unknown/code_0214d000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_0210b000.h"
#include "01/code_02182000.h"
#include "01/code_02183000.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_02108000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"

MissionRunData *gMissionRunData;

void AddMissionRunMapObject(Unk02188950 *a) {
    u8 n;
    u16 k;

    n = data_021759c0->mKartCount;
    k = gMissionRunData->mMapObjectCount + n;
    gMissionRunData->mMapObjects[k - n] = a;
    func_020a1728(k);
    gMissionRunData->mMapObjectCount++;
}

Unk02188950 *GetMissionRunMapObject(int a) {
    return gMissionRunData->mMapObjects[a - data_021759c0->mKartCount];
}

u8 func_ov001_02181b54(void) {
    return data_021759c0->mKartCount;
}

u16 GetMissionRunMapObjectLastIndex(void) {
    return gMissionRunData->mMapObjectCount + data_021759c0->mKartCount - 1;
}

void func_ov001_02181aa0(void) {
    MissionRunData *p;
    u32 n;

    if ((data_021759c0->mMode == MODE_MISSION_RUN ? IsWinnerDecided() : 0) != FALSE) {
        return;
    }
    p = gMissionRunData;
    n = func_ov001_0218180c();
    if (p->mCount >= n) {
        return;
    }
    p->mCount = p->mCount + 1;
    func_02108edc(gMissionRunData->mCount, func_ov001_0218180c());
    switch (data_021759c0->mUnk_2f) {
        case 0:
        case 1:
        case 3:
        case 5:
        case 7:
            n = func_ov001_0218180c();
            if (gMissionRunData->mCount >= n) {
                func_0203e74c(data_021759c0->mEntryIndex);
            }
            break;
    }
}

Vec3 *GetMissionRunKartPos(void) {
    return &gMissionRunData->mKartPos;
}

Vec3 *GetMissionRunPrevKartPos(void) {
    return &gMissionRunData->mPrevKartPos;
}

u16 GetMissionRunKartHeadingAngle(void) {
    return (gMissionRunData->mKartHeadingAngle);
}

u16 GetMissionRunPrevKartHeadingAngle(void) {
    return (gMissionRunData->mPrevKartHeadingAngle);
}

void CreateMissionRunData(void) {
    Kart *c;
    MissionRunData *o;

    gMissionRunData = HeapAlloc(GetHeap(func_020364e8()), 0x68);
    c = GetKart((u16) data_021759c0->mEntryIndex);
    o = gMissionRunData;
    o->mPrevKartPos = c->mPos;
    o->mKartPos = o->mPrevKartPos;
    o->mPrevKartHeadingAngle = c->mHeadingAngle;
    o = gMissionRunData;
    o->mKartHeadingAngle = o->mPrevKartHeadingAngle;
}

void UpdateMissionRunData(void) {
    Kart *c;
    MissionRunData *o;

    c = GetKart((u16) data_021759c0->mEntryIndex);
    if ((c->mUnk_48 & 0x200) == 0) {
        o = gMissionRunData;
        o->mPrevKartPos = o->mKartPos;
        o->mPrevKartHeadingAngle = o->mKartHeadingAngle;
        o = gMissionRunData;
        o->mKartPos = c->mPos;
        o->mKartHeadingAngle = c->mHeadingAngle;
    }
    if (data_021759c0->mMode == MODE_MISSION_RUN ? IsWinnerDecided() : 0) {
        if (data_021759c0->mMode == MODE_MISSION_RUN ? IsKartEliminated((u16) data_021759c0->mEntryIndex) : 0) {
            if (GetBalloonOrShineCount(data_021759c0->mEntryIndex)) {
                gMissionRunData->mUnk_00 += 1;
                if (gMissionRunData->mUnk_00 > 0xf) {
                    gMissionRunData->mUnk_00 = 0;
                    func_020a1748(data_021759c0->mEntryIndex);
                    return;
                }
            }
        }
        return;
    }
    {
        u32 m = data_021759c0->mUnk_2f;
        if (m == 1 || m == 5) {
            if (GetRaceUpdateFramesMod8() == 0) {
                o = gMissionRunData;
                if (o->mUnk_0c != 0) {
                    o->mUnk_0c -= 1;
                    o = gMissionRunData;
                    if (o->mCount != 0) {
                        o->mCount -= 1;
                        gMissionRunData->mUnk_06 += 1;
                    }
                    if (gMissionRunData->mUnk_20 != NULL) {
                        gMissionRunData->mUnk_20();
                    }
                    gMissionRunData->mUnk_0e = 0;
                } else if (o->mUnk_0a != 0) {
                    o->mUnk_0a -= 1;
                    o = gMissionRunData;
                    if (o->mCount != 0) {
                        o->mCount -= 1;
                    }
                    if (gMissionRunData->mUnk_1c != NULL) {
                        gMissionRunData->mUnk_1c();
                    }
                    gMissionRunData->mUnk_0e = 0;
                } else if (o->mPendingCountUp != 0) {
                    o->mPendingCountUp -= 1;
                    func_ov001_02181aa0();
                    if (gMissionRunData->mUnk_18 != NULL) {
                        gMissionRunData->mUnk_18();
                    }
                }
            }
            o = gMissionRunData;
            if (o->mUnk_0e != 0) {
                o->mUnk_0e -= 1;
                o = gMissionRunData;
                if (o->mUnk_0e == 0) {
                    if (o->mUnk_24 != NULL) {
                        o->mUnk_24();
                    }
                }
            }
        }
    }
}

void func_ov001_02181844(u16 a, u16 b, u16 c, u16 d) {
    gMissionRunData->mUnk_10 = a;
    gMissionRunData->mUnk_12 = b;
    gMissionRunData->mUnk_14 = c;
    gMissionRunData->mUnk_16 = d;
}

s32 func_ov001_02181838(void) {
    return (gMissionRunData->mUnk_0e);
}

void func_ov001_0218182c(u32 p0) {
    gMissionRunData->mUnk_0e = p0;
}

u32 GetMissionRunCount(void) {
    return (gMissionRunData->mCount);
}

u32 func_ov001_0218180c(void) {
    u32 v = data_021759c0->mUnk_37;
    if (v == 0) {
        v = 1;
    }
    return v;
}

s32 func_ov001_02181800(void) {
    return (gMissionRunData->mUnk_06);
}

void func_ov001_021817e0(void) {
    if (data_021759c0->mUnk_2f == '\a') {
        func_ov001_02181aa0();
    }
}

void func_ov001_0218175c(s32 b) {
    Unk021759c0 *p = data_021759c0;
    u32 m = p->mUnk_2f;
    if (m == 3 || m == 7 || m == 0) {
        u32 a = p->mUnk_3c;
        if (a == 0 && p->mUnk_3e == 0 && p->mUnk_40 == 0 && p->mUnk_42 == 0 && b > 400 && b < 500) {
            func_ov001_02181aa0();
            return;
        }
        if (b == a || b == p->mUnk_3e || b == p->mUnk_40 || b == p->mUnk_42) {
            func_ov001_02181aa0();
        }
    }
}

void func_ov001_0218173c(void) {
    if (data_021759c0->mMode == MODE_MISSION_RUN) {
        func_ov001_02181678(5);
    }
}

void func_ov001_0218171c(void) {
    if (data_021759c0->mUnk_2f == 4) {
        func_ov001_02181aa0();
    }
}

void func_ov001_021816fc(void) {
    if (data_021759c0->mUnk_2f == 0) {
        func_ov001_02181aa0();
    }
}

BOOL func_ov001_021816b4(void) {
    Unk021816b4 *list;
    Balloon *e;
    s32 i;

    list = func_02100138(MAP_OBJECT_KIND_BALLOON);
    if (list != NULL) {
        for (i = 0; i < list->mUnk_04 && (e = list->mUnk_00[i]) != NULL; i++) {
            if ((e->mUnk_00.mFlags & 0x100) == 0) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

void func_ov001_021816a8(UnkFunc *p0) {
    gMissionRunData->mUnk_18 = p0;
}

void func_ov001_0218169c(UnkFunc *p0) {
    gMissionRunData->mUnk_1c = p0;
}

void func_ov001_02181690(UnkFunc *p0) {
    gMissionRunData->mUnk_20 = p0;
}

void func_ov001_02181678(u32 a) {
    MissionRunData *p = gMissionRunData;
    u16 lim = p->mCount;
    if (a >= lim) {
        a = lim;
    }
    p->mUnk_0a += a;
}

void func_ov001_02181660(u16 a) {
    MissionRunData *p = gMissionRunData;
    u16 lim = p->mCount;
    if (a >= lim) {
        a = lim;
    }
    p->mUnk_0c += a;
}

void func_ov001_02181630(short a) {
    gMissionRunData->mUnk_06 += a;
    if (gMissionRunData->mUnk_06 > func_ov001_0218180c()) {
        gMissionRunData->mUnk_06 = func_ov001_0218180c();
    }
}

void func_ov001_021815d0(s32 p0) {
    s32 i;

    for (i = 0; i < p0; i++) {
        if (++gMissionRunData->mPendingCountUp > func_ov001_0218180c()) {
            gMissionRunData->mPendingCountUp = func_ov001_0218180c();
            return;
        }
        if (gMissionRunData->mUnk_0e == 0) {
            gMissionRunData->mUnk_0e = gMissionRunData->mUnk_10;
        } else {
            gMissionRunData->mUnk_0e += gMissionRunData->mUnk_14;
            if (gMissionRunData->mUnk_0e > gMissionRunData->mUnk_12) {
                gMissionRunData->mUnk_0e = gMissionRunData->mUnk_12;
            }
        }
    }
}

void func_ov001_0218155c(s32 p0) {
    s32 i;

    if ((u32) p0 >= gMissionRunData->mUnk_06) {
        p0 = gMissionRunData->mUnk_06;
    }
    for (i = 0; i < p0; i++) {
        gMissionRunData->mUnk_06--;
        if (++gMissionRunData->mPendingCountUp > func_ov001_0218180c()) {
            gMissionRunData->mPendingCountUp = func_ov001_0218180c();
            return;
        }
        if (gMissionRunData->mUnk_0e == 0) {
            gMissionRunData->mUnk_0e = gMissionRunData->mUnk_10;
        } else {
            gMissionRunData->mUnk_0e += gMissionRunData->mUnk_16;
            if (gMissionRunData->mUnk_0e > gMissionRunData->mUnk_12) {
                gMissionRunData->mUnk_0e = gMissionRunData->mUnk_12;
            }
        }
    }
}
