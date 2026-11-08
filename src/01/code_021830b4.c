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

void func_ov001_021841e0(Unk02188950 *donketu) {
    Vec3 velocity = {0, 0, 0};

    velocity.y = donketu->mPrm->mUnk_238;
    func_ov001_02187218(donketu, 8, func_ov001_02184274);
    func_ov001_02188d64(donketu, donketu->mPrm->mUnk_224, donketu->mPrm->mUnk_228);
    SetVelocity(donketu, &velocity);
    func_ov001_02188c90(donketu);
    func_ov001_02188cd8(donketu, donketu->mPrm->mUnk_230, donketu->mPrm->mUnk_234);
    func_ov001_02188db8(donketu, func_ov001_021842ec);
    donketu->mUnk_000.mFlags |= data_ov001_021a6578;
}

void func_ov001_02184160(Unk02188950 *donketu) {
    u32 v1;
    func_ov001_02187218(donketu, 8, NULL);
    func_ov001_02188d64(donketu, donketu->mPrm->mUnk_210, donketu->mPrm->mUnk_214);
    v1 = donketu->mPrm->mUnk_21c;
    func_ov001_02188c48(donketu, v1, v1);
    SetAnglePointAndMoveAnglePoint(donketu, (Vec3 *) donketu->mUnk_000.mCourseMapRow);
    v1 = donketu->mPrm->mUnk_218;
    func_ov001_02188cd8(donketu, v1, v1);
    func_ov001_02188e24(donketu, donketu->mPrm->mUnk_220, &func_ov001_021841e0);
}

void func_ov001_02183ff4(Unk02188950 *donketu) {
    Vec3 velocity;
    s32 scale;

    velocity.x = donketu->mUnk_000.mPos.x;
    velocity.y = 0;
    velocity.z = donketu->mUnk_000.mPos.z;
    if ((s64) velocity.z * velocity.z + ((s64) velocity.x * velocity.x + (s64) velocity.y * velocity.y) >= 16) {
        Vec3NormalizeAndGetLengthUnchecked(&velocity, &velocity);
    }
    scale = donketu->mPrm->mUnk_204;
    velocity.x = (s64) velocity.x * scale >> 12;
    velocity.y = (s64) velocity.y * scale >> 12;
    velocity.z = (s64) velocity.z * scale >> 12;
    velocity.y = -donketu->mPrm->mUnk_208;
    func_ov001_02187218(donketu, 8, NULL);
    func_ov001_02188d64(donketu, donketu->mPrm->mUnk_1fc, donketu->mPrm->mUnk_200);
    func_ov001_02188c90(donketu);
    func_ov001_02188cec(donketu, 0);
    SetVelocity(donketu, &velocity);
    func_ov001_0218720c(donketu);
    func_ov001_02188e24(donketu, donketu->mPrm->mUnk_20c, func_ov001_02184160);
    func_ov001_021874c4(donketu, 0, 0, 0, 0x423, 0);
    func_ov001_021874c4(donketu, 0, 0, 0, 0x425, 0);
    func_ov001_02187444(donketu, 4, 0);
    StartMapObjectSound(&donketu->mUnk_000, 0x244);
    donketu->mUnk_000.mFlags |= data_ov001_021a6578;
}

void func_ov001_02183f0c(Unk02188950 *donketu) {
    Vec3 velocity = {0, 0, 0};

    func_ov001_02187218(donketu, 8, NULL);
    func_ov001_02188d64(donketu, donketu->mPrm->mUnk_070, donketu->mPrm->mUnk_074);
    SetVelocity(donketu, &velocity);
    func_ov001_0218720c(donketu);
    func_ov001_02188c90(donketu);
    func_ov001_02188cec(donketu, 0);
    if (donketu->mUnk_000.mKind == 0x1f5) {
        func_ov001_021874c4(donketu, 0, 0, 0, 0x423, 0);
        func_ov001_021874c4(donketu, 0, 0, 0, 0x425, 0);
    } else if (donketu->mUnk_000.mKind == 0x1f6) {
        func_ov001_021874c4(donketu, 0, 0, 0, 0x423, 0);
        func_ov001_021874c4(donketu, 0, 0, 0, 0x425, 0);
    }
    {
        Unk021a78d8 soundRequest = {0x212, 0, 0xc, 0};

        soundRequest.mUnk_04 = &donketu->mUnk_000.mPos;
        soundRequest.mUnk_0c = GetHorizontalCameraDistanceSquared(&donketu->mUnk_000.mPos);
        func_0210b734(&soundRequest, func_02108e7c());
    }
    donketu->mUnk_000.mFlags |= data_ov001_021a6578;
}

