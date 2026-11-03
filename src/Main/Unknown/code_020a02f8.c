#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020681f0.h"
#include "Main/Unknown/code_020a02f8.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02068000.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_02175628.h"

Unk02175620_84 *func_020a0f0c(void) {
    Unk020f41c4_B *a;
    u16 v;
    s32 w;

    a = &data_0217561c->mUnk_47c;
    a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
    v = (u16) (((u64) (u32) (a->mUnk_00 >> 32) * 5) >> 32) + 1;
    w = data_0217b1fc->mUnk_3b8 + v;
    if (w >= gCourseMap->mUnk_88) {
        w = 0;
    }
    data_0217b1fc->mUnk_3b8 = w;
    return &gCourseMap->mUnk_84[data_0217b1fc->mUnk_3b8];
}

void func_020a0e00(void) {
    s32 i;
    Unk0217b1fc_000 *e;

    data_0217b1fc = func_02036bec(func_020364e0(func_020364e8()), 0x3c0);
    for (i = 0; i < 8; i++) {
        e = &data_0217b1fc->mUnk_000[i];
        e->mUnk_1c = -2;
        e->mUnk_18 = -2;
        e->mUnk_44 = (u16) i;
        e->mUnk_48 = (u16) i;
        if (i < data_021759c0->mKartCount) {
            switch (data_021759c0->mUnk_68[(u16) i].mUnk_08.mTeamIndex) {
                case 0:
                    e->mUnk_46 = 1;
                    break;
                case 1:
                    e->mUnk_46 = 3;
                    break;
                default:
                    e->mUnk_46 = (u16) i;
                    break;
            }
            e->mUnk_08 = 0;
            e->mUnk_4c = 0;
            e->mUnk_50 = 0;
        } else {
            e->mUnk_08 = 2;
            e->mUnk_4c = -1;
            e->mUnk_50 = 0;
            e->mUnk_46 = data_021759c0->mKartCount;
        }
    }
    data_0217b1fc->mUnk_3b4 = -1;
}

void func_020a0dbc(void) {
    data_0217b1fc->mUnk_3a8 = -1;
    if (data_0217b1fc->mUnk_390 != NULL) {
        data_0217b1fc->mUnk_390();
    }
}

