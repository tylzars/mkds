#include "01/code_021830b4.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0209b60c.h"
#include "Main/Unknown/code_0209bef0.h"
#include "01/code_02184274.h"
#include "01/code_02184cc8.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/code_0210b000.h"

void func_ov001_021841e0(Unk02188950 *a) {
    Vec3 sp = {0, 0, 0};

    sp.y = a->mPrm->mUnk_238;
    func_ov001_02187218(a, 8, func_ov001_02184274);
    func_ov001_02188d64(a, a->mPrm->mUnk_224, a->mPrm->mUnk_228);
    SetVelocity(a, &sp);
    func_ov001_02188c90(a);
    func_ov001_02188cd8(a, a->mPrm->mUnk_230, a->mPrm->mUnk_234);
    func_ov001_02188db8(a, func_ov001_021842ec);
    a->mUnk_000.mFlags |= data_ov001_021a6578;
}

void func_ov001_02184160(Unk02188950 *a) {
    u32 v1;
    func_ov001_02187218(a, 8, NULL);
    func_ov001_02188d64(a, a->mPrm->mUnk_210, a->mPrm->mUnk_214);
    v1 = a->mPrm->mUnk_21c;
    func_ov001_02188c48(a, v1, v1);
    SetAnglePointAndMoveAnglePoint(a, (Vec3 *) a->mUnk_000.mCourseMapRow);
    v1 = a->mPrm->mUnk_218;
    func_ov001_02188cd8(a, v1, v1);
    func_ov001_02188e24(a, a->mPrm->mUnk_220, &func_ov001_021841e0);
}

void func_ov001_02183ff4(Unk02188950 *a) {
    Vec3 sp;
    s32 scale;

    sp.x = a->mUnk_000.mPos.x;
    sp.y = 0;
    sp.z = a->mUnk_000.mPos.z;
    if ((s64) sp.z * sp.z + ((s64) sp.x * sp.x + (s64) sp.y * sp.y) >= 16) {
        Vec3NormalizeAndGetLengthUnchecked(&sp, &sp);
    }
    scale = a->mPrm->mUnk_204;
    sp.x = (s64) sp.x * scale >> 12;
    sp.y = (s64) sp.y * scale >> 12;
    sp.z = (s64) sp.z * scale >> 12;
    sp.y = -a->mPrm->mUnk_208;
    func_ov001_02187218(a, 8, NULL);
    func_ov001_02188d64(a, a->mPrm->mUnk_1fc, a->mPrm->mUnk_200);
    func_ov001_02188c90(a);
    func_ov001_02188cec(a, 0);
    SetVelocity(a, &sp);
    func_ov001_0218720c(a);
    func_ov001_02188e24(a, a->mPrm->mUnk_20c, func_ov001_02184160);
    func_ov001_021874c4(a, 0, 0, 0, 0x423, 0);
    func_ov001_021874c4(a, 0, 0, 0, 0x425, 0);
    func_ov001_02187444(a, 4, 0);
    StartMapObjectSound(&a->mUnk_000, 0x244);
    a->mUnk_000.mFlags |= data_ov001_021a6578;
}

void func_ov001_02183f0c(Unk02188950 *a) {
    Vec3 sp8 = {0, 0, 0};

    func_ov001_02187218(a, 8, NULL);
    func_ov001_02188d64(a, a->mPrm->mUnk_070, a->mPrm->mUnk_074);
    SetVelocity(a, &sp8);
    func_ov001_0218720c(a);
    func_ov001_02188c90(a);
    func_ov001_02188cec(a, 0);
    if (a->mUnk_000.mKind == 0x1f5) {
        func_ov001_021874c4(a, 0, 0, 0, 0x423, 0);
        func_ov001_021874c4(a, 0, 0, 0, 0x425, 0);
    } else if (a->mUnk_000.mKind == 0x1f6) {
        func_ov001_021874c4(a, 0, 0, 0, 0x423, 0);
        func_ov001_021874c4(a, 0, 0, 0, 0x425, 0);
    }
    {
        Unk021a78d8 sp14 = {0x212, 0, 0xc, 0};

        sp14.mUnk_04 = &a->mUnk_000.mPos;
        sp14.mUnk_0c = GetHorizontalCameraDistanceSquared(&a->mUnk_000.mPos);
        func_0210b734(&sp14, func_02108e7c());
    }
    a->mUnk_000.mFlags |= data_ov001_021a6578;
}

