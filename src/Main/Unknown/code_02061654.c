#include "Main/Unknown/code_02061654.h"

#include "Main/Unknown/code_02056b30.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0203ca20.h"
#include "Main/Unknown/code_0207a30c.h"
#include "Main/Unknown/code_02062ed8.h"
#include "Main/Unknown/code_02036820.h"
#include "registers.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_02076cd0.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02063000.h"
#include "Main/Unknown/code_0203d568.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0208eb10.h"
#include "Main/Unknown/code_02017000.h"
#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_02075000.h"
#include "Main/Unknown/code_02076000.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/code_02078000.h"
#include "code_02013740.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02088000.h"
#include "Main/Unknown/unk_02155000.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_02077bc0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_02073e04.h"
#include "Main/Unknown/code_02073e98.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/code_02086058.h"
#include "Main/Unknown/code_02086e8c.h"
#include "Main/Unknown/code_02088338.h"
#include "Main/Unknown/code_02089fa0.h"
#include "Main/Unknown/code_02018000.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_0208533c.h"
#include "Main/Unknown/code_0203c5ac.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0205b0f4.h"
#include "Main/Unknown/code_020a02f8.h"
#include "Main/Unknown/code_020af66c.h"
#include "Main/Unknown/code_020d2d94.h"
#include "Main/Unknown/code_020d2dec.h"
#include "Main/Unknown/code_020d4130.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d50c4.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_020e7a84.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_021031f4.h"
#include "Main/Unknown/code_02148d24.h"
#include "code_0214a730.h"
#include "code_02010c84.h"
#include "code_02012b20.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "00/code_021832d8.h"
#include "00/code_02181f98.h"
#include "code_02015f98.h"
#include "code_020162b0.h"
#include "code_0214a748.h"
#include "Main/Unknown/code_02042064.h"
#include "01/code_0218155c.h"

u32 func_02062ec4(void) {
    return ((u32) data_0217aa54->mUnk_28);
}

u32 func_02062eb0(void) {
    return ((u32) data_0217aa54->mUnk_38);
}

extern const u16 data_02154970[8];
extern const u16 data_02154980[8];

void func_02062b50(void) {
    void *a;
    u16 b;
    s16 i;
    u16 j;

    a = GetHeap(func_020364e8());
    SetKartModelPathPrefix(0);
    data_0217aa54 = HeapAlloc(a, 72);
    func_02062a0c();
    b = func_02148d24();
    func_020161b4((u16) (((b >> 3) & 1) + ((b >> 2) & 1) + ((b >> 1) & 1) + (b & 1)), 1);
    func_02016414(0x10000, 1);
    func_0208533c();
    func_02077998();
    func_02047b6c(1);
    func_020875b4();
    InitKartModels(a, data_021759c0->mKartCount);
    func_0207800c();
    func_020872a4();
    func_02047728();
    InitMap2D();
    func_02047b6c(2);
    CreateCourseMap(a);
    func_0206331c(a);
    func_020476ec();
    func_02047b6c(7);
    func_0203d848(a);
    func_0205cd24(a);
    func_02047b6c(2);
    InitCourseCollision();
    func_02047b6c(8);
    func_020d58c0();
    func_02047b6c(1);
    func_0208aa30(a);
    func_02085e04();
    InitKarts(data_021759c0->mKartCount);
    func_02077944();
    func_020777ac(data_021759c0->mUnk_063);
    if (data_0217aa54->mUnk_28 != 0) {
        if (data_0217aa54->mUnk_2c != 0) {
            func_020775e4();
        } else {
            func_0207767c();
        }
    }
    data_0217aa88 = func_020748a8();
    data_0217aa5c = func_02074898();
    data_0217aa6c = data_0217aa88;
    data_0217aa7c = &data_0217aa88->mUnk_030;
    func_02077060(data_0217aa88);
    func_02047b6c(3);
    switch (data_021759c0->mMode) {
        case 2:
            func_020a0e00();
            break;
        case 4:
            if (data_021759c0->mMode == 4) {
                func_ov001_021819f4();
            }
            if (data_021759c0->mMode == 4) {
                func_020a0e00();
            }
            break;
    }
    func_02047b6c(3);
    func_020e7460();
    func_020e7760();
    InitMapObjects();
    func_020fa13c();
    func_02047b6c(6);
    func_0208b934(a);
    func_020846c0(a);
    func_0208e570(a);
    func_0208f0f8(a);
    func_02047b6c(9);
    *(u16 *) 0x05000000 = 0xff00;
    reg_G3X_DISP3DCNT = reg_G3X_DISP3DCNT & 0xffffcffd;
    func_0214a730(data_0217aadc);
    for (i = 0; i < 8; i++) {
        data_0217aadc[i] = data_02154970[i];
        data_0217aadc[i + 16] = data_02154980[i];
    }
    for (i = 0; i < 8; i++) {
        data_0217aadc[i + 8] = data_0217aadc[i];
        data_0217aadc[i + 24] = data_0217aadc[i + 16];
    }
    func_02061c28();
    func_020631b0();
    if (data_021759c0->mUnk_00c == 5) {
        for (j = 0; j < 3; j++) {
            func_0208eb1c(j);
        }
    }
}

