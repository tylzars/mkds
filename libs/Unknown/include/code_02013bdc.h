#pragma once

#include "types.h"
#include "code_02010c84.h"

typedef struct Unk020136f0 Unk020136f0;

// Fourth argument of func_02013e18 and func_02014164: halfword counts at 0x04 and 0x06, flags at 0x08, byte
// offsets (from this struct) to two s16 arrays at 0x0c and 0x10, and halfword offsets to entries from 0x14.
typedef struct Unk02014c5c {
    /* 00 */ u8 mUnk_00[0x4];
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;    // byte offset from this struct to an s16 array (second argument of func_02013c78)
    /* 10 */ u32 mUnk_10;    // byte offset from this struct to an s16 array (third argument of func_02013c78)
    /* 14 */ u16 mUnk_14[1]; // byte offsets from this struct, indexed by func_02014c5c's second argument
} Unk02014c5c;

// Two halfwords, or two words, read per sample by func_0201456c.
typedef struct Unk0201456c_16 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mUnk_02;
} Unk0201456c_16;

typedef struct Unk0201456c_32 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk0201456c_32;

// Fourth argument of func_02014c5c; filled by it.
typedef struct Unk02014c5c_out {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 mUnk_04[0x24];
    /* 28 */ s32 mUnk_28[9];
    /* 4c */ s32 mUnk_4c[3];
} Unk02014c5c_out;

// Halfword at 0x06: byte offset from this struct to a table whose first halfword is the stride; entry i holds a
// word at offset 4 + i * stride that is the byte offset of the entry from this struct.
typedef struct Unk02170500_d4 {
    /* 00 */ u8 mUnk_00[6];
    /* 06 */ u16 mUnk_06;
} Unk02170500_d4;

// Header of the data an Unk02170500_04 describes: byte offsets (from this struct) at 0x04, 0x08 and 0x0c.
typedef struct Unk02170500_04_04 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u8 mUnk_10[5];
    /* 15 */ u8 mUnk_15;
    /* 16 */ u8 mUnk_16;
    /* 17 */ u8 mUnk_17;
    /* 18 */ u8 mUnk_18[4];
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
} Unk02170500_04_04;

struct Unk02170500;
struct Unk020152bc;

// Three (list, function) pairs, each with a bit set (two words) of the entries the list marks.
typedef struct Unk02170500_04 {
    /* 00 */ u32 mUnk_00; // bit 0 and bit 4 are tested
    /* 04 */ Unk02170500_04_04 *mUnk_04;
    /* 08 */ struct Unk020152bc *mUnk_08;
    /* 0c */ s32 (*mUnk_0c)(Unk0201290c_1c *, struct Unk020152bc *, u32);
    /* 10 */ struct Unk020152bc *mUnk_10;
    /* 14 */ s32 (*mUnk_14)(Unk02014c5c_out *, struct Unk020152bc *, u32);
    /* 18 */ struct Unk020152bc *mUnk_18;
    /* 1c */ s32 (*mUnk_1c)(u32 *, struct Unk020152bc *, u32);
    /* 20 */ void (*mUnk_20)(struct Unk02170500 *);
    /* 24 */ u8 mUnk_24;
    /* 25 */ u8 mUnk_25;
    /* 28 */ void (*mUnk_28)(struct Unk02170500 *);
    /* 2c */ u8 mUnk_2c[4];
    /* 30 */ u8 *mUnk_30;
    /* 34 */ Unk02014c5c_out *mUnk_34;
    /* 38 */ Unk0201290c_1c *mUnk_38;
    /* 3c */ u32 mUnk_3c[2];
    /* 44 */ u32 mUnk_44[2];
    /* 4c */ u32 mUnk_4c[2];
} Unk02170500_04;

// Object data_02170500 points to.
typedef struct Unk02170500 {
    /* 00 */ u8 *mUnk_00;
    /* 04 */ Unk02170500_04 *mUnk_04;
    /* 08 */ u32 mUnk_08; // bits 0-4, 6, 7 to 10 are tested
    /* 0c */ void (*mUnk_0c[0x20])(struct Unk02170500 *);
    /* 8c */ u8 mUnk_8c[0x20];
    /* ac */ u8 mUnk_ac;
    /* ad */ u8 mUnk_ad;
    /* ae */ u8 mUnk_ae;
    /* af */ u8 mUnk_af;
    /* b0 */ Unk0201290c_1c *mUnk_b0;
    /* b4 */ Unk02014c5c_out *mUnk_b4;
    /* b8 */ u32 *mUnk_b8;
    /* bc */ u32 mUnk_bc[2];
    /* c4 */ u32 mUnk_c4[4];
    /* d4 */ Unk02170500_d4 *mUnk_d4;
    /* d8 */ u8 *mUnk_d8;
    /* dc */ u8 *mUnk_dc;
    /* e0 */ s32 mUnk_e0;
    /* e4 */ s32 mUnk_e4;
    /* e8 */ UnkFunc *mUnk_e8; // called with four arguments by func_02014c5c and two by func_020151a4
    /* ec */ void (*mUnk_ec)(Unk02014c5c_out *);
    /* f0 */ void (*mUnk_f0)(Unk0201290c_1c *);
    /* f4 */ Unk0201290c_1c mUnk_f4;
    /* 12c */ Unk02014c5c_out mUnk_12c;
    /* 184 */ u32 mUnk_184;
} Unk02170500;

