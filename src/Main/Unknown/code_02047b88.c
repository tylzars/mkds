#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02047b88.h"
#include "code_0200d118.h"
#include "code_02004270.h"
#include "code_0200eddc.h"
#include "code_020176c0.h"
#include "code_020182c0.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_02004d80.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_02048284.h"
#include "Main/Unknown/code_020483e4.h"
#include "code_0214d464.h"
#include "code_0214d564.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "00/code_02182fdc.h"

#pragma thumb on

void func_02047b88(void) {
    s32 i;

    for (i = 0; i < 20; i++) {
        func_02047cf0(i);
    }
}

void func_02047ba0(s32 a) {
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2 && a == 6 && data_0217b488->mUnk_74 == 0) {
    } else {
        func_02048050(1, a);
    }
    switch (a) {
        case 1:
        case 12:
            func_02048050(5, a);
            func_02048050(14, a);
            func_02048050(16, a);
            break;
        case 10:
            func_02048050(0, a);
            func_02048050(5, a);
            func_02048050(16, a);
            func_02048050(18, a);
            break;
        case 2:
            func_02048050(18, a);
            func_02048050(6, a);
            func_02048050(8, a);
            break;
        case 3:
            func_02048050(0, a);
            func_02048050(5, a);
            func_02048050(16, a);
            break;
        case 5:
            func_02048050(5, a);
            func_02048050(14, a);
            func_02048050(16, a);
            break;
        case 0:
        case 7:
        case 8:
        case 9:
        case 11:
        case 13:
        case 14:
        case 15:
            func_02048050(5, a);
            func_02048050(16, a);
            break;
        case 4:
            if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
                func_02048050(5, a);
                func_02048050(16, a);
            }
            break;
        case 6:
            if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
                func_02048050(5, a);
                func_02048050(16, a);
            }
            break;
    }
}

void func_02047cf0(int a) {
    BOOL b;
    s32 c;

    b = TRUE;
    if (data_021759c8->mUnk_00[a].mLoaded != 0 && a != 0x13) {
        func_02018314(&data_021759c8->mUnk_00[a].mArchive.mUnk_00);
        if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
            c = data_usa_021543e0[a].mUnk_08;
            if (c != -1 && data_021759c8->mUnk_9b0[c].mUnk_08_29 != 0) {
                b = FALSE;
            } else {
                data_021759c8->mUnk_9b0[c].mUnk_08_31 = 1;
            }
        }
        if (b != FALSE) {
            func_02036b30(func_020364e0(func_020364e8()), data_021759c8->mUnk_00[a].mData);
        }
        data_021759c8->mUnk_00[a].mLoaded = 0;
        data_021759c8->mUnk_00[a].mData = 0;
        func_02017748(func_020364e0(func_020364e8()));
    }
}

void func_02047db8(void) {
    Unk021759c8_8c8 *p;
    Unk021759c8_00 *e;

    p = &data_021759c8->mUnk_8c8;
    e = &data_021759c8->mUnk_00[p->mUnk_8c];
    if (p->mUnk_84 != NULL) {
        if (func_02018344(&e->mArchive, (const u8 *) gArchiveNames[p->mUnk_8c], p->mUnk_84) != 0) {
            e->mLoaded = 1;
            e->mData = p->mUnk_84;
        }
    }
}

void func_02047e0c(void) {
    Unk021759c8_8c8 *p;
    u32 n;

    p = &data_021759c8->mUnk_8c8;
    n = *p->mUnk_80 >> 8;
    if (p->mUnk_90 != 0) {
        p->mUnk_84 = func_02036b74(func_020364e0(func_020364e8()), n, -0x20);
    } else {
        p->mUnk_84 = func_02036b74(func_020364e0(func_020364e8()), n, 0x20);
    }
    func_0214d344(p->mUnk_80, p->mUnk_84);
    func_0200ee58(p->mUnk_84, n);
    func_02017748(func_020364e0(func_020364e8()));
}

void func_02047e94(void) {
    Unk021759c8_8c8 *p;
    Unk02003024 f;
    u8 b[0x10];
    u32 n;
    s32 r;

    p = &data_021759c8->mUnk_8c8;
    FS_InitFile(&f);
    if (FS_OpenFile(&f, p->mUnk_00) == 0) {
        return;
    }
    if (FS_ReadFile(&f, p->mUnk_88, 4) < 0) {
        return;
    }
    n = *p->mUnk_88 >> 8;
    if (n > 0x200000) {
        return;
    }
    if (p->mUnk_90 != 0) {
        p->mUnk_84 = func_02036b74(func_020364e0(func_020364e8()), n, -0x20);
    } else {
        p->mUnk_84 = func_02036b74(func_020364e0(func_020364e8()), n, 0x20);
    }
    func_0214d564((u32) b, (u32) p->mUnk_84, (u32) p->mUnk_88);
    do {
        r = FS_ReadFile(&f, p->mUnk_88, 0x400);
        if (r <= 0) {
            return;
        }
    } while (func_0214d464(b, (const u8 *) p->mUnk_88, r) != 0);
    func_0200ee58(p->mUnk_84, n);
    func_02017748(func_020364e0(func_020364e8()));
}

