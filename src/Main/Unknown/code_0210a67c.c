#include "Main/Unknown/code_0210a67c.h"
#include "Main/Unknown/code_020d3c94.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"

#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_0210fad4.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_0210aa0c.h"
#include "Main/Unknown/code_0210aa14.h"
#include "Main/Unknown/code_02079b40.h"
#include "Main/Unknown/code_0210f000.h"
#include "Main/Unknown/code_0210faac.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_0210ab30.h"
#include "Main/Unknown/code_0210ab48.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0203c5ac.h"
#include "Main/Unknown/code_021053e4.h"
#include "Main/Unknown/code_0210bafc.h"
#include "Main/Unknown/code_0210c1b0.h"
#include "Main/Unknown/code_0211057c.h"
#include "Main/Unknown/code_02110590.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_020172d0.h"
#include "Main/Unknown/code_0210b564.h"
#include "Main/Unknown/code_0210b610.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_0210b6a0.h"
#include "code_02147cd8.h"

u32 func_0210b6a0(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 value12;
    value1 = 0xafc8000u;
    value0 = 0x384000u;
    value0 = FX_Div(value0, value1);
    value2 = (u32) &data_0217ccb0;
    value1 = 0xafc8000u;
    *(u32 *) ((value2) + (0)) = value0;
    value0 = 0x1c2000u;
    value0 = FX_Div(value0, value1);
    value3 = (u32) &data_0217ccbc;
    value2 = (u32) &data_0217ccb4;
    value12 = 0u;
    value1 = (u32) &data_0217ccb8;
    *(u32 *) ((value3) + (0)) = value0;
    *(u32 *) ((value2) + (0)) = value12;
    *(u32 *) ((value1) + (0)) = value12;
    return value0;
}

void func_0210b610(void) {
    s32 a;
    s32 b;
    s32 c;
    s64 d;

    a = *(u32 *) data_0217ccb8 + 0x1999;
    *(u32 *) data_0217ccb8 = a;
    b = a & 0xffff;
    c = gPairsByAngle[(b >> 4) * 2];
    d = (s64) c * 0x90000 + 0x800;
    *(u32 *) data_0217ccb8 = b;
    data_0217ccb4 = (s32) (d >> 12) >> 12;
}

void func_0210b564(SoundSource *a, int b, u32 c, u32 d, u32 e) {
    int v1;
    if ((a->mUnk_34 & 1) == 0) {
        return;
    }
    if (b == 2) {
        if ((0x00009c40u) < e) {
            StartSound(a, 0x70, 0x7f, 0);
            return;
        }
        if (e != 0) {
            StartSound(a, 0x6f, 0x7f, 0);
            return;
        }
    }
    v1 = func_0210bb74(b, c, d);
    if (v1 != 0xffff) {
        StartSound(a, v1, 0x7f, 0);
        return;
    }
}

void func_0210b4e0(Kart *a, s32 b, s32 c, s32 d) {
    u32 e;

    switch (a->mUnk_490) {
        case 0:
            e = 0xb2;
            break;
        case 1:
            e = 0xb9;
            break;
        case 2:
            e = 0xc0;
            break;
    }
    if (b != 0) {
        StartSoundWhileRequested(&a->mSoundSource, func_0210bb74(1, c, d), 0x5f, -0x345);
    }
    StartSoundWhileRequested(&a->mSoundSource, e, 0x7f, 0);
}

void func_0210b2a8(Kart *a, s32 b, s32 c, s32 d, u32 e) {
    Unk0206bcb0_A *p;
    s16 f;
    s32 g;
    BOOL h;
    s16 w;
    u32 i;
    s32 j;
    s32 k;
    u32 m;
    u32 n;

    if (!(a->mSoundSource.mUnk_34 & 1)) {
        return;
    }
    if (a->mUnk_4c & 0x10000000) {
        return;
    }
    p = &a->mUnk_450;
    f = p->mUnk_08 >> 12;
    if (f > 0x1fc) {
        g = 0x7f;
    } else {
        g = f >> 2;
    }
    if (b == 1) {
        if (e != 0) {
            f = f + 0x1c0;
        } else {
            f = (s16) (f - 0x7d0) >> 2;
        }
    }
    if (e != 0) {
        w = 0;
        h = a->mIndex == gRaceSetup->mEntryIndex;
        if (e > 0x11170) {
            w = 0x384;
            if (h != FALSE) {
                w += data_0217ccb4;
            }
        } else if (e > 0x61a8 && e <= 0x11170) {
            w = ((s32) ((((s64) data_0217ccb0 * (s32) ((e - 0x61a8) << 12)) + 0x800) >> 12)) >> 12;
            if (h != FALSE) {
                w += data_0217ccb4 >> 1;
            }
        }
        StartSoundWhileRequested(&a->mSoundSource, 0x74, g & 0xff, (s16) (f - w));
    } else {
        i = func_0210bb74(b, c, d);
        if (i == 0xffff) {
            return;
        }
        switch (i) {
            case 0xffd0:
            case 0xffd1:
                m = i & 1;
                j = GetKartLapProgress(a->mIndex);
                k = j - p->mUnk_28;
                if (k < 0) {
                    k = -k;
                }
                if (k > GetLapProgressSoundGap(m)) {
                    n = GetLapProgressSoundId(m);
                    p->mUnk_2c++;
                    StartSound(&a->mSoundSource, (u16) ((p->mUnk_2c & 1) + n), 0x7f, 0);
                    p->mUnk_28 = j;
                }
                break;
            default:
                StartSoundWhileRequested(&a->mSoundSource, i, g & 0xff, f);
                break;
        }
    }
}

