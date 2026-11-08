#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0214d018.h"

static inline u32 func_0208b190_inline(Unk020f41c4_B *b, u32 n) {
    b->mValue = b->mMultiplier * b->mValue + b->mIncrement;
    if (n == 0) {
        return b->mValue >> 32;
    }
    return ((b->mValue >> 32) * n) >> 32;
}

// Ids from 1000 up belong to the second manager (Mission Run); the id inside the manager goes to *a.
SPLManager *GetSPLManagerForEffectId(s32 *outIndex, s32 effectId) {
    if (effectId >= 0x3e8) {
        effectId -= 0x3e8;
        *outIndex = effectId;
        return data_0217b03c;
    }
    *outIndex = effectId;
    return data_0217b044;
}

void AdvanceStadiumEmitters(void) {
    s16 i;
    s32 bestIndex;
    Vec3 cameraForward;
    s32 effectIds[6];
    s32 emitterDirectionIndices[6];
    s32 bestDot;
    s32 previousIndex;
    s32 nextIndex;
    s32 emitterIndex;
    s32 randomDraw;
    Unk0217b050Func *getManager;
    Camera *camera;

    data_0217b048->mEmitterTimer--;
    if (data_0217b048->mEmitterTimer > 0) {
        return;
    }
    bestDot = -0x1000;
    bestIndex = -1;
    camera = GetCurrentCamera();
    cameraForward = camera->mForward;
    for (i = 0; i < 6; i++) {
        StadiumEmitters *stadiumEmitters = data_0217b048;
        if (stadiumEmitters->mEmitters[i] != NULL) {
            s32 effectIndex;
            Unk0201ca6c **emitterSlot = &stadiumEmitters->mEmitters[i];
            SPLManager_DeleteEmitter(data_0217b050(&effectIndex, 0), *emitterSlot);
            *emitterSlot = NULL;
        }
    }
    for (i = 0; i < 6; i++) {
        s32 dot = VEC_DotProduct(&cameraForward, &data_0217b048->mDirections[i]);
        if (dot >= bestDot) {
            bestDot = dot;
            bestIndex = i;
        }
    }
    previousIndex = bestIndex - 1;
    if (previousIndex < 0) {
        previousIndex = 5;
    }
    nextIndex = bestIndex + 1;
    if (nextIndex >= 6) {
        nextIndex = 0;
    }
    effectIds[0] = data_usa_02155f48[previousIndex * 2];
    effectIds[1] = data_usa_02155f48[previousIndex * 2 + 1];
    effectIds[2] = data_usa_02155f48[bestIndex * 2];
    effectIds[3] = data_usa_02155f48[bestIndex * 2 + 1];
    effectIds[4] = data_usa_02155f48[nextIndex * 2];
    effectIds[5] = data_usa_02155f48[nextIndex * 2 + 1];
    emitterDirectionIndices[0] = emitterDirectionIndices[1] = previousIndex;
    emitterDirectionIndices[2] = emitterDirectionIndices[3] = bestIndex;
    emitterDirectionIndices[4] = emitterDirectionIndices[5] = nextIndex;
    for (emitterIndex = 0; emitterIndex < 6; emitterIndex++) {
        s32 effectIndex;
        Vec3 position;
        Unk0201ca6c *emitter;
        SPLManager *manager;
        Vec3 *tablePosition = &data_usa_02155f78[emitterDirectionIndices[emitterIndex]];
        getManager = data_0217b050;
        manager = getManager(&effectIndex, effectIds[emitterIndex]);
        position.x = tablePosition->x >> 4;
        position.y = tablePosition->y >> 4;
        position.z = tablePosition->z >> 4;
        emitter = SPLManager_CreateEmitter(manager, effectIndex, &position);
        if (emitter != NULL) {
            if (emitter->mUnk_20->mUnk_00->mUnk_54 & 0x80) {
                emitter->mUnk_80_16 = 1;
            } else if (emitter->mUnk_20->mUnk_00->mUnk_54 & 0x40) {
                emitter->mUnk_80_16 = 2;
            }
        }
        data_0217b048->mEmitters[emitterIndex] = emitter;
    }
    randomDraw = func_0208b190_inline(&gRaceProgress->mLocalRandom, 0x19);
    data_0217b048->mEmitterTimer = (u16) randomDraw + 0x14;
}

