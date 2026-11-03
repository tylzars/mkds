#include "code_0212c7f0.h"
#include "code_020207ec.h"
#include "code_02020eb0.h"
#include "code_0214f4a4.h"
#include "Main/Unknown/code_02017000.h"
#include "code_020172d0.h"
#include "code_0201ec30.h"
#include "Main/Unknown/code_02021000.h"
#include "code_0212bb7c.h"
#include "Main/Unknown/unk_0217d000.h"

void func_0212c9a4(Unk0212c7f0 *p) {
    if (p->mUnk_44 == 0) {
        return;
    }
    func_0212bc20(p->mUnk_44);
    p->mUnk_44 = 0;
    p->mUnk_48 = 0;
}

void func_0212c948(Unk0212c7f0 *p) {
    func_02020c2c(p->mUnk_44, 0, 1 << p->mUnk_40, 0);
    if (p->mUnk_24_1) {
        return;
    }
    func_0214f4ec(&p->mUnk_08);
    func_0214f4d4(&p->mUnk_14);
    p->mUnk_24_1 = 1;
}

void func_0212c918(Unk0212c7f0 *p) {
    if (p->mUnk_24_0) {
        func_0212c824(p);
    }
}

void func_0212c8a4(Unk0212c7f0 *p, s32 a) {
    u32 v;
    s32 i;
    s32 r;

    p->mUnk_3c = a;
    for (i = 0; i < p->mUnk_48; i++) {
        v = p->mUnk_4c[i];
        r = func_020218f4(p->mUnk_3c + data_0217dd28[v].mUnk_04);
        func_02020a6c(1 << v, r & 0xff, r >> 8);
    }
}

void func_0212c824(Unk0212c7f0 *p) {
    u32 r;

    if (p->mUnk_24_1) {
        func_02020bbc(p->mUnk_44, 0, 1 << p->mUnk_40, 0);
        func_0214f4bc(&p->mUnk_08);
        func_0214f4a4(&p->mUnk_14);
        p->mUnk_24_1 = 0;
        r = func_02021114();
        func_020211e4(1);
        func_02021154(r);
    }
    func_0212c7f0(p);
}

void func_0212c7f0(Unk0212c7f0 *p) {
    func_0212bb7c(p->mUnk_40);
    func_02017354(&data_0217dd1c, p);
    p->mUnk_24_0 = 0;
}
