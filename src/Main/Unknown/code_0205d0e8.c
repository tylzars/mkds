#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

void func_0205db50(void) {
    Unk0217aa1c *p;
    s32 i;
    s32 j;
    s32 k;
    Unk0217aa1c_00 *e;
    BOOL x;
    Unk0217aa1c_144_00 *f;

    p = data_0217aa1c;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            e = &p->mUnk_000[i][j];
            e->mUnk_03 = 0;
            e->mUnk_04 = 0;
            e->mUnk_00 = 0;
            e->mUnk_05 = 0;
            e->mUnk_02 = 0;
            e->mUnk_08 = 0;
            e->mUnk_09 = 0;
            e->mUnk_06 = 0;
        }
        for (k = 0; k < 2; k++) {
            f = &p->mUnk_144[i].mUnk_00[k];
            f->mUnk_00 = 0;
            f->mUnk_02 = 0;
        }
    }
    x = FALSE;
    if ((data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000) != 0 && data_0217aa00->mUnk_0004 != 13) {
        x = TRUE;
    }
    if (x != FALSE) {
        data_0217aa1c->mUnk_164_0 = 1;
    } else {
        data_0217aa1c->mUnk_164_0 = 0;
    }
    p->mUnk_140 = 0;
}

u8 func_0205db28(void) {
    return (u8) ((data_021759c0->mUnk_60 - 1) % 4);
}

void func_0205d9d4(u32 a, s32 b, u32 c) {
    Unk021759c0 *p;
    s8 i, j;
    s32 t, k, m;
    u16 v;
    u8 n;
    Unk0217aa1c_00 *e;

    p = data_021759c0;
    t = (p->mUnk_60 - 1) % 4;
    m = p->mUnk_08;
    k = (u8) t - 1;
    i = k;
    if (m == 2 || m == 3 || m == 5) {
        if (i < 0) {
            i = i + 4;
        }
    }
    if (i < 0) {
        v = 0;
    } else {
        v = data_0217aa1c->mUnk_000[i][(u8) a].mUnk_00;
    }
    j = k;
    if (m == 2 || m == 3 || m == 5) {
        if (j < 0) {
            j = j + 4;
        }
    }
    if (j < 0) {
        n = 0;
    } else {
        n = data_0217aa1c->mUnk_000[j][(u8) a].mUnk_05;
    }
    e = &data_0217aa1c->mUnk_000[(u8) t][(u8) a];
    e->mUnk_03 = b;
    e->mUnk_04 = c;
    e->mUnk_00 = v + c;
    if (e->mUnk_00 > 9999) {
        e->mUnk_00 = 9999;
    }
    if (b == 1) {
        n = n + 1;
    }
    if (n > 99) {
        n = 99;
    }
    e->mUnk_05 = n;
}

void func_0205d974(u32 a) {
    data_0217aa1c->mUnk_000[(u8) ((data_021759c0->mUnk_60 - 1) % 4)][(u8) a].mUnk_00 = 0;
}

void func_0205d88c(u32 a, s32 b) {
    Unk021759c0 *p;
    s8 i;
    s32 m, t, k;
    u8 c;
    Unk0217aa1c_00 *e;

    p = data_021759c0;
    t = (p->mUnk_60 - 1) % 4;
    m = p->mUnk_08;
    k = (u8) t - 1;
    i = k;
    if (m == 2 || m == 3 || m == 5) {
        if (i < 0) {
            i = i + 4;
        }
    }
    if (i < 0) {
        c = 0;
    } else {
        c = data_0217aa1c->mUnk_000[i][(u8) a].mUnk_05;
    }
    e = &data_0217aa1c->mUnk_000[(u8) t][(u8) a];
    e->mUnk_04 = 0;
    e->mUnk_03 = 1;
    e->mUnk_00 = 0;
    if (b != 0) {
        c = c + 1;
    }
    if (c > 99) {
        c = 99;
    }
    e->mUnk_05 = c;
}

