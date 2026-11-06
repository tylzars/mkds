#include "code_0214b824.h"
#include "code_0214c778.h"
#include "code_0214cfe4.h"
#include "code_02148950.h"
#include "code_02149e90.h"
#include "code_02149fe0.h"
#include "code_0214a000.h"
#include "code_0214a054.h"
#include "code_0214a2c0.h"
#include "code_0214a314.h"
#include "code_0214a034.h"
#include "code_0214a2a0.h"
#include "code_0214a2f4.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0216f000.h"

void GX_LoadBGPltt(const void *src, u32 offset, u32 size) {
    if (data_0216f074[0] != -1 && size > 0x1c) {
        MI_DmaCopy16(data_0216f074[0], src, (void *) (0x5000000 + offset), size);
    } else {
        MIi_CpuCopy16(src, (void *) (0x5000000 + offset), size);
    }
}

void GXS_LoadBGPltt(const void *src, u32 offset, u32 size) {
    if (data_0216f074[0] != -1 && size > 0x1c) {
        MI_DmaCopy16(data_0216f074[0], src, (void *) (0x5000400 + offset), size);
    } else {
        MIi_CpuCopy16(src, (void *) (0x5000400 + offset), size);
    }
}

void GX_LoadOBJPltt(const void *src, u32 offset, u32 size) {
    if (data_0216f074[0] != -1 && size > 0x1c) {
        MI_DmaCopy16(data_0216f074[0], src, (void *) (0x5000200 + offset), size);
    } else {
        MIi_CpuCopy16(src, (void *) (0x5000200 + offset), size);
    }
}

void GXS_LoadOBJPltt(const void *src, u32 offset, u32 size) {
    if (data_0216f074[0] != -1 && size > 0x1c) {
        MI_DmaCopy16(data_0216f074[0], src, (void *) (0x5000600 + offset), size);
    } else {
        MIi_CpuCopy16(src, (void *) (0x5000600 + offset), size);
    }
}

void GX_LoadOAM(const void *src, u32 offset, u32 size) {
    if (data_0216f074[0] != -1 && size > 0x30) {
        MI_DmaCopy32(data_0216f074[0], src, (void *) (0x7000000 + offset), size);
    } else {
        MIi_CpuCopy32(src, (void *) (0x7000000 + offset), size);
    }
}

void GXS_LoadOAM(const void *src, u32 offset, u32 size) {
    if (data_0216f074[0] != -1 && size > 0x30) {
        MI_DmaCopy32(data_0216f074[0], src, (void *) (0x7000400 + offset), size);
    } else {
        MIi_CpuCopy32(src, (void *) (0x7000400 + offset), size);
    }
}

void GX_LoadOBJ(const void *src, u32 offset, u32 size) {
    enum { K0 } base = 0x6400000;

    if (data_0216f074[0] != -1 && size > 0x30) {
        MI_DmaCopy32(data_0216f074[0], src, (void *) (base + offset), size);
    } else {
        MIi_CpuCopy32(src, (void *) (base + offset), size);
    }
}

void GXS_LoadOBJ(const void *src, u32 offset, u32 size) {
    enum { K0 } base = 0x6600000;

    if (data_0216f074[0] != -1 && size > 0x30) {
        MI_DmaCopy32(data_0216f074[0], src, (void *) (base + offset), size);
    } else {
        MIi_CpuCopy32(src, (void *) (base + offset), size);
    }
}

