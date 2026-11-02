#include "Main/Unknown/code_020992ac.h"

#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/unk_0217b000.h"

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

Unk02166a74 data_usa_02166b44 = {0, 0xa0, 0, func_0209a728, func_02099474};
Unk02166a74 data_usa_02166fbc = {0, 0xa0, 0, func_0209a728, func_02099ab0};
Unk02166a74 data_usa_02166f88 = {0, 0xa0, 0, func_0209a728, func_02099b94};
Unk02166a74 data_usa_02166c14 = {0, 0xa0, 0, func_0209a728, (void (*)(void)) func_0209a47c};
Unk02166a74 data_usa_02166c48 = {0, 0xa0, 0, func_0209a728, (void (*)(void)) func_0209a398};
Unk02166a74 data_usa_02166eec = {0, 0xa0, 0, func_0209a728, (void (*)(void)) func_0209a644};
Unk02166a74 data_usa_02166cb0 = {0, 0xa0, 0, func_0209a728, (void (*)(void)) func_0209a1d0};
Unk02166a74 data_usa_02166ce4 = {0, 0xa0, 0, func_0209a728, (void (*)(void)) func_0209a0ec};
Unk02166a74 data_usa_02166d18 = {0, 0xa0, 0, func_0209a728, (void (*)(void)) func_0209a008};
Unk02166a74 data_usa_02166e1c = {0, 0xa0, 0, func_0209a728, (void (*)(void)) func_0209a2b4};
Unk02166a74 data_usa_02166d4c = {0, 0xa0, 0, func_0209a728, (void (*)(void)) func_02099f24};
Unk02166a74 data_usa_02166d80 = {0, 0xa0, 0, func_0209a728, (void (*)(void)) func_02099f24};
Unk02166a74 data_usa_02166db4 = {0, 0xa0, 0, func_0209a728, func_02099e40};
Unk02166a74 data_usa_02166de8 = {0, 0xa0, 0, func_0209a728, func_02099e40};
Unk02166a74 data_usa_02166e50 = {0, 0xa0, 0, func_0209a728, func_02099d5c};
Unk02166a74 data_usa_02166e84 = {0, 0xa0, 0, func_0209a728, func_02099c78};
Unk02166a74 data_usa_02166eb8 = {0, 0xa0, 0, func_0209a728, (void (*)(void)) func_0209a560};
Unk02166a74 data_usa_02166f20 = {0, 0xa0, 0, func_0209a728, func_02099c78};
Unk02166a74 data_usa_02166f54 = {0, 0xa0, 0, func_0209a728, func_02099b94};
Unk02166a74 data_usa_02166ff0 = {0, 0xa0, 0, func_0209a728, func_020999cc};
Unk02166a74 data_usa_02167024 = {0, 0xa0, 0, func_0209a728, func_020998e8};
Unk02166a74 data_usa_02166bac = {0, 0xa0, 0, func_0209a728, func_02099474};
Unk02166a74 data_usa_02166a74 = {0, 0xa0, 0, func_0209a728, func_02099804};
Unk02166a74 data_usa_02166aa8 = {0, 0xa0, 0, func_0209a728, func_02099720};
Unk02166a74 data_usa_02166adc = {0, 0xa0, 0, func_0209a728, func_0209963c};
Unk02166a74 data_usa_02166b10 = {0, 0xa0, 0, func_0209a728, func_02099558};
Unk02166a74 data_usa_02166b78 = {0, 0xa0, 0, func_0209a728, (void (*)(void)) func_0209a644};
Unk02166a74 data_usa_02166be0 = {0, 0xa0, 0, func_0209a728, func_02099390};
Unk02166a74 data_usa_02166c7c = {0, 0xa0, 0, func_0209a728, func_020992ac};

void func_0209a728(void) {
    Unk0209bf70 *o;

    o = (Unk0209bf70 *) func_0209bf8c();
    o->mUnk_24 = 0x84;
}

void CreateBeachTree1(void *a) {
    gBeachTree1 = func_0209bd08(a, "BeachTree1.nsbmd");
    func_0209b940(gBeachTree1, 0x3f);
}

void func_0209a6dc(void *a) {
    func_0209bbd0(a, gBeachTree1);
}

