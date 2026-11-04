#include "01/code_021a2408.h"
#include "01/code_02180ce8.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/code_020ca9e4.h"
#include "Main/Unknown/code_021108ac.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/code_0214a000.h"
#include "code_0200eddc.h"
#include "code_021488e8.h"
#include "code_0214a390.h"
#include "code_0214b824.h"
#include "01/code_021a4724.h"
#include "01/code_021a5140.h"
#include "01/code_021a4000.h"
#include "01/code_021a59cc.h"
#include "01/code_021a6000.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/code_020ca000.h"
#include "Main/Unknown/unk_0217a000.h"

void func_ov001_021a2408(void) {
    u16 *src;
    u16 *dst;
    u32 bits;

    if ((data_0217aa08->mUnk_28 == 0 ? (data_021759d4->mUnk_0c ? data_021759d4->mUnk_10 : 0) : 1) == 0) {
        func_02077c1c();
    }

    switch (gEmblem->mUnk_1098) {
        case 0:
            func_ov001_021a4fa0();
            func_ov001_021a4d10();
            gEmblem->mUnk_10b4++;
            if (gEmblem->mUnk_10b4 >= 2) {
                gEmblem->mUnk_1098 = 8;
            }
            break;
        case 2:
            bits = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
            *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & ~0x1f00) | ((bits | 1) << 8);
            *(vu16 *) 0x4001008 = (*(vu16 *) 0x4001008 & ~3) | 1;
            *(vu16 *) 0x4001008 = (*(vu16 *) 0x4001008 & 0x43) | 0x8a10;
            *(vu32 *) 0x4001010 = (-(gEmblem->mUnk_10a0 - 0xc0) << 16) & 0x1ff0000;
            *(vu32 *) 0x4001018 =
                ((gEmblem->mUnk_10a8 >> 12) & 0x1ff) | (((-gEmblem->mUnk_10a8 >> 12) << 16) & 0x1ff0000);
            gEmblem->mUnk_1098 = 4;
            break;
        case 6:
            *(vu32 *) 0x4001010 = (-(gEmblem->mUnk_10a0 - 0xc0) << 16) & 0x1ff0000;
            *(vu32 *) 0x4001018 =
                ((gEmblem->mUnk_10a8 >> 12) & 0x1ff) | (((-gEmblem->mUnk_10a8 >> 12) << 16) & 0x1ff0000);
            GxsDispCntBits0To2Write(1);
            *(vu16 *) 0x400100e = (*(vu16 *) 0x400100e & ~3) | 2;
            *(vu16 *) 0x400100e = (*(vu16 *) 0x400100e & 0x43) | 0x1218;
            func_0200ee74(gEmblem->mUnk_0a7c, 0x200);
            func_0214b95c((const void *) (gEmblem->mUnk_0a7c), 0, 0x200);
            func_0214a40c((u32 *) 0x4001050, 0, 0, 0x10, 0x10);
            gEmblem->mUnk_1098 = 4;
            break;
        case 4:
            *(vu32 *) 0x4001010 = (-(gEmblem->mUnk_10a0 - 0xc0) << 16) & 0x1ff0000;
            *(vu32 *) 0x4001018 =
                ((gEmblem->mUnk_10a8 >> 12) & 0x1ff) | (((-gEmblem->mUnk_10a8 >> 12) << 16) & 0x1ff0000);
            func_0200ee74((const void *) func_ov001_02181174(), func_ov001_02181180());
            func_0214b824((const void *) (func_ov001_02181174()), func_ov001_02181194(), func_ov001_02181180());
            func_0200ee74(gEmblem->mUnk_0a7c, 0x200);
            func_0214b95c((const void *) (gEmblem->mUnk_0a7c), 0, 0x200);
            src = gEmblem->mEmblemSBNclr->mData;
            dst = gEmblem->mEmblemSONclr->mData;
            dst[0x91] = src[func_ov001_021a63b4() == 1 ? 2 : 1];
            dst[0x92] = src[func_ov001_021a63b4()];
            func_0200ee74(gEmblem->mEmblemSONclr->mData, gEmblem->mEmblemSONclr->mDataSize);
            func_0214c028((const void *) gEmblem->mEmblemSONclr->mData, 0, gEmblem->mEmblemSONclr->mDataSize);
            break;
        case 3:
            *(vu32 *) 0x4001010 = (-(gEmblem->mUnk_10a0 - 0xc0) << 16) & 0x1ff0000;
            *(vu32 *) 0x4001018 =
                ((gEmblem->mUnk_10a8 >> 12) & 0x1ff) | (((-gEmblem->mUnk_10a8 >> 12) << 16) & 0x1ff0000);
            GxsDispCntBits0To2Write(0);
            *(vu16 *) 0x400100e = (*(vu16 *) 0x400100e & ~3) | 1;
            *(vu16 *) 0x400100e = (*(vu16 *) 0x400100e & 0x43) | 0x1010;
            *(vu32 *) 0x400101c = 0;
            func_0214a40c((u32 *) 0x4001050, 8, 0x36, 8, 8);
            gEmblem->mUnk_1098 = 5;
            break;
        case 7:
            bits = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
            *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & ~0x1f00) | ((bits & ~1) << 8);
            *(vu32 *) 0x4001018 =
                ((gEmblem->mUnk_10a8 >> 12) & 0x1ff) | (((-gEmblem->mUnk_10a8 >> 12) << 16) & 0x1ff0000);
            gEmblem->mUnk_1098 = 8;
            break;
        case 5:
            func_0200ee74(gEmblem->mUnk_0a7c, 0x200);
            func_0214b95c((const void *) (gEmblem->mUnk_0a7c), 0, 0x200);
            src = gEmblem->mEmblemSBNclr->mData;
            dst = gEmblem->mEmblemSONclr->mData;
            dst[0x91] = src[func_ov001_021a63b4() == 1 ? 2 : 1];
            dst[0x92] = src[func_ov001_021a63b4()];
            func_0200ee74(gEmblem->mEmblemSONclr->mData, gEmblem->mEmblemSONclr->mDataSize);
            func_0214c028((const void *) gEmblem->mEmblemSONclr->mData, 0, gEmblem->mEmblemSONclr->mDataSize);
            break;
        case 8:
            *(vu32 *) 0x4001018 =
                ((gEmblem->mUnk_10a8 >> 12) & 0x1ff) | (((-gEmblem->mUnk_10a8 >> 12) << 16) & 0x1ff0000);
            func_0200ee74((const void *) func_ov001_02181174(), func_ov001_02181180());
            func_0214b824((const void *) (func_ov001_02181174()), func_ov001_02181194(), func_ov001_02181180());
            func_0200ee74(gEmblem->mUnk_0a7c, 0x200);
            func_0214b95c((const void *) (gEmblem->mUnk_0a7c), 0, 0x200);
            src = gEmblem->mEmblemSBNclr->mData;
            dst = gEmblem->mEmblemSONclr->mData;
            dst[0x91] = src[func_ov001_021a63b4() == 1 ? 2 : 1];
            dst[0x92] = src[func_ov001_021a63b4()];
            func_0200ee74(gEmblem->mEmblemSONclr->mData, gEmblem->mEmblemSONclr->mDataSize);
            func_0214c028((const void *) gEmblem->mEmblemSONclr->mData, 0, gEmblem->mEmblemSONclr->mDataSize);
            break;
        case 12:
            func_0214a3e8((u16 *) 0x4001050, 0x3e, -16);
            func_ov001_021a4d10();
            gEmblem->mUnk_1098 = 13;
            break;
        case 9:
            func_0214a3e8((u16 *) 0x4001050, 0x3e, -16);
            func_ov001_021a4ba0();
            gEmblem->mUnk_1098 = 10;
            break;
        case 10:
            *(vu32 *) 0x4001018 = 0;
            func_0214a3e8((u16 *) 0x4001050, 0x3e, -gEmblem->mUnk_109c);
            break;
        case 13:
            *(vu32 *) 0x4001018 =
                ((gEmblem->mUnk_10a8 >> 12) & 0x1ff) | (((-gEmblem->mUnk_10a8 >> 12) << 16) & 0x1ff0000);
            func_0214a3e8((u16 *) 0x4001050, 0x3e, -gEmblem->mUnk_109c);
            break;
        case 14:
            func_ov001_021a4d10();
            *(vu32 *) 0x4001010 = 0;
            *(vu16 *) 0x4001008 = (*(vu16 *) 0x4001008 & ~3) | 1;
            *(vu16 *) 0x4001008 = (*(vu16 *) 0x4001008 & 0x43) | 0xa00;
            gEmblem->mUnk_1098 = 1;
            break;
        case 15:
            func_ov001_021a4d10();
            gEmblem->mUnk_1098 = 8;
            break;
    }

    if (gEmblem->mUnk_10b8 != 0) {
        if (func_ov001_021a639c() == 0) {
            if (func_ov001_021a637c() == 0) {
                func_021108ac(0);
            } else if (func_ov001_021a637c() == 1) {
                func_021108ac(1);
                gEmblem->mUnk_10bc = 1;
            } else if (func_ov001_021a637c() == 2) {
                func_021108ac(2);
                gEmblem->mUnk_10bc = 2;
            }
        } else if (func_ov001_021a639c() == 1) {
            if (func_ov001_021a637c() == 0) {
                func_021108ac(3);
            } else if (func_ov001_021a637c() == 1) {
                func_021108ac(4);
            } else if (func_ov001_021a637c() == 2) {
                func_021108ac(5);
            }
        }
        gEmblem->mUnk_10b8 = 0;
    }
    func_020ca9e4();
    func_020ae5f0(gEmblem->mUnk_0000, gEmblem->mUnk_0404);
}
