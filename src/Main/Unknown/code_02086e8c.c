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

void func_0208784c(s32 texWidthFixed, s32 texHeightFixed) {
    u16 heightTexCoord;
    u16 widthTexCoord;
    u16 vertexZ;
    heightTexCoord = (texHeightFixed << 8) >> 16;
    widthTexCoord = (texWidthFixed << 8) >> 16;
    reg_G3_TEXCOORD = 0x60006;
    vertexZ = data_021659d4[2];
    reg_G3_VTX_16 = data_021659d4[0] | data_021659d4[1] << 16;
    reg_G3_VTX_16 = vertexZ;
    reg_G3_TEXCOORD = heightTexCoord << 16 | 6;
    vertexZ = data_021659d4[5];
    reg_G3_VTX_16 = data_021659d4[3] | data_021659d4[4] << 16;
    reg_G3_VTX_16 = vertexZ;
    reg_G3_TEXCOORD = widthTexCoord | heightTexCoord << 16;
    vertexZ = data_021659d4[8];
    reg_G3_VTX_16 = data_021659d4[6] | data_021659d4[7] << 16;
    reg_G3_VTX_16 = vertexZ;
    reg_G3_TEXCOORD = widthTexCoord | 0x60000;
    vertexZ = data_021659d4[11];
    reg_G3_VTX_16 = data_021659d4[9] | data_021659d4[10] << 16;
    reg_G3_VTX_16 = vertexZ;
}

#pragma thumb on

