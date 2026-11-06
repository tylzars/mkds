#include "00/code_02185954.h"
#include "code_0200fc8c.h"
#include "00/unk_021b1000.h"
#include "code_02151868.h"
#include "code_021519d4.h"
#include "00/code_02186a9c.h"
#include "00/code_021acef8.h"
#include "00/code_021a6c08.h"
#include "00/code_0218a67c.h"
#include "00/code_021a6934.h"

#include "00/code_02181f98.h"
#include "code_0200e77c.h"
#include "00/code_021857b8.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "00/code_021ad734.h"
#include "03/code_021b94b8.h"
#include "00/code_02186d04.h"
#include "00/code_02188008.h"
#include "00/code_02187000.h"
#include "00/code_021a6000.h"
#include "code_0200d118.h"
#include "code_0200db4c.h"
#include "code_0200f5ac.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "code_0214d018.h"
#include "code_0214d93c.h"
#include "code_0200edc0.h"
#include "Main/Unknown/code_02151f88.h"

u32 func_ov000_02186a84(u32 value) {
    if (value & 0x8000) {
        value &= 0xffff7fff;
    }
    return value;
}

u32 InitHttpBuffer(Http *a, HttpBuffer *b, int c) {
    if (c == 0) {
        return 0;
    }
    b->mStart = a->mAllocate(gHttpBufferName, c);
    if (b->mStart == NULL) {
        return 0;
    }
    b->mCursor = b->mStart;
    b->mSize = c;
    b->mEnd = b->mStart + b->mSize;
    return 1;
}

void FreeHttpBuffer(Http *a, HttpBuffer *b) {
    if (b->mStart != NULL) {
        a->mFree(gHttpBufferName, b->mStart, 0);
    }
    MI_CpuFill8(b, 0, 0x10);
}

u32 GrowHttpBuffer(Http *a, HttpBuffer *b, int c) {
    char *v1;
    if (c <= 0) {
        return 0;
    }
    v1 = a->mAllocate(NULL, b->mSize + c);
    if (v1 == NULL) {
        return 0;
    }
    MI_CpuCopy8(b->mStart, v1, b->mSize);
    a->mFree(NULL, b->mStart, 0);
    if (v1 == NULL) {
        return 0;
    }
    b->mCursor = b->mCursor + (v1 - b->mStart);
    b->mSize = b->mSize + c;
    b->mStart = v1;
    b->mEnd = v1 + b->mSize;
    return 1;
}

BOOL DWCi_Http_SetHostinfo(Http *a, const char *b) {
    char *p;
    if (strlen(b) >= 0x80) {
        return FALSE;
    }
    strncpy(a->mUnk_028, b, 0x80);
    if (strlen(b) != strlen(a->mUnk_028)) {
        return FALSE;
    }
    p = strstr(a->mUnk_028, data_ov000_021b1268);
    if (p != NULL) {
        a->mHost = a->mUnk_028 + 7;
        a->mUseHttps = FALSE;
    } else {
        p = strstr(a->mUnk_028, data_ov000_021b1270);
        if (p == NULL) {
            return FALSE;
        }
        a->mHost = p + 8;
        a->mUseHttps = TRUE;
    }
    p = strstr(a->mHost, data_ov000_021b127c);
    if (p == NULL) {
        a->mPath = NULL;
    } else {
        *p = 0;
        a->mPath = p + 1;
    }
    return TRUE;
}

BOOL DWCi_Http_AddResult(DWCHttpParseResult *list, void *first, void *second) {
    if (list->mCount > list->mCapacity) {
        return FALSE;
    }
    list->mEntries[list->mCount].mFirst = first;
    list->mEntries[list->mCount].mSecond = second;
    list->mCount++;
    return TRUE;
}

