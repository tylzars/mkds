#pragma once

#include "Main/Unknown/code_02074854.h"
#include "Main/Unknown/code_0207a104.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02086058.h"
#include "Main/Unknown/code_0210a578.h"

#include "types.h"
#include "Main/Unknown/code_02039774.h"
#include "code_02012b30.h" // Unk02012f58
#include "code_02148538.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_0210b000.h" // Unk0210b7ec
#include "Main/Unknown/code_02080b1c.h" // Unk020905a8
#include "code_0212da38.h" // Unk02017328

typedef struct UnkVec16 {
    s16 x;
    s16 y;
    s16 z;
} UnkVec16;

struct Unk020888b4;

typedef struct Unk0206c1ac_B {
    /* 0 */ u32 mUnk_00;
    /* 4 */ Vec3 mUnk_04;
} Unk0206c1ac_B;

typedef struct Unk0206c1ac_A {
    /* 0 */ Unk0206c1ac_B *mUnk_00;
} Unk0206c1ac_A;

typedef struct Unk0206c1ac {
    /* 0 */ u8 mUnk_00[0x20];
    /* 20 */ Unk0206c1ac_A *mUnk_20;
    /* 24 */ u8 mUnk_24[4];
    /* 28 */ Vec3 mUnk_28;
    /* 34 */ u8 mUnk_34[0xc];
    /* 40 */ Vec3 mUnk_40;
    /* 4c */ u8 mUnk_4c[4];
    /* 50 */ UnkVec16 mUnk_50;
    /* 56 */ u8 mUnk_56[0x16];
    /* 6c */ s32 mUnk_6c;
    /* 70 */ u8 mUnk_70[2];
    /* 72 */ u16 mUnk_72;
} Unk0206c1ac;

typedef struct Unk0206cdd4_A {
    /* 0 */ s32 mUnk_00;
    /* 4 */ s32 mUnk_04;
    /* 8 */ s32 mUnk_08;
    /* c */ s16 mUnk_0c;
    /* e */ s16 mUnk_0e;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s16 mUnk_30;
    /* 32 */ s16 mUnk_32;
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38[12];
    /* 68 */ s32 mUnk_68[12];
} Unk0206cdd4_A;

typedef struct Unk0206cdd4_B {
    /* 0 */ s32 mUnk_00;
    /* 4 */ s32 mUnk_04;
    /* 8 */ s32 mUnk_08;
    /* c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
} Unk0206cdd4_B;

struct Unk0206bcb0;

// 16-byte entry of the table at Unk0217d26c::mUnk_04: func_0210dd44 calls mUnk_04 with the words at 8 and 0xc.
typedef struct Unk0210ddf4 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ void (*mUnk_04)(void *, s32);
    /* 08 */ void *mUnk_08;
    /* 0c */ s32 mUnk_0c;
} Unk0210ddf4;

typedef struct Unk0217d26c {
    /* 0 */ s32 mUnk_00;
    /* 4 */ Unk0210ddf4 *mUnk_04;
} Unk0217d26c;

extern Unk0217d26c data_0217d294;
extern Unk0217d26c data_0217d29c;

typedef struct Unk0206ceb4 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mUnk_02;
    /* 04 */ s16 mUnk_04;
    /* 06 */ s16 mUnk_06;
    /* 08 */ s16 mUnk_08;
    /* 0a */ s16 mUnk_0a;
    /* 0c */ s16 mUnk_0c;
    /* 0e */ s16 mUnk_0e;
    /* 10 */ s16 mUnk_10;
    /* 12 */ s16 mUnk_12;
    /* 14 */ s16 mUnk_14;
    /* 16 */ s16 mUnk_16;
    /* 18 */ s16 mUnk_18;
    /* 1a */ s16 mUnk_1a;
    /* 1c */ s16 mUnk_1c;
    /* 1e */ s16 mUnk_1e;
    /* 20 */ s16 mUnk_20;
    /* 22 */ u8 mUnk_22[2];
    /* 24 */ s32 mUnk_24;
    /* 28 */ s16 mUnk_28;
    /* 2a */ u8 mUnk_2a[2];
    /* 2c */ Unk020905a8 mUnk_2c;
} Unk0206ceb4;