void func_ov001_02183ed4(Unk02188950 *donketu) {
    func_ov001_02187218(donketu, 5, NULL);
    func_ov001_02188d30(donketu, donketu->mPrm->mUnk_160, donketu->mPrm->mUnk_164, NULL);
    func_ov001_02188cec(donketu, 0);
}

u32 func_ov001_02183ebc(Unk02188950 *donketu) {
    StartMapObjectSoundWhileRequested(&donketu->mUnk_000, 0x00000243u);
    return 0;
}

void func_ov001_02183e40(Unk02188950 *donketu) {
    Vec3 velocity = {0, 0, 0};

    velocity.y = donketu->mPrm->mUnk_154;
    func_ov001_02187218(donketu, 5, (s32(*)(Unk02188950 *)) func_ov001_02183ebc);
    func_ov001_02188d64(donketu, donketu->mPrm->mUnk_14c, donketu->mPrm->mUnk_150);
    func_ov001_02188a8c(donketu, donketu->mPrm->mUnk_158, donketu->mPrm->mUnk_158);
    SetVelocity(donketu, &velocity);
    func_ov001_02188db8(donketu, func_ov001_02183ed4);
}

void func_ov001_02183dec(Unk02188950 *donketu) {
    func_ov001_02187218(donketu, 5, NULL);
    func_ov001_02188d30(donketu, donketu->mPrm->mUnk_12c, donketu->mPrm->mUnk_130, NULL);
    func_ov001_02188e24(donketu, donketu->mPrm->mUnk_134, &func_ov001_02183e40);
    func_ov001_02188cec(donketu, 0);
}

s32 func_ov001_02183d94(Unk02188950 *donketu) {
    SetAnglePointAndMoveAnglePoint(donketu, &GetKart((u16) gRaceSetup->mEntryIndex)->mPos);
    if (donketu->mSpeed < donketu->mPrm->mUnk_108) {
        func_ov001_02188200(donketu, func_ov001_02184874);
        func_ov001_02184e6c(donketu);
    }
    return 0;
}

void func_ov001_02183cc8(Unk02188950 *donketu) {
    Kart *kart;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    func_ov001_02187218(donketu, 2, func_ov001_02183d94);
    func_ov001_02188d64(donketu, donketu->mPrm->mUnk_10c, donketu->mPrm->mUnk_110);
    func_ov001_02188c48(donketu, donketu->mPrm->mUnk_118, donketu->mPrm->mUnk_118);
    SetAnglePointAndMoveAnglePoint(donketu, &kart->mPos);
    func_ov001_021889c8(donketu);
    func_ov001_02188cd8(donketu, 0, donketu->mPrm->mUnk_114);
    func_ov001_02188dcc(donketu, func_ov001_02184cc8);
    func_ov001_02188200(donketu, func_ov001_021843b0);
    if (donketu->mSpeed < donketu->mPrm->mUnk_114) {
        func_ov001_02188200(donketu, func_ov001_02184874);
    }
    func_ov001_02184e18((u16 *) donketu);
}

void func_ov001_02183c54(Unk02188950 *donketu) {
    func_ov001_02187218(donketu, 2, NULL);
    func_ov001_02188d64(donketu, donketu->mPrm->mUnk_0f4, donketu->mPrm->mUnk_0f8);
    func_ov001_02188c90(donketu);
    func_ov001_02188cd8(donketu, donketu->mPrm->mUnk_0fc, donketu->mPrm->mUnk_100);
    func_ov001_02188e24(donketu, donketu->mPrm->mUnk_104, &func_ov001_02183cc8);
    func_ov001_02188200(donketu, func_ov001_021843b0);
    func_ov001_02184e18((u16 *) donketu);
}

void func_ov001_02183c08(Unk02188950 *donketu) {
    func_ov001_02187218(donketu, 2, NULL);
    func_ov001_02188d64(donketu, donketu->mPrm->mUnk_0e8, donketu->mPrm->mUnk_0ec);
    func_ov001_02188c90(donketu);
    func_ov001_02188e24(donketu, donketu->mPrm->mUnk_0f0, &func_ov001_02183c54);
    func_ov001_02184e6c(donketu);
}

