#include "Main/Unknown/code_020a8a6c.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020a8ed8.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02147cd8.h"

void func_020a8a6c(Unk020a8a6c *a) {
    s32 i;
    Unk020a826c *p;
    CourseMapRow *q;
    s32 x1;
    s32 y1;
    s32 z1;
    s32 x2;
    s32 y2;
    s32 z2;
    s32 x3;
    s32 y3;
    s32 z3;
    s32 x4;
    s32 y4;
    s32 z4;
    s32 x5;
    s32 y5;
    s32 z5;
    s32 v1;

    if (a == NULL) {
        return;
    }
    for (i = 0; i < a->mUnk_04 && (p = a->mUnk_00[i]) != NULL; i++) {
        if (GetRaceUseChainCameras() != 0) {
            switch (gRaceSetup->mCourseId) {
                case COURSE_ID_CROSS:
                    p->mUnk_0f0 = 4;
                    q = p->mUnk_000.mCourseMapRow;
                    z1 = q->mUnk_00.z + (-0x4a6000);
                    y1 = q->mUnk_00.y;
                    x1 = q->mUnk_00.x + (-0x2c6000);
                    p->mUnk_0a0.mUnk_00.mSoundId = 0x103;
                    p->mUnk_0a0.mUnk_00.mUnk_08 = 5;
                    p->mUnk_0a0.mUnk_00.mPositionSource = &p->mUnk_0a0.mUnk_10;
                    p->mUnk_0a0.mUnk_1c = GetSndHandleSlot(8);
                    p->mUnk_0a0.mUnk_10.x = x1;
                    p->mUnk_0a0.mUnk_10.y = y1;
                    p->mUnk_0a0.mUnk_10.z = z1;
                    q = p->mUnk_000.mCourseMapRow;
                    z2 = q->mUnk_00.z + 0x726000;
                    y2 = q->mUnk_00.y;
                    x2 = q->mUnk_00.x + (-0x7ee000);
                    p->mUnk_0c8.mUnk_00.mSoundId = 0x103;
                    p->mUnk_0c8.mUnk_00.mUnk_08 = 5;
                    p->mUnk_0c8.mUnk_00.mPositionSource = &p->mUnk_0c8.mUnk_10;
                    p->mUnk_0c8.mUnk_1c = GetSndHandleSlot(9);
                    p->mUnk_0c8.mUnk_10.x = x2;
                    p->mUnk_0c8.mUnk_10.y = y2;
                    p->mUnk_0c8.mUnk_10.z = z2;
                    break;
                case COURSE_ID_BANK:
                    p->mUnk_0f0 = 5;
                    q = p->mUnk_000.mCourseMapRow;
                    z3 = q->mUnk_00.z;
                    y3 = q->mUnk_00.y;
                    x3 = q->mUnk_00.x;
                    p->mUnk_0a0.mUnk_00.mSoundId = 0x109;
                    p->mUnk_0a0.mUnk_00.mUnk_08 = 4;
                    p->mUnk_0a0.mUnk_00.mPositionSource = &p->mUnk_0a0.mUnk_10;
                    if (i == 0) {
                        v1 = 8;
                    } else if (i == 1) {
                        v1 = 9;
                    } else {
                        v1 = 10;
                    }
                    p->mUnk_0a0.mUnk_1c = GetSndHandleSlot(v1);
                    p->mUnk_0a0.mUnk_10.x = x3;
                    p->mUnk_0a0.mUnk_10.y = y3;
                    p->mUnk_0a0.mUnk_10.z = z3;
                    VEC_MultAdd(((s64) p->mUnk_000.mScale.z * 0x5000) >> 12, &p->mUnk_000.mMatrix.mUnk_00[2],
                                &p->mUnk_0a0.mUnk_10, &p->mUnk_0a0.mUnk_10);
                    break;
                default:
                    if ((p->mUnk_000.mFlags & 0x100) == 0) {
                        ParkMapObject(&p->mUnk_000);
                    }
                    break;
            }
        } else {
            switch (gRaceSetup->mCourseId) {
                case COURSE_ID_CROSS:
                    p->mUnk_0f0 = 1;
                    p->mUnk_0a0.mUnk_00.mSoundId = 0x108;
                    p->mUnk_0a0.mUnk_00.mUnk_08 = 8;
                    p->mUnk_0a0.mUnk_00.mPositionSource = &p->mUnk_0a0.mUnk_10;
                    p->mUnk_0a0.mUnk_1c = GetSndHandleSlot(8);
                    p->mUnk_0a0.mUnk_10.x = 0;
                    p->mUnk_0a0.mUnk_10.y = 0;
                    p->mUnk_0a0.mUnk_10.z = 0;
                    p->mUnk_0c8.mUnk_00.mSoundId = 0x107;
                    p->mUnk_0c8.mUnk_00.mUnk_08 = 8;
                    p->mUnk_0c8.mUnk_00.mPositionSource = &p->mUnk_0c8.mUnk_10;
                    p->mUnk_0c8.mUnk_1c = GetSndHandleSlot(9);
                    p->mUnk_0c8.mUnk_10.x = 0;
                    p->mUnk_0c8.mUnk_10.y = 0;
                    p->mUnk_0c8.mUnk_10.z = 0;
                    func_020a8ed8(&p->mUnk_0a0, &p->mUnk_000.mPos);
                    break;
                case COURSE_ID_MARIO:
                    p->mUnk_0f0 = 1;
                    p->mUnk_0a0.mUnk_00.mSoundId = 0x1a0;
                    p->mUnk_0a0.mUnk_00.mUnk_08 = 8;
                    p->mUnk_0a0.mUnk_00.mPositionSource = &p->mUnk_0a0.mUnk_10;
                    p->mUnk_0a0.mUnk_1c = GetSndHandleSlot(8);
                    p->mUnk_0a0.mUnk_10.x = 0;
                    p->mUnk_0a0.mUnk_10.y = 0;
                    p->mUnk_0a0.mUnk_10.z = 0;
                    p->mUnk_0c8.mUnk_00.mSoundId = 0x19f;
                    p->mUnk_0c8.mUnk_00.mUnk_08 = 8;
                    p->mUnk_0c8.mUnk_00.mPositionSource = &p->mUnk_0c8.mUnk_10;
                    p->mUnk_0c8.mUnk_1c = GetSndHandleSlot(9);
                    p->mUnk_0c8.mUnk_10.x = 0;
                    p->mUnk_0c8.mUnk_10.y = 0;
                    p->mUnk_0c8.mUnk_10.z = 0;
                    func_020a8ed8(&p->mUnk_0a0, &p->mUnk_000.mPos);
                    break;
                case COURSE_ID_BANK:
                    p->mUnk_0f0 = 6;
                    q = p->mUnk_000.mCourseMapRow;
                    z4 = q->mUnk_00.z;
                    y4 = q->mUnk_00.y;
                    x4 = q->mUnk_00.x;
                    p->mUnk_0a0.mUnk_00.mSoundId = 0x109;
                    p->mUnk_0a0.mUnk_00.mUnk_08 = 6;
                    p->mUnk_0a0.mUnk_00.mPositionSource = &p->mUnk_0a0.mUnk_10;
                    p->mUnk_0a0.mUnk_1c = GetSndHandleSlot(8);
                    p->mUnk_0a0.mUnk_10.x = x4;
                    p->mUnk_0a0.mUnk_10.y = y4;
                    p->mUnk_0a0.mUnk_10.z = z4;
                    VEC_MultAdd(((s64) p->mUnk_000.mScale.z * 0x5000) >> 12, &p->mUnk_000.mMatrix.mUnk_00[2],
                                &p->mUnk_0a0.mUnk_10, &p->mUnk_0a0.mUnk_10);
                    q = p->mUnk_000.mCourseMapRow;
                    z5 = q->mUnk_00.z;
                    y5 = q->mUnk_00.y;
                    x5 = q->mUnk_00.x;
                    p->mUnk_0c8.mUnk_00.mSoundId = 0x109;
                    p->mUnk_0c8.mUnk_00.mUnk_08 = 6;
                    p->mUnk_0c8.mUnk_00.mPositionSource = &p->mUnk_0c8.mUnk_10;
                    p->mUnk_0c8.mUnk_1c = GetSndHandleSlot(9);
                    p->mUnk_0c8.mUnk_10.x = x5;
                    p->mUnk_0c8.mUnk_10.y = y5;
                    p->mUnk_0c8.mUnk_10.z = z5;
                    VEC_MultAdd(((s64) p->mUnk_000.mScale.z * -0x5000) >> 12, &p->mUnk_000.mMatrix.mUnk_00[2],
                                &p->mUnk_0c8.mUnk_10, &p->mUnk_0c8.mUnk_10);
                    break;
                default:
                    if ((p->mUnk_000.mFlags & 0x100) == 0) {
                        ParkMapObject(&p->mUnk_000);
                    }
                    break;
            }
        }
    }
}
