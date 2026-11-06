#include "01/code_021a41c8.h"
#include "01/code_02184f7c.h"
#include "Main/Unknown/code_020aa81c.h"
#include "Main/Unknown/unk_0217d068.h"
#include "01/code_02180ce8.h"
#include "01/code_021a4724.h"
#include "01/code_021a5140.h"
#include "01/code_02181000.h"
#include "01/code_02184000.h"
#include "01/code_02185000.h"
#include "01/code_021a4000.h"
#include "01/code_021a5000.h"
#include "01/code_021a6000.h"
#include "Main/Unknown/code_020ac000.h"
#include "code_0212df7c.h"

void func_ov001_021a41c8(s32 a, s32 b) {
    s32 n;
    u8 *p;
    u16 buf[16];

    switch (gEmblem->mUnk_1090) {
        case 0:
            switch (a) {
                case 0x1b:
                case 0x1c:
                case 0x1d:
                case 0x1e:
                case 0x1f:
                case 0x20:
                case 0x21:
                case 0x22:
                case 0x23:
                case 0x24:
                case 0x25:
                case 0x26:
                case 0x27:
                case 0x28:
                case 0x29:
                    if (b) {
                        func_ov001_02184fb4(func_ov001_02185160(gEmblem->mEmblemSLld, 9), 0);
                        func_ov001_02184fb4(func_ov001_02185160(gEmblem->mEmblemSLld, 10), 0x1000);
                        gEmblem->mUnk_1080 = a - 0x1b;
                        func_ov001_021a63c0((u8) (gEmblem->mUnk_1080 + 1));
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1f1);
                    } else {
                        gEmblem->mUnk_1080 = a - 0x1b;
                        func_ov001_021a5df0((gEmblem->mEmblemSLld), (s32) (a));
                        func_ov001_021a63c0((u8) (gEmblem->mUnk_1080 + 1));
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1f0);
                    }
                    if (func_ov001_021a639c() == 1) {
                        func_ov001_021a5ab0(gEmblem->mEmblemSLld, (s32) (func_ov001_021a637c() + 0xe));
                        func_ov001_021a63a8(0);
                    }
                    gEmblem->mUnk_1094 = 3;
                    return;
                case 0x2a:
                    if (b) {
                        func_ov001_02184fb4(func_ov001_02185160(gEmblem->mEmblemSLld, 10), 0x1000);
                    }
                    func_ov001_021a59cc((gEmblem->mEmblemSLld), (s32) (a));
                    if (b) {
                        gEmblem->mUnk_1094 = 3;
                        return;
                    }
                    break;
                case 0xe:
                case 0xf:
                case 0x10:
                    func_ov001_021a5ab0((gEmblem->mEmblemSLld), (s32) (a));
                    func_ov001_021a63a8(0);
                    func_ov001_021a6388((s32) (a - 0xe));
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1f2);
                    gEmblem->mUnk_1094 = 3;
                    return;
                case 0x11:
                case 0x12:
                case 0x13:
                    func_ov001_021a5ab0((gEmblem->mEmblemSLld), (s32) (a));
                    func_ov001_021a63a8(1);
                    func_ov001_021a6388((s32) (a - 0x11));
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1f2);
                    gEmblem->mUnk_1094 = 3;
                    return;
                case 0x14:
                    func_ov001_021a5ab0((gEmblem->mEmblemSLld), (s32) (a));
                    func_ov001_021a63a8(2);
                    func_ov001_021a6388(0);
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1f2);
                    gEmblem->mUnk_1094 = 3;
                    return;
                case 0x15:
                    func_ov001_021a5ab0((gEmblem->mEmblemSLld), (s32) (a));
                    func_ov001_021a63a8(3);
                    func_ov001_021a6388(0);
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1f2);
                    gEmblem->mUnk_1094 = 3;
                    return;
                case 0x16:
                    if (gEmblem->mUnk_108c == NULL) {
                        gEmblem->mUnk_108c = func_ov001_021a4a10;
                        func_ov001_021a5d00((gEmblem->mEmblemSLld), (s32) (a));
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1f3);
                        gEmblem->mUnk_10b0 = TRUE;
                    }
                    gEmblem->mUnk_1094 = 3;
                    return;
                case 0x17:
                    if (func_ov001_02181070()) {
                        if (func_ov001_0218108c()) {
                            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1fb);
                        } else {
                            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1fc);
                        }
                        func_ov001_02181098();
                        func_ov001_021a5d00((gEmblem->mEmblemSLld), (s32) (a));
                    }
                    if (b) {
                        gEmblem->mUnk_1094 = 3;
                        return;
                    }
                    break;
                case 0x19:
                    if (gEmblem->mUnk_108c == NULL) {
                        gEmblem->mUnk_108c = func_ov001_021a4878;
                        func_ov001_021a5d00((gEmblem->mEmblemSLld), (s32) (a));
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0xc);
                        gEmblem->mUnk_10b0 = TRUE;
                        gEmblem->mUnk_10ac = FALSE;
                    }
                    gEmblem->mUnk_1094 = 3;
                    return;
                case 0x1a:
                    if (gEmblem->mUnk_108c == NULL) {
                        gEmblem->mUnk_108c = func_ov001_021a4b28;
                        func_ov001_021a5c28((gEmblem->mEmblemSLld), (s32) (a));
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 4);
                        gEmblem->mUnk_10b0 = TRUE;
                    }
                    gEmblem->mUnk_1094 = 3;
                    return;
            }
            break;
        case 1:
            switch (a) {
                case 0:
                    if (gEmblem->mUnk_108c == NULL) {
                        gEmblem->mUnk_108c = func_ov001_021a4914;
                        func_ov001_021a5a40((gEmblem->mEmblemTemplateSLld), 1);
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0xe);
                        gEmblem->mUnk_10b0 = TRUE;
                    }
                    gEmblem->mUnk_1094 = 3;
                    return;
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 0xa:
                case 0xb:
                case 0xc:
                case 0xd:
                case 0xe:
                case 0xf:
                case 0x10:
                case 0x11:
                case 0x12:
                case 0x13:
                case 0x14:
                case 0x15:
                case 0x16:
                case 0x17:
                case 0x18:
                case 0x19:
                case 0x1a:
                case 0x1b:
                case 0x1c:
                case 0x1d:
                case 0x1e:
                case 0x1f:
                    if (gEmblem->mUnk_108c == NULL) {
                        n = (s32) (func_ov001_02181268() * func_ov001_02181268()) / 2;
                        p = (u8 *) gEmblem->mEmblemTemplateBNcgr->mData + (a - 3) * n;
                        buf[0] = 0;
                        buf[1] = (func_ov001_021a63b4() == 1) ? 2 : 1;
                        buf[2] = func_ov001_021a63b4();
                        SplitBytesIntoNibbles(p, gEmblem->mUnk_0c7c, func_ov001_02181268());
                        func_ov001_021810bc((gEmblem->mUnk_0c7c), (buf));
                        func_ov001_0218107c();
                        gEmblem->mUnk_108c = func_ov001_021a4914;
                        func_ov001_021a5d00((gEmblem->mEmblemTemplateSLld), (s32) (a));
                        gEmblem->mUnk_1084 = a - 3;
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1f6);
                    }
                    gEmblem->mUnk_1094 = 3;
                    return;
            }
            break;
        case 4:
            if (a == 1) {
                if (gEmblem->mUnk_108c == NULL) {
                    gEmblem->mUnk_108c = func_ov001_021a4844;
                    func_ov001_021a5d00((gEmblem->mEmblemCameraSLld), (s32) (a));
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0xc);
                    gEmblem->mUnk_10ac = TRUE;
                }
                gEmblem->mUnk_1094 = 3;
            }
            break;
    }
}
