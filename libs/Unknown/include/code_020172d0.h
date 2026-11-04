#pragma once

#include "types.h"
#include "code_0212da38.h" // Unk02017328

s32 func_020172d0(s32 a);
void *ListGetNth(Unk02017328 *a, s32 b);
void *ListGetPrev(Unk02017328 *a, void *p);
void *ListGetNext(Unk02017328 *a, void *p);
void ListRemove(Unk02017328 *a, void *p);
// Inserts q in front of p; a NULL p appends q at the end.
void ListInsertBefore(Unk02017328 *a, void *p, void *q);
void ListPrepend(Unk02017328 *a, void *p);
void ListAppend(Unk02017328 *a, void *p);