void func_ov001_02183b9c(Unk02188950 *donketu) {
    func_ov001_02187218(donketu, 2, NULL);
    func_ov001_02188d64(donketu, donketu->mPrm->mUnk_080, donketu->mPrm->mUnk_084);
    func_ov001_02188c90(donketu);
    func_ov001_02188cd8(donketu, donketu->mPrm->mUnk_088, donketu->mPrm->mUnk_08c);
    func_ov001_02188e24(donketu, donketu->mPrm->mUnk_090, &func_ov001_02183cc8);
    func_ov001_02188200(donketu, func_ov001_021843b0);
    func_ov001_02184e18((u16 *) donketu);
}

void func_ov001_02183ad8(Unk02188950 *donketu) {
    Kart *kart;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    func_ov001_02187218(donketu, 3, NULL);
    func_ov001_02188d64(donketu, donketu->mPrm->mUnk_0cc, donketu->mPrm->mUnk_0d0);
    func_ov001_02188c48(donketu, donketu->mPrm->mUnk_0d8, donketu->mPrm->mUnk_0d8);
    SetAnglePointAndMoveAnglePoint(donketu, &kart->mPos);
    func_ov001_02188cec(donketu, donketu->mPrm->mUnk_0d4);
    func_ov001_02188de0(donketu, 0, donketu->mPrm->mUnk_0e4, &kart->mPos, func_ov001_02183c08);
    if (donketu->mUnk_000.mKind == 0x1f5) {
        StartMapObjectSound(&donketu->mUnk_000, 0x214);
    } else if (donketu->mUnk_000.mKind == 0x1f6) {
        StartMapObjectSound(&donketu->mUnk_000, 0x245);
    }
    func_ov001_02184e6c(donketu);
}

void func_ov001_021839ac(Unk02188950 *donketu) {
    if (func_ov001_021881a8(donketu, (Vec3 *) donketu->mUnk_000.mCourseMapRow, (donketu->mPrm->mUnk_180 + 0x28), 0)) {
        func_ov001_02187218(donketu, 3, NULL);
        func_ov001_02188d64(donketu, donketu->mPrm->mUnk_168, donketu->mPrm->mUnk_16c);
        func_ov001_02188c48(donketu, donketu->mPrm->mUnk_178, 0x270f000);
        SetAnglePointAndMoveAnglePoint(donketu, &donketu->mUnk_000.mCourseMapRow->mUnk_00);
        func_ov001_02188cd8(donketu, donketu->mPrm->mUnk_174, donketu->mPrm->mUnk_170);
        func_ov001_02188e24(donketu, donketu->mPrm->mUnk_17c, NULL);
        func_ov001_02188200(donketu, func_ov001_02184874);
    } else {
        func_ov001_02187218(donketu, 3, NULL);
        func_ov001_02188d64(donketu, donketu->mPrm->mUnk_168, donketu->mPrm->mUnk_16c << 2);
        func_ov001_02188c48(donketu, donketu->mPrm->mUnk_178, 0x270f000);
        SetAnglePointAndMoveAnglePoint(donketu, &donketu->mUnk_000.mCourseMapRow->mUnk_00);
        func_ov001_02188cd8(donketu, -donketu->mPrm->mUnk_174, donketu->mPrm->mUnk_170);
        func_ov001_02188e24(donketu, donketu->mPrm->mUnk_17c, NULL);
        func_ov001_02188200(donketu, func_ov001_02184874);
    }
    func_ov001_02184e6c(donketu);
}

