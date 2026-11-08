#include "Main/Unknown/code_02086e8c.h"
#include "03/code_021b94b8.h"
#include "Main/Unknown/code_020adddc.h"
#include "Main/Unknown/code_02086058.h"

#include "code_0200eddc.h"
#include "code_02013740.h"
#include "code_02012b30.h"
#include "gx_load3d.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02079bcc.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02088338.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02077bc0.h"
#include "code_0214a748.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02077000.h"
#include "registers.h"

void func_0208784c(s32 a, s32 b) {
    u16 x;
    u16 y;
    u16 c;
    x = (b << 8) >> 16;
    y = (a << 8) >> 16;
    reg_G3_TEXCOORD = 0x60006;
    c = data_021659d4[2];
    reg_G3_VTX_16 = data_021659d4[0] | data_021659d4[1] << 16;
    reg_G3_VTX_16 = c;
    reg_G3_TEXCOORD = x << 16 | 6;
    c = data_021659d4[5];
    reg_G3_VTX_16 = data_021659d4[3] | data_021659d4[4] << 16;
    reg_G3_VTX_16 = c;
    reg_G3_TEXCOORD = y | x << 16;
    c = data_021659d4[8];
    reg_G3_VTX_16 = data_021659d4[6] | data_021659d4[7] << 16;
    reg_G3_VTX_16 = c;
    reg_G3_TEXCOORD = y | 0x60000;
    c = data_021659d4[11];
    reg_G3_VTX_16 = data_021659d4[9] | data_021659d4[10] << 16;
    reg_G3_VTX_16 = c;
}

#pragma thumb on

void func_020875b4(void) {
    void *v1;
    BOOL f;
    u16 i;
    s32 j;
    BOOL t;
    BOOL u;
    u32 v;
    Unk02086250 *q;
    s32 w;
    BOOL k;
    v1 = GetHeap(GetCurrentHeapCall());
    if (gRaceSetup->mMode == MODE_GRAND_PRIX) {
        f = TRUE;
    } else {
        f = FALSE;
    }
    data_0217aed0 = HeapAlloc(v1, 0x194);
    data_0217aed0->mUnk_184 = 0;
    data_0217aed0->mUnk_188 = NULL;
    if (IsRaceAwardOrStaffRoll() != 0) {
        data_0217aed0->mUnk_020 = 0;
    } else if (f == FALSE) {
        data_0217aed0->mUnk_020 = gRaceSetup->mKartCount - 1;
        for (i = 0; (u32) i < gRaceSetup->mKartCount; i++) {
            if (gRaceSetup->mCurrentEntries[i].mPlayer.mKind == PLAYER_KIND_GHOST &&
                gRaceSetup->mCurrentEntries[i].mPlayer.mUnk_10 == 0) {
                data_0217aed0->mUnk_020 = data_0217aed0->mUnk_020 - 1;
            }
        }
    } else {
        data_0217aed0->mUnk_020 = gRaceSetup->mHumanAndPeerKartCount;
        w = gRaceSetup->mEntryIndex;
        u = FALSE;
        if (w != -1) {
            v = gRaceSetup->mCurrentEntries[(u16) w].mPlayer.mKind;
            if (v <= 3 && ((1 << v) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) != 0) {
                u = TRUE;
            }
            if (u != FALSE) {
                data_0217aed0->mUnk_020 = data_0217aed0->mUnk_020 - 1;
            }
        }
    }
    data_0217aed8 = &data_02155a48;
    InitKartEmblemPointers();
    for (i = 0; (u32) i < gRaceSetup->mKartCount; i++) {
        data_0217aed0->mUnk_024[i] = i;
        data_0217aed0->mUnk_044[i] = i;
        data_0217aed0->mUnk_094[i] = i;
        data_0217aed0->mUnk_034[i] = 0;
        data_0217aed0->mUnk_084[i] = 0;
        data_0217aed0->mUnk_054[i] = 0;
        data_0217aed0->mUnk_0a4[i] = 0;
        data_0217aed0->mUnk_074[i] = i;
        data_0217aed0->mUnk_094[i] = i;
        data_0217aed0->mUnk_104[i] = 0;
        data_0217aed0->mUnk_000[i] = NULL;
        data_0217aed0->mUnk_0e4[i] = 0;
    }
    if (data_0217aed0->mUnk_020 > 0) {
        j = 0;
        for (i = 0; (u32) i < gRaceSetup->mKartCount; i++) {
            t = FALSE;
            if (f == FALSE) {
                if (i != gRaceSetup->mEntryIndex) {
                    if (gRaceSetup->mCurrentEntries[i].mPlayer.mKind != PLAYER_KIND_GHOST ||
                        gRaceSetup->mCurrentEntries[i].mPlayer.mUnk_10 != 0) {
                        t = TRUE;
                    }
                }
            } else {
                k = FALSE;
                v = gRaceSetup->mCurrentEntries[i].mPlayer.mKind;
                if (v <= 3 && ((1 << v) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) != 0) {
                    k = TRUE;
                }
                if (k != FALSE && i != gRaceSetup->mEntryIndex) {
                    t = TRUE;
                }
            }
            if (t != FALSE) {
                data_0217aed0->mUnk_000[i] = HeapAlloc(v1, 0x28);
                q = data_0217aed0->mUnk_000[i];
                func_02087508(q, i, v1);
                data_0217aed0->mUnk_0c4[j] = q;
                j++;
            } else {
                data_0217aed0->mUnk_000[i] = NULL;
            }
        }
    }
    reg_G3_MTX_MODE = 0;
    G3i_OrthoW_(0x60000, 0xfffa0000, 0xfff80000, 0x80000, 0, 0x1000, 0x200, 1, &data_0217aee0);
}

