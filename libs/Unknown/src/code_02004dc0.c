#include "code_02004dc0.h"
#include "code_02003be0.h"
#include "Main/Unknown/code_02000000.h"
#include "code_02004d80.h"
#include "Main/Unknown/code_02000920.h"
#include "Main/Unknown/code_0200c000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200cd1c.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "code_0214578c.h"
#include "Main/Unknown/code_02146000.h"
#include "code_021458c4.h"
#include "code_0214d018.h"
#include "code_02150808.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/unk_0217e000.h"
#include "Main/Unknown/unk_02152000.h"

u32 data_0216f350;
u32 data_0216f354;
u32 data_0216f358;
Unk02005704 data_0216f364;
Unk02005704 data_0216f35c;
Unk02003a6c data_0216f36c;

void *data_02161768 = data_02152b80;
u8 data_02161764[4] = "rom";
u32 data_0216176c = 0x40;

s32 FileGetOverlayLoadSize(Unk020055f0 *p) {
    if (p->mUnk_1c.b[3] & 1) {
        return p->mUnk_1c.f.mUnk_00_0;
    }
    return p->mUnk_08;
}

void FS_ClearOverlayImage(Unk020055f0 *p) {
    u8 *b;
    s32 n;
    s32 a;

    n = p->mUnk_08;
    a = n + p->mUnk_0c;
    b = p->mUnk_04;
    IC_InvalidateRange(b, a);
    DC_InvalidateRange(b, a);
    MI_CpuFill8(b + n, 0, a - n);
}

void FS_GetOverlayFileID(Unk02005814 *dst, Unk020055f0 *src) {
    Unk02005814 tmp;

    tmp.mUnk_00 = &data_0216f36c;
    tmp.mUnk_04 = src->mUnk_18;
    *dst = tmp;
}

u32 FileReadOverlayEntry(Unk020055f0 *dst, u32 sel, u32 idx, Unk02003a6c *owner, u8 *base0, u32 size0, u8 *base1,
                         u32 size1) {
    Unk02003024 o;
    Unk02005814 s;
    u32 off;
    u8 *base;
    u32 size;

    if (sel == 0) {
        size = size0;
        base = base0;
    } else {
        size = size1;
        base = base1;
    }
    off = idx << 5;
    if (off >= size) {
        return 0;
    }
    FS_InitFile(&o);
    if (FS_OpenFileDirect(&o, owner, (u32) (base + off), (u32) (base + size), -1) == 0) {
        return 0;
    }
    if (FS_ReadFile(&o, dst, 0x20) != 0x20) {
        FS_CloseFile(&o);
        return 0;
    }
    FS_CloseFile(&o);
    dst->mUnk_20 = sel;
    FS_GetOverlayFileID(&s, dst);
    if (FS_OpenFileFast(&o, s) == 0) {
        return 0;
    }
    dst->mUnk_24 = o.mUnk_20.p.mUnk_04;
    dst->mUnk_28 = o.mUnk_20.p.mUnk_08 - o.mUnk_20.p.mUnk_04;
    FS_CloseFile(&o);
    return 1;
}

u32 FS_LoadOverlayInfo(Unk020055f0 *dst, u32 sel, u32 idx) {
    Unk02003024 o;
    Unk02005814 s;
    Unk02005704 *tab;
    Unk02005704 *x;
    Unk02005704 *y;

    if (sel == 0) {
        tab = &data_0216f35c;
    } else {
        tab = &data_0216f364;
    }
    if (tab->mUnk_00 != 0) {
        if (idx * 32 >= tab->mUnk_04) {
            return 0;
        }
        MI_CpuCopy8(tab->mUnk_00 + idx * 32, dst, 0x20);
        dst->mUnk_20 = sel;
        FS_InitFile(&o);
        FS_GetOverlayFileID(&s, dst);
        if (FS_OpenFileFast(&o, s) == 0) {
            return 0;
        }
        dst->mUnk_24 = o.mUnk_20.p.mUnk_04;
        dst->mUnk_28 = o.mUnk_20.p.mUnk_08 - o.mUnk_20.p.mUnk_04;
        FS_CloseFile(&o);
        return 1;
    }
    x = (Unk02005704 *) 0x27ffe50;
    y = (Unk02005704 *) 0x27ffe58;
    return FileReadOverlayEntry(dst, sel, idx, &data_0216f36c, x->mUnk_00, x->mUnk_04, y->mUnk_00, y->mUnk_04);
}

