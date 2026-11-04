#include "00/code_02190ba0.h"
#include "00/code_021967b4.h"
#include "00/unk_021b3000.h"
#include "code_0213442c.h"
#include "code_02139f70.h"
#include "code_0213a460.h"

void func_ov000_0219690c(GpConnection *a, const char *b, ...) {}

BOOL func_ov000_02196870(GpConnection *a, const char *b, s32 c) {
    GpiConnection *r;
    BOOL t;
    char d[0x10];

    r = a->mGpiConnection;
    if (strncmp(b, data_ov000_021b3aec, 7) == 0) {
        if (func_ov000_021967b4(b, data_ov000_021b3af4, d, 0x10) != FALSE) {
            r->mErrorNumber = func_0213bf90(d);
        }
        if (func_ov000_021967b4(b, data_ov000_021b3afc, r->mErrorMessage, 0x100) == FALSE) {
            r->mErrorMessage[0] = 0;
        }
        if (c != 0) {
            t = (strstr(b, data_ov000_021b3b08) != NULL);
            func_ov000_02190f4c(a, 4, (t != FALSE) ? 1 : 0);
        }
        return TRUE;
    }
    return FALSE;
}

BOOL func_ov000_021967b4(const char *a, const char *b, char *c, s32 d) {
    const char *p;
    const char *q;
    s32 i;
    s8 f;
    s8 g;

    if (a == NULL) {
        func_0213442c(data_ov000_021b3ad4, data_ov000_021b3a1c, NULL, 0x10d);
    }
    if (b == NULL) {
        func_0213442c(data_ov000_021b3a2c, data_ov000_021b3a1c, NULL, 0x10e);
    }
    if (c == NULL) {
        func_0213442c(data_ov000_021b3a38, data_ov000_021b3a1c, NULL, 0x10f);
    }
    if (d <= 0) {
        func_0213442c(data_ov000_021b3ae4, data_ov000_021b3a1c, NULL, 0x110);
    }
    f = (s8) *b;
    p = strstr(a, b);
    if (p == NULL) {
        return FALSE;
    }
    q = p + strlen(b);
    for (i = 0; i < d - 1 && (g = (s8) q[i]) != 0 && g != f; i++) {
        c[i] = g;
    }
    c[i] = 0;
    return TRUE;
}
