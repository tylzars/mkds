#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_020ea618.h"
#include "Main/Unknown/code_020ea670.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_020109c4.h"
#include "code_02012b30.h"

// Unparks and returns the first parked map object of the list, or NULL if the list is NULL or has none.
void *UnparkFirstParkedMapObject(void *b) {
    MapObjectList *mapObjectList = b;
    MapObject *mapObject;
    s32 i;

    if (mapObjectList != NULL) {
        for (i = 0; i < mapObjectList->mMapObjectCount && (mapObject = mapObjectList->mMapObjects[i]) != NULL; i++) {
            if ((mapObject->mFlags & 0x100) != 0) {
                UnparkMapObject(mapObject);
                return mapObject;
            }
        }
    }
    return NULL;
}

void func_0209bbd0(void *a, void *b) {
    MapObjectModel *mapObjectModel = b;

    if (mapObjectModel->mNsbmdModel == NULL) {
        return;
    }
    func_020e6a18(mapObjectModel->mNsbmdModel);
}

void DrawMapObjectModel(MapObjectList *mapObjectList, void *b, void *d) {
    MapObjectModel *mapObjectModel = b;
    MapObject *mapObject = d;

    func_01ff9048(0x1b, mapObjectModel, 3);
    if (mapObjectModel->mNsbmdModel != NULL) {
        func_020ea5b0(mapObjectModel->mNsbmdModel, mapObject->mAlpha, NULL);
    }
    if (mapObjectModel->mAnimatedModel == NULL && mapObjectModel->mShadowModel == NULL) {
        return;
    }
    if (mapObjectModel->mAnimatedModel != NULL) {
        if (mapObjectModel->mAnimations[2] != NULL) {
            func_020ea670(mapObjectModel->mAnimatedModel, mapObject->mAlpha);
        } else {
            DrawNsbmdWithMaxAlpha(mapObjectModel->mAnimatedModel, mapObject->mAlpha);
        }
    }
    if (mapObjectModel->mShadowModel == NULL) {
        return;
    }
    DrawShadowModelWithMaxAlpha(mapObjectModel->mShadowModel, mapObject->mAlpha);
}

// Like DrawMapObjectModel but passes the object's position to the model draw, which lowers the alpha of an object whose
// camera depth is below its alpha level (near fade) and picks a polygon id for it.
void DrawMapObjectModelWithPos(u32 a, MapObjectModel *mapObjectModel, MapObject *mapObject) {
    MapObjectModel *o = mapObjectModel;

    func_01ff9048(0x1b, o, 3);
    if (o->mNsbmdModel != NULL) {
        func_020ea5b0(o->mNsbmdModel, mapObject->mAlpha, &mapObject->mPos);
    }
    if (o->mAnimatedModel == NULL && o->mShadowModel == NULL) {
        return;
    }
    if (o->mAnimatedModel != NULL) {
        if (o->mAnimations[2] != NULL) {
            func_020ea670(o->mAnimatedModel, mapObject->mAlpha);
        } else {
            DrawNsbmdWithMaxAlpha(o->mAnimatedModel, mapObject->mAlpha);
        }
    }
    if (o->mShadowModel == NULL) {
        return;
    }
    DrawShadowModelWithMaxAlpha(o->mShadowModel, mapObject->mAlpha);
}

void DrawMapObjectModel1Mat1Shp(void *a, void *b, void *c) {
    MapObjectModel *mapObjectModel = b;

    if (mapObjectModel->mAnimatedModel == NULL) {
        return;
    }
    DrawNsbmd1Mat1ShpWithMaxAlpha(mapObjectModel->mAnimatedModel, ((MapObject *) c)->mAlpha);
}

