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

void func_ov000_02187fb8(void) {
    if (data_ov000_021b4cb0 != NULL) {
        if (gHttp != NULL) {
            func_ov000_02187274(gHttp);
        }
        func_ov000_02186474();
        if (data_ov000_021b4cb0->mUnk_11c.mId != 0) {
            ThreadWaitForEnd(&data_ov000_021b4cb0->mUnk_11c);
        }
        data_ov000_021b4cb0->mUnk_04 = 0xfffffff9;
    }
}

void func_ov000_021874ec(void) {
    Unk0218635c e;
    Unk021510a4 c;
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
    Unk02187490 *q;

    p1 = NULL;
    p2 = NULL;
    p3 = NULL;
    for (;;) {
        data_ov000_021b4cb4.mUnk_00 = data_ov000_021b1384;
        data_ov000_021b4cb4.mUnk_04 = TRUE;
        data_ov000_021b4cb4.mUnk_08 = FALSE;
        data_ov000_021b4cb4.mUnk_0c = 0x1000;
        data_ov000_021b4cb4.mUnk_10 = data_ov000_021b4cb0->mUnk_108.mUnk_00;
        data_ov000_021b4cb4.mUnk_14 = data_ov000_021b4cb0->mUnk_108.mUnk_04;
        data_ov000_021b4cb4.mUnk_1c = 20000;
        data_ov000_021b4cb0->mUnk_04 = -2;
        if (func_ov000_021873d4(gHttp, (const Unk021873d4 *) &data_ov000_021b4cb4) != 0) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(1);
            break;
        }
        if (func_ov000_0218735c(gHttp) != 0) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(1);
            break;
        }
        func_ov000_021872bc(gHttp);
        if (((Unk021b4cac *) gHttp)->mUnk_9d4 != 0) {
            ThreadWaitForEnd((Thread *) ((Unk021b4cac *) gHttp)->mThread);
        }
        o = (Unk021b4cac *) gHttp;
        switch (o->mResult) {
            case 2:
                data_ov000_021b4cb0->mUnk_04 = -1;
            default:
                ReleaseHttp((Http *) gHttp);
                func_ov000_02187490(3);
                goto end;
            case 8:
                break;
        }
        if (func_ov000_021866fc(data_ov000_021b4cb0->mUnk_08, 0x20, 0, o->mUnk_938) != TRUE) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(2);
            break;
        }
        r = StrtolBase10(func_ov000_021866b8(data_ov000_021b4cb0->mUnk_08, 0x20, data_ov000_021b13f4));
        if (gLibErrorCode == 0x22) {
            func_ov000_02187490(2);
            break;
        }
        if (r != 200) {
            if (r == 0x12e) {
                q = data_ov000_021b4cb0;
                if (q->mUnk_118 != NULL) {
                    q->mUnk_04 = -6;
                    ReleaseHttp((Http *) gHttp);
                    data_ov000_021b4cb4.mUnk_00 = data_ov000_021b1040.mUnk_00;
                    data_ov000_021b4cb4.mUnk_04 = FALSE;
                    data_ov000_021b4cb4.mUnk_08 = FALSE;
                    data_ov000_021b4cb4.mUnk_0c = 0x200;
                    data_ov000_021b4cb4.mUnk_10 = data_ov000_021b4cb0->mUnk_108.mUnk_00;
                    data_ov000_021b4cb4.mUnk_14 = data_ov000_021b4cb0->mUnk_108.mUnk_04;
                    data_ov000_021b4cb4.mUnk_1c = 20000;
                    if (strcmp(data_ov000_021b4cb4.mUnk_00, data_ov000_021b1400) != 0) {
                        data_ov000_021b4cb4.mUnk_18 = TRUE;
                    }
                    if (func_ov000_021873d4(gHttp, (const Unk021873d4 *) &data_ov000_021b4cb4) != 0) {
                        ReleaseHttp((Http *) gHttp);
                        func_ov000_02187490(1);
                        break;
                    }
                    if (func_ov000_02185984((Http *) gHttp, data_ov000_021b1420, data_ov000_021b1420,
                                            data_ov000_021b4cb0->mUnk_08, 0x20, 1) != 0) {
                        ReleaseHttp((Http *) gHttp);
                        func_ov000_02187490(8);
                        break;
                    }
                    if (func_ov000_02186b0c((Http *) gHttp, data_ov000_021b1424, data_ov000_021b142c, 7) != FALSE) {
                        ReleaseHttp((Http *) gHttp);
                        func_ov000_02187490(8);
                        break;
                    }
                    h = IrqDisable();
                    MemFill(d, 0, 0x21);
                    func_ov000_021a6abc(&b);
                    MemCopy(func_ov000_021a6abc(NULL), d, b);
                    IrqRestore(h);
                    if (func_ov000_02186b0c((Http *) gHttp, data_ov000_021b1434, d, strlen(d)) != FALSE) {
                        ReleaseHttp((Http *) gHttp);
                        func_ov000_02187490(8);
                        break;
                    }
                    s = data_ov000_021b4cb0->mUnk_118;
                    if (func_ov000_02186b0c((Http *) gHttp, data_ov000_021b143c, s, strlen(s)) != FALSE) {
                        ReleaseHttp((Http *) gHttp);
                        func_ov000_02187490(8);
                        break;
                    }
                    q = data_ov000_021b4cb0;
                    q->mUnk_108.mUnk_04(data_ov000_021b13d8, q->mUnk_118, 0);
                    data_ov000_021b4cb0->mUnk_118 = NULL;
                    if (func_ov000_0218735c(gHttp) != 0) {
                        ReleaseHttp((Http *) gHttp);
                        func_ov000_02187490(1);
                        break;
                    }
                    func_ov000_021872bc(gHttp);
                    if (((Unk021b4cac *) gHttp)->mUnk_9d4 != 0) {
                        ThreadWaitForEnd((Thread *) ((Unk021b4cac *) gHttp)->mThread);
                    }
                    o = (Unk021b4cac *) gHttp;
                    switch (o->mResult) {
                        case 2:
                            data_ov000_021b4cb0->mUnk_04 = -1;
                        default:
                            ReleaseHttp((Http *) gHttp);
                            func_ov000_02187490(3);
                            goto end;
                        case 8:
                            ReleaseHttp((Http *) o);
                            func_ov000_02187490(7);
                            goto end;
                    }
                }
                s = func_ov000_021866b8(q->mUnk_08, 0x20, data_ov000_021b144c);
                if (s == NULL) {
                    ReleaseHttp((Http *) gHttp);
                    func_ov000_02187490(2);
                    break;
                }
                data_ov000_021b4cb0->mUnk_114 =
                    data_ov000_021b4cb0->mUnk_108.mUnk_00(data_ov000_021b13ac, strlen(s) + 1);
                t = data_ov000_021b4cb0->mUnk_114;
                if (t == NULL) {
                    ReleaseHttp((Http *) gHttp);
                    func_ov000_02187490(4);
                    break;
                }
                strncpy(t, s, strlen(s));
            } else {
                ReleaseHttp((Http *) gHttp);
                func_ov000_02187490(10);
                break;
            }
        }
        ReleaseHttp((Http *) gHttp);
        func_02151910(&c);
        if (c.mUnk_00 == 0) {
            data_ov000_021b4cb0->mUnk_04 = -3;
            data_ov000_021b4cd4.mUnk_00 = 0;
            data_ov000_021b4cd4.mUnk_15 = 0;
            data_ov000_021b4cd4.mUnk_24 = data_ov000_021b4cb0->mUnk_108.mUnk_00;
            data_ov000_021b4cd4.mUnk_28 = data_ov000_021b4cb0->mUnk_108.mUnk_04;
            if (func_ov000_02186560((Unk02186560 *) &data_ov000_021b4cd4, (Http *) gHttp) != 0) {
                func_ov000_02187490(5);
                break;
            }
            func_ov000_02186404();
            if (func_ov000_021863cc() != 20) {
                if (func_ov000_021863cc() == 9) {
                    data_ov000_021b4cb0->mUnk_04 = -1;
                } else {
                    func_ov000_0218635c((s32 *) &e);
                    data_ov000_021b4cb0->mUnk_04 = e.mUnk_000;
                }
                func_ov000_02187490(6);
                break;
            }
            func_ov000_02186430();
        }
        if (r == 200) {
            data_ov000_021b4cb0->mUnk_04 = 0;
            func_ov000_02187490(11);
            break;
        }
        data_ov000_021b4cb0->mUnk_04 = -4;
        data_ov000_021b4cb4.mUnk_00 = data_ov000_021b1040.mUnk_00;
        data_ov000_021b4cb4.mUnk_04 = FALSE;
        data_ov000_021b4cb4.mUnk_08 = FALSE;
        data_ov000_021b4cb4.mUnk_0c = 0x1000;
        data_ov000_021b4cb4.mUnk_10 = data_ov000_021b4cb0->mUnk_108.mUnk_00;
        data_ov000_021b4cb4.mUnk_14 = data_ov000_021b4cb0->mUnk_108.mUnk_04;
        data_ov000_021b4cb4.mUnk_1c = 40000;
        if (strcmp(data_ov000_021b4cb4.mUnk_00, data_ov000_021b1400) != 0) {
            data_ov000_021b4cb4.mUnk_18 = TRUE;
        }
        if (func_ov000_021873d4(gHttp, (const Unk021873d4 *) &data_ov000_021b4cb4) != 0) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(1);
            break;
        }
        if (func_ov000_02185984((Http *) gHttp, data_ov000_021b1420, data_ov000_021b1420, data_ov000_021b4cb0->mUnk_08,
                                0x20, 1) != 0) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(8);
            break;
        }
        if (func_ov000_02186b0c((Http *) gHttp, data_ov000_021b1424, data_ov000_021b1458, 5) != FALSE) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(8);
            break;
        }
        h = IrqDisable();
        MemFill(d, 0, 0x21);
        func_ov000_021a6abc(&b);
        MemCopy(func_ov000_021a6abc(NULL), d, b);
        IrqRestore(h);
        if (func_ov000_02186b0c((Http *) gHttp, data_ov000_021b1434, d, strlen(d)) != FALSE) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(8);
            break;
        }
        s = data_ov000_021b4cb0->mUnk_114;
        if (func_ov000_02186b0c((Http *) gHttp, data_ov000_021b1460, s, strlen(s)) != FALSE) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(8);
            break;
        }
        q = data_ov000_021b4cb0;
        q->mUnk_108.mUnk_04(data_ov000_021b13ac, q->mUnk_114, 0);
        data_ov000_021b4cb0->mUnk_114 = NULL;
        if (func_ov000_0218735c(gHttp) != 0) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(1);
            break;
        }
        func_ov000_021872bc(gHttp);
        if (((Unk021b4cac *) gHttp)->mUnk_9d4 != 0) {
            ThreadWaitForEnd((Thread *) ((Unk021b4cac *) gHttp)->mThread);
        }
        o = (Unk021b4cac *) gHttp;
        switch (o->mResult) {
            case 2:
                data_ov000_021b4cb0->mUnk_04 = -1;
            default:
                ReleaseHttp((Http *) gHttp);
                func_ov000_02187490(3);
                goto end;
            case 8:
                break;
        }
        if (func_ov000_021866fc(data_ov000_021b4cb0->mUnk_08, 0x20, 0, o->mUnk_938) != TRUE) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(2);
            break;
        }
        r = StrtolBase10(func_ov000_021866b8(data_ov000_021b4cb0->mUnk_08, 0x20, data_ov000_021b13f4));
        if (gLibErrorCode == 0x22) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(2);
            break;
        }
        if (r != 200) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(2);
            break;
        }
        if (func_ov000_02186674(data_ov000_021b4cb0->mUnk_08, 0x20, data_ov000_021b1468, b2, 4) <= 0) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(9);
            break;
        }
        r = StrtolBase10(b2);
        if (gLibErrorCode == 0x22) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(9);
            break;
        }
        if (r >= 100) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(6);
            break;
        }
        n1 = func_ov000_02186674(data_ov000_021b4cb0->mUnk_08, 0x20, data_ov000_021b13c4, NULL, 0);
        if (n1 <= 0) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(9);
            break;
        }
        n2 = func_ov000_02186674(data_ov000_021b4cb0->mUnk_08, 0x20, data_ov000_021b13c8, NULL, 0);
        if (n2 <= 0) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(9);
            break;
        }
        n3 = func_ov000_02186674(data_ov000_021b4cb0->mUnk_08, 0x20, data_ov000_021b13d0, NULL, 0);
        p1 = data_ov000_021b4cb0->mUnk_108.mUnk_00(data_ov000_021b13c4, n1 + 1);
        if (p1 == NULL) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(4);
            break;
        }
        p2 = data_ov000_021b4cb0->mUnk_108.mUnk_00(data_ov000_021b13c8, n2 + 1);
        if (p2 == NULL) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(4);
            break;
        }
        if (n3 > 0) {
            p3 = data_ov000_021b4cb0->mUnk_108.mUnk_00(data_ov000_021b13d0, n3 + 1);
            if (p3 == NULL) {
                ReleaseHttp((Http *) gHttp);
                func_ov000_02187490(4);
                break;
            }
        }
        k = func_ov000_02186674(data_ov000_021b4cb0->mUnk_08, 0x20, data_ov000_021b13c4, p1, n1 + 1);
        if (k < 0) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(9);
            break;
        }
        p1[k] = 0;
        k = func_ov000_02186674(data_ov000_021b4cb0->mUnk_08, 0x20, data_ov000_021b13c8, p2, n2 + 1);
        if (k < 0) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(9);
            break;
        }
        p2[k] = 0;
        v = 0;
        if (n3 > 0) {
            k = func_ov000_02186674(data_ov000_021b4cb0->mUnk_08, 0x20, data_ov000_021b13d0, p3, n3 + 1);
            if (k < 0) {
                ReleaseHttp((Http *) gHttp);
                func_ov000_02187490(9);
                break;
            }
            p3[k] = 0;
            v = StrtolBase10(p3);
            if (gLibErrorCode == 0x22) {
                ReleaseHttp((Http *) gHttp);
                func_ov000_02187490(9);
                break;
            }
            v *= 1000;
            if (v > 180000) {
                v = 180000;
            }
        }
        ReleaseHttp((Http *) gHttp);
        data_ov000_021b4cb0->mUnk_04 = -5;
        data_ov000_021b4cb4.mUnk_00 = p1;
        data_ov000_021b4cb4.mUnk_04 = FALSE;
        data_ov000_021b4cb4.mUnk_08 = FALSE;
        data_ov000_021b4cb4.mUnk_0c = 0x1000;
        data_ov000_021b4cb4.mUnk_10 = data_ov000_021b4cb0->mUnk_108.mUnk_00;
        data_ov000_021b4cb4.mUnk_14 = data_ov000_021b4cb0->mUnk_108.mUnk_04;
        data_ov000_021b4cb4.mUnk_1c = 40000;
        if (func_ov000_021873d4(gHttp, (const Unk021873d4 *) &data_ov000_021b4cb4) != 0) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(1);
            break;
        }
        if (func_ov000_02186a9c((Http *) gHttp, p2) != FALSE) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(8);
            break;
        }
        if (func_ov000_0218735c(gHttp) != 0) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(1);
            break;
        }
        func_ov000_021872bc(gHttp);
        if (((Unk021b4cac *) gHttp)->mUnk_9d4 != 0) {
            ThreadWaitForEnd((Thread *) ((Unk021b4cac *) gHttp)->mThread);
        }
        o = (Unk021b4cac *) gHttp;
        switch (o->mResult) {
            case 2:
                data_ov000_021b4cb0->mUnk_04 = -1;
            default:
                ReleaseHttp((Http *) gHttp);
                func_ov000_02187490(3);
                goto end;
            case 8:
                break;
        }
        if (func_ov000_021866fc(data_ov000_021b4cb0->mUnk_08, 0x20, 1, o->mUnk_938) != TRUE) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(2);
            break;
        }
        s = func_ov000_021866b8(data_ov000_021b4cb0->mUnk_08, 0x20, data_ov000_021b144c);
        if (s == NULL) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(2);
            break;
        }
        data_ov000_021b4cb0->mUnk_118 = data_ov000_021b4cb0->mUnk_108.mUnk_00(data_ov000_021b13d8, strlen(s) + 1);
        t = data_ov000_021b4cb0->mUnk_118;
        if (t == NULL) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(4);
            break;
        }
        strncpy(t, s, strlen(s));
        ReleaseHttp((Http *) gHttp);
        OS_Sleep(v);
    }
