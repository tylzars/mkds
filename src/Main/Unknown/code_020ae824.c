#include "Main/Unknown/code_020ae824.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020b33d8.h"
#include "Main/Unknown/code_020b3724.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b9994.h"
#include "Main/Unknown/code_020bb5ec.h"
#include "Main/Unknown/code_020bc11c.h"
#include "Main/Unknown/code_020be950.h"
#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c2118.h"
#include "Main/Unknown/code_020c3e44.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02022030.h"
#include "Main/Unknown/code_020c476c.h"
#include "Main/Unknown/code_020c53c4.h"
#include "Main/Unknown/code_020c5e30.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020cffd0.h"
#include "Main/Unknown/code_020d1158.h"
#include "Main/Unknown/code_020d12e0.h"
#include "Main/Unknown/code_020d1298.h"
#include "Main/Unknown/code_020d18d4.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_0200eddc.h"
#include "code_0214c778.h"

void func_020ae824(void) {
    u32 v;
    s32 a;

    v = data_021759c0->mUnk_00c;
    if (v == 3) {
        func_020c4ae8();
        return;
    }
    if (v == 5) {
        return;
    }
    if (v == 6) {
        DrawEndingStaffRoll();
        return;
    }
    if (gRaceHud->mEnabled == FALSE) {
        return;
    }
    func_020b3410();
    func_020b3724();
    gRaceHud->mUnk_404 = 0;
    gRaceHud->mUnk_406 = 0;
    if (data_021759c0->mUnk_00c == 4) {
        func_020d1198((Unk020d029c *) gRaceHud->mUnk_004);
    }
    v = data_021759c0->mMode;
    if ((v == 2   ? gRaceProgress->mRaceDone
         : v == 4 ? func_0203c174()
                  : (IsKartEnded(func_020b4d9c()) != 0 && gRaceHud->mUnk_8dc == 0)) == 0) {
        func_020ba63c((Unk020d029c *) gRaceHud->mUnk_004);
        func_020bc208((Unk020d029c *) gRaceHud->mUnk_004);
        DrawRaceMNumberPair((Unk020d029c *) gRaceHud->mUnk_004);
        func_020d06b8((Unk020d029c *) gRaceHud->mUnk_004);
        func_020c4f08((Unk020c06c4 *) gRaceHud->mUnk_004);
        func_020b9dfc((Unk020d029c *) gRaceHud->mUnk_004);
        func_020c5804((Unk020c06c4 *) gRaceHud->mUnk_004);
    } else {
        func_020d06b8((Unk020d029c *) gRaceHud->mUnk_004);
        func_020c4f08((Unk020c06c4 *) gRaceHud->mUnk_004);
        func_020c5804((Unk020c06c4 *) gRaceHud->mUnk_004);
    }
    func_0200ee74(gRaceHud->mUnk_004, 0x400);
    func_0214cc04(3, gRaceHud->mUnk_004 + gRaceHud->mUnk_404 * 8, 0xc0, (0x80 - gRaceHud->mUnk_404) << 3);
    gRaceHud->mUnk_808 = 0;
    gRaceHud->mUnk_80a = 0;
    a = gRaceHud->mSubScreenState;
    if (a != 4 && a != 5) {
        func_020bb5ec((Unk020d029c *) gRaceHud->mUnk_408);
    }
    func_020be2f4((Unk020d029c *) gRaceHud->mUnk_408);
    func_0200ee74(gRaceHud->mUnk_408, 0x400);
    func_0214cc04(3, gRaceHud->mUnk_408 + gRaceHud->mUnk_808 * 8, 0xc0, (0x80 - gRaceHud->mUnk_808) << 3);
    switch (gRaceHud->mSubScreenState) {
        case 0:
            func_020be950(gRaceHud->mUnk_408);
            break;
        case 1:
        case 2:
        case 3:
            func_020be950(gRaceHud->mUnk_408);
            func_020c3e44((Unk020c06c4 *) gRaceHud->mUnk_408);
            break;
        case 4:
        case 5:
            func_020c2118((Unk020c06c4 *) gRaceHud->mUnk_408);
            break;
        case 6:
            DrawRaceNewRecordTa((Unk020c06c4 *) gRaceHud->mUnk_408);
            break;
    }
}
