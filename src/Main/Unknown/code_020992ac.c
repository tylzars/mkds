#include "Main/Unknown/code_020992ac.h"

#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_0209b000.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/unk_0217b000.h"
#include "ITCM/code_01ff8000.h"

void *gDeTree1;
void *gCrossTree1;
void *gNsCannon1;
void *gBeachTree1;
void *gMiniDokan;
void *gOm6Tree1;
void *gKinoHouse2;
void *gOsaTree1c;
void *gTownTree1;
void *gOf6Tree1;
void *gMarioTree3;
void *gOlgMush1;
void *gOlaTree1c;
void *gKinoHouse1;
void *gBankTree1;
void *gOlgPipe1;
void *gOpaTree1;
void *gGardenTree1;
void *gKinoMount2;
void *gSnowTree1;
void *gBankEgg1;
void *gKinoMount1;
void *gOf6yoshi1;

Unk02166a74 data_usa_02166b44 = {0, 0xa0, 0, func_0209a728, CreateOf6Tree1DrawList};
Unk02166a74 data_usa_02166fbc = {0, 0xa0, 0, func_0209a728, CreateOlaTree1cDrawList};
Unk02166a74 data_usa_02166f88 = {0, 0xa0, 0, func_0209a728, CreateDeTree1DrawList};
Unk02166a74 data_usa_02166c14 = {0, 0xa0, 0, func_0209a728, (void (*)(void)) CreateOlgMush1DrawList};
Unk02166a74 data_usa_02166c48 = {0, 0xa0, 0, func_0209a728, (void (*)(void)) CreateOlgPipe1DrawList};
Unk02166a74 data_usa_02166eec = {0, 0xa0, 0, func_0209a728, (void (*)(void)) CreateBeachTree1DrawList};
Unk02166a74 data_usa_02166cb0 = {0, 0xa0, 0, func_0209a728, (void (*)(void)) CreateNsCannon1DrawList};
Unk02166a74 data_usa_02166ce4 = {0, 0xa0, 0, func_0209a728, (void (*)(void)) CreateCrossTree1DrawList};
Unk02166a74 data_usa_02166d18 = {0, 0xa0, 0, func_0209a728, (void (*)(void)) CreateBankTree1DrawList};
Unk02166a74 data_usa_02166e1c = {0, 0xa0, 0, func_0209a728, (void (*)(void)) CreateOf6yoshi1DrawList};
Unk02166a74 data_usa_02166d4c = {0, 0xa0, 0, func_0209a728, (void (*)(void)) CreateGardenTree1DrawList};
Unk02166a74 data_usa_02166d80 = {0, 0xa0, 0, func_0209a728, (void (*)(void)) CreateGardenTree1DrawList};
Unk02166a74 data_usa_02166db4 = {0, 0xa0, 0, func_0209a728, CreateTownTree1DrawList};
Unk02166a74 data_usa_02166de8 = {0, 0xa0, 0, func_0209a728, CreateTownTree1DrawList};
Unk02166a74 data_usa_02166e50 = {0, 0xa0, 0, func_0209a728, CreateMarioTree3DrawList};
Unk02166a74 data_usa_02166e84 = {0, 0xa0, 0, func_0209a728, CreateSnowTree1DrawList};
Unk02166a74 data_usa_02166eb8 = {0, 0xa0, 0, func_0209a728, (void (*)(void)) CreateOpaTree1DrawList};
Unk02166a74 data_usa_02166f20 = {0, 0xa0, 0, func_0209a728, CreateSnowTree1DrawList};
Unk02166a74 data_usa_02166f54 = {0, 0xa0, 0, func_0209a728, CreateDeTree1DrawList};
Unk02166a74 data_usa_02166ff0 = {0, 0xa0, 0, func_0209a728, CreateOsaTree1cDrawList};
Unk02166a74 data_usa_02167024 = {0, 0xa0, 0, func_0209a728, CreateKinoHouse1DrawList};
Unk02166a74 data_usa_02166bac = {0, 0xa0, 0, func_0209a728, CreateOf6Tree1DrawList};
Unk02166a74 data_usa_02166a74 = {0, 0xa0, 0, func_0209a728, CreateKinoHouse2DrawList};
Unk02166a74 data_usa_02166aa8 = {0, 0xa0, 0, func_0209a728, CreateKinoMount1DrawList};
Unk02166a74 data_usa_02166adc = {0, 0xa0, 0, func_0209a728, CreateKinoMount2DrawList};
Unk02166a74 data_usa_02166b10 = {0, 0xa0, 0, func_0209a728, CreateOm6Tree1DrawList};
Unk02166a74 data_usa_02166b78 = {0, 0xa0, 0, func_0209a728, (void (*)(void)) CreateBeachTree1DrawList};
Unk02166a74 data_usa_02166be0 = {0, 0xa0, 0, func_0209a728, CreateBankEgg1DrawList};
Unk02166a74 data_usa_02166c7c = {0, 0xa0, 0, func_0209a728, CreateMiniDokanDrawList};