end:
    if (p1 != NULL) {
        data_ov000_021b4cb0->mUnk_108.mUnk_04(data_ov000_021b13c4, p1, 0);
    }
    if (p2 != NULL) {
        data_ov000_021b4cb0->mUnk_108.mUnk_04(data_ov000_021b13c8, p2, 0);
    }
    if (p3 != NULL) {
        data_ov000_021b4cb0->mUnk_108.mUnk_04(data_ov000_021b13d0, p3, 0);
    }
}

u32 func_ov000_021874c0(void) {
    u32 v1;
    ThreadLockWait(&data_ov000_021b4cb0->mUnk_1dc);
    v1 = data_ov000_021b4cb0->mUnk_00;
    ThreadLockUnlock(&data_ov000_021b4cb0->mUnk_1dc);
    return v1;
}

void func_ov000_02187490(u32 a) {
    ThreadLockWait(&data_ov000_021b4cb0->mUnk_1dc);
    data_ov000_021b4cb0->mUnk_00 = a;
    ThreadLockUnlock(&data_ov000_021b4cb0->mUnk_1dc);
}

u32 func_ov000_02187484(void) {
    return (u32) data_ov000_021b4cb0->mUnk_04;
}

s32 func_ov000_021873d4(Unk02186d7c *p, const Unk021873d4 *q) {
    MemFill(p, 0, 0x1a60);
    p->mContentLength = -1;
    p->mUnk_04 = *q;
    p->mLowReceiveBuffer = p->mUnk_04.mUnk_10(data_ov000_021b1320, 0xb68);
    if (p->mLowReceiveBuffer == NULL) {
        p->mResult = 1;
        return 1;
    }
    p->mLowSendBuffer = p->mUnk_04.mUnk_10(data_ov000_021b1334, 0x5ea);
    if (p->mLowSendBuffer == NULL) {
        p->mResult = 1;
        return 1;
    }
    func_ov000_021868d0((Http *) p, (const char *) q->mUnk_00);
    p->mResult = func_ov000_02186c74((Http *) p);
    if (p->mResult == 0) {
        p->mUnk_00 = 0xff;
    }
    return p->mResult;
}