void SetMapObjectModelLightEnableFlag(void *a, u32 light) {
    MapObjectModel *mapObjectModel = a;
    NsbmdModel *nsbmdModel = mapObjectModel->mNsbmdModel;

    if (nsbmdModel != NULL) {
        nsbmdModel->mUnk_14 &= ~0xf;
        nsbmdModel->mUnk_14 |= light;
    }
    if (mapObjectModel->mAnimatedModel == NULL) {
        return;
    }
    SetNsbmdLightEnableFlagAll(mapObjectModel->mAnimatedModel, light);
}

void SetMapObjectModelAlpha(void *a, u16 alpha) {
    MapObjectModel *mapObjectModel = a;
    NsbmdModel *nsbmdModel = mapObjectModel->mNsbmdModel;

    if (nsbmdModel != NULL) {
        nsbmdModel->mUnk_14 &= ~0x1f0000;
        nsbmdModel->mUnk_14 |= alpha << 16;
    }
    if (mapObjectModel->mAnimatedModel != NULL) {
        NNS_G3dMdlSetMdlAlphaAll(mapObjectModel->mAnimatedModel->mResMdl, alpha);
    }
    if (mapObjectModel->mShadowModel != NULL) {
        mapObjectModel->mShadowModel->mAlpha = alpha;
    }
}

// Stores a polygon id (6 bits at bit 24 of the polygon attribute) in every model the bundle holds; 0x3f at creation,
// The draw may replace this polygon id.
void SetMapObjectModelPolygonId(void *a, u32 polygonId) {
    MapObjectModel *mapObjectModel = a;
    NsbmdModel *nsbmdModel = mapObjectModel->mNsbmdModel;

    if (nsbmdModel != NULL) {
        nsbmdModel->mUnk_14 &= ~0x3f000000;
        nsbmdModel->mUnk_14 |= polygonId << 24;
    }
    if (mapObjectModel->mAnimatedModel != NULL) {
        NNS_G3dMdlSetMdlPolygonIDAll(mapObjectModel->mAnimatedModel->mResMdl, polygonId);
    }
    if (mapObjectModel->mShadowModel != NULL) {
        mapObjectModel->mShadowModel->mPolygonId = polygonId;
    }
}

void SetMapObjectModelMaterialPolygonId(void *a, u32 polygonId, u16 matId) {
    MapObjectModel *mapObjectModel = a;

    if (mapObjectModel->mAnimatedModel == NULL) {
        return;
    }
    NNS_G3dMdlSetMdlPolygonID(mapObjectModel->mAnimatedModel->mResMdl, matId, polygonId);
}

void SetMapObjectModelFogEnabled(void *a, u32 fogEnabled) {
    MapObjectModel *mapObjectModel = a;
    NsbmdModel *nsbmdModel = mapObjectModel->mNsbmdModel;

    if (nsbmdModel != NULL) {
        if (fogEnabled != 0) {
            nsbmdModel->mUnk_14 |= 0x8000;
        } else {
            nsbmdModel->mUnk_14 &= ~0x8000;
        }
    }
    if (mapObjectModel->mAnimatedModel == NULL) {
        return;
    }
    NNS_G3dMdlSetMdlFogEnableFlagAll(mapObjectModel->mAnimatedModel->mResMdl, fogEnabled);
}

void SetMapObjectModelMirror(void *a, s32 b, s32 c) {
    MapObjectModel *mapObjectModel = a;
    NsbmdModel *nsbmdModel;
    s32 mirrored;

    if (mapObjectModel->mNsbmdModel != NULL) {
        nsbmdModel = mapObjectModel->mNsbmdModel;
        mirrored = b != 0 || c != 0 ? 1 : 0;
        if (mirrored ^ gRaceSetup->mMirrorMode) {
            nsbmdModel->mUnk_14 &= ~0x80;
            mapObjectModel->mNsbmdModel->mUnk_14 |= 0x40;
        } else {
            nsbmdModel->mUnk_14 |= 0x80;
            mapObjectModel->mNsbmdModel->mUnk_14 &= ~0x40;
        }
    }
    if (mapObjectModel->mAnimatedModel != NULL) {
        mirrored = b != 0 || c != 0 ? 1 : 0;
        if (mirrored ^ gRaceSetup->mMirrorMode) {
            SetNsbmdCullModeAll(mapObjectModel->mAnimatedModel, 1);
        } else {
            SetNsbmdCullModeAll(mapObjectModel->mAnimatedModel, 2);
        }
    }
    mapObjectModel->mScale.mUnk_00 = b != 0 ? -0x1000 : 0x1000;
    mapObjectModel->mScale.mUnk_04 = c != 0 ? -0x1000 : 0x1000;
}