typedef struct Unk0206bcb0_514 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ Vec3 mUnk_10;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ u32 mUnk_2c;
    /* 30 */ u32 mUnk_30;
    /* 34 */ Vec3 mUnk_34;
    /* 40 */ s16 mUnk_40;
    /* 42 */ u8 mUnk_42[2];
    /* 44 */ u32 mUnk_44;
    /* 48 */ u32 mUnk_48;
    /* 4c */ Vec4 mUnk_4c;
    /* 5c */ s16 mUnk_5c;
    /* 5e */ u8 mUnk_5e[2];
    /* 60 */ s32 mUnk_60;
    /* 64 */ s32 mUnk_64;
    /* 68 */ u8 mUnk_68[0x18];
    /* 80 */ Unk02017328 mUnk_80;
    /* 8c */ Unk02017328 mUnk_8c;
    /* 98 */ Vec3 mUnk_98;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ Vec3 mUnk_a8;
    /* b4 */ u16 mUnk_b4;
} Unk0206bcb0_514;

typedef struct Unk0206c5e4_208 {
    /* 0 */ s32 mUnk_00;
} Unk0206c5e4_208;

// The 0x38 bytes at 0x450 of a Unk0206bcb0: words at 0x08, 0x28, 0x30 and 0x34 and a byte at 0x2c.
typedef struct Unk0206bcb0_A {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u8 mUnk_04[4];
    /* 08 */ s32 mUnk_08;
    /* 0c */ u8 mUnk_0c[0x1c];
    /* 28 */ s32 mUnk_28;
    /* 2c */ u8 mUnk_2c;
    /* 2d */ u8 mUnk_2d[3];
    /* 30 */ u32 mUnk_30;
    /* 34 */ u32 mUnk_34;
} Unk0206bcb0_A;

