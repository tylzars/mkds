#include "code_0200fe74.h"

#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200f59c.h"
#include "code_02013740.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_02170000.h"

u32 gVramBankLockedMask;
u16 gVramBankLockIds[9];

// Binds the texture to the materials of one entry of the texture-to-material list: sets the texture offset in
// each material and the scale from the texture size. Sets bit 0 of the flag.
void bindMdlTex_Internal_(Unk020101e8_08 *mat, Unk020103c0_e *data, Unk02010294 *tex, Unk020106c8_0c *texData) {
    u32 vramOffset;
    u32 i;
    u8 *matIndices;
    u32 width;
    u32 height;
    Unk020106c8_14 *matData;

    matIndices = (u8 *) mat + data->mUnk_00;
    if ((texData->mUnk_00 & 0x1c000000) != 0x14000000) {
        vramOffset = tex->mUnk_08 & 0xffff;
    } else {
        vramOffset = tex->mUnk_18 & 0xffff;
    }
    for (i = 0; i < data->mUnk_02; i++) {
        u8 *table;
        table = (u8 *) mat + 4 + mat->mUnk_0a;
        matData = (Unk020106c8_14 *) ((u8 *) mat + *(u32 *) (table + *(u16 *) table * matIndices[i] + 4));
        matData->mUnk_14 |= texData->mUnk_00 + vramOffset;
        width = texData->mUnk_04 & 0x7ff;
        height = (texData->mUnk_04 >> 11) & 0x7ff;
        matData->mUnk_24 = (width == matData->mUnk_20) ? 0x1000 : DivFixed12(width << 12, matData->mUnk_20 << 12);
        matData->mUnk_28 = (height == matData->mUnk_22) ? 0x1000 : DivFixed12(height << 12, matData->mUnk_22 << 12);
    }
    data->mUnk_03 |= 1;
}

// Undoes bindMdlTex_Internal_ for one entry: clears the texture offset and resets the scale. Clears bit 0 of the flag.
void releaseMdlTex_Internal_(Unk020101e8_08 *mat, Unk020103c0_e *data) {
    u8 *matIndices;
    u32 i;
    Unk020106c8_14 *matData;

    matIndices = (u8 *) mat + data->mUnk_00;
    for (i = 0; i < data->mUnk_02; i++) {
        u8 *table;
        table = (u8 *) mat + 4 + mat->mUnk_0a;
        matData = (Unk020106c8_14 *) ((u8 *) mat + *(u32 *) (table + *(u16 *) table * matIndices[i] + 4));
        matData->mUnk_14 &= 0xc00f0000;
        matData->mUnk_24 = 0x1000;
        matData->mUnk_28 = matData->mUnk_24;
    }
    data->mUnk_03 &= ~1;
}

// Binds the texture to every texture-to-material entry of the model that is not bound yet. Returns 0 when the texture
// has no texture for one of the names.
int NNS_G3dBindMdlTex(Unk020101e8 *mdl, Unk02010294 *tex) {
    Unk020101e8_08 *materials;
    Unk02010294_t *dict;
    int result;
    u32 i;
    void *texData;
    u8 *table;
    Unk020103c0_e *data;

    materials = (Unk020101e8_08 *) ((u8 *) mdl + mdl->mUnk_08);
    dict = (Unk02010294_t *) ((u8 *) materials + materials->mUnk_00);
    result = 1;
    for (i = 0; i < dict->mUnk_01; i++) {
        table = (u8 *) dict + dict->mUnk_06;
        texData = func_020138b4(tex->mUnk_3c, (const u32 *) (table + *(u16 *) (table + 2) + i * 16));
        if (texData != 0) {
            table = (u8 *) dict + dict->mUnk_06;
            data = (Unk020103c0_e *) (table + 4 + *(u16 *) table * i);
            if ((data->mUnk_03 & 1) == 0) {
                bindMdlTex_Internal_(materials, data, tex, texData);
            }
        } else {
            result = 0;
        }
    }
    return result;
}

