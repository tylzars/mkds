#include "03/code_021c6f08.h"

#include "03/code_021c209c.h"
#include "03/code_021c6764.h"
#include "03/code_021cdbd0.h"
#include "03/code_021cea3c.h"
#include "03/code_021cef90.h"
#include "03/code_021cd2e0.h"
#include "03/unk_021da000.h"
#include "code_021510a4.h"
#include "03/code_021bf4dc.h"
#include "03/code_021bf000.h"
#include "03/code_021bf410.h"
#include "03/code_021c2000.h"
#include "03/code_021c9000.h"
#include "03/code_021c7d30.h"
#include "03/code_021d1dd0.h"
#include "03/unk_021d7000.h"
#include "code_0214b824.h"
#include "03/code_021c0fd8.h"
#include "03/code_021ce000.h"
#include "03/code_021c7000.h"
#include "03/code_021cd000.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d254c.h"
#include "03/code_021d27d8.h"
#include "03/code_021d2ecc.h"
#include "code_0213a460.h"
#include "code_0214d018.h"
#include "03/code_021c1000.h"
#include "03/unk_021d5000.h"
#include "03/code_021d1440.h"
#include "03/code_021bf810.h"
#include "03/code_021d1c18.h"
#include "string.h"
#include "code_02134398.h"

void CreateEditAddr(void) {
    Unk021d7310 a;
    u8 b[5];
    s32 c;
    EditAddr *d;
    a = data_ov003_021d7310;
    b[0] = data_ov003_021d7300[0];
    b[1] = data_ov003_021d7300[1];
    b[2] = data_ov003_021d7300[2];
    b[3] = data_ov003_021d7300[3];
    b[4] = data_ov003_021d7300[4];
    gEditAddr = func_ov003_021d283c(0x18, 4);
    func_ov003_021c20dc(&c, NULL);
    a.mUnk_00[c](gEditAddr->mText);
    d = gEditAddr;
    if (memcmp(d->mText, data_ov003_021d73ac, 3) != 0) {
        d->mGroupIndex = 3;
    } else {
        MI_CpuFill8(d->mText, 0, 0xc);
        gEditAddr->mGroupIndex = 0;
    }
    LoadEditAddrFilesAndSetBgCnt();
    LoadHlScr(c + 0xb);
    func_ov003_021bf43c(b[c], -1, 0);
    func_ov003_021bf5ec(2);
    gEditAddr->mUnk_00 = func_ov003_021d2288(0, 0);
    gEditAddr->mUnk_04 = func_ov003_021d1c18(0, 0x3f);
    gEditAddr->mUnk_04->mUnk_04 = (gEditAddr->mUnk_04->mUnk_04 & 0xfffff3ff) | 0xc00;
    func_ov003_021c7160();
    PrintEditAddrText();
    func_ov003_021c212c(func_ov003_021c7678);
}

void LoadEditAddrFilesAndSetBgCnt(void) {
    void *v2 = &gYbObjKbNclName2;
    void *v3 = &GX_LoadOBJPltt;
    u32 v4 = LoadFileToVram(v2, v3);
    void *v5 = &gJbBgStep3NcgName3;
    void *v6 = &GX_LoadBG2Char;
    u32 v7 = LoadFileToVram(v5, v6);
    void *v8 = &gYbBgStep3NclName3;
    void *v9 = &GX_LoadBGPltt;
    u32 v10 = LoadFileToVram(v8, v9);
    void *v11 = &gXb4EditAddrNscName;
    void *v12 = &GX_LoadBG2Scr;
    u32 v13 = LoadFileToVram(v11, v12);
    u32 v14 = 0x4001008u;
    u32 v15 = (*(u16 *) ((v14) + (0)));
    u32 v17 = ((v15) & ~(0x3u));
    u32 v18 = ((v17) | (0x3u));
    u32 v20;
    u32 v21;
    u32 v22;
    u32 v23;
    u32 v25;
    u32 v26;
    u32 v27;
    u32 v29;
    u32 v31;
    u32 v32;
    u32 v33;
    u32 v34;
    u32 v36;
    u32 v37;
    u32 v38;
    u32 v39;
    *(u16 *) ((v14) + (0)) = v18;
    v20 = 0x400100au;
    v21 = (*(u16 *) ((v20) + (0)));
    v22 = ((v21) & ~(0x3u));
    v23 = ((v22) | (0x3u));
    *(u16 *) ((v20) + (0)) = v23;
    v25 = 0x4000008u;
    v26 = (*(u16 *) ((v25) + (0)));
    v27 = ((v26) & ~(0x3u));
    v29 = ((v27) | (0x2u));
    *(u16 *) ((v25) + (0)) = v29;
    v31 = 0x400000au;
    v32 = (*(u16 *) ((v31) + (0)));
    v33 = ((v32) & ~(0x3u));
    v34 = ((v33) | (0x3u));
    *(u16 *) ((v31) + (0)) = v34;
    v36 = 0x400000cu;
    v37 = (*(u16 *) ((v36) + (0)));
    v38 = ((v37) & ~(0x3u));
    v39 = ((v38) | (0x3u));
    *(u16 *) ((v36) + (0)) = v39;
}