void func_0205d818(u32 a, Unk0217aa1c_144_00 *b) {
    Unk0217aa1c_00 *e;
    Unk0217aa1c_144_00 *t;

    e = &data_0217aa1c->mUnk_000[(u8) ((data_021759c0->mUnk_60 - 1) % 4)][(u8) a];
    t = (Unk0217aa1c_144_00 *) &e->mUnk_06;
    t->mUnk_02 = b->mUnk_02;
    t->mUnk_03 = b->mUnk_03;
    t->mUnk_00 = b->mUnk_00;
}

void func_0205d7c8(Unk0217aa1c_144_00 *a, u32 b, u32 c) {
    Unk0217aa1c_00 *e;
    Unk0217aa1c_144_00 *t;

    e = &data_0217aa1c->mUnk_000[c][(u8) b];
    t = (Unk0217aa1c_144_00 *) &e->mUnk_06;
    a->mUnk_02 = t->mUnk_02;
    a->mUnk_03 = t->mUnk_03;
    a->mUnk_00 = t->mUnk_00;
}

void func_0205d76c(s32 a, u8 b) {
    data_0217aa1c->mUnk_000[(u8) ((data_021759c0->mUnk_60 - 1) % 4)][(u8) a].mUnk_02 = b;
}

void func_0205d6d0(s32 a) {
    s32 b;
    Unk0217aa1c_144_00 *p, *q;

    b = 0;
    if (a == 0) {
        b = 1;
    }
    p = data_0217aa1c->mUnk_144[(u8) ((data_021759c0->mUnk_60 - 1) % 4)].mUnk_00;
    p[a].mUnk_03_0 = 1;
    q = data_0217aa1c->mUnk_144[(u8) ((data_021759c0->mUnk_60 - 1) % 4)].mUnk_00;
    q[b].mUnk_03_0 = 0;
}

void func_0205d558(s32 a) {
    s32 j;
    u16 k, n;
    u32 r;
    s8 i;
    Unk0217aa1c_144 *v1;
    Unk0217aa1c_144_00 *e;

    for (j = 0; j < 2; j++) {
        n = 0;
        v1 = &data_0217aa1c->mUnk_144[(u8) ((data_021759c0->mUnk_60 - 1) % 4)];
        e = &v1->mUnk_00[(s32) j];
        i = (u8) ((data_021759c0->mUnk_60 - 1) % 4) - 1;
        if (data_021759c0->mUnk_08 == 2 || data_021759c0->mUnk_08 == 3 || data_021759c0->mUnk_08 == 5) {
            if (i < 0) {
                i = i + 4;
            }
        }
        if (i < 0) {
            r = 0;
        } else {
            r = data_0217aa1c->mUnk_144[i].mUnk_00[j].mUnk_02;
        }
        if (j == a) {
            r = (u8) (r + 1);
        }
        if (r > 99) {
            r = 99;
        }
        e->mUnk_02 = r;
        for (k = 0; k < (u32) data_021759c0->mKartCount; k++) {
            if (j == data_021759c0->mCurrentEntries[k].mUnk_08.mTeamIndex) {
                n = n + data_0217aa1c->mUnk_000[(u8) ((data_021759c0->mUnk_60 - 1) % 4)][(u8) (s32) (u8) k].mUnk_00;
            }
        }
        if (n > 9999) {
            n = 9999;
        }
        e->mUnk_00 = n;
    }
}

s32 func_0205d4e8(u32 a) {
    s32 m;
    Unk0217aa1c_00 *v1;
    Unk0217aa1c_00 *b;

    m = data_021759c0->mUnk_08;
    if (m == 0 || m == 3 || m == 5) {
        v1 = data_0217aa1c->mUnk_000[(u8) ((data_021759c0->mUnk_60 - 1) % 4)];
        b = &v1[(u8) a];
        return b->mUnk_02;
    }
    return 0;
}