void func_ov001_02183ed4(Unk02188950 *a) {
    func_ov001_02187218(a, 5, NULL);
    func_ov001_02188d30(a, a->mPrm->mUnk_160, a->mPrm->mUnk_164, NULL);
    func_ov001_02188cec(a, 0);
}

u32 func_ov001_02183ebc(Unk02188950 *a) {
    StartMapObjectSoundWhileRequested(&a->mUnk_000, 0x00000243u);
    return 0;
}

void func_ov001_02183e40(Unk02188950 *a) {
    Vec3 sp = {0, 0, 0};

    sp.y = a->mPrm->mUnk_154;
    func_ov001_02187218(a, 5, (s32(*)(Unk02188950 *)) func_ov001_02183ebc);
    func_ov001_02188d64(a, a->mPrm->mUnk_14c, a->mPrm->mUnk_150);
    func_ov001_02188a8c(a, a->mPrm->mUnk_158, a->mPrm->mUnk_158);
    SetVelocity(a, &sp);
    func_ov001_02188db8(a, func_ov001_02183ed4);
}

void func_ov001_02183dec(Unk02188950 *a) {
    func_ov001_02187218(a, 5, NULL);
    func_ov001_02188d30(a, a->mPrm->mUnk_12c, a->mPrm->mUnk_130, NULL);
    func_ov001_02188e24(a, a->mPrm->mUnk_134, &func_ov001_02183e40);
    func_ov001_02188cec(a, 0);
}

s32 func_ov001_02183d94(Unk02188950 *a) {
    SetAnglePointAndMoveAnglePoint(a, &GetKart((u16) gRaceSetup->mEntryIndex)->mPos);
    if (a->mSpeed < a->mPrm->mUnk_108) {
        func_ov001_02188200(a, func_ov001_02184874);
        func_ov001_02184e6c(a);
    }
    return 0;
}

void func_ov001_02183cc8(Unk02188950 *a) {
    Kart *r4;

    r4 = GetKart((u16) gRaceSetup->mEntryIndex);
    func_ov001_02187218(a, 2, func_ov001_02183d94);
    func_ov001_02188d64(a, a->mPrm->mUnk_10c, a->mPrm->mUnk_110);
    func_ov001_02188c48(a, a->mPrm->mUnk_118, a->mPrm->mUnk_118);
    SetAnglePointAndMoveAnglePoint(a, &r4->mPos);
    func_ov001_021889c8(a);
    func_ov001_02188cd8(a, 0, a->mPrm->mUnk_114);
    func_ov001_02188dcc(a, func_ov001_02184cc8);
    func_ov001_02188200(a, func_ov001_021843b0);
    if (a->mSpeed < a->mPrm->mUnk_114) {
        func_ov001_02188200(a, func_ov001_02184874);
    }
    func_ov001_02184e18((u16 *) a);
}

void func_ov001_02183c54(Unk02188950 *a) {
    func_ov001_02187218(a, 2, NULL);
    func_ov001_02188d64(a, a->mPrm->mUnk_0f4, a->mPrm->mUnk_0f8);
    func_ov001_02188c90(a);
    func_ov001_02188cd8(a, a->mPrm->mUnk_0fc, a->mPrm->mUnk_100);
    func_ov001_02188e24(a, a->mPrm->mUnk_104, &func_ov001_02183cc8);
    func_ov001_02188200(a, func_ov001_021843b0);
    func_ov001_02184e18((u16 *) a);
}