void func_020a08ec(void) {
    Unk0206bcb0 *o;
    BOOL a;
    BOOL b;
    s32 v;
    u32 f;
    s32 i;
    s32 n;
    Unk0217b1fc_000 *e = data_0217b1fc->mUnk_000;

    n = data_021759c0->mKartCount;
    if (data_0217b1fc->mUnk_3b4 >= 0) {
        if (data_0217b1fc->mUnk_3a8 > 0) {
            data_0217b1fc->mUnk_3a8 = data_0217b1fc->mUnk_3a8 - 1;
            if (data_0217b1fc->mUnk_3a8 <= 0) {
                data_0217b1fc->mUnk_3a8 = -1;
                if (data_0217b1fc->mUnk_390 != NULL) {
                    data_0217b1fc->mUnk_390();
                }
            }
        }
        for (i = 0; i < n; i++) {
            if (data_0217b1fc->mUnk_000[i].mUnk_08 == 1) {
                if (i != data_021759c0->mUnk_62) {
                    func_02068a00(func_0207a974((u16) i));
                }
                data_0217b1fc->mUnk_000[i].mUnk_08 = 2;
            }
        }
        return;
    }
    for (i = n - 1; i >= 0; i--) {
        e = &data_0217b1fc->mUnk_000[i];
        if (e->mUnk_08 == 1) {
            func_02068a00(func_0207a974((u16) i));
            data_0217b1fc->mUnk_000[i].mUnk_08 = 2;
        } else if (data_0217b1fc->mUnk_3b4 < 0 && e->mUnk_4c > 0) {
            o = func_0207a974((u16) i);
            e = &data_0217b1fc->mUnk_000[i];
            v = e->mUnk_64 - 1;
            if (v <= 0) {
                v = 0;
            }
            e->mUnk_64 = v;
            data_0217b1fc->mUnk_000[i].mUnk_68 = -(data_0217b1fc->mUnk_000[i].mUnk_68 <= 0);
            if (func_01ffc67c(o) != 0 || (u16) (data_02175628[o->mUnk_78].mUnk_02 & 3) != 0) {
                data_0217b1fc->mUnk_000[i].mUnk_68 = -1;
                data_0217b1fc->mUnk_000[i].mUnk_64 = -1;
            } else if (func_02061fec() == 1) {
                if ((u16) (data_02175628[(u32) o->mUnk_78].mUnk_02 & 4) != 0) {
                    data_0217b1fc->mUnk_000[i].mUnk_68 = 1;
                } else if (data_02175628[o->mUnk_78].mUnk_5a != 0) {
                    data_0217b1fc->mUnk_000[i].mUnk_64 = 10;
                }
            }
            if (data_0217b1fc->mUnk_388 != NULL) {
                b = TRUE;
                f = o->mUnk_48;
                a = (f & 0x200) != 0;
                if (o->mState == 0 && (f & 0x4000000) == 0) {
                    b = FALSE;
                }
                if (e->mUnk_04 == 0 && a != FALSE && (o->mUnk_4c & 0x400000) == 0) {
                    e->mUnk_04 = 1;
                    e->mUnk_00 = 0;
                    e->mUnk_18 = -2;
                    e->mUnk_44 = (u16) i;
                    e->mUnk_20 = 0;
                    if (e->mUnk_4c <= 1) {
                        if ((data_021759c0->mUnk_08 == 2 && data_021759c0->mUnk_18 == 0) ||
                            data_021759c0->mUnk_08 == 4) {
                            o->mUnk_7c |= 0x20000000;
                            o->mUnk_48 &= ~0x2000000;
                        }
                    }
                } else if (e->mUnk_04 == 1 && (o->mUnk_44 & 0x10000) != 0) {
                    e->mUnk_04 = 0;
                    e->mUnk_1c = 0;
                    if ((o->mUnk_4c & 0x400000) == 0) {
                        func_0206c17c(o);
                    }
                }
                if (e->mUnk_1c == 0) {
                    e->mUnk_1c = -2;
                    data_0217b1fc->mUnk_388((u16) i, 8);
                    e->mUnk_44 = i;
                } else if (e->mUnk_1c >= 0) {
                    e->mUnk_1c = e->mUnk_1c + 1;
                }
                if (e->mUnk_00 == 0 && b != FALSE && (o->mUnk_4c & 0x400000) == 0) {
                    e->mUnk_00 = 1;
                    if (e->mUnk_4c <= 1) {
                        if ((data_021759c0->mUnk_08 == 2 && data_021759c0->mUnk_18 == 0) ||
                            data_021759c0->mUnk_08 == 4) {
                            o->mUnk_7c |= 0x20000000;
                        }
                    }
                } else if (e->mUnk_00 == 1 && b == FALSE && (o->mUnk_48 & 0x6052840) == 0) {
                    e->mUnk_00 = 0;
                    if (e->mUnk_20 == 0) {
                        e->mUnk_18 = 0;
                        if ((o->mUnk_4c & 0x400000) == 0) {
                            func_0206c17c(o);
                        }
                    } else {
                        e->mUnk_20 = 0;
                    }
                }
                if (e->mUnk_18 == 0) {
                    e->mUnk_18 = -2;
                    data_0217b1fc->mUnk_388((u16) i, e->mUnk_44);
                    e->mUnk_44 = i;
                } else if (e->mUnk_18 >= 0) {
                    e->mUnk_18 = e->mUnk_18 + 1;
                }
            }
            e->mUnk_0c = o->mUnk_80;
        }
    }
}

void func_020a089c(Unk020a0318 *p) {
    s32 v;

    v = data_021759c0->mCourseId;
    if (v == 0x12) {
        p->mUnk_bc = 0x121;
    } else if (v == 0x1f) {
        p->mUnk_bc = 0x111;
        p->mUnk_be = 0x10a;
    } else {
        p->mUnk_bc = 0x20d;
    }
}

void func_020a066c(Unk020a066c *p) {
    s32 i;
    Unk020a0318 *o;
    Unk020f41c4_B *a;

    if (p == NULL) {
        return;
    }
    for (i = 0; i < p->mUnk_04 && (o = p->mUnk_00[i]) != NULL; i++) {
        if (data_021759c0->mCourseId == 0x12) {
            o->mUnk_a8 = 0xa28;
            o->mUnk_ac = o->mUnk_00.mUnk_04.x + 0x73a000;
            o->mUnk_b0 = o->mUnk_00.mUnk_04.y;
            o->mUnk_b4 = o->mUnk_00.mUnk_04.z - 0x1400000;
            o->mUnk_b8 = 1;
        } else if (data_021759c0->mCourseId == 0x1f) {
            o->mUnk_a8 = 0x546;
            o->mUnk_ac = o->mUnk_00.mUnk_04.x + 0x28a000;
            o->mUnk_b0 = o->mUnk_00.mUnk_04.y;
            o->mUnk_b4 = o->mUnk_00.mUnk_04.z - 0x32000;
            o->mUnk_b8 = 0;
        } else {
            o->mUnk_a8 = 0xa28;
            o->mUnk_ac = o->mUnk_00.mUnk_04.x;
            o->mUnk_b0 = o->mUnk_00.mUnk_04.y;
            o->mUnk_b4 = o->mUnk_00.mUnk_04.z;
            o->mUnk_b8 = 0;
        }
        a = &data_0217561c->mUnk_498;
        a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
        o->mUnk_c8 = (u16) (((u64) (u32) (a->mUnk_00 >> 32) * 0x3c) >> 32) + 0x258;
        o->mUnk_a4 = 0x7f000;
        a = &data_0217561c->mUnk_498;
        a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
        o->mUnk_c0 = (u16) (((u64) (u32) (a->mUnk_00 >> 32) * 0xf) >> 32);
    }
}

