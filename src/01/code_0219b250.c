#include "01/code_0219b250.h"

#include "01/unk_021a6000.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_02048000.h"
#include "01/unk_021a9000.h"
#include "code_02013740.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02088000.h"
#include "code_02135014.h"
#include "Main/Unknown/code_0209b000.h"

void *func_ov001_0219b510(void *p0, void *p1, void *p2, u32 p3, u16 p4, u16 p5, u16 p6) {
    u8 *r = func_0209bfa8(p0, p1, p2, p3, p4);
    *(u32 *) (r + 0x24) = p5;
    *(u32 *) (r + 0x28) = p6;
    *(u32 *) (r + 0x38) = 0x270f000;
    *(u32 *) (r + 0x3c) = 0xfd8f1000;
    return r;
}

void *func_ov001_0219b4d8(char *p0) {
    char buf[0x100];
    void *out = NULL;
    snprintf(buf, 0x100, "data/MissionRun/%s", p0);
    func_02048590(buf, (u32) func_020364e0(func_020364e8()), &out);
    return out;
}

Unk0219b250 *func_ov001_0219b478(Unk0219b478 *p0, char *p1) {
    Unk0219b250 *o = func_02036bec((void *) func_020364e0(func_020364e8()), (u32) (0x2c));
    if (p0 != NULL) {
        p0->mUnk_18 = 1;
    }
    o->mUnk_18 = func_ov001_0219b4d8((p1));
    o->mUnk_10 = func_02036bec((void *) func_020364e0(func_020364e8()), (u32) (0x6c));
    func_02084e28(o->mUnk_10, o->mUnk_18);
    func_0209b8ac(o, 0);
    o->mUnk_00 = data_ov001_021a6b2c;
    return o;
}

Unk0219b250 *func_ov001_0219b418(Unk0219b478 *p0, char *p1) {
    Unk0219b250 *o = func_02036bec((void *) func_020364e0(func_020364e8()), (u32) (0x2c));
    void *r = func_ov001_0219b4d8((p1));
    if (p0 != NULL) {
        p0->mUnk_18 = 1;
    }
    o->mUnk_14 = func_02036bec((void *) func_020364e0(func_020364e8()), (u32) (0x74));
    func_0207afa8(o->mUnk_14, r, 0x3f);
    func_0209b8ac(o, 0);
    o->mUnk_00 = data_ov001_021a6b20;
    return o;
}

void func_ov001_0219b3b4(Unk0219b250 *p0, char *p1) {
    void *r = func_ov001_0219b4d8((p1));
    u8 v;
    p0->mUnk_1c = func_02036bec((void *) func_020364e0(func_020364e8()), (u32) (0x38));
    v = ((u8 *) func_02013a30(r))[9];
    func_0208823c(0, p0->mUnk_1c, p0->mUnk_10, v, func_020364e0(func_020364e8()), p0->mUnk_18);
    func_0208805c(p0->mUnk_1c, r, func_020364e0(func_020364e8()));
    func_02087f84(p0->mUnk_1c, 0);
}

void func_ov001_0219b380(Unk0219b250 *p0, char *p1) {
    void *r = func_ov001_0219b4d8((p1));
    p0->mUnk_24 = func_02036bec((void *) func_020364e0(func_020364e8()), (u32) (0x38));
    func_020ea514((u32) (4), (void *) (p0->mUnk_10), (void *) (p0->mUnk_24), (void *) (p0->mUnk_18), (void *) (r));
}

void func_ov001_0219b31c(Unk0219b250 *p0, char *p1) {
    void *r = func_ov001_0219b4d8((p1));
    u8 v;
    p0->mUnk_28 = func_02036bec((void *) func_020364e0(func_020364e8()), (u32) (0x38));
    v = ((u8 *) func_02013aa8(r))[9];
    func_0208823c(1, p0->mUnk_28, p0->mUnk_10, v, func_020364e0(func_020364e8()), p0->mUnk_18);
    func_0208805c(p0->mUnk_28, r, func_020364e0(func_020364e8()));
    func_02087f84(p0->mUnk_28, 0);
}

void func_ov001_0219b2e8(Unk0219b250 *p0, char *p1) {
    void *r = func_ov001_0219b4d8((p1));
    p0->mUnk_20 = func_02036bec((void *) func_020364e0(func_020364e8()), (u32) (0x38));
    func_020ea514((u32) (2), (void *) (p0->mUnk_10), (void *) (p0->mUnk_20), (void *) (p0->mUnk_18), (void *) (r));
}

void func_ov001_0219b28c(Unk0219b250 *p0, void *p1) {
    u8 v;
    p0->mUnk_1c = func_02036bec((void *) func_020364e0(func_020364e8()), (u32) (0x38));
    v = ((u8 *) func_02013a30(p1))[9];
    func_0208823c(0, p0->mUnk_1c, p0->mUnk_10, v, func_020364e0(func_020364e8()), p0->mUnk_18);
    func_0208805c(p0->mUnk_1c, p1, func_020364e0(func_020364e8()));
    func_02087f84(p0->mUnk_1c, 0);
}

void func_ov001_0219b25c(Unk0219b250 *p0, void *p1) {
    p0->mUnk_20 = func_02036bec((void *) func_020364e0(func_020364e8()), (u32) (0x38));
    func_020ea514((u32) (2), (void *) (p0->mUnk_10), (void *) (p0->mUnk_20), (void *) (p0->mUnk_18), (void *) (p1));
}

void func_ov001_0219b250(Unk0219b250 *p0) {
    func_02087de0(p0->mUnk_1c);
}
