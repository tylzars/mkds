#include "00/code_02186d04.h"
#include "00/unk_021b1000.h"
#include "03/code_021b94b8.h"
#include "00/code_021ad734.h"
#include "00/code_021acef8.h"
#include "00/code_02186a9c.h"
#include "00/code_02186000.h"
#include "00/code_02185954.h"
#include "00/code_021a9200.h"
#include "00/code_021a9228.h"
#include "code_0200d118.h"
#include "code_0200db4c.h"
#include "code_0200f5ac.h"
#include "code_0200fe74.h"
#include "code_0213a460.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200edc0.h"
#include "code_0200e77c.h"
#include "00/code_02187484.h"
#include "00/unk_021b4000.h"
#include "code_0200fc8c.h"
#include "code_021510a4.h"

void DWC_Netcheck_Abort(void) {
    if (gNetcheck != NULL) {
        if (gHttp != NULL) {
            DWC_Http_Abort(gHttp);
        }
        DWC_Auth_Abort();
        if (gNetcheck->mThread.mId != 0) {
            OS_JoinThread(&gNetcheck->mThread);
        }
        gNetcheck->mUnk_04 = 0xfffffff9;
    }
}

void DWCi_Netcheck_Thread(void) {
    Unk0218635c e;
    DWCWiFiInfo c;
    char d[0x24];
    char b2[4];
    u16 b;
    char *p1;
    s32 n1;
    char *p2;
    s32 n2;
    char *p3;
    s32 v;
    char *t;
    char *s;
    s32 n3;
    s32 k;
    s32 r;
    u32 h;
    Unk021b4cac *o;
    DWCNetcheck *q;

    p1 = NULL;
    p2 = NULL;
    p3 = NULL;
    for (;;) {
        data_ov000_021b4cb4.mUnk_00 = data_ov000_021b1384;
        data_ov000_021b4cb4.mUnk_04 = TRUE;
        data_ov000_021b4cb4.mUnk_08 = FALSE;
        data_ov000_021b4cb4.mUnk_0c = 0x1000;
        data_ov000_021b4cb4.mUnk_10 = gNetcheck->mParam.mAlloc;
        data_ov000_021b4cb4.mUnk_14 = gNetcheck->mParam.mFree;
        data_ov000_021b4cb4.mUnk_1c = 20000;
        gNetcheck->mUnk_04 = -2;
        if (DWC_Http_Create(gHttp, (const Unk021873d4 *) &data_ov000_021b4cb4) != 0) {
            ReleaseHttp((Http *) gHttp);
            DWCi_Netcheck_SetError(1);
            break;
        }
        if (DWC_Http_FinishHeader(gHttp) != 0) {
            ReleaseHttp((Http *) gHttp);
            DWCi_Netcheck_SetError(1);
            break;
        }
        DWC_Http_StartThread(gHttp);
        if (((Unk021b4cac *) gHttp)->mUnk_9d4 != 0) {
            OS_JoinThread((OSThread *) ((Unk021b4cac *) gHttp)->mThread);
        }
        o = (Unk021b4cac *) gHttp;
        switch (o->mResult) {
            case 2:
                gNetcheck->mUnk_04 = -1;
            default:
                ReleaseHttp((Http *) gHttp);
                DWCi_Netcheck_SetError(3);
                goto end;
            case 8:
                break;
        }
        if (DWC_Http_ParseResult(gNetcheck->mHttpLabelvalue, 0x20, 0, o->mUnk_938) != TRUE) {
            ReleaseHttp((Http *) gHttp);
            DWCi_Netcheck_SetError(2);
            break;
        }
        r = StrtolBase10(DWC_Http_GetResult(gNetcheck->mHttpLabelvalue, 0x20, gHttpresultPairName3));
        if (gLibErrorCode == 0x22) {
            DWCi_Netcheck_SetError(2);
            break;
        }
        if (r != 200) {
            if (r == 0x12e) {
                q = gNetcheck;
                if (q->mBodyWayport != NULL) {
                    q->mUnk_04 = -6;
                    ReleaseHttp((Http *) gHttp);
                    data_ov000_021b4cb4.mUnk_00 = data_ov000_021b1040.mUnk_00;
                    data_ov000_021b4cb4.mUnk_04 = FALSE;
                    data_ov000_021b4cb4.mUnk_08 = FALSE;
                    data_ov000_021b4cb4.mUnk_0c = 0x200;
                    data_ov000_021b4cb4.mUnk_10 = gNetcheck->mParam.mAlloc;
                    data_ov000_021b4cb4.mUnk_14 = gNetcheck->mParam.mFree;
                    data_ov000_021b4cb4.mUnk_1c = 20000;
                    if (strcmp(data_ov000_021b4cb4.mUnk_00, data_ov000_021b1400) != 0) {
                        data_ov000_021b4cb4.mUnk_18 = TRUE;
                    }
                    if (DWC_Http_Create(gHttp, (const Unk021873d4 *) &data_ov000_021b4cb4) != 0) {
                        ReleaseHttp((Http *) gHttp);
                        DWCi_Netcheck_SetError(1);
                        break;
                    }
                    if (DWCi_Auth_Prepare_FirstPost((Http *) gHttp, data_ov000_021b1420, data_ov000_021b1420,
                                                    gNetcheck->mHttpLabelvalue, 0x20, 1) != 0) {
                        ReleaseHttp((Http *) gHttp);
                        DWCi_Netcheck_SetError(8);
                        break;
                    }
                    if (DWC_Http_Add_PostBase64Item((Http *) gHttp, gActionPairName2, gMessagePairValue, 7) != FALSE) {
                        ReleaseHttp((Http *) gHttp);
                        DWCi_Netcheck_SetError(8);
                        break;
                    }
                    h = OS_DisableInterrupts();
                    MI_CpuFill8(d, 0, 0x21);
                    func_ov000_021a6abc(&b);
                    MI_CpuCopy8(func_ov000_021a6abc(NULL), d, b);
                    OS_RestoreInterrupts(h);
                    if (DWC_Http_Add_PostBase64Item((Http *) gHttp, gSsidPairName, d, strlen(d)) != FALSE) {
                        ReleaseHttp((Http *) gHttp);
                        DWCi_Netcheck_SetError(8);
                        break;
                    }
                    s = gNetcheck->mBodyWayport;
                    if (DWC_Http_Add_PostBase64Item((Http *) gHttp, gHotSpotResponsePairName, s, strlen(s)) != FALSE) {
                        ReleaseHttp((Http *) gHttp);
                        DWCi_Netcheck_SetError(8);
                        break;
                    }
                    q = gNetcheck;
                    q->mParam.mFree(gNetcheckBodyWayportName, q->mBodyWayport, 0);
                    gNetcheck->mBodyWayport = NULL;
                    if (DWC_Http_FinishHeader(gHttp) != 0) {
                        ReleaseHttp((Http *) gHttp);
                        DWCi_Netcheck_SetError(1);
                        break;
                    }
                    DWC_Http_StartThread(gHttp);
                    if (((Unk021b4cac *) gHttp)->mUnk_9d4 != 0) {
                        OS_JoinThread((OSThread *) ((Unk021b4cac *) gHttp)->mThread);
                    }
                    o = (Unk021b4cac *) gHttp;
                    switch (o->mResult) {
                        case 2:
                            gNetcheck->mUnk_04 = -1;
                        default:
                            ReleaseHttp((Http *) gHttp);
                            DWCi_Netcheck_SetError(3);
                            goto end;
                        case 8:
                            ReleaseHttp((Http *) o);
                            DWCi_Netcheck_SetError(7);
                            goto end;
                    }
                }
                s = DWC_Http_GetResult(q->mHttpLabelvalue, 0x20, gHttpbodyPairName2);
                if (s == NULL) {
                    ReleaseHttp((Http *) gHttp);
                    DWCi_Netcheck_SetError(2);
                    break;
                }
                gNetcheck->mBody302 = gNetcheck->mParam.mAlloc(gNetcheckBody302Name, strlen(s) + 1);
                t = gNetcheck->mBody302;
                if (t == NULL) {
                    ReleaseHttp((Http *) gHttp);
                    DWCi_Netcheck_SetError(4);
                    break;
                }
                strncpy(t, s, strlen(s));
            } else {
                ReleaseHttp((Http *) gHttp);
                DWCi_Netcheck_SetError(10);
                break;
            }
        }
        ReleaseHttp((Http *) gHttp);
        DWCi_BM_GetWiFiInfo(&c);
        if (c.mAttestedUserId == 0) {
            gNetcheck->mUnk_04 = -3;
            data_ov000_021b4cd4.mUnk_00 = 0;
            data_ov000_021b4cd4.mUnk_15 = 0;
            data_ov000_021b4cd4.mUnk_24 = gNetcheck->mParam.mAlloc;
            data_ov000_021b4cd4.mUnk_28 = gNetcheck->mParam.mFree;
            if (DWC_Auth_Create((Unk02186560 *) &data_ov000_021b4cd4, (Http *) gHttp) != 0) {
                DWCi_Netcheck_SetError(5);
                break;
            }
            DWC_Auth_Join();
            if (DWC_Auth_GetError() != 20) {
                if (DWC_Auth_GetError() == 9) {
                    gNetcheck->mUnk_04 = -1;
                } else {
                    func_ov000_0218635c((s32 *) &e);
                    gNetcheck->mUnk_04 = e.mUnk_000;
                }
                DWCi_Netcheck_SetError(6);
                break;
            }
            DWC_Auth_Destroy();
        }
        if (r == 200) {
            gNetcheck->mUnk_04 = 0;
            DWCi_Netcheck_SetError(11);
            break;
        }
        gNetcheck->mUnk_04 = -4;
        data_ov000_021b4cb4.mUnk_00 = data_ov000_021b1040.mUnk_00;
        data_ov000_021b4cb4.mUnk_04 = FALSE;
        data_ov000_021b4cb4.mUnk_08 = FALSE;
        data_ov000_021b4cb4.mUnk_0c = 0x1000;
        data_ov000_021b4cb4.mUnk_10 = gNetcheck->mParam.mAlloc;
        data_ov000_021b4cb4.mUnk_14 = gNetcheck->mParam.mFree;
        data_ov000_021b4cb4.mUnk_1c = 40000;
        if (strcmp(data_ov000_021b4cb4.mUnk_00, data_ov000_021b1400) != 0) {
            data_ov000_021b4cb4.mUnk_18 = TRUE;
        }
        if (DWC_Http_Create(gHttp, (const Unk021873d4 *) &data_ov000_021b4cb4) != 0) {
            ReleaseHttp((Http *) gHttp);
            DWCi_Netcheck_SetError(1);
            break;
        }
        if (DWCi_Auth_Prepare_FirstPost((Http *) gHttp, data_ov000_021b1420, data_ov000_021b1420,
                                        gNetcheck->mHttpLabelvalue, 0x20, 1) != 0) {
            ReleaseHttp((Http *) gHttp);
            DWCi_Netcheck_SetError(8);
            break;
        }
        if (DWC_Http_Add_PostBase64Item((Http *) gHttp, gActionPairName2, gParsePairValue, 5) != FALSE) {
            ReleaseHttp((Http *) gHttp);
            DWCi_Netcheck_SetError(8);
            break;
        }
        h = OS_DisableInterrupts();
        MI_CpuFill8(d, 0, 0x21);
        func_ov000_021a6abc(&b);
        MI_CpuCopy8(func_ov000_021a6abc(NULL), d, b);
        OS_RestoreInterrupts(h);
        if (DWC_Http_Add_PostBase64Item((Http *) gHttp, gSsidPairName, d, strlen(d)) != FALSE) {
            ReleaseHttp((Http *) gHttp);
            DWCi_Netcheck_SetError(8);
            break;
        }
        s = gNetcheck->mBody302;
        if (DWC_Http_Add_PostBase64Item((Http *) gHttp, gHtmlPairName, s, strlen(s)) != FALSE) {
            ReleaseHttp((Http *) gHttp);
            DWCi_Netcheck_SetError(8);
            break;
        }
        q = gNetcheck;
        q->mParam.mFree(gNetcheckBody302Name, q->mBody302, 0);
        gNetcheck->mBody302 = NULL;
        if (DWC_Http_FinishHeader(gHttp) != 0) {
            ReleaseHttp((Http *) gHttp);
            DWCi_Netcheck_SetError(1);
            break;
        }
        DWC_Http_StartThread(gHttp);
        if (((Unk021b4cac *) gHttp)->mUnk_9d4 != 0) {
            OS_JoinThread((OSThread *) ((Unk021b4cac *) gHttp)->mThread);
        }
        o = (Unk021b4cac *) gHttp;
        switch (o->mResult) {
            case 2:
                gNetcheck->mUnk_04 = -1;
            default:
                ReleaseHttp((Http *) gHttp);
                DWCi_Netcheck_SetError(3);
                goto end;
            case 8:
                break;
        }
        if (DWC_Http_ParseResult(gNetcheck->mHttpLabelvalue, 0x20, 0, o->mUnk_938) != TRUE) {
            ReleaseHttp((Http *) gHttp);
            DWCi_Netcheck_SetError(2);
            break;
        }
        r = StrtolBase10(DWC_Http_GetResult(gNetcheck->mHttpLabelvalue, 0x20, gHttpresultPairName3));
        if (gLibErrorCode == 0x22) {
            ReleaseHttp((Http *) gHttp);
            DWCi_Netcheck_SetError(2);
            break;
        }
        if (r != 200) {
            ReleaseHttp((Http *) gHttp);
            DWCi_Netcheck_SetError(2);
            break;
        }
        if (DWC_Http_GetBase64DecodedResult(gNetcheck->mHttpLabelvalue, 0x20, gReturncdPairName2, b2, 4) <= 0) {
            ReleaseHttp((Http *) gHttp);
            DWCi_Netcheck_SetError(9);
            break;
        }
        r = StrtolBase10(b2);
        if (gLibErrorCode == 0x22) {
            ReleaseHttp((Http *) gHttp);
            DWCi_Netcheck_SetError(9);
            break;
        }
        if (r >= 100) {
            ReleaseHttp((Http *) gHttp);
            DWCi_Netcheck_SetError(6);
            break;
        }
        n1 = DWC_Http_GetBase64DecodedResult(gNetcheck->mHttpLabelvalue, 0x20, gUrlPairName, NULL, 0);
        if (n1 <= 0) {
            ReleaseHttp((Http *) gHttp);
            DWCi_Netcheck_SetError(9);
            break;
        }
        n2 = DWC_Http_GetBase64DecodedResult(gNetcheck->mHttpLabelvalue, 0x20, gDataPairName, NULL, 0);
        if (n2 <= 0) {
            ReleaseHttp((Http *) gHttp);
            DWCi_Netcheck_SetError(9);
            break;
        }
        n3 = DWC_Http_GetBase64DecodedResult(gNetcheck->mHttpLabelvalue, 0x20, gWaitPairName, NULL, 0);
        p1 = gNetcheck->mParam.mAlloc(gUrlPairName, n1 + 1);
        if (p1 == NULL) {
            ReleaseHttp((Http *) gHttp);
            DWCi_Netcheck_SetError(4);
            break;
        }
        p2 = gNetcheck->mParam.mAlloc(gDataPairName, n2 + 1);
        if (p2 == NULL) {
            ReleaseHttp((Http *) gHttp);
            DWCi_Netcheck_SetError(4);
            break;
        }
        if (n3 > 0) {
            p3 = gNetcheck->mParam.mAlloc(gWaitPairName, n3 + 1);
            if (p3 == NULL) {
                ReleaseHttp((Http *) gHttp);
                DWCi_Netcheck_SetError(4);
                break;
            }
        }
        k = DWC_Http_GetBase64DecodedResult(gNetcheck->mHttpLabelvalue, 0x20, gUrlPairName, p1, n1 + 1);
        if (k < 0) {
            ReleaseHttp((Http *) gHttp);
            DWCi_Netcheck_SetError(9);
            break;
        }
        p1[k] = 0;
        k = DWC_Http_GetBase64DecodedResult(gNetcheck->mHttpLabelvalue, 0x20, gDataPairName, p2, n2 + 1);
        if (k < 0) {
            ReleaseHttp((Http *) gHttp);
            DWCi_Netcheck_SetError(9);
            break;
        }
        p2[k] = 0;
        v = 0;
        if (n3 > 0) {
            k = DWC_Http_GetBase64DecodedResult(gNetcheck->mHttpLabelvalue, 0x20, gWaitPairName, p3, n3 + 1);
            if (k < 0) {
                ReleaseHttp((Http *) gHttp);
                DWCi_Netcheck_SetError(9);
                break;
            }
            p3[k] = 0;
            v = StrtolBase10(p3);
            if (gLibErrorCode == 0x22) {
                ReleaseHttp((Http *) gHttp);
                DWCi_Netcheck_SetError(9);
                break;
            }
            v *= 1000;
            if (v > 180000) {
                v = 180000;
            }
        }
        ReleaseHttp((Http *) gHttp);
        gNetcheck->mUnk_04 = -5;
        data_ov000_021b4cb4.mUnk_00 = p1;
        data_ov000_021b4cb4.mUnk_04 = FALSE;
        data_ov000_021b4cb4.mUnk_08 = FALSE;
        data_ov000_021b4cb4.mUnk_0c = 0x1000;
        data_ov000_021b4cb4.mUnk_10 = gNetcheck->mParam.mAlloc;
        data_ov000_021b4cb4.mUnk_14 = gNetcheck->mParam.mFree;
        data_ov000_021b4cb4.mUnk_1c = 40000;
        if (DWC_Http_Create(gHttp, (const Unk021873d4 *) &data_ov000_021b4cb4) != 0) {
            ReleaseHttp((Http *) gHttp);
            DWCi_Netcheck_SetError(1);
            break;
        }
        if (DWC_Http_Add_Body((Http *) gHttp, p2) != FALSE) {
            ReleaseHttp((Http *) gHttp);
            DWCi_Netcheck_SetError(8);
            break;
        }
        if (DWC_Http_FinishHeader(gHttp) != 0) {
            ReleaseHttp((Http *) gHttp);
            DWCi_Netcheck_SetError(1);
            break;
        }
        DWC_Http_StartThread(gHttp);
        if (((Unk021b4cac *) gHttp)->mUnk_9d4 != 0) {
            OS_JoinThread((OSThread *) ((Unk021b4cac *) gHttp)->mThread);
        }
        o = (Unk021b4cac *) gHttp;
        switch (o->mResult) {
            case 2:
                gNetcheck->mUnk_04 = -1;
            default:
                ReleaseHttp((Http *) gHttp);
                DWCi_Netcheck_SetError(3);
                goto end;
            case 8:
                break;
        }
        if (DWC_Http_ParseResult(gNetcheck->mHttpLabelvalue, 0x20, 1, o->mUnk_938) != TRUE) {
            ReleaseHttp((Http *) gHttp);
            DWCi_Netcheck_SetError(2);
            break;
        }
        s = DWC_Http_GetResult(gNetcheck->mHttpLabelvalue, 0x20, gHttpbodyPairName2);
        if (s == NULL) {
            ReleaseHttp((Http *) gHttp);
            DWCi_Netcheck_SetError(2);
            break;
        }
        gNetcheck->mBodyWayport = gNetcheck->mParam.mAlloc(gNetcheckBodyWayportName, strlen(s) + 1);
        t = gNetcheck->mBodyWayport;
        if (t == NULL) {
            ReleaseHttp((Http *) gHttp);
            DWCi_Netcheck_SetError(4);
            break;
        }
        strncpy(t, s, strlen(s));
        ReleaseHttp((Http *) gHttp);
        OS_Sleep(v);
    }
end:
    if (p1 != NULL) {
        gNetcheck->mParam.mFree(gUrlPairName, p1, 0);
    }
    if (p2 != NULL) {
        gNetcheck->mParam.mFree(gDataPairName, p2, 0);
    }
    if (p3 != NULL) {
        gNetcheck->mParam.mFree(gWaitPairName, p3, 0);
    }
}

