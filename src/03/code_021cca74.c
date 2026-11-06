#include "03/code_021cca74.h"

#include "03/code_021cc000.h"
#include "03/code_021d1000.h"
#include "03/code_021d1790.h"
#include "03/unk_021da000.h"
#include "03/unk_021d6000.h"
#include "03/code_021d2940.h"
#include "03/code_021cdbd0.h"
#include "03/unk_021d7000.h"
#include "code_02147cd8.h"
#include "code_0212bcac.h"

u8 func_ov003_021cce6c(void) {
    return data_ov003_021da268->mOffset;
}

u8 func_ov003_021cce60(void) {
    return data_ov003_021da268->mUnk_1d;
}

void func_ov003_021cce58(s32 offset) {
    func_ov003_021cca74(offset);
}

void func_ov003_021cce48(void) {
    data_ov003_021da268->mUnk_1e = 0;
    return;
}

void func_ov003_021cce38(void) {
    data_ov003_021da268->mUnk_1e = 1;
    return;
}

void func_ov003_021ccd18(void) {
    data_ov003_021da268->mUnk_1d = 0;
    switch (data_ov003_021da268->mUnk_1c) {
        case 0:
            if (data_ov003_021da268->mUnk_1e == 0) {
                switch (func_ov003_021ccb50()) {
                    case 1:
                        if (data_ov003_021da268->mUnk_1b != 0) {
                            StartSoundSeq(0x16);
                            SetSoundSeqVolume(0);
                            data_ov003_021da268->mUnk_1d = 1;
                            func_ov003_021d2940(data_ov003_021da268->mUnk_14);
                            data_ov003_021da268->mUnk_18 = data_ov003_021da268->mOffset;
                            data_ov003_021da268->mUnk_1c = 1;
                        }
                        break;
                    case 2:
                        func_ov003_021ccc08(2);
                        break;
                    case 3:
                        func_ov003_021ccc08(3);
                        break;
                    case 4:
                        func_ov003_021ccbbc();
                        break;
                }
            }
            break;
        case 1:
            func_ov003_021ccc90();
            break;
        case 2:
            if (func_ov003_021ccb1c(2) != 2) {
                data_ov003_021da268->mUnk_1d = 5;
                data_ov003_021da268->mUnk_1c = 0;
            } else if (func_ov003_021ccb50() == 2) {
                func_ov003_021ccc08(2);
            }
            break;
        case 3:
            if (func_ov003_021ccb1c(3) != 3) {
                data_ov003_021da268->mUnk_1d = 7;
                data_ov003_021da268->mUnk_1c = 0;
            } else if (func_ov003_021ccb50() == 3) {
                func_ov003_021ccc08(3);
            }
            break;
    }
}

void func_ov003_021ccc90(void) {
    u16 a[2];
    s32 b;
    s32 c;
    if (func_ov003_021d2a80(&data_ov003_021d67e8) != 0) {
        func_ov003_021d2940(a);
        if (a[0] >= data_ov003_021da268->mX - 0x1e) {
            b = data_ov003_021da268->mUnk_18 + (a[1] - data_ov003_021da268->mUnk_14[1]);
            if (b < 0) {
                b = 0;
            } else {
                c = data_ov003_021da268->mUnk_19 - data_ov003_021d6630[data_ov003_021da268->mUnk_1b];
                if (b >= c) {
                    b = c;
                }
            }
            func_ov003_021ccc24(b);
            func_ov003_021cca74(b);
            data_ov003_021da268->mUnk_1d = 2;
            return;
        }
    }
    StopSoundSeq();
    data_ov003_021da268->mUnk_1c = 0;
    data_ov003_021da268->mUnk_1d = 3;
}

void func_ov003_021ccc24(s32 param_1) {
    s32 a = data_ov003_021da268->mOffset - param_1;
    u32 b;
    u32 c;
    if (a < 0) {
        a = -a;
    }
    if (a < 2) {
        b = 0;
    } else if (a < 6) {
        b = FX_DivS32(0x7f, 6 - a);
    } else {
        b = 0x7f;
    }
    SetSoundSeqVolume(b);
    if (a < 2) {
        c = -0x100;
    } else if (a < 6) {
        c = FX_DivS32(0x200, 6 - a) - 0x100;
    } else {
        c = 0x100;
    }
    SetSoundSeqTrackPitch(0xffff, c);
}

void func_ov003_021ccc08(int a) {
    u8 v1;
    data_ov003_021da268->mUnk_1c = (s8) a;
    if (a == 2) {
        v1 = 4;
    } else {
        v1 = 6;
    }
    data_ov003_021da268->mUnk_1d = v1;
    return;
}

void func_ov003_021ccbbc(void) {
    u16 a[2];
    u32 b;
    s32 c;
    s32 d;
    func_ov003_021d2940(a);
    b = data_ov003_021d6630[data_ov003_021da268->mUnk_1b];
    c = a[1] - data_ov003_021da268->mY - (b >> 1);
    if (c < 0) {
        c = 0;
    } else {
        d = data_ov003_021da268->mUnk_19 - b;
        if (c >= d) {
            c = d;
        }
    }
    func_ov003_021cca74(c);
    data_ov003_021da268->mUnk_1d = 3;
}

int func_ov003_021ccb50(void) {
    int v1;
    int v2;
    u8 v3[8];
    func_ov003_021cca9c(1, (void *) (v3));
    v1 = func_ov003_021d29e8((const Unk021d299c *) (u16 *) (void *) (v3));
    if (v1 != 0) {
        return 1;
    }
    v1 = 2;
    do {
        func_ov003_021cca9c(v1, (void *) (v3));
        v2 = func_ov003_021d29e8((const Unk021d299c *) (u16 *) (void *) (v3));
        if (v2 != 0) {
            return v1;
        }
        v1 = v1 + 1;
    } while (v1 <= 3);
    func_ov003_021cca9c(4, (void *) (v3));
    v1 = func_ov003_021d2a34((const Unk021d299c *) (u16 *) ((u16 *) (void *) (v3)));
    if (v1 != 0) {
        return 4;
    }
    return 0;
}

int func_ov003_021ccb1c(int a) {
    int v1;
    int v2;
    u8 v3[8];
    v2 = 2;
    do {
        func_ov003_021cca9c(v2, (void *) (v3));
        v1 = func_ov003_021d2a80((const Unk021d299c *) (u16 *) (void *) (v3));
        if (v1 != 0) {
            return v2;
        }
        v2 = v2 + 1;
    } while (v2 <= 3);
    return 0;
}

void func_ov003_021cca9c(s32 a, u16 *b) {
    b[0] = data_ov003_021da268->mX;
    b[2] = b[0] + 0xc;
    switch (a) {
        case 1:
            b[1] = data_ov003_021da268->mY + data_ov003_021da268->mOffset;
            b[3] = b[1] + data_ov003_021d6630[data_ov003_021da268->mUnk_1b];
            break;
        case 2:
            b[1] = data_ov003_021da268->mY - 0xd;
            b[3] = data_ov003_021da268->mY;
            break;
        case 3:
            b[1] = data_ov003_021da268->mY + data_ov003_021da268->mUnk_19;
            b[3] = b[1] + 0xd;
            break;
        case 4:
            b[1] = data_ov003_021da268->mY;
            b[3] = b[1] + data_ov003_021da268->mUnk_19;
            break;
    }
}

void func_ov003_021cca74(s32 offset) {
    Unk021cca74 *state = data_ov003_021da268;
    func_ov003_021d17d4(state->mResource, -1, state->mX, offset + state->mY);
    data_ov003_021da268->mOffset = offset;
}
