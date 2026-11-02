#include "code_02003be0.h"
#include "code_02003024.h"
#include "code_02004270.h"
#include "code_02004d80.h"
#include "code_0200dc3c.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_0214d000.h"

Unk02003a6c *FS_FindArchive(const u8 *p0, s32 p1) {
    u32 name;
    u32 state;
    Unk02003a6c *p;

    name = func_02004788(p0, p1);
    state = func_0200fca0();
    p = data_0216f340;
    while (p != 0 && p->mUnk_00 != name) {
        p = p->mUnk_04;
    }
    func_0200fcb4(state);
    return p;
}

u32 FS_RegisterArchiveName(Unk02003a6c *p0, const u8 *p1, s32 p2) {
    u32 ok;
    u32 state;
    Unk02003a6c *p;

    ok = 0;
    state = func_0200fca0();
    if (FS_FindArchive(p1, p2) == 0) {
        if (data_0216f340 == 0) {
            data_0216f340 = p0;
            data_0216f344.h.mUnk_00 = p0;
            data_0216f344.h.mUnk_08 = 0;
            data_0216f344.h.mUnk_06 = 0;
            data_0216f344.h.mUnk_04 = 0;
        } else {
            p = data_0216f340;
            while (p->mUnk_04 != 0) {
                p = p->mUnk_04;
            }
            p->mUnk_04 = p0;
            p0->mUnk_08 = p;
        }
        p0->mUnk_00 = func_02004788(p1, p2);
        ok = 1;
        p0->mUnk_1c |= 1;
    }
    func_0200fcb4(state);
    return ok;
}

void FS_ReleaseArchiveName(Unk02003a6c *p0) {
    u32 state;

    if (p0->mUnk_00 == 0) {
        return;
    }
    state = func_0200fca0();
    if (p0->mUnk_04 != 0) {
        p0->mUnk_04->mUnk_08 = p0->mUnk_08;
    }
    if (p0->mUnk_08 != 0) {
        p0->mUnk_08->mUnk_04 = p0->mUnk_04;
    }
    p0->mUnk_00 = 0;
    p0->mUnk_08 = 0;
    p0->mUnk_04 = p0->mUnk_08;
    p0->mUnk_1c &= ~1;
    if (data_0216f344.h.mUnk_00 == p0) {
        data_0216f344.h.mUnk_08 = 0;
        data_0216f344.h.mUnk_06 = 0;
        data_0216f344.h.mUnk_00 = data_0216f340;
        data_0216f344.h.mUnk_04 = 0;
    }
    func_0200fcb4(state);
}

u32 FS_LoadArchive(Unk02003a6c *p0, u8 *p1, u32 p2, u32 p3, u32 p4, u32 p5, s32 (*p6)(Unk02003a6c *, void *, u32, u32),
                   s32 (*p7)(Unk02003a6c *, void *, u32, u32)) {
    p0->mUnk_28 = p1;
    p0->mUnk_30 = p3;
    p0->mUnk_3c = p2;
    p0->mUnk_2c = p0->mUnk_3c;
    p0->mUnk_38 = p5;
    p0->mUnk_40 = p4;
    p0->mUnk_34 = p0->mUnk_40;
    p0->mUnk_48 = (p6 == 0) ? func_02004760 : p6;
    p0->mUnk_4c = (p7 == 0) ? func_02004734 : p7;
    p0->mUnk_50 = p0->mUnk_48;
    p0->mUnk_44 = 0;
    p0->mUnk_1c |= 2;
    return 1;
}

// non-matching: 'mov r0' and 'ldr r1' before the call to FS_SuspendArchive are swapped (2 words); the load is the
// taller node in either schedule (before or after colouring), so the original's block has a dependence or
// readiness difference that this source does not give
u32 FS_UnloadArchive(Unk02003a6c *p0) {
    u32 state;
    Unk02003024 *p;
    Unk02003024 *n;
    u32 s;

    state = func_0200fca0();
    if (((p0->mUnk_1c & 2) ? 1 : 0) != 0) {
        s = FS_SuspendArchive(p0, p0->mUnk_1c);
        p0->mUnk_1c |= 0x80;
        p = p0->mUnk_24;
        if (p != 0) {
            do {
                n = p->mUnk_04;
                FileFinishCommand(p, 3);
                p = n;
            } while (n != 0);
        }
        p0->mUnk_24 = 0;
        if (s != 0) {
            FS_ResumeArchive(p0);
        }
        p0->mUnk_28 = 0;
        p0->mUnk_2c = 0;
        p0->mUnk_30 = 0;
        p0->mUnk_34 = 0;
        p0->mUnk_38 = 0;
        p0->mUnk_40 = 0;
        p0->mUnk_3c = p0->mUnk_40;
        p0->mUnk_1c &= ~0xa2;
    }
    func_0200fcb4(state);
    return 1;
}

