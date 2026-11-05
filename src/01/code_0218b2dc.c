#include "01/code_0218b2dc.h"
#include "01/code_021882b8.h"
#include "01/code_02188cd8.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0209b60c.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "01/code_0218b9b4.h"
#include "01/unk_021a6000.h"
#include "01/code_02188000.h"
#include "01/code_0218c000.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Unknown/code_020ac524.h"
#include "Main/Unknown/code_020d4000.h"
#include "01/code_02185ef4.h"
#include "01/code_02187d14.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/unk_0217c000.h"
#include "01/code_02188158.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_020ac000.h"
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
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02109000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020f9c6c.h"

Unk021a7b64 data_ov001_021a7b64 = {
    0, 0x30c, func_ov001_0218b72c, func_ov001_0218b310, func_ov001_0218b2f4, 0, 0, func_ov001_0218b2dc, {0, 0, 0, 0, 0},
};

typedef struct Unk0218b928_local {
    s32 mUnk_00;
    Vec3 *mUnk_04;
    s32 mUnk_08;
    u32 mUnk_0c;
} Unk0218b928_local;
void func_ov001_0218b928(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    func_0208b7bc(0x418, &a->mUnk_000.mPos);
    func_0208b7bc(0x417, &a->mUnk_000.mPos);
    func_0208b7bc(0x416, &a->mUnk_000.mPos);
    {
        Unk0218b928_local local = {0x225, 0, 0xf, 0};

        local.mUnk_04 = &a->mUnk_000.mPos;
        local.mUnk_0c = func_020d4ef4(local.mUnk_04);
        func_0210b734(&local, func_02108e7c());
    }
    a->mUnk_000.mFlags |= data_ov001_021a659c;
    a->mUnk_000.mFlags |= data_ov001_021a65a0;
    a->mUnk_000.mFlags |= data_ov001_021a65a4;
}

void func_ov001_0218b8f8(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(a, (s32) (a->mPrm->mUnk_070), (s32) (a->mPrm->mUnk_074));
    func_ov001_02188e24(a, 0x3c, &func_ov001_0218b928);
}

void func_ov001_0218b8f0(void) {
    func_ov001_021882b8();
}

s32 func_ov001_0218b8d4(Unk02188950 *a) {
    int v1;
    v1 = func_02061fec();
    if (v1 == 1) {
        func_ov001_02188e88(a);
    }
    return 0;
}

s32 func_ov001_0218b850(Unk02188950 *a) {
    int v1;
    v1 = GetMapObjectModelNsbcaFrameIndex(a->mNsbmd);
    if (v1 == 0x4d) {
        func_ov001_02187af4(a);
        func_ov001_02187518(a, (u32) (((u32) 0xfffff99au)), (u32) 0, (u32) (((u32) 0xfffff99au)),
                            (u32) (((u32) 0x0000042bu)), (u32) 0);
        func_020d2774(&a->mUnk_000, (u32) (((u32) 0x0000021eu)));
    } else {
        v1 = GetMapObjectModelNsbcaFrameIndex(a->mNsbmd);
        if (v1 == 0x68) {
            func_ov001_02187af4(a);
            func_ov001_02187518(a, (u32) (((u32) 0xfffff99au)), (u32) 0, (u32) (((u32) 0xfffff99au)),
                                (u32) (((u32) 0x0000042cu)), (u32) 0);
            func_020d2774(&a->mUnk_000, (u32) (((u32) 0x0000021fu)));
        }
    }
    return 0;
}

void func_ov001_0218b828(Unk02188950 *a) {
    func_ov001_02187218(a, 8, func_ov001_0218b8d4);
    func_ov001_02188d64(a, a->mPrm->mUnk_064, a->mPrm->mUnk_068);
}

void func_ov001_0218b7fc(Unk02188950 *a) {
    func_ov001_02187218(a, 8, func_ov001_0218b850);
    func_ov001_02188d30(a, (s32) (a->mPrm->mUnk_058), (s32) (a->mPrm->mUnk_05c), (UnkFunc *) &func_ov001_0218b828);
}

void func_ov001_0218b7c8(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(a, (s32) (a->mPrm->mUnk_04c), (s32) (a->mPrm->mUnk_050));
    func_ov001_02188e24(a, a->mPrm->mUnk_054, &func_ov001_0218b7fc);
}

void func_ov001_0218b7a4(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(a, a->mPrm->mUnk_040, a->mPrm->mUnk_044);
}

void func_ov001_0218b770(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(a, (s32) (a->mPrm->mUnk_034), (s32) (a->mPrm->mUnk_038));
    func_ov001_02188e24(a, a->mPrm->mUnk_03c, &func_ov001_0218b7a4);
}

void func_ov001_0218b72c(Unk02188950 *a) {
    func_020ac588((u32) 0x191, 0x32, a);
    a->mUnk_000.mUnk_94 = HeapAlloc(GetHeap(func_020364e8()), 0x44);
    func_02109110((Unk0210bfbc *) (a->mUnk_000.mUnk_94), (u32) 0xf, (&a->mUnk_000.mPos));
    a->mUnk_000.mUnk_70 = data_0217cc6c[15];
}

void func_ov001_0218b6f8(Unk02188950 *a, void *b) {
    func_ov001_02188200(a, func_ov001_0218b6f8);
    if (a->mTimer == 0) {
        func_020d26ec(b, (u32) 0x224);
    }
}

