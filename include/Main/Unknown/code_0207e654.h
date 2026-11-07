#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct KartAi KartAi;

#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_02080b1c.h"

BOOL IsTargetKartSet(KartAi *p);
void func_0207e668(KartAi *p);
void func_0207e7f0(KartAi *p);
void func_0207e944(KartAi *p);
s32 func_0207eafc(Vec3 *a, Vec3 *b, Vec3 *c, Vec3 *d);
void func_0207ebfc(KartAi *p);
void func_0207f05c(KartAi *p);
void func_0207f2e4(KartAi *p);
s32 func_0207f554(u32 a, u32 b);
BOOL func_0207f600(s32 a);
void func_0207f630(KartAi *p, LinkCursor *q, Kart *r);
void func_0207f668(KartAi *p, LinkCursor *q, Kart *r);
void func_0207f6f0(KartAi *p, LinkCursor *q, Kart *r, Unk02175620_bc *s, Vec3 *a, Vec3 *b);
void func_0207f8f8(KartAi *p);
void func_0207f9a8(KartAi *p);
void func_0207f9cc(KartAi *p, s32 a);
void func_0207fa74(KartAi *p, Kart *q, s32 a);
void func_0207fba0(void);
void func_0207fd28(Unk02080b1c *p);
s32 func_0207fe70(Unk02080b1c *p);
void func_0207fec0(Unk02080b1c *p);
