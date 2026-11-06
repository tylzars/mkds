#include "Main/Unknown/code_0210e33c.h"
#include "Main/Unknown/code_0202511c.h"
#include "Main/Unknown/code_021053e4.h"

#include "Main/Unknown/code_02111158.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_02111000.h"
#include "code_020219e8.h"
#include "code_0212d214.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02108950.h"
#include "Main/Unknown/code_0210d960.h"
#include "Main/Unknown/code_0210ef68.h"
#include "Main/Unknown/code_0211127c.h"
#include "Main/Unknown/code_0212da2c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"

const Unk0215c380 data_0215c38c = {0xff, 0xff, 0xff};
const Unk0215c380 data_0215c380 = {0xff, 0xff, 0xff};
const Unk0215c380 data_0215c398 = {0xff, 0xff, 0xff};

void func_0210ef34(void) {
    func_0210e434(func_02108950());
}

u32 func_0210ed20(u32 a, u32 b) {
    NNSSndArcBankInfo *p;
    u32 *q;
    u32 *r;
    u32 v;
    u32 w;
    u32 x;
    u32 ok;
    u32 n;
    s32 i;

    if (b != 0) {
        if (NNS_SndArcLoadWaveArc(0x61, data_0217d130) == 0) {
            ok = 0;
        } else {
            u32 *q;
            u32 *r;
            u32 v;
            u32 w;

            q = (u32 *) NNS_SndArcGetWaveArcInfo(0x61);
            r = (u32 *) NNS_SndArcGetWaveArcInfo(0);
            w = ((NNSSndArcWaveArcInfo *) r)->mFileId;
            v = ((NNSSndArcWaveArcInfo *) q)->mFileId;
            NNS_SndArcSetFileAddress(w, NNS_SndArcGetFileAddress(v));
            NNS_SndArcSetFileAddress(v, NULL);
            ok = 1;
            n = data_0217d178.mUnk_40;
            data_0217d178.mUnk_40 = n + 1;
            data_0217d178.mUnk_00[n] = w;
        }
        if (ok == 0) {
            return 0;
        }
        if (NNS_SndArcLoadWaveArc(0x62, data_0217d130) == 0) {
            ok = 0;
        } else {
            u32 *q;
            u32 *r;
            u32 v;
            u32 w;

            q = (u32 *) NNS_SndArcGetWaveArcInfo(0x62);
            r = (u32 *) NNS_SndArcGetWaveArcInfo(0x50);
            w = ((NNSSndArcWaveArcInfo *) r)->mFileId;
            v = ((NNSSndArcWaveArcInfo *) q)->mFileId;
            NNS_SndArcSetFileAddress(w, NNS_SndArcGetFileAddress(v));
            NNS_SndArcSetFileAddress(v, NULL);
            ok = 1;
            n = data_0217d178.mUnk_40;
            data_0217d178.mUnk_40 = n + 1;
            data_0217d178.mUnk_00[n] = w;
        }
        if (ok == 0) {
            return 0;
        }
    } else {
        if (NNS_SndArcLoadWaveArc(0, data_0217d130) == 0) {
            return 0;
        }
        if (NNS_SndArcLoadWaveArc(0x50, data_0217d130) == 0) {
            return 0;
        }
    }
    p = NNS_SndArcGetBankInfo(0);
    x = (u32) NNS_SndArcGetFileAddress(p->mFileId);
    for (i = 0; i < 4; i++) {
        v = p->mWaveArcNo[i];
        if (v == 0xffff) {
            continue;
        }
        q = (u32 *) NNS_SndArcGetWaveArcInfo(v);
        if (q == NULL) {
            break;
        }
        w = ((NNSSndArcWaveArcInfo *) q)->mFileId;
        r = NNS_SndArcGetFileAddress(w);
        if (x == 0) {
            continue;
        }
        if (r == NULL) {
            continue;
        }
        SND_AssignWaveArc((Unk02021968 *) x, i, (Unk02021968 *) r);
    }
    if (func_0210e50c(a) == 0) {
        return 0;
    }
    return 1;
}