void func_ov001_02183894(Unk02188950 *donketu) {
    Unk02188950_a0 *prm;

    prm = donketu->mPrm;
    if (func_ov001_021881a8(donketu, &func_ov001_02187fc0(donketu)->mPos, prm->mUnk_0ac, prm->mUnk_0b0)) {
        func_ov001_02187218(donketu, 1, NULL);
        func_ov001_02188d64(donketu, donketu->mPrm->mUnk_0b8, donketu->mPrm->mUnk_0bc);
        func_ov001_02188b2c(donketu, donketu->mPrm->mUnk_0c4, donketu->mPrm->mUnk_0c4, 0);
        SetAnglePointAndMoveAnglePoint(donketu, &func_ov001_02187fc0(donketu)->mPos);
        func_ov001_02188cd8(donketu, donketu->mPrm->mUnk_0c0, donketu->mPrm->mUnk_0c0);
        func_ov001_02188e24(donketu, donketu->mPrm->mUnk_0c8, NULL);
    } else {
        func_ov001_02187e78(donketu);
        func_ov001_02187218(donketu, 1, NULL);
        func_ov001_02188d64(donketu, donketu->mPrm->mUnk_09c, donketu->mPrm->mUnk_0a0);
        func_ov001_02188c48(donketu, donketu->mPrm->mUnk_0a8, donketu->mPrm->mUnk_0a8);
        SetAnglePointAndMoveAnglePoint(donketu, &func_ov001_02187fc0(donketu)->mPos);
        func_ov001_02188cd8(donketu, donketu->mPrm->mUnk_0a4, donketu->mPrm->mUnk_0a4);
        prm = donketu->mPrm;
        func_ov001_02188de0(donketu, prm->mUnk_0ac, prm->mUnk_0b0, &func_ov001_02187fc0(donketu)->mPos, NULL);
    }
    func_ov001_02184e6c(donketu);
}

void func_ov001_02183880(Unk02188950 *donketu) {
    func_ov001_02183ff4(donketu);
    func_ov001_02188260(donketu);
}

void func_ov001_02183850(Unk02188950 *donketu) {
    func_ov001_02187218(donketu, 8, NULL);
    func_ov001_02188d64(donketu, donketu->mPrm->mUnk_078, donketu->mPrm->mUnk_07c);
    func_ov001_02188c90(donketu);
    func_ov001_02188cec(donketu, 0);
}

void func_ov001_02183848(void) {
    func_ov001_021882b8();
}

int func_ov001_02183780(Unk02188950 *donketu) {
    if (donketu->mUnk_000.mKind == 0x1f6) {
        if (GetMapObjectModelNsbcaFrameIndex(donketu->mNsbmd) == 2 ||
            GetMapObjectModelNsbcaFrameIndex(donketu->mNsbmd) == 3) {
            func_ov001_02187af4(donketu);
            func_ov001_021872e0(donketu, 0x1000, 0, 0, 0, 0x666, -0x1000, 0x428, 0);
            func_ov001_021872e0(donketu, 0x1000, 0, 0, 0, 0x666, -0x1000, 0x429, 0);
            func_ov001_021872e0(donketu, 0x1000, 0, 0, 0, 0x800, -0x1000, 0x42a, 0);
            StartMapObjectSound(&donketu->mUnk_000, 0x240);
        }
    }
    if (IsRaceStarted() == 1) {
        func_ov001_02183b9c(donketu);
    }
    return 0;
}

int func_ov001_02183690(Unk02188950 *donketu) {
    if (donketu->mUnk_000.mKind == 0x1f6) {
        if (GetMapObjectModelNsbcaFrameIndex(donketu->mNsbmd) == 2) {
            func_ov001_02187af4(donketu);
            func_ov001_021872e0(donketu, 0x1000, 0, 0, 0, 0x666, -0x1000, 0x428, 0);
            func_ov001_021872e0(donketu, 0x1000, 0, 0, 0, 0x666, -0x1000, 0x429, 0);
            func_ov001_021872e0(donketu, 0x1000, 0, 0, 0, 0x800, -0x1000, 0x42a, 0);
            StartMapObjectSound(&donketu->mUnk_000, 0x240);
        }
    } else if (donketu->mUnk_000.mKind == 0x1f5) {
        if (GetMapObjectModelNsbcaFrameIndex(donketu->mNsbmd) == 0x2b ||
            GetMapObjectModelNsbcaFrameIndex(donketu->mNsbmd) == 0x48) {
            func_ov001_02187af4(donketu);
            func_ov001_02187518(donketu, 0, 0, 0, 0x410, 0);
        }
    }
    return 0;
}

