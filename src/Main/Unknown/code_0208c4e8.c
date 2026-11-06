#include "Main/Unknown/code_0208c4e8.h"
#include "Main/Unknown/code_0208c534.h"

void RequestKartLevel4EffectsRestart(KartTurnEffects *p0) {
    p0->mLevel4RestartFrames = 0x0u;
    p0->mLevel4RestartRequested = 0x1u;
}

void HideKartTurnEffects(KartTurnEffects *p0) {
    p0->mHideEffects(p0);
}

void ShowKartTurnEffects(KartTurnEffects *p0) {
    u32 v2 = (*(u32 *) (((u32) p0) + (128)));
    u32 v3 = ((u32(*)(u32))(v2))((u32) p0);
}