u32 FS_LoadOverlayImageAsync(Unk020055f0 *rec, Unk02003024 *o) {
    Unk02005814 s;
    s32 n;

    FS_InitFile(o);
    FS_GetOverlayFileID(&s, rec);
    if (FS_OpenFileFast(o, s) == 0) {
        return 0;
    }
    n = FileGetOverlayLoadSize(rec);
    FS_ClearOverlayImage(rec);
    if (n == FS_ReadFileAsync(o, rec->mUnk_04, n)) {
        return 1;
    }
    FS_CloseFile(o);
    return 0;
}

u32 FS_LoadOverlayImage(Unk020055f0 *rec) {
    Unk02005814 s;
    Unk02003024 o;
    s32 n;

    FS_InitFile(&o);
    FS_GetOverlayFileID(&s, rec);
    if (FS_OpenFileFast(&o, s) == 0) {
        return 0;
    }
    n = FileGetOverlayLoadSize(rec);
    FS_ClearOverlayImage(rec);
    if (n != FS_ReadFile(&o, rec->mUnk_04, n)) {
        FS_CloseFile(&o);
        return 0;
    }
    FS_CloseFile(&o);
    return 1;
}

u32 FileCheckHmac(const u8 *expected, const u8 *data, u32 n) {
    u8 d[0x14];
    u8 k[0x40];
    u32 i;

    MI_CpuFill8(d, 0, 0x14);
    MI_CpuCopy8(data_02161768, k, data_0216176c);
    DGT_Hash2CalcHmac(d, data, n, k, data_0216176c);
    for (i = 0; i < 0x14; i += 4) {
        if (*(u32 *) (d + i) != *(u32 *) (expected + i)) {
            break;
        }
    }
    return i == 0x14;
}

void FS_StartOverlay(Unk020055f0 *rec) {
    u32 n;
    u32 ok;
    void (**p)(void);
    void (**end)(void);

    n = FileGetOverlayLoadSize(rec);
    if (*(u16 *) 0x27ffc40 == 2) {
        ok = 0;
        if (rec->mUnk_1c.b[3] & 2) {
            if (rec->mUnk_00 < ((u8 *) &data_0216f340 - (u8 *) OverlaySignatures) / 20) {
                ok = FileCheckHmac(OverlaySignatures[rec->mUnk_00], rec->mUnk_04, n);
            }
        }
        if (ok == 0) {
            MI_CpuFill8(rec->mUnk_04, 0, n);
            OS_Terminate();
            return;
        }
    }
    if (rec->mUnk_1c.b[3] & 1) {
        func_02000934(rec->mUnk_04 + n);
    }
    DC_FlushRange(rec->mUnk_04, rec->mUnk_08);
    p = rec->mUnk_10;
    end = rec->mUnk_14;
    if (p >= end) {
        return;
    }
    do {
        if (*p != 0) {
            (*p)();
        }
        p++;
    } while (p < end);
}

void FS_EndOverlay(Unk020055f0 *rec) {
    Unk02005210 *prev;
    Unk02005210 *head;
    Unk02005210 *cur;
    Unk02005210 *next;
    Unk02005210 *found;
    Unk02005210 *last;
    u32 lo;
    u32 hi;
    u32 irq;
    u32 x;
    void *y;

    for (;;) {
        lo = (u32) rec->mUnk_04;
        hi = lo + (rec->mUnk_08 + rec->mUnk_0c);
        found = 0;
        last = 0;
        irq = OS_DisableInterrupts();
        prev = 0;
        head = data_0217eeb0;
        cur = head;
        if (head != 0) {
            do {
                y = cur->mUnk_08;
                next = cur->mUnk_00;
                x = (u32) cur->mUnk_04;
                if ((y == 0 && x >= lo && x < hi) || ((u32) y >= lo && (u32) y < hi)) {
                    if (last != 0) {
                        last->mUnk_00 = cur;
                    } else {
                        found = cur;
                    }
                    if (head == cur) {
                        data_0217eeb0 = next;
                        head = next;
                    }
                    cur->mUnk_00 = 0;
                    last = cur;
                    if (prev != 0) {
                        prev->mUnk_00 = next;
                    }
                } else {
                    prev = cur;
                }
                cur = next;
            } while (cur != 0);
        }
        OS_RestoreInterrupts(irq);
        if (found == 0) {
            return;
        }
        do {
            next = found->mUnk_00;
            if (found->mUnk_04 != 0) {
                found->mUnk_04(found->mUnk_08);
            }
            found = next;
        } while (found != 0);
    }
}

u32 FS_UnloadOverlayImage(Unk020055f0 *rec) {
    FS_EndOverlay(rec);
    return 1;
}