void func_0209a668(u32 a, int b) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (b + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (b + 0x1c), 3);
    func_0209ba88(a, gBeachTree1, b);
}

void *func_0209a644(void) {
    return (void *) func_0209bef0(CreateBeachTree1, func_0209a668, func_0209a6dc);
}

void CreateOpaTree1(void *a) {
    gOpaTree1 = func_0209bd08(a, "opa_tree1.nsbmd");
    func_0209b940(gOpaTree1, 0x3f);
}

void func_0209a5f8(void *a) {
    func_0209bbd0(a, gOpaTree1);
}

void func_0209a584(u32 a, int b) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (b + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (b + 0x1c), 3);
    func_0209ba88(a, gOpaTree1, b);
}

void *func_0209a560(void) {
    return (void *) func_0209bef0(CreateOpaTree1, func_0209a584, func_0209a5f8);
}

void CreateOlgMush1(void *a) {
    gOlgMush1 = func_0209bd08(a, "OlgMush1.nsbmd");
    func_0209b940(gOlgMush1, 0x3f);
}

void func_0209a514(void *a) {
    func_0209bbd0(a, gOlgMush1);
}

void func_0209a4a0(u32 a, int b) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (b + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (b + 0x1c), 3);
    func_0209ba88(a, gOlgMush1, b);
}

void *func_0209a47c(void) {
    return (void *) func_0209bef0(CreateOlgMush1, func_0209a4a0, func_0209a514);
}

void CreateOlgPipe1(void *a) {
    gOlgPipe1 = func_0209bd08(a, "OlgPipe1.nsbmd");
    func_0209b940(gOlgPipe1, 0x3f);
}

void func_0209a430(void *a) {
    func_0209bbd0(a, gOlgPipe1);
}

void func_0209a3bc(u32 a, int b) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (b + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (b + 0x1c), 3);
    func_0209ba88(a, gOlgPipe1, b);
}

void *func_0209a398(void) {
    return (void *) func_0209bef0(CreateOlgPipe1, func_0209a3bc, func_0209a430);
}

void CreateOf6yoshi1(void *a) {
    gOf6yoshi1 = func_0209bd08(a, "of6yoshi1.nsbmd");
    func_0209b940(gOf6yoshi1, 0x3f);
}

void func_0209a34c(void *a) {
    func_0209bbd0(a, gOf6yoshi1);
}

void func_0209a2d8(u32 a, int b) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (b + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (b + 0x1c), 3);
    func_0209ba88(a, gOf6yoshi1, b);
}

void *func_0209a2b4(void) {
    return (void *) func_0209bef0(CreateOf6yoshi1, func_0209a2d8, func_0209a34c);
}

void CreateNsCannon1(void *a) {
    gNsCannon1 = func_0209bd08(a, "NsCannon1.nsbmd");
    func_0209b940(gNsCannon1, 0x3f);
}

void func_0209a268(void *a) {
    func_0209bbd0(a, gNsCannon1);
}

void func_0209a1f4(u32 a, int b) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (b + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (b + 0x1c), 3);
    func_0209ba88(a, gNsCannon1, b);
}

void *func_0209a1d0(void) {
    return (void *) func_0209bef0(CreateNsCannon1, func_0209a1f4, func_0209a268);
}

void CreateCrossTree1(void *a) {
    gCrossTree1 = func_0209bd08(a, "CrossTree1.nsbmd");
    func_0209b940(gCrossTree1, 0x3f);
}

void func_0209a184(void *a) {
    func_0209bbd0(a, gCrossTree1);
}

void func_0209a110(u32 a, int b) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (b + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (b + 0x1c), 3);
    func_0209ba88(a, gCrossTree1, b);
}

void *func_0209a0ec(void) {
    return (void *) func_0209bef0(CreateCrossTree1, func_0209a110, func_0209a184);
}

void CreateBankTree1(void *a) {
    gBankTree1 = func_0209bd08(a, "Bank_Tree1.nsbmd");
    func_0209b940(gBankTree1, 0x3f);
}

void func_0209a0a0(void *a) {
    func_0209bbd0(a, gBankTree1);
}

void func_0209a02c(u32 a, int b) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (b + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (b + 0x1c), 3);
    func_0209ba88(a, gBankTree1, b);
}

