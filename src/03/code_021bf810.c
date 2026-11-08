#include "03/code_021bf810.h"
#include "03/code_021bf000.h"
#include "03/code_021b94b8.h"
#include "03/code_021cd2e0.h"
#include "03/code_021d1440.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf4dc.h"

#include "03/code_021d3488.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0200eddc.h"
#include "code_0214b824.h"
#include "03/code_021d1000.h"
#include "code_0214d018.h"
#include "03/code_021d27d8.h"
#include "03/unk_021d67d8.h"

void ReleaseHlScr(void) {
    FreeExpHeapBlockAndClearPointer(&gHlScr);
}

void LoadHlScr(int b) {
    void *a;

    a = LoadFile(BuildFilePathWithLanguage(gHlNscNames[b]), NULL, 4);
    MIi_CpuCopyFast(a, gHlScr, 0xc0);
    DeleteLoadedFile(a);
    AddTask(1, UploadHlScr, NULL, 0x78);
}

void LoadHlSetScr(void) {
    u32 value0;
    value0 = func_ov003_021cdb6c()->mUnk_f4;
    value0 = (value0) + (5u);
    LoadHlScr(value0);
}

void LoadHlListScr(void) {
    u32 value0;
    value0 = func_ov003_021cdb6c()->mUnk_f4;
    value0 = (value0) + (2u);
    LoadHlScr(value0);
}

void UploadHlScr(u32 a) {
    DC_FlushRange(gHlScr, 0xc0);
    GX_LoadBG1Scr(gHlScr, 0, 0xc0);
    RequestTaskRemoval(1, a);
}
