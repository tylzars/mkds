#include "Main/Unknown/code_020de438.h"
#include "Main/Unknown/code_020467d0.h"

#include "Main/Unknown/code_020de488.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020ec1fc.h"
#include "Main/Unknown/code_020de4d4.h"
#include "Main/Unknown/code_020de4e4.h"
#include "Main/Unknown/unk_0216b000.h"

void func_020de4e4(u32 a, Unk020e43a8 *b, u32 c, u16 d) {
    Unk02012f58 *v1;
    if (b->mUnk_00.mUnk_80.mState == 0) {
        v1 = func_020e6cbc(&b->mUnk_00.mPos);
        func_020e67c4(gEarthenPipe1, v1, &b->mUnk_00.mScale, 0, d);
        return;
    }
    func_020e6a18(gEarthenPipe2);
    v1 = func_020e6cbc(&b->mUnk_00.mPos);
    func_020e66e4(gEarthenPipe2, v1, *(u16 *) &b->mUnk_a0.mUnk_0c.x, &b->mUnk_00.mScale, 0, d);
    func_020e6a18(gEarthenPipe1);
}

void func_020de4d4(u32 arg0, u32 arg1) {
    u32 value0;
    u32 value1 = arg1;
    u32 value12;
    value0 = (value1) + (0x80u);
    func_02046b40((void *) value0);
}

u8 func_020de4a0(Unk020e43a8 *a, void *b, u8 *c, u8 *d) {
    if (func_020ec450(a, b, c) != FALSE) {
        func_020d26f8(&a->mUnk_00, b);
    }
    return *d;
}

u8 func_020de488(Unk020e43a8 *a, void *b, u8 *c, u8 *d) {
    func_020ec41c(a, b, c);
    return *d;
}

#pragma thumb on

void CreateEarthenPipe1AndEarthenPipe2(void) {
    void *v1;
    v1 = FindCourseMapObjFile(gEarthenPipe1NsbmdName);
    func_020e6488((Unk020e6488 **) (((u32 *) &gEarthenPipe1)), v1, (u32) 0, (u32) 0);
    v1 = FindCourseMapObjFile(gEarthenPipe2NsbmdName);
    func_020e6488((Unk020e6488 **) (((u32 *) &gEarthenPipe2)), v1, (u32) 0, (u32) 0);
    func_020e6ab8(gEarthenPipe1);
    func_020e6ab8(gEarthenPipe2);
}

#pragma thumb off