void func_ov001_0218b640(Unk02188950 *a, void *b) {
    a->mUnk_000.mUnk_10.x = (s64) a->mPrm->mUnk_130 * gPairsByAngle[((u16) a->mMoveAngle >> 4) * 2] >> 12;
    a->mUnk_000.mUnk_10.y = 0;
    a->mUnk_000.mUnk_10.z = (s64) a->mPrm->mUnk_130 * gPairsByAngle[((u16) a->mMoveAngle >> 4) * 2 + 1] >> 12;
    a->mUnk_2d8 = 0xd;
    func_02073fb0(a->mUnk_000.mUnk_78 & 0x3fffffe0, 0x1000);
    func_ov001_02188200(a, func_ov001_0218b6f8);
    if (a->mTimer == 0) {
        func_020d26ec(b, (u32) 0x224);
    }
}

void func_ov001_0218b5d8(Unk0218d87c *a) {
    s32 i;
    Unk02188950 *obj;

    if (a != NULL) {
        for (i = 0; i < a->mUnk_04 && (obj = a->mUnk_00[i]) != NULL; i++) {
            func_ov001_0219b1c4(obj->mNsbmd, obj->mPrm->mUnk_080, obj->mPrm->mUnk_050, 0);
            if (func_02062ec4()) {
                func_ov001_0218b770(obj);
            } else {
                func_ov001_0218b7c8(obj);
            }
        }
    }
    SetStandingsEndCallback((void (*)(void)) func_ov001_0218b8f0);
}

void UpdateKuriking(u32 a, Unk02188950 *b) {
    s32 var;

    if (data_021759c0->mMode == 4 ? IsWinnerDecided() : 0) {
        if (func_ov001_021871f8(b, 1)) {
            if (data_021759c0->mMode == 4 ? IsKartEliminated((u16) data_021759c0->mEntryIndex) : 0) {
                func_ov001_0218b9b4(b);
            } else {
                func_ov001_0218b8f8(b);
            }
        }
    } else {
        if (func_ov001_021881a8(b, (Vec3 *) func_ov001_02187fc0(b), (s32) (b->mPrm->mUnk_0b4), 0)) {
            var = func_ov001_02187f7c(b);
            if (var >= 200) {
                if (func_ov001_021871f8(b, 8)) {
                    func_ov001_0218ba34(b);
                    func_ov001_02188200(b, func_ov001_0218b6f8);
                }
            } else if (var >= 100) {
                if (func_ov001_021871f8(b, 7)) {
                    func_ov001_0218bbac(b);
                    func_ov001_02188200(b, func_ov001_0218b6f8);
                }
            } else if (var >= 1) {
                if (func_ov001_021871f8(b, 1)) {
                    func_ov001_0218bde8(b);
                    func_ov001_02188200(b, func_ov001_0218b6f8);
                }
            }
            func_ov001_02187e78(b);
            if (b->mUnk_14c == 0) {
                func_ov001_02187e48(b, 3);
            }
        }
        if (func_ov001_021871f8(b, 2)) {
            if (func_ov001_02188104(b, b->mPrm->mUnk_124, b->mPrm->mUnk_128)) {
                func_ov001_0218c490(b);
                func_ov001_02188200(b, func_ov001_0218b640);
            }
        }
        if (func_ov001_021871f8(b, 1)) {
            func_ov001_0218c354(b);
            func_ov001_02188200(b, func_ov001_0218b640);
        }
        b->mUnk_2b8 = 1;
    }
    func_ov001_021864ac(a, b);
    func_ov001_0219b1fc(b->mNsbmd);
    var = b->mUnk_134 + 1;
    if (var >= func_ov001_02188220(b) * 30) {
        var = func_ov001_02188220(b) * 30;
    }
    b->mUnk_134 = var;
    var = b->mUnk_134;
    if (var >= GetMapObjectModelNsbmaFrameCount(b->mNsbmd) - 1) {
        var = GetMapObjectModelNsbmaFrameCount(b->mNsbmd) - 1;
    }
    b->mUnk_134 = var;
    SetMapObjectModelNsbmaFrameIndex(b->mNsbmd, (u16) b->mUnk_134);
}

void InitKuriking(Unk0218d87c *a) {
    s32 i;
    Unk02188950 *obj;

    if (a != NULL) {
        for (i = 0; i < a->mUnk_04 && (obj = a->mUnk_00[i]) != NULL; i++) {
            if (data_021759c0->mMode == 4) {
                func_ov001_02181b8c(obj);
            }
            func_ov001_021870e4(a, obj, ("kuriking.nsbmd"), ("kuriking.nsbca"), ("kuriking.prm"));
            func_ov001_021870b0(a, obj, ("sh_circle.nsbmd"));
            LoadMapObjectModelNsbtaAnimation(obj->mNsbmd, "kuriking.nsbta");
            LoadMapObjectModelNsbtpAnimation(obj->mNsbmd, "kuriking.nsbtp");
            LoadMapObjectModelNsbmaAnimation(obj->mNsbmd, "kuriking.nsbma");
            func_ov001_0218c728(obj);
            func_ov001_02188200(obj, func_ov001_0218b6f8);
        }
    }
}

void DrawKuriking(void *a, Unk02188950 *b) {
    func_ov001_02186368(a, b);
    func_ov001_021861f4(a, b, 0);
}

void func_ov001_0218b310(void) {
    void *v7 = &func_ov001_02185fb0;
    void *v8 = &func_ov001_02185f04;
    void *v9 = &func_ov001_021860cc;
    void *v11 = func_ov001_0219b510(v7, v8, v9, (u32) 0x2u, (u16) ((u32) 0x1u), (u16) ((u32) 0x0u), (u16) ((u32) 0x0u));
}

void *func_ov001_0218b2f4(void) {
    return (void *) func_0209bf1c(InitKuriking, DrawKuriking, func_ov001_02187098);
}

void *func_ov001_0218b2dc(void) {
    return (void *) func_0209bf48(func_ov001_0218b5d8, UpdateKuriking, NULL);
}