void func_ov003_021c7678(void) {
    func_ov003_021d1ee0(2, 1, 1, 8);
    func_ov003_021d1ee0(2, 0, 0x15, 8);
    func_ov003_021d2784(1, 1);
    func_ov003_021d2784(0, 0x15);
    func_ov003_021c212c(func_ov003_021c7614);
}

void func_ov003_021c7614(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if ((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) {
        CreateEditAddrKeyboard();
        StartSoundSeq(0x14);
        if (gEditAddr->mGroupIndex == 0) {
            SetEditAddrKeyboardRemoveCharEnabled(0);
            SetEditAddrKeyboardNextGroupEnabled(0);
        } else {
            v1 = func_ov003_021c735c(0x1a);
            if (v1 != 0) {
                SetEditAddrKeyboardAddCharEnabled(0);
            }
            SetEditAddrKeyboardNextGroupEnabled(0);
        }
        func_ov003_021c212c(func_ov003_021c75f8);
    }
}

void func_ov003_021c75f8(void) {
    if (GetEditAddrKeyboardInput() != 31) {
        func_ov003_021c212c(UpdateEditAddr);
    }
}

void UpdateEditAddr(void) {
    UpdateEditAddrInput();
    func_ov003_021c7358();
}

void UpdateEditAddrInput(void) {
    s32 a;
    u8 *b;
    s32 k;
    EditAddr *h;
    EditAddr **g;
    u8 e;
    a = GetEditAddrKeyboardInput();
    switch (a) {
        case 0:
            return;
        case 0x10:
            if (gEditAddr->mGroupIndex == 0 && gEditAddr->mText[2] == 0) {
                break;
            }
            StartSoundSeq(3);
            if (gEditAddr->mText[gEditAddr->mGroupIndex * 3 + 2] == 0) {
                gEditAddr->mGroupIndex--;
            }
            MI_CpuFill8(gEditAddr->mText + gEditAddr->mGroupIndex * 3, 0, 3);
            if (gEditAddr->mGroupIndex == 0 && gEditAddr->mText[2] == 0) {
                SetEditAddrKeyboardRemoveCharEnabled(0);
            }
            SetEditAddrKeyboardAddCharEnabled(1);
            SetEditAddrKeyboardNextGroupEnabled(0);
            break;
        case 0x11:
            e = gEditAddr->mGroupIndex;
            if (e >= 3) {
                break;
            }
            if (gEditAddr->mText[e * 3 + 2] == 0) {
                break;
            }
            StartSoundSeq(1);
            gEditAddr->mGroupIndex = gEditAddr->mGroupIndex + 1;
            SetEditAddrKeyboardNextGroupEnabled(0);
            break;
        case 0x12:
            gEditAddr->mUnk_15 = 0;
            StartSoundSeq(7);
            func_ov003_021c212c(func_ov003_021c733c);
            return;
        case 0x13:
            if (func_ov003_021c6f64() != FALSE) {
                StartSoundSeq(6);
                gEditAddr->mUnk_15 = 1;
            } else {
                gEditAddr->mUnk_15 = 2;
                StartSoundSeq(9);
            }
            gEditAddr->mGroupIndex = 3;
            gEditAddr->mUnk_04->mUnk_00 = (gEditAddr->mUnk_04->mUnk_00 & 0xc1fffcff) | 0x200;
            func_ov003_021c7160();
            func_ov003_021c7050();
            func_ov003_021c212c(func_ov003_021c733c);
            return;
        default:
            if (gEditAddr->mGroupIndex == 3) {
                if (func_ov003_021c735c(0x1a) != 0) {
                    break;
                }
            }
            StartSoundSeq(1);
            g = &gEditAddr;
            b = (*g)->mText;
            k = (*g)->mGroupIndex * 3;
            if (b[k + 2] == 0) {
                b[k + 2] = a;
            } else if (b[k + 1] == 0) {
                b[k + 1] = b[k + 2];
                b[k + 2] = a;
                if (func_ov003_021c735c(0x1a) != 0) {
                    h = gEditAddr;
                    if (h->mGroupIndex < 3) {
                        h->mGroupIndex = h->mGroupIndex + 1;
                    }
                }
            } else {
                b[k] = b[k + 1];
                b[k + 1] = b[k + 2];
                b[k + 2] = a;
                if ((*g)->mGroupIndex < 3) {
                    (*g)->mGroupIndex = (*g)->mGroupIndex + 1;
                }
            }
            SetEditAddrKeyboardRemoveCharEnabled(1);
            if (gEditAddr->mGroupIndex < 3) {
                SetEditAddrKeyboardNextGroupEnabled(1);
            } else {
                SetEditAddrKeyboardNextGroupEnabled(0);
            }
            if (gEditAddr->mGroupIndex == 3) {
                if (func_ov003_021c735c(0x1a) != 0) {
                    SetEditAddrKeyboardAddCharEnabled(0);
                }
            }
            break;
    }
    PrintEditAddrText();
    func_ov003_021c7160();
}

u32 func_ov003_021c735c(s32 a) {
    u8 b[4];
    u8 *c;
    u8 *d;
    s32 e;
    u8 f;
    d = gEditAddr->mText;
    c = d + gEditAddr->mGroupIndex * 3;
    f = *c;
    if (f != 0 && f != 0x20) {
        return 1;
    }
    MI_CpuCopy8(c, b, 3);
    b[3] = 0;
    c = b;
    for (e = 0; e < 3; e++) {
        if (*c != 0) {
            break;
        }
        *c = 0x20;
        c++;
    }
    if (StrtolBase10((const char *) b) >= a) {
        return 1;
    }
    return 0;
}

void func_ov003_021c7358(void) {}

void func_ov003_021c733c(void) {
    func_ov003_021d1dd0(8);
    func_ov003_021c212c(func_ov003_021c7314);
}

void func_ov003_021c7314(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (v1 == 0) {
        StartEditAddrKeyboardSlideOut();
        StartSoundSeq(0x15);
        func_ov003_021c212c(func_ov003_021c72a4);
    }
}

void func_ov003_021c72a4(void) {
    u8 a;
    if (HasEditAddrKeyboard() == 0) {
        a = gEditAddr->mUnk_15;
        if (a == 0) {
            func_ov003_021c212c(func_ov003_021c722c);
            return;
        }
        if (a == 2) {
            func_ov003_021cefc0(0x2f, 3, 1, -1, 0);
            func_ov003_021c212c(func_ov003_021c6f3c);
            return;
        }
        func_ov003_021cefc0(0x9b, 2, 1, -1, 0);
        func_ov003_021c212c(func_ov003_021c7118);
    }
}

void func_ov003_021c722c(void) {
    int v1[1];
    func_ov003_021bf410();
    func_ov003_021d2f00((u32 *) (u32) (gEditAddr->mUnk_04));
    func_ov003_021d2168(0);
    LoadFileToVram(&gYbObjMainNclName3, &GX_LoadOBJPltt);
    func_ov003_021d272c(1, 1);
    func_ov003_021d272c(0, 0x15);
    func_ov003_021c20dc(v1, NULL);
    if (3 <= v1[0]) {
        v1[0] = v1[0] + 1;
    }
    func_ov003_021c2120(2, 1);
    func_ov003_021c20f8(0, v1[0] + 3);
    func_ov003_021c212c(CreateJb3List);
    func_ov003_021d2808(&gEditAddr);
}

void PrintEditAddrText(void) {
    u16 a[6];
    s32 b;
    u8 *c;
    EditAddr *s;
    u16 d;
    a[0] = data_ov003_021d7308[0];
    a[1] = data_ov003_021d7308[1];
    a[2] = data_ov003_021d7308[2];
    a[3] = data_ov003_021d7308[3];
    a[2] = data_ov003_021d63f8[0];
    a[3] = data_ov003_021d63f8[1];
    func_ov003_021d2060(gEditAddr->mUnk_00, 0);
    b = 0;
    a[5] = 0;
    c = gEditAddrCharX;
    do {
        s = gEditAddr;
        a[4] = s->mText[b];
        d = *c;
        a[0] = d;
        func_ov003_021d2070(s->mUnk_00, d, a[1], a[2], a[3], 2, 0x480, &a[4]);
        c++;
        b++;
    } while (b < 12);
    func_ov003_021d1fd0(gEditAddr->mUnk_00);
}

void func_ov003_021c7160(void) {
    EditAddr *a;
    Unk021da1f8_04 *p;
    u32 t;
    s32 b;
    a = gEditAddr;
    b = a->mGroupIndex;
    if (b > 3) {
        b = 3;
    }
    p = a->mUnk_04;
    t = (gEditAddrCharX[b * 3 + 2] & 0x1ff) << 16;
    p->mUnk_00 = t | ((p->mUnk_00 & 0xfe00ff00) | 0x28);
}

void func_ov003_021c7118(void) {
    gEditAddr->mUnk_15 = func_ov003_021cef80();
    switch (gEditAddr->mUnk_15) {
        case 0:
            StartSoundSeq(7);
            break;
        case 1:
            StartSoundSeq(0xe);
            break;
        default:
            return;
    }
    func_ov003_021cef90();
    func_ov003_021c212c(func_ov003_021c70a4);
}

void func_ov003_021c70a4(void) {
    Unk021d7324 a;
    s32 b;
    a = data_ov003_021d7324;
    if (func_ov003_021cef6c() == 0) {
        if (gEditAddr->mUnk_15 == 0) {
            gEditAddr->mUnk_04->mUnk_00 = gEditAddr->mUnk_04->mUnk_00 & 0xc1fffcff;
            func_ov003_021c212c(func_ov003_021c7614);
            return;
        }
        func_ov003_021c20dc(&b, NULL);
        a.mUnk_00[b](gEditAddr->mText);
        func_ov003_021c212c(func_ov003_021c722c);
    }
}

void func_ov003_021c7050(void) {
    int v1;
    int v2;
    int v3;
    int v4;
    u8 v5;
    u8 v6;
    v1 = 0;
    v4 = 0;
    do {
        v2 = (s32) gEditAddr + 8 + v4;
        v3 = 0;
        do {
            v6 = *(s8 *) (v2 + v3);
            if (((v6 != '0') && (v6 != ' ')) && (v6 != 0)) {
                break;
            }
            if (v3 == 2) {
                v5 = 0x30;
            } else {
                v5 = 0x20;
            }
            *(u8 *) (v2 + v3) = v5;
            v3 = v3 + 1;
        } while (v3 < 3);
        v4 = v4 + 3;
        v1 = v1 + 1;
    } while (v1 < 4);
    PrintEditAddrText();
}

BOOL func_ov003_021c6f64(void) {
    u8 a[4];
    u8 *k;
    u8 *j;
    s32 c;
    s32 e;
    s32 d;
    u8 *i;
    s32 f;
    u8 b[4];
    BOOL g;
    s32 h;
    u8 *m;
    a[0] = gEditAddrGroupMax[0];
    a[1] = gEditAddrGroupMax[1];
    a[2] = gEditAddrGroupMax[2];
    a[3] = gEditAddrGroupMax[3];
    c = 0;
    d = 0;
    k = (u8 *) gEditAddr;
    do {
        j = k + 8 + d;
        if (*j != 0x20) {
            for (e = 0, i = a; e < 3; e++) {
                if (j[e] > *i) {
                    return FALSE;
                }
                if (j[e] < *i) {
                    break;
                }
                i++;
            }
        }
        d += 3;
        c++;
    } while (c < 4);
    k += 8;
    func_ov003_021cd2e0((char *) k, b);
    func_ov003_021c20dc(&f, NULL);
    if (f == 1) {
        g = FALSE;
        h = 0;
        m = b;
        do {
            for (e = 0; e < 8; e++) {
                if (g != FALSE) {
                    if ((*m & (1 << (7 - e))) != 0) {
                        return FALSE;
                    }
                } else if ((*m & (1 << (7 - e))) == 0) {
                    g = TRUE;
                }
            }
            m++;
            h++;
        } while (h < 4);
        return TRUE;
    }
    if (DWC_BACKUPlCheckAddress(b) != 0) {
        return TRUE;
    }
    return FALSE;
}

void func_ov003_021c6f3c(void) {
    int v1;
    v1 = func_ov003_021cef80();
    if (v1 == 0) {
        StartSoundSeq(6);
        func_ov003_021cef90();
        func_ov003_021c212c(func_ov003_021c6f08);
    }
}

void func_ov003_021c6f08(void) {
    int v1;
    v1 = func_ov003_021cef6c();
    if (v1 == 0) {
        gEditAddr->mUnk_04->mUnk_00 = gEditAddr->mUnk_04->mUnk_00 & (0xc1fffcffu);
        func_ov003_021c212c(func_ov003_021c7614);
    }
}