// Binds the texture of the given name to the model if it is not bound yet. Returns 1 when it was bound.
int NNS_G3dBindMdlTexEx(Unk020101e8 *mdl, Unk02010294 *tex, const u32 *name) {
    Unk02010294_t *dict;
    Unk020101e8_08 *materials;
    void *texData;
    Unk020103c0_e *data;

    materials = (Unk020101e8_08 *) ((u8 *) mdl + mdl->mUnk_08);
    dict = (Unk02010294_t *) ((u8 *) materials + materials->mUnk_00);
    texData = func_020138b4(tex->mUnk_3c, name);
    if (texData != 0) {
        data = func_020138b4(dict, name);
        if (data != 0 && (data->mUnk_03 & 1) == 0) {
            bindMdlTex_Internal_(materials, data, tex, texData);
            return 1;
        }
    }
    return 0;
}

// Releases every texture binding of the model.
void NNS_G3dReleaseMdlTex(Unk020101e8 *mdl) {
    Unk020101e8_08 *materials;
    Unk02010294_t *dict;
    u8 *table;
    Unk020103c0_e *data;
    u32 i;

    materials = (Unk020101e8_08 *) ((u8 *) mdl + mdl->mUnk_08);
    dict = (Unk02010294_t *) ((u8 *) materials + materials->mUnk_00);
    for (i = 0; i < dict->mUnk_01; i++) {
        table = (u8 *) dict + dict->mUnk_06;
        data = (Unk020103c0_e *) (table + 4 + *(u16 *) table * i);
        if ((data->mUnk_03 & 1) != 0) {
            releaseMdlTex_Internal_(materials, data);
        }
    }
}

// Releases the texture binding of the given name. Returns 1 when a binding was released.
u32 NNS_G3dReleaseMdlTexEx(Unk020101e8 *mdl, const u32 *name) {
    Unk020101e8_08 *materials;
    Unk020103c0_e *data;

    materials = (Unk020101e8_08 *) ((u8 *) mdl + mdl->mUnk_08);
    data = func_020138b4((u8 *) materials + materials->mUnk_00, name);
    if (data != 0 && (data->mUnk_03 & 1) != 0) {
        releaseMdlTex_Internal_(materials, data);
        return 1;
    }
    return 0;
}

// Binds the palette to the materials of one entry of the palette-to-material list. Sets bit 0 of the flag.
void bindMdlPltt_Internal_(Unk020101e8_08 *mat, Unk020103c0_e *data, Unk02010294 *tex, Unk020103c0_d *plttData) {
    u8 *matIndices;
    u32 base;
    u32 vramOffset;
    u32 i;
    u8 *table;
    Unk020103c0_o *matData;

    matIndices = (u8 *) mat + data->mUnk_00;
    base = (u16) tex->mUnk_2c;
    vramOffset = plttData->mUnk_00;
    if ((plttData->mUnk_02 & 1) == 0) {
        base = (base << 15) >> 16;
        vramOffset = (vramOffset << 15) >> 16;
    }
    for (i = 0; i < data->mUnk_02; i++) {
        table = (u8 *) mat + 4 + mat->mUnk_0a;
        matData = (Unk020103c0_o *) ((u8 *) mat + *(u32 *) (table + *(u16 *) table * matIndices[i] + 4));
        matData->mUnk_1c = vramOffset + base;
    }
    data->mUnk_03 |= 1;
}

// Binds the palette to every palette-to-material entry of the model that is not bound yet. Returns 0 when the texture
// has no palette for one of the names.
u32 NNS_G3dBindMdlPltt(Unk020101e8 *mdl, Unk02010294 *tex) {
    Unk020101e8_08 *materials;
    Unk02010294_t *dict;
    u8 *table;
    u32 i;
    u32 result;
    void *plttData;
    Unk020103c0_e *data;

    materials = (Unk020101e8_08 *) ((u8 *) mdl + mdl->mUnk_08);
    result = 1;
    i = 0;
    dict = (Unk02010294_t *) ((u8 *) materials + materials->mUnk_02);
    for (; i < dict->mUnk_01; i++) {
        table = (u8 *) dict + dict->mUnk_06;
        plttData =
            func_020138b4((u8 *) tex + tex->mUnk_34, (u32 *) (table + ((Unk02010310_d *) table)->mUnk_02 + i * 16));
        if (plttData != 0) {
            table = (u8 *) dict + dict->mUnk_06;
            data = (Unk020103c0_e *) (table + 4 + *(u16 *) table * i);
            if ((data->mUnk_03 & 1) == 0) {
                bindMdlPltt_Internal_(materials, data, tex, plttData);
            }
        } else {
            result = 0;
        }
    }
    return result;
}

