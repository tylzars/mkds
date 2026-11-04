#pragma once

#include "types.h"
#include "00/code_0218f960.h"
#include "00/unk_021b4000.h"
#include "00/code_021965a0.h"

u32 GpiSendBuffer(GpConnection *a, s32 sock, GpiBuffer *outputBuffer, u32 *d, s32 e, const s8 *f);
u32 GpiReceiveBuffer(GpConnection *a, s32 sock, GpiBuffer *inputBuffer, s32 *bytesRead, u32 *connClosed, const s8 *f);
u32 GpiPeerSendString(GpConnection *p0, Unk02190988 *p1, const char *p2);
u32 GpiPeerSendBytes(GpConnection *a, Unk02190988 *b, const char *c, s32 d);
u32 GpiPeerSendByte(GpConnection *a, Unk02190988 *b, s8 c);
u32 GpiSendBytes(GpConnection *a, s32 b, const void *c, s32 d, s32 *e, s32 *f, const s8 *g);
u32 GpiAppendBufferNumber(void *a, void *b, u32 c);
u32 GpiAppendBufferString(void *p0, void *p1, const void *p2);
u32 GpiAppendBufferBytes(void *a, GpiBuffer *outputBuffer, const void *string, s32 stringLen);
u32 GpiAppendBufferByte(void *a, GpiBuffer *outputBuffer, s32 c);