u32 func_ov000_0218735c(Unk02186d7c *p) {
    char v1[8];
    u32 n;
    if (func_ov000_02186bd4((Http *) p, data_ov000_021b135c, data_ov000_021b1368) != FALSE) {
        return 1;
    }
    n = strlen(strstr(p->mSendBuffer.mStart, data_ov000_021b1230) + 4);
    if (n != 0) {
        StringFormatBounded(v1, 7, data_ov000_021b1370, n);
        if (func_ov000_02186bd4((Http *) p, data_ov000_021b1374, v1) != FALSE) {
            return 1;
        }
    }
    return 0;
}

void func_ov000_021872bc(Unk02186d7c *p) {
    u32 n;
    n = ThreadGetSortKey(data_0216ff5c.mCurrentThread);
    p->mUnk_a40 = FALSE;
    ThreadLockInit(&p->mUnk_a28);
    ThreadLockInit(&p->mUnk_948);
    if (p->mUnk_04.mUnk_18 == 1) {
        data_ov000_021b4ca8 = 1;
    } else {
        data_ov000_021b4ca8 = 0;
    }
    if (p->mThread.mId == 0 || ThreadHasEnded(&p->mThread) != 0) {
        ThreadInit(&p->mThread, func_ov000_02186d7c, p, p->mUnk_1a60, 0x1000, n - 1);
        ThreadSetRunnable(&p->mThread);
    }
}