void func_02062a0c(void) {
    Vec3 v;
    s32 m;

    data_0217aa54->mUnk_04 = 0;
    data_0217aa54->mUnk_08 = 0;
    data_0217aa54->mUnk_14 = 0;
    data_0217aa54->mUnk_10 = 0;
    data_0217aa54->mUnk_0c = 0;
    data_0217aa54->mUnk_18 = 0;
    data_0217aa54->mUnk_1c = 0;
    data_0217aa54->mUnk_30 = 0;
    data_0217aa54->mUnk_34 = 0;
    data_0217aa54->mUnk_3c = 0;
    v = data_021653f0;
    data_0217aa54->mUnk_40 = v.x;
    data_0217aa54->mUnk_42 = v.y;
    data_0217aa54->mUnk_44 = v.z;
    data_0217aa54->mUnk_28 = (u32) (data_021759c0->mUnk_00c - 3) <= 2 ? 1 : 0;
    data_0217aa54->mUnk_2c = data_021759c0->mUnk_00c == 4 ? 1 : 0;
    data_0217aa54->mUnk_38 = (data_021759c0->mUnk_00c == 5 || data_021759c0->mUnk_00c == 6) != 0 ? 1 : 0;
    data_0217aa54->mUnk_00 = data_0217aa54->mUnk_38 != 0 ? 1 : 0;
}

void func_020629a4(void) {
    u16 b;

    b = func_02148d24();
    func_020161b4((u16) (((b >> 3) & 1) + ((b >> 2) & 1) + ((b >> 1) & 1) + (b & 1)), 1);
    func_02016414(0x10000, 1);
    func_0208533c();
}

void func_02062860(void) {
    func_02012f24();
    func_02011074();
    func_01ff92b4();
    func_02012b20(1);
    data_021759d0->mUnk_1c |= 8;
    func_02010fac(0, 0, -0x1000, 0);
    func_02010fac(1, 0x93d, 0x93d, 0x93d);
    func_02010fac(2, 0, -0x1000, 0);
    func_02010fac(3, 0, 0xfff, 0);
    func_02010f98(0, 0x7fff);
    func_02010f98(1, 0x6318);
    func_02010f98(2, 31);
    func_02010f98(3, 0x3ff);
    func_02010f74(0x5294, 0x5294, 0);
    func_02010f50(0, 0, 1);
    func_02010f24(15, 0, 2, 0, 31, 0);
    data_0217aa74 = HeapAlloc(data_021759d0->mHeap, 772);
    func_01ff92e0(data_0217aa74);
}

