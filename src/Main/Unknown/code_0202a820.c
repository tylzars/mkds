#include "Main/Unknown/code_0202a820.h"
#include "Main/Unknown/code_02036000.h"

#include "Main/Unknown/code_02025ebc.h"
#include "code_02148950.h"

#pragma thumb on

void func_0202a90c(void) {
    func_02036ab0((void *) (gWiFiVSCourseSelect->mUnk_090));
    *&gWiFiVSCourseSelect = NULL;
    return;
}

#pragma thumb off

#pragma thumb on

void func_0202a820(void) {
    s32 t;

    func_02148950(1, 0, 0);
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | 0x1a00;
    *(vu16 *) 0x400100e = (*(vu16 *) 0x400100e & ~3) | 2;
    *(vu32 *) 0x4000010 = (-func_02025ebc(&gWiFiVSCourseSelect->mUnk_0cc[1]) << 16) & 0x1ff0000;
    *(vu32 *) 0x400101c = (-gWiFiVSCourseSelect->mUnk_154 << 16) & 0x1ff0000;
    if (gWiFiVSCourseSelect->mUnk_154 != 0) {
        *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffff1fff) | 0x2000;
        *(vu16 *) 0x4001048 = (u32) ((*(vu16 *) 0x4001048 & ~0x3f) | 0x1f) | 0x20;
        *(vu16 *) 0x400104a = (u32) ((*(vu16 *) 0x400104a & ~0x3f) | 7) | 0x20;
        t = gWiFiVSCourseSelect->mUnk_154 + 0xc0;
        *(vu16 *) 0x4001040 = 0xff;
        *(vu16 *) 0x4001044 = t & 0xff;
    } else {
        *(vu32 *) 0x4001000 = *(vu32 *) 0x4001000 & 0xffff1fff;
    }
}

#pragma thumb off