typedef struct Unk0206bcb0 {
    /* 00 */ Unk0210bfbc mUnk_00;
    /* 44 */ vu32 mUnk_44;
    /* 48 */ vu32 mUnk_48;
    /* 4c */ vu32 mUnk_4c;
    /* 50 */ Vec3 mUnk_50;
    /* 05c */ Vec3 mUnk_05c;
    /* 68 */ Vec3 mUnk_68;
    /* 74 */ u16 mIndex;
    /* 76 */ u8 mUnk_76[0x2];
    /* 78 */ s32 mUnk_78;
    /* 7c */ vu32 mUnk_7c;
    /* 80 */ Vec3 mUnk_80;
    /* 8c */ Vec3 mUnk_8c;
    /* 98 */ Vec3 mUnk_98;
    /* a4 */ Vec3 mUnk_a4;
    /* b0 */ Vec3 mUnk_b0;
    /* bc */ Vec3 mUnk_bc;
    /* c8 */ s32 mUnk_c8;
    /* cc */ s32 mUnk_cc;
    /* d0 */ s32 mUnk_d0;
    /* d4 */ u32 mUnk_d4;
    /* d8 */ s32 mUnk_d8;
    /* dc */ s32 mUnk_dc;
    /* e0 */ union {
        struct {
            s32 mUnk_e0;
            Vec3 mUnk_e4;
            Vec3 mUnk_f0;
            u32 mUnk_fc;
            s32 mUnk_100;
            struct Unk020e04b0 *mUnk_104;
            Vec3 mUnk_108;
            u8 mUnk_114[6];
            s16 mUnk_11a;
            s32 mUnk_11c;
        };
        struct {
            Vec4 mUnk_e0_m;
            Vec4 mUnk_f0_q;
            Vec4 mUnk_100_q;
            Vec4 mUnk_110_q;
        };
    };
    /* 120 */ union {
        struct {
            Vec3 mUnk_120;
            Vec3 mUnk_12c;
            Vec3 mUnk_138;
            Vec3 mUnk_144;
        };
        Unk02012f58 mUnk_120_m;
    };
    /* 150 */ union {
        struct {
            Vec3 mUnk_150;
            Vec3 mUnk_15c;
            Vec3 mUnk_168;
            Vec3 mUnk_174;
        };
        Unk02012f58 mUnk_150_m;
    };
    /* 180 */ vs32 mState;
    /* 184 */ Unk02012f58 mUnk_184_m;
    /* 1b4 */ Unk02012f58 *mUnk_1b4;
    /* 1b8 */ Vec3 mUnk_1b8;
    /* 1c4 */ Vec3 mUnk_1c4;
    /* 1d0 */ s32 mUnk_1d0;
    /* 1d4 */ s32 mUnk_1d4;
    /* 1d8 */ Vec3 mUnk_1d8;
    /* 1e4 */ Vec3 mUnk_1e4;
    /* 1f0 */ Vec3 mUnk_1f0;
    /* 1fc */ Vec3 mUnk_1fc;
    /* 208 */ Unk0206c5e4_208 *mUnk_208;
    /* 20c */ union {
        void (*mUnk_20c_fn[9])(struct Unk0206bcb0 *);
        struct {
            u8 mUnk_20c[4];
            void (*mUnk_210)(struct Unk0206bcb0 *);
            u8 mUnk_214[8];
            s32 mUnk_21c;
            void (*mUnk_220)(struct Unk0206bcb0 *);
            u8 mUnk_224[4];
            struct Unk020ee684 *mUnk_228;
            u8 mUnk_22c[4];
        };
    };
    /* 230 */ void (*mUnk_230)(struct Unk0206bcb0 *);
    /* 234 */ s16 mUnk_234;
    /* 236 */ u16 mUnk_236;
    /* 238 */ s16 mUnk_238;
    /* 23a */ s16 mUnk_23a;
    /* 23c */ s16 mUnk_23c;
    /* 23e */ u8 mUnk_23e[2];
    /* 240 */ u32 mUnk_240;
    /* 244 */ Vec3 mUnk_244;
    /* 250 */ Vec3 mUnk_250;
    /* 25c */ s32 mUnk_25c;
    /* 260 */ s32 mUnk_260;
    /* 264 */ u8 mUnk_264[4];
    /* 268 */ Vec3 mUnk_268;
    /* 274 */ s32 mUnk_274;
    /* 278 */ Vec3 mUnk_278;
    /* 284 */ Vec3 mUnk_284;
    /* 290 */ Vec3 mUnk_290;
    /* 29c */ s32 mUnk_29c;
    /* 2a0 */ s32 mUnk_2a0;
    /* 2a4 */ s32 mUnk_2a4;
    /* 2a8 */ s32 mUnk_2a8;
    /* 2ac */ s32 mUnk_2ac;
    /* 2b0 */ u16 mUnk_2b0;
    /* 2b2 */ u16 mUnk_2b2;
    /* 2b4 */ u16 mUnk_2b4;
    /* 2b6 */ u8 mUnk_2b6[2];
    /* 2b8 */ s32 mUnk_2b8;
    /* 2bc */ s32 mUnk_2bc;
    /* 2c0 */ u16 mUnk_2c0;
    /* 2c2 */ u8 mUnk_2c2[2];
    /* 2c4 */ s32 mUnk_2c4;
    /* 2c8 */ s16 mUnk_2c8;
    /* 2ca */ s16 mUnk_2ca;
    /* 2cc */ Unk0206cdd4_A *mUnk_2cc;
    /* 2d0 */ s32 *mUnk_2d0;
    /* 2d4 */ s32 mUnk_2d4;
    /* 2d8 */ Vec3 mUnk_2d8;
    /* 2e4 */ Vec3 mUnk_2e4;
    /* 2f0 */ Vec3 mUnk_2f0;
    /* 2fc */ s32 mUnk_2fc;
    /* 300 */ u16 mUnk_300;
    /* 302 */ u16 mUnk_302;
    /* 304 */ u16 *mUnk_304;
    /* 308 */ u16 *mUnk_308;
    /* 30c */ s32 mUnk_30c;
    /* 310 */ struct Unk020888b4 *mUnk_310;
    /* 314 */ u16 mUnk_314;
    /* 316 */ u8 mUnk_316[2];
    /* 318 */ s32 mUnk_318;
    /* 31c */ Vec3 mUnk_31c;
    /* 328 */ Vec3 mUnk_328;
    /* 334 */ s32 mUnk_334;
    /* 338 */ u16 mUnk_338;
    /* 33a */ u8 mUnk_33a[2];
    /* 33c */ s32 mUnk_33c;
    /* 340 */ s32 mUnk_340;
    /* 344 */ s32 mUnk_344;
    /* 348 */ s32 mUnk_348;
    /* 34c */ Vec4 mUnk_34c;
    /* 35c */ s16 mUnk_35c;
    /* 35e */ u8 mUnk_35e[2];
    /* 360 */ s32 mUnk_360;
    /* 364 */ u16 mUnk_364;
    /* 366 */ u16 mUnk_366;
    /* 368 */ s32 mUnk_368;
    /* 36c */ s32 mUnk_36c;
    /* 370 */ u16 mUnk_370;
    /* 372 */ u8 mUnk_372[2];
    /* 374 */ Vec3 mUnk_374;
    /* 380 */ u32 mUnk_380;
    /* 384 */ u16 mUnk_384;
    /* 386 */ s16 mUnk_386;
    /* 388 */ s16 mUnk_388;
    /* 38a */ s16 mUnk_38a;
    /* 38c */ s32 mUnk_38c;
    /* 390 */ u8 mUnk_390[4];
    /* 394 */ s32 mUnk_394;
    /* 398 */ s32 mUnk_398;
    /* 39c */ s32 mUnk_39c;
    /* 3a0 */ s32 mUnk_3a0;
    /* 3a4 */ u16 mUnk_3a4;
    /* 3a6 */ u8 mUnk_3a6[2];
    /* 3a8 */ s32 mUnk_3a8;
    /* 3ac */ u16 mUnk_3ac;
    /* 3ae */ u8 mUnk_3ae[2];
    /* 3b0 */ Vec3 mUnk_3b0;
    /* 3bc */ u16 mUnk_3bc;
    /* 3be */ u16 mUnk_3be;
    /* 3c0 */ s16 mUnk_3c0;
    /* 3c2 */ u8 mUnk_3c2[2];
    /* 3c4 */ s32 mUnk_3c4;
    /* 3c8 */ s16 mUnk_3c8;
    /* 3ca */ u8 mUnk_3ca[2];
    /* 3cc */ s32 mUnk_3cc;
    /* 3d0 */ s16 mUnk_3d0;
    /* 3d2 */ s16 mUnk_3d2;
    /* 3d4 */ s16 mUnk_3d4;
    /* 3d6 */ u8 mUnk_3d6[2];
    /* 3d8 */ s32 mUnk_3d8;
    /* 3dc */ s32 mUnk_3dc;
    /* 3e0 */ s32 mUnk_3e0;
    /* 3e4 */ s32 mUnk_3e4;
    /* 3e8 */ s16 mUnk_3e8;
    /* 3ea */ u8 mUnk_3ea[2];
    /* 3ec */ s32 mUnk_3ec;
    /* 3f0 */ s32 mUnk_3f0;
    /* 3f4 */ s32 mUnk_3f4;
    /* 3f8 */ s32 mUnk_3f8;
    /* 3fc */ u16 mUnk_3fc;
    /* 3fe */ u16 mUnk_3fe;
    /* 400 */ u16 mUnk_400;
    /* 402 */ u8 mUnk_402[2];
    /* 404 */ s32 mUnk_404;
    /* 408 */ s32 mUnk_408;
    /* 40c */ s32 mUnk_40c;
    /* 410 */ s32 mUnk_410;
    /* 414 */ s32 mUnk_414;
    /* 418 */ s32 mUnk_418;
    /* 41c */ Vec3 mUnk_41c;
    /* 428 */ Vec3 mUnk_428;
    /* 434 */ s32 mUnk_434;
    /* 438 */ struct MapObject *mUnk_438[2];
    /* 440 */ u16 mUnk_440[2];
    /* 444 */ s32 mUnk_444[2];
    /* 44c */ struct MapObject *mUnk_44c;
    /* 450 */ Unk0206bcb0_A mUnk_450;
    /* 488 */ u32 mUnk_488;
    /* 48c */ s32 (*mUnk_48c)(void *);
    /* 490 */ u32 mUnk_490;
    /* 494 */ u8 mUnk_494[0x24];
    /* 4b8 */ s32 mUnk_4b8;
    /* 4bc */ s32 mUnk_4bc;
    /* 4c0 */ s32 mUnk_4c0;
    /* 4c4 */ s32 mUnk_4c4;
    /* 4c8 */ s32 mUnk_4c8;
    /* 4cc */ s32 mUnk_4cc;
    /* 4d0 */ u32 mUnk_4d0;
    /* 4d4 */ s32 mUnk_4d4;
    /* 4d8 */ s16 mUnk_4d8;
    /* 4da */ s16 mUnk_4da;
    /* 4dc */ s16 mUnk_4dc;
    /* 4de */ s16 mUnk_4de;
    /* 4e0 */ s16 mUnk_4e0;
    /* 4e2 */ s16 mUnk_4e2;
    /* 4e4 */ u16 mUnk_4e4;
    /* 4e6 */ u8 mUnk_4e6[2];
    /* 4e8 */ s32 mUnk_4e8;
    /* 4ec */ s32 mUnk_4ec;
    /* 4f0 */ Vec3 mUnk_4f0;
    /* 4fc */ u16 mUnk_4fc;
    /* 4fe */ u8 mUnk_4fe[2];
    /* 500 */ u32 mUnk_500;
    /* 504 */ u16 mUnk_504;
    /* 506 */ u16 mUnk_506;
    /* 508 */ Vec3 *mUnk_508;
    /* 50c */ Vec4 *mUnk_50c;
    /* 510 */ Vec3 *mUnk_510;
    /* 514 */ Unk0206bcb0_514 *mUnk_514;
    /* 518 */ Unk0210b7ec mUnk_518;
    /* 528 */ u8 mUnk_528[0xc];
    /* 534 */ Vec3 *mUnk_534;
    /* 538 */ Unk0206ceb4 mUnk_538;
    /* 590 */ struct Unk0206bcb0_590 *mKartModelsEntry;
    /* 594 */ s32 mUnk_594;
    /* 598 */ s16 mUnk_598;
    /* 59a */ u8 mUnk_59a[2];
    /* 59c */ s32 mUnk_59c;
    /* 5a0 */ u16 mUnk_5a0;
    /* 5a2 */ u8 mUnk_5a2[2];
    /* 5a4 */ s32 mUnk_5a4;
} Unk0206bcb0;