// Binds the palette of the given name to the model if it is not bound yet. Returns 1 when it was bound.
u32 NNS_G3dBindMdlPlttEx(Unk020101e8 *mdl, Unk02010294 *tex, const u32 *name) {
    Unk02010294_t *dict;
    Unk020101e8_08 *materials;
    void *plttData;
    Unk020103c0_e *data;

    materials = (Unk020101e8_08 *) ((u8 *) mdl + mdl->mUnk_08);
    dict = (Unk02010294_t *) ((u8 *) materials + materials->mUnk_02);
    plttData = func_020138b4((u8 *) tex + tex->mUnk_34, name);
    if (plttData != 0) {
        data = func_020138b4(dict, name);
        if (data != 0 && (data->mUnk_03 & 1) == 0) {
            bindMdlPltt_Internal_(materials, data, tex, plttData);
            return 1;
        }
    }
    return 0;
}

// Releases every palette binding of the model.
void NNS_G3dReleaseMdlPltt(Unk020101e8 *mdl) {
    Unk020101e8_08 *materials;
    Unk02010294_t *dict;
    u8 *table;
    Unk020103c0_e *data;
    u32 i;

    materials = (Unk020101e8_08 *) ((u8 *) mdl + mdl->mUnk_08);
    dict = (Unk02010294_t *) ((u8 *) materials + materials->mUnk_02);
    for (i = 0; i < dict->mUnk_01; i++) {
        table = (u8 *) dict + dict->mUnk_06;
        data = (Unk020103c0_e *) (table + 4 + *(u16 *) table * i);
        if ((data->mUnk_03 & 1) != 0) {
            data->mUnk_03 &= ~1;
        }
    }
}

// Releases the palette binding of the given name. Returns 1 when a binding was released.
u32 NNS_G3dReleaseMdlPlttEx(Unk020101e8 *mdl, const u32 *name) {
    Unk020101e8_08 *materials;
    Unk020103c0_e *data;

    materials = (Unk020101e8_08 *) ((u8 *) mdl + mdl->mUnk_08);
    data = func_020138b4((u8 *) materials + materials->mUnk_02, name);
    if (data != 0 && (data->mUnk_03 & 1) != 0) {
        data->mUnk_03 &= ~1;
        return 1;
    }
    return 0;
}

// Binds the textures and palettes of tex to every model of the model set. Returns 0 when one name is missing.
u32 NNS_G3dBindMdlSet(Unk02010168 *mdlSet, Unk02010294 *tex) {
    u32 i;
    u32 result;
    u8 *table;
    u16 offset;
    u16 stride;
    Unk020101e8 *model;

    result = 1;
    i = 0;
    if (i < mdlSet->mUnk_09) {
        table = (u8 *) mdlSet + 8;
        do {
            offset = mdlSet->mUnk_0e;
            stride = *(u16 *) (table + offset);
            model = (Unk020101e8 *) ((u8 *) mdlSet + *(u32 *) (table + offset + stride * i + 4));
            result &= NNS_G3dBindMdlTex(model, tex);
            result &= NNS_G3dBindMdlPltt(model, tex);
            i++;
        } while (i < mdlSet->mUnk_09);
    }
    return result;
}

// Releases the texture and palette bindings of every model of the model set.
void NNS_G3dReleaseMdlSet(Unk02010168 *mdlSet) {
    u32 i;
    u8 *table;
    u16 offset;
    u16 stride;
    Unk020101e8 *model;

    i = 0;
    if (i < mdlSet->mUnk_09) {
        table = (u8 *) mdlSet + 8;
        do {
            offset = mdlSet->mUnk_0e;
            stride = *(u16 *) (table + offset);
            model = (Unk020101e8 *) ((u8 *) mdlSet + *(u32 *) (table + offset + stride * i + 4));
            NNS_G3dReleaseMdlTex(model);
            NNS_G3dReleaseMdlPltt(model);
            i++;
        } while (i < mdlSet->mUnk_09);
    }
}

