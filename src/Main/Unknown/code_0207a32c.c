#include "Main/Unknown/code_0207a32c.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02012b30.h"

void func_0207a5f0(s32 a) {
    s32 i;
    Unk0206bcb0 *p = data_0217ad18;
    Unk0206bcb0_590 *s;
    for (i = 0; i < data_usa_0217acf4; i++) {
        s = p->mUnk_590;
        func_02013044(s->mUnk_010[1]->mUnk_04, a);
        func_02013044(s->mUnk_010[0]->mUnk_04, a);
        if (s->mUnk_010[2] != NULL) {
            func_02013044(s->mUnk_010[2]->mUnk_04, a);
        }
        p++;
    }
}

s32 func_0207a5c4(s32 a) {
    return (data_0217ad18[a].mUnk_48 & 0x800) != 0 ? 1 : 0;
}

BOOL func_0207a574(void) {
    Unk0206bcb0 *p = &data_0217ad18[data_021759c0->mUnk_62];
    if (p->mUnk_180 != 0 || (p->mUnk_48 & 0x4000000) != 0) {
        return TRUE;
    }
    return FALSE;
}

s32 func_0207a538(void) {
    return (data_0217ad18[data_021759c0->mUnk_62].mUnk_44 & 0xc0) != 0 ? 1 : 0;
}

s32 func_0207a4fc(void) {
    return (data_0217ad18[data_021759c0->mUnk_62].mUnk_48 & 0x1000) != 0 ? 1 : 0;
}

void func_0207a32c(void) {
    s32 d[3];
    u32 n = func_0203c8dc((u16) data_021759c0->mUnk_62);
    u16 i;
    u16 k;
    s32 j;
    Unk0206bcb0 *p;
    if (data_021759c0->mUnk_00c == 5) {
        for (k = 0; k < 3; k++) {
            data_0217ad18[k].mUnk_4c |= 0x8000;
        }
        return;
    }
    d[0] = data_021759c0->mUnk_62;
    if (n == 1) {
        d[1] = func_02085408(2);
        if (d[1] >= 0) {
            if ((data_0217ad18[d[1]].mUnk_590)->mUnk_060 != 0) {
                d[1] = -1;
            }
        }
    } else {
        d[1] = func_02085408((u16) (n - 1));
        if (d[1] >= 0) {
            if ((data_0217ad18[d[1]].mUnk_590)->mUnk_060 != 0) {
                d[1] = -1;
            }
        }
        if (n < data_021759c0->mUnk_3d0) {
            j = func_02085408((u16) (n + 1));
            if (j >= 0) {
                p = &data_0217ad18[j];
                p->mUnk_4c |= 0x40000;
            }
        }
    }
    for (i = 0; i < data_usa_021658bc; i++) {
        j = d[i];
        if (j >= 0) {
            p = &data_0217ad18[j];
            if ((p->mUnk_4c & 0x10000000) == 0) {
                p->mUnk_4c |= 0x8000;
            }
        }
    }
}
