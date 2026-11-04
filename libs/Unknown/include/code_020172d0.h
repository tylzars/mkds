#pragma once

#include "types.h"
#include "code_0212d214.h"

s32 func_020172d0(s32 a);
void *ListGetNth(LinkedList *a, s32 b);
void *ListGetPrev(LinkedList *a, void *p);
void *ListGetNext(LinkedList *a, void *p);
void ListRemove(LinkedList *a, void *p);
// Inserts q in front of p; a NULL p appends q at the end.
void ListInsertBefore(LinkedList *a, void *p, void *q);
void ListPrepend(LinkedList *a, void *p);
void ListAppend(LinkedList *a, void *p);
