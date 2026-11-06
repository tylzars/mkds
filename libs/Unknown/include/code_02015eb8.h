#pragma once

#include "types.h"
#include "code_02010c84.h"

void NNSi_G3dGetJointScaleBasic(NNSG3dJntAnmResult *pResult, const s32 *p, const u8 *cmd, u32 srtflag);
void NNSi_G3dSendJointSRTBasic(const NNSG3dJntAnmResult *result);
s32 FreeTexVram_(u32 texKey);
u32 AllocTexVram_(u32 szByte, BOOL is4x4comp, u32 opt);
s32 FreePlttVram_(u32 plttKey);
u32 AllocPlttVram_(u32 szByte, BOOL b4Pltt, u32 opt);