void func_ov001_02183c08(Unk02188950 *a) {
    func_ov001_02187218(a, 2, NULL);
    func_ov001_02188d64(a, a->mPrm->mUnk_0e8, a->mPrm->mUnk_0ec);
    func_ov001_02188c90(a);
    func_ov001_02188e24(a, a->mPrm->mUnk_0f0, &func_ov001_02183c54);
    func_ov001_02184e6c(a);
}

void func_ov001_02183b9c(Unk02188950 *a) {
    func_ov001_02187218(a, 2, NULL);
    func_ov001_02188d64(a, a->mPrm->mUnk_080, a->mPrm->mUnk_084);
    func_ov001_02188c90(a);
    func_ov001_02188cd8(a, a->mPrm->mUnk_088, a->mPrm->mUnk_08c);
    func_ov001_02188e24(a, a->mPrm->mUnk_090, &func_ov001_02183cc8);
    func_ov001_02188200(a, func_ov001_021843b0);
    func_ov001_02184e18((u16 *) a);
}

void func_ov001_02183ad8(Unk02188950 *a) {
    Kart *r4;

    r4 = GetKart((u16) gRaceSetup->mEntryIndex);
    func_ov001_02187218(a, 3, NULL);
    func_ov001_02188d64(a, a->mPrm->mUnk_0cc, a->mPrm->mUnk_0d0);
    func_ov001_02188c48(a, a->mPrm->mUnk_0d8, a->mPrm->mUnk_0d8);
    SetAnglePointAndMoveAnglePoint(a, &r4->mPos);
    func_ov001_02188cec(a, a->mPrm->mUnk_0d4);
    func_ov001_02188de0(a, 0, a->mPrm->mUnk_0e4, &r4->mPos, func_ov001_02183c08);
    if (a->mUnk_000.mKind == 0x1f5) {
        StartMapObjectSound(&a->mUnk_000, 0x214);
    } else if (a->mUnk_000.mKind == 0x1f6) {
        StartMapObjectSound(&a->mUnk_000, 0x245);
    }
    func_ov001_02184e6c(a);
}

void func_ov001_021839ac(Unk02188950 *a) {
    if (func_ov001_021881a8(a, (Vec3 *) a->mUnk_000.mCourseMapRow, (a->mPrm->mUnk_180 + 0x28), 0)) {
        func_ov001_02187218(a, 3, NULL);
        func_ov001_02188d64(a, a->mPrm->mUnk_168, a->mPrm->mUnk_16c);
        func_ov001_02188c48(a, a->mPrm->mUnk_178, 0x270f000);
        SetAnglePointAndMoveAnglePoint(a, &a->mUnk_000.mCourseMapRow->mUnk_00);
        func_ov001_02188cd8(a, a->mPrm->mUnk_174, a->mPrm->mUnk_170);
        func_ov001_02188e24(a, a->mPrm->mUnk_17c, NULL);
        func_ov001_02188200(a, func_ov001_02184874);
    } else {
        func_ov001_02187218(a, 3, NULL);
        func_ov001_02188d64(a, a->mPrm->mUnk_168, a->mPrm->mUnk_16c << 2);
        func_ov001_02188c48(a, a->mPrm->mUnk_178, 0x270f000);
        SetAnglePointAndMoveAnglePoint(a, &a->mUnk_000.mCourseMapRow->mUnk_00);
        func_ov001_02188cd8(a, -a->mPrm->mUnk_174, a->mPrm->mUnk_170);
        func_ov001_02188e24(a, a->mPrm->mUnk_17c, NULL);
        func_ov001_02188200(a, func_ov001_02184874);
    }
    func_ov001_02184e6c(a);
}