void func_0209a728(void) {
    Unk0209bf70 *o;

    o = (Unk0209bf70 *) CreateMapObjectKindDataWithoutCallbacks();
    o->mUnk_24 = 0x84;
}

void CreateBeachTree1(void *a) {
    gBeachTree1 = CreateMapObjectModelNsbmd(a, "BeachTree1.nsbmd");
    SetMapObjectModelPolygonId(gBeachTree1, 0x3f);
}

void SetupDrawBeachTree1(void *a) {
    func_0209bbd0(a, gBeachTree1);
}

void DrawBeachTree1(u32 a, MapObject *b) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048(0x14, &v2, 1);
    matrix = func_020e6cbc(&b->mPos);
    func_01ff9048(0x19, matrix, 0xc);
    func_01ff9048(0x1b, &b->mScale, 3);
    DrawMapObjectModelWithPos(a, gBeachTree1, b);
}

void *CreateBeachTree1DrawList(void) {
    return CreateMapObjectDrawList2(CreateBeachTree1, DrawBeachTree1, SetupDrawBeachTree1);
}

void CreateOpaTree1(void *a) {
    gOpaTree1 = CreateMapObjectModelNsbmd(a, "opa_tree1.nsbmd");
    SetMapObjectModelPolygonId(gOpaTree1, 0x3f);
}

void SetupDrawOpaTree1(void *a) {
    func_0209bbd0(a, gOpaTree1);
}

void DrawOpaTree1(u32 a, MapObject *b) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048(0x14, &v2, 1);
    matrix = func_020e6cbc(&b->mPos);
    func_01ff9048(0x19, matrix, 0xc);
    func_01ff9048(0x1b, &b->mScale, 3);
    DrawMapObjectModelWithPos(a, gOpaTree1, b);
}

void *CreateOpaTree1DrawList(void) {
    return CreateMapObjectDrawList2(CreateOpaTree1, DrawOpaTree1, SetupDrawOpaTree1);
}

void CreateOlgMush1(void *a) {
    gOlgMush1 = CreateMapObjectModelNsbmd(a, "OlgMush1.nsbmd");
    SetMapObjectModelPolygonId(gOlgMush1, 0x3f);
}

void SetupDrawOlgMush1(void *a) {
    func_0209bbd0(a, gOlgMush1);
}

void DrawOlgMush1(u32 a, MapObject *b) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048(0x14, &v2, 1);
    matrix = func_020e6cbc(&b->mPos);
    func_01ff9048(0x19, matrix, 0xc);
    func_01ff9048(0x1b, &b->mScale, 3);
    DrawMapObjectModelWithPos(a, gOlgMush1, b);
}

void *CreateOlgMush1DrawList(void) {
    return CreateMapObjectDrawList2(CreateOlgMush1, DrawOlgMush1, SetupDrawOlgMush1);
}

void CreateOlgPipe1(void *a) {
    gOlgPipe1 = CreateMapObjectModelNsbmd(a, "OlgPipe1.nsbmd");
    SetMapObjectModelPolygonId(gOlgPipe1, 0x3f);
}

void SetupDrawOlgPipe1(void *a) {
    func_0209bbd0(a, gOlgPipe1);
}

void DrawOlgPipe1(u32 a, MapObject *b) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048(0x14, &v2, 1);
    matrix = func_020e6cbc(&b->mPos);
    func_01ff9048(0x19, matrix, 0xc);
    func_01ff9048(0x1b, &b->mScale, 3);
    DrawMapObjectModelWithPos(a, gOlgPipe1, b);
}

