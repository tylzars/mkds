#include "00/code_0218a9bc.h"
#include "00/code_0218b280.h"
#include "00/code_0218aea4.h"
#include "00/code_0218cd74.h"
#include "00/code_0218d000.h"
#include "00/code_0218dd8c.h"
#include "code_02134398.h"
#include "code_02139f70.h"
#include "code_0213a460.h"

void SbServerSetValue(SbServer *e, const char *v1, const char *v2) {
    char *a[2];
    a[0] = func_ov000_0218d134(NULL, v1);
    a[1] = func_ov000_0218d134(NULL, v2);
    HashtableSet(e->mKeyValues, a);
}

void SbServerSetInt(SbServer *e, const char *v1, u32 c) {
    char a[20];
    sprintf(a, data_ov000_021b21e4, c);
    SbServerSetValue(e, v1, a);
}

char *SbServerGetValue(SbServer *server, const char *v1, char *d) {
    Unk0218b30c a;
    u32 *b;
    if (server == NULL) {
        AssertionFailed(data_ov000_021b21d0, data_ov000_021b21d8, NULL, 0x97);
    }
    if (server == NULL) {
        return NULL;
    }
    a.mUnk_00 = v1;
    b = HashtableFind(server->mKeyValues, &a);
    if (b != NULL) {
        d = (char *) b[1];
    }
    return d;
}

s32 SbServerGetInt(SbServer *e, const char *v1, s32 d) {
    char *a;
    s32 c;
    if (strcmp(v1, data_ov000_021b21c8) == 0) {
        return func_ov000_0218af9c(e);
    }
    a = SbServerGetValue(e, v1, NULL);
    if (a == NULL || (c = *a, !((c < 0 || c >= 0x80) ? 0 : (data_0215d284[c] & 8)))) {
        return d;
    }
    return StrtolBase10(a);
}

double SbServerGetDouble(SbServer *e, const char *v1, double d) {
    char *a;
    a = SbServerGetValue(e, v1, NULL);
    if (a != NULL) {
        d = atof(a);
    }
    return d;
}