s32 func_ov001_021835e0(Unk02188950 *donketu) {
    int nsbcaFrameIndex;
    if ((donketu->mUnk_000.mKind == 0x000001f6u) &&
        (nsbcaFrameIndex = GetMapObjectModelNsbcaFrameIndex(donketu->mNsbmd), nsbcaFrameIndex == 2)) {
        func_ov001_02187af4(donketu);
        func_ov001_021872e0(donketu, 0x00001000u, 0, 0, 0, 0x00000666u, 0xfffff000u, 0x00000428u, 0);
        func_ov001_021872e0(donketu, 0x00001000u, 0, 0, 0, 0x00000666u, 0xfffff000u, 0x00000429u, 0);
        func_ov001_021872e0(donketu, 0x00001000u, 0, 0, 0, 0x00000800u, 0xfffff000u, 0x0000042au, 0);
        StartMapObjectSound(&donketu->mUnk_000, 0x00000240u);
    }
    return 0;
}

void func_ov001_021835b8(Unk02188950 *donketu) {
    func_ov001_02187218(donketu, 8, &func_ov001_02183780);
    func_ov001_02188d64(donketu, donketu->mPrm->mUnk_064, donketu->mPrm->mUnk_068);
}

void func_ov001_0218355c(Unk02188950 *donketu) {
    func_ov001_02187218(donketu, 8, &func_ov001_02183690);
    if (donketu->mUnk_000.mKind == 0x1f6) {
        func_ov001_02188d64(donketu, donketu->mPrm->mUnk_058, donketu->mPrm->mUnk_05c);
        func_ov001_02188e24(donketu, donketu->mPrm->mUnk_060, &func_ov001_021835b8);
        return;
    }
    func_ov001_02188d30(donketu, donketu->mPrm->mUnk_058, donketu->mPrm->mUnk_05c, &func_ov001_021835b8);
}

void func_ov001_02183524(Unk02188950 *donketu) {
    func_ov001_02187218(donketu, 8, func_ov001_021835e0);
    func_ov001_02188d64(donketu, donketu->mPrm->mUnk_04c, donketu->mPrm->mUnk_050);
    func_ov001_02188e24(donketu, donketu->mPrm->mUnk_054, &func_ov001_0218355c);
}

void func_ov001_021834fc(Unk02188950 *donketu) {
    func_ov001_02187218(donketu, 8, func_ov001_021835e0);
    func_ov001_02188d64(donketu, donketu->mPrm->mUnk_040, donketu->mPrm->mUnk_044);
}

void func_ov001_021834c4(Unk02188950 *donketu) {
    func_ov001_02187218(donketu, 8, func_ov001_021835e0);
    func_ov001_02188d64(donketu, donketu->mPrm->mUnk_034, donketu->mPrm->mUnk_038);
    func_ov001_02188e24(donketu, donketu->mPrm->mUnk_03c, &func_ov001_021834fc);
}

void InitDonketuObjects(Unk0218fa78 *list) {
    s32 i;
    Unk02188950 *donketu;

    if (list != NULL) {
        for (i = 0; i < list->mUnk_04 && (donketu = list->mUnk_00[i]) != NULL; i++) {
            func_ov001_02187eb0(donketu);
            donketu->mUnk_000.mCourseMapRow->mUnk_00.x = 0;
            donketu->mUnk_000.mCourseMapRow->mUnk_00.z = 0;
            if (GetRaceUseChainCameras() != 0) {
                func_ov001_021834c4(donketu);
            } else {
                func_ov001_02183524(donketu);
            }
            func_ov001_02188da4(donketu, func_ov001_02183b9c);
        }
    }
    SetStandingsEndCallback((void (*)(void)) func_ov001_02183848);
}