// Fills the eight words of buffer with values that change from run to run: the tick counter, the vertical counter,
// the console's stored user data, the clock, the microphone, the touch panel and the buttons.
void OS_GetLowEntropyData(Unk0201000c *buffer) {
    u16 vcount;
    u8 *work;
    u8 *userInfo;
    u8 *macAddress;

    work = (u8 *) 0x27ffc00;
    userInfo = work + 0x80;
    macAddress = (u8 *) ((u32) userInfo + 0x74);
    vcount = *(vu16 *) 0x4000006;
    buffer->mUnk_00 = OS_GetTickLo() | (vcount << 16);
    buffer->mUnk_04 = (*(u16 *) (macAddress + 4) << 16) ^ (u32) gTickOverflowCount;
    buffer->mUnk_08 = *(u32 *) (work + 0x3c) ^ ((gTickOverflowCount >> 32) ^ *(u32 *) macAddress);
    buffer->mUnk_08 = buffer->mUnk_08 ^ *(vu32 *) 0x4000600;
    buffer->mUnk_0c = *(u32 *) (work + 0x1e8);
    buffer->mUnk_10 = *(u32 *) (work + 0x1ec);
    buffer->mUnk_14 = *(u32 *) (work + 0x390) ^ (*(u16 *) (work + 0x394) << 16);
    buffer->mUnk_18 = (*(u16 *) (work + 0x3aa) << 16) | *(u16 *) (work + 0x3ac);
    buffer->mUnk_1c = *(vu16 *) 0x4000130 | *(vu16 *) 0x27fffa8 | (*(u16 *) (work + 0x398) << 16);
}

// Sets the locked-bank mask and the nine bank lock ids to 0.
void OSi_InitVramExclusive(void) {
    s32 i;

    gVramBankLockedMask = 0;
    for (i = 0; i < 9; i++) {
        gVramBankLockIds[i] = 0;
    }
}

// Under OS_DisableInterrupts: returns 0 and changes nothing when a bank of bank is already locked with an id other
// than lockId. Otherwise locks every bank of bank & 0x1ff with lockId and returns 1.
u32 OSi_TryLockVram(u32 bank, u16 lockId) {
    u32 remainingBanks;
    u32 enabled;
    s32 bankIndex;

    enabled = OS_DisableInterrupts();
    remainingBanks = bank & gVramBankLockedMask;
    while (1) {
        bankIndex = 31 - OsCountZeroBits(remainingBanks);
        if (bankIndex < 0) {
            break;
        }
        remainingBanks &= ~(1 << bankIndex);
        if (lockId != gVramBankLockIds[bankIndex]) {
            OS_RestoreInterrupts(enabled);
            return 0;
        }
    }
    remainingBanks = bank & 0x1ff;
    while (1) {
        bankIndex = 31 - OsCountZeroBits(remainingBanks);
        if (bankIndex < 0) {
            break;
        }
        remainingBanks &= ~(1 << bankIndex);
        gVramBankLockIds[bankIndex] = lockId;
        gVramBankLockedMask |= 1 << bankIndex;
    }
    OS_RestoreInterrupts(enabled);
    return 1;
}

// Under OS_DisableInterrupts: for each locked bank of bank & 0x1ff whose lock id equals lockId, clears the lock bit
// and the id. Other banks are left alone.
void OSi_UnlockVram(u32 bank, u16 lockId) {
    u32 remainingBanks;
    u32 enabled;
    s32 bankIndex;

    enabled = OS_DisableInterrupts();
    remainingBanks = bank & gVramBankLockedMask & 0x1ff;
    while (1) {
        bankIndex = 31 - OsCountZeroBits(remainingBanks);
        if (bankIndex < 0) {
            break;
        }
        remainingBanks &= ~(1 << bankIndex);
        if (lockId == gVramBankLockIds[bankIndex]) {
            gVramBankLockIds[bankIndex] = 0;
            gVramBankLockedMask &= ~(1 << bankIndex);
        }
    }
    OS_RestoreInterrupts(enabled);
}

// clang-format off
// Counts the leading zero bits of bitmap.
asm u32 OsCountZeroBits(u32 bitmap) {
    clz r0, r0
    bx lr
}
// clang-format on