u32 DWC_Netcheck_GetError(void) {
    u32 v1;
    OS_LockMutex(&gNetcheck->mMutex);
    v1 = gNetcheck->mError;
    OS_UnlockMutex(&gNetcheck->mMutex);
    return v1;
}

void DWCi_Netcheck_SetError(u32 a) {
    OS_LockMutex(&gNetcheck->mMutex);
    gNetcheck->mError = a;
    OS_UnlockMutex(&gNetcheck->mMutex);
}

u32 func_ov000_02187484(void) {
    return gNetcheck->mUnk_04;
}

s32 DWC_Http_Create(Unk02186d7c *p, const Unk021873d4 *q) {
    MI_CpuFill8(p, 0, 0x1a60);
    p->mContentLength = -1;
    p->mUnk_04 = *q;
    p->mLowReceiveBuffer = p->mUnk_04.mUnk_10(gHttpLowReceiveBufferName, 0xb68);
    if (p->mLowReceiveBuffer == NULL) {
        p->mResult = 1;
        return 1;
    }
    p->mLowSendBuffer = p->mUnk_04.mUnk_10(gHttpLowSendBufferName, 0x5ea);
    if (p->mLowSendBuffer == NULL) {
        p->mResult = 1;
        return 1;
    }
    DWCi_Http_SetHostinfo((Http *) p, (const char *) q->mUnk_00);
    p->mResult = DWCi_Http_WriteBasicHeader((Http *) p);
    if (p->mResult == 0) {
        p->mUnk_00 = 0xff;
    }
    return p->mResult;
}