u32 FS_LoadArchiveTables(Unk02003a6c *p0, u32 p1, u32 p2) {
    Unk02003024 b;
    u32 sz;

    sz = ((s32) (p0->mUnk_30 + p0->mUnk_38 + 32) + 31) & ~31;
    if (sz <= p2) {
        u8 *p;

        p = (u8 *) ((p1 + 31) & ~31);
        func_02004d80(&b);
        if (func_02004afc(&b, p0, p0->mUnk_2c, p0->mUnk_2c + p0->mUnk_30, -1) != 0) {
            if (func_020048ac(&b, p, p0->mUnk_30) < 0) {
                func_0214d168(p, 0, p0->mUnk_30);
            }
            func_020049e8(&b);
        }
        p0->mUnk_2c = (u32) p;
        p += p0->mUnk_30;
        if (func_02004afc(&b, p0, p0->mUnk_34, p0->mUnk_34 + p0->mUnk_38, -1) != 0) {
            if (func_020048ac(&b, p, p0->mUnk_38) < 0) {
                func_0214d168(p, 0, p0->mUnk_38);
            }
            func_020049e8(&b);
        }
        p0->mUnk_34 = (u32) p;
        p0->mUnk_44 = p1;
        p0->mUnk_50 = func_02004710;
        p0->mUnk_1c |= 4;
    }
    return sz;
}

u32 FS_UnloadArchiveTables(Unk02003a6c *p0, u32 p1) {
    u32 r;
    u32 s;

    r = 0;
    if (((p0->mUnk_1c & 2) ? 1 : 0) != 0) {
        s = FS_SuspendArchive(p0, p1);
        if (((p0->mUnk_1c & 4) ? 1 : 0) != 0) {
            p0->mUnk_1c &= ~4;
            r = p0->mUnk_44;
            p0->mUnk_44 = 0;
            p0->mUnk_2c = p0->mUnk_3c;
            p0->mUnk_34 = p0->mUnk_40;
            p0->mUnk_50 = p0->mUnk_48;
        }
        if (s != 0) {
            FS_ResumeArchive(p0);
        }
    }
    return r;
}

u32 FS_SuspendArchive(Unk02003a6c *p0, u32 p1) {
    u32 state;
    u32 r;

    state = func_0200fca0();
    r = ((p0->mUnk_1c & 8) ? 1 : 0) == 0;
    if (r) {
        if (p0->mUnk_1c & 0x10) {
            p0->mUnk_1c |= 0x40;
            do {
                func_0200e01c(&p0->mUnk_14);
            } while (p0->mUnk_1c & 0x40);
        } else {
            p0->mUnk_1c |= 8;
        }
    }
    func_0200fcb4(state);
    return r;
}

u32 FS_ResumeArchive(Unk02003a6c *p0) {
    Unk02003024 *p;
    u32 state;
    u32 r;

    p = 0;
    state = func_0200fca0();
    r = ((p0->mUnk_1c & 8) ? 1 : 0) == 0;
    if (!r) {
        p0->mUnk_1c &= ~8;
        p = func_02004518(p0);
    }
    func_0200fcb4(state);
    if (p != 0) {
        func_02004474(p);
    }
    return r;
}

void FS_SetArchiveProc(Unk02003a6c *p0, s32 (*p1)(Unk02003024 *, u32), u32 p2) {
    if (p2 == 0) {
        p1 = 0;
    } else if (p1 == 0) {
        p2 = 0;
    }
    p0->mUnk_54 = p1;
    p0->mUnk_58 = p2;
}

void FS_NotifyArchiveAsyncEnd(Unk02003a6c *p0, u32 p1) {
    u32 state;
    Unk02003024 *p;

    if (p0->mUnk_1c & 0x100) {
        p = p0->mUnk_24;
        p0->mUnk_1c &= ~0x100;
        FileFinishCommand(p, p1);
        p = func_02004518(p0);
        if (p != 0) {
            func_02004474(p);
        }
    } else {
        p = p0->mUnk_24;
        state = func_0200fca0();
        p->mUnk_14 = p1;
        p0->mUnk_1c &= ~0x200;
        func_0200df9c(&p0->mUnk_0c);
        func_0200fcb4(state);
    }
}