void func_ov001_02183894(Unk02188950 *a) {
    Unk02188950_a0 *a0;

    a0 = a->mPrm;
    if (func_ov001_021881a8(a, &func_ov001_02187fc0(a)->mUnk_00, a0->mUnk_0ac, a0->mUnk_0b0)) {
        func_ov001_02187218(a, 1, NULL);
        func_ov001_02188d64(a, a->mPrm->mUnk_0b8, a->mPrm->mUnk_0bc);
        func_ov001_02188b2c(a, a->mPrm->mUnk_0c4, a->mPrm->mUnk_0c4, 0);
        SetAnglePointAndMoveAnglePoint(a, &func_ov001_02187fc0(a)->mUnk_00);
        func_ov001_02188cd8(a, a->mPrm->mUnk_0c0, a->mPrm->mUnk_0c0);
        func_ov001_02188e24(a, a->mPrm->mUnk_0c8, NULL);
    } else {
        func_ov001_02187e78(a);
        func_ov001_02187218(a, 1, NULL);
        func_ov001_02188d64(a, a->mPrm->mUnk_09c, a->mPrm->mUnk_0a0);
        func_ov001_02188c48(a, a->mPrm->mUnk_0a8, a->mPrm->mUnk_0a8);
        SetAnglePointAndMoveAnglePoint(a, &func_ov001_02187fc0(a)->mUnk_00);
        func_ov001_02188cd8(a, a->mPrm->mUnk_0a4, a->mPrm->mUnk_0a4);
        a0 = a->mPrm;
        func_ov001_02188de0(a, a0->mUnk_0ac, a0->mUnk_0b0, &func_ov001_02187fc0(a)->mUnk_00, NULL);
    }
    func_ov001_02184e6c(a);
}

void func_ov001_02183880(Unk02188950 *a) {
    func_ov001_02183ff4(a);
    func_ov001_02188260(a);
}

void func_ov001_02183850(Unk02188950 *a) {
    func_ov001_02187218(a, 8, NULL);
    func_ov001_02188d64(a, a->mPrm->mUnk_078, a->mPrm->mUnk_07c);
    func_ov001_02188c90(a);
    func_ov001_02188cec(a, 0);
}

void func_ov001_02183848(void) {
    func_ov001_021882b8();
}

int func_ov001_02183780(Unk02188950 *a) {
    if (a->mUnk_000.mKind == 0x1f6) {
        if (GetMapObjectModelNsbcaFrameIndex(a->mNsbmd) == 2 || GetMapObjectModelNsbcaFrameIndex(a->mNsbmd) == 3) {
            func_ov001_02187af4(a);
            func_ov001_021872e0(a, 0x1000, 0, 0, 0, 0x666, -0x1000, 0x428, 0);
            func_ov001_021872e0(a, 0x1000, 0, 0, 0, 0x666, -0x1000, 0x429, 0);
            func_ov001_021872e0(a, 0x1000, 0, 0, 0, 0x800, -0x1000, 0x42a, 0);
            StartMapObjectSound(&a->mUnk_000, 0x240);
        }
    }
    if (IsRaceStarted() == 1) {
        func_ov001_02183b9c(a);
    }
    return 0;
}

int func_ov001_02183690(Unk02188950 *a) {
    if (a->mUnk_000.mKind == 0x1f6) {
        if (GetMapObjectModelNsbcaFrameIndex(a->mNsbmd) == 2) {
            func_ov001_02187af4(a);
            func_ov001_021872e0(a, 0x1000, 0, 0, 0, 0x666, -0x1000, 0x428, 0);
            func_ov001_021872e0(a, 0x1000, 0, 0, 0, 0x666, -0x1000, 0x429, 0);
            func_ov001_021872e0(a, 0x1000, 0, 0, 0, 0x800, -0x1000, 0x42a, 0);
            StartMapObjectSound(&a->mUnk_000, 0x240);
        }
    } else if (a->mUnk_000.mKind == 0x1f5) {
        if (GetMapObjectModelNsbcaFrameIndex(a->mNsbmd) == 0x2b ||
            GetMapObjectModelNsbcaFrameIndex(a->mNsbmd) == 0x48) {
            func_ov001_02187af4(a);
            func_ov001_02187518(a, 0, 0, 0, 0x410, 0);
        }
    }
    return 0;
}