// differ only by that register choice
BOOL DWC_Http_ParseResult(DWCHttpLabelValue *a, s32 b, s32 c, const char *d) {
    char *e;
    char *f;
    DWCHttpParseResult g;
    s8 *k;
    s8 *h;
    char *j;
    s8 *i;
    g.mEntries = a;
    g.mCapacity = b;
    g.mCount = 0;
    MI_CpuFill8(a, 0, b * 8);
    e = strstr(d, data_ov000_021b1230);
    if (e == NULL) {
        return FALSE;
    }
    f = e + 4 + strlen(e + 4);
    i = (s8 *) strstr(d, data_ov000_021b1238);
    if (i == NULL) {
        return FALSE;
    }
    k = i + 1;
    k[3] = 0;
    if (DWCi_Http_AddResult(&g, gHttpresultPairName, k) != TRUE) {
        return FALSE;
    }
    if (c == 1 || strncmp((const char *) k, data_ov000_021b1248, 3) != 0) {
        if (DWCi_Http_AddResult(&g, gHttpbodyPairName, e + 4) != TRUE) {
            return FALSE;
        }
        return TRUE;
    }
    i = (s8 *) strstr((const char *) (k + 4), data_ov000_021b1258);
    if (i == NULL) {
        return FALSE;
    }
    h = i + 2;
    while (h[0] != 0xd && h[1] != 0xa) {
        i = (s8 *) strstr((const char *) h, data_ov000_021b125c);
        if (i == NULL) {
            break;
        }
        i[0] = i[1] = 0;
        j = (char *) (i + 2);
        i = (s8 *) strstr(j, data_ov000_021b1258);
        if (i == NULL) {
            break;
        }
        i[0] = i[1] = 0;
        if (DWCi_Http_AddResult(&g, h, j) != TRUE) {
            return FALSE;
        }
        h = (s8 *) (j + strlen(j) + 2);
    }
    j = e + 4;
    if (j < f) {
        do {
            i = (s8 *) strstr(j, data_ov000_021b1260);
            if (i == NULL) {
                break;
            }
            i[0] = 0;
            h = i + 1;
            i = (s8 *) strstr((const char *) h, data_ov000_021b1264);
            if (i == NULL) {
                i = (s8 *) strstr((const char *) h, data_ov000_021b1258);
            }
            if (i != NULL) {
                i[0] = 0;
            }
            if (DWCi_Http_AddResult(&g, j, h) != TRUE) {
                return FALSE;
            }
            j = (char *) h + strlen((const char *) h) + 1;
        } while (j < f);
    }
    return TRUE;
}

void *DWC_Http_GetResult(DWCHttpLabelValue *a, s32 b, const char *c) {
    s32 e;
    for (e = 0; e < b; e++) {
        if (a[e].mFirst == NULL) {
            break;
        }
        if (strcmp(c, a[e].mFirst) == 0) {
            return a[e].mSecond;
        }
    }
    return NULL;
}

s32 DWC_Http_GetBase64DecodedResult(DWCHttpLabelValue *a, s32 b, const char *c, char *d, s32 e) {
    const char *f = DWC_Http_GetResult(a, b, c);
    u32 g;
    if (f == NULL) {
        return 0;
    }
    g = DWC_Auth_Base64Decode((const s8 *) f, strlen(f), (u8 *) d, e);
    if (g != -1 && g < e) {
        d[g] = 0;
    }
    return g;
}

BOOL DWC_Http_GetRawResult(DWCHttpLabelValue *a, s32 b, const char *c, char *d, s32 e) {
    const char *f = DWC_Http_GetResult(a, b, c);
    if (f == NULL) {
        return FALSE;
    }
    if ((s32) strlen(f) >= e) {
        return FALSE;
    }
    strcpy(d, f);
    return TRUE;
}

void func_ov000_02186628(const void *a) {
    data_ov000_021b1040.mUnk_00 = (char *) a;
    return;
}

s32 DWC_Auth_Create(Unk02186560 *a, Http *b) {
    void *c;
    if (gAuth != NULL) {
        return 2;
    }
    c = a->mAlloc(gAuthAllocName, 0x13e0);
    if (c == NULL) {
        return 2;
    }
    gAuth = c;
    MI_CpuFill8(c, 0, 0x13e0);
    gAuth->mHttp = b;
    MI_CpuFill8(&gAuth->mUnk_008, 0, 0x1c4);
    gAuth->mUnk_008 = -1;
    gAuth->mUnk_1cc = *a;
    gAuth->mUnk_1cc.mIngamesn[0x14] = 0;
    gAuth->mUnk_1cc.mGsbrcd[0xb] = 0;
    data_ov000_021b1040.mUnk_10 = a->mAlloc;
    data_ov000_021b1040.mUnk_14 = a->mFree;
    gAuth->mError = DWCi_Auth_Start(1);
    if (gAuth->mError == 0) {
        DWCi_Auth_StartThread();
        return 0;
    }
    return gAuth->mError;
}