void *CreateOlgPipe1DrawList(void) {
    return CreateMapObjectDrawList2(CreateOlgPipe1, DrawOlgPipe1, SetupDrawOlgPipe1);
}

void CreateOf6yoshi1(void *a) {
    gOf6yoshi1 = CreateMapObjectModelNsbmd(a, "of6yoshi1.nsbmd");
    SetMapObjectModelPolygonId(gOf6yoshi1, 0x3f);
}

void SetupDrawOf6yoshi1(void *a) {
    func_0209bbd0(a, gOf6yoshi1);
}

void DrawOf6yoshi1(u32 a, MapObject *b) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048(0x14, &v2, 1);
    matrix = func_020e6cbc(&b->mPos);
    func_01ff9048(0x19, matrix, 0xc);
    func_01ff9048(0x1b, &b->mScale, 3);
    DrawMapObjectModelWithPos(a, gOf6yoshi1, b);
}

void *CreateOf6yoshi1DrawList(void) {
    return CreateMapObjectDrawList2(CreateOf6yoshi1, DrawOf6yoshi1, SetupDrawOf6yoshi1);
}

void CreateNsCannon1(void *a) {
    gNsCannon1 = CreateMapObjectModelNsbmd(a, "NsCannon1.nsbmd");
    SetMapObjectModelPolygonId(gNsCannon1, 0x3f);
}

void SetupDrawNsCannon1(void *a) {
    func_0209bbd0(a, gNsCannon1);
}

void DrawNsCannon1(u32 a, MapObject *b) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048(0x14, &v2, 1);
    matrix = func_020e6cbc(&b->mPos);
    func_01ff9048(0x19, matrix, 0xc);
    func_01ff9048(0x1b, &b->mScale, 3);
    DrawMapObjectModelWithPos(a, gNsCannon1, b);
}

void *CreateNsCannon1DrawList(void) {
    return CreateMapObjectDrawList2(CreateNsCannon1, DrawNsCannon1, SetupDrawNsCannon1);
}

void CreateCrossTree1(void *a) {
    gCrossTree1 = CreateMapObjectModelNsbmd(a, "CrossTree1.nsbmd");
    SetMapObjectModelPolygonId(gCrossTree1, 0x3f);
}

void SetupDrawCrossTree1(void *a) {
    func_0209bbd0(a, gCrossTree1);
}

void DrawCrossTree1(u32 a, MapObject *b) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048(0x14, &v2, 1);
    matrix = func_020e6cbc(&b->mPos);
    func_01ff9048(0x19, matrix, 0xc);
    func_01ff9048(0x1b, &b->mScale, 3);
    DrawMapObjectModelWithPos(a, gCrossTree1, b);
}

void *CreateCrossTree1DrawList(void) {
    return CreateMapObjectDrawList2(CreateCrossTree1, DrawCrossTree1, SetupDrawCrossTree1);
}

void CreateBankTree1(void *a) {
    gBankTree1 = CreateMapObjectModelNsbmd(a, "Bank_Tree1.nsbmd");
    SetMapObjectModelPolygonId(gBankTree1, 0x3f);
}

void SetupDrawBankTree1(void *a) {
    func_0209bbd0(a, gBankTree1);
}

void DrawBankTree1(u32 a, MapObject *b) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048(0x14, &v2, 1);
    matrix = func_020e6cbc(&b->mPos);
    func_01ff9048(0x19, matrix, 0xc);
    func_01ff9048(0x1b, &b->mScale, 3);
    DrawMapObjectModelWithPos(a, gBankTree1, b);
}

void *CreateBankTree1DrawList(void) {
    return CreateMapObjectDrawList2(CreateBankTree1, DrawBankTree1, SetupDrawBankTree1);
}

void CreateGardenTree1(void *a) {
    gGardenTree1 = CreateMapObjectModelNsbmd(a, "GardenTree1.nsbmd");
    SetMapObjectModelPolygonId(gGardenTree1, 0x3f);
}

void SetupDrawGardenTree1(void *a) {
    func_0209bbd0(a, gGardenTree1);
}