void func_02062464(void) {
    void *v;

    data_0217d020 = 1;
    func_01ffdb70();
    func_02063294();
    UpdateKarts();
    if (data_0217aa54->mUnk_0c == 0) {
        func_02085778();
    }
    switch (data_021759c0->mMode) {
        case 2:
            func_020a08ec();
            break;
        case 4:
            if (data_021759c0->mMode == 4) {
                func_ov001_02181860();
            }
            if (data_021759c0->mMode == 4) {
                func_020a08ec();
            }
            break;
    }
    func_02073e98();
    if (data_0217aa54->mUnk_28 != 0) {
        if (data_0217aa54->mUnk_2c != 0) {
            v = func_0207564c();
        } else {
            v = func_02075694();
        }
        data_0217aa7c = v;
        data_0217aa6c = func_02074888();
    } else if (func_0203c5e4() != 0) {
        func_02076528(data_0217aa88, GetKart(data_021759c0->mUnk_063));
        func_02076cd0(data_0217aa88);
        if (func_02075a94(data_0217aa5c) != 0) {
            data_0217aa6c = data_0217aa5c;
            data_0217aa7c = &data_0217aa5c->mUnk_030;
        } else {
            data_0217aa6c = data_0217aa88;
            data_0217aa7c = &data_0217aa88->mUnk_030;
        }
    } else {
        func_02076528(data_0217aa88, GetKart(data_021759c0->mEntryIndex));
        func_02076cd0(data_0217aa88);
        data_0217aa6c = data_0217aa88;
        data_0217aa7c = &data_0217aa88->mUnk_030;
    }
    func_02077060(data_0217aa6c);
    func_020d4f94((Unk020d4f94 *) data_0217aa7c);
    if (func_02073e88() != 0) {
        func_020d50c4();
    }
    func_020fa920();
    func_020e9d10();
    UpdateMapObjects();
    func_0208e400();
    func_0208f0a0();
    func_0208b8c8();
    if (data_0217aa64 != 0) {
        if (data_0217aa4c != 0) {
            if (data_021653e8 == 0) {
                data_0217aa54->mUnk_20 = 0;
                func_0207a5f0(1);
                func_02062ef8(0);
                data_0217aa64 = 0;
                data_0217aa4c = 0;
            } else {
                func_02061944(data_021653e8, 0);
            }
            data_021653e8 -= 4;
        } else {
            data_0217aa2c++;
            if (data_0217aa2c >= 72) {
                data_0217aa4c = 1;
            }
        }
    }
    func_0208a218();
    func_0203ca38();
    func_0207aa7c();
    func_0208677c();
    if (data_021759c0->mMode == 5) {
        if (data_0217aa54->mUnk_34 == 0) {
            if (data_0217aa54->mUnk_30 == 0) {
                data_0217aa54->mUnk_04++;
                if ((u32) data_0217aa54->mUnk_04 >= 128) {
                    data_0217aa54->mUnk_30 = 1;
                }
            }
        } else {
            data_0217aa54->mUnk_04++;
        }
    } else {
        data_0217aa54->mUnk_04++;
    }
    data_0217aa54->mUnk_0c = data_0217aa54->mUnk_04 & 7;
    data_0217aa54->mUnk_10 = data_0217aa54->mUnk_04 & 1;
    data_0217aa54->mUnk_14 = (u32) data_0217aa54->mUnk_04 % data_021759c0->mKartCount;
    func_0214a730(&data_0217aadc[data_0217aa54->mUnk_18]);
    data_0217aa54->mUnk_1c++;
    if ((u32) data_0217aa54->mUnk_1c > data_021653ec) {
        data_0217aa54->mUnk_1c = 0;
        data_0217aa54->mUnk_18++;
    }
    if ((u32) data_0217aa54->mUnk_18 > 7) {
        data_0217aa54->mUnk_18 = 0;
    }
}

void func_02062284(void) {
    if (data_0217aa4c != 0) {
        func_0214a7ec(1, 0, data_0217aa80, data_0217aa70);
        func_0214a748(data_0217aa9c);
        reg_G3X_FOG_COLOR = data_0217aa28 | (data_0217aa68 << 16);
    } else if (data_0217aa54->mUnk_20 != data_0217aa54->mUnk_24) {
        if (data_0217aa54->mUnk_20 == 0) {
            if (gCourseMap->mUnk_018->mUnk_05 != 0) {
                func_0214a7ec(1, 0, data_0217aa80, data_0217aa48);
                reg_G3X_FOG_COLOR = data_0217aa38 | (data_0217aa50 << 16);
                func_0214a748(data_0217aabc);
            } else {
                func_0214a7ec(0, 0, 5, 0);
            }
        } else {
            func_0214a7ec(1, 0, data_0217aa80, 0);
            reg_G3X_FOG_COLOR = data_0217aa30 | (data_0217aa60 << 16);
            func_0214a748(data_0217aa9c);
        }
    }
    data_0217aa54->mUnk_24 = data_0217aa54->mUnk_20;
    func_02062078();
    func_0208b870(data_0217aa7c);
    func_0208ee7c(data_0217aa7c);
    func_02089fa0();
    if (data_0217aa54->mUnk_28 == 0) {
        func_02086250(data_0217aa7c);
    }
    func_02104118();
    data_0217aa54->mUnk_08++;
}

