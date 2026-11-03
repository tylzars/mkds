#include "01/code_021882b8.h"
#include "01/code_0218d520.h"
#include "01/code_0218155c.h"
#include "01/code_02188e88.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a2f30.h"
#include "Main/Unknown/code_02100000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/unk_021759c0.h"
#include "01/code_0218c000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020a3000.h"
#include "Main/Unknown/code_020f9c6c.h"

void func_ov001_021882b8(void) {
    u16 i;
    Unk02188950 *obj;
    Unk0218d87c *table;

    if (!(data_021759c0->mUnk_08 == 4 ? func_020a1084((u16) data_021759c0->mUnk_62) : 0)) {
        for (i = data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : (u8) 0;
             i <= (data_021759c0->mUnk_08 == 4 ? func_ov001_02181b30() : (u16) 0); i++) {
            obj = data_021759c0->mUnk_08 == 4 ? func_ov001_02181b68(i) : 0;
            table = func_02100138(0x1ff);
            func_ov001_02188e88(obj);
            obj->mUnk_2c0 = 0;
            obj->mUnk_2b8 = 3;
            obj->mSpeed = obj->mUnk_178 = obj->mUnk_17c = 0;
            obj->mAngleState = 0;
            obj->mUnk_194 = obj->mUnk_198 = obj->mUnk_19c = 0;
            obj->mMoveAngleMode = 0;
            obj->mUnk_1b8 = obj->mUnk_1bc = obj->mUnk_1c0 = 0;
            obj->mVelocity.x = obj->mVelocity.y = obj->mVelocity.z = 0;
            obj->mUnk_168 = obj->mUnk_16c = 0x1f000;
            obj->mUnk_170 = 0;
            if (i - (data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) < table->mUnk_04) {
                obj->mUnk_000.mPos = table->mUnk_00[i - (data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)]
                                         ->mUnk_000.mCourseMapRow->mUnk_00;
                obj->mAngle =
                    (u16) (((s64) table->mUnk_00[i - (data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)]
                                    ->mUnk_000.mCourseMapRow->mUnk_0c.y *
                                0xb60b60b60bLL +
                            0x80000000000LL) >>
                           44);
            }
        }
    }
    func_020a305c();
}
