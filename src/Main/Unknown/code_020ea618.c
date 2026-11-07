#include "Main/Unknown/code_020ea618.h"
#include "Main/Unknown/code_0209bc74.h"
#include "Main/Unknown/code_020d3b10.h"

void func_020ea618(Unk0209bc74_14 *model, int value) {
    u16 savedValue;
    u16 savedPolygonId;
    u16 newPolygonId;
    savedValue = model->mUnk_6e;
    if (value < savedValue) {
        savedPolygonId = model->mUnk_6c;
        newPolygonId = AllocPolygonIdWrapping();
        model->mUnk_6c = newPolygonId;
        model->mUnk_6e = value;
        func_0207ad88(model);
        model->mUnk_6c = savedPolygonId;
        model->mUnk_6e = savedValue;
        return;
    }
    func_0207ad88();
}