// Entry found through Unk02170500_d4: flags at 0x00, a value at 0x02 and halfwords from 0x04.
typedef struct Unk02015044_e {
    /* 00 */ u16 mUnk_00;
    /* 02 */ s16 mUnk_02;
    /* 04 */ s16 mUnk_04[8];
} Unk02015044_e;

// Second argument of func_02015274: a value with 12 fractional bits at 0x00 and an Unk02014c5c at 0x08.
typedef struct Unk02015274 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u8 mUnk_04[4];
    /* 08 */ Unk02014c5c *mUnk_08;
} Unk02015274;

// Third argument of func_020152bc and func_02015e6c: a count at 0x17.
typedef struct Unk020152bc_c {
    /* 00 */ u8 mUnk_00[0x17];
    /* 17 */ u8 mUnk_17;
} Unk020152bc_c;

// First argument of func_020152bc and the functions that fill it the same way: halfwords from 0x1a, their count at
// 0x19.
typedef struct Unk020152bc {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ void *mUnk_08;
    /* 0c */ UnkFunc *mUnk_0c;
    /* 10 */ struct Unk020152bc *mUnk_10; // next object in the list
    /* 14 */ u8 mUnk_14[5];
    /* 19 */ u8 mUnk_19;
    /* 1a */ u16 mUnk_1a[1];
} Unk020152bc;

// Object whose halfword at 0x0e is the byte offset (from 0x08) of a table: stride halfword at 0, entries of five
// words from 4.
typedef struct Unk02015358_b {
    /* 00 */ u8 mUnk_00[0xe];
    /* 0e */ u16 mUnk_0e;
} Unk02015358_b;

typedef struct Unk02015358_e {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
} Unk02015358_e;

// Second argument of func_02015358: a value with 12 fractional bits at 0x00 and an Unk02015358_b at 0x08.
typedef struct Unk02015358_s {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u8 mUnk_04[4];
    /* 08 */ Unk02015358_b *mUnk_08;
} Unk02015358_s;

// First argument of func_02015358: words at 0x04, 0x08 and 0x0c.
typedef struct Unk02015358 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk02015358;

// Second argument of func_02015428 and func_020157d8: a count at 0x09 and at 0x0e the offset (from 0x08) of a table.
typedef struct Unk02015428_b {
    /* 00 */ u8 mUnk_00[9];
    /* 09 */ u8 mUnk_09;
    /* 0a */ u8 mUnk_0a[4];
    /* 0e */ u16 mUnk_0e;
} Unk02015428_b;

// Third argument of func_02015428, func_020157d8 and func_02015d68: an offset at 0x08 and a count at 0x18.
typedef struct Unk02015428_c {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u32 mUnk_08;
    /* 0c */ u8 mUnk_0c[0xc];
    /* 18 */ u8 mUnk_18;
} Unk02015428_c;

// Second argument of func_02015d68: a count at 0x0d and at 0x12 the offset (from 0x0c) of a table.
typedef struct Unk02015d68_b {
    /* 00 */ u8 mUnk_00[0xd];
    /* 0d */ u8 mUnk_0d;
    /* 0e */ u8 mUnk_0e[4];
    /* 12 */ u16 mUnk_12;
} Unk02015d68_b;

// Halfword at 0x06, a bit set from 0x0c.
typedef struct Unk02015e28_b {
    /* 00 */ u8 mUnk_00[6];
    /* 06 */ u16 mUnk_06;
    /* 08 */ u8 mUnk_08[4];
    /* 0c */ u32 mUnk_0c[1];
} Unk02015e28_b;

// Second argument of func_02015e28: a value with 12 fractional bits at 0x00 and an Unk02015e28_b at 0x08.
typedef struct Unk02015e28 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u8 mUnk_04[4];
    /* 08 */ Unk02015e28_b *mUnk_08;
} Unk02015e28;

// Fourth argument of func_02015788 and func_02015894: flags at 0x00 and 0x10, words and halfwords written from 0x18.
typedef struct Unk02015788 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 mUnk_04[0xc];
    /* 10 */ u32 mUnk_10;
    /* 14 */ u8 mUnk_14[4];
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ u16 mUnk_20;
    /* 22 */ u16 mUnk_22;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
} Unk02015788;

// First argument of func_02015894: its halfword at 0x0e is the byte offset (from 0x08) of a table of entries.
typedef struct Unk02015894_a {
    /* 00 */ u8 mUnk_00[0xe];
    /* 0e */ u16 mUnk_0e;
} Unk02015894_a;