void *func_0209a008(void) {
    return (void *) func_0209bef0(CreateBankTree1, func_0209a02c, func_0209a0a0);
}

void CreateGardenTree1(void *a) {
    gGardenTree1 = func_0209bd08(a, "GardenTree1.nsbmd");
    func_0209b940(gGardenTree1, 0x3f);
}

void func_02099fbc(void *a) {
    func_0209bbd0(a, gGardenTree1);
}

void func_02099f48(u32 a, int b) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (b + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (b + 0x1c), 3);
    func_0209ba88(a, gGardenTree1, b);
}

void *func_02099f24(void) {
    return (void *) func_0209bef0(CreateGardenTree1, func_02099f48, func_02099fbc);
}

void CreateTownTree1(void *a) {
    gTownTree1 = func_0209bd08(a, "TownTree1.nsbmd");
    func_0209b940(gTownTree1, 0x3f);
}

void func_02099ed8(void *a) {
    func_0209bbd0(a, gTownTree1);
}

void func_02099e64(u32 a, int b) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (b + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (b + 0x1c), 3);
    func_0209ba88(a, gTownTree1, b);
}

void func_02099e40(void) {
    func_0209bef0(CreateTownTree1, func_02099e64, func_02099ed8);
}

void CreateMarioTree3(void *a) {
    gMarioTree3 = func_0209bd08(a, "MarioTree3.nsbmd");
    func_0209b940(gMarioTree3, 0x3f);
}

void func_02099df4(void *a) {
    func_0209bbd0(a, gMarioTree3);
}

void func_02099d80(u32 a, int b) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (b + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (b + 0x1c), 3);
    func_0209ba88(a, gMarioTree3, b);
}

void func_02099d5c(void) {
    func_0209bef0(CreateMarioTree3, func_02099d80, func_02099df4);
}

void CreateSnowTree1(void *a) {
    gSnowTree1 = func_0209bd08(a, "Snow_Tree1.nsbmd");
    func_0209b940(gSnowTree1, 0x3f);
}

void func_02099d10(void *a) {
    func_0209bbd0(a, gSnowTree1);
}

void func_02099c9c(u32 a, int b) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (b + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (b + 0x1c), 3);
    func_0209ba88(a, gSnowTree1, b);
}

void func_02099c78(void) {
    func_0209bef0(CreateSnowTree1, func_02099c9c, func_02099d10);
}

void CreateDeTree1(void *a) {
    gDeTree1 = func_0209bd08(a, "DeTree1.nsbmd");
    func_0209b940(gDeTree1, 0x3f);
}

void func_02099c2c(void *a) {
    func_0209bbd0(a, gDeTree1);
}

void func_02099bb8(u32 a, int b) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (b + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (b + 0x1c), 3);
    func_0209ba88(a, gDeTree1, b);
}

void func_02099b94(void) {
    func_0209bef0(CreateDeTree1, func_02099bb8, func_02099c2c);
}

void CreateOlaTree1c(void *a) {
    gOlaTree1c = func_0209bd08(a, "olaTree1c.nsbmd");
    func_0209b940(gOlaTree1c, 0x3f);
}

void func_02099b48(void *a) {
    func_0209bbd0(a, gOlaTree1c);
}

void func_02099ad4(u32 a, int b) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (b + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (b + 0x1c), 3);
    func_0209ba88(a, gOlaTree1c, b);
}

void func_02099ab0(void) {
    func_0209bef0(CreateOlaTree1c, func_02099ad4, func_02099b48);
}

void CreateOsaTree1c(void *a) {
    gOsaTree1c = func_0209bd08(a, "osaTree1c.nsbmd");
    func_0209b940(gOsaTree1c, 0x3f);
}

void func_02099a64(void *a) {
    func_0209bbd0(a, gOsaTree1c);
}

void func_020999f0(u32 a, int b) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (b + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (b + 0x1c), 3);
    func_0209ba88(a, gOsaTree1c, b);
}

void func_020999cc(void) {
    func_0209bef0(CreateOsaTree1c, func_020999f0, func_02099a64);
}

void CreateKinoHouse1(void *a) {
    gKinoHouse1 = func_0209bd08(a, "KinoHouse1.nsbmd");
    func_0209b940(gKinoHouse1, 0x3f);
}

