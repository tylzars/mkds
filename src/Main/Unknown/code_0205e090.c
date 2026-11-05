#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02059bc0.h"
#include "Main/Unknown/unk_02165000.h"

#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02059000.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0212030c.h"
#include "Main/Unknown/code_02042064.h"
#include "Main/Unknown/code_020d4130.h"
#include "Main/Unknown/code_020d411c.h"
#include "Main/Unknown/unk_0217a000.h"

u32 func_0205e2b8(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217aa24;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

s32 func_0205e1c4(void) {
    BOOL r = FALSE;
    u16 i = 0;
    Unk0217aa24_00 *e;
    CourseMapShape *p;
    s32 n;
    u16 j;
    u8 c;
    for (i = 0; i < data_0217aa24->mUnk_04; i++) {
        e = &data_0217aa24->mUnk_00[i];
        p = GetCourseMapShape(e->mUnk_00);
        n = func_020d4130(&p->mUnk_00, e->mUnk_04, p->mUnk_3c);
        c = 0;
        for (j = 0; j < n; j++) {
            if (IsPosInCourseMapShape(&GetFoundMapObject(j)->mPos, p) != 0) {
                c = c + 1;
            }
        }
        if (e->mUnk_09 < c) {
            e->mUnk_08++;
        }
        e->mUnk_09 = c;
        if (e->mUnk_08 > p->mUnk_3e) {
            r = TRUE;
            break;
        }
    }
    return r;
}

void func_0205e180(void *a) {
    data_0217aa20 = HeapAlloc(a, 0x10);
    data_0217aa20->mUnk_00 = 0;
    data_0217aa20->mUnk_04 = 3;
    data_0217aa20->mUnk_0c = NULL;
}

void func_0205e0b0(void) {
    void *h;
    s32 m;
    h = GetHeap(func_020364e8());
    switch (data_0217aa20->mUnk_00) {
        case 0:
            if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
                m = 2;
            } else {
                m = 0;
                func_02059ea4(1);
                func_02059e1c();
            }
            func_02054368(h);
            break;
        case 1:
            m = 1;
            func_02059ea4(0);
            func_02059e1c();
            CreateWiFiSessionHeap(h);
            break;
    }
    if (m == 2) {
        return;
    }
    h = HeapAlloc(h, func_021087d4(m));
    func_02108598(m, (u32) h);
    data_0217aa20->mUnk_0c = h;
}

int GetCurrentSceneNumber(void) {
    u32 value0;
    value0 = (u32) &gSceneNumbers;
    value0 = (u32) * (const s16 *) ((value0) + (2));
    return value0;
}

u32 GetNextSceneNumber(void) {
    u32 value0;
    value0 = (u32) &gSceneNumbers;
    value0 = (u32) * (const s16 *) ((value0) + (4));
    return value0;
}