s32 func_ov001_021835e0(Unk02188950 *a) {
    int v1;
    if ((a->mUnk_000.mKind == 0x000001f6u) && (v1 = GetMapObjectModelNsbcaFrameIndex(a->mNsbmd), v1 == 2)) {
        func_ov001_02187af4(a);
        func_ov001_021872e0(a, 0x00001000u, 0, 0, 0, 0x00000666u, 0xfffff000u, 0x00000428u, 0);
        func_ov001_021872e0(a, 0x00001000u, 0, 0, 0, 0x00000666u, 0xfffff000u, 0x00000429u, 0);
        func_ov001_021872e0(a, 0x00001000u, 0, 0, 0, 0x00000800u, 0xfffff000u, 0x0000042au, 0);
        StartMapObjectSound(&a->mUnk_000, 0x00000240u);
    }
    return 0;
}

void func_ov001_021835b8(Unk02188950 *a) {
    func_ov001_02187218(a, 8, &func_ov001_02183780);
    func_ov001_02188d64(a, a->mPrm->mUnk_064, a->mPrm->mUnk_068);
}

void func_ov001_0218355c(Unk02188950 *a) {
    func_ov001_02187218(a, 8, &func_ov001_02183690);
    if (a->mUnk_000.mKind == 0x1f6) {
        func_ov001_02188d64(a, a->mPrm->mUnk_058, a->mPrm->mUnk_05c);
        func_ov001_02188e24(a, a->mPrm->mUnk_060, &func_ov001_021835b8);
        return;
    }
    func_ov001_02188d30(a, a->mPrm->mUnk_058, a->mPrm->mUnk_05c, &func_ov001_021835b8);
}

void func_ov001_02183524(Unk02188950 *a) {
    func_ov001_02187218(a, 8, func_ov001_021835e0);
    func_ov001_02188d64(a, a->mPrm->mUnk_04c, a->mPrm->mUnk_050);
    func_ov001_02188e24(a, a->mPrm->mUnk_054, &func_ov001_0218355c);
}

void func_ov001_021834fc(Unk02188950 *a) {
    func_ov001_02187218(a, 8, func_ov001_021835e0);
    func_ov001_02188d64(a, a->mPrm->mUnk_040, a->mPrm->mUnk_044);
}

void func_ov001_021834c4(Unk02188950 *a) {
    func_ov001_02187218(a, 8, func_ov001_021835e0);
    func_ov001_02188d64(a, a->mPrm->mUnk_034, a->mPrm->mUnk_038);
    func_ov001_02188e24(a, a->mPrm->mUnk_03c, &func_ov001_021834fc);
}

void func_ov001_02183450(Unk0218fa78 *a) {
    s32 i;
    Unk02188950 *o;

    if (a != NULL) {
        for (i = 0; i < a->mUnk_04 && (o = a->mUnk_00[i]) != NULL; i++) {
            func_ov001_02187eb0(o);
            o->mUnk_000.mCourseMapRow->mUnk_00.x = 0;
            o->mUnk_000.mCourseMapRow->mUnk_00.z = 0;
            if (GetRaceUseChainCameras() != 0) {
                func_ov001_021834c4(o);
            } else {
                func_ov001_02183524(o);
            }
            func_ov001_02188da4(o, func_ov001_02183b9c);
        }
    }
    SetStandingsEndCallback((void (*)(void)) func_ov001_02183848);
}