void func_02087508(Unk02086250 *a, u16 b, void *c) {
    a->mUnk_1c = HeapAlloc(c, 0x90);
    a->mUnk_00 = data_02155ccc;
    a->mUnk_0c = b;
    a->mUnk_1c->mUnk_00[0] = data_021659ec;
    a->mUnk_1c->mUnk_00[1] = data_02165a34;
    a->mUnk_1c->mUnk_00[2] = data_02165a10;
    a->mUnk_1c->mUnk_00[3] = data_02165a58;
    a->mUnk_10 = TRUE;
    a->mUnk_14 = 0;
    a->mUnk_18 = TRUE;
    a->mUnk_24 = 0;
    a->mUnk_26 = 0x7fff;
    a->mUnk_22 = 0;
    a->mUnk_20 = 0;
}

void SetTextureSizeFromBits(Unk02086098 *a) {
    u16 v;
    u16 w;
    s32 x;
    s32 y;
    v = a->mUnk_00 >> 23 & 7;
    w = a->mUnk_00 >> 20 & 7;
    switch (w) {
        case 0:
            x = 8;
            break;
        case 1:
            x = 0x11;
            break;
        case 2:
            x = 0x21;
            break;
        case 3:
            x = 0x41;
            break;
        case 4:
            x = 0x80;
            break;
        case 5:
            x = 0x100;
            break;
        case 6:
            x = 0x200;
            break;
        case 7:
            x = 0x400;
            break;
    }
    switch (v) {
        case 0:
            y = 8;
            break;
        case 1:
            y = 0x11;
            break;
        case 2:
            y = 0x21;
            break;
        case 3:
            y = 0x41;
            break;
        case 4:
            y = 0x80;
            break;
        case 5:
            y = 0x100;
            break;
        case 6:
            y = 0x200;
            break;
        case 7:
            y = 0x400;
            break;
    }
    a->mUnk_1c = x << 12;
    a->mUnk_20 = y << 12;
}

u16 GetKartPaletteColor(int a) {
    if (gRaceSetup->mMode == 5) {
        return data_02155a2c[gRaceSetup->mCurrentEntries[a].mPlayer.mUnk_25];
    }
    if (gRaceSetup->mUseTeams != 0) {
        return data_02155a28[gRaceSetup->mCurrentEntries[a].mPlayer.mTeamIndex];
    }
    if (GetKartModelsEntry(a)->mUnk_000 == 0xc) {
        return func_02077f7c(a)->mUnk_04;
    }
    return data_02155a64[a];
}