void CreateAwardEmitters(void) {
    Unk02166108 secondEffectIds = data_usa_02166108;
    Unk021660f8 firstEffectIds = data_usa_021660f8;
    s32 baseX = data_usa_02155fc0.x;
    s32 baseY = data_usa_02155fc0.y;
    s32 baseZ = data_usa_02155fc0.z;
    u16 emitterIndex;
    s32 emitX = baseX >> 4;
    s32 emitY = baseY >> 4;
    s32 emitZ = baseZ >> 4;

    for (emitterIndex = 0; emitterIndex < 2; emitterIndex++) {
        s32 effectIndex;
        Vec3 position;
        Unk0201ca6c *emitter;
        SPLManager *manager = data_0217b050(&effectIndex, firstEffectIds.mUnk_00[emitterIndex]);
        position.x = emitX;
        position.y = emitY;
        position.z = emitZ;
        emitter = SPLManager_CreateEmitter(manager, effectIndex, &position);
        if (emitter != NULL) {
            if (emitter->mUnk_20->mUnk_00->mUnk_54 & 0x80) {
                emitter->mUnk_80_16 = 1;
            } else if (emitter->mUnk_20->mUnk_00->mUnk_54 & 0x40) {
                emitter->mUnk_80_16 = 2;
            }
        }
    }
    for (emitterIndex = 0; emitterIndex < 0x18; emitterIndex++) {
        s32 effectIndex;
        Vec3 position;
        Unk0201ca6c *emitter;
        SPLManager *manager = data_0217b050(&effectIndex, secondEffectIds.mUnk_00[emitterIndex]);
        position.x = baseX >> 4;
        position.y = emitY;
        position.z = emitZ;
        emitter = SPLManager_CreateEmitter(manager, effectIndex, &position);
        if (emitter != NULL) {
            if (emitter->mUnk_20->mUnk_00->mUnk_54 & 0x80) {
                emitter->mUnk_80_16 = 1;
            } else if (emitter->mUnk_20->mUnk_00->mUnk_54 & 0x40) {
                emitter->mUnk_80_16 = 2;
            }
        }
    }
}

void CreateKartPhysicalParamTable(void *heap, u32 entryCount) {
    gKartPhysicalParamTable = HeapAlloc(heap, 0x14);
    gKartPhysicalParamTable->mKartParams = HeapAlloc(heap, entryCount * 0x98);
    gKartPhysicalParamTable->mCharParams = HeapAlloc(heap, entryCount * 8);
    gKartPhysicalParamTable->mKartParamFile = FindKartModelFile(data_usa_021660c8);
    gKartPhysicalParamTable->mCharParamFile = FindKartModelFile(data_usa_021660e0);
    gKartPhysicalParamTable->mFirstBaseSpeedLimit = *OFFSET_PTR(s32, gKartPhysicalParamTable->mKartParamFile, 0x10);
}

// Copies the kart row and the character row of the files to the slot after choosing the rows (rows 0 when
// IsRaceAwardOrStaffRoll() != 0; character + 0x25 in mode 2).
void CopyKartPhysicalParams(u32 slot, u32 kartRow, u32 characterRow) {
    u8 *kartParamFile = gKartPhysicalParamTable->mKartParamFile;
    u8 *characterParamFile = gKartPhysicalParamTable->mCharParamFile;
    if (IsRaceAwardOrStaffRoll() != 0) {
        characterRow = 0;
        kartRow = characterRow;
    } else if (gRaceSetup->mMode == MODE_BATTLE) {
        kartRow = (u16) (characterRow + 0x25);
    }
    MI_CpuCopy8(kartParamFile + kartRow * 0x98, gKartPhysicalParamTable->mKartParams + slot * 0x98, 0x98);
    MI_CpuCopy8(characterParamFile + characterRow * 8, gKartPhysicalParamTable->mCharParams + slot * 8, 8);
}
