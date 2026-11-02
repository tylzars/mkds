#include "Main/Unknown/code_020992ac.h"

#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/unk_0217b000.h"

void *data_0217b154;
void *data_0217b11c;
void *data_0217b170;
void *data_0217b150;
void *data_0217b160;
void *data_0217b158;
void *data_0217b128;
void *data_0217b12c;
void *data_0217b124;
void *data_0217b138;
void *data_0217b134;
void *data_0217b16c;
void *data_0217b130;
void *data_0217b148;
void *data_0217b144;
void *data_0217b14c;
void *data_0217b140;
void *data_0217b118;
void *data_0217b13c;
void *data_0217b168;
void *data_0217b164;
void *data_0217b120;
void *data_0217b15c;

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

void func_0209a6f4(void *a) {
    data_0217b150 = func_0209bd08(a, "BeachTree1.nsbmd");
    func_0209b940(data_0217b150, 0x3f);
}

void func_0209a6dc(void *a) {
    func_0209bbd0(a, data_0217b150);
}

void func_0209a668(u32 param_1, int param_2) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (param_2 + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (param_2 + 0x1c), 3);
    func_0209ba88(param_1, data_0217b150, param_2);
}

void *func_0209a644(void) {
    return (void *) func_0209bef0(func_0209a6f4, func_0209a668, func_0209a6dc);
}

void func_0209a610(void *a) {
    data_0217b140 = func_0209bd08(a, "opa_tree1.nsbmd");
    func_0209b940(data_0217b140, 0x3f);
}

void func_0209a5f8(void *a) {
    func_0209bbd0(a, data_0217b140);
}

void func_0209a584(u32 param_1, int param_2) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (param_2 + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (param_2 + 0x1c), 3);
    func_0209ba88(param_1, data_0217b140, param_2);
}

void *func_0209a560(void) {
    return (void *) func_0209bef0(func_0209a610, func_0209a584, func_0209a5f8);
}

void func_0209a52c(void *a) {
    data_0217b16c = func_0209bd08(a, "OlgMush1.nsbmd");
    func_0209b940(data_0217b16c, 0x3f);
}

void func_0209a514(void *a) {
    func_0209bbd0(a, data_0217b16c);
}

void func_0209a4a0(u32 param_1, int param_2) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (param_2 + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (param_2 + 0x1c), 3);
    func_0209ba88(param_1, data_0217b16c, param_2);
}

void *func_0209a47c(void) {
    return (void *) func_0209bef0(func_0209a52c, func_0209a4a0, func_0209a514);
}

void func_0209a448(void *a) {
    data_0217b14c = func_0209bd08(a, "OlgPipe1.nsbmd");
    func_0209b940(data_0217b14c, 0x3f);
}

void func_0209a430(void *a) {
    func_0209bbd0(a, data_0217b14c);
}

void func_0209a3bc(u32 param_1, int param_2) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (param_2 + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (param_2 + 0x1c), 3);
    func_0209ba88(param_1, data_0217b14c, param_2);
}

void *func_0209a398(void) {
    return (void *) func_0209bef0(func_0209a448, func_0209a3bc, func_0209a430);
}

void func_0209a364(void *a) {
    data_0217b15c = func_0209bd08(a, "of6yoshi1.nsbmd");
    func_0209b940(data_0217b15c, 0x3f);
}

void func_0209a34c(void *a) {
    func_0209bbd0(a, data_0217b15c);
}

void func_0209a2d8(u32 param_1, int param_2) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (param_2 + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (param_2 + 0x1c), 3);
    func_0209ba88(param_1, data_0217b15c, param_2);
}

void *func_0209a2b4(void) {
    return (void *) func_0209bef0(func_0209a364, func_0209a2d8, func_0209a34c);
}

void func_0209a280(void *a) {
    data_0217b170 = func_0209bd08(a, "NsCannon1.nsbmd");
    func_0209b940(data_0217b170, 0x3f);
}

void func_0209a268(void *a) {
    func_0209bbd0(a, data_0217b170);
}

void func_0209a1f4(u32 param_1, int param_2) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (param_2 + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (param_2 + 0x1c), 3);
    func_0209ba88(param_1, data_0217b170, param_2);
}

void *func_0209a1d0(void) {
    return (void *) func_0209bef0(func_0209a280, func_0209a1f4, func_0209a268);
}

void func_0209a19c(void *a) {
    data_0217b11c = func_0209bd08(a, "CrossTree1.nsbmd");
    func_0209b940(data_0217b11c, 0x3f);
}

void func_0209a184(void *a) {
    func_0209bbd0(a, data_0217b11c);
}