void GX_LoadBG0Scr(const void *src, u32 offset, u32 size) {
    u32 ptr = G2Bg0CntBits8To12Address();
    if (data_0216f074[0] != -1 && size > 0x1c) {
        MI_DmaCopy16(data_0216f074[0], src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy16(src, (void *) (ptr + offset), size);
    }
}

void GXS_LoadBG0Scr(const void *src, u32 offset, u32 size) {
    u32 ptr = G2sBg0CntBits8To12Address();
    if (data_0216f074[0] != -1 && size > 0x1c) {
        MI_DmaCopy16(data_0216f074[0], src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy16(src, (void *) (ptr + offset), size);
    }
}

void GX_LoadBG1Scr(const void *src, u32 offset, u32 size) {
    u32 ptr = G2Bg1CntBits8To12Address();
    if (data_0216f074[0] != -1 && size > 0x1c) {
        MI_DmaCopy16(data_0216f074[0], src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy16(src, (void *) (ptr + offset), size);
    }
}

void GXS_LoadBG1Scr(const void *src, u32 offset, u32 size) {
    u32 ptr = G2sBg1CntBits8To12Address();
    if (data_0216f074[0] != -1 && size > 0x1c) {
        MI_DmaCopy16(data_0216f074[0], src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy16(src, (void *) (ptr + offset), size);
    }
}

void GX_LoadBG2Scr(const void *src, u32 offset, u32 size) {
    u32 ptr = G2Bg2CntBits8To12Address();
    if (data_0216f074[0] != -1 && size > 0x1c) {
        MI_DmaCopy16(data_0216f074[0], src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy16(src, (void *) (ptr + offset), size);
    }
}

void GXS_LoadBG2Scr(const void *src, u32 offset, u32 size) {
    u32 ptr = G2sBg2CntBits8To12Address();
    if (data_0216f074[0] != -1 && size > 0x1c) {
        MI_DmaCopy16(data_0216f074[0], src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy16(src, (void *) (ptr + offset), size);
    }
}

void GX_LoadBG3Scr(const void *src, u32 offset, u32 size) {
    u32 ptr = G2Bg3CntBits8To12Address();
    if (data_0216f074[0] != -1 && size > 0x1c) {
        MI_DmaCopy16(data_0216f074[0], src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy16(src, (void *) (ptr + offset), size);
    }
}

void GXS_LoadBG3Scr(const void *src, u32 offset, u32 size) {
    u32 ptr = G2sBg3CntBits8To12Address();
    if (data_0216f074[0] != -1 && size > 0x1c) {
        MI_DmaCopy16(data_0216f074[0], src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy16(src, (void *) (ptr + offset), size);
    }
}

void GX_LoadBG0Char(const void *src, u32 offset, u32 size) {
    u32 ptr = G2Bg0CntBits2To5Address();
    if (data_0216f074[0] != -1 && size > 0x30) {
        MI_DmaCopy32(data_0216f074[0], src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy32(src, (void *) (ptr + offset), size);
    }
}

void GXS_LoadBG0Char(const void *src, u32 offset, u32 size) {
    u32 ptr = G2sBg0CntBits2To5Address();
    if (data_0216f074[0] != -1 && size > 0x30) {
        MI_DmaCopy32(data_0216f074[0], src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy32(src, (void *) (ptr + offset), size);
    }
}

void GX_LoadBG1Char(const void *src, u32 offset, u32 size) {
    u32 ptr = G2Bg1CntBits2To5Address();
    if (data_0216f074[0] != -1 && size > 0x30) {
        MI_DmaCopy32(data_0216f074[0], src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy32(src, (void *) (ptr + offset), size);
    }
}

void GXS_LoadBG1Char(const void *src, u32 offset, u32 size) {
    u32 ptr = G2sBg1CntBits2To5Address();
    if (data_0216f074[0] != -1 && size > 0x30) {
        MI_DmaCopy32(data_0216f074[0], src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy32(src, (void *) (ptr + offset), size);
    }
}

void GX_LoadBG2Char(const void *src, u32 offset, u32 size) {
    u32 ptr = G2Bg2CntBits2To5Address();
    if (data_0216f074[0] != -1 && size > 0x30) {
        MI_DmaCopy32(data_0216f074[0], src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy32(src, (void *) (ptr + offset), size);
    }
}

void GXS_LoadBG2Char(const void *src, u32 offset, u32 size) {
    u32 ptr = G2sBg2CntBits2To5Address();
    if (data_0216f074[0] != -1 && size > 0x30) {
        MI_DmaCopy32(data_0216f074[0], src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy32(src, (void *) (ptr + offset), size);
    }
}

void GX_LoadBG3Char(const void *src, u32 offset, u32 size) {
    u32 ptr = G2Bg3CntBits2To5Address();
    if (data_0216f074[0] != -1 && size > 0x30) {
        MI_DmaCopy32(data_0216f074[0], src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy32(src, (void *) (ptr + offset), size);
    }
}

void GXS_LoadBG3Char(const void *src, u32 offset, u32 size) {
    u32 ptr = G2sBg3CntBits2To5Address();
    if (data_0216f074[0] != -1 && size > 0x30) {
        MI_DmaCopy32(data_0216f074[0], src, (void *) (ptr + offset), size);
    } else {
        MIi_CpuCopy32(src, (void *) (ptr + offset), size);
    }
}
