#include "Main/Unknown/code_020ea618.h"
#include "Main/Unknown/code_0209bc74.h"
#include "Main/Unknown/code_020d3b10.h"

void DrawShadowModelWithMaxAlpha(ShadowModel *model, int maxAlpha) {
    u16 savedAlpha;
    u16 savedPolygonId;
    u16 newPolygonId;
    savedAlpha = model->mAlpha;
    if (maxAlpha < savedAlpha) {
        savedPolygonId = model->mPolygonId;
        newPolygonId = AllocPolygonIdWrapping();
        model->mPolygonId = newPolygonId;
        model->mAlpha = maxAlpha;
        func_0207ad88(model);
        model->mPolygonId = savedPolygonId;
        model->mAlpha = savedAlpha;
        return;
    }
    func_0207ad88();
}