void func_02047f7c(s32 a, const u8 *b, u32 *c, void *d, s32 e, s32 f, s32 g) {
    Unk021759c8_8c8 *p;
    s32 h;

    p = &data_021759c8->mUnk_8c8;
    strncpy(p->mUnk_00, b, 0x80);
    p->mUnk_8c = a;
    p->mUnk_80 = c;
    p->mUnk_84 = d;
    p->mUnk_90 = e;
    p->mUnk_94 = f;
    p->mUnk_9c = g;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        if (p->mUnk_80 != NULL) {
            if (p->mUnk_94 != 0) {
                h = data_usa_021543e0[a].mUnk_08;
                if (h != -1) {
                    data_021759c8->mUnk_9b0[h].mUnk_08_31 = 1;
                }
                func_02047e0c();
            } else {
                p->mUnk_84 = p->mUnk_80;
            }
            func_02047db8();
        }
    } else {
        if (a == 0x13) {
            func_02047e0c();
        } else {
            func_02047e94();
        }
        func_02047db8();
    }
}

// non-matching: 2 words; the last read of data_usa_021543e0 loads the table address before the a * 0x18 multiply in
// the original (ours: multiply first). The two (s32) a casts keep those reads from sharing the first reads' a * 0x18
// (as in the original); f is declared before e for the stack slots
void func_02048050(int a, int b) {
    u8 c[0x80] = {0};
    u32 *d;
    s32 f;
    s32 e;
    s32 g;
    s32 h;

    d = NULL;
    if (data_021759c8->mUnk_00[a].mLoaded != 0) {
        return;
    }
    e = data_usa_021543e0[a].mUnk_0c;
    f = data_usa_021543e0[a].mUnk_10;
    g = data_usa_021543e0[a].mUnk_14;
    h = data_usa_021543e0[a].mUnk_08;
    if (h != -1) {
        d = data_021759c8->mUnk_9b0[h].mUnk_04;
    }
    switch (a) {
        case 3:
        case 13:
            func_02048498((char *) c, data_021759c0->mCourseId, a != 3);
            break;
        case 5:
            switch (b) {
                case 2:
                    d = data_021759c8->mUnk_9b0[2].mUnk_04;
                    break;
                case 1:
                    d = data_021759c8->mUnk_9b0[0].mUnk_04;
                    break;
                case 10:
                    d = data_021759c8->mUnk_9b0[14].mUnk_04;
                    break;
            }
            switch (b) {
                case 10:
                    func_020483a0((char *) c);
                    break;
                case 2:
                    if (data_021759c0->mUnk_00c == 6) {
                        func_0200d9e0((char *) c, 0x80, data_usa_02165058);
                    } else {
                        func_020483e4((u32) c, (u8 *) data_usa_021541a8[b].mUnk_00);
                    }
                    break;
                default:
                    func_020483e4((u32) c, (u8 *) data_usa_021541a8[b].mUnk_00);
                    break;
            }
            g = data_usa_021541a8[b].mUnk_04;
            break;
        case 9:
            switch (b) {
                case 2:
                    d = data_021759c8->mUnk_9b0[3].mUnk_04;
                    break;
                case 1:
                    d = data_021759c8->mUnk_9b0[1].mUnk_04;
                    break;
                case 10:
                    d = data_021759c8->mUnk_9b0[15].mUnk_04;
                    break;
            }
            switch (b) {
                case 10:
                    func_02048350((char *) c);
                    break;
                case 2:
                    if (data_021759c0->mUnk_00c == 6) {
                        func_02048324((u32) c);
                    } else {
                        func_0204840c((u32) c, (u8 *) data_usa_021541a8[b].mUnk_00);
                    }
                    break;
                default:
                    func_0204840c((u32) c, (u8 *) data_usa_021541a8[b].mUnk_00);
                    break;
            }
            break;
        case 11:
            func_020482f0((u32) c, data_usa_021541a8[b].mUnk_00, data_021759c0->mUnk_08);
            break;
        case 12:
            func_020482ac((s32) c, (u8 *) data_usa_021541a8[b].mUnk_00, data_021759c0->mUnk_08);
            break;
        case 2:
        case 15:
        case 17:
            func_02048284((u32) data_usa_021543e0[a].mUnk_00, (u32) c);
            break;
        case 0:
        case 1:
        case 6:
        case 7:
        case 8:
        case 10:
        case 14:
        case 16:
        case 18:
            strncpy(c, (const u8 *) data_usa_021543e0[(s32) a].mUnk_00, 0x80);
            break;
    }
    if (c[0] != 0) {
        func_02047f7c(a, c, d, NULL, f, e, g);
    }
    h = data_usa_021543e0[(s32) a].mUnk_04;
    if (h != -1) {
        func_02048050(h, b);
    }
}

#pragma thumb off
