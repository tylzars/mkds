#include "code_02015eb8.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"

u32 AllocPlttVram_(u32 szByte, BOOL b4Pltt, u32 opt) {
    return 0;
}

s32 FreePlttVram_(u32 plttKey) {
    return -1;
}

u32 AllocTexVram_(u32 szByte, BOOL is4x4comp, u32 opt) {
    return 0;
}

s32 FreeTexVram_(u32 texKey) {
    return -1;
}

void NNSi_G3dSendJointSRTBasic(const NNSG3dJntAnmResult *result) {
    u32 flag;

    flag = result->mFlag;
    if ((flag & 4) == 0) {
        if ((flag & 2) == 0) {
            func_01ff9048(0x19, result->mRot, 0xc);
        } else {
            func_01ff9048(0x1c, &result->mTrans, 3);
        }
    } else if ((flag & 2) == 0) {
        func_01ff9048(0x1a, result->mRot, 9);
    }
    if ((result->mFlag & 1) == 0) {
        func_01ff9048(0x1b, &result->mScale, 3);
    }
}

void NNSi_G3dGetJointScaleBasic(NNSG3dJntAnmResult *pResult, const s32 *p, const u8 *cmd, u32 srtflag) {
    if (srtflag & 4) {
        pResult->mFlag |= 1;
    } else {
        pResult->mScale.x = p[0];
        pResult->mScale.y = p[1];
        pResult->mScale.z = p[2];
    }
    pResult->mFlag |= 0x18;
}