void func_0210b234(Kart *a, s32 b, s32 c, s32 d, s32 f) {
    u32 e;

    if (!(a->mSoundSource.mUnk_34 & 1)) {
        return;
    }
    e = func_0210bafc(b, c, d);
    if (e == 0xffff) {
        return;
    }
    if (gRaceSetup->mCourseId == COURSE_ID_RAINBOW) {
        e = 0x1b6;
    }
    StartSound(&a->mSoundSource, e, 0x7f, 0);
}

void func_0210b198(s32 a, s32 b, u32 c, s32 d, s32 e) {
    NNSSndSeqPlayer *h;
    u16 f;

    if (func_02105504() == 0) {
        return;
    }
    NNS_SndHandleInit(&h);
    f = a * 0xe + b;
    if (h != NULL) {
        NNS_SndPlayerStopSeq(&h, 0);
    }
    NNS_SndArcPlayerStartSeqArcEx(&h, d, -1, e, 2, f);
    SetSndHandleTrackVolume(&h, c);
    NNS_SndHandleReleaseSeq(&h);
}

void func_0210b12c(Kart *a, s32 b, s16 d) {
    PlayingSound *p;
    s32 c;

    c = b + 0xc1;
    if (gSceneSoundState.mRaceFrames < 0x78) {
        return;
    }
    p = StartSoundEx(&a->mSoundSource, 0, c, 0x7f, 0);
    if (p == NULL) {
        return;
    }
    p->mUnk_19 |= 0x20;
    p->mUnk_19 |= 0x40;
}

void func_0210af40(Kart *a, s32 b, s32 c) {
    NNSSndSeqPlayer *h;
    Unk0206bcb0_A *p;
    u32 d;
    s32 e;
    BOOL f;
    u16 g;
    s32 x;
    s32 y;

    d = gSceneSoundState.mRaceFrames;
    if (!(a->mSoundSource.mUnk_34 & 1)) {
        return;
    }
    p = &a->mUnk_450;
    if (a->mUnk_4c & 0x10000000) {
        return;
    }
    if (a->mUnk_7c & KART_7C_ENTRY_KIND_2) {
        return;
    }
    if (gSceneSoundState.mRaceState != 1) {
        if (gSceneSoundState.mRaceState != 0) {
            return;
        }
        e = 0x7f;
        f = a->mIndex == gRaceSetup->mEntryIndex;
        if (c == 5) {
            e = 0x7f;
        } else if (c == 3) {
            e = 0x7f;
        }
        if (f != FALSE) {
            if (func_02105504() == 0) {
                return;
            }
            NNS_SndHandleInit(&h);
            g = b * 0xe + c;
            if (h != NULL) {
                NNS_SndPlayerStopSeq(&h, 0);
            }
            NNS_SndArcPlayerStartSeqArcEx(&h, 1, -1, 0x7f, 2, g);
            SetSndHandleTrackVolume(&h, e);
            NNS_SndHandleReleaseSeq(&h);
        } else {
            if (c != 3 && c != 5) {
                return;
            }
            StartSoundEx(&a->mSoundSource, 2, b * 0xe + (c + 1), 0x73, 0);
        }
    } else {
        x = 0xf0;
        y = 0x1e;
        if (c == 1 || c == 2) {
            x = 0x3c;
            y = 0;
        }
        if (d < x) {
            return;
        }
        if (d - p->mUnk_30 < y) {
            return;
        }
        StartSoundEx(&a->mSoundSource, 2, b * 0xe + c, 0x7f, 0);
        p->mUnk_30 = d;
    }
}

void func_0210aefc(void) {
    s32 i;
    Unk0217ccc0 *q = &data_0217ccc0;

    q->mUnk_60 = 0;
    q->mUnk_64 = FALSE;
    for (i = 0; i < 8; i++) {
        q->mUnk_00[i] = NULL;
        q->mUnk_40[i] = 0;
    }
    q->mUnk_68 = 0x5f;
    q->mUnk_6c = -1;
}