void func_020872a4(void) {
    u16 i;
    void *v1;
    Unk02086250 *p;
    Unk02086250_1c *q;
    Unk02086098 *e1;
    Unk02086098 *e3;
    v1 = GetHeap(GetCurrentHeapCall());
    UploadKartEmblems();
    data_0217aedc = 0;
    gKartEmblemPlltBuffer = HeapAllocAligned(v1, 0x20, -4);
    gKartEntryNameTexBuffer = HeapAllocAligned(v1, 0x100, -4);
    gKartEntryNamePlltBuffer = HeapAllocAligned(v1, 8, -4);
    data_0217aecc = HeapAllocAligned(v1, 0x200, -4);
    for (i = 0; i < data_0217aed0->mUnk_020; i++) {
        p = data_0217aed0->mUnk_0c4[i];
        q = p->mUnk_1c;
        e1 = &q->mUnk_00[1];
        e3 = &q->mUnk_00[3];
        q->mUnk_00[0].mTexByteCount = 0x200;
        q->mUnk_00[0].mPlttByteCount = 0x20;
        q->mUnk_00[0].mPlttData = data_0217aed0->mUnk_188;
        p->mUnk_26 = GetKartPaletteColor(p->mUnk_0c);
        SetupKartEmblemTexture(&q->mUnk_00[0], p->mUnk_0c);
        SetupKartEntryNameTexture(e1, p->mUnk_0c);
        SetPaletteKartColor(&q->mUnk_00[2], p->mUnk_0c);
        func_020870ec(e3, p->mUnk_0c);
        UploadTextureAndPalette(&q->mUnk_00[0]);
        UploadTextureAndPalette(e1);
        UploadTextureAndPalette(&p->mUnk_1c->mUnk_00[2]);
        if (e3->mTexData != NULL) {
            UploadTextureAndPalette(e3);
        }
    }
    HeapFree(v1, data_0217aecc);
    HeapFree(v1, gKartEntryNamePlltBuffer);
    HeapFree(v1, gKartEntryNameTexBuffer);
    HeapFree(v1, gKartEmblemPlltBuffer);
}

void SetupKartEmblemTexture(Unk02086098 *a, u16 b) {
    u16 *p;
    void *q;
    u16 v;
    p = gKartEmblemPlltBuffer;
    q = data_0217aed0->mEmblemTex[b];
    MI_CpuCopy8(data_0217aed0->mEmblemPltt[b], p, a->mPlttByteCount);
    v = 0x7fff;
    if (gRaceSetup->mUseTeams != 0) {
        v = data_02155a28[gRaceSetup->mCurrentEntries[b].mPlayer.mTeamIndex];
    }
    *p = v;
    DC_FlushRange(p, a->mPlttByteCount);
    DC_FlushRange(q, a->mTexByteCount);
    a->mPlttData = p;
    a->mTexData = q;
}

#pragma thumb off

#pragma thumb on

void SetupKartEntryNameTexture(Unk02086098 *a, u32 b) {
    u16 v1;
    u16 *v2;
    u8 *v3;
    v3 = gKartEntryNameTexBuffer;
    v2 = gKartEntryNamePlltBuffer;
    *v2 = (0x00007c00u);
    v1 = GetKartPaletteColor(b);
    v2[1] = v1;
    v2[2] = 0;
    v2[3] = 0x1f;
    DC_FlushRange(v2, 8);
    MI_CpuFill8(v3, 0, a->mTexByteCount);
    func_020adddc(b, v3, 1, 2);
    DC_FlushRange(v3, 0x100);
    a->mTexData = v3;
    a->mPlttData = v2;
}

void SetPaletteKartColor(Unk02086098 *a, u32 b) {
    u16 v1;
    u16 *v2;
    v2 = a->mPlttData;
    v1 = GetKartPaletteColor(b);
    v2[1] = v1;
    DC_FlushRange(v2, 8);
}

#pragma thumb off

#pragma thumb on

void func_020870ec(Unk02086098 *a, u16 b) {
    u8 *p;
    s32 c;
    u32 i;
    Unk02086098 *q;
    u8 v;
    u32 w;
    u8 x;
    u8 y;
    q = a;
    if (gRaceSetup->mCurrentEntries[b].mPlayer.mUnk_26 != 0) {
        p = data_0217aecc;
        c = 7;
        switch (gRaceSetup->mCurrentEntries[b].mPlayer.mUnk_26) {
            case 2:
                c = 4;
                break;
            case 3:
                c = -1;
                break;
        }
        MI_CpuCopy8(q->mTexData, p, q->mTexByteCount);
        if (c > 0) {
            for (i = 0; i < q->mTexByteCount; i++) {
                v = p[i];
                w = v & 0xf0;
                x = w >> 4;
                y = v & 0xf;
                if (y < c) {
                    v = w;
                }
                if (x < c) {
                    v = v & 0xf;
                }
                p[i] = v;
            }
        }
        DC_FlushRange(p, q->mTexByteCount);
        q->mTexData = p;
    } else {
        q->mTexData = NULL;
    }
}

