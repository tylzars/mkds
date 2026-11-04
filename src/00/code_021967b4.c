#include "00/code_02190cd4.h"
#include "00/code_021967b4.h"
#include "00/unk_021b3000.h"
#include "code_02134398.h"
#include "code_02139f70.h"
#include "code_0213a460.h"

void func_ov000_0219690c(GpConnection *a, const char *b, ...) {}

BOOL GpiReadError(GpConnection *a, const char *b, s32 c) {
    GpiConnection *r;
    BOOL t;
    char d[0x10];

    r = a->mGpiConnection;
    if (strncmp(b, data_ov000_021b3aec, 7) == 0) {
        if (GpiGetValue(b, data_ov000_021b3af4, d, 0x10) != FALSE) {
            r->mErrorNumber = StrtolBase10(d);
        }
        if (GpiGetValue(b, data_ov000_021b3afc, r->mErrorMessage, 0x100) == FALSE) {
            r->mErrorMessage[0] = 0;
        }
        if (c != 0) {
            t = (strstr(b, data_ov000_021b3b08) != NULL);
            GpiQueueErrorCallback(a, 4, (t != FALSE) ? 1 : 0);
        }
        return TRUE;
    }
    return FALSE;
}

BOOL GpiGetValue(const char *command, const char *key, char *value, s32 len) {
    const char *p;
    const char *q;
    s32 i;
    s8 f;
    s8 g;

    if (command == NULL) {
        AssertionFailed(data_ov000_021b3ad4, data_ov000_021b3a1c, NULL, 0x10d);
    }
    if (key == NULL) {
        AssertionFailed(data_ov000_021b3a2c, data_ov000_021b3a1c, NULL, 0x10e);
    }
    if (value == NULL) {
        AssertionFailed(data_ov000_021b3a38, data_ov000_021b3a1c, NULL, 0x10f);
    }
    if (len <= 0) {
        AssertionFailed(data_ov000_021b3ae4, data_ov000_021b3a1c, NULL, 0x110);
    }
    f = (s8) *key;
    p = strstr(command, key);
    if (p == NULL) {
        return FALSE;
    }
    q = p + strlen(key);
    for (i = 0; i < len - 1 && (g = (s8) q[i]) != 0 && g != f; i++) {
        value[i] = g;
    }
    value[i] = 0;
    return TRUE;
}