// Second argument of func_02015788: a value with 12 fractional bits at 0x00 and an Unk02015894_a at 0x08.
typedef struct Unk02015788_s {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u8 mUnk_04[4];
    /* 08 */ Unk02015894_a *mUnk_08;
} Unk02015788_s;

// Entry of ten words found by func_02015894 in the table of an Unk02015894_a.
typedef struct Unk02015894_e {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mUnk_24;
} Unk02015894_e;

// First argument of func_02015b9c: words at 0x10 and 0x14, halfwords at 0x2c and 0x2e, words at 0x30 and 0x34.
typedef struct Unk02015b9c {
    /* 00 */ u8 mUnk_00[0x10];
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u8 mUnk_18[0x14];
    /* 2c */ u16 mUnk_2c;
    /* 2e */ u16 mUnk_2e;
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
} Unk02015b9c;

// Object read by func_02015c24 and func_02015c7c: words at 0x08, 0x18 and 0x2c, at 0x34 the offset of a table and
// at 0x3c a table, both searched with func_020138b4.
typedef struct Unk02015b9c_o {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u32 mUnk_08;
    /* 0c */ u8 mUnk_0c[0xc];
    /* 18 */ u32 mUnk_18;
    /* 1c */ u8 mUnk_1c[0x10];
    /* 2c */ u32 mUnk_2c;
    /* 30 */ u8 mUnk_30[4];
    /* 34 */ u16 mUnk_34;
} Unk02015b9c_o;

// Second argument of func_02015b9c: a word at 0x00, a block at 0x08 and an Unk02015b9c_o at 0x14.
typedef struct Unk02015b9c_b {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 mUnk_04[4];
    /* 08 */ void *mUnk_08;
    /* 0c */ u8 mUnk_0c[8];
    /* 14 */ Unk02015b9c_o *mUnk_14;
} Unk02015b9c_b;

// Entry found by func_020138b4 in func_02015c24.
typedef struct Unk02015c24_e {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
} Unk02015c24_e;

// Entry found by func_020138b4 in func_02015c7c.
typedef struct Unk02015c7c_e {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
} Unk02015c7c_e;

void *func_02013bdc(void *a);
void *func_02013bf8(void *a, u32 b);
void *func_02013c18(Unk020136f0 *a, u32 b, u32 c);
int func_02013c78(s32 *out, const s16 *a, const s16 *b, u32 n);
void func_02013e18(s32 *out, s32 a, const u32 *p, Unk02014c5c *obj);
void func_02014164(s32 *out, s32 a, const u32 *p, Unk02014c5c *obj);
void func_0201456c(s32 *out, s32 a, const u32 *p, Unk02014c5c *obj);
void func_02014724(s32 *out, s32 a, const u32 *p, Unk02014c5c *obj);
void func_02014954(s32 *out, s32 a, const u32 *p, Unk02014c5c *obj);
void func_02014ad0(s32 *out, s32 a, const u32 *p, Unk02014c5c *obj);
void func_02014c5c(Unk02014c5c *obj, int idx, s32 a, Unk02014c5c_out *o);
void func_02015044(Unk02014c5c_out *o);
void func_020151a4(Unk02014c5c_out *o);
void func_0201520c(Unk02014c5c_out *o);
void func_02015274(Unk02014c5c_out *a, Unk02015274 *b, int c);
void func_020152bc(Unk020152bc *a, Unk02014c5c *b, Unk020152bc_c *c);
void func_02015358(Unk02015358 *a, Unk02015358_s *b, u32 c);
void func_02015428(Unk020152bc *a, Unk02015428_b *b, Unk02015428_c *c);
u16 func_020154e4(const void *a, u32 b, u32 c);
u16 func_020155d8(const void *a, u32 b, u32 c);
void func_02015788(Unk02015788 *a, Unk02015788_s *b, u32 c);
void func_020157d8(Unk020152bc *a, Unk02015428_b *b, Unk02015428_c *c);
void func_02015894(const Unk02015894_a *a, u16 b, u32 c, Unk02015788 *d);
u32 func_02015994(const void *a, u32 b, u32 c, u32 d);
s32 func_02015aa0(const void *a, u32 b, s32 c, u32 d);
void func_02015b9c(Unk02015b9c *a, Unk02015b9c_b *b, u32 c);
void func_02015c24(Unk02015b9c_o *a, const u32 *b, Unk02015b9c *c);
void func_02015c7c(Unk02015b9c_o *a, const u32 *b, Unk02015b9c *c);
void func_02015d68(Unk020152bc *a, Unk02015d68_b *b, Unk02015428_c *c);
void func_02015e28(u32 *a, Unk02015e28 *b, u32 c);
void func_02015e6c(Unk020152bc *a, void *b, Unk020152bc_c *c);
