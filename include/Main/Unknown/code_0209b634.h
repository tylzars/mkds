#pragma once

#include "types.h"
#include "Main/Unknown/code_0209bc74.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

typedef struct MapObjectList MapObjectList;

u16 GetMapObjectModelNsbtpFrameCount(void *a);
void SetMapObjectModelNsbtpFrameIndex(void *a, u16 frameIndex);
void SetMapObjectModelNsbtaFrameIndex(void *a, s32 frameIndex);
u16 GetMapObjectModelNsbtaFrameCount(MapObjectModel *mapObjectModel);
s32 GetMapObjectModelNsbmaFrameCount(void *a);
void SetMapObjectModelNsbmaFrameIndex(void *a, u32 frameIndex);
u16 GetMapObjectModelNsbcaFrameCount(MapObjectModel *mapObjectModel);
void SetMapObjectModelNsbcaFrameIndex(MapObjectModel *mapObjectModel, u16 frameIndex);
void SetMapObjectModelMirror(void *a, s32 b, s32 c);
void SetMapObjectModelFogEnabled(void *a, u32 fogEnabled);
void SetMapObjectModelMaterialPolygonId(void *a, u32 polygonId, u16 matId);
void SetMapObjectModelPolygonId(void *a, u32 polygonId);
void SetMapObjectModelAlpha(void *a, u16 alpha);
void SetMapObjectModelLightEnableFlag(void *a, u32 light);
void DrawMapObjectModel1Mat1Shp(void *a, void *b, void *c);
void DrawMapObjectModelWithPos(u32 a, MapObjectModel *mapObjectModel, MapObject *mapObject);
void DrawMapObjectModel(MapObjectList *mapObjectList, void *b, void *d);
void func_0209bbd0(void *a, void *b);
void *UnparkFirstParkedMapObject(void *b);
