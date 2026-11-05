#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020d94dc.h"
#include "Main/Unknown/code_020da414.h"
#include "Main/Unknown/code_020e005c.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020d6dc0.h"
#include "Main/Unknown/code_020d849c.h"
#include "Main/Unknown/code_020dc474.h"

// Object with the Unk020e0144 base at 0xc8 and its own fields from 0xec.
typedef struct Dossun {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ s32 mState;
    /* a4 */ s32 mTimer;
    /* a8 */ s32 mUnk_a8;
    /* ac */ s32 mUnk_ac;
    /* b0 */ BOOL mUnk_b0;
    /* b4 */ s32 mUnk_b4;
    /* b8 */ s16 mUnk_b8;
    /* ba */ s16 mUnk_ba;
    /* bc */ u32 mUnk_bc;
    /* c0 */ u16 mUnk_c0;
    /* c2 */ u16 mUnk_c2;
    /* c4 */ s32 mUnk_c4;
    /* c8 */ Unk020e0144 mUnk_c8;
    /* ec */ u16 mUnk_ec;
    /* ee */ u8 mUnk_ee[2];
    /* f0 */ s32 mUnk_f0;
    /* f4 */ s32 mUnk_f4;
    /* f8 */ s32 mUnk_f8;
    /* fc */ s32 mUnk_fc;
    /* 100 */ s32 mUnk_100;
    /* 104 */ s32 mUnk_104;
    /* 108 */ s32 mUnk_108;
} Dossun;

// 0x28 bytes: a function at 0x10.
typedef struct Unk020db1b0 {
    /* 00 */ u8 mUnk_00[0x10];
    /* 10 */ void (*mUnk_10)(void *a, Kuribo *p);
    /* 14 */ u8 mUnk_14[0x14];
} Unk020db1b0;

// 0x2c bytes: three functions at 0x08, 0x0c and 0x10.
typedef struct Unk020db20c {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ void (*mUnk_08)(void);
    /* 0c */ void (*mUnk_0c)(void);
    /* 10 */ void (*mUnk_10)(void *a, Kuribo *p, void *c, u16 d);
    /* 14 */ u8 mUnk_14[0x18];
} Unk020db20c;

// 0x40 bytes: two functions at 0x00 and 0x04.
typedef struct Unk020db268 {
    /* 00 */ u32 (*mUnk_00)(Kuribo *p, Kart *a, u8 *b, u8 *c);
    /* 04 */ u32 (*mUnk_04)(Kuribo *p, Kart *a, u8 *b, u8 *c);
    /* 08 */ u8 mUnk_08[0x38];
} Unk020db268;

// 0x28 bytes: a function at 0x10.
typedef struct Unk020dbe74 {
    /* 00 */ u8 mUnk_00[0x10];
    /* 10 */ void (*mUnk_10)(void *a, Dossun *p);
    /* 14 */ u8 mUnk_14[0x14];
} Unk020dbe74;

// 0x2c bytes: functions at 0x08 and 0x10.
typedef struct Unk020dbed0 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ void (*mUnk_08)(void);
    /* 0c */ u8 mUnk_0c[4];
    /* 10 */ void (*mUnk_10)(void *a, Dossun *p, void *c, s32 d);
    /* 14 */ u8 mUnk_14[0x18];
} Unk020dbed0;

// 0x40 bytes: a function at 0x00.
typedef struct Unk020dbf2c {
    /* 00 */ u32 (*mUnk_00)(Dossun *p, Kart *a, u8 *b, u8 *c);
    /* 04 */ u8 mUnk_04[0x3c];
} Unk020dbf2c;

Unk020dbf2c *func_020dbf2c(void);
Unk020dbed0 *func_020dbed0(void);
Unk020dbe74 *func_020dbe74(void);
Unk020db268 *func_020db268(void);
Unk020db20c *func_020db20c(void);
Unk020db1b0 *func_020db1b0(void);
s32 func_020db4c4(Dossun *p);
void func_020db430(Dossun *p);
void CreateDossunAndDossunShadow(void);
void InitDossun(Dossun *p, CourseMapRow *a);
void func_020db198(void);
void DrawKuribo(void *a, Kuribo *p, void *c, u16 d);
void UpdateKuribo(void *a, Kuribo *p); /* skipped for objects with mFlags & 4 (parked pool objects) */
void DrawDossun(void *a, Dossun *p, void *c, s32 d);
u32 func_020db548(Dossun *p, Kart *a, u8 *b, u8 *c);
void UpdateDossun(void *a, Dossun *p); /* skipped for objects with mFlags & 4 (parked pool objects) */