void func_0210add4(void) {
    Unk0217ccc0 *q = &data_0217ccc0;
    s32 i;

    if (q->mUnk_64 != FALSE) {
        return;
    }
    if (q->mUnk_6c != -1) {
        q->mUnk_6c++;
        if (q->mUnk_6c >= 0x19) {
            q->mUnk_6c = -1;
        }
        return;
    }
    for (i = 0; i < 8; i++) {
        if (q->mUnk_00[i] == NULL) {
            continue;
        }
        if (q->mUnk_40[i] == 0) {
            if (i != 0 && q->mUnk_40[i - 1] < 0x14) {
                continue;
            }
            if (i != 0 && q->mUnk_40[i - 1] == 0x14) {
                q->mUnk_68 -= 0xf;
            } else {
                q->mUnk_68 = 0x5f;
            }
            if (q->mUnk_68 < 0x1e) {
                q->mUnk_68 = 0x1e;
            }
            func_0210abf4(q->mUnk_00[i], q->mUnk_20[i], 0, q->mUnk_68);
            q->mUnk_40[i]++;
        } else {
            q->mUnk_40[i]++;
        }
    }
}

void func_0210ad58(Kart *a, s32 b) {
    Unk0217ccc0 *q = &data_0217ccc0;

    if (q->mUnk_64 != FALSE) {
        return;
    }
    if (a->mIndex == gRaceSetup->mEntryIndex) {
        func_0210abf4(a, b, 1, 0x6e);
        q->mUnk_6c = 0;
        return;
    }
    q->mUnk_00[q->mUnk_60] = a;
    q->mUnk_20[q->mUnk_60] = b;
    q->mUnk_60++;
}

void func_0210abf4(Kart *a, s32 b, s32 c, s32 d) {
    NNSSndSeqPlayer *h;
    PlayingSound *p;
    PlayingSound *q;
    BOOL e;
    u16 f;
    enum { K0 } k;

    p = a->mSoundSource.mPlayingSounds.mHead;
    if (p != NULL) {
        do {
            if (p->mUnk_18 == 2) {
                q = p;
                p = NNS_FndGetNextListObject(&a->mSoundSource.mPlayingSounds, p);
                StopPlayingSound(&a->mSoundSource, q, 0);
            } else {
                p = NNS_FndGetNextListObject(&a->mSoundSource.mPlayingSounds, p);
            }
        } while (p != NULL);
    }
    e = TRUE;
    if (data_0217d084.mUnk_04 != 2 && data_0217d084.mUnk_04 != 3) {
        e = FALSE;
    }
    if (e == FALSE) {
        return;
    }
    k = 0xd;
    if (c != 0) {
        StartSoundEx(&a->mSoundSource, 2, b * 0xe + k, 0x7f, 0);
        return;
    }
    if (func_02105504() == 0) {
        return;
    }
    NNS_SndHandleInit(&h);
    f = b * 0xe + k;
    if (h != NULL) {
        NNS_SndPlayerStopSeq(&h, 0);
    }
    NNS_SndArcPlayerStartSeqArcEx(&h, -1, -1, 0x6e, 2, f);
    SetSndHandleTrackVolume(&h, d);
    NNS_SndHandleReleaseSeq(&h);
}

void func_0210ab48(s32 a, s32 b) {
    NNSSndSeqPlayer *h;
    s32 c;
    u16 d;

    c = b != 0 ? 0xc : 0xd;
    data_0217ccc0.mUnk_64 = TRUE;
    if (func_02105504() == 0) {
        return;
    }
    NNS_SndHandleInit(&h);
    d = a * 0xe + c;
    if (h != NULL) {
        NNS_SndPlayerStopSeq(&h, 0);
    }
    NNS_SndArcPlayerStartSeqArcEx(&h, 7, -1, -1, 2, d);
    SetSndHandleTrackVolume(&h, 0x6e);
    NNS_SndHandleReleaseSeq(&h);
}

void func_0210ab44(Kart *a, PlayingSound *b, s32 c) {}

void func_0210ab40(Kart *a, PlayingSound *b, s32 c) {}

void func_0210ab30(Kart *a) {
    a->mSoundSource.mUnk_2c = (void (*)(void *, void *, u32)) func_0210ab40;
}

