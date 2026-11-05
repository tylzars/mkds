#pragma once

#include "types.h"

typedef struct MapObjectModel MapObjectModel;

void CreateMapObjectModelNsbcaAnimation(MapObjectModel *a, const char *b);
void *CreateMapObjectModelAnimated(void *a, const char *b);
void *CreateMapObjectModelNsbmdNsbtp(void *a, const char *b, const char *c);
void *CreateMapObjectModelNsbmd(void *a, const char *b);
void *CreateMapObjectModelShadow(void *a, const char *b);
void CreateMapObjectModelNsbtpAnimation(MapObjectModel *a, const char *b);
void CreateMapObjectModelNsbtaAnimation(MapObjectModel *a, const char *b);
