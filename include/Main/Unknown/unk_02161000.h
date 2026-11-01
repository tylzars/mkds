#pragma once

#include "types.h"
#include "code_02013bdc.h"
#include "code_02010c84.h"
#include "code_02010fac.h"
#include "code_02147cd8.h"

// Objects whose layout isn't known yet.
extern s16 data_021614b4[];
extern s16 data_021615b8[];
extern s32 data_02161770;
extern u32 data_02161774;
extern s32 data_02161778;
extern s32 data_0216177c;
extern u32 data_02161780;
extern u8 data_02161790[];
extern u8 data_02161794[];
extern u8 data_02161798[];
extern u8 data_0216179c[];
extern u8 data_02161e64[];
extern u8 data_02161e7c[];
extern u8 data_02161e94[];
extern u8 data_02161eac[];
extern u8 data_02161ec4[];
extern u8 data_02161edc[];

extern u32 (*data_021619ec)(s32 a, s32 b, s32 c);
extern u32 (*data_021619f4)(s32 a, s32 b, s32 c);
extern void (*data_02161ac0[])(s32 a, s32 b, s32 c, s32 d);
extern void (*data_02161ac8[])(s32 a, s32 b, void *c);
extern Unk02148038 data_02161ad0;

extern u8 data_02161ad8;

extern u8 data_02161adc[];
extern u8 data_02161ae0[];
extern u8 data_02161ae4[];

// Seven word tables, entries 0x1c bytes apart, indexed by the result of func_0202578c.
extern u8 data_02161ae8[];
extern u8 data_02161aec[];
extern u8 data_02161af0[];
extern u8 data_02161af4[];
extern u8 data_02161af8[];
extern u8 data_02161afc[];
extern u8 data_02161b00[];

extern u16 data_021616bc[];
extern u8 data_021616cc[];
extern u8 data_021616ce[];
extern u8 data_021616d0[];

extern u32 data_021617d0;
extern Unk021617f4 data_021617f4[];
extern Unk021617f8 data_021617f8[];
extern u32 data_021617f0;
extern u32 data_021617ec;
extern u32 data_021617e8;
extern void (*data_0216185c[])(Unk0201290c_1c *);
extern u32 data_0216186c[2];
extern u32 data_02161874[2];
extern s32 data_0216189c[16];
extern u32 data_021618dc[];
extern u32 data_021618e0[];
extern u32 data_021618e8[];
extern Vec3 data_0216190c;
extern Vec3 data_02161918;
extern u32 data_02161924[];
extern u32 data_02161928[];
extern Vec3 data_02161930[];
extern Vec3 data_02161954;
extern Vec3 data_02161960;
extern void (*data_021619f0)(void *);
extern void (*data_021619f8)(void *);

extern UnkFunc *data_021617d4;
extern UnkFunc *data_021617d8;
extern UnkFunc *data_021617dc;
extern UnkFunc *data_021617e0;
extern UnkFunc *data_021617e4;
extern u32 (*data_021619ec)();
extern u32 (*data_021619f4)();

extern const char data_02161c88[];
extern const char data_02161ca8[];
extern const char data_02161cc8[];
extern const char data_02161ce8[];
extern const char data_02161d04[];
extern const char data_02161d2c[];
extern const char data_02161d54[];
extern const char data_02161d78[];
extern const char data_02161d9c[];
extern const char data_02161dc0[];
extern const char data_02161de0[];
extern const char data_02161dfc[];
extern const char data_02161e18[];
extern const char data_02161e34[];
extern const char data_02161e4c[];

extern void (*data_usa_02161844[])(Unk02014c5c_out *);
extern void (*data_usa_02161850[])(Unk02014c5c_out *, void *, u8 *, u32);
extern void (*data_usa_0216187c[])(Unk02170500 *, u32, void *, u32);
extern void (*data_usa_0216188c[])(Unk02170500 *, u32, void *, u32);
extern void (*data_usa_0216196c[])(Unk02170500 *, u32);

// Strings from data_usa_02161ef0 on.
extern const char data_usa_02161ef0[];
extern const char data_usa_02161f00[];
extern const char data_usa_02161f20[];
extern const char data_usa_02161f40[];
extern const char data_usa_02161f60[];
extern const char data_usa_02161f7c[];
extern const char data_usa_02161fa4[];
extern const char data_usa_02161fcc[];
extern const char data_usa_02161ff0[];
extern const char data_usa_02162014[];
extern const char data_usa_02162038[];
extern const char data_usa_02162058[];
extern const char data_usa_02162070[];
extern const char data_usa_02162088[];
extern const char data_usa_0216209c[];
extern const char data_usa_021620b4[];
extern const char data_usa_021620cc[];
extern const char data_usa_021620e4[];
extern const char data_usa_021620f8[];
extern const char data_usa_0216210c[];
extern const char data_usa_02162120[];
extern const char data_usa_0216212c[];