void func_02099980(void *a) {
    func_0209bbd0(a, gKinoHouse1);
}

void func_0209990c(u32 a, int b) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (b + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (b + 0x1c), 3);
    func_0209ba88(a, gKinoHouse1, b);
}

void func_020998e8(void) {
    func_0209bef0(CreateKinoHouse1, func_0209990c, func_02099980);
}

void CreateKinoHouse2(void *a) {
    gKinoHouse2 = func_0209bd08(a, "KinoHouse2.nsbmd");
    func_0209b940(gKinoHouse2, 0x3f);
}

void func_0209989c(void *a) {
    func_0209bbd0(a, gKinoHouse2);
}

void func_02099828(u32 a, int b) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (b + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (b + 0x1c), 3);
    func_0209ba88(a, gKinoHouse2, b);
}

void func_02099804(void) {
    func_0209bef0(CreateKinoHouse2, func_02099828, func_0209989c);
}

void CreateKinoMount1(void *a) {
    gKinoMount1 = func_0209bd08(a, "KinoMount1.nsbmd");
    func_0209b940(gKinoMount1, 0x3f);
}

void func_020997b8(void *a) {
    func_0209bbd0(a, gKinoMount1);
}

void func_02099744(u32 a, int b) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (b + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (b + 0x1c), 3);
    func_0209ba88(a, gKinoMount1, b);
}

void func_02099720(void) {
    func_0209bef0(CreateKinoMount1, func_02099744, func_020997b8);
}

void CreateKinoMount2(void *a) {
    gKinoMount2 = func_0209bd08(a, "KinoMount2.nsbmd");
    func_0209b940(gKinoMount2, 0x3f);
}

void func_020996d4(void *a) {
    func_0209bbd0(a, gKinoMount2);
}

void func_02099660(u32 a, int b) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (b + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (b + 0x1c), 3);
    func_0209ba88(a, gKinoMount2, b);
}

void func_0209963c(void) {
    func_0209bef0(CreateKinoMount2, func_02099660, func_020996d4);
}

void CreateOm6Tree1(void *a) {
    gOm6Tree1 = func_0209bd08(a, "om6Tree1.nsbmd");
    func_0209b940(gOm6Tree1, 0x3f);
}

void func_020995f0(void *a) {
    func_0209bbd0(a, gOm6Tree1);
}

void func_0209957c(u32 a, int b) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (b + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (b + 0x1c), 3);
    func_0209ba88(a, gOm6Tree1, b);
}

void func_02099558(void) {
    func_0209bef0(CreateOm6Tree1, func_0209957c, func_020995f0);
}

void CreateOf6Tree1(void *a) {
    gOf6Tree1 = func_0209bd08(a, "Of6Tree1.nsbmd");
    func_0209b940(gOf6Tree1, 0x3f);
}

void func_0209950c(void *a) {
    func_0209bbd0(a, gOf6Tree1);
}

void func_02099498(u32 a, int b) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (b + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (b + 0x1c), 3);
    func_0209ba88(a, gOf6Tree1, b);
}

void func_02099474(void) {
    func_0209bef0(CreateOf6Tree1, func_02099498, func_0209950c);
}

void CreateBankEgg1(void *a) {
    gBankEgg1 = func_0209bd08(a, "BankEgg1.nsbmd");
    func_0209b940(gBankEgg1, 0x3f);
}

void func_02099428(void *a) {
    func_0209bbd0(a, gBankEgg1);
}

void func_020993b4(u32 a, int b) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (b + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (b + 0x1c), 3);
    func_0209ba88(a, gBankEgg1, b);
}

void func_02099390(void) {
    func_0209bef0(CreateBankEgg1, func_020993b4, func_02099428);
}

void CreateMiniDokan(void *a) {
    gMiniDokan = func_0209bd08(a, "mini_dokan.nsbmd");
    func_0209b940(gMiniDokan, 0x3f);
}

void func_02099344(void *a) {
    func_0209bbd0(a, gMiniDokan);
}

void func_020992d0(u32 a, int b) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (b + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (b + 0x1c), 3);
    func_0209ba88(a, gMiniDokan, b);
}

void func_020992ac(void) {
    func_0209bef0(CreateMiniDokan, func_020992d0, func_02099344);
}