void func_ov001_021832cc(u32 b, Unk02188950 *d) {
    Unk02188950_a0 *a;
    Kart *c;

    if (gRaceSetup->mMode == MODE_MISSION_RUN ? IsWinnerDecided() : 0) {
        if (func_ov001_021871f8(d, 1) != 0) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN ? IsKartEliminated((u16) gRaceSetup->mEntryIndex) : 0) {
                func_ov001_02183850(d);
            } else {
                func_ov001_02183f0c(d);
            }
        }
    } else {
        if (func_ov001_021871f8(d, 8) != 0) {
            if (func_ov001_021871d0(d) != FALSE) {
                func_ov001_02183880(d);
            }
        }
        if (func_ov001_021871f8(d, 5) != 0) {
            a = d->mPrm;
            if (func_ov001_02188220(d) >= a->mUnk_148) {
                a = d->mPrm;
                if (func_ov001_02188104(d, a->mUnk_138, a->mUnk_13c) != NULL) {
                    a = d->mPrm;
                    c = func_ov001_02188000(d, a->mUnk_140, a->mUnk_144);
                    if (c != NULL) {
                        if ((GetKart(c->mIndex)->mUnk_48 & 0x100000) != 0 && c->mBoostTimer > 0) {
                            func_ov001_02183dec(d);
                        }
                    }
                }
            }
        }
        if (func_ov001_021871f8(d, 3) != 0) {
            if (func_ov001_021881a8(d, (Vec3 *) d->mUnk_000.mCourseMapRow, d->mPrm->mUnk_180, 0) == FALSE) {
                func_ov001_021839ac(d);
            }
        }
        if (func_ov001_021871f8(d, 2) != 0) {
            a = d->mPrm;
            if (func_ov001_02188104(d, a->mUnk_0dc, a->mUnk_0e0) != NULL) {
                func_ov001_02183ad8(d);
            }
        }
        if (func_ov001_021871f8(d, 1) != 0) {
            func_ov001_02183894(d);
        }
    }
    func_ov001_021864ac(b, d);
}

void func_ov001_02183294(Unk02188950 *a) {
    a->mUnk_000.mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x44);
    InitSoundSource((SoundSource *) a->mUnk_000.mSound, 0xc, &a->mUnk_000.mPos);
    a->mUnk_000.mFarDistanceSquared = data_0217cbec[20];
}

void InitBossDonketu(Unk0218fa78 *a) {
    Unk02188950 *o;
    s32 i;

    if (a != NULL) {
        for (i = 0; i < a->mUnk_04 && (o = a->mUnk_00[i]) != NULL; i++) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                AddMissionRunMapObject(o);
            }
            func_ov001_021870e4(a, o, data_ov001_021a79a8, data_ov001_021a79bc, data_ov001_021a79d0);
            func_ov001_021870b0(a, o, data_ov001_021a79e4);
            func_ov001_0218875c(o, o->mPrm->mUnk_008, o->mPrm->mUnk_00c, 0);
            func_ov001_021888a4(o, 0, 0x11000);
            func_ov001_02188200(o, func_ov001_02184874);
            o->mUnk_2b8 = 2;
        }
    }
}

void InitKingIceDonketu(Unk0218fa78 *a) {
    Unk02188950 *o;
    s32 i;

    if (a != NULL) {
        for (i = 0; i < a->mUnk_04 && (o = a->mUnk_00[i]) != NULL; i++) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                AddMissionRunMapObject(o);
            }
            func_ov001_021870e4(a, o, data_ov001_021a7950, data_ov001_021a7968, data_ov001_021a7980);
            func_ov001_021870b0(a, o, data_ov001_021a7998);
            func_ov001_0218875c(o, o->mPrm->mUnk_008, o->mPrm->mUnk_00c, 0);
            func_ov001_021888a4(o, 0, 0x21000);
            func_ov001_02188200(o, func_ov001_02184874);
        }
    }
}

void func_ov001_02183138(void *a, Unk02188950 *b) {
    func_ov001_02186368(a, b);
    func_ov001_021861f4(a, b, 0);
}

void func_ov001_02183104(void) {
    u32 v4 = 0x23eu;
    void *v8 = &func_ov001_02185fb0;
    void *v9 = &func_ov001_02185f04;
    void *v10 = &func_ov001_021860cc;
    void *v12 = func_ov001_0219b510(v8, v9, v10, 0x2u, 0x1u, v4, 0x0u);
}

void *func_ov001_021830e8(void) {
    return CreateMapObjectDrawList1(InitBossDonketu, func_ov001_02183138, func_ov001_02187098);
}

void *func_ov001_021830cc(void) {
    return CreateMapObjectDrawList1(InitKingIceDonketu, func_ov001_02183138, func_ov001_02187098);
}

void *func_ov001_021830b4(void) {
    return CreateMapObjectUpdateList(func_ov001_02183450, func_ov001_021832cc, NULL);
}
