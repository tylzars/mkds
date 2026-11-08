#include "Main/Unknown/code_020ea618.h"
#include "Main/Unknown/code_0209bc74.h"
#include "Main/Unknown/code_020d3b10.h"

void DrawShadowModelWithMaxAlpha(Unk0209bc74_14 *model, int maxAlpha) {
    u16 savedAlpha;
    u16 savedPolygonId;
    u16 newPolygonId;
    savedAlpha = model->mUnk_6e;
    if (maxAlpha < savedAlpha) {
        savedPolygonId = model->mUnk_6c;
        newPolygonId = AllocPolygonIdWrapping();
        model->mUnk_6c = newPolygonId;
        model->mUnk_6e = maxAlpha;
        func_0207ad88(model);
        model->mUnk_6c = savedPolygonId;
        model->mUnk_6e = savedAlpha;
        return;
    }
    func_0207ad88();
}
