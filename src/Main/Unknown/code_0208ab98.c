#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_020b502c.h"

void *func_0208adc8(void *a, u32 b) {
    Unk0208ab98 *p = a;
    u16 i;
    u16 v;

    for (i = 0; i < 4; i++) {
        if (b & (1 << i)) {
            break;
        }
    }
    v = gCourseMap->mUnk_018->mUnk_18[i];
    p->mUnk_00 = v;
    p->mUnk_0e = 1 << i;
    p->mUnk_02 = p->mUnk_00 & 0x1f;
    p->mUnk_04 = (p->mUnk_00 >> 5) & 0x1f;
    p->mUnk_06 = (p->mUnk_00 >> 10) & 0x1f;
    p->mUnk_08 = 0;
    p->mUnk_0a = 0;
    p->mUnk_0c = 0;
    p->mUnk_10 = 0x1000;
    return a;
}

void func_0208ad74(void *a, u32 b) {
    Unk0208ab98 *p = a;
    u16 i;

    for (i = 0; i < 4; i++) {
        if (b & (1 << i)) {
            break;
        }
    }
    p->mUnk_00 = gCourseMap->mUnk_018->mUnk_18[i];
    p->mUnk_0e = 1 << i;
}

void func_0208ab98(void *a, u16 b, s32 c) {
    Unk0208ab98 *p = a;
    u16 m = ~p->mUnk_0e & b;
    u16 i;
    u16 v;
    s32 n;

    if (m != 0) {
        for (i = 0; i < 4; i++) {
            if (m & (1 << i)) {
                break;
            }
        }
        v = gCourseMap->mUnk_018->mUnk_18[i];
        p->mUnk_02 = p->mUnk_00 & 0x1f;
        p->mUnk_08 = (s16) (v & 0x1f) - p->mUnk_02;
        p->mUnk_04 = (p->mUnk_00 >> 5) & 0x1f;
        p->mUnk_0a = (s16) ((v >> 5) & 0x1f) - p->mUnk_04;
        p->mUnk_06 = (p->mUnk_00 >> 10) & 0x1f;
        p->mUnk_0c = (s16) ((v >> 10) & 0x1f) - p->mUnk_06;
        p->mUnk_10 = 0;
        p->mUnk_0e = 1 << i;
    }
    if (p->mUnk_10 == 0x1000) {
        return;
    }
    p->mUnk_10 = p->mUnk_10 + ((s32) (((s64) c * 0xa4 + 0x800) >> 12) + 0x29);
    if (p->mUnk_10 >= 0x1000) {
        p->mUnk_10 = 0x1000;
    }
    p->mUnk_00 = (s16) (p->mUnk_02 + (s32) (((s64) p->mUnk_08 * p->mUnk_10 + 0x800) >> 12)) +
                 ((s16) (p->mUnk_04 + (s32) (((s64) p->mUnk_0a * p->mUnk_10 + 0x800) >> 12)) << 5) +
                 ((s16) (p->mUnk_06 + (s32) (((s64) p->mUnk_0c * p->mUnk_10 + 0x800) >> 12)) << 10);
}
