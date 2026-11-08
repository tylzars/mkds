#include "01/code_02184e18.h"
#include "01/code_02184f7c.h"

void func_ov001_02184f40(Unk02188950 *mapObject) {
    StartMapObjectSound(&mapObject->mUnk_000, 0x0000020fu);
    func_ov001_02187af4(mapObject);
    func_ov001_02187518(mapObject, 0x000008cdu, 0, 0x0000119au, 0x00000413u, 0);
}

void func_ov001_02184f04(Unk02188950 *mapObject) {
    StartMapObjectSound(&mapObject->mUnk_000, 0x0000020fu);
    func_ov001_02187af4(mapObject);
    func_ov001_02187518(mapObject, 0xfffff733u, 0, 0x0000119au, 0x00000413u, 0);
}

void func_ov001_02184ec8(Unk02188950 *mapObject) {
    StartMapObjectSound(&mapObject->mUnk_000, 0x0000020fu);
    func_ov001_02187af4(mapObject);
    func_ov001_02187518(mapObject, 0xfffff000u, 0, 0x00001333u, 0x00000444u, 0);
}

void func_ov001_02184e8c(Unk02188950 *mapObject) {
    StartMapObjectSound(&mapObject->mUnk_000, 0x0000020fu);
    func_ov001_02187af4(mapObject);
    func_ov001_02187518(mapObject, 0x00001000u, 0, 0x00001333u, 0x00000444u, 0);
}

void func_ov001_02184e6c(Unk02188950 *mapObject) {
    func_ov001_02188e48(mapObject, 0x19, func_ov001_02184f8c, 0x36, func_ov001_02184f7c);
}

void func_ov001_02184e18(u16 *mapObject) {
    if (*mapObject == (0x000001f5u)) {
        func_ov001_02188e48((Unk02188950 *) mapObject, 0x19, func_ov001_02184f40, 0x36, func_ov001_02184f04);
        return;
    }
    if (*mapObject == (0x000001f6u)) {
        func_ov001_02188e48((Unk02188950 *) mapObject, 9, func_ov001_02184ec8, 0x26, func_ov001_02184e8c);
    }
}