s32 func_0205d480(void) {
    s32 j, r;
    Unk0217aa1c_144 *p;

    r = -1;
    p = &data_0217aa1c->mUnk_144[(u8) ((data_021759c0->mUnk_60 - 1) % 4)];
    for (j = 0; j < 2; j++) {
        if (p->mUnk_00[(u32) j].mUnk_03_0) {
            r = j;
            break;
        }
    }
    return r;
}

u16 func_0205d3f0(u32 a) {
    s32 m;
    s8 i;

    m = data_021759c0->mUnk_08;
    i = (u8) ((data_021759c0->mUnk_60 - 1) % 4) - 1;
    if (m == 2 || m == 3 || m == 5) {
        if (i < 0) {
            i = i + 4;
        }
    }
    if (i < 0) {
        return 0;
    }
    return data_0217aa1c->mUnk_000[i][(u8) a].mUnk_00;
}

u8 func_0205d360(u32 a) {
    s32 m;
    s8 i;

    m = data_021759c0->mUnk_08;
    i = (u8) ((data_021759c0->mUnk_60 - 1) % 4) - 1;
    if (m == 2 || m == 3 || m == 5) {
        if (i < 0) {
            i = i + 4;
        }
    }
    if (i < 0) {
        return 0;
    }
    return data_0217aa1c->mUnk_000[i][(u8) a].mUnk_05;
}

u8 func_0205d27c(u32 a) {
    Unk021759c0 *p;
    s32 m;
    s8 i;
    u8 r;

    p = data_021759c0;
    m = p->mUnk_08;
    i = (u8) ((p->mUnk_60 - 1) % 4) - 1;
    if (m == 2 || m == 3 || m == 5) {
        if (i < 0) {
            i = i + 4;
        }
    }
    if (m == 0 || m == 3 || m == 5) {
        if (i < 0) {
            r = p->mKartCount - a;
        } else {
            r = data_0217aa1c->mUnk_000[i][(u8) a].mUnk_03;
        }
    } else {
        r = p->mKartCount - a;
    }
    if (r == 0) {
        r = p->mKartCount - a;
    }
    return r;
}

s32 func_0205d190(void) {
    Unk021759c0 *p;
    Unk0217aa1c *q;
    s32 a, x, y, z;
    u16 v, c;
    u32 d;

    p = data_021759c0;
    q = data_0217aa1c;
    c = p->mEntryIndex;
    a = q->mUnk_140;
    d = (u8) c;
    v = q->mUnk_000[(u8) ((p->mUnk_60 - 1) % 4)][(u8) d].mUnk_00;
    if (a >= 1000) {
        x = 0;
    } else if (a >= 700) {
        x = 1;
    } else if (a >= 400) {
        x = 2;
    } else if (a >= 200) {
        x = 3;
    } else if (a >= 0) {
        x = 4;
    } else {
        x = 5;
    }
    if (v >= 40) {
        y = 0;
    } else if (v >= 36) {
        y = 1;
    } else if (v >= 30) {
        y = 2;
    } else if (v >= 20) {
        y = 3;
    } else {
        y = 4;
    }
    z = x + y;
    if (z >= 8) {
        z = 7;
    }
    return 7 - z;
}

s32 func_0205d140(void) {
    s32 a;

    a = data_0217aa1c->mUnk_140;
    if (a >= 100) {
        return 7;
    }
    if (a >= 90) {
        return 6;
    }
    if (a >= 70) {
        return 5;
    }
    if (a >= 50) {
        return 4;
    }
    if (a >= 0) {
        return 3;
    }
    return 2;
}

void func_0205d0e8(u8 a, u8 b) {
    s32 i;

    for (i = 0; i < 4; i++) {
        MemCopy(&data_0217aa1c->mUnk_000[i][a], &data_0217aa1c->mUnk_000[i][b], 10);
    }
}