void DWCi_Auth_StartThread(void) {
    OS_InitMutex(&gAuth->mMutex);
    gAuth->mAbort = FALSE;
    if (gAuth->mThread.mId == 0 || OS_IsThreadTerminated(&gAuth->mThread) != 0) {
        OS_CreateThread(&gAuth->mThread, DWCi_Auth_Thread, &gAuth, gAuth->mStack + 0x1000, 0x1000, 0x10);
        OS_WakeupThreadDirect(&gAuth->mThread);
    }
}

void DWC_Auth_Abort(void) {
    if (gAuth != NULL) {
        OS_LockMutex(&gAuth->mMutex);
        gAuth->mAbort = TRUE;
        OS_UnlockMutex(&gAuth->mMutex);
        if (gAuth->mHttp != NULL) {
            DWC_Http_Abort((Unk02186d7c *) gAuth->mHttp);
        }
        if (gAuth->mThread.mId != 0) {
            OS_JoinThread(&gAuth->mThread);
        }
    }
}

void DWC_Auth_Destroy(void) {
    if (gAuth != NULL) {
        if (gAuth->mHttp != NULL) {
            ReleaseHttp(gAuth->mHttp);
        }
        gAuth->mUnk_1cc.mFree(gAuthFreeName, gAuth, 0);
        gAuth = NULL;
    }
}

void DWC_Auth_Join(void) {
    if (gAuth->mThread.mId != 0) {
        OS_JoinThread(&gAuth->mThread);
    }
}

s32 DWC_Auth_GetError(void) {
    s32 a;
    if (gAuth == NULL) {
        return 0x15;
    }
    OS_LockMutex(&gAuth->mMutex);
    a = gAuth->mError;
    OS_UnlockMutex(&gAuth->mMutex);
    return a;
}

void func_ov000_0218635c(s32 *a) {
    s32 b;
    if (gAuth == NULL) {
        MI_CpuFill8(a, 0, 0x1c4);
    }
    MI_CpuCopy8(&gAuth->mUnk_008, a, 0x1c4);
    b = *a;
    if (b >= 0) {
        if (b < 0x4e20 || b >= 0x7530) {
            *a = -0x5206;
        }
    } else if (b > -0x4e20 || b <= -0x7530) {
        *a = -0x5206;
    }
}

s32 DWCi_Auth_Start(s32 a) {
    if (strcmp(data_ov000_021b1040.mUnk_00, data_ov000_021b1020) != 0) {
        data_ov000_021b1040.mUnk_18 = TRUE;
    }
    if (DWC_Http_Create((Unk02186d7c *) gAuth->mHttp, (const Unk021873d4 *) &data_ov000_021b1040) != 0) {
        return 4;
    }
    if (a == 1) {
        DWCi_BM_GetWiFiInfo((DWCWiFiInfo *) &data_ov000_021b4c94);
    }
    gAuth->mError = DWCi_Auth_Prepare_FirstPost(gAuth->mHttp, gAuth->mUnk_1cc.mGsbrcd, gAuth->mUnk_1cc.mIngamesn,
                                                gAuth->mHttpLabelvalue, 0x20, 0);
    if (gAuth->mError != 0) {
        return 4;
    }
    if (DWC_Http_FinishHeader((Unk02186d7c *) gAuth->mHttp) != 0) {
        return 4;
    }
    DWC_Http_StartThread((Unk02186d7c *) gAuth->mHttp);
    return 0;
}