void func_0210aa14(Kart *a, PlayingSound *b, s32 c) {
    u32 d;
    u32 e;
    s32 f;
    NNSSndSeqParam *p;
    u32 g;

    d = b->mUnk_18;
    e = b->mSoundId;
    f = -1;
    if (a->mIndex == gRaceSetup->mEntryIndex) {
        p = NNS_SndArcGetSeqArcParam(d, e);
        g = p->mPlayerNo;
        if (g == 2) {
            f = 4;
        } else if (g == 3) {
            f = 5;
        } else if (g == 6) {
            if (func_0210fad4() != 0 || IsKartNear() != 0) {
                f = 7;
            }
        }
    }
    if ((b->mUnk_19 & 0x20) && (b->mUnk_19 & 0x40)) {
        g = GetKartVariant(a->mIndex) + 0x2d;
        NNS_SndArcPlayerStartSeqArcEx(&b->mUnk_00, f, g, c, d, e);
        if (b == NULL) {
            return;
        }
        NNS_SndPlayerWriteVariable(&b->mUnk_00, 0, a->mUnk_4b8);
    } else {
        NNS_SndArcPlayerStartSeqArcEx(&b->mUnk_00, f, -1, c, d, e);
    }
}

u32 func_0210aa0c(void) {
    return 0x0u;
}

void func_0210a880(Kart *a, PlayingSound *b, s32 c) {
    s32 d;
    u32 e;
    u32 f;
    BOOL g;
    s16 w;

    e = b->mVolume;
    d = c + a->mUnk_48c(&a->mUnk_518);
    if (b->mUnk_18 != 2) {
        f = a->mUnk_500;
        w = 0;
        g = a->mIndex == gRaceSetup->mEntryIndex;
        if (f > 0x11170) {
            w = 0x384;
            if (g != FALSE) {
                w += data_0217ccb4;
            }
        } else if (f > 0x61a8 && f <= 0x11170) {
            w = ((s32) ((((s64) data_0217ccb0 * (s32) ((f - 0x61a8) << 12)) + 0x800) >> 12)) >> 12;
            if (g != FALSE) {
                w += data_0217ccb4 >> 1;
            }
        }
        d -= w;
    } else {
        f = a->mUnk_500;
        w = 0;
        if (f > 0x11170) {
            w += data_0217ccb4;
        } else if (f > 0x61a8 && f <= 0x11170) {
            w += data_0217ccb4;
        }
        d -= w;
    }
    SetSndHandleTrackVolume(&b->mUnk_00, e);
    SetSndHandleTrackPitch(&b->mUnk_00, b->mUnk_14 + d);
}

void func_0210a77c(Kart *a, PlayingSound *b) {
    Vec3 *o;
    u32 c;
    s32 v;
    s16 w;
    u32 m;
    s32 t;

    v = 0;
    c = b->mVolume;
    if (a->mUnk_44 == 0) {
        o = (Vec3 *) &a->mUnk_168.y;
    } else {
        o = (Vec3 *) &a->mUnk_250.z;
    }
    v += o->z;
    t = GetHeightAboveWaterOrEfct(a->mTurnedForward.y);
    if (t < 0) {
        m = -t;
        w = 0;
        if (m > 0x11170) {
            w = 0x1c2;
            w += data_0217ccb4;
        } else if (m > 0x61a8 && m <= 0x11170) {
            w = ((s32) ((((s64) data_0217ccbc * (s32) ((m - 0x61a8) << 12)) + 0x800) >> 12)) >> 12;
            w += data_0217ccb4 >> 1;
        }
        v -= w;
    }
    SetSndHandleTrackVolume(&b->mUnk_00, c);
    SetSndHandleTrackPitch(&b->mUnk_00, b->mUnk_14 + v);
}

void func_0210a76c(Kart *a, PlayingSound *b) {
    func_0210a880(a, b, 0);
}

void func_0210a724(Kart *a, PlayingSound *b) {
    u32 c;
    s32 v;

    c = b->mUnk_19;
    v = 0;
    if (!(c & 0x10) && gSceneSoundState.mRaceFrames > a->mUnk_450.mUnk_34 + 1) {
        v = 0x180;
        if (c & 0x80) {
            v += 0x100;
        }
    }
    func_0210a880(a, b, v);
}

void func_0210a6ec(Kart *a, PlayingSound *b) {
    u32 c;

    c = a->mUnk_4c;
    SetSndHandleTrackVolume(&b->mUnk_00, b->mVolume);
    SetSndHandleTrackPitch(&b->mUnk_00, b->mUnk_14 + c);
}

void func_0210a6b4(Kart *a, PlayingSound *b) {
    u32 c;

    c = a->mUnk_4c;
    SetSndHandleTrackVolume(&b->mUnk_00, b->mVolume);
    SetSndHandleTrackPitch(&b->mUnk_00, b->mUnk_14 + c);
}

void func_0210a67c(Kart *a, PlayingSound *b) {
    s32 c;

    c = (s32) a->mTowardTurnCounter;
    SetSndHandleTrackVolume(&b->mUnk_00, b->mVolume);
    SetSndHandleTrackPitch(&b->mUnk_00, b->mUnk_14 + c);
}
