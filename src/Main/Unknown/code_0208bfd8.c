#include "Main/Unknown/code_0208bfd8.h"
#include "Main/Unknown/code_0207d814.h"
#include "Main/Unknown/code_0207e654.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_0207c000.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_0207d000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0207e000.h"
#include "Main/Unknown/code_0207f000.h"

void func_0208c0f0(Unk020888b4 *p, s32 a) {
    Kart *q = GetKart(a);

    p->mUnk_154 = (data_021759c0->mCurrentEntries[a].mUnk_08.mUnk_14 & 1) != 0;
    func_0207fa74(p, q, p->mUnk_154);
    func_0207e200(&p->mUnk_e8, p);
    func_0207c448(&p->mUnk_11c);
    func_0207e088(&p->mUnk_e8, p);
}

void func_0208c0c8(Unk020888b4 *p) {
    func_0207f9a8(p);
    func_0207e1d4(&p->mUnk_e8, p);
    func_0207c448(&p->mUnk_11c);
}

void func_0208c09c(Unk020888b4 *p) {
    func_0207f8f8(p);
    func_0207de84(&p->mUnk_e8, p);
    func_0207c270(&p->mUnk_11c, p);
}

void func_0208c050(Unk020888b4 *p) {
    if (p->mUnk_08.mUnk_00.mUnk_14 != NULL) {
        if (p->mUnk_08.mUnk_00.mUnk_18 != FALSE) {
            return;
        }
    }
    p->mUnk_08.mUnk_00.mUnk_14 = func_02041588(&p->mKart->mPos);
    if (p->mUnk_08.mUnk_00.mUnk_14 != NULL) {
        p->mUnk_08.mUnk_00.mUnk_18 = TRUE;
    }
}

BOOL func_0208c03c(Unk020888b4 *p) {
    return p->mUnk_08.mUnk_00.mUnk_14 != NULL;
}

void func_0208c000(Vec3 *a, Vec3 *b, Unk020888b4 *p) {
    Unk0208001c *s = &p->mUnk_08.mUnk_00;

    *a = *s->mUnk_00->mUnk_18;
    *b = s->mUnk_08;
}

void func_0208bfec(Unk020888b4 *p) {
    func_0207c144(&p->mUnk_11c, p);
}

void func_0208bfd8(Unk020888b4 *p) {
    func_0207becc(&p->mUnk_11c, p);
}