void DWCi_Auth_Thread(void *param_1) {
    s32 a = 0;
    s32 b;
    BOOL c = FALSE;
    BOOL d = FALSE;
    BOOL e = FALSE;
    s32 f;
    u64 g;
    u64 h;
    DWCAuth *i;
    while (1) {
        i = gAuth;
        if (i->mHttp->mThread.mId != 0) {
            OS_JoinThread(&i->mHttp->mThread);
        }
        if (gAuth->mHttp->mResult != 8) {
            gAuth->mUnk_008 = -0x4e84;
            if (gAuth->mHttp->mResult == 7) {
                DWCi_Auth_SetError(0x13);
                return;
            }
            if (a > 2) {
                if (gAuth->mHttp->mResult == 2) {
                    DWCi_Auth_SetError(9);
                    return;
                }
                DWCi_Auth_SetError(0xc);
                return;
            }
            a++;
            b = 1;
        } else {
            f = func_ov000_02185ef4();
            switch (f) {
                case 0x14:
                    DWCi_Auth_SetError(0x14);
                    return;
                case 0xf:
                    if (a >= 2) {
                        DWCi_Auth_SetError(0xf);
                        gAuth->mUnk_008 = -gAuth->mUnk_008;
                        return;
                    }
                    a++;
                    b = c;
                    break;
                default:
                    if (a >= 2) {
                        gAuth->mUnk_008 = -gAuth->mUnk_008;
                        DWCi_Auth_SetError(f);
                        return;
                    }
                    a++;
                    b = 1;
                    break;
            }
        }
        g = OS_GetTick();
        h = ((OS_GetTick() - g) * 64) / 0x82ea;
        while (h < 5000) {
            OS_LockMutex(&gAuth->mMutex);
            if (gAuth->mAbort == TRUE) {
                gAuth->mUnk_008 = -0x4e84;
                OS_UnlockMutex(&gAuth->mMutex);
                DWCi_Auth_SetError(0x13);
                return;
            }
            OS_UnlockMutex(&gAuth->mMutex);
            OS_Sleep(5000);
            h = ((OS_GetTick() - g) * 64) / 0x82ea;
        }
        ReleaseHttp(gAuth->mHttp);
        OS_LockMutex(&gAuth->mMutex);
        gAuth->mError = DWCi_Auth_Start(b);
        if (gAuth->mError != 0) {
            gAuth->mUnk_008 = -0x4e84;
            OS_UnlockMutex(&gAuth->mMutex);
            return;
        }
        OS_UnlockMutex(&gAuth->mMutex);
    }
}

s32 func_ov000_02185ef4(void) {
    DWCAuth *a;
    const char *b;
    void *c;
    if (DWC_Http_ParseResult(gAuth->mHttpLabelvalue, 0x20, 0, gAuth->mHttp->mReceiveBuffer.mStart) != TRUE) {
        gAuth->mUnk_008 = 0x4e84;
        return 0xd;
    }
    if (DWCi_Auth_FillResult() != 0) {
        return 0xd;
    }
    a = gAuth;
    if (a->mUnk_008 < 0x4e84) {
        if (a->mUnk_008 == 0x4e22) {
            b = gBmworkName;
            c = a->mUnk_1cc.mAlloc(b, 0x71f);
            if (c == NULL) {
                gAuth->mUnk_008 = 0x4e84;
                return 2;
            }
            if (DWCi_AUTH_UpDateWiFiID((DWCWiFiInfo *) &data_ov000_021b4c94, (u8 *) (((u32) c + 0x1f) & ~0x1f)) != 1) {
                gAuth->mUnk_1cc.mFree(b, c, 0);
                gAuth->mUnk_008 = 0x4e84;
                return 0xe;
            }
            gAuth->mUnk_1cc.mFree(b, c, 0);
        }
        return 0x14;
    }
    switch (a->mUnk_008) {
        case 0x4e88:
            if (DWCi_AUTH_RemakeWiFiID((DWCWiFiInfo *) &data_ov000_021b4c94) == 0) {
                gAuth->mUnk_008 = 0x4e88;
                return 0xe;
            }
            gAuth->mUnk_008 = 0x4e88;
            return 0xf;
        case 0x4e8c:
            b = gBmworkName;
            c = a->mUnk_1cc.mAlloc(b, 0x71f);
            if (c == NULL) {
                gAuth->mUnk_008 = 0x4e8c;
                return 2;
            }
            if (func_02151f88(((u32) c + 0x1f) & ~0x1f) != 1) {
                gAuth->mUnk_1cc.mFree(b, c, 0);
                gAuth->mUnk_008 = 0x4e8c;
                return 0xe;
            }
            gAuth->mUnk_1cc.mFree(b, c, 0);
            gAuth->mUnk_008 = 0x4e8c;
            return 0x10;
    }
    return 0x11;
}