void InitKartEmblemPointers(void) {
    u16 i;
    Nclr *o;
    NNSG3dResTex *p;
    char *s;
    u8 *q;
    u8 *r;
    for (i = 0; (u32) i < gRaceSetup->mKartCount; i++) {
        data_0217aed0->mEmblemTex[i] = NULL;
        data_0217aed0->mEmblemPltt[i] = NULL;
        if (gRaceSetup->mCurrentEntries[i].mPlayer.mUnk_24 == 0 || gRaceSetup->mUseTeams != 0) {
            if (gRaceSetup->mUseTeams != 0) {
                s = BuildTeamEmblemNsbtxPath(gRaceSetup->mCurrentEntries[i].mPlayer.mTeamIndex == 1 ? 1 : 0);
            } else {
                s = BuildEmblemNsbtxPath(gRaceSetup->mCurrentEntries[i].mCharacterIndex);
            }
            p = NNS_G3dGetTex(func_02047950(s));
            q = OFFSET_PTR(u8, p, p->mPlttInfo.mOfsPlttData);
            r = OFFSET_PTR(u8, p, p->mTexInfo.mOfsTex);
            data_0217aed0->mEmblemTex[i] = r;
            data_0217aed0->mEmblemPltt[i] = q;
        } else {
            r = (void *) gRaceSetup->mCurrentEntries[i].mPlayer.mEmblemData;
            LoadNclrData(&o, func_02047950(gEmblemSBNclrName));
            q = (u8 *) o->mData;
            data_0217aed0->mEmblemTex[i] = r;
            data_0217aed0->mEmblemPltt[i] = q;
        }
    }
}

void UploadKartEmblems(void) {
    u16 i;
    for (i = 0; (u32) i < gRaceSetup->mKartCount; i++) {
        UploadKartEmblem(i, data_0217aed0->mEmblemTex[i], data_0217aed0->mEmblemPltt[i]);
    }
}

// Replaces the pixels and palette of the kart_emblem texture of the model of kart a.
void UploadKartEmblem(u32 a, void *b, void *c) {
    u8 *p;
    u8 *q;
    u8 *r;
    u8 *e;
    s32 n;
    s32 h;
    u32 d;
    u32 f;
    p = GetKartModelResMdl((u16) a);
    n = NNS_G3dGetResDictIdxByName(p + *OFFSET_PTR(u32, p, 8) + 4, &data_02155a54);
    q = p + *OFFSET_PTR(u32, p, 8);
    r = q + 4;
    h = *(u16 *) (r + *OFFSET_PTR(u16, q, 0xa));
    e = q + *(u32 *) (r + *OFFSET_PTR(u16, q, 0xa) + h * n + 4);
    d = (*OFFSET_PTR(u32, e, 0x14) & 0xffff) << 3;
    f = *OFFSET_PTR(u16, e, 0x1c) << 4;
    DC_FlushRange(b, 0x200);
    DC_FlushRange(c, 0x20);
    GX_BeginLoadTex();
    GX_LoadTex(b, d, 0x200);
    GX_EndLoadTex();
    GX_BeginLoadTexPltt();
    GX_LoadTexPltt(c, f, 0x20);
    GX_EndLoadTexPltt();
}

void UploadTextureAndPalette(Unk02086098 *a) {
    u16 v;
    u32 d;
    v = a->mUnk_00 >> 26 & 7;
    d = (data_021619ec(a->mTexByteCount, 0, 0) & 0xffff) << 3;
    a->mUnk_00 = a->mUnk_00 & 0xffff0000;
    GX_BeginLoadTex();
    GX_LoadTex(a->mTexData, d, a->mTexByteCount);
    GX_EndLoadTex();
    a->mUnk_00 = a->mUnk_00 | (d >> 3 & 0xffff);
    if (a->mPlttByteCount != 0) {
        a->mPlttOffset = (data_021619f4(a->mPlttByteCount, v == 2, 0) & 0xffff) << 3;
        GX_BeginLoadTexPltt();
        GX_LoadTexPltt(a->mPlttData, a->mPlttOffset, a->mPlttByteCount);
        GX_EndLoadTexPltt();
    }
    SetTextureSizeFromBits(a);
}

#pragma thumb off