void InitKartNameTagsAndDistanceOrder(void) {
    void *heap;
    BOOL isGrandPrix;
    u16 i;
    s32 objectCount;
    BOOL createsObject;
    BOOL isEntryIndexHumanGhostOrPeer;
    u32 playerKind;
    KartNameTag *kartObject;
    s32 entryIndex;
    BOOL isEntryHumanGhostOrPeer;
    heap = GetHeap(GetCurrentHeapCall());
    if (gRaceSetup->mMode == MODE_GRAND_PRIX) {
        isGrandPrix = TRUE;
    } else {
        isGrandPrix = FALSE;
    }
    data_0217aed0 = HeapAlloc(heap, 0x194);
    data_0217aed0->mUnk_184 = 0;
    data_0217aed0->mUnk_188 = NULL;
    if (IsRaceAwardOrStaffRoll() != 0) {
        data_0217aed0->mNameTagCount = 0;
    } else if (isGrandPrix == FALSE) {
        data_0217aed0->mNameTagCount = gRaceSetup->mKartCount - 1;
        for (i = 0; (u32) i < gRaceSetup->mKartCount; i++) {
            if (gRaceSetup->mCurrentEntries[i].mPlayer.mKind == PLAYER_KIND_GHOST &&
                gRaceSetup->mCurrentEntries[i].mPlayer.mGhostRecordIndex == 0) {
                data_0217aed0->mNameTagCount = data_0217aed0->mNameTagCount - 1;
            }
        }
    } else {
        data_0217aed0->mNameTagCount = gRaceSetup->mHumanAndPeerKartCount;
        entryIndex = gRaceSetup->mEntryIndex;
        isEntryIndexHumanGhostOrPeer = FALSE;
        if (entryIndex != -1) {
            playerKind = gRaceSetup->mCurrentEntries[(u16) entryIndex].mPlayer.mKind;
            if (playerKind <= 3 && ((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) != 0) {
                isEntryIndexHumanGhostOrPeer = TRUE;
            }
            if (isEntryIndexHumanGhostOrPeer != FALSE) {
                data_0217aed0->mNameTagCount = data_0217aed0->mNameTagCount - 1;
            }
        }
    }
    gKartDistanceLimitsSquared = &data_02155a48;
    InitKartEmblemPointers();
    for (i = 0; (u32) i < gRaceSetup->mKartCount; i++) {
        data_0217aed0->mUnk_024[i] = i;
        data_0217aed0->mKartIndicesByDistanceAlongView[i] = i;
        data_0217aed0->mKartIndicesByDistance[i] = i;
        data_0217aed0->mAlongViewOrderOffset[i] = 0;
        data_0217aed0->mDistanceSquaredOrderOffset[i] = 0;
        data_0217aed0->mSortedDistanceAlongView[i] = 0;
        data_0217aed0->mSortedDistanceSquared[i] = 0;
        data_0217aed0->mAlongViewOrderIndex[i] = i;
        data_0217aed0->mKartIndicesByDistance[i] = i;
        data_0217aed0->mDistanceAlongViewWithMargin[i] = 0;
        data_0217aed0->mNameTagByKart[i] = NULL;
        data_0217aed0->mNameTagBeyondTwoNearest[i] = 0;
    }
    if (data_0217aed0->mNameTagCount > 0) {
        objectCount = 0;
        for (i = 0; (u32) i < gRaceSetup->mKartCount; i++) {
            createsObject = FALSE;
            if (isGrandPrix == FALSE) {
                if (i != gRaceSetup->mEntryIndex) {
                    if (gRaceSetup->mCurrentEntries[i].mPlayer.mKind != PLAYER_KIND_GHOST ||
                        gRaceSetup->mCurrentEntries[i].mPlayer.mGhostRecordIndex != 0) {
                        createsObject = TRUE;
                    }
                }
            } else {
                isEntryHumanGhostOrPeer = FALSE;
                playerKind = gRaceSetup->mCurrentEntries[i].mPlayer.mKind;
                if (playerKind <= 3 && ((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) != 0) {
                    isEntryHumanGhostOrPeer = TRUE;
                }
                if (isEntryHumanGhostOrPeer != FALSE && i != gRaceSetup->mEntryIndex) {
                    createsObject = TRUE;
                }
            }
            if (createsObject != FALSE) {
                data_0217aed0->mNameTagByKart[i] = HeapAlloc(heap, 0x28);
                kartObject = data_0217aed0->mNameTagByKart[i];
                InitKartNameTag(kartObject, i, heap);
                data_0217aed0->mNameTags[objectCount] = kartObject;
                objectCount++;
            } else {
                data_0217aed0->mNameTagByKart[i] = NULL;
            }
        }
    }
    reg_G3_MTX_MODE = 0;
    G3i_OrthoW_(0x60000, 0xfffa0000, 0xfff80000, 0x80000, 0, 0x1000, 0x200, 1, &data_0217aee0);
}

void InitKartNameTag(KartNameTag *kartObject, u16 kartIndex, void *heap) {
    kartObject->mTexPlttEntries = HeapAlloc(heap, 0x90);
    kartObject->mPos = data_02155ccc;
    kartObject->mKartIndex = kartIndex;
    kartObject->mTexPlttEntries->mEntries[0] = data_021659ec;
    kartObject->mTexPlttEntries->mEntries[1] = data_02165a34;
    kartObject->mTexPlttEntries->mEntries[2] = data_02165a10;
    kartObject->mTexPlttEntries->mEntries[3] = data_02165a58;
    kartObject->mUnk_10 = TRUE;
    kartObject->mUnk_14 = 0;
    kartObject->mFadeStopped = TRUE;
    kartObject->mAlpha = 0;
    kartObject->mKartPaletteColor = 0x7fff;
    kartObject->mFadeLevel = 0;
    kartObject->mFadeLevelPerCall = 0;
}

void SetTextureSizeFromBits(TexPlttEntry *texPlttEntry) {
    u16 texHeightBits;
    u16 texWidthBits;
    s32 texWidth;
    s32 texHeight;
    texHeightBits = texPlttEntry->mUnk_00 >> 23 & 7;
    texWidthBits = texPlttEntry->mUnk_00 >> 20 & 7;
    switch (texWidthBits) {
        case 0:
            texWidth = 8;
            break;
        case 1:
            texWidth = 0x11;
            break;
        case 2:
            texWidth = 0x21;
            break;
        case 3:
            texWidth = 0x41;
            break;
        case 4:
            texWidth = 0x80;
            break;
        case 5:
            texWidth = 0x100;
            break;
        case 6:
            texWidth = 0x200;
            break;
        case 7:
            texWidth = 0x400;
            break;
    }
    switch (texHeightBits) {
        case 0:
            texHeight = 8;
            break;
        case 1:
            texHeight = 0x11;
            break;
        case 2:
            texHeight = 0x21;
            break;
        case 3:
            texHeight = 0x41;
            break;
        case 4:
            texHeight = 0x80;
            break;
        case 5:
            texHeight = 0x100;
            break;
        case 6:
            texHeight = 0x200;
            break;
        case 7:
            texHeight = 0x400;
            break;
    }
    texPlttEntry->mTexWidthFixed = texWidth << 12;
    texPlttEntry->mTexHeightFixed = texHeight << 12;
}

u16 GetKartPaletteColor(int kartIndex) {
    if (gRaceSetup->mMode == 5) {
        return data_02155a2c[gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mUnk_25];
    }
    if (gRaceSetup->mUseTeams != 0) {
        return data_02155a28[gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex];
    }
    if (GetKartModelsEntry(kartIndex)->mCharacterIndex == 0xc) {
        return GetHeyhoPalette(kartIndex)->mUnk_04;
    }
    return data_02155a64[kartIndex];
}

void func_020872a4(void) {
    u16 i;
    void *heap;
    KartNameTag *kartObject;
    KartNameTagTexPlttEntries *texPlttEntries;
    TexPlttEntry *entryNameTexPltt;
    TexPlttEntry *fourthTexPltt;
    heap = GetHeap(GetCurrentHeapCall());
    UploadKartEmblems();
    data_0217aedc = 0;
    gKartEmblemPlltBuffer = HeapAllocAligned(heap, 0x20, -4);
    gKartEntryNameTexBuffer = HeapAllocAligned(heap, 0x100, -4);
    gKartEntryNamePlltBuffer = HeapAllocAligned(heap, 8, -4);
    data_0217aecc = HeapAllocAligned(heap, 0x200, -4);
    for (i = 0; i < data_0217aed0->mNameTagCount; i++) {
        kartObject = data_0217aed0->mNameTags[i];
        texPlttEntries = kartObject->mTexPlttEntries;
        entryNameTexPltt = &texPlttEntries->mEntries[1];
        fourthTexPltt = &texPlttEntries->mEntries[3];
        texPlttEntries->mEntries[0].mTexByteCount = 0x200;
        texPlttEntries->mEntries[0].mPlttByteCount = 0x20;
        texPlttEntries->mEntries[0].mPlttData = data_0217aed0->mUnk_188;
        kartObject->mKartPaletteColor = GetKartPaletteColor(kartObject->mKartIndex);
        SetupKartEmblemTexture(&texPlttEntries->mEntries[0], kartObject->mKartIndex);
        SetupKartEntryNameTexture(entryNameTexPltt, kartObject->mKartIndex);
        SetPaletteKartColor(&texPlttEntries->mEntries[2], kartObject->mKartIndex);
        func_020870ec(fourthTexPltt, kartObject->mKartIndex);
        UploadTextureAndPalette(&texPlttEntries->mEntries[0]);
        UploadTextureAndPalette(entryNameTexPltt);
        UploadTextureAndPalette(&kartObject->mTexPlttEntries->mEntries[2]);
        if (fourthTexPltt->mTexData != NULL) {
            UploadTextureAndPalette(fourthTexPltt);
        }
    }
    HeapFree(heap, data_0217aecc);
    HeapFree(heap, gKartEntryNamePlltBuffer);
    HeapFree(heap, gKartEntryNameTexBuffer);
    HeapFree(heap, gKartEmblemPlltBuffer);
}

void SetupKartEmblemTexture(TexPlttEntry *texPlttEntry, u16 kartIndex) {
    u16 *plttBuffer;
    void *emblemTex;
    u16 firstColor;
    plttBuffer = gKartEmblemPlltBuffer;
    emblemTex = data_0217aed0->mEmblemTex[kartIndex];
    MI_CpuCopy8(data_0217aed0->mEmblemPltt[kartIndex], plttBuffer, texPlttEntry->mPlttByteCount);
    firstColor = 0x7fff;
    if (gRaceSetup->mUseTeams != 0) {
        firstColor = data_02155a28[gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex];
    }
    *plttBuffer = firstColor;
    DC_FlushRange(plttBuffer, texPlttEntry->mPlttByteCount);
    DC_FlushRange(emblemTex, texPlttEntry->mTexByteCount);
    texPlttEntry->mPlttData = plttBuffer;
    texPlttEntry->mTexData = emblemTex;
}

#pragma thumb off

#pragma thumb on

void SetupKartEntryNameTexture(TexPlttEntry *texPlttEntry, u32 kartIndex) {
    u16 kartPaletteColor;
    u16 *plttBuffer;
    u8 *texBuffer;
    texBuffer = gKartEntryNameTexBuffer;
    plttBuffer = gKartEntryNamePlltBuffer;
    *plttBuffer = (0x00007c00u);
    kartPaletteColor = GetKartPaletteColor(kartIndex);
    plttBuffer[1] = kartPaletteColor;
    plttBuffer[2] = 0;
    plttBuffer[3] = 0x1f;
    DC_FlushRange(plttBuffer, 8);
    MI_CpuFill8(texBuffer, 0, texPlttEntry->mTexByteCount);
    RenderKartEntryNameToTexture(kartIndex, texBuffer, 1, 2);
    DC_FlushRange(texBuffer, 0x100);
    texPlttEntry->mTexData = texBuffer;
    texPlttEntry->mPlttData = plttBuffer;
}

void SetPaletteKartColor(TexPlttEntry *texPlttEntry, u32 kartIndex) {
    u16 kartPaletteColor;
    u16 *plttData;
    plttData = texPlttEntry->mPlttData;
    kartPaletteColor = GetKartPaletteColor(kartIndex);
    plttData[1] = kartPaletteColor;
    DC_FlushRange(plttData, 8);
}

#pragma thumb off

#pragma thumb on

void func_020870ec(TexPlttEntry *texPlttEntry, u16 kartIndex) {
    u8 *pixels;
    s32 nibbleLimit;
    u32 i;
    TexPlttEntry *texPlttEntryAlias;
    u8 pixelPair;
    u32 highNibbleBits;
    u8 highNibble;
    u8 lowNibble;
    texPlttEntryAlias = texPlttEntry;
    if (gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mUnk_26 != 0) {
        pixels = data_0217aecc;
        nibbleLimit = 7;
        switch (gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mUnk_26) {
            case 2:
                nibbleLimit = 4;
                break;
            case 3:
                nibbleLimit = -1;
                break;
        }
        MI_CpuCopy8(texPlttEntryAlias->mTexData, pixels, texPlttEntryAlias->mTexByteCount);
        if (nibbleLimit > 0) {
            for (i = 0; i < texPlttEntryAlias->mTexByteCount; i++) {
                pixelPair = pixels[i];
                highNibbleBits = pixelPair & 0xf0;
                highNibble = highNibbleBits >> 4;
                lowNibble = pixelPair & 0xf;
                if (lowNibble < nibbleLimit) {
                    pixelPair = highNibbleBits;
                }
                if (highNibble < nibbleLimit) {
                    pixelPair = pixelPair & 0xf;
                }
                pixels[i] = pixelPair;
            }
        }
        DC_FlushRange(pixels, texPlttEntryAlias->mTexByteCount);
        texPlttEntryAlias->mTexData = pixels;
    } else {
        texPlttEntryAlias->mTexData = NULL;
    }
}

void InitKartEmblemPointers(void) {
    u16 i;
    Nclr *nclr;
    NNSG3dResTex *texture;
    char *path;
    u8 *emblemPltt;
    u8 *emblemTex;
    for (i = 0; (u32) i < gRaceSetup->mKartCount; i++) {
        data_0217aed0->mEmblemTex[i] = NULL;
        data_0217aed0->mEmblemPltt[i] = NULL;
        if (gRaceSetup->mCurrentEntries[i].mPlayer.mUnk_24 == 0 || gRaceSetup->mUseTeams != 0) {
            if (gRaceSetup->mUseTeams != 0) {
                path = BuildTeamEmblemNsbtxPath(gRaceSetup->mCurrentEntries[i].mPlayer.mTeamIndex == 1 ? 1 : 0);
            } else {
                path = BuildEmblemNsbtxPath(gRaceSetup->mCurrentEntries[i].mCharacterIndex);
            }
            texture = NNS_G3dGetTex(func_02047950(path));
            emblemPltt = OFFSET_PTR(u8, texture, texture->mPlttInfo.mOfsPlttData);
            emblemTex = OFFSET_PTR(u8, texture, texture->mTexInfo.mOfsTex);
            data_0217aed0->mEmblemTex[i] = emblemTex;
            data_0217aed0->mEmblemPltt[i] = emblemPltt;
        } else {
            emblemTex = (void *) gRaceSetup->mCurrentEntries[i].mPlayer.mEmblemData;
            LoadNclrData(&nclr, func_02047950(gEmblemSBNclrName));
            emblemPltt = (u8 *) nclr->mData;
            data_0217aed0->mEmblemTex[i] = emblemTex;
            data_0217aed0->mEmblemPltt[i] = emblemPltt;
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
void UploadKartEmblem(u32 kartIndex, void *texData, void *plttData) {
    u8 *kartModelResMdl;
    u8 *q;
    u8 *r;
    u8 *e;
    s32 textureIndex;
    s32 h;
    u32 texOffset;
    u32 plttOffset;
    kartModelResMdl = GetKartModelResMdl((u16) kartIndex);
    textureIndex =
        NNS_G3dGetResDictIdxByName(kartModelResMdl + *OFFSET_PTR(u32, kartModelResMdl, 8) + 4, &data_02155a54);
    q = kartModelResMdl + *OFFSET_PTR(u32, kartModelResMdl, 8);
    r = q + 4;
    h = *(u16 *) (r + *OFFSET_PTR(u16, q, 0xa));
    e = q + *(u32 *) (r + *OFFSET_PTR(u16, q, 0xa) + h * textureIndex + 4);
    texOffset = (*OFFSET_PTR(u32, e, 0x14) & 0xffff) << 3;
    plttOffset = *OFFSET_PTR(u16, e, 0x1c) << 4;
    DC_FlushRange(texData, 0x200);
    DC_FlushRange(plttData, 0x20);
    GX_BeginLoadTex();
    GX_LoadTex(texData, texOffset, 0x200);
    GX_EndLoadTex();
    GX_BeginLoadTexPltt();
    GX_LoadTexPltt(plttData, plttOffset, 0x20);
    GX_EndLoadTexPltt();
}

void UploadTextureAndPalette(TexPlttEntry *texPlttEntry) {
    u16 v;
    u32 texOffset;
    v = texPlttEntry->mUnk_00 >> 26 & 7;
    texOffset = (data_021619ec(texPlttEntry->mTexByteCount, 0, 0) & 0xffff) << 3;
    texPlttEntry->mUnk_00 = texPlttEntry->mUnk_00 & 0xffff0000;
    GX_BeginLoadTex();
    GX_LoadTex(texPlttEntry->mTexData, texOffset, texPlttEntry->mTexByteCount);
    GX_EndLoadTex();
    texPlttEntry->mUnk_00 = texPlttEntry->mUnk_00 | (texOffset >> 3 & 0xffff);
    if (texPlttEntry->mPlttByteCount != 0) {
        texPlttEntry->mPlttOffset = (data_021619f4(texPlttEntry->mPlttByteCount, v == 2, 0) & 0xffff) << 3;
        GX_BeginLoadTexPltt();
        GX_LoadTexPltt(texPlttEntry->mPlttData, texPlttEntry->mPlttOffset, texPlttEntry->mPlttByteCount);
        GX_EndLoadTexPltt();
    }
    SetTextureSizeFromBits(texPlttEntry);
}

#pragma thumb off
