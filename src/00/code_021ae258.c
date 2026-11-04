#include "00/code_021ae258.h"
#include "00/code_021a9228.h"
#include "00/code_021ae314.h"
#include "00/code_021b0014.h"
#include "Main/Unknown/unk_0216f000.h"

void func_ov000_021ae2d8(void) {
    Unk021a998c *v1;
    v1 = *(Unk021a998c **) data_0216ff5c.mUnk_04->mUnk_a4;
    if (v1 != NULL) {
        v1->mState = 10;
        v1->mReceiveBufferLength = 0;
    }
}

void func_ov000_021ae290(int a, u16 b, int c) {
    u16 v1;
    Unk021a998c *v2;
    v2 = *(Unk021a998c **) data_0216ff5c.mUnk_04->mUnk_a4;
    if (v2 != NULL) {
        if (c == 0x7f000001) {
            c = *(s32 *) &data_ov000_021b63b4;
        }
        v2->mUnk_1a = b;
        v2->mUnk_18 = v2->mUnk_1a;
        v2->mUnk_20 = c;
        v2->mUnk_1c = v2->mUnk_20;
        if (a == 0) {
            v1 = func_ov000_021ae340();
            v2->mUnk_0a = v1;
            return;
        }
        v2->mUnk_0a = a;
    }
}

void func_ov000_021ae270(void) {
    Unk021a998c *v1;
    v1 = *(Unk021a998c **) data_0216ff5c.mUnk_04->mUnk_a4;
    if (v1 != NULL) {
        v1->mThread = data_0216ff5c.mUnk_04;
        v1->mState = 0;
        v1->mReceiveBufferLength = 0;
        v1->mUnk_60 = 0;
        v1->mReceiveCallback = NULL;
    }
}

void func_ov000_021ae258(void) {
    Unk021a998c *v1;
    v1 = *(Unk021a998c **) data_0216ff5c.mUnk_04->mUnk_a4;
    if (v1 != NULL) {
        v1->mThread = NULL;
    }
}