void DrawGardenTree1(u32 a, MapObject *b) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048(0x14, &v2, 1);
    matrix = func_020e6cbc(&b->mPos);
    func_01ff9048(0x19, matrix, 0xc);
    func_01ff9048(0x1b, &b->mScale, 3);
    DrawMapObjectModelWithPos(a, gGardenTree1, b);
}

void *CreateGardenTree1DrawList(void) {
    return CreateMapObjectDrawList2(CreateGardenTree1, DrawGardenTree1, SetupDrawGardenTree1);
}

void CreateTownTree1(void *a) {
    gTownTree1 = CreateMapObjectModelNsbmd(a, "TownTree1.nsbmd");
    SetMapObjectModelPolygonId(gTownTree1, 0x3f);
}

void SetupDrawTownTree1(void *a) {
    func_0209bbd0(a, gTownTree1);
}

void DrawTownTree1(u32 a, MapObject *b) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048(0x14, &v2, 1);
    matrix = func_020e6cbc(&b->mPos);
    func_01ff9048(0x19, matrix, 0xc);
    func_01ff9048(0x1b, &b->mScale, 3);
    DrawMapObjectModelWithPos(a, gTownTree1, b);
}

void CreateTownTree1DrawList(void) {
    CreateMapObjectDrawList2(CreateTownTree1, DrawTownTree1, SetupDrawTownTree1);
}

void CreateMarioTree3(void *a) {
    gMarioTree3 = CreateMapObjectModelNsbmd(a, "MarioTree3.nsbmd");
    SetMapObjectModelPolygonId(gMarioTree3, 0x3f);
}

void SetupDrawMarioTree3(void *a) {
    func_0209bbd0(a, gMarioTree3);
}

void DrawMarioTree3(u32 a, MapObject *b) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048(0x14, &v2, 1);
    matrix = func_020e6cbc(&b->mPos);
    func_01ff9048(0x19, matrix, 0xc);
    func_01ff9048(0x1b, &b->mScale, 3);
    DrawMapObjectModelWithPos(a, gMarioTree3, b);
}

void CreateMarioTree3DrawList(void) {
    CreateMapObjectDrawList2(CreateMarioTree3, DrawMarioTree3, SetupDrawMarioTree3);
}

void CreateSnowTree1(void *a) {
    gSnowTree1 = CreateMapObjectModelNsbmd(a, "Snow_Tree1.nsbmd");
    SetMapObjectModelPolygonId(gSnowTree1, 0x3f);
}

void SetupDrawSnowTree1(void *a) {
    func_0209bbd0(a, gSnowTree1);
}

void DrawSnowTree1(u32 a, MapObject *b) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048(0x14, &v2, 1);
    matrix = func_020e6cbc(&b->mPos);
    func_01ff9048(0x19, matrix, 0xc);
    func_01ff9048(0x1b, &b->mScale, 3);
    DrawMapObjectModelWithPos(a, gSnowTree1, b);
}

void CreateSnowTree1DrawList(void) {
    CreateMapObjectDrawList2(CreateSnowTree1, DrawSnowTree1, SetupDrawSnowTree1);
}

void CreateDeTree1(void *a) {
    gDeTree1 = CreateMapObjectModelNsbmd(a, "DeTree1.nsbmd");
    SetMapObjectModelPolygonId(gDeTree1, 0x3f);
}

void SetupDrawDeTree1(void *a) {
    func_0209bbd0(a, gDeTree1);
}

void DrawDeTree1(u32 a, MapObject *b) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048(0x14, &v2, 1);
    matrix = func_020e6cbc(&b->mPos);
    func_01ff9048(0x19, matrix, 0xc);
    func_01ff9048(0x1b, &b->mScale, 3);
    DrawMapObjectModelWithPos(a, gDeTree1, b);
}

void CreateDeTree1DrawList(void) {
    CreateMapObjectDrawList2(CreateDeTree1, DrawDeTree1, SetupDrawDeTree1);
}

void CreateOlaTree1c(void *a) {
    gOlaTree1c = CreateMapObjectModelNsbmd(a, "olaTree1c.nsbmd");
    SetMapObjectModelPolygonId(gOlaTree1c, 0x3f);
}

void SetupDrawOlaTree1c(void *a) {
    func_0209bbd0(a, gOlaTree1c);
}