void UpdateDonketu(u32 b, Unk02188950 *donketu) {
    Unk02188950_a0 *prm;
    Kart *kart;

    if (gRaceSetup->mMode == MODE_MISSION_RUN ? IsWinnerDecided() : 0) {
        if (func_ov001_021871f8(donketu, 1) != 0) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN ? IsKartEliminated((u16) gRaceSetup->mEntryIndex) : 0) {
                func_ov001_02183850(donketu);
            } else {
                func_ov001_02183f0c(donketu);
            }
        }
    } else {
        if (func_ov001_021871f8(donketu, 8) != 0) {
            if (func_ov001_021871d0(donketu) != FALSE) {
                func_ov001_02183880(donketu);
            }
        }
        if (func_ov001_021871f8(donketu, 5) != 0) {
            prm = donketu->mPrm;
            if (func_ov001_02188220(donketu) >= prm->mUnk_148) {
                prm = donketu->mPrm;
                if (func_ov001_02188104(donketu, prm->mUnk_138, prm->mUnk_13c) != NULL) {
                    prm = donketu->mPrm;
                    kart = func_ov001_02188000(donketu, prm->mUnk_140, prm->mUnk_144);
                    if (kart != NULL) {
                        if ((GetKart(kart->mIndex)->mUnk_48 & 0x100000) != 0 && kart->mBoostTimer > 0) {
                            func_ov001_02183dec(donketu);
                        }
                    }
                }
            }
        }
        if (func_ov001_021871f8(donketu, 3) != 0) {
            if (func_ov001_021881a8(donketu, (Vec3 *) donketu->mUnk_000.mCourseMapRow, donketu->mPrm->mUnk_180, 0) ==
                FALSE) {
                func_ov001_021839ac(donketu);
            }
        }
        if (func_ov001_021871f8(donketu, 2) != 0) {
            prm = donketu->mPrm;
            if (func_ov001_02188104(donketu, prm->mUnk_0dc, prm->mUnk_0e0) != NULL) {
                func_ov001_02183ad8(donketu);
            }
        }
        if (func_ov001_021871f8(donketu, 1) != 0) {
            func_ov001_02183894(donketu);
        }
    }
    func_ov001_021864ac(b, donketu);
}

void func_ov001_02183294(Unk02188950 *donketu) {
    donketu->mUnk_000.mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x44);
    InitSoundSource((SoundSource *) donketu->mUnk_000.mSound, 0xc, &donketu->mUnk_000.mPos);
    donketu->mUnk_000.mFarDistanceSquared = data_0217cbec[20];
}

void InitBossDonketu(Unk0218fa78 *list) {
    Unk02188950 *donketu;
    s32 i;

    if (list != NULL) {
        for (i = 0; i < list->mUnk_04 && (donketu = list->mUnk_00[i]) != NULL; i++) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                AddMissionRunMapObject(donketu);
            }
            func_ov001_021870e4(list, donketu, gBossDonketuNsbmdName, gBossDonketuNsbcaName, gBossDonketuPrmName);
            func_ov001_021870b0(list, donketu, data_ov001_021a79e4);
            func_ov001_0218875c(donketu, donketu->mPrm->mUnk_008, donketu->mPrm->mUnk_00c, 0);
            func_ov001_021888a4(donketu, 0, 0x11000);
            func_ov001_02188200(donketu, func_ov001_02184874);
            donketu->mUnk_2b8 = 2;
        }
    }
}

void InitKingIceDonketu(Unk0218fa78 *list) {
    Unk02188950 *donketu;
    s32 i;

    if (list != NULL) {
        for (i = 0; i < list->mUnk_04 && (donketu = list->mUnk_00[i]) != NULL; i++) {
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                AddMissionRunMapObject(donketu);
            }
            func_ov001_021870e4(list, donketu, gKingIceDonketuNsbmdName, gKingIceDonketuNsbcaName,
                                gKingIceDonketuPrmName);
            func_ov001_021870b0(list, donketu, data_ov001_021a7998);
            func_ov001_0218875c(donketu, donketu->mPrm->mUnk_008, donketu->mPrm->mUnk_00c, 0);
            func_ov001_021888a4(donketu, 0, 0x21000);
            func_ov001_02188200(donketu, func_ov001_02184874);
        }
    }
}

void func_ov001_02183138(void *a, Unk02188950 *donketu) {
    func_ov001_02186368(a, donketu);
    func_ov001_021861f4(a, donketu, 0);
}

void func_ov001_02183104(void) {
    u32 v4 = 0x23eu;
    void *v8 = &func_ov001_02185fb0;
    void *v9 = &func_ov001_02185f04;
    void *v10 = &func_ov001_021860cc;
    void *v12 = func_ov001_0219b510(v8, v9, v10, 0x2u, 0x1u, v4, 0x0u);
}

void *CreateBossDonketuDrawList(void) {
    return CreateMapObjectDrawList1(InitBossDonketu, func_ov001_02183138, func_ov001_02187098);
}

void *CreateKingIceDonketuDrawList(void) {
    return CreateMapObjectDrawList1(InitKingIceDonketu, func_ov001_02183138, func_ov001_02187098);
}

void *CreateDonketuUpdateList(void) {
    return CreateMapObjectUpdateList(InitDonketuObjects, UpdateDonketu, NULL);
}