void func_020a0318(void *a, Unk020a0318 *p) {
    Unk0206bcb0 *o;
    Unk0212c400 **h;
    Unk020f41c4_B *r;
    Unk0210b7a8 s1;
    Unk0210b7a8 s2;
    s32 v;
    s32 x;
    s32 w;
    s32 z;
    s32 y;
    s64 d;

    if (p->mUnk_c0-- <= 0) {
        p->mUnk_c0 = 0xf;
        w = p->mUnk_a8;
        x = w / 2;
        o = func_0207a974((u16) data_021759c0->mUnk_62);
        y = o->mUnk_80.x - p->mUnk_ac;
        z = o->mUnk_80.z - p->mUnk_b4;
        d = (s64) y * y + (s64) z * z;
        if (d < (s64) x * x) {
            v = 2;
        } else if (d < (s64) (w << 12) * (w << 12)) {
            v = 1;
        } else {
            v = 0;
        }
        p->mUnk_c4 = v;
        if (p->mUnk_b8 != 0) {
            p->mUnk_c4 = p->mUnk_c4 == 0;
        }
    }
    if (p->mUnk_c4 > 1) {
        p->mUnk_a4 = 0x7f001;
    } else if (p->mUnk_c4 > 0) {
        p->mUnk_a4 = p->mUnk_a4 + 0x4000;
        if (p->mUnk_a4 > 0x7f000) {
            p->mUnk_a4 = 0x7f000;
        }
    } else {
        p->mUnk_a4 = p->mUnk_a4 - 0x4000;
        if (p->mUnk_a4 < 0) {
            p->mUnk_a4 = 0;
        }
    }
    if (p->mUnk_bc != 0) {
        if (p->mUnk_c4 != 0) {
            if (*func_02108e6c(8) != NULL) {
                o = func_0207a974((u16) data_021759c0->mUnk_62);
                p->mUnk_a0 = p->mUnk_a0 - (s32) (((s64) o->mUnk_2a0 * 0x1000) >> 12);
                if (p->mUnk_a0 < 0xc000) {
                    p->mUnk_a0 = 0xc000;
                }
            } else if (p->mUnk_c8-- <= 0) {
                h = func_02108e6c(8);
                s1.mUnk_00 = p->mUnk_bc;
                s1.mUnk_04 = NULL;
                s1.mUnk_08 = 4;
                s1.mUnk_0c = func_020d4ef4(NULL);
                func_0210b760(&s1, h);
                r = &data_0217561c->mUnk_498;
                r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
                p->mUnk_c8 = (u16) (((u64) (u32) (r->mUnk_00 >> 32) * 0x3c) >> 32) + 0x78;
                p->mUnk_a0 = 0x7f000;
            }
        } else if (p->mUnk_c8 > 0) {
            p->mUnk_c8 = p->mUnk_c8 - 1;
        }
        if (*func_02108e6c(8) != NULL) {
            v = p->mUnk_a4 < p->mUnk_a0 ? p->mUnk_a4 : p->mUnk_a0;
            func_02105b28(func_02108e6c(8), v >> 12);
        }
    }
    if (p->mUnk_be == 0) {
        return;
    }
    if (p->mUnk_c4 != 0) {
        if (*func_02108e6c(9) == NULL) {
            h = func_02108e6c(9);
            s2.mUnk_00 = p->mUnk_be;
            s2.mUnk_04 = NULL;
            s2.mUnk_08 = 4;
            s2.mUnk_0c = func_020d4ef4(NULL);
            func_0210b760(&s2, h);
        }
    }
    if (*func_02108e6c(9) == NULL) {
        return;
    }
    func_02105b28(func_02108e6c(9), p->mUnk_a4 >> 12);
}

u32 func_020a02f8(void) {
    return func_0209bf48(func_020a066c, func_020a0318, NULL);
}
