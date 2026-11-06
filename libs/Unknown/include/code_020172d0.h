#pragma once

#include "types.h"
#include "code_0212d214.h"

typedef struct Unk0212c400 Unk0212c400;

s32 func_020172d0(s32 a);
void *NNS_FndGetNthListObject(NNSFndList *list, u16 index);
void *NNS_FndGetPrevListObject(NNSFndList *list, void *object);
void *NNS_FndGetNextListObject(NNSFndList *list, void *object);
void NNS_FndRemoveListObject(NNSFndList *list, void *object);
void NNS_FndInsertListObject(NNSFndList *list, void *target, void *object);
void NNS_FndPrependListObject(NNSFndList *list, void *object);
void NNS_FndAppendListObject(NNSFndList *list, void *object);