u32 func_0210e98c(Unk0215c380 v, u32 d) {
    Unk0217d134 *p;
    u32 ok;
    u32 n;
    s32 i;
    Unk0217d134 *t;

    if (v.mUnk_00 == 0xff && v.mUnk_04 == 0xff && v.mUnk_08 == 0xff) {
        return 1;
    }
    if (func_0210e3ec(func_02108950(), v) != 0) {
        return 1;
    }
    func_0210e434(func_02108950());
    p = &data_0217d134;
    for (i = 0; i < p->mUnk_40; i++) {
        NNS_SndArcSetFileAddress(p->mUnk_00[i], NULL);
    }
    t = &data_0217d134;
    for (i = 0; i < 16; i++) {
        t->mUnk_00[i] = 0;
    }
    t->mUnk_40 = 0;
    if (d != 0) {
        switch (v.mUnk_00) {
            case 0x4a:
                if (NNS_SndArcLoadWaveArc(0x63, data_0217d130) == 0) {
                    ok = 0;
                } else {
                    u32 *p;
                    u32 *q;
                    u32 a;
                    u32 b;

                    p = (u32 *) NNS_SndArcGetWaveArcInfo(0x63);
                    q = (u32 *) NNS_SndArcGetWaveArcInfo(0x31);
                    b = ((NNSSndArcWaveArcInfo *) q)->mFileId;
                    a = ((NNSSndArcWaveArcInfo *) p)->mFileId;
                    NNS_SndArcSetFileAddress(b, NNS_SndArcGetFileAddress(a));
                    NNS_SndArcSetFileAddress(a, NULL);
                    ok = 1;
                    n = data_0217d134.mUnk_40;
                    data_0217d134.mUnk_40 = n + 1;
                    data_0217d134.mUnk_00[n] = b;
                }
                if (ok == 0) {
                    return 0;
                }
                break;
            case 0x2b:
                if (NNS_SndArcLoadWaveArc(0x64, data_0217d130) == 0) {
                    ok = 0;
                } else {
                    u32 *p;
                    u32 *q;
                    u32 a;
                    u32 b;

                    p = (u32 *) NNS_SndArcGetWaveArcInfo(0x64);
                    q = (u32 *) NNS_SndArcGetWaveArcInfo(0x58);
                    b = ((NNSSndArcWaveArcInfo *) q)->mFileId;
                    a = ((NNSSndArcWaveArcInfo *) p)->mFileId;
                    NNS_SndArcSetFileAddress(b, NNS_SndArcGetFileAddress(a));
                    NNS_SndArcSetFileAddress(a, NULL);
                    ok = 1;
                    n = data_0217d134.mUnk_40;
                    data_0217d134.mUnk_40 = n + 1;
                    data_0217d134.mUnk_00[n] = b;
                }
                if (ok == 0) {
                    return 0;
                }
                break;
            case 0xf:
                if (NNS_SndArcLoadWaveArc(0x34, data_0217d130) == 0) {
                    ok = 0;
                } else {
                    u32 *p;
                    u32 *q;
                    u32 a;
                    u32 b;

                    p = (u32 *) NNS_SndArcGetWaveArcInfo(0x34);
                    q = (u32 *) NNS_SndArcGetWaveArcInfo(0x33);
                    b = ((NNSSndArcWaveArcInfo *) q)->mFileId;
                    a = ((NNSSndArcWaveArcInfo *) p)->mFileId;
                    NNS_SndArcSetFileAddress(b, NNS_SndArcGetFileAddress(a));
                    NNS_SndArcSetFileAddress(a, NULL);
                    ok = 1;
                    n = data_0217d134.mUnk_40;
                    data_0217d134.mUnk_40 = n + 1;
                    data_0217d134.mUnk_00[n] = b;
                }
                if (ok == 0) {
                    return 0;
                }
                break;
        }
        if (v.mUnk_04 == 0x10) {
            if (NNS_SndArcLoadWaveArc(0x13, data_0217d130) == 0) {
                ok = 0;
            } else {
                u32 *p;
                u32 *q;
                u32 a;
                u32 b;

                p = (u32 *) NNS_SndArcGetWaveArcInfo(0x13);
                q = (u32 *) NNS_SndArcGetWaveArcInfo(0x12);
                b = ((NNSSndArcWaveArcInfo *) q)->mFileId;
                a = ((NNSSndArcWaveArcInfo *) p)->mFileId;
                NNS_SndArcSetFileAddress(b, NNS_SndArcGetFileAddress(a));
                NNS_SndArcSetFileAddress(a, NULL);
                ok = 1;
                n = data_0217d134.mUnk_40;
                data_0217d134.mUnk_40 = n + 1;
                data_0217d134.mUnk_00[n] = b;
            }
            if (ok == 0) {
                return 0;
            }
        }
    }
    return func_0210e33c(func_02108950(), v) != 0;
}

void func_0210e920(void) {
    if (NNS_SndArcLoadWaveArc(1, data_0217d130) == 0) {
        return;
    }
    if (NNS_SndArcLoadBankEx(0, 2, data_0217d130) == 0) {
        return;
    }
    NNS_SndArcLoadSeqArc(0, data_0217d130);
}

void func_0210e8f8(u32 a) {
    func_0210ed20(0, a);
    func_0210e4c8(func_02108950());
}

void func_0210e888(Unk0210e524 a, u32 b) {
    Unk0215c380 v;

    v.mUnk_00 = a.mUnk_01;
    v.mUnk_04 = a.mUnk_02;
    v.mUnk_08 = a.mUnk_03;
    func_0210e98c(v, b);
    if (func_02105504() == 0) {
        return;
    }
    func_02111158(data_021759c0->mMode);
}

