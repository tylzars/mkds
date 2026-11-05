#pragma once

#include "types.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_0205e2cc.h"

#include "Main/Unknown/code_020ac2fc.h"
#include "Main/Unknown/code_0210895c.h"
#include "Main/Unknown/code_02108a40.h"
#include "Main/Unknown/code_02120294.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/code_0212658c.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_0212b928.h"

#include "Main/Unknown/code_0202b604.h"
#include "Main/Unknown/code_02120240.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_0212a910.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_02036c5c.h"

void InitWiFiVSMatching(void *a);

#include "00/code_ov000_021804e0.h"
#include "00/unk_021b4000.h"
#include "00/code_02180608.h"
#include "00/code_0219b580.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02077bc0.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02125f88.h"
#include "Main/Unknown/code_02128210.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02124094.h" // Unk02124b1c
#include "code_02016468.h"

extern Unk0217b488 *data_0217b488;
extern WiFiSession *gWiFiSession;
extern u8 data_ov000_021b0658[2];
extern u8 data_ov000_021b065c[3];
extern u8 data_ov000_021b0660[3];
extern u8 data_ov000_021b0664[3];
extern u8 data_ov000_021b0668[3];
extern s32 data_ov000_021b0680[3];
extern s8 data_ov000_021b069c[30];
extern u8 data_ov000_021b0ce4[30];
extern u8 data_ov000_021b0d04[40];
extern char data_ov000_021b0e18[];
extern char data_ov000_021b0e24[];

void func_ov000_02183330(void);
void func_ov000_02183444(void);
void func_ov000_021834b0(s32 t);
void func_ov000_02183548(void);
void AdvanceWiFiVSMatchingState11(void);
void AdvanceWiFiVSMatchingState10(void);
void AdvanceWiFiVSMatchingState9(void);
void AdvanceWiFiVSMatchingState8(void);
void AdvanceWiFiVSMatchingState5(void);
void AdvanceWiFiVSMatchingState4(void);
void AdvanceWiFiVSMatchingState3(void);
void AdvanceWiFiVSMatchingState2(void);
void AdvanceWiFiVSMatchingState1(void);
void AdvanceWiFiVSMatchingState0(void);
void func_ov000_021840c8(void);
void func_ov000_02184130(void);
void func_ov000_02184354(void);
void func_ov000_021845ac(void);
void func_ov000_02184670(void);
