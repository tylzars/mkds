#include "Main/Unknown/code_02067cb0.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_02081120.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_0206a354.h"
#include "Main/Unknown/code_02077bc0.h"

int CollideKartWithMapObjectResponse3(Kart *p, s32 *a, MapObject *c) {
    if (p->mVelocityLength > 0x3000 || (c->mFlags & 0x200)) {
        if (func_0206bcb0(p, 1, 0)) {
            if (p->mKartModelsEntry->mUnk_058 == 0) {
                StartEffect(0xc, &p->mPos);
                StartEffect(0xd, &p->mPos);
                StartEffect(0xe, &p->mPos);
            }
            if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
                GetEntryKartCounters()->mUnk_14++;
            }
        }
        *a = 3;
    } else {
        *a = 2;
    }
    return 0xb;
}

int CollideKartWithMapObjectResponse4(Kart *p, s32 *a, MapObject *c) {
    if (p->mVelocityLength > 0x3000 || (c->mFlags & 0x200)) {
        if (func_0206bcb0(p, 2, 0)) {
            if (p->mKartModelsEntry->mUnk_058 == 0) {
                StartEffect(0xc, &p->mPos);
                StartEffect(0xd, &p->mPos);
                StartEffect(0xe, &p->mPos);
            }
            if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
                GetEntryKartCounters()->mUnk_14++;
            }
        }
        *a = 4;
    } else {
        *a = 2;
    }
    return 0xb;
}

int CollideKartWithMapObjectResponse6(Kart *p, s32 *a, MapObject *c) {
    if (p->mVelocityLength > 0x3000 || (c->mFlags & 0x200)) {
        if (func_0206bcb0(p, 2, 0)) {
            if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
                GetEntryKartCounters()->mUnk_14++;
            }
            func_020812d0(p->mIndex);
        }
        *a = 4;
    } else {
        *a = 0;
    }
    return 0;
}

int CollideKartWithMapObjectResponse5(Kart *p, s32 *a) {
    if (func_0206bcb0(p, 2, 0)) {
        if (p->mUnk_7c & KART_7C_MODELS_ENTRY_008_SET) {
            func_02081e3c(StartEffect(0x4f, &p->mPos), p->mIndex, 0x46);
        }
        if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            GetEntryKartCounters()->mUnk_14++;
        }
    }
    *a = 5;
    return 0;
}

int CollideKartWithMapObjectResponse7(Kart *p, s32 *a) {
    if (TryStartKartState3(p)) {
        if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            GetEntryKartCounters()->mUnk_14++;
        }
        p->mUnk_48 |= 0x20000;
    }
    *a = 7;
    return 2;
}