void func_0209a110(u32 param_1, int param_2) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (param_2 + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (param_2 + 0x1c), 3);
    func_0209ba88(param_1, data_0217b11c, param_2);
}

void *func_0209a0ec(void) {
    return (void *) func_0209bef0(func_0209a19c, func_0209a110, func_0209a184);
}

void func_0209a0b8(void *a) {
    data_0217b144 = func_0209bd08(a, "Bank_Tree1.nsbmd");
    func_0209b940(data_0217b144, 0x3f);
}

void func_0209a0a0(void *a) {
    func_0209bbd0(a, data_0217b144);
}

void func_0209a02c(u32 param_1, int param_2) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (param_2 + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (param_2 + 0x1c), 3);
    func_0209ba88(param_1, data_0217b144, param_2);
}

void *func_0209a008(void) {
    return (void *) func_0209bef0(func_0209a0b8, func_0209a02c, func_0209a0a0);
}

void func_02099fd4(void *a) {
    data_0217b118 = func_0209bd08(a, "GardenTree1.nsbmd");
    func_0209b940(data_0217b118, 0x3f);
}

void func_02099fbc(void *a) {
    func_0209bbd0(a, data_0217b118);
}

void func_02099f48(u32 param_1, int param_2) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (param_2 + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (param_2 + 0x1c), 3);
    func_0209ba88(param_1, data_0217b118, param_2);
}

void *func_02099f24(void) {
    return (void *) func_0209bef0(func_02099fd4, func_02099f48, func_02099fbc);
}

void func_02099ef0(void *a) {
    data_0217b124 = func_0209bd08(a, "TownTree1.nsbmd");
    func_0209b940(data_0217b124, 0x3f);
}

void func_02099ed8(void *a) {
    func_0209bbd0(a, data_0217b124);
}

void func_02099e64(u32 param_1, int param_2) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (param_2 + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (param_2 + 0x1c), 3);
    func_0209ba88(param_1, data_0217b124, param_2);
}

void func_02099e40(void) {
    func_0209bef0(func_02099ef0, func_02099e64, func_02099ed8);
}

void func_02099e0c(void *a) {
    data_0217b134 = func_0209bd08(a, "MarioTree3.nsbmd");
    func_0209b940(data_0217b134, 0x3f);
}

void func_02099df4(void *a) {
    func_0209bbd0(a, data_0217b134);
}

void func_02099d80(u32 param_1, int param_2) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (param_2 + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (param_2 + 0x1c), 3);
    func_0209ba88(param_1, data_0217b134, param_2);
}

void func_02099d5c(void) {
    func_0209bef0(func_02099e0c, func_02099d80, func_02099df4);
}

void func_02099d28(void *a) {
    data_0217b168 = func_0209bd08(a, "Snow_Tree1.nsbmd");
    func_0209b940(data_0217b168, 0x3f);
}

void func_02099d10(void *a) {
    func_0209bbd0(a, data_0217b168);
}

void func_02099c9c(u32 param_1, int param_2) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (param_2 + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (param_2 + 0x1c), 3);
    func_0209ba88(param_1, data_0217b168, param_2);
}

void func_02099c78(void) {
    func_0209bef0(func_02099d28, func_02099c9c, func_02099d10);
}

void func_02099c44(void *a) {
    data_0217b154 = func_0209bd08(a, "DeTree1.nsbmd");
    func_0209b940(data_0217b154, 0x3f);
}

void func_02099c2c(void *a) {
    func_0209bbd0(a, data_0217b154);
}

void func_02099bb8(u32 param_1, int param_2) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (param_2 + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (param_2 + 0x1c), 3);
    func_0209ba88(param_1, data_0217b154, param_2);
}

void func_02099b94(void) {
    func_0209bef0(func_02099c44, func_02099bb8, func_02099c2c);
}

void func_02099b60(void *a) {
    data_0217b130 = func_0209bd08(a, "olaTree1c.nsbmd");
    func_0209b940(data_0217b130, 0x3f);
}

void func_02099b48(void *a) {
    func_0209bbd0(a, data_0217b130);
}

void func_02099ad4(u32 param_1, int param_2) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (param_2 + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (param_2 + 0x1c), 3);
    func_0209ba88(param_1, data_0217b130, param_2);
}

void func_02099ab0(void) {
    func_0209bef0(func_02099b60, func_02099ad4, func_02099b48);
}

void func_02099a7c(void *a) {
    data_0217b12c = func_0209bd08(a, "osaTree1c.nsbmd");
    func_0209b940(data_0217b12c, 0x3f);
}

void func_02099a64(void *a) {
    func_0209bbd0(a, data_0217b12c);
}