void func_02062254(const Vec3 *a) {
    data_0217aa54->mUnk_40 = a->x;
    data_0217aa54->mUnk_42 = a->y;
    data_0217aa54->mUnk_44 = a->z;
}

void func_02062078(void) {
    Vec3 c;
    Vec3 a;
    Vec3 b;
    u32 v;
    Unk02061808 *p;

    func_02076c50(data_0217aa6c, 1);
    func_02076bcc(data_0217aa6c);
    p = data_0217aa6c;
    func_02010fac(0, data_0217aa54->mUnk_40, data_0217aa54->mUnk_42, data_0217aa54->mUnk_44);
    func_02010f98(0, 0x7fff);
    a.x = p->mUnk_030.mUnk_00[0].y;
    a.y = p->mUnk_030.mUnk_00[1].y;
    a.z = p->mUnk_030.mUnk_00[2].y;
    b.x = -p->mUnk_030.mUnk_00[0].z;
    b.y = -p->mUnk_030.mUnk_00[1].z;
    b.z = -p->mUnk_030.mUnk_00[2].z;
    Vec3Sub(&b, &a, &c);
    if ((s64) c.x * c.x + (s64) c.y * c.y + (s64) c.z * c.z >= 16) {
        func_02039860(&c, &c);
    }
    func_02010fac(1, (s16) c.x, (s16) c.y, (s16) c.z);
    func_02010f98(1, 0x7fff);
    func_02011034();
    func_01ff9048(23, data_0217aa7c, 12);
    v = 30;
    func_01ff9048(19, &v, 1);
    func_02063228();
    func_02076c50(data_0217aa6c, 0);
    func_02011034();
    func_01ff92e0(data_0217aa74);
    func_0206326c();
    func_020d4418((Unk020d4418 *) data_0217aa6c);
    func_01ff92b4();
    DrawKarts();
    func_02010fac(0, data_0217aa54->mUnk_40, data_0217aa54->mUnk_42, data_0217aa54->mUnk_44);
    func_020e9810();
    DrawMapObjects((Unk020d4418 *) data_0217aa6c);
    func_020fa8ac(data_0217aa7c);
    func_0208e358();
    func_01ff9234();
}

void func_02062004(void) {
    Unk0217d384 *p;
    BOOL f;

    func_020d2d94();
    func_0207a990();
    func_020848fc();
    func_0203d568();
    f = FALSE;
    p = data_0217d384;
    if (p != NULL && p->mHeapCreated != 0) {
        f = TRUE;
    }
    if (f != FALSE) {
        p->mKartMask = data_0217aa14->mUnk_749;
    }
    data_0217aa14 = NULL;
}

void func_02062000(void) {}

u32 func_02061fec(void) {
    return ((u32) data_0217aa54->mUnk_00);
}

void func_02061fcc(void) {
    data_0217aa54->mUnk_00 = 1;
    func_0203ca20();
}

u32 func_02061fb8(void) {
    return ((u32) data_0217aa54->mUnk_04);
}

u32 func_02061fa4(void) {
    return ((u32) data_0217aa54->mUnk_14);
}

u32 func_02061f90(void) {
    return ((u32) data_0217aa54->mUnk_0c);
}

u32 func_02061f7c(void) {
    return ((u32) data_0217aa54->mUnk_10);
}