void DrawOlaTree1c(u32 a, MapObject *b) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048(0x14, &v2, 1);
    matrix = func_020e6cbc(&b->mPos);
    func_01ff9048(0x19, matrix, 0xc);
    func_01ff9048(0x1b, &b->mScale, 3);
    DrawMapObjectModelWithPos(a, gOlaTree1c, b);
}

void CreateOlaTree1cDrawList(void) {
    CreateMapObjectDrawList2(CreateOlaTree1c, DrawOlaTree1c, SetupDrawOlaTree1c);
}

void CreateOsaTree1c(void *a) {
    gOsaTree1c = CreateMapObjectModelNsbmd(a, "osaTree1c.nsbmd");
    SetMapObjectModelPolygonId(gOsaTree1c, 0x3f);
}

void SetupDrawOsaTree1c(void *a) {
    func_0209bbd0(a, gOsaTree1c);
}

void DrawOsaTree1c(u32 a, MapObject *b) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048(0x14, &v2, 1);
    matrix = func_020e6cbc(&b->mPos);
    func_01ff9048(0x19, matrix, 0xc);
    func_01ff9048(0x1b, &b->mScale, 3);
    DrawMapObjectModelWithPos(a, gOsaTree1c, b);
}

void CreateOsaTree1cDrawList(void) {
    CreateMapObjectDrawList2(CreateOsaTree1c, DrawOsaTree1c, SetupDrawOsaTree1c);
}

void CreateKinoHouse1(void *a) {
    gKinoHouse1 = CreateMapObjectModelNsbmd(a, "KinoHouse1.nsbmd");
    SetMapObjectModelPolygonId(gKinoHouse1, 0x3f);
}

void SetupDrawKinoHouse1(void *a) {
    func_0209bbd0(a, gKinoHouse1);
}

void DrawKinoHouse1(u32 a, MapObject *b) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048(0x14, &v2, 1);
    matrix = func_020e6cbc(&b->mPos);
    func_01ff9048(0x19, matrix, 0xc);
    func_01ff9048(0x1b, &b->mScale, 3);
    DrawMapObjectModelWithPos(a, gKinoHouse1, b);
}

void CreateKinoHouse1DrawList(void) {
    CreateMapObjectDrawList2(CreateKinoHouse1, DrawKinoHouse1, SetupDrawKinoHouse1);
}

void CreateKinoHouse2(void *a) {
    gKinoHouse2 = CreateMapObjectModelNsbmd(a, "KinoHouse2.nsbmd");
    SetMapObjectModelPolygonId(gKinoHouse2, 0x3f);
}

void SetupDrawKinoHouse2(void *a) {
    func_0209bbd0(a, gKinoHouse2);
}

void DrawKinoHouse2(u32 a, MapObject *b) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048(0x14, &v2, 1);
    matrix = func_020e6cbc(&b->mPos);
    func_01ff9048(0x19, matrix, 0xc);
    func_01ff9048(0x1b, &b->mScale, 3);
    DrawMapObjectModelWithPos(a, gKinoHouse2, b);
}

void CreateKinoHouse2DrawList(void) {
    CreateMapObjectDrawList2(CreateKinoHouse2, DrawKinoHouse2, SetupDrawKinoHouse2);
}

void CreateKinoMount1(void *a) {
    gKinoMount1 = CreateMapObjectModelNsbmd(a, "KinoMount1.nsbmd");
    SetMapObjectModelPolygonId(gKinoMount1, 0x3f);
}

void SetupDrawKinoMount1(void *a) {
    func_0209bbd0(a, gKinoMount1);
}

void DrawKinoMount1(u32 a, MapObject *b) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048(0x14, &v2, 1);
    matrix = func_020e6cbc(&b->mPos);
    func_01ff9048(0x19, matrix, 0xc);
    func_01ff9048(0x1b, &b->mScale, 3);
    DrawMapObjectModelWithPos(a, gKinoMount1, b);
}

void CreateKinoMount1DrawList(void) {
    CreateMapObjectDrawList2(CreateKinoMount1, DrawKinoMount1, SetupDrawKinoMount1);
}

void CreateKinoMount2(void *a) {
    gKinoMount2 = CreateMapObjectModelNsbmd(a, "KinoMount2.nsbmd");
    SetMapObjectModelPolygonId(gKinoMount2, 0x3f);
}

