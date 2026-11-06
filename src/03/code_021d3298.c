#include "03/code_021d3298.h"
#include "03/unk_021da000.h"
#include "code_0214d018.h"
#include "code_0214f4a4.h"
#include "code_02148950.h"
#include "registers.h"

void func_ov003_021d3408(void) {
    data_ov003_021da2f8[0] = GX_DisableBankForBG();
    data_ov003_021da2f8[1] = GX_DisableBankForOBJ();
    data_ov003_021da2f8[2] = GX_DisableBankForBGExtPltt();
    data_ov003_021da2f8[3] = GX_DisableBankForOBJExtPltt();
    data_ov003_021da2f8[4] = GX_DisableBankForTex();
    data_ov003_021da2f8[5] = GX_DisableBankForTexPltt();
    data_ov003_021da2f8[6] = GX_DisableBankForClearImage();
    data_ov003_021da2f8[7] = GX_DisableBankForSubBG();
    data_ov003_021da2f8[8] = GX_DisableBankForSubOBJ();
    data_ov003_021da2f8[9] = GX_DisableBankForSubBGExtPltt();
    data_ov003_021da2f8[10] = GX_DisableBankForSubOBJExtPltt();
    data_ov003_021da2f8[11] = GX_DisableBankForARM7();
    data_ov003_021da2f8[12] = GX_DisableBankForLCDC();
    GX_SetBankForARM7(data_ov003_021da2f8[11]);
    func_ov003_021d3298();
}

void func_ov003_021d332c(void) {
    GX_DisableBankForBG();
    GX_DisableBankForOBJ();
    GX_DisableBankForSubBG();
    GX_DisableBankForSubOBJ();
    func_ov003_021d3298();
    GX_SetBankForBG(data_ov003_021da2f8[0]);
    GX_SetBankForOBJ(data_ov003_021da2f8[1]);
    GX_SetBankForBGExtPltt(data_ov003_021da2f8[2]);
    GX_SetBankForOBJExtPltt(data_ov003_021da2f8[3]);
    GX_SetBankForTex(data_ov003_021da2f8[4]);
    GX_SetBankForTexPltt(data_ov003_021da2f8[5]);
    GX_SetBankForClearImage(data_ov003_021da2f8[6]);
    GX_SetBankForSubBG(data_ov003_021da2f8[7]);
    GX_SetBankForSubOBJ(data_ov003_021da2f8[8]);
    GX_SetBankForSubBGExtPltt(data_ov003_021da2f8[9]);
    GX_SetBankForSubOBJExtPltt(data_ov003_021da2f8[10]);
    GX_SetBankForLCDC(data_ov003_021da2f8[12]);
    reg_G2_BLDCNT = 0;
    reg_G2S_DB_BLDCNT = 0;
    reg_G2_BG0OFS = 0;
    reg_G2_BG1OFS = 0;
    reg_G2_BG2OFS = 0;
    reg_G2_BG3OFS = 0;
    reg_G2S_DB_BG0OFS = 0;
    reg_G2S_DB_BG1OFS = 0;
    reg_G2S_DB_BG2OFS = 0;
    reg_G2S_DB_BG3OFS = 0;
    PM_SetLCDPower(1);
}

void func_ov003_021d3298(void) {
    vu32 c;
    vu32 e;
    vu32 a;
    vu32 b;
    vu32 d;
    vu32 f;

    GX_SetBankForLCDC(0x1f3);
    a = 0;
    MIi_CpuClearFast(a, (void *) 0x6800000, 0x40000);
    b = 0;
    MIi_CpuClearFast(b, (void *) 0x6880000, 0x24000);
    GX_DisableBankForLCDC();
    c = 0x200;
    MIi_CpuClearFast(c, (void *) 0x7000000, 0x400);
    d = 0;
    MIi_CpuClearFast(d, (void *) 0x5000000, 0x400);
    e = 0x200;
    MIi_CpuClearFast(e, (void *) 0x7000400, 0x400);
    f = 0;
    MIi_CpuClearFast(f, (void *) 0x5000400, 0x400);
}
