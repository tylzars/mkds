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

void DrawEarthenPipe(u32 unused0, Unk020e43a8 *pipe, u32 unused1, u16 d) {
    MtxFx43 *matrix;
    if (pipe->mUnk_00.mStateMachine.mState == 0) {
        matrix = func_020e6cbc(&pipe->mUnk_00.mPos);
        func_020e67c4(gEarthenPipe1, matrix, &pipe->mUnk_00.mScale, 0, d);
        return;
    }
    func_020e6a18(gEarthenPipe2);
    matrix = func_020e6cbc(&pipe->mUnk_00.mPos);
    func_020e66e4(gEarthenPipe2, matrix, *(u16 *) &pipe->mUnk_a0.mUnk_0c.x, &pipe->mUnk_00.mScale, 0, d);
    func_020e6a18(gEarthenPipe1);
}

void func_020de4d4(u32 unused, u32 object) {
    u32 stateMachineAddress;
    u32 objectCopy = object;
    u32 unused12;
    stateMachineAddress = (objectCopy) + (0x80u);
    AdvanceStateMachine((void *) stateMachineAddress);
}

u8 func_020de4a0(Unk020e43a8 *pipe, void *kart, u8 *c, u8 *d) {
    if (func_020ec450(pipe, kart, c) != FALSE) {
        StartSoundIfKartStarOrKiller(&pipe->mUnk_00, kart);
    }
    return *d;
}

u8 func_020de488(Unk020e43a8 *pipe, void *kart, u8 *c, u8 *d) {
    func_020ec41c(pipe, kart, c);
    return *d;
}

#pragma thumb on

void CreateEarthenPipe1AndEarthenPipe2(void) {
    void *nsbmdFile;
    nsbmdFile = FindCourseMapObjFile(gEarthenPipe1NsbmdName);
    func_020e6488((Unk020e6488 **) (((u32 *) &gEarthenPipe1)), nsbmdFile, 0, 0);
    nsbmdFile = FindCourseMapObjFile(gEarthenPipe2NsbmdName);
    func_020e6488((Unk020e6488 **) (((u32 *) &gEarthenPipe2)), nsbmdFile, 0, 0);
    func_020e6ab8(gEarthenPipe1);
    func_020e6ab8(gEarthenPipe2);
}

#pragma thumb off
