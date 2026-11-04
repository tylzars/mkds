#include "Main/Unknown/code_02067cb0.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_02081120.h"
#include "Main/Unknown/code_020ed5c0.h"

int func_02067ec4(Kart *p, s32 *a, MapObject *c) {
    if (p->mVelocityLength > 0x3000 || (c->mFlags & 0x200)) {
        if (func_0206bcb0(p, 1, 0)) {
            if (p->mKartModelsEntry->mUnk_058 == 0) {
                func_0208b7bc(0xc, &p->mPos);
                func_0208b7bc(0xd, &p->mPos);
                func_0208b7bc(0xe, &p->mPos);
            }
            if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
                func_0207a6b0()->mUnk_14++;
            }
        }
        *a = 3;
    } else {
        *a = 2;
    }
    return 0xb;
}

int func_02067e10(Kart *p, s32 *a, MapObject *c) {
    if (p->mVelocityLength > 0x3000 || (c->mFlags & 0x200)) {
        if (func_0206bcb0(p, 2, 0)) {
            if (p->mKartModelsEntry->mUnk_058 == 0) {
                func_0208b7bc(0xc, &p->mPos);
                func_0208b7bc(0xd, &p->mPos);
                func_0208b7bc(0xe, &p->mPos);
            }
            if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
                func_0207a6b0()->mUnk_14++;
            }
        }
        *a = 4;
    } else {
        *a = 2;
    }
    return 0xb;
}

int func_02067d88(Kart *p, s32 *a, MapObject *c) {
    if (p->mVelocityLength > 0x3000 || (c->mFlags & 0x200)) {
        if (func_0206bcb0(p, 2, 0)) {
            if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
                func_0207a6b0()->mUnk_14++;
            }
            func_020812d0(p->mIndex);
        }
        *a = 4;
    } else {
        *a = 0;
    }
    return 0;
}

int func_02067d0c(Kart *p, s32 *a) {
    if (func_0206bcb0(p, 2, 0)) {
        if (p->mUnk_7c & KART_7C_MODELS_ENTRY_008_SET) {
            func_02081e3c(func_0208b7bc(0x4f, &p->mPos), p->mIndex, 0x46);
        }
        if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            func_0207a6b0()->mUnk_14++;
        }
    }
    *a = 5;
    return 0;
}

int func_02067cb0(Kart *p, s32 *a) {
    if (TryStartKartState3(p)) {
        if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            func_0207a6b0()->mUnk_14++;
        }
        p->mUnk_48 |= 0x20000;
    }
    *a = 7;
    return 2;
}