u32 DWC_Http_FinishHeader(Unk02186d7c *p) {
    char v1[8];
    u32 n;
    if (DWC_Http_Add_HeaderItem((Http *) p, data_ov000_021b135c, data_ov000_021b1368) != FALSE) {
        return 1;
    }
    n = strlen(strstr(p->mSendBuffer.mStart, data_ov000_021b1230) + 4);
    if (n != 0) {
        OS_SNPrintf(v1, 7, data_ov000_021b1370, n);
        if (DWC_Http_Add_HeaderItem((Http *) p, data_ov000_021b1374, v1) != FALSE) {
            return 1;
        }
    }
    return 0;
}

void DWC_Http_StartThread(Unk02186d7c *p) {
    u32 n;
    n = OS_GetThreadPriority(data_0216ff5c.mCurrentThread);
    p->mUnk_a40 = FALSE;
    OS_InitMutex(&p->mUnk_a28);
    OS_InitMutex(&p->mUnk_948);
    if (p->mUnk_04.mUnk_18 == 1) {
        data_ov000_021b4ca8 = 1;
    } else {
        data_ov000_021b4ca8 = 0;
    }
    if (p->mThread.mId == 0 || OS_IsThreadTerminated(&p->mThread) != 0) {
        OS_CreateThread(&p->mThread, DWCi_Http_Thread, p, p->mUnk_1a60, 0x1000, n - 1);
        OS_WakeupThreadDirect(&p->mThread);
    }
}

