#pragma avoid_byte all

#include "code_02135014.h"
#include "code_02134890.h"
#include "code_02134d30.h"
#include "code_021352e0.h"
#include "code_0213c94c.h"
#include "code_0200e77c.h"
#include "Main/Unknown/unk_0216e000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/unk_0217e000.h"

void *FormatPutFwrite(void *a, const char *b, u32 n) {
    if (n != fwrite(b, 1, n, a)) {
        a = 0;
    }
    return a;
}

void *FormatPutBuffer(void *p, const char *b, u32 n) {
    FormatPutTarget *a = p;

    if (a->mWrittenCount + n > a->mSize) {
        n = a->mSize - a->mWrittenCount;
    }
    memcpy(a->mBuffer + a->mWrittenCount, b, n);
    a->mWrittenCount += n;
    return (void *) 1;
}

int printf(const char *fmt, ...) {
    int r;

    if (fwide(&data_0216eb7c[1], -1) >= 0) {
        return -1;
    }
    if (func_0200ec08(data_0217eadc[3]) == 0) {
        data_0217ea94[3] = data_0216ff5c.mUnk_08->mUnk_6c;
        data_0217eab8[3] = 1;
    } else if (data_0217ea94[3] == data_0216ff5c.mUnk_08->mUnk_6c) {
        data_0217eab8[3]++;
    } else {
        func_0200ed34(data_0217eadc[3]);
        data_0217ea94[3] = data_0216ff5c.mUnk_08->mUnk_6c;
        data_0217eab8[3] = 1;
    }
    r = FormatWithPutFunc(FormatPutFwrite, &data_0216eb7c[1], fmt, (char *) (((int) &fmt & ~3) + 4));
    data_0217eab8[3]--;
    if (data_0217eab8[3] == 0) {
        func_0200ecc4(data_0217eadc[3]);
    }
    return r;
}

int vsnprintf(char *buf, u32 n, const char *fmt, char *va) {
    FormatPutTarget st;
    int r;

    st.mBuffer = buf;
    st.mSize = n;
    st.mWrittenCount = 0;
    r = FormatWithPutFunc(FormatPutBuffer, &st, fmt, va);
    if (buf == 0) {
        return r;
    }
    if (r < n) {
        buf[r] = 0;
    } else if (n != 0) {
        *(buf + n - 1) = 0;
    }
    return r;
}

int snprintf(char *buf, u32 n, const char *fmt, ...) {
    return vsnprintf(buf, n, fmt, (char *) (((int) &fmt & ~3) + 4));
}

int sprintf(char *buf, const char *fmt, ...) {
    return vsnprintf(buf, -1, fmt, (char *) (((int) &fmt & ~3) + 4));
}
