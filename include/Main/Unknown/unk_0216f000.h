#pragma once

#include "types.h"
#include "code_0200db4c.h"
#include "code_02142eac.h" // Unk02143a78

// Three words that func_0200c448 sets up.
typedef struct Unk0216fdf8 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
} Unk0216fdf8;

// Object behind data_0216fdf4: the words from 0x1e0 on are indexed like the 0x20-byte entries before them.
typedef struct Unk0216fdf4 {
    /* 000 */ u8 mUnk_000[0x1e0];
    /* 1e0 */ u32 mUnk_1e0[15];
} Unk0216fdf4;

// Objects whose layout isn't known yet.
extern u32 data_0216f06c;
extern char data_0216f2a0[];
extern s8 data_0216f2b0[];
extern const char data_0216f2d4[];
extern u32 data_0216f3c8;
extern u8 data_0216f3cc[];
extern s16 data_0216f3d0;
extern s16 data_0216f3d4;
struct Unk02007014;
extern struct Unk02007014 *data_0216f3d8;
extern u8 data_0216f3dc[];
extern u8 data_0216f478[];
struct Unk0216fda8;
extern struct Unk0216fda8 *data_0216fda8;
struct Unk0216fdac;
extern struct Unk0216fdac *data_0216fdac;
struct Unk0200aeec_head;
extern struct Unk0200aeec_head *data_0216fde0;
extern u8 data_0216fde4[];
struct Unk0216fde8;
extern struct Unk0216fde8 *data_0216fde8;
struct Unk0216fdec;
extern struct Unk0216fdec *data_0216fdec;
struct Unk0216fdf4;
extern struct Unk0216fdf4 *data_0216fdf4;
extern u8 data_0216fdf0;
extern Unk0216fdf8 data_0216fdf8;
extern u8 data_0216f2dc[];
extern u8 OverlaySignatures[][0x14];

extern u8 data_0216f070[];
extern u32 data_0216f074[];
extern void (*data_0216fc34)(void);
extern void (*data_0216fc38)(u8 *);
extern Unk02143a78 data_0216fdc0;

extern u32 data_0216ff44;
extern u32 data_0216ff48;
extern u32 data_0216ff4c;
extern void (*data_0216ff50)(Unk0200db5c *, Unk0200db5c *);
extern Unk0200db5c **data_0216ff54;
extern u32 data_0216ff58;
extern ThreadSystem data_0216ff5c;
extern Unk0200db5c data_0216ff6c;
