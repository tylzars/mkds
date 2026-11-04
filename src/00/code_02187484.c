#include "00/code_02187484.h"

#include "00/unk_021b4000.h"
#include "code_0200e77c.h"
#include "00/unk_021b1000.h"
#include "00/code_02186a9c.h"
#include "00/code_021acef8.h"
#include "00/code_021adbac.h"
#include "03/code_021b94b8.h"
#include "00/code_02186d04.h"
#include "00/code_02186000.h"
#include "code_0200db4c.h"
#include "code_0200fc8c.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "code_0214d018.h"
#include "code_021510a4.h"

void func_ov000_02187fb8(void) {
    if (data_ov000_021b4cb0 != NULL) {
        if (gHttp != NULL) {
            func_ov000_02187274(gHttp);
        }
        func_ov000_02186474();
        if (data_ov000_021b4cb0->mUnk_11c.mUnk_6c != 0) {
            func_0200e084(&data_ov000_021b4cb0->mUnk_11c);
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
        data_ov000_021b4cb4.mUnk_04 = 1;
        data_ov000_021b4cb4.mUnk_08 = 0;
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
            func_0200e084((Unk0200db5c *) ((Unk021b4cac *) gHttp)->mThread);
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
        if (func_ov000_021866fc(data_ov000_021b4cb0->mUnk_08, 0x20, 0, (const char *) o->mUnk_938) != 1) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(2);
            break;
        }
        r = func_0213bf90(func_ov000_021866b8(data_ov000_021b4cb0->mUnk_08, 0x20, data_ov000_021b13f4));
        if (data_0217ee90 == 0x22) {
            func_ov000_02187490(2);
            break;
        }
        if (r != 200) {
            if (r == 0x12e) {
                q = data_ov000_021b4cb0;
                if (q->mUnk_118 != NULL) {
                    q->mUnk_04 = -6;
                    ReleaseHttp((Http *) gHttp);
                    data_ov000_021b4cb4.mUnk_00 = *(char **) data_ov000_021b1040;
                    data_ov000_021b4cb4.mUnk_04 = 0;
                    data_ov000_021b4cb4.mUnk_08 = 0;
                    data_ov000_021b4cb4.mUnk_0c = 0x200;
                    data_ov000_021b4cb4.mUnk_10 = data_ov000_021b4cb0->mUnk_108.mUnk_00;
                    data_ov000_021b4cb4.mUnk_14 = data_ov000_021b4cb0->mUnk_108.mUnk_04;
                    data_ov000_021b4cb4.mUnk_1c = 20000;
                    if (strcmp(data_ov000_021b4cb4.mUnk_00, data_ov000_021b1400) != 0) {
                        data_ov000_021b4cb4.mUnk_18 = 1;
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
                    if (func_ov000_02186b0c((Http *) gHttp, data_ov000_021b1424, data_ov000_021b142c, 7) != 0) {
                        ReleaseHttp((Http *) gHttp);
                        func_ov000_02187490(8);
                        break;
                    }
                    h = IrqDisable();
                    MemFill(d, 0, 0x21);
                    func_ov000_021a6abc(&b);
                    MemCopy(func_ov000_021a6abc(NULL), d, b);
                    IrqRestore(h);
                    if (func_ov000_02186b0c((Http *) gHttp, data_ov000_021b1434, d, strlen(d)) != 0) {
                        ReleaseHttp((Http *) gHttp);
                        func_ov000_02187490(8);
                        break;
                    }
                    s = data_ov000_021b4cb0->mUnk_118;
                    if (func_ov000_02186b0c((Http *) gHttp, data_ov000_021b143c, s, strlen(s)) != 0) {
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
                        func_0200e084((Unk0200db5c *) ((Unk021b4cac *) gHttp)->mThread);
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
        data_ov000_021b4cb4.mUnk_00 = *(char **) data_ov000_021b1040;
        data_ov000_021b4cb4.mUnk_04 = 0;
        data_ov000_021b4cb4.mUnk_08 = 0;
        data_ov000_021b4cb4.mUnk_0c = 0x1000;
        data_ov000_021b4cb4.mUnk_10 = data_ov000_021b4cb0->mUnk_108.mUnk_00;
        data_ov000_021b4cb4.mUnk_14 = data_ov000_021b4cb0->mUnk_108.mUnk_04;
        data_ov000_021b4cb4.mUnk_1c = 40000;
        if (strcmp(data_ov000_021b4cb4.mUnk_00, data_ov000_021b1400) != 0) {
            data_ov000_021b4cb4.mUnk_18 = 1;
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
        if (func_ov000_02186b0c((Http *) gHttp, data_ov000_021b1424, data_ov000_021b1458, 5) != 0) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(8);
            break;
        }
        h = IrqDisable();
        MemFill(d, 0, 0x21);
        func_ov000_021a6abc(&b);
        MemCopy(func_ov000_021a6abc(NULL), d, b);
        IrqRestore(h);
        if (func_ov000_02186b0c((Http *) gHttp, data_ov000_021b1434, d, strlen(d)) != 0) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(8);
            break;
        }
        s = data_ov000_021b4cb0->mUnk_114;
        if (func_ov000_02186b0c((Http *) gHttp, data_ov000_021b1460, s, strlen(s)) != 0) {
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
            func_0200e084((Unk0200db5c *) ((Unk021b4cac *) gHttp)->mThread);
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
        if (func_ov000_021866fc(data_ov000_021b4cb0->mUnk_08, 0x20, 0, (const char *) o->mUnk_938) != 1) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(2);
            break;
        }
        r = func_0213bf90(func_ov000_021866b8(data_ov000_021b4cb0->mUnk_08, 0x20, data_ov000_021b13f4));
        if (data_0217ee90 == 0x22) {
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
        r = func_0213bf90(b2);
        if (data_0217ee90 == 0x22) {
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
            v = func_0213bf90(p3);
            if (data_0217ee90 == 0x22) {
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
        data_ov000_021b4cb4.mUnk_04 = 0;
        data_ov000_021b4cb4.mUnk_08 = 0;
        data_ov000_021b4cb4.mUnk_0c = 0x1000;
        data_ov000_021b4cb4.mUnk_10 = data_ov000_021b4cb0->mUnk_108.mUnk_00;
        data_ov000_021b4cb4.mUnk_14 = data_ov000_021b4cb0->mUnk_108.mUnk_04;
        data_ov000_021b4cb4.mUnk_1c = 40000;
        if (func_ov000_021873d4(gHttp, (const Unk021873d4 *) &data_ov000_021b4cb4) != 0) {
            ReleaseHttp((Http *) gHttp);
            func_ov000_02187490(1);
            break;
        }
        if (func_ov000_02186a9c((Http *) gHttp, p2) != 0) {
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
            func_0200e084((Unk0200db5c *) ((Unk021b4cac *) gHttp)->mThread);
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
        if (func_ov000_021866fc(data_ov000_021b4cb0->mUnk_08, 0x20, 1, (const char *) o->mUnk_938) != 1) {
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
        func_0200dc3c(v);
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
    func_0200ed34((void *) &data_ov000_021b4cb0->mUnk_1dc);
    v1 = data_ov000_021b4cb0->mUnk_00;
    func_0200ecc4((void *) &data_ov000_021b4cb0->mUnk_1dc);
    return v1;
}

void func_ov000_02187490(u32 a) {
    func_0200ed34(&data_ov000_021b4cb0->mUnk_1dc);
    data_ov000_021b4cb0->mUnk_00 = a;
    func_0200ecc4(&data_ov000_021b4cb0->mUnk_1dc);
}

u32 func_ov000_02187484(void) {
    return (u32) data_ov000_021b4cb0->mUnk_04;
}
