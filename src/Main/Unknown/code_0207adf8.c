#include "Main/Unknown/code_0207adf8.h"

void DrawShadowModel(ShadowModel *shadowModel, u32 b, u32 c) {
    func_02084ad8(shadowModel, shadowModel->mAlpha);
    data_02155a20[shadowModel->mNsbmd.mDrawKind](shadowModel);
    func_02084a88(shadowModel, shadowModel->mAlpha, shadowModel->mPolygonId);
    data_02155a20[shadowModel->mNsbmd.mDrawKind](shadowModel);
}