void DWC_Http_Abort(Unk02186d7c *p) {
    if (p->mUnk_00 == 0xff) {
        OS_LockMutex(&p->mUnk_a28);
        p->mUnk_a40 = TRUE;
        OS_UnlockMutex(&p->mUnk_a28);
        if (p->mThread.mId != 0) {
            OS_JoinThread(&p->mThread);
        }
    }
}

u32 func_ov000_02187230(Unk02186d7c *a) {
    OS_LockMutex(&a->mUnk_a28);
    if (a->mUnk_a40 == TRUE) {
        OS_UnlockMutex(&a->mUnk_a28);
        return 0;
    }
    OS_UnlockMutex(&a->mUnk_a28);
    OS_Sleep(10);
    return 1;
}

void DWCi_Http_Thread(void *l) {
    Unk02186d7c *p = l;
    Unk02186d7cB4 *a;
    Unk02186d7c118 *b;
    Unk02186d7cBuf *c;
    const u8 *x;
    s32 d;
    int g;
    u64 t0;
    u64 t1;
    u8 f;
    int h;
    u32 m;
    s32 r;
    u64 t;
    s8 *q;
    s8 e;
    s32 n;
    Unk0201000c v1;
    char *s;
    const char *y;

    f = 0;
    a = &p->mUnk_b4;
    b = &p->mUnk_118;
    c = &p->mReceiveBuffer;
    d = p->mUnk_04.mUnk_1c;
    if (d <= 0) {
        d = 60000;
    }
    MI_CpuFill8(a, 0, 0x64);
    a->mReceiveBufferSize = 0xb68;
    a->mReceiveBuffer = p->mLowReceiveBuffer;
    a->mSendBufferSize = 0x5ea;
    a->mSendBuffer = p->mLowSendBuffer;
    func_ov000_021ae304(a);
    g = func_ov000_021acef8(p->mHost);
    if (g == 0) {
        p->mResult = 2;
        return;
    }
    func_ov000_021ae270();
    if (p->mUseHttps == 1) {
        MI_CpuFill8(b, 0, 0x804);
        b->mUnk_7e4 = func_ov000_02186a84;
        b->mUnk_7d4 = p->mHost;
        a->mUnk_0c = b;
        func_ov000_021ab594((u32) data_ov000_021b1204, 0xb);
        func_ov000_021a9200(1);
        h = 0x1bb;
    } else {
        h = 0x50;
    }
    func_ov000_021ae290(0, h, g);
    t0 = OS_GetTick();
    if (p->mUseHttps == 1) {
        OS_GetLowEntropyData(&v1);
        func_ov000_021a9c5c(&v1, 0x20);
        t1 = t0;
    }
    if (func_ov000_021ae134() != 0) {
        p->mResult = 3;
        func_ov000_021ae258();
        func_ov000_021ae2f4();
        return;
    }
    p->mSendBuffer.mCursor = p->mSendBuffer.mStart;
    s = p->mSendBuffer.mStart;
    p->mSendBuffer.mEnd = s + strlen(s);
    while (p->mSendBuffer.mCursor < p->mSendBuffer.mEnd) {
        if (data_ov000_021b63b4 == 0) {
            p->mResult = 5;
            goto fail;
        }
        n = p->mSendBuffer.mEnd - p->mSendBuffer.mCursor;
        if (n > 0x238) {
            n = 0x238;
        }
        n = func_ov000_021adbf4((const u8 *) p->mSendBuffer.mCursor, n);
        if (n <= 0) {
            p->mResult = 5;
            goto fail;
        }
        func_ov000_021adb80();
        t = OS_GetTick();
        if ((u64) d < (t - t0) * 64 / 0x82ea) {
            p->mResult = 4;
            goto fail;
        }
        if (p->mUseHttps == 1) {
            if (1000 < (t - t1) * 64 / 0x82ea) {
                OS_GetLowEntropyData(&v1);
                func_ov000_021a9c5c(&v1, 0x20);
                t1 = t;
            }
        }
        p->mSendBuffer.mCursor += n;
        if (func_ov000_02187230(p) == 0) {
            p->mResult = 7;
            goto fail;
        }
    }
    FreeHttpBuffer((Http *) p, (HttpBuffer *) &p->mSendBuffer);
    OS_LockMutex(&p->mUnk_948);
    if (p->mUnk_04.mUnk_08 == NULL) {
        if (InitHttpBuffer((Http *) p, (HttpBuffer *) &p->mReceiveBuffer, p->mUnk_04.mUnk_0c) == 0) {
            p->mResult = 1;
            OS_UnlockMutex(&p->mUnk_948);
            goto fail;
        }
    } else {
        p->mReceiveBuffer.mStart = p->mUnk_04.mUnk_08;
        p->mReceiveBuffer.mCursor = p->mReceiveBuffer.mStart;
        p->mReceiveBuffer.mEnd = p->mReceiveBuffer.mStart + p->mUnk_04.mUnk_0c;
        p->mReceiveBuffer.mSize = p->mUnk_04.mUnk_0c;
    }
    c->mCursor = c->mStart;
    c->mEnd = c->mStart + c->mSize;
    OS_UnlockMutex(&p->mUnk_948);
    while (1) {
        if (data_ov000_021b63b4 == 0) {
            p->mResult = 5;
            goto fail;
        }
        OS_LockMutex(&p->mUnk_948);
        if (c->mCursor >= c->mEnd - 1) {
            OS_UnlockMutex(&p->mUnk_948);
            break;
        }
        n = func_ov000_021adbac();
        if (n > 0) {
            x = func_ov000_021adf78((u32 *) &n);
            if (x == NULL) {
                OS_UnlockMutex(&p->mUnk_948);
                break;
            }
            r = c->mEnd - 1 - c->mCursor;
            m = n;
            if ((s32) m >= r) {
                m = r;
            }
            MI_CpuCopy8(x, c->mCursor, m);
            c->mCursor += m;
            *c->mCursor = 0;
            if (f != 1) {
                s = c->mStart;
                if (strstr(s, data_ov000_021b1230) != NULL) {
                    f = 1;
                    p->mBodyStart = strstr(s, data_ov000_021b1230) + 4;
                    y = strstr(c->mStart, data_ov000_021b1348);
                    if (y != NULL) {
                        y = y + strlen(data_ov000_021b1348);
                        q = (s8 *) strstr(y, data_ov000_021b1258);
                        e = *q;
                        *q = 0;
                        p->mContentLength = StrtolBase10(y);
                        *q = e;
                    }
                }
            }
            if (n > m) {
                func_ov000_021adf00(n);
                OS_UnlockMutex(&p->mUnk_948);
                break;
            }
            func_ov000_021adf00(m);
        }
        if (n < 0) {
            OS_UnlockMutex(&p->mUnk_948);
            break;
        }
        if (p->mContentLength > 0 && n > 0 && p->mBodyStart + p->mContentLength <= c->mCursor) {
            OS_UnlockMutex(&p->mUnk_948);
            break;
        }
        t = OS_GetTick();
        if ((u64) d < (t - t0) * 64 / 0x82ea) {
            p->mResult = 6;
            OS_UnlockMutex(&p->mUnk_948);
            goto fail;
        }
        if (p->mUseHttps == 1) {
            if (1000 < (t - t1) * 64 / 0x82ea) {
                OS_GetLowEntropyData(&v1);
                func_ov000_021a9c5c(&v1, 0x20);
                t1 = t;
            }
        }
        OS_UnlockMutex(&p->mUnk_948);
        if (func_ov000_02187230(p) == 0) {
            p->mResult = 7;
            goto fail;
        }
    }
    func_ov000_021ae094();
    func_ov000_021ae048();
    func_ov000_021ae258();
    func_ov000_021ae2f4();
    p->mResult = 8;
    return;
fail:
    func_ov000_021ae094();
    func_ov000_021ae048();
    func_ov000_021ae258();
    func_ov000_021ae2f4();
}

void ReleaseHttp(Http *a) {
    if (a != NULL) {
        if (a->mGivenReceiveBuffer == 0) {
            FreeHttpBuffer(a, &a->mReceiveBuffer);
        }
        FreeHttpBuffer(a, &a->mSendBuffer);
        if (a->mLowReceiveBuffer != NULL) {
            a->mFree(gHttpLowReceiveBufferName, a->mLowReceiveBuffer, 0);
            a->mLowReceiveBuffer = NULL;
        }
        if (a->mLowSendBuffer != NULL) {
            a->mFree(gHttpLowSendBufferName, a->mLowSendBuffer, 0);
            a->mLowSendBuffer = NULL;
        }
        MI_CpuFill8(a, 0, 0x1a60);
    }
}
