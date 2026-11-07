#include "Main/Unknown/code_020638c0.h"
#include "Main/Unknown/code_0206390c.h"
#include "code_020109c4.h"

void SetKillerItemRenderCallback(void *model) {
    NNS_G3dRenderObjSetCallBack(model, (NNSG3dSbcCallBackFunc) func_0206390c, 0, 6, (u8) 3);
}

// Calls slot 8 of the kart's function table.
void CallKartSlot8(struct Kart *kart) {
    u32 slotFunction = (*(u32 *) (((u32) kart) + (556)));
    u32 result = ((u32(*)(u32))(slotFunction))((u32) kart);
}
