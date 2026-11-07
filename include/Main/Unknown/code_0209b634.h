#pragma once

#include "types.h"
#include "Main/Unknown/code_0209bc74.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

typedef struct Unk02100094 Unk02100094;

u16 GetMapObjectModelNsbtpFrameCount(void *a);
void SetMapObjectModelNsbtpFrameIndex(void *a, u16 b);
void SetMapObjectModelNsbtaFrameIndex(void *a, s32 b);
u16 GetMapObjectModelNsbtaFrameCount(MapObjectModel *a);
s32 GetMapObjectModelNsbmaFrameCount(void *a);
void SetMapObjectModelNsbmaFrameIndex(void *a, u32 b);
u16 GetMapObjectModelNsbcaFrameCount(MapObjectModel *a);
void SetMapObjectModelNsbcaFrameIndex(MapObjectModel *a, u16 b);
void SetMapObjectModelMirror(void *a, s32 b, s32 c);
void SetMapObjectModelFogEnabled(void *a, u32 b);
void func_0209b904(void *a, u32 b, u16 c);
void SetMapObjectModelPolygonId(void *a, u32 b);
void SetMapObjectModelAlpha(void *a, u16 b);
void func_0209ba08(void *a, u32 b);
void DrawMapObjectModel1Mat1Shp(void *a, void *b, void *c);
void DrawMapObjectModelWithPos(u32 a, MapObjectModel *b, MapObject *c);
void DrawMapObjectModel(Unk02100094 *a, void *b, void *d);
void func_0209bbd0(void *a, void *b);
void *UnparkFirstParkedMapObject(void *b);