s32 DWCi_Auth_FillResult(void) {
    s32 b;
    const char *c;
    DWCAuth *d;
    c = NULL;
    b = StrtolBase10(DWC_Http_GetResult(gAuth->mHttpLabelvalue, 0x20, gHttpresultPairName2));
    if (gLibErrorCode == 0x22) {
        gAuth->mUnk_008 = 0x4e85;
        return 0xb;
    }
    if (b != 200) {
        gAuth->mUnk_008 = b + 0x59d8;
        return 0x11;
    }
    d = gAuth;
    if (DWC_Http_GetBase64DecodedResult(d->mHttpLabelvalue, 0x20, gReturncdPairName, d->mRetcode, 4) <= 0) {
        gAuth->mUnk_008 = 0x4e85;
        return 0xd;
    }
    b = strtol(gAuth->mRetcode, &c, 10);
    d = gAuth;
    if (c != d->mRetcode + strlen(d->mRetcode)) {
        d->mUnk_008 = 0x4e85;
        return 0xb;
    }
    d->mUnk_008 = b + 0x4e20;
    if (b < 100) {
        gAuth->mToken[0] = 0;
        gAuth->mLocator[0] = 0;
        gAuth->mChallenge[0] = 0;
        gAuth->mDatetime[0] = 0;
        gAuth->mCookie[0] = 0;
        DWC_Http_GetBase64DecodedResult(gAuth->mHttpLabelvalue, 0x20, gTokenPairName, gAuth->mToken, 0x12d);
        DWC_Http_GetBase64DecodedResult(gAuth->mHttpLabelvalue, 0x20, gLocatorPairName, gAuth->mLocator, 0x33);
        DWC_Http_GetBase64DecodedResult(gAuth->mHttpLabelvalue, 0x20, gChallengePairName, gAuth->mChallenge, 9);
        DWC_Http_GetBase64DecodedResult(gAuth->mHttpLabelvalue, 0x20, gDatetimePairName, gAuth->mDatetime, 0xf);
        DWC_Http_GetRawResult(gAuth->mHttpLabelvalue, 0x20, gSetCookieHeaderName, gAuth->mCookie, 0x41);
        gAuth->mCookie[0x2b] = 0;
    }
    return 0;
}