void func_ov000_02187274(Unk02186d7c *p) {
    if (p->mUnk_00 == 0xff) {
        ThreadLockWait(&p->mUnk_a28);
        p->mUnk_a40 = TRUE;
        ThreadLockUnlock(&p->mUnk_a28);
        if (p->mThread.mId != 0) {
            ThreadWaitForEnd(&p->mThread);
        }
    }
}

u32 func_ov000_02187230(Unk02186d7c *a) {
    ThreadLockWait(&a->mUnk_a28);
    if (a->mUnk_a40 == TRUE) {
        ThreadLockUnlock(&a->mUnk_a28);
        return 0;
    }
    ThreadLockUnlock(&a->mUnk_a28);
    OS_Sleep((u32) 10);
    return 1;
}

void func_ov000_02186d7c(void *l) {
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
    MemFill(a, 0, 0x64);
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
        MemFill(b, 0, 0x804);
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
        func_0201000c(&v1);
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
                func_0201000c(&v1);
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
    ThreadLockWait(&p->mUnk_948);
    if (p->mUnk_04.mUnk_08 == NULL) {
        if (InitHttpBuffer((Http *) p, (HttpBuffer *) &p->mReceiveBuffer, p->mUnk_04.mUnk_0c) == 0) {
            p->mResult = 1;
            ThreadLockUnlock(&p->mUnk_948);
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
    ThreadLockUnlock(&p->mUnk_948);
    while (1) {
        if (data_ov000_021b63b4 == 0) {
            p->mResult = 5;
            goto fail;
        }
        ThreadLockWait(&p->mUnk_948);
        if (c->mCursor >= c->mEnd - 1) {
            ThreadLockUnlock(&p->mUnk_948);
            break;
        }
        n = func_ov000_021adbac();
        if (n > 0) {
            x = func_ov000_021adf78((u32 *) &n);
            if (x == NULL) {
                ThreadLockUnlock(&p->mUnk_948);
                break;
            }
            r = c->mEnd - 1 - c->mCursor;
            m = n;
            if ((s32) m >= r) {
                m = r;
            }
            MemCopy(x, c->mCursor, m);
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
                ThreadLockUnlock(&p->mUnk_948);
                break;
            }
            func_ov000_021adf00(m);
        }
        if (n < 0) {
            ThreadLockUnlock(&p->mUnk_948);
            break;
        }
        if (p->mContentLength > 0 && n > 0 && p->mBodyStart + p->mContentLength <= c->mCursor) {
            ThreadLockUnlock(&p->mUnk_948);
            break;
        }
        t = OS_GetTick();
        if ((u64) d < (t - t0) * 64 / 0x82ea) {
            p->mResult = 6;
            ThreadLockUnlock(&p->mUnk_948);
            goto fail;
        }
        if (p->mUseHttps == 1) {
            if (1000 < (t - t1) * 64 / 0x82ea) {
                func_0201000c(&v1);
                func_ov000_021a9c5c(&v1, 0x20);
                t1 = t;
            }
        }
        ThreadLockUnlock(&p->mUnk_948);
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
            a->mFree(data_ov000_021b1320, a->mLowReceiveBuffer, 0);
            a->mLowReceiveBuffer = NULL;
        }
        if (a->mLowSendBuffer != NULL) {
            a->mFree(data_ov000_021b1334, a->mLowSendBuffer, 0);
            a->mLowSendBuffer = NULL;
        }
        MemFill(a, 0, 0x1a60);
    }
    return;
}