void func_02061c28(void) {
    u32 a[32];
    u16 i;
    u8 m;

    func_02061944(72, 1);
    data_021653e8 = 72;
    data_0217aa4c = 0;
    data_0217aa64 = 0;
    data_0217aa2c = 0;
    data_0217aa54->mUnk_24 = 0;
    data_0217aa54->mUnk_20 = data_0217aa54->mUnk_24;
    if (gCourseMap->mUnk_018->mUnk_05 != 0) {
        m = gCourseMap->mUnk_018->mUnk_06;
        if (m == 0) {
            for (i = 0; i < 8; i++) {
                data_0217aabc[i] = ((i * 4) << 2) | ((i * 16 + 4) << 8) | ((i * 16 + 8) << 16) | ((i * 16 + 12) << 24);
            }
        } else if (m == 1) {
            for (i = 0; i < 32; i++) {
                a[i] = ((i + 1) * (i + 1)) / 8;
                if (a[i] > 127) {
                    a[i] = 127;
                }
            }
            a[0] = 0;
            for (i = 0; i < 8; i++) {
                data_0217aabc[i] = a[i * 4] | (a[i * 4 + 1] << 8) | (a[i * 4 + 2] << 16) | (a[i * 4 + 3] << 24);
            }
        } else if (m == 2) {
            for (i = 0; i < 32; i++) {
                a[i] = 128 - ((32 - (i + 1)) * (32 - (i + 1))) / 8;
                if (a[i] > 127) {
                    a[i] = 127;
                }
            }
            a[0] = 0;
            for (i = 0; i < 8; i++) {
                data_0217aabc[i] = a[i * 4] | (a[i * 4 + 1] << 8) | (a[i * 4 + 2] << 16) | (a[i * 4 + 3] << 24);
            }
        }
        data_0217aa38 = gCourseMap->mUnk_018->mUnk_14 & 0x7fff;
        data_0217aa50 = ((u32) gCourseMap->mUnk_018->mUnk_14 >> 15) & 31;
        data_0217aa80 = gCourseMap->mUnk_018->mUnk_07;
        data_0217aa48 = gCourseMap->mUnk_018->mUnk_10 / 512;
        data_0217aa40 = data_0217aa38 & 31;
        data_0217aa34 = (data_0217aa38 >> 5) & 31;
        data_0217aa3c = (data_0217aa38 >> 10) & 31;
    }
    if (gCourseMap->mUnk_018->mUnk_05 != 0) {
        func_0214a7ec(1, 0, data_0217aa80, data_0217aa48);
        *(u32 *) 0x04000358 = data_0217aa38 | (data_0217aa50 << 16);
        func_0214a748(data_0217aabc);
    } else {
        func_0214a7ec(0, 0, 5, 0);
    }
}

void func_02061944(s32 a, s32 b) {
    s32 t;
    s32 u;
    u32 j;
    u32 w;
    u16 i;
    s32 e;

    if (gCourseMap->mUnk_018->mUnk_05 != 0 && b == 0) {
        t = (s32) (((s64) 57 * (a << 12) + 0x800) >> 12);
        data_0217aa78 = t;
        u = 4096 - t;
        data_0217aa84 = u;
        data_0217aa44 = (s32) (((s64) t * 72 + 0x800) >> 12);
        data_0217aa28 = (s32) (((s64) data_0217aa40 * u + 0x800) >> 12) +
                        ((s32) (((s64) data_0217aa34 * u + 0x800) >> 12) << 5) +
                        ((s32) (((s64) data_0217aa3c * u + 0x800) >> 12) << 10);
        data_0217aa68 =
            (s32) (((s64) u * data_0217aa50 + 0x800) >> 12) + (s32) (((s64) t * data_0217aa60 + 0x800) >> 12);
        data_0217aa70 = (s32) (((s64) u * data_0217aa48 + 0x800) >> 12);
        for (i = 0; i < 8; i++) {
            w = data_0217aabc[i];
            data_0217aa8c[0] = w & 0xff;
            data_0217aa8c[1] = (w & 0xff00) >> 8;
            data_0217aa8c[2] = (w & 0xff0000) >> 16;
            data_0217aa8c[3] = (w & 0xff000000) >> 24;
            for (j = 0; j < 4; j++) {
                e = data_0217aa8c[j];
                data_0217aa8c[j] = (s32) (((s64) e * (s32) u + 0x800) >> 12) + data_0217aa44;
            }
            data_0217aa9c[i] =
                data_0217aa8c[0] | (data_0217aa8c[1] << 8) | (data_0217aa8c[2] << 16) | (data_0217aa8c[3] << 24);
        }
        data_0217aa58 = w;
    } else {
        for (i = 0; i < 8; i++) {
            data_0217aa9c[i] = a | (a << 8) | (a << 16) | (a << 24);
        }
    }
}

