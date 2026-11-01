#pragma avoid_byte all

#include "code_0213c9f8.h"
#include "code_0213c9e8.h"
#include "code_0213cae0.h"

void *func_0213ca94(void *p, const u16 *s, u32 n) {
    Unk0213c9f8 *a = p;
    void *r;

    if (a->mUnk_08 + n > a->mUnk_04) {
        n = a->mUnk_04 - a->mUnk_08;
    }
    r = func_0213c9e8(a->mUnk_00 + a->mUnk_08, s, n);
    a->mUnk_08 += n;
    return r;
}

int func_0213ca64(u16 *buf, u32 n, const u16 *fmt, ...) {
    return func_0213c9f8(buf, n, fmt, (char *) (((int) &fmt & ~3) + 4));
}

int func_0213c9f8(u16 *buf, u32 n, const u16 *fmt, char *va) {
    Unk0213c9f8 st;
    int r;

    st.mUnk_00 = buf;
    st.mUnk_04 = n;
    st.mUnk_08 = 0;
    r = func_0213cae0(func_0213ca94, &st, fmt, va);
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
