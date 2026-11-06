#include "00/code_02196594.h"

#include "00/code_02190cd4.h"
#include "00/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/code_0218e8d4.h"
#include "00/code_02196000.h"
#include "00/code_021965a0.h"
#include "code_02134398.h"
#include "00/unk_021b3000.h"
#include "code_02139f70.h"
#include "code_0213a460.h"

void GpiCopyString(char *dest, const char *src, s32 c) {
    if (dest == NULL) {
        AssertionFailed(data_ov000_021b3b10, data_ov000_021b3a1c, NULL, 0x2f);
    }
    if (src == NULL) {
        AssertionFailed(data_ov000_021b3b20, data_ov000_021b3a1c, NULL, 0x30);
    }
    strncpy(dest, src, c);
    *(dest + c + -1) = 0;
}

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
    f = *key;
    p = strstr(command, key);
    if (p == NULL) {
        return FALSE;
    }
    q = p + strlen(key);
    for (i = 0; i < len - 1 && (g = q[i]) != 0 && g != f; i++) {
        value[i] = g;
    }
    value[i] = 0;
    return TRUE;
}

u32 GpiCheckConnectComplete(GpConnection *a, u32 b, u32 *c) {
    int v1;
    int v2;
    int v3[2];
    v2 = 0;
    v3[0] = 0;
    v1 = func_ov000_0218e68c((u32) b, NULL, (u32 *) (&v2), (u32 *) v3);
    if (v1 == -1) {
        func_ov000_0219690c(a, data_ov000_021b3a58);
        GpiSetError(a, 5, data_ov000_021b3a6c);
        GpiQueueErrorCallback(a, 3, 1);
        return 3;
    }
    if (0 < v1) {
        if (v3[0] != 0) {
            func_ov000_0219690c(a, data_ov000_021b3aa4);
            *c = 4;
            return 0;
        }
        if (v2 != 0) {
            func_ov000_0219690c(a, data_ov000_021b3abc);
            *c = 3;
            return 0;
        }
    }
    *c = 0;
    return 0;
}

s32 GpiReadKeyValue(GpConnection *a, s8 *buffer, s32 *c, s8 *key, s8 *value) {
    s8 *p;
    s8 f;
    s32 i;

    if (buffer == NULL) {
        AssertionFailed(data_ov000_021b3a0c, data_ov000_021b3a1c, NULL, 0x199);
    }
    if (key == NULL) {
        AssertionFailed(data_ov000_021b3a2c, data_ov000_021b3a1c, NULL, 0x19a);
    }
    if (value == NULL) {
        AssertionFailed(data_ov000_021b3a38, data_ov000_021b3a1c, NULL, 0x19b);
    }
    p = buffer + *c;
    if (*p != 0x5c) {
        GpiSetError(a, 1, data_ov000_021b3a48);
        GpiQueueErrorCallback(a, 3, 1);
        return 3;
    }
    i = 0;
    buffer = p + 2;
    f = p[1];
    if (f != 0x5c) {
        do {
            if (f == 0) {
                GpiSetError(a, 1, data_ov000_021b3a48);
                GpiQueueErrorCallback(a, 3, 1);
                return 3;
            }
            if (i == 0x1ff) {
                GpiSetError(a, 1, data_ov000_021b3a48);
                GpiQueueErrorCallback(a, 3, 1);
                return 3;
            }
            *key = f;
            key++;
            i++;
            f = *buffer;
            buffer++;
        } while (f != 0x5c);
    }
    *key = 0;
    i = 0;
    while ((f = *buffer++) != 0x5c && f != 0) {
        if (i == 0x1ff) {
            GpiSetError(a, 1, data_ov000_021b3a48);
            GpiQueueErrorCallback(a, 3, 1);
            return 3;
        }
        *value = f;
        value++;
        i++;
    }
    *value = 0;
    *c = *c + ((buffer - p) - 1);
    return 0;
}