extern Unk0206bcb0 *data_0217b8c8;

extern int data_02154f10[];

void func_0206bf88(Unk0206bcb0 *p, int mode);
BOOL func_0206c094(Unk0206bcb0 *p);
int func_0206c0a8(Unk0206bcb0 *p);
BOOL func_0206c0b0(Unk0206bcb0 *p);
BOOL func_0206c0e0(Unk0206bcb0 *p);
void func_0206c11c(Unk0206bcb0 *p);
void func_0206c14c(Unk0206bcb0 *p);
void func_0206c17c(Unk0206bcb0 *p);
void func_0206c1ac(Unk0206c1ac *obj, Unk0206bcb0 *p);
void func_0206c2b4(Unk0206c1ac *obj, Unk0206bcb0 *p);
BOOL func_0206c354(Unk0206bcb0 *p, const Vec3 *a, int flag);
void func_0206c450(Unk0206c1ac *obj, Unk0206bcb0 *p);
void func_0206c488(Unk0206c1ac *obj, Unk0206bcb0 *p);

void func_02068a64(Unk0206bcb0 *p, int a, int b);
void func_0208b748(u32 idx, const Vec3 *pos, void *p, void (*cb)());
int func_0206c494(Unk0206bcb0 *p);
void func_0206cc60(Unk0206bcb0 *p, int arg);
#include "Main/Unknown/code_0210ab48.h"
void func_0206cdd4(Unk0206bcb0 *p);
void func_0206ceb4(s32 *out, Unk0206bcb0 *p);
extern Unk0217d26c data_0217d26c;
extern Unk0217d26c data_0217d274;
extern Unk0217d26c data_0217d284;
extern Unk0217d26c data_0217d28c;
Unk0206cdd4_B *func_0207a6b0(void);
void func_0206d020(Unk0206bcb0 *p, int a, int b);
void func_0206f914(Unk0206bcb0 *p);
void func_01ffc9e8(Unk0206bcb0 *p, int a);
void func_020681f0(Unk0206bcb0 *p);
#include "Main/Unknown/code_0210dc7c.h"
void func_020718c8(void *p, int arg);
void func_02071944(void *p, int arg);
#include "Main/Unknown/code_021035ac.h"
BOOL func_0206bcb0(Unk0206bcb0 *p, int a, int b);
BOOL func_0206be54(Unk0206bcb0 *p, int a);
void func_0206bbb4(Unk0206bcb0 *p, int a, int b);
void func_0206c5e4(Unk0206bcb0 *p);
void func_02063b10(const Unk0206bcb0 *p, Vec3 *out);
void func_02063b30(const Unk0206bcb0 *p, Vec3 *out);

#include "Main/Unknown/code_0207ae58.h"
#include "Main/Unknown/code_02079c0c.h"