void func_02061874(void) {
    if (data_0217aa54->mUnk_24 == 1) {
        data_0217aa54->mUnk_24 = 0;
    }
    data_0217aa54->mUnk_20 = 1;
    func_0207a5f0(0);
    func_02062ef8(1);
    data_021653e8 = 72;
    func_02061944(72, 1);
    data_0217aa4c = 0;
    data_0217aa64 = 1;
    data_0217aa2c = 0;
    data_0217aa70 = 0;
    data_0217aa28 = data_0217aa30;
    data_0217aa68 = data_0217aa60;
}

void func_02061860(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217aa2c;
    value1 = 0u;
    *(u16 *) ((value0) + (0)) = (u16) value1;
}

void func_0206184c(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217aa2c;
    value1 = 0x48u;
    *(u16 *) ((value0) + (0)) = (u16) value1;
}

u32 func_0206183c(void) {
    return ((u32) data_0217aa64);
}

Unk02012f58 *func_0206182c(void) {
    return data_0217aa7c;
}

u32 func_02061818(void) {
    return ((u32) data_0217aa6c->mUnk_250);
}

void *func_02061808(void) {
    return (void *) ((u32) data_0217aa6c);
}

u32 func_020617f0(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217aa54;
    value1 = 1u;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    *(u32 *) ((value0) + (52)) = value1;
    return value0;
}

u32 func_020617d8(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217aa54;
    value1 = (u32) * (const u32 *) ((value0) + (0));
    value0 = (u32) * (const u32 *) ((value1) + (4));
    *(u32 *) ((value1) + (60)) = value0;
    return value0;
}

s32 func_020617a8(u32 *a) {
    Unk0217aa54 *b;
    BOOL c;

    b = data_0217aa54;
    c = FALSE;
    if (b->mUnk_3c != 0) {
        c = TRUE;
        *a = b->mUnk_04 - b->mUnk_3c;
    }
    return c;
}

s32 func_02061788(void) {
    if (data_021759c0->mMode == 4) {
        return 0x2e;
    }
    return 0x1f;
}

u16 func_02061768(void) {
    if (data_021759c0->mMode == 4) {
        return 0x2d;
    }
    return 0x1e;
}

BOOL func_0206174c(void *v) {
    Unk0217aa08_14 *a = v;

    if (a->mUnk_08_0 == 1) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_02061704(void *v, Unk02056bc0 *b) {
    Unk0217aa08_14 *a = v;

    if (a->mUnk_08_0 != 1) {
        return FALSE;
    }
    b->mUnk_02 = a->mUnk_08_8;
    b->mUnk_03 = a->mUnk_08_15;
    b->mUnk_00 = a->mUnk_08_22;
    return TRUE;
}

BOOL func_020616c0(void *v, void *b) {
    Unk0217aa08_14 *a = v;

    if (a->mUnk_08_0 != 1) {
        return FALSE;
    }
    MemCopy(a->mUnk_0c, b, 0x14);
    return TRUE;
}

s32 func_0206169c(void *v) {
    Unk0217aa08_14 *a = v;

    if (a->mUnk_08_0 != 1) {
        return -1;
    }
    return a->mUnk_04_0;
}

s32 func_02061678(void *v) {
    Unk0217aa08_14 *a = v;

    if (a->mUnk_08_0 != 1) {
        return -1;
    }
    return a->mUnk_04_4;
}

u32 func_02061654(void *v) {
    Unk0217aa08_14 *a = v;

    if (a->mUnk_08_0 != 1) {
        return 0;
    }
    return a->mUnk_04_10;
}
