#include "Main/Unknown/code_02008934.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0214cfe4.h"

#pragma thumb on

void func_02008d68(u32 a) {
    if (data_usa_0216fc1c->mUnk_05 != data_0216fc40->mUnk_10[a].mUnk_4b3) {
        func_0200895c(a);
        func_02008a4c(a);
        data_0216fc40->mUnk_10[a].mUnk_4b3 = data_usa_0216fc1c->mUnk_05;
    }
}

void func_02008d30(u32 a) {
    if (data_usa_0216fc1c->mUnk_06 != data_0216fc40->mUnk_10[a].mUnk_4b4) {
        func_02008a4c(a);
    }
}

void func_02008cbc(const u8 *a) {
    s32 i;
    u32 v1;
    u32 z;
    i = 0;
    v1 = 0;
    z = 0;
    for (; i < 0x10; i++) {
        if (data_0216fc40->mUnk_00 & (1 << i)) {
            u8 *q = data_0216fc40->mUnk_10[0].mUnk_4c4;
            u8 *p = q + v1;
            if (a[0] == q[v1] && a[1] == p[1] && a[2] == p[2] && a[3] == p[3] && a[4] == p[4] && a[5] == p[5]) {
                *(s16 *) ((u8 *) data_0216fc40 + v1 + 0x59a) = z;
            }
        }
        v1 += sizeof(Unk02008934);
    }
}

void func_02008c08(u32 a) {
    Unk02008934 *e;
    u8 *v1;
    u8 *p;
    Unk0216fc1c *s;
    u32 n;
    e = &data_0216fc40->mUnk_10[a];
    v1 = &e->mUnk_358;
    if (e->mUnk_4b3 == data_usa_0216fc1c->mUnk_05 && (e->mUnk_580 & (1 << data_usa_0216fc1c->mUnk_0a)) != 0) {
        return;
    }
    if (data_usa_0216fc1c->mUnk_04 == 0) {
        p = (u8 *) e;
    } else {
        p = e->mUnk_220;
    }
    s = data_usa_0216fc1c;
    p += s->mUnk_0a * 0x62;
    n = *(u8 *) &s->mUnk_0c;
    if (p + n > v1) {
        return;
    }
    MemCopyHalfwords(&data_usa_0216fc1c->mUnk_0e, p, n);
    e->mUnk_4b2 = data_usa_0216fc1c->mUnk_04;
    e->mUnk_580 |= 1 << data_usa_0216fc1c->mUnk_0a;
    e->mUnk_584 = (1 << data_usa_0216fc1c->mUnk_0b) - 1;
}

void func_02008aa0(u32 a) {
    Unk02008934 *e;
    s32 i;
    u32 j;
    u8 *p;
    vu16 v1;
    u16 z;
    e = &data_0216fc40->mUnk_10[a];
    if (e->mUnk_4b4 != data_usa_0216fc1c->mUnk_06) {
        if ((u8) (e->mUnk_4b4 + 1) == data_usa_0216fc1c->mUnk_06) {
            i = 0;
            p = e->mUnk_35e;
            z = 0;
            for (; i < 0xf; i++) {
                if (data_usa_0216fc1c->mUnk_0e & (2 << i)) {
                    v1 = z;
                    MemFillHalfwords(v1, p, 0x16);
                }
                p += 0x16;
            }
            *(u16 *) &e->mUnk_588 &= ~data_usa_0216fc1c->mUnk_0e;
            data_0216fc40->mUnk_04 &= ~(1 << a);
        } else {
            vu16 v2 = 0;
            MemFillHalfwords(v2, e->mUnk_35e, 0x14a);
            e->mUnk_588 = 0;
            data_0216fc40->mUnk_04 &= ~(1 << a);
        }
        e->mUnk_4b4 = data_usa_0216fc1c->mUnk_06;
    } else if (e->mUnk_588 == data_usa_0216fc1c->mUnk_0c) {
        return;
    }
    e->mUnk_358 = data_usa_0216fc1c->mUnk_0a;
    e->mUnk_35a = data_usa_0216fc1c->mUnk_0c;
    e->mUnk_35c = data_usa_0216fc1c->mUnk_0e;
    e->mUnk_588 |= 1;
    for (i = 0; i < 8; i++) {
        e->mUnk_4a8[i] = data_usa_0216fc1c->mUnk_68[i];
    }
    for (j = 0; j < 4; j++) {
        u32 n = data_usa_0216fc1c->mUnk_10[j].mUnk_00_4;
        if (n != 0) {
            MemCopyHalfwords(&data_usa_0216fc1c->mUnk_10[j], &e->mUnk_35e[(n - 1) * 0x16], 0x16);
            e->mUnk_588 |= 1 << n;
        }
    }
}

void func_02008a4c(u32 a) {
    if (data_0216fc40->mUnk_06 == 0) {
        if (data_0216fc38 != NULL) {
            data_0216fc38(data_0216fc40->mUnk_10[a].mUnk_4c4);
        }
        data_0216fc40->mUnk_0c = 0x16;
        data_0216fc40->mUnk_06 = 1 << a;
        data_0216fc40->mUnk_08 = 0x321;
    }
}

void func_02008a14(void) {
    if (data_0216fc40->mUnk_06 != 0) {
        if (*data_0216fc34 != 0) {
            (*data_0216fc34)();
        }
        data_0216fc40->mUnk_0c = 1;
        data_0216fc40->mUnk_06 = 0;
        data_0216fc40->mUnk_0a = 0;
    }
}

void func_020089d0(u32 a) {
    u32 m = 1 << a;
    vu16 v1;
    data_0216fc40->mUnk_02 &= ~m;
    data_0216fc40->mUnk_04 &= ~m;
    v1 = 0;
    MemFillHalfwords(v1, &data_0216fc40->mUnk_10[a], sizeof(Unk02008934));
}

void func_0200895c(u32 a) {
    u32 m = 1 << a;
    vu16 v1;
    data_0216fc40->mUnk_02 &= ~m;
    data_0216fc40->mUnk_04 &= ~m;
    data_0216fc40->mUnk_10[a].mUnk_580 = 0;
    data_0216fc40->mUnk_10[a].mUnk_584 = 0;
    data_0216fc40->mUnk_10[a].mUnk_588 = 0;
    data_0216fc40->mUnk_10[a].mUnk_58c = 0;
    v1 = 0;
    MemFillHalfwords(v1, &data_0216fc40->mUnk_10[a], 0x4c0);
}

Unk02008934 *func_02008934(u32 a) {
    if ((data_0216fc40->mUnk_02 & (1 << a)) == 0) {
        return NULL;
    }
    return &data_0216fc40->mUnk_10[a];
}

#pragma thumb off
