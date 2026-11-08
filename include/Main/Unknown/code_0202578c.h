#pragma once

#include "types.h"

// 12-byte entries of the table at data_usa_02153918.
typedef struct Unk02153918 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ s16 mUnk_06;
    /* 08 */ s32 mUnk_08;
} Unk02153918;

u32 func_0202578c(u32 a);
void func_02025854(u32 a, void *fileSetPointer, const char *charsName, const char *paletteName,
                   const char *screenMapName, s32 index, void *(*findFile)(const char *) );
void LoadScreenMapFileSet(void *fileSetPointer, const char *charsName, const char *paletteName,
                          const char *screenMapName, s32 index, void *(*findFile)(const char *) );
void func_020258d4(u32 a, void *fileSetPointer, const char *charsName, const char *paletteName,
                   const char *screenMapName, s32 index, void *(*findFile)(const char *) );
void LocateScreenMapFileSet(void *fileSetPointer, const char *charsName, const char *paletteName,
                            const char *screenMapName, s32 index, void *(*findFile)(const char *) );
void func_02025954(u32 a, void *fileSetPointer, u32 index);
s32 func_02025a00(u32 a, void *heap, void *fileSetPointer, void *entryPointer, s32 e);
void func_02025a50(u32 a, void *heap, void *fileSetPointer);
void LoadCellFileSet(void *fileSetPointer, const char *charsName, const char *cellsName, const char *paletteName,
                     const char *cellLayoutName, const char *labelLayoutName, const char *rectsName,
                     void *(*findFile)(const char *) );
void LocateCellFileSet(void *fileSetPointer, const char *charsName, const char *cellsName, const char *paletteName,
                       const char *cellLayoutName, const char *labelLayoutName, const char *rectsName,
                       void *(*findFile)(const char *) );