u32 FS_LoadOverlay(u32 sel, u32 idx) {
    Unk020055f0 rec;

    if (FS_LoadOverlayInfo(&rec, sel, idx) == 0 || FS_LoadOverlayImage(&rec) == 0) {
        return 0;
    }
    FS_StartOverlay(&rec);
    return 1;
}

u32 FS_UnloadOverlay(u32 sel, u32 idx) {
    Unk020055f0 rec;

    if (FS_LoadOverlayInfo(&rec, sel, idx) == 0 || FS_UnloadOverlayImage(&rec) == 0) {
        return 0;
    }
    return 1;
}

void FS_AttachOverlayTable(u32 sel, u8 *data, u32 n) {
    Unk02005704 *dst;
    u32 irq;

    if (data != 0 && sel == 0) {
        irq = DGT_SetOverlayTableMode(1);
        if (FileCheckHmac(data_0216f2dc, data, n) == 0) {
            OS_Terminate();
        }
        DGT_SetOverlayTableMode(irq);
    }
    if (sel == 0) {
        dst = &data_0216f35c;
    } else {
        dst = &data_0216f364;
    }
    irq = OS_DisableInterrupts();
    dst->mUnk_00 = data;
    dst->mUnk_04 = n;
    OS_RestoreInterrupts(irq);
}

void FileFinishCardRead(Unk02003a6c *p) {
    FS_NotifyArchiveAsyncEnd(p, 0);
}

s32 FileStartCardRead(Unk02003a6c *p, void *buf, u32 off, u32 n) {
    CARDi_ReadRom(data_0216f358, off, (u32) buf, n, FileFinishCardRead, (u32) p, 1);
    return 6;
}

s32 FileWriteFail(Unk02003a6c *p0, void *p1, u32 p2, u32 p3) {
    return 1;
}

s32 FileHandleRomLock(Unk02003024 *p, u32 cmd) {
    switch (cmd) {
        case 9:
            CARD_LockRom(data_0216f354);
            return 0;
        case 10:
            CARD_UnlockRom(data_0216f354);
            return 0;
        case 1:
            return 4;
        default:
            return 8;
    }
}

s32 FileReadFail(Unk02003a6c *p0, void *p1, u32 p2, u32 p3) {
    return 1;
}

s32 FileRejectAllCommands(Unk02003024 *p0, u32 p1) {
    return 4;
}

void FileInitRomArchive(u32 arg) {
    enum { K0 } x, y;

    data_0216f358 = arg;
    data_0216f354 = OS_GetLockID();
    data_0216f35c.mUnk_00 = 0;
    data_0216f35c.mUnk_04 = 0;
    data_0216f364.mUnk_00 = 0;
    data_0216f364.mUnk_04 = 0;
    CARD_Init();
    FS_InitArchive(&data_0216f36c);
    FS_RegisterArchiveName(&data_0216f36c, data_02161764, 3);
    if (*(u16 *) 0x27ffc40 == 2) {
        data_0216f35c.mUnk_00 = (u8 *) -1;
        data_0216f35c.mUnk_04 = 0;
        data_0216f364.mUnk_00 = (u8 *) -1;
        data_0216f364.mUnk_04 = 0;
        FS_SetArchiveProc(&data_0216f36c, FileRejectAllCommands, -1);
        FS_LoadArchive(&data_0216f36c, 0, 0, 0, 0, 0, FileReadFail, FileWriteFail);
        return;
    }
    x = 0x27ffe40;
    y = 0x27ffe48;
    FS_SetArchiveProc(&data_0216f36c, FileHandleRomLock, 0x602);
    if (((Unk02005704 *) x)->mUnk_00 == (u8 *) -1) {
        return;
    }
    if (((Unk02005704 *) x)->mUnk_00 == 0) {
        return;
    }
    if (((Unk02005704 *) y)->mUnk_00 == (u8 *) -1) {
        return;
    }
    if (((Unk02005704 *) y)->mUnk_00 == 0) {
        return;
    }
    FS_LoadArchive(&data_0216f36c, 0, (u32) ((Unk02005704 *) y)->mUnk_00, ((Unk02005704 *) y)->mUnk_04,
                   (u32) ((Unk02005704 *) x)->mUnk_00, ((Unk02005704 *) x)->mUnk_04, FileStartCardRead, FileWriteFail);
}

u32 FS_TryLoadTable(u32 a, u32 b) {
    return FS_LoadArchiveTables(&data_0216f36c, a, b);
}

void FS_Init(u32 arg) {
    if (data_0216f350 != 0) {
        return;
    }
    data_0216f350 = 1;
    FileInitRomArchive(arg);
}
