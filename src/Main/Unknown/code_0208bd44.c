#include "Main/Unknown/code_0207d814.h"
#include "Main/Unknown/code_0208bd44.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_02089ce4.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_0207d000.h"
#include "Main/Unknown/code_020901a0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0207d7e4.h"
#include "Main/Unknown/code_0207e000.h"
#include "Main/Unknown/code_02090000.h"

void func_0208bf40(Unk020888b4 *p) {
    func_020896e0(p);
    func_02089c3c(&p->mUnk_140, p);
    func_0209033c(&p->mUnk_11c, p);
}

void func_0208bef4(Unk020888b4 *p) {
    if (p->mUnk_28.mUnk_14 != NULL) {
        if (p->mUnk_28.mUnk_18 != 0) {
            return;
        }
    }
    p->mUnk_28.mUnk_14 = func_020413a4(&p->mKart->mUnk_80);
    if (p->mUnk_28.mUnk_14 != NULL) {
        p->mUnk_28.mUnk_18 = 1;
    }
}

BOOL func_0208bee0(Unk020888b4 *p) {
    return p->mUnk_28.mUnk_14 != NULL;
}

void func_0208bea4(Vec3 *a, Vec3 *b, Unk020888b4 *p) {
    Unk0208001c *s = &p->mUnk_28;

    *a = *s->mUnk_00->mUnk_20;
    *b = s->mUnk_08;
}

void func_0208be90(Unk020888b4 *p) {
    func_020902fc(&p->mUnk_11c, p);
}

void func_0208be7c(Unk020888b4 *p) {
    func_0208fd8c(&p->mUnk_11c, p);
}

void func_0208be00(Unk020888b4 *p, s32 a) {
    Kart *q = GetKart(a);

    p->mUnk_154 = 0;
    func_0207e594(p, q, p->mUnk_154);
    func_0207d814(&p->mUnk_e8, p);
    if (data_021759c0->mMode == 4) {
        p->mUnk_e8.mUnk_2c = 1;
        p->mUnk_e8.mUnk_30 = 4;
    } else {
        p->mUnk_e8.mUnk_2c = 0;
        p->mUnk_e8.mUnk_30 = 0;
    }
}

void func_0208bde0(Unk020888b4 *p, Unk02175620_bc *a) {
    func_0207e564(p, a);
    func_0207d7e4(&p->mUnk_e8, p);
}

void func_0208bdc0(Unk020888b4 *p) {
    func_0207e4a4(p);
    func_0207d6a4(&p->mUnk_e8, p);
}

void func_0208bd44(Unk020888b4 *p, s32 a) {
    Kart *q = GetKart(a);

    p->mUnk_154 = 0;
    func_0207e400(p, q, p->mUnk_154);
    func_0207d814(&p->mUnk_e8, p);
    p->mUnk_e8.mUnk_2c = 0;
    p->mUnk_e8.mUnk_30 = 0;
    if (q->mIndex != data_021759c0->mEntryIndex) {
        q->mUnk_7c |= 0x40;
    }
}
