#include "code_020207ec.h"
#include "code_02020eb0.h"
#include "code_02021764.h"

void SND_StopSeq(u32 a) {
    PxiCommandEnqueue(1, a, 0, 0, 0);
}

void SND_PrepareSeq(u32 a, u32 b, u32 c, u32 d) {
    PxiCommandEnqueue(2, a, b, c, d);
}

void SND_StartPreparedSeq(u32 a) {
    PxiCommandEnqueue(3, a, 0, 0, 0);
}

void SND_SetPlayerTempoRatio(u32 a, u32 b) {
    SendPlayerFieldCommand(a, 0x1a, b, 2);
}

void SND_SetPlayerVolume(u32 a, u32 b) {
    SendPlayerFieldCommand(a, 6, b, 2);
}

void SND_SetPlayerChannelPriority(u32 a, u32 b) {
    SendPlayerFieldCommand(a, 4, b, 1);
}

void SND_SetPlayerLocalVariable(u32 a, u32 b, u32 c) {
    PxiCommandEnqueue(0xa, a, b, c, 0);
}

void SND_SetTrackVolume(u32 a, u32 b, u32 c) {
    SendTrackFieldCommand(a, b, 0xa, c, 2);
}

void SND_SetTrackPitch(u32 a, u32 b, u32 c) {
    SendTrackFieldCommand(a, b, 0xc, c, 2);
}

void SND_SetTrackPan(u32 a, u32 b, u32 c) {
    SendTrackFieldCommand(a, b, 9, c, 1);
}

void SND_SetTrackModSpeed(u32 a, u32 b, u32 c) {
    SendTrackFieldCommand(a, b, 0x19, c, 1);
}

void SND_SetTrackAllocatableChannel(u32 a, u32 b, u32 c) {
    PxiCommandEnqueue(9, a, b, c, 0);
}

void SND_StartTimer(u32 a, u32 b, u32 c, u32 d) {
    PxiCommandEnqueue(0xc, a, b, c, d);
}

void SND_StopTimer(u32 a, u32 b, u32 c, u32 d) {
    int i;
    u32 m;

    m = c;
    for (i = 0; i < 8 && m != 0; i++, m >>= 1) {
        if (m & 1) {
            func_02021764(i);
        }
    }
    PxiCommandEnqueue(0xd, a, b, c, d);
}

void SND_SetupCapture(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    PxiCommandEnqueue(0x11, c, d, (a << 31) | (b << 30) | (e << 29) | (f << 28) | (g << 27), 0);
}

void SND_SetupAlarm(s32 a, u32 b, u32 c, UnkFunc *d, void *e) {
    u32 t;

    t = PxiCommandCallbackSet(a, d, e);
    PxiCommandEnqueue(0x12, a, b, c, t);
}

void SND_SetTrackMuteEx(u32 a, u32 b, u32 c) {
    PxiCommandEnqueue(8, a, b, c, 0);
}

void SND_LockChannel(u32 a, u32 b) {
    PxiCommandEnqueue(0x1a, a, b, 0, 0);
}

void SND_UnlockChannel(u32 a, u32 b) {
    PxiCommandEnqueue(0x1b, a, b, 0, 0);
}

void SND_SetChannelVolume(u32 a, u32 b, u32 c) {
    PxiCommandEnqueue(0x14, a, b, c, 0);
}

void SND_SetupChannelPcm(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j) {
    PxiCommandEnqueue(0xe, a | (i << 16), c, (g << 24) | (h << 22) | f, (d << 26) | (b << 24) | (j << 16) | e);
}

void SND_InvalidateSeqData(void *a, void *b) {
    PxiCommandEnqueue(0x1e, (u32) a, (u32) b, 0, 0);
}

void SND_InvalidateBankData(void *a, void *b) {
    PxiCommandEnqueue(0x1f, (u32) a, (u32) b, 0, 0);
}

void SND_InvalidateWaveData(void *a, void *b) {
    PxiCommandEnqueue(0x20, (u32) a, (u32) b, 0, 0);
}

void SND_SetMasterVolume(u32 a) {
    PxiCommandEnqueue(0x17, a, 0, 0, 0);
}

void SND_SetOutputSelector(u32 a, u32 b, u32 c, u32 d) {
    PxiCommandEnqueue(0x19, a, b, c, d);
}

void SND_SetMasterPan(u32 a) {
    PxiCommandEnqueue(0x18, a, 0, 0, 0);
}

void SND_ResetMasterPan(void) {
    PxiCommandEnqueue(0x18, 0xffffffff, 0, 0, 0);
}

void SendPlayerFieldCommand(u32 a, u32 b, u32 c, u32 d) {
    PxiCommandEnqueue(6, a, b, c, d);
}

void SendTrackFieldCommand(u32 a, u32 b, u32 c, u32 d, u32 e) {
    PxiCommandEnqueue(7, a | (e << 24), b, c, d);
}

void func_02020844(u32 a) {
    PxiCommandEnqueue(0x16, a, 0, 0, 0);
}

void PxiCommandEnqueue(u32 a, u32 b, u32 c, u32 d, u32 e) {
    PxiCommand *p;

    p = PxiCommandAlloc(1);
    if (p == 0) {
        return;
    }
    p->mUnk_04 = a;
    p->mUnk_08 = b;
    p->mUnk_0c = c;
    p->mUnk_10 = d;
    p->mUnk_14 = e;
    PxiCommandPendingAppend(p);
}