u32 func_0210e680(void) {
    u32 *p;
    u32 *q;
    u32 v;
    u32 a;
    u32 b;
    u32 ok;
    u32 n;

    NNS_SndArcSetCurrent(&data_0217c868);
    v = func_0210efcc(&data_0217d0a0, data_0216cb30, data_0217d130, 0);
    func_0210d990(1);
    if (v == 0) {
        return 0;
    }
    if (NNS_SndArcLoadSeqArc(1, data_0217d130) == 0) {
        return 0;
    }
    p = (u32 *) NNS_SndArcGetSeqArcInfo(1);
    q = (u32 *) NNS_SndArcGetSeqArcInfo(0);
    a = *p;
    b = *q;
    NNS_SndArcSetFileAddress(b, NNS_SndArcGetFileAddress(a));
    NNS_SndArcSetFileAddress(a, NULL);
    n = data_0217d178.mUnk_40;
    data_0217d178.mUnk_40 = n + 1;
    data_0217d178.mUnk_00[n] = b;
    if (NNS_SndArcLoadWaveArc(0x3e, data_0217d130) != 0) {
        p = (u32 *) NNS_SndArcGetWaveArcInfo(0x3e);
        q = (u32 *) NNS_SndArcGetWaveArcInfo(0x3d);
        b = ((NNSSndArcWaveArcInfo *) q)->mFileId;
        a = ((NNSSndArcWaveArcInfo *) p)->mFileId;
        NNS_SndArcSetFileAddress(b, NNS_SndArcGetFileAddress(a));
        NNS_SndArcSetFileAddress(a, NULL);
        ok = 1;
        n = data_0217d178.mUnk_40;
        data_0217d178.mUnk_40 = n + 1;
        data_0217d178.mUnk_00[n] = b;
    } else {
        ok = 0;
    }
    if (ok == 0) {
        return 0;
    }
    if (NNS_SndArcLoadWaveArc(1, data_0217d130) == 0) {
        ok = 0;
    } else if (NNS_SndArcLoadBankEx(0, 2, data_0217d130) == 0) {
        ok = 0;
    } else if (NNS_SndArcLoadSeqArc(0, data_0217d130) == 0) {
        ok = 0;
    } else {
        ok = 1;
    }
    if (ok == 0) {
        return 0;
    }
    if (func_0210ed20(1, 1) == 0) {
        return 0;
    }
    func_0210e4c8(func_02108950());
    return 1;
}

u32 func_0210e5e4(u32 a, u32 b) {
    Unk0210e524 c, d;
    Unk0215c380 v;
    u32 x;

    func_0202553c(b, &c);
    d = c;
    v.mUnk_00 = d.mUnk_01;
    v.mUnk_04 = d.mUnk_02;
    v.mUnk_08 = d.mUnk_03;
    NNS_SndArcSetCurrent(&data_0217d0a0);
    x = func_0210e98c(v, 1) != 0;
    if (x != 0) {
        x = func_02111158(a);
    }
    return x;
}

u32 func_0210e524(void) {
    Unk0215316c b, c;
    Unk0215c380 v;

    b = func_0202577c(0x29);
    b.mUnk_00[1] = func_0211127c();
    c = b;
    v.mUnk_00 = c.mUnk_00[1];
    v.mUnk_04 = c.mUnk_00[2];
    v.mUnk_08 = c.mUnk_00[3];
    NNS_SndArcSetCurrent(&data_0217d0a0);
    return func_0210e98c(v, 1) != 0;
}

u32 func_0210e50c(s32 a) {
    return NNS_SndArcLoadGroup(a, data_0217d130);
}

void func_0210e4ec(Unk0217c7b4 *p) {
    p->mUnk_00 = data_0215c398;
    p->mUnk_0c = 0xff00;
}

void func_0210e4c8(Unk0217c7b4 *p) {
    p->mUnk_0c = NNS_SndHeapSaveState(data_0217d130);
}

void func_0210e434(Unk0217c7b4 *p) {
    Unk0215c380 v = data_0215c380;

    if (v.mUnk_00 == p->mUnk_00.mUnk_00 && v.mUnk_04 == p->mUnk_00.mUnk_04 && v.mUnk_08 == p->mUnk_00.mUnk_08) {
        return;
    }
    NNS_SndHeapLoadState(data_0217d130, p->mUnk_0c);
    NNS_SndHeapGetCurrentLevel(data_0217d130);
    p->mUnk_00 = data_0215c38c;
}

u32 func_0210e3ec(Unk0217c7b4 *p, Unk0215c380 v) {
    if (v.mUnk_00 == p->mUnk_00.mUnk_00 && v.mUnk_04 == p->mUnk_00.mUnk_04 && v.mUnk_08 == p->mUnk_00.mUnk_08) {
        return 1;
    }
    return 0;
}

u32 func_0210e33c(Unk0217c7b4 *p, Unk0215c380 v) {
    if (v.mUnk_00 != 0xff && NNS_SndArcLoadSeq(v.mUnk_00, data_0217d130) == 0) {
        return 0;
    }
    if (v.mUnk_04 != 0xff && NNS_SndArcLoadBank(v.mUnk_04, data_0217d130) == 0) {
        return 0;
    }
    if (v.mUnk_08 != 0xff && NNS_SndArcLoadBank(v.mUnk_08, data_0217d130) == 0) {
        return 0;
    }
    p->mUnk_00 = v;
    return 1;
}
