#include "code_020182c0.h"
#include "code_02004d80.h"
#include "code_02003be0.h"
#include "code_02139f70.h"

u32 ArchiveHeaderMatches(Unk02018344 *a) {
    if (a->mUnk_00 != 0x4352414e) {
        return 0;
    }
    if (a->mUnk_04 != 0xfffe) {
        return 0;
    }
    return a->mUnk_06 == 0x100 ? 1 : 0;
}

u32 ArchiveLoadFromMemory(Unk020182c0 *a, const u8 *b, Unk02018344 *c) {
    u8 *p6;
    u8 *p5;
    u8 *p4;
    s32 i;
    u8 *p;
    s32 n;

    p6 = 0;
    p5 = 0;
    p4 = 0;
    if (ArchiveHeaderMatches(c) == 0) {
        return 0;
    }
    p = (u8 *) c + c->mUnk_0c;
    n = c->mUnk_0e;
    for (i = 0; i < n; i++) {
        switch (*(u32 *) p) {
            case 0x46415442:
                p6 = p;
                break;
            case 0x464e5442:
                p5 = p;
                break;
            case 0x46494d47:
                p4 = p;
                break;
        }
        p += *(u32 *) (p + 4);
    }
    FS_InitArchive(&a->mUnk_00);
    a->mUnk_5c = c;
    a->mUnk_60 = p6;
    p4 = (u8 *) p4 + 8;
    a->mUnk_64 = p4;
    if (FS_RegisterArchiveName(&a->mUnk_00, b, strlen((const char *) b)) == 0) {
        return 0;
    }
    if (FS_LoadArchive(&a->mUnk_00, p4, p6 + 0xc - p4, *(u32 *) (p6 + 4) - 0xc, p5 + 8 - p4, *(u32 *) (p5 + 4) - 8, 0,
                       0) != 0) {
        return 1;
    }
    FS_ReleaseArchiveName(&a->mUnk_00);
    return 0;
}

u32 ArchiveUnload(FSArchive *a) {
    if (FS_UnloadArchive(a) == 0) {
        return 0;
    }
    FS_ReleaseArchiveName(a);
    return 1;
}

void *ArchiveFileGetAddress(const u8 *a) {
    FSFile s;
    void *r;

    r = NULL;
    FS_InitFile(&s);
    if (FS_OpenFile(&s, a) != 0) {
        r = ((Unk020182c0 *) s.mArc)->mUnk_64 + s.mProp.w.mUnk_04;
        FS_CloseFile(&s);
    }
    return r;
}
