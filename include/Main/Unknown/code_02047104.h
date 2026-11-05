#pragma once

#include "types.h"

void *LoadKartModelFile(const char *path);
void *FindKartModelFile(const char *path);
void *FindCourseFile(const char *path);
void *FindSceneFile(const char *name);
void *FindMainRaceOrMainEffectFile(const char *path);
u32 FindArchiveFile(u32 archiveName, const char *path);

// 0x18-byte entries.
typedef struct Unk021543e0 {
    /* 00 */ const char *mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s8 mUnk_08;
    /* 09 */ u8 mUnk_09[0x3];
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
} Unk021543e0;

// 8-byte entries of a string and a number.
typedef struct Unk021541a8 {
    /* 00 */ const char *mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk021541a8;

#include "Main/Unknown/unk_02175000.h"

// The scene-name table, 16 rows indexed by scene number like gSceneFuncs: 0 'Title', 1 'Menu', 2 'Race', 3 'Emblem',
// 4 'Menu', 5 'Test', 6 'WLMenu', 7 'Option', 8 'Record', 9 'Logo', 10 'Result', 11 'Nickname', 12 'WiFiMenu',
// 13 'Ghost', 14 'Keyboard', 15 'Ending'.
extern Unk021541a8 gSceneNames[];
extern Unk021543e0 data_usa_021543e0[];
extern const char data_usa_02165008[];
extern const char data_usa_02165010[];
extern const char data_usa_02165018[];
extern const char data_usa_02165020[];
extern const char data_usa_02165028[];
extern const char data_usa_02165030[];
extern const char data_usa_02165038[];
extern const char data_usa_02165040[];
extern const char data_usa_02165058[];
extern const char data_usa_021650e0[];
extern const char data_usa_021650e4[];
extern const char data_usa_021650e8[];
extern const char data_usa_02165100[];
extern const char data_usa_02165108[];
extern const char data_usa_0216510c[];
extern const char data_usa_02165110[];
extern const char data_usa_02165124[];

void func_02047104(void *a);
void func_02047178(void);
void func_020471b0(void *a);
void func_02047220(void *a, u32 b);
s32 func_02047250(void);
void func_02047274(void);
void func_020472a8(void);
void func_020472e4(void *a, void *b);
void func_020473a8(void);
void func_020473e4(void);
void func_02047468(const void *a, u32 b);
void func_02047498(const void *a, s32 b);
void func_020474e4(void);
void func_02047544(Unk02017f24 *a, Unk02017f24 *b, Unk02017f24 *c);
void func_02047634(Unk02017f24 *a, s32 b, s32 c, u32 d, u32 e);
void func_020476ac(void);
void func_020476ec(void);
void func_02047728(void);
void func_0204775c(void);
void *func_02047950(const char *path);
void *func_02047a28(const char *name);
void func_02047b6c(u16 arg0);
void func_02047b88(void);
void func_02047ba0(s32 a);
void func_02047cf0(int a);
void func_02047db8(void);
void func_02047e0c(void);
void func_02047e94(void);
void func_02047f7c(s32 a, const char *b, u32 *c, void *d, s32 e, s32 f, s32 g);
void func_02048050(int a, int b);
void func_02048284(u32 a, char *b);
void func_020482ac(char *a, u8 *b, int c);
void func_020482f0(char *a, const char *b, int c);
void func_02048324(char *a);
void func_02048350(char *a);
void func_020483a0(char *a);