void SetupDrawKinoMount2(void *a) {
    func_0209bbd0(a, gKinoMount2);
}

void DrawKinoMount2(u32 a, MapObject *b) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048(0x14, &v2, 1);
    matrix = func_020e6cbc(&b->mPos);
    func_01ff9048(0x19, matrix, 0xc);
    func_01ff9048(0x1b, &b->mScale, 3);
    DrawMapObjectModelWithPos(a, gKinoMount2, b);
}

void CreateKinoMount2DrawList(void) {
    CreateMapObjectDrawList2(CreateKinoMount2, DrawKinoMount2, SetupDrawKinoMount2);
}

void CreateOm6Tree1(void *a) {
    gOm6Tree1 = CreateMapObjectModelNsbmd(a, "om6Tree1.nsbmd");
    SetMapObjectModelPolygonId(gOm6Tree1, 0x3f);
}

void SetupDrawOm6Tree1(void *a) {
    func_0209bbd0(a, gOm6Tree1);
}

void DrawOm6Tree1(u32 a, MapObject *b) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048(0x14, &v2, 1);
    matrix = func_020e6cbc(&b->mPos);
    func_01ff9048(0x19, matrix, 0xc);
    func_01ff9048(0x1b, &b->mScale, 3);
    DrawMapObjectModelWithPos(a, gOm6Tree1, b);
}

void CreateOm6Tree1DrawList(void) {
    CreateMapObjectDrawList2(CreateOm6Tree1, DrawOm6Tree1, SetupDrawOm6Tree1);
}

void CreateOf6Tree1(void *a) {
    gOf6Tree1 = CreateMapObjectModelNsbmd(a, "Of6Tree1.nsbmd");
    SetMapObjectModelPolygonId(gOf6Tree1, 0x3f);
}

void SetupDrawOf6Tree1(void *a) {
    func_0209bbd0(a, gOf6Tree1);
}

void DrawOf6Tree1(u32 a, MapObject *b) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048(0x14, &v2, 1);
    matrix = func_020e6cbc(&b->mPos);
    func_01ff9048(0x19, matrix, 0xc);
    func_01ff9048(0x1b, &b->mScale, 3);
    DrawMapObjectModelWithPos(a, gOf6Tree1, b);
}

void CreateOf6Tree1DrawList(void) {
    CreateMapObjectDrawList2(CreateOf6Tree1, DrawOf6Tree1, SetupDrawOf6Tree1);
}

void CreateBankEgg1(void *a) {
    gBankEgg1 = CreateMapObjectModelNsbmd(a, "BankEgg1.nsbmd");
    SetMapObjectModelPolygonId(gBankEgg1, 0x3f);
}

void SetupDrawBankEgg1(void *a) {
    func_0209bbd0(a, gBankEgg1);
}

void DrawBankEgg1(u32 a, MapObject *b) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048(0x14, &v2, 1);
    matrix = func_020e6cbc(&b->mPos);
    func_01ff9048(0x19, matrix, 0xc);
    func_01ff9048(0x1b, &b->mScale, 3);
    DrawMapObjectModelWithPos(a, gBankEgg1, b);
}

void CreateBankEgg1DrawList(void) {
    CreateMapObjectDrawList2(CreateBankEgg1, DrawBankEgg1, SetupDrawBankEgg1);
}

void CreateMiniDokan(void *a) {
    gMiniDokan = CreateMapObjectModelNsbmd(a, "mini_dokan.nsbmd");
    SetMapObjectModelPolygonId(gMiniDokan, 0x3f);
}

void SetupDrawMiniDokan(void *a) {
    func_0209bbd0(a, gMiniDokan);
}

void DrawMiniDokan(u32 a, MapObject *b) {
    MtxFx43 *matrix;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048(0x14, &v2, 1);
    matrix = func_020e6cbc(&b->mPos);
    func_01ff9048(0x19, matrix, 0xc);
    func_01ff9048(0x1b, &b->mScale, 3);
    DrawMapObjectModelWithPos(a, gMiniDokan, b);
}

void CreateMiniDokanDrawList(void) {
    CreateMapObjectDrawList2(CreateMiniDokan, DrawMiniDokan, SetupDrawMiniDokan);
}
