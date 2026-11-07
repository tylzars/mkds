#pragma once

#include "types.h"
#include "code_02022030.h" // Unk02022030, Unk02022438, Unk020224e0_c, GXOamAttr

u32 SetAnimCtrlCurrentFrameImpl_(Unk02022030 *pAnimCtrl, u32 index);
void SequenceEdgeHandle_(Unk02022030 *pAnimCtrl);
void NNSi_G2dSrtcSetInitialValue(Unk02022438 *pCtrl);
void NNSi_G2dSrtcInitControl(Unk02022438 *pCtrl, u32 type);
void NNSi_G2dSrtcSetSRTScale(Unk02022438 *pCtrl, s32 x, s32 y);
void NNSi_G2dSrtcSetSRTRotZ(Unk02022438 *pCtrl, u16 rotZ);
void NNSi_G2dSrtcSetTrans(Unk02022438 *pCtrl, s16 x, s16 y);
u16 NNS_G2dMakeCellToOams(GXOamAttr *pDstOams, u16 numDstOam, Unk020224e0_c *pCell, s32 *pMtxSR, s32 *pBaseTrans,
                          u16 affineIndex, s32 bDoubleAffine);
void NNS_G2dSetCellAnimationSpeed(Unk02022030 *pCellAnim, s32 speed);
void NNS_G2dSetCellAnimationCurrentFrame(Unk02022030 *pCellAnim, u16 frameIndex);
void NNS_G2dTickCellAnimation(Unk02022030 *pCellAnim, s32 frames);
void NNS_G2dSetCellAnimationSequence(Unk02022030 *pCellAnim, Unk02021dc8 *pAnimSeq);
void NNS_G2dInitCellAnimation(Unk02022030 *pCellAnim, Unk02021dc8 *pAnimSeq, Unk02021dc8 *pCellDataBank);
void ApplyCurrentAnimResult_(Unk02022030 *pCellAnim);