u32 DWCi_Auth_Prepare_FirstPost(Http *a, const char *b, const char *c, DWCHttpLabelValue *d, s32 e, s32 f) {
    Unk02185984Data g;
    RTCDate o;
    RTCTime p;
    DWCHttpParseResult q;
    char r[13];
    char s[13];
    u8 t[0x15];
    char u[13];
    u8 v[0x21];
    char w[14];
    char x[0xe];
    Unk0200fddc y;
    u8 *l;
    u32 h;
    u8 *i;
    u8 *j;
    s32 k;
    s32 m;
    char *n;
    OS_GetMacAddress(g.mUnk_02);
    OS_GetOwnerInfo(&y);
    if (RTC_GetDate(&o) != 0 || RTC_GetTime(&p) != 0) {
        return 5;
    }
    h = OS_DisableInterrupts();
    i = func_ov000_021a6b10();
    if (i == NULL) {
        OS_RestoreInterrupts(h);
        return 3;
    }
    MI_CpuCopy8(i, g.mUnk_08, 6);
    MI_CpuFill8(v, 0, 0x21);
    j = func_ov000_021a6abc((u16 *) &g);
    if (j == NULL) {
        OS_RestoreInterrupts(h);
        return 3;
    }
    MI_CpuCopy8(j, v, g.mUnk_00);
    OS_RestoreInterrupts(h);
    MI_CpuCopy8((const void *) 0x27ffe0c, g.mUnk_0e, 4);
    g.mUnk_0e[4] = 0;
    MI_CpuCopy8((const void *) 0x27ffe10, g.mUnk_13, 2);
    g.mUnk_13[2] = 0;
    l = g.mUnk_02;
    for (k = 0; k < 6; l++, k++) {
        OS_SPrintf(&r[k * 2], data_ov000_021b1060, *l);
    }
    r[12] = 0;
    if (y.mUnk_00 > 6) {
        y.mUnk_00 = 1;
    }
    OS_SNPrintf(g.mUnk_16, 5, data_ov000_021b1068, y.mUnk_02, y.mUnk_03);
    OS_SNPrintf(s, 0xd, data_ov000_021b1074, o.mYear, o.mMonth, o.mDay, p.mHour, p.mMinute, p.mSecond);
    MI_CpuCopy8(y.mUnk_04, t, 0x14);
    t[0x14] = 0;
    MI_CpuFill8(&q, 0, 0xc);
    q.mEntries = d;
    q.mCapacity = e;
    if (f != 1) {
        if (data_ov000_021b4c94.mUnk_00 == 0) {
            DWCi_Http_AddResult(&q, gActionPairName, gAcctcreatePairValue);
        } else {
            if (strlen(b) == 0) {
                return 6;
            }
            DWCi_Http_AddResult(&q, gActionPairName, gLoginPairValue);
            DWCi_Http_AddResult(&q, gGsbrcdPairName, b);
            if (strlen(c) != 0) {
                DWCi_Http_AddResult(&q, gIngamesnPairName, c);
            }
        }
    } else {
        DWCi_BM_GetWiFiInfo((DWCWiFiInfo *) &data_ov000_021b4c94);
    }
    DWCi_Http_AddResult(&q, gSdkverPairName, gSdkverPairValue);
    if (data_ov000_021b4c94.mUnk_00 != 0) {
        OS_SNPrintf(x, 0xe, data_ov000_021b10d0, data_ov000_021b4c94.mUnk_00);
    } else {
        OS_SNPrintf(x, 0xe, data_ov000_021b10d0, data_ov000_021b4c94.mUnk_08);
    }
    DWCi_Http_AddResult(&q, gUseridPairName, x);
    OS_SNPrintf(g.mUnk_1b, 4, data_ov000_021b10e0, data_ov000_021b4c94.mUnk_10);
    DWCi_Http_AddResult(&q, gPasswdPairName, g.mUnk_1b);
    OS_SNPrintf(u, 0xd, data_ov000_021b10f0, g.mUnk_08[0], g.mUnk_08[1], g.mUnk_08[2], g.mUnk_08[3], g.mUnk_08[4],
                g.mUnk_08[5]);
    OS_SNPrintf(w, 0xd, data_ov000_021b110c, 0);
    func_ov000_0218a67c(v, &w[3]);
    DWCi_Http_AddResult(&q, gGamecdPairName, g.mUnk_0e);
    DWCi_Http_AddResult(&q, gMakercdPairName, g.mUnk_13);
    DWCi_Http_AddResult(&q, gUnitcdPairName, gUnitcdPairValue);
    DWCi_Http_AddResult(&q, gMacadrPairName, r);
    DWCi_Http_AddResult(&q, gLangPairName, data_ov000_021b1004[y.mUnk_00]);
    DWCi_Http_AddResult(&q, gBirthPairName, g.mUnk_16);
    DWCi_Http_AddResult(&q, gDevtimePairName, s);
    DWCi_Http_AddResult(&q, gBssidPairName, u);
    DWCi_Http_AddResult(&q, gApinfoPairName, w);
    if (DWC_Http_Add_HeaderItem(a, gUserAgentHeaderName, gUserAgentHeaderValue) != FALSE) {
        return 7;
    }
    if (DWC_Http_Add_HeaderItem(a, gHttpXGamecdHeaderName, g.mUnk_0e) != FALSE) {
        return 7;
    }
    for (m = 0; d->mFirst != NULL; d++, m++) {
        n = d->mSecond;
        if (DWC_Http_Add_PostBase64Item(a, d->mFirst, n, strlen(n)) != FALSE) {
            return 8;
        }
    }
    if (DWC_Http_Add_PostBase64Item(a, gDevnamePairName, t, 0x14) != FALSE) {
        return 8;
    }
    return 0;
}

void DWCi_Auth_SetError(s32 a) {
    OS_LockMutex(&((Unk021b4c90 *) gAuth)->mMutex);
    ((Unk021b4c90 *) gAuth)->mError = a;
    OS_UnlockMutex(&((Unk021b4c90 *) gAuth)->mMutex);
}
