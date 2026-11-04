#pragma avoid_byte all

#include "code_0213c9f8.h"
#include "code_0213c9e8.h"
#include "code_0213cae0.h"

void *FormatPutWideBuffer(void *p, const u16 *s, u32 n) {
    FormatPutWideTarget *a = p;
    void *r;

    if (a->mWrittenCount + n > a->mSize) {
        n = a->mSize - a->mWrittenCount;
    }
    r = wmemcpy(a->mBuffer + a->mWrittenCount, s, n);
    a->mWrittenCount += n;
    return r;
}

int swprintf(u16 *buf, u32 n, const u16 *fmt, ...) {
    return vswprintf(buf, n, fmt, (char *) (((int) &fmt & ~3) + 4));
}

int vswprintf(u16 *buf, u32 n, const u16 *fmt, char *va) {
    FormatPutWideTarget st;
    int r;

    st.mBuffer = buf;
    st.mSize = n;
    st.mWrittenCount = 0;
    r = FormatWideWithPutFunc(FormatPutWideBuffer, &st, fmt, va);
    if (r < 0) {
        return r;
    }
    if (r < n) {
        buf[r] = 0;
    } else {
        *(buf + n - 1) = 0;
        return -1;
    }
    return r;
}
