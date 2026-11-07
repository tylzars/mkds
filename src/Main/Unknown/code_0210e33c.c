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

const SoundSet data_0215c38c = {0xff, 0xff, 0xff};
const SoundSet data_0215c380 = {0xff, 0xff, 0xff};
const SoundSet data_0215c398 = {0xff, 0xff, 0xff};

void ReleaseLoadedSoundSet(void) {
    ReleaseSoundSet(func_02108950());
}

// Loads wave archives 0 and 0x50 (taken from archives 0x61 and 0x62 when b is set), assigns bank 0's wave archives to
// it, then loads group a.
u32 func_0210ed20(u32 a, u32 b) {
    NNSSndArcBankInfo *p;
    NNSSndArcWaveArcInfo *q;
    Unk02021968 *r;
    u32 v;
    u32 w;
    Unk02021968 *x;
    u32 ok;
    u32 n;
    s32 i;

    if (b != 0) {
        if (NNS_SndArcLoadWaveArc(0x61, data_0217d130) == 0) {
            ok = 0;
        } else {
            NNSSndArcWaveArcInfo *q;
            NNSSndArcWaveArcInfo *r;
            u32 v;
            u32 w;

            q = NNS_SndArcGetWaveArcInfo(0x61);
            r = NNS_SndArcGetWaveArcInfo(0);
            w = (r)->mFileId;
            v = q->mFileId;
            NNS_SndArcSetFileAddress(w, NNS_SndArcGetFileAddress(v));
            NNS_SndArcSetFileAddress(v, NULL);
            ok = 1;
            n = data_0217d178.mCount;
            data_0217d178.mCount = n + 1;
            data_0217d178.mFileIds[n] = w;
        }
        if (ok == 0) {
            return 0;
        }
        if (NNS_SndArcLoadWaveArc(0x62, data_0217d130) == 0) {
            ok = 0;
        } else {
            NNSSndArcWaveArcInfo *q;
            NNSSndArcWaveArcInfo *r;
            u32 v;
            u32 w;

            q = NNS_SndArcGetWaveArcInfo(0x62);
            r = NNS_SndArcGetWaveArcInfo(0x50);
            w = (r)->mFileId;
            v = q->mFileId;
            NNS_SndArcSetFileAddress(w, NNS_SndArcGetFileAddress(v));
            NNS_SndArcSetFileAddress(v, NULL);
            ok = 1;
            n = data_0217d178.mCount;
            data_0217d178.mCount = n + 1;
            data_0217d178.mFileIds[n] = w;
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
    x = NNS_SndArcGetFileAddress(p->mFileId);
    for (i = 0; i < 4; i++) {
        v = p->mWaveArcNo[i];
        if (v == 0xffff) {
            continue;
        }
        q = NNS_SndArcGetWaveArcInfo(v);
        if (q == NULL) {
            break;
        }
        w = q->mFileId;
        r = NNS_SndArcGetFileAddress(w);
        if (x == NULL) {
            continue;
        }
        if (r == NULL) {
            continue;
        }
        SND_AssignWaveArc(x, i, r);
    }
    if (LoadSndGroup(a) == 0) {
        return 0;
    }
    return 1;
}

// Releases the loaded set and loads v unless it is empty or already loaded; d adds extra wave archives for some sets.
u32 LoadSoundSetIfChanged(SoundSet v, u32 d) {
    Unk0217d134 *p;
    u32 ok;
    u32 n;
    s32 i;
    Unk0217d134 *t;

    if (v.mSeqId == 0xff && v.mUnk_04 == 0xff && v.mUnk_08 == 0xff) {
        return 1;
    }
    if (IsSoundSetLoaded(func_02108950(), v) != 0) {
        return 1;
    }
    ReleaseSoundSet(func_02108950());
    p = &data_0217d134;
    for (i = 0; i < p->mCount; i++) {
        NNS_SndArcSetFileAddress(p->mFileIds[i], NULL);
    }
    t = &data_0217d134;
    for (i = 0; i < 16; i++) {
        t->mFileIds[i] = 0;
    }
    t->mCount = 0;
    if (d != 0) {
        switch (v.mSeqId) {
            case 0x4a:
                if (NNS_SndArcLoadWaveArc(0x63, data_0217d130) == 0) {
                    ok = 0;
                } else {
                    NNSSndArcWaveArcInfo *p;
                    NNSSndArcWaveArcInfo *q;
                    u32 a;
                    u32 b;

                    p = NNS_SndArcGetWaveArcInfo(0x63);
                    q = NNS_SndArcGetWaveArcInfo(0x31);
                    b = q->mFileId;
                    a = p->mFileId;
                    NNS_SndArcSetFileAddress(b, NNS_SndArcGetFileAddress(a));
                    NNS_SndArcSetFileAddress(a, NULL);
                    ok = 1;
                    n = data_0217d134.mCount;
                    data_0217d134.mCount = n + 1;
                    data_0217d134.mFileIds[n] = b;
                }
                if (ok == 0) {
                    return 0;
                }
                break;
            case 0x2b:
                if (NNS_SndArcLoadWaveArc(0x64, data_0217d130) == 0) {
                    ok = 0;
                } else {
                    NNSSndArcWaveArcInfo *p;
                    NNSSndArcWaveArcInfo *q;
                    u32 a;
                    u32 b;

                    p = NNS_SndArcGetWaveArcInfo(0x64);
                    q = NNS_SndArcGetWaveArcInfo(0x58);
                    b = q->mFileId;
                    a = p->mFileId;
                    NNS_SndArcSetFileAddress(b, NNS_SndArcGetFileAddress(a));
                    NNS_SndArcSetFileAddress(a, NULL);
                    ok = 1;
                    n = data_0217d134.mCount;
                    data_0217d134.mCount = n + 1;
                    data_0217d134.mFileIds[n] = b;
                }
                if (ok == 0) {
                    return 0;
                }
                break;
            case 0xf:
                if (NNS_SndArcLoadWaveArc(0x34, data_0217d130) == 0) {
                    ok = 0;
                } else {
                    NNSSndArcWaveArcInfo *p;
                    NNSSndArcWaveArcInfo *q;
                    u32 a;
                    u32 b;

                    p = NNS_SndArcGetWaveArcInfo(0x34);
                    q = NNS_SndArcGetWaveArcInfo(0x33);
                    b = q->mFileId;
                    a = p->mFileId;
                    NNS_SndArcSetFileAddress(b, NNS_SndArcGetFileAddress(a));
                    NNS_SndArcSetFileAddress(a, NULL);
                    ok = 1;
                    n = data_0217d134.mCount;
                    data_0217d134.mCount = n + 1;
                    data_0217d134.mFileIds[n] = b;
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
                NNSSndArcWaveArcInfo *p;
                NNSSndArcWaveArcInfo *q;
                u32 a;
                u32 b;

                p = NNS_SndArcGetWaveArcInfo(0x13);
                q = NNS_SndArcGetWaveArcInfo(0x12);
                b = q->mFileId;
                a = p->mFileId;
                NNS_SndArcSetFileAddress(b, NNS_SndArcGetFileAddress(a));
                NNS_SndArcSetFileAddress(a, NULL);
                ok = 1;
                n = data_0217d134.mCount;
                data_0217d134.mCount = n + 1;
                data_0217d134.mFileIds[n] = b;
            }
            if (ok == 0) {
                return 0;
            }
        }
    }
    return LoadSoundSet(func_02108950(), v) != 0;
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
    SaveSndHeapState(func_02108950());
}

void LoadSceneSoundSet(Unk0210e524 a, u32 b) {
    SoundSet v;

    v.mSeqId = a.mUnk_01;
    v.mUnk_04 = a.mUnk_02;
    v.mUnk_08 = a.mUnk_03;
    LoadSoundSetIfChanged(v, b);
    if (func_02105504() == 0) {
        return;
    }
    func_02111158(gRaceSetup->mMode);
}

u32 LoadSndDataFromFile(void) {
    NNSSndArcSeqArcInfo *p;
    NNSSndArcSeqArcInfo *q;
    NNSSndArcWaveArcInfo *v1;
    NNSSndArcWaveArcInfo *v2;
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
    p = NNS_SndArcGetSeqArcInfo(1);
    q = NNS_SndArcGetSeqArcInfo(0);
    a = p->mFileId;
    b = q->mFileId;
    NNS_SndArcSetFileAddress(b, NNS_SndArcGetFileAddress(a));
    NNS_SndArcSetFileAddress(a, NULL);
    n = data_0217d178.mCount;
    data_0217d178.mCount = n + 1;
    data_0217d178.mFileIds[n] = b;
    if (NNS_SndArcLoadWaveArc(0x3e, data_0217d130) != 0) {
        v1 = NNS_SndArcGetWaveArcInfo(0x3e);
        v2 = NNS_SndArcGetWaveArcInfo(0x3d);
        b = v2->mFileId;
        a = v1->mFileId;
        NNS_SndArcSetFileAddress(b, NNS_SndArcGetFileAddress(a));
        NNS_SndArcSetFileAddress(a, NULL);
        ok = 1;
        n = data_0217d178.mCount;
        data_0217d178.mCount = n + 1;
        data_0217d178.mFileIds[n] = b;
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
    SaveSndHeapState(func_02108950());
    return 1;
}

u32 LoadCourseSoundSet(u32 a, u32 b) {
    Unk0210e524 c, d;
    SoundSet v;
    u32 x;

    func_0202553c(b, &c);
    d = c;
    v.mSeqId = d.mUnk_01;
    v.mUnk_04 = d.mUnk_02;
    v.mUnk_08 = d.mUnk_03;
    NNS_SndArcSetCurrent(&data_0217d0a0);
    x = LoadSoundSetIfChanged(v, 1) != 0;
    if (x != 0) {
        x = func_02111158(a);
    }
    return x;
}

u32 func_0210e524(void) {
    Unk0215316c b, c;
    SoundSet v;

    b = func_0202577c(0x29);
    b.mUnk_00[1] = func_0211127c();
    c = b;
    v.mSeqId = c.mUnk_00[1];
    v.mUnk_04 = c.mUnk_00[2];
    v.mUnk_08 = c.mUnk_00[3];
    NNS_SndArcSetCurrent(&data_0217d0a0);
    return LoadSoundSetIfChanged(v, 1) != 0;
}

u32 LoadSndGroup(s32 a) {
    return NNS_SndArcLoadGroup(a, data_0217d130);
}

void ResetLoadedSoundSet(LoadedSoundSet *p) {
    p->mSoundSet = data_0215c398;
    p->mHeapState = 0xff00;
}

void SaveSndHeapState(LoadedSoundSet *p) {
    p->mHeapState = NNS_SndHeapSaveState(data_0217d130);
}

// Restores the heap to the state saved before the set was loaded.
void ReleaseSoundSet(LoadedSoundSet *p) {
    SoundSet v = data_0215c380;

    if (v.mSeqId == p->mSoundSet.mSeqId && v.mUnk_04 == p->mSoundSet.mUnk_04 && v.mUnk_08 == p->mSoundSet.mUnk_08) {
        return;
    }
    NNS_SndHeapLoadState(data_0217d130, p->mHeapState);
    NNS_SndHeapGetCurrentLevel(data_0217d130);
    p->mSoundSet = data_0215c38c;
}

u32 IsSoundSetLoaded(LoadedSoundSet *p, SoundSet v) {
    if (v.mSeqId == p->mSoundSet.mSeqId && v.mUnk_04 == p->mSoundSet.mUnk_04 && v.mUnk_08 == p->mSoundSet.mUnk_08) {
        return 1;
    }
    return 0;
}

u32 LoadSoundSet(LoadedSoundSet *p, SoundSet v) {
    if (v.mSeqId != 0xff && NNS_SndArcLoadSeq(v.mSeqId, data_0217d130) == 0) {
        return 0;
    }
    if (v.mUnk_04 != 0xff && NNS_SndArcLoadBank(v.mUnk_04, data_0217d130) == 0) {
        return 0;
    }
    if (v.mUnk_08 != 0xff && NNS_SndArcLoadBank(v.mUnk_08, data_0217d130) == 0) {
        return 0;
    }
    p->mSoundSet = v;
    return 1;
}
