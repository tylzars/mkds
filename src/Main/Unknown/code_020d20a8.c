#include "Main/Unknown/code_020d20a8.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d6d8c.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02135014.h"
#include "Main/Unknown/code_020d6000.h"
#include "Main/Unknown/code_020b4000.h"

BOOL func_020d2234(Unk020e71a0 *d, Unk020f41c4_A *e) {
    s32 a;
    s32 c;
    s32 b;
    a = d->mUnk_00;
    b = e->mUnk_44;
    c = 0;
    while (a >= 100) {
        a -= 100;
        c++;
    }
    if (func_020d6d8c(0, b, c, a) == 0 || func_020d6d34(0, b, c, a, 3) != 2) {
        return FALSE;
    }
    return TRUE;
}

#pragma thumb on

void *FindMainRaceOrMainEffectMapObjFile(const char *a) {
    char buf[0x100];
    snprintf(buf, 0x100, "MapObj/%s", a);
    return FindMainRaceOrMainEffectFile(buf);
}

void *FindCourseMapObjFile(const char *a) {
    char buf[0x100];
    snprintf(buf, 0x100, "MapObj/%s", a);
    return FindCourseFile(buf);
}

u32 func_020d2178(s32 c) {
    u32 a;
    s32 b;
    a = 0;
    if (c >= 1000) {
        b = c / 1000;
        a |= 1 << b;
        c = (s16) (c - b * 1000);
    }
    if (c >= 100) {
        b = c / 100;
        a |= 1 << b;
        c = (s16) (c - b * 100);
    }
    if (c >= 10) {
        b = c / 10;
        a |= 1 << b;
        c = (s16) (c - b * 10);
    }
    if (c >= 1) {
        a |= 1 << c;
    }
    return a;
}

#pragma thumb off

void func_020d20a8(void) {
    Unk0217b4b4 *p;
    p = func_02036bec(func_020364e0(func_020364e8()), 0x28);
    data_0217b4b4 = p;
    p->mUnk_00 = data_021759c0->mUnk_60;
    if (data_021759c0->mUnk_08 == 5) {
        data_0217b4b4->mUnk_04 = 4;
    } else if (data_021759c0->mUnk_08 == 3 && data_021759c0->mUnk_1c == 2) {
        data_0217b4b4->mUnk_04 = data_021759c0->mUnk_3d8;
    } else {
        data_0217b4b4->mUnk_04 = 0;
    }
    func_020b4cec(data_0217b4b4->mUnk_08, 0x1000);
    data_0217b4b4->mUnk_18 = NULL;
    data_0217b4b4->mUnk_1c = 0;
    data_0217b4b4->mUnk_20 = 0;
    data_0217b4b4->mUnk_24 = 0;
}