void func_020999f0(u32 param_1, int param_2) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (param_2 + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (param_2 + 0x1c), 3);
    func_0209ba88(param_1, data_0217b12c, param_2);
}

void func_020999cc(void) {
    func_0209bef0(func_02099a7c, func_020999f0, func_02099a64);
}

void func_02099998(void *a) {
    data_0217b148 = func_0209bd08(a, "KinoHouse1.nsbmd");
    func_0209b940(data_0217b148, 0x3f);
}

void func_02099980(void *a) {
    func_0209bbd0(a, data_0217b148);
}

void func_0209990c(u32 param_1, int param_2) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (param_2 + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (param_2 + 0x1c), 3);
    func_0209ba88(param_1, data_0217b148, param_2);
}

void func_020998e8(void) {
    func_0209bef0(func_02099998, func_0209990c, func_02099980);
}

void func_020998b4(void *a) {
    data_0217b128 = func_0209bd08(a, "KinoHouse2.nsbmd");
    func_0209b940(data_0217b128, 0x3f);
}

void func_0209989c(void *a) {
    func_0209bbd0(a, data_0217b128);
}

void func_02099828(u32 param_1, int param_2) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (param_2 + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (param_2 + 0x1c), 3);
    func_0209ba88(param_1, data_0217b128, param_2);
}

void func_02099804(void) {
    func_0209bef0(func_020998b4, func_02099828, func_0209989c);
}

void func_020997d0(void *a) {
    data_0217b120 = func_0209bd08(a, "KinoMount1.nsbmd");
    func_0209b940(data_0217b120, 0x3f);
}

void func_020997b8(void *a) {
    func_0209bbd0(a, data_0217b120);
}

void func_02099744(u32 param_1, int param_2) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (param_2 + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (param_2 + 0x1c), 3);
    func_0209ba88(param_1, data_0217b120, param_2);
}

void func_02099720(void) {
    func_0209bef0(func_020997d0, func_02099744, func_020997b8);
}

void func_020996ec(void *a) {
    data_0217b13c = func_0209bd08(a, "KinoMount2.nsbmd");
    func_0209b940(data_0217b13c, 0x3f);
}

void func_020996d4(void *a) {
    func_0209bbd0(a, data_0217b13c);
}

void func_02099660(u32 param_1, int param_2) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (param_2 + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (param_2 + 0x1c), 3);
    func_0209ba88(param_1, data_0217b13c, param_2);
}

void func_0209963c(void) {
    func_0209bef0(func_020996ec, func_02099660, func_020996d4);
}

void func_02099608(void *a) {
    data_0217b158 = func_0209bd08(a, "om6Tree1.nsbmd");
    func_0209b940(data_0217b158, 0x3f);
}

void func_020995f0(void *a) {
    func_0209bbd0(a, data_0217b158);
}

void func_0209957c(u32 param_1, int param_2) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (param_2 + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (param_2 + 0x1c), 3);
    func_0209ba88(param_1, data_0217b158, param_2);
}

void func_02099558(void) {
    func_0209bef0(func_02099608, func_0209957c, func_020995f0);
}

void func_02099524(void *a) {
    data_0217b138 = func_0209bd08(a, "Of6Tree1.nsbmd");
    func_0209b940(data_0217b138, 0x3f);
}

void func_0209950c(void *a) {
    func_0209bbd0(a, data_0217b138);
}

void func_02099498(u32 param_1, int param_2) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (param_2 + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (param_2 + 0x1c), 3);
    func_0209ba88(param_1, data_0217b138, param_2);
}

void func_02099474(void) {
    func_0209bef0(func_02099524, func_02099498, func_0209950c);
}

void func_02099440(void *a) {
    data_0217b164 = func_0209bd08(a, "BankEgg1.nsbmd");
    func_0209b940(data_0217b164, 0x3f);
}

void func_02099428(void *a) {
    func_0209bbd0(a, data_0217b164);
}

void func_020993b4(u32 param_1, int param_2) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (param_2 + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (param_2 + 0x1c), 3);
    func_0209ba88(param_1, data_0217b164, param_2);
}

void func_02099390(void) {
    func_0209bef0(func_02099440, func_020993b4, func_02099428);
}

void func_0209935c(void *a) {
    data_0217b160 = func_0209bd08(a, "mini_dokan.nsbmd");
    func_0209b940(data_0217b160, 0x3f);
}

void func_02099344(void *a) {
    func_0209bbd0(a, data_0217b160);
}

void func_020992d0(u32 param_1, int param_2) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (param_2 + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (param_2 + 0x1c), 3);
    func_0209ba88(param_1, data_0217b160, param_2);
}

void func_020992ac(void) {
    func_0209bef0(func_0209935c, func_020992d0, func_02099344);
}
