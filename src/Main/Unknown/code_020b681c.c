#include "Main/Unknown/code_020b681c.h"
#include "Main/Unknown/unk_021759c0.h"

void GetRaceHudSubScreenBg3MinMax(UnkPair020b502c *outMin, UnkPair020b502c *outMax) {
    int courseId;
    courseId = RaceHudSubScreenGetCurrentCourseId();
    if (courseId == COURSE_ID_OLD_LUIGI_GC) {
        SetFixed12MinMaxFromWhole(outMin, outMax, 0xfffff434u, 0xfffffff6, 0x00000ba4u, 0x00001766u);
        return;
    }
    if (courseId == COURSE_ID_MANSION) {
        SetFixed12MinMaxFromWhole(outMin, outMax, 0xfffff7c0, 0xfffffc18, 0xf30, 0x00001388u);
        return;
    }
    if (courseId == COURSE_ID_CROSS) {
        SetFixed12MinMaxFromWhole(outMin, outMax, 0, 0xfffff446u, 0x00001770u, 0x00000bb6u);
        return;
    }
    if (courseId == COURSE_ID_TOWN) {
        SetFixed12MinMaxFromWhole(outMin, outMax, 0xffffff42, 0xfffff132u, 0x000018a6u, 0x00000a96u);
        return;
    }
    if (courseId == COURSE_ID_SNOW) {
        SetFixed12MinMaxFromWhole(outMin, outMax, 0xfffff7c2u, 0xffffffec, 0x00000f32u, 0x0000175cu);
        return;
    }
    if (courseId == COURSE_ID_PINBALL) {
        SetFixed12MinMaxFromWhole(outMin, outMax, 0xfffff443u, 0xffffffe2, 0x00000bb3u, 0x00001752u);
        return;
    }
    if (courseId == COURSE_ID_OLD_KINOKO_GC) {
        SetFixed12MinMaxFromWhole(outMin, outMax, 0xfffffff6, 0xfffff434u, 0x00001766u, 0x00000ba4u);
        return;
    }
    GetRaceHudSubScreenCourseMinMax(outMin, outMax);
}