// Sets the current frame of slot 0 in 20.12 fixed point (the track frame follows).
void SetMapObjectModelNsbcaFrameIndex(MapObjectModel *mapObjectModel, u16 frameIndex) {
    MapObjectModel *o = mapObjectModel;
    ModelAnimation *animation = o->mAnimations[0];

    animation->mFrameIndex = frameIndex << 12;
    animation->mAnmObjs[animation->mCurrentIndex]->mFrame = animation->mFrameIndex;
}

// Number of frames of the animation in slot 0 (its length, not the current frame).
u16 GetMapObjectModelNsbcaFrameCount(MapObjectModel *mapObjectModel) {
    MapObjectModel *o = mapObjectModel;

    return (u32) GetModelAnimationFrameCountFixed(o->mAnimations[0]) >> 12;
}

// Sets the current frame of slot 2 in 20.12 fixed point (the track frame follows).
void SetMapObjectModelNsbmaFrameIndex(void *a, u32 frameIndex) {
    MapObjectModel *o = a;
    ModelAnimation *animation = o->mAnimations[2];

    animation->mFrameIndex = frameIndex << 12;
    animation->mAnmObjs[animation->mCurrentIndex]->mFrame = animation->mFrameIndex;
}

// Number of frames of the animation in slot 2 (its length, not the current frame).
s32 GetMapObjectModelNsbmaFrameCount(void *a) {
    MapObjectModel *o = a;

    return (u16) ((u32) GetModelAnimationFrameCountFixed(o->mAnimations[2]) >> 12);
}

// Number of frames of the animation in slot 3 (its length, not the current frame).
u16 GetMapObjectModelNsbtaFrameCount(MapObjectModel *mapObjectModel) {
    MapObjectModel *o = mapObjectModel;

    return (u32) GetModelAnimationFrameCountFixed(o->mAnimations[3]) >> 12;
}

// Sets the current frame of slot 3 in 20.12 fixed point (the track frame follows).
void SetMapObjectModelNsbtaFrameIndex(void *a, s32 frameIndex) {
    MapObjectModel *o = a;
    ModelAnimation *animation = o->mAnimations[3];

    animation->mFrameIndex = frameIndex << 12;
    animation->mAnmObjs[animation->mCurrentIndex]->mFrame = animation->mFrameIndex;
}

void SetMapObjectModelNsbtpFrameIndex(void *a, u16 frameIndex) {
    MapObjectModel *o = a;
    ModelAnimation *animation;

    if (o->mNsbmdModel != NULL) {
        o->mNsbmdModel->mFrameIndex = frameIndex;
        return;
    }
    if (o->mAnimatedModel == NULL) {
        return;
    }
    animation = o->mAnimations[1];
    animation->mFrameIndex = frameIndex << 12;
    animation->mAnmObjs[animation->mCurrentIndex]->mFrame = animation->mFrameIndex;
}

u16 GetMapObjectModelNsbtpFrameCount(void *a) {
    MapObjectModel *o = a;

    if (o->mNsbmdModel != NULL) {
        return o->mNsbmdModel->mFrameCount;
    }
    if (o->mAnimatedModel == NULL) {
        return 0;
    }
    return (u32) GetModelAnimationFrameCountFixed(o->mAnimations[1]) >> 12;
}
