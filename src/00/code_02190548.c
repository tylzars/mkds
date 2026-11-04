#include "00/code_02190548.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_0218d818.h"
#include "00/code_0218e2dc.h"
#include "00/code_021965a0.h"
#include "00/code_02190ff8.h"
#include "00/code_02196000.h"
#include "code_02135014.h"
#include "00/code_021906e4.h"
#include "00/code_021967b4.h"
#include "00/unk_021b23b0.h"
#include "code_02134d30.h"
#include "code_0213a460.h"

u32 func_ov000_02190618(GpConnection *a, GpiBuffer *b, s32 *c, s32 *d, s32 *e) {
    char f[0x10];
    u8 *p;
    s32 n;
    s32 m;
    *c = 0;
    if (b->mLength < 5) {
        return 0;
    }
    p = (u8 *) strchr((const char *) b->mBuffer, 10);
    if (p != NULL) {
        if (strncmp((const char *) (p - 5), data_ov000_021b287c, 5) != 0) {
            return 3;
        }
        *p = 0;
        if (GpiGetValue((const char *) b->mBuffer, data_ov000_021b2884, f, 0x10) == 0) {
            return 3;
        }
        *d = func_0213bf90(f);
        if (GpiGetValue((const char *) b->mBuffer, data_ov000_021b2888, f, 0x10) == 0) {
            return 3;
        }
        n = func_0213bf90(f);
        m = n + 1;
        if (b->mLength > m + (p - b->mBuffer)) {
            if (*(s8 *) (p + m) != 0) {
                return 3;
            }
            *c = (s32) (p + 1);
            *e = n;
            b->mPos = m + (p - b->mBuffer) + 1;
        } else {
            *p = 10;
        }
    }
    return 0;
}

u32 func_ov000_021905d4(GpConnection *a, GpiBuffer *b) {
    s32 n;
    if (b == NULL || b->mBuffer == NULL || (n = b->mPos) == 0) {
        return 0;
    }
    b->mLength = b->mLength - n;
    if (b->mLength != 0) {
        memmove(b->mBuffer, b->mBuffer + b->mPos, b->mLength);
    }
    b->mBuffer[b->mLength] = 0;
    b->mPos = 0;
    return 0;
}

u32 func_ov000_02190548(GpConnection *a, GpiProfile *b) {
    GpiConnection *o;
    o = a->mGpiConnection;
    GpiAppendBufferString(a, &o->mOutputBuffer, data_ov000_021b2858);
    GpiAppendBufferString(a, &o->mOutputBuffer, data_ov000_021b275c);
    GpiAppendBufferNumber(a, &o->mOutputBuffer, o->mSesskey);
    GpiAppendBufferString(a, &o->mOutputBuffer, data_ov000_021b2864);
    GpiAppendBufferNumber(a, &o->mOutputBuffer, b->mProfileId);
    GpiAppendBufferString(a, &o->mOutputBuffer, data_ov000_021b2874);
    GpiAppendBufferString(a, &o->mOutputBuffer, b->mUnk_10);
    GpiAppendBufferString(a, &o->mOutputBuffer, data_ov000_021b2778);
    return 0;
}
