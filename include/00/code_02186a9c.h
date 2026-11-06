#pragma once

#include "types.h"

typedef struct Http Http;

BOOL DWC_Http_Add_Body(Http *a, const char *b);
BOOL DWC_Http_Add_PostBase64Item(Http *a, const char *b, const void *c, s32 d);
BOOL DWC_Http_Add_HeaderItem(Http *a, const char *b, const char *c);
BOOL DWCi_Http_WriteBasicHeader(Http *a);
