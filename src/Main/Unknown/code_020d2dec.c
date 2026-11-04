#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02059bc0.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020d2dec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d3ae0.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020d4a10.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020d7db4.h"
#include "Main/Unknown/code_020e01f0.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02103598.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_020e3b28.h"
#include "Main/Unknown/code_020e3618.h"
#include "Main/Unknown/code_020ff344.h"
#include "Main/Unknown/code_020e662c.h"
#include "Main/Unknown/code_020e6f58.h"
#include "Main/Unknown/code_020d49e0.h"
#include "Main/Unknown/code_020d4a18.h"
#include "Main/Unknown/code_020e6f9c.h"
#include "Main/Unknown/code_020e6fc4.h"
#include "Main/Unknown/code_020d4bf0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_020d6000.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_02059000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_020df890.h"
#include "Main/Unknown/code_020d94dc.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

static inline GrpconfTblRow *func_020d34e4_inline(u16 f) {
    s32 j;
    for (j = 0; j < 1000; j++) {
        if (f == gGrpconfTbl[j].mUnk_00) {
            return &gGrpconfTbl[j];
        }
    }
    return NULL;
}

MapObject *CreateMapObject(u32 kind, Unk020fa294 *courseRow, MapObject *source) {
    s32 i;
    s32 j;
    MapObjectKindRow *row;
    Unk021000d0 *a;
    Unk021000d0 *o;
    MapObjectKindData *kindData;
    GrpconfTblRow *t;
    MapObject *object;
    s32 v;
    u32 m;
    for (i = 0; i < data_0217b4ec; i++) {
        {
            row = &data_0216b288[i];
            if (kind != row->mKind) {
                continue;
            }
            a = row->mUnk_04;
            if (a->mObjectCount == 0) {
                for (j = 0; j < data_0217b4ec; j++) {
                    o = data_0216b288[j].mUnk_04;
                    if (o == NULL) {
                        continue;
                    }
                    if (o->mUnk_10 == a->mUnk_10 && o->mUnk_24[0] != NULL) {
                        a->mUnk_24[0] = o->mUnk_24[0];
                    }
                    if (o->mUnk_10 == a->mUnk_14 && o->mUnk_24[0] != NULL) {
                        a->mUnk_24[1] = o->mUnk_24[0];
                    }
                    if (o->mUnk_10 == a->mUnk_18 && o->mUnk_24[0] != NULL) {
                        a->mUnk_24[2] = o->mUnk_24[0];
                    }
                    if (o->mUnk_14 == a->mUnk_10 && o->mUnk_24[1] != NULL) {
                        a->mUnk_24[0] = o->mUnk_24[1];
                    }
                    if (o->mUnk_14 == a->mUnk_14 && o->mUnk_24[1] != NULL) {
                        a->mUnk_24[1] = o->mUnk_24[1];
                    }
                    if (o->mUnk_14 == a->mUnk_18 && o->mUnk_24[1] != NULL) {
                        a->mUnk_24[2] = o->mUnk_24[1];
                    }
                    if (o->mUnk_18 == a->mUnk_10 && o->mUnk_24[2] != NULL) {
                        a->mUnk_24[0] = o->mUnk_24[2];
                    }
                    if (o->mUnk_18 == a->mUnk_14 && o->mUnk_24[2] != NULL) {
                        a->mUnk_24[1] = o->mUnk_24[2];
                    }
                    if (o->mUnk_18 == a->mUnk_18 && o->mUnk_24[2] != NULL) {
                        a->mUnk_24[2] = o->mUnk_24[2];
                    }
                    if (o->mUnk_1c == a->mUnk_1c && o->mUnk_24[3] != NULL) {
                        a->mUnk_24[3] = o->mUnk_24[3];
                    }
                }
                if (a->mKindData == NULL && a->mCreateKindData != NULL) {
                    a->mKindData = a->mCreateKindData();
                    if (a->mKindData == NULL) {
                        return NULL;
                    }
                    if (a->mKindData->mUnk_24 == 0) {
                        a->mKindData->mUnk_24 = -1;
                    }
                    if (a->mKindData->mUnk_28 == 0) {
                        a->mKindData->mUnk_28 = -1;
                    }
                    if (a->mKindData->mUnk_38 == 0) {
                        a->mKindData->mUnk_38 = 0x64000;
                    }
                    if (a->mKindData->mUnk_3c == 0) {
                        a->mKindData->mUnk_3c = -0x64000;
                    }
                    if (data_021759c0->mUnk_00c == 2) {
                        if (a->mKindData->mUnk_38 < 0x44c000) {
                            a->mKindData->mUnk_38 = 0x44c000;
                        }
                    }
                }
                t = func_020d34e4_inline(row->mKind);
                if (t->mUnk_02 != 0) {
                    a->mKindData->mUnk_34 = t->mUnk_02 >= 2 ? 1 : 0;
                    v = t->mUnk_04;
                    a->mKindData->mUnk_2c = (s32) (v != 0 ? (float) (v << 12) + 0.5f : (float) (v << 12) - 0.5f);
                    v = t->mUnk_06;
                    a->mKindData->mUnk_30 = (s32) (v != 0 ? (float) (v << 12) + 0.5f : (float) (v << 12) - 0.5f);
                }
                if (t->mUnk_08 != 0) {
                    a->mKindData->mUnk_08 = t->mUnk_08;
                    v = t->mUnk_0a;
                    a->mKindData->mUnk_0c = (s32) (v != 0 ? (float) (v << 12) + 0.5f : (float) (v << 12) - 0.5f);
                    v = t->mUnk_0c;
                    a->mKindData->mUnk_10 = (s32) (v != 0 ? (float) (v << 12) + 0.5f : (float) (v << 12) - 0.5f);
                    v = t->mUnk_0e;
                    a->mKindData->mUnk_14 = (s32) (v != 0 ? (float) (v << 12) + 0.5f : (float) (v << 12) - 0.5f);
                }
                if (a->mUnk_24[0] == NULL && a->mUnk_10 != NULL) {
                    a->mUnk_24[0] = a->mUnk_10();
                }
                if (a->mUnk_24[1] == NULL && a->mUnk_14 != NULL) {
                    a->mUnk_24[1] = a->mUnk_14();
                }
                if (a->mUnk_24[2] == NULL && a->mUnk_18 != NULL) {
                    a->mUnk_24[2] = a->mUnk_18();
                }
                if (a->mUnk_24[3] == NULL && a->mUnk_1c != NULL) {
                    a->mUnk_24[3] = a->mUnk_1c();
                }
            }
            if (a == NULL) {
                continue;
            }
            kindData = a->mKindData;
            object = HeapAlloc(GetHeap(func_020364e8()), a->mObjectSize);
            a->mObjectCount++;
            if (courseRow != NULL) {
                object->mCourseMapRow = courseRow;
            } else if (source != NULL) {
                object->mCourseMapRow = source->mCourseMapRow;
            }
            object->mKind = kind;
            object->mFlags = 0;
            if (data_0217b4e0 != 0) {
                object->mFlags |= data_021568c8;
            }
            object->mUnk_64 = -1;
            if (courseRow != NULL) {
                object->mPos.x = courseRow->mUnk_00.x;
                object->mPos.y = courseRow->mUnk_00.y;
                object->mPos.z = courseRow->mUnk_00.z;
            } else if (source != NULL) {
                object->mPos.x = source->mPos.x;
                object->mPos.y = source->mPos.y;
                object->mPos.z = source->mPos.z;
            }
            if (kindData->mUnk_20 == 0 || kindData->mUnk_20 == 2) {
                object->mUnk_10.x = 0;
                object->mUnk_10.y = 0;
                object->mUnk_10.z = 0;
            } else {
                object->mUnk_10.x = 0x270f000;
                object->mUnk_10.y = 0x270f000;
                object->mUnk_10.z = 0x270f000;
            }
            if (courseRow != NULL) {
                object->mAngle = (u16) (((s64) courseRow->mUnk_0c.y * 0xb60b60b60bLL + 0x80000000000LL) >> 44);
                func_020d6df0(&courseRow->mUnk_0c, (s32 *) &object->mMatrix);
            } else if (source != NULL) {
                object->mAngle = source->mAngle;
                object->mMatrix = source->mMatrix;
            }
            object->mKindData = kindData;
            if (courseRow != NULL) {
                SetMapObjectScale(object, &courseRow->mUnk_18);
            } else {
                SetMapObjectScale(object, &source->mScale);
            }
            func_020d24d8(object, kindData->mUnk_30);
            object->mUnk_7c = kindData->mUnk_34;
            if (kindData->mUnk_08 != 0) {
                object->mFlags &= ~1;
            } else {
                object->mFlags |= data_021568cc;
            }
            if (kindData->mUnk_1c != 0) {
                object->mFlags &= ~0x40;
            } else {
                object->mFlags |= data_021568d0;
            }
            if ((a->mUnk_24[0] != NULL && a->mUnk_24[0]->mUnk_10 != NULL) ||
                (a->mUnk_24[1] != NULL && a->mUnk_24[1]->mUnk_10 != NULL) ||
                (a->mUnk_24[2] != NULL && a->mUnk_24[2]->mUnk_10 != NULL)) {
                object->mFlags &= ~2;
                object->mFlags &= ~8;
                object->mUnk_66 = 0x1f;
            } else {
                object->mFlags |= data_021568d4;
                object->mFlags |= data_021568d8;
            }
            if (source != NULL) {
                object->mUnk_74 = source->mUnk_74;
                object->mFlags |= source->mFlags & 0x80;
            } else if (courseRow != NULL) {
                if (courseRow->mUnk_36 != 0) {
                    func_020d3ae0(courseRow->mUnk_36, object);
                }
            }
            if (a->mUnk_24[3] != NULL && a->mUnk_24[3]->mUnk_10 != NULL) {
                object->mFlags &= ~4;
            } else {
                object->mFlags |= data_021568dc;
            }
            object->mUnk_70 = data_0217ca6c[2].mUnk_20;
            if (courseRow != NULL) {
                if (a->mInitObject != NULL) {
                    a->mInitObject(object, courseRow, data_0216b288[i].mUnk_08);
                }
            } else if (source != NULL) {
                if (a->mInitObject != NULL) {
                    a->mInitObject(object, NULL, source);
                }
            }
            if (kindData->mUnk_08 != 0) {
                m = 0x2000;
                if (kindData->mUnk_20 == 0) {
                    m |= data_021568e0;
                }
                if (func_020dff70(object->mKind) != 0 || func_020e4320(object->mKind) != 0 ||
                    func_020e3af0(object->mKind) != 0 || func_020ffabc(object->mKind) != 0) {
                    m |= data_021568e4;
                }
                object->mUnk_64 = func_020d555c(&object->mPos, func_020d252c(object), m, object);
            }
            j = data_0217b4f0->mMapObjectCount;
            data_0217b4f0->mMapObjectCount = j + 1;
            data_0217b4f0->mMapObjects[j] = object;
            if (data_0217b4f0->mMapObjectCount >= 0x100) {
                data_0217b4f0->mMapObjectCount = 0xff;
            }
            return object;
        }
    }
    return NULL;
}

MapObject *CreateMapObjectFromObject(MapObject *source, s32 kind) {
    return CreateMapObject(kind, NULL, source);
}

MapObject *CreateMapObjectFromCourseMapRow(Unk020fa294 *courseRow, s32 kind) {
    return CreateMapObject(kind, courseRow, NULL);
}

void InitMapObjects(void) {
    void *h;
    s32 i;
    s32 n;
    s32 j;
    s32 m;
    s32 c1;
    s32 c2;
    s32 s1;
    s32 s2;
    s32 k;
    s32 t;
    s32 g;
    u32 v;
    MapObjectKindRow *row;
    Unk021000d0 *d;
    Unk020fa294 *e;
    MapObject *o;
    Unk020e6fd4 *w[3];
    Unk020e6fd4 *x;
    Unk020e6fd4 **y;
    Unk0217b4f0 *q;
    h = GetHeap(func_020364e8());
    func_020d22e0();
    data_0217b4cc = func_02061788();
    data_0217b4c0 = data_0217b4cc + 9;
    data_0217b4c8 = data_0217b4c0 + 1;
    n = gCourseMap->mUnk_04;
    data_0217b4f0 = HeapAlloc(h, 0x2bc);
    data_0217b4f0->mMapObjects = HeapAlloc(h, 0x400);
    data_0217b4e8 = HeapAlloc(h, 0x80);
    data_0217b4dc = HeapAlloc(h, 0x180);
    data_0217b4f0->mMapObjectCount = 0;
    data_0217b4f0->mUnk_130 = 0;
    data_0217b4f0->mUnk_178 = 0;
    v = 0;
    if (data_021759c0->mMode != 5) {
        v = 1;
    }
    data_0217b4f0->mUnk_2b8 = v;
    data_0217b4ec = 0;
    do {
        row = &data_0216b288[data_0217b4ec];
        d = row->mUnk_04;
        if (row->mKind == 0) {
            break;
        }
        if (data_0217aa10->mUnk_00 != 1 && func_02059c04(d) != 0) {
            break;
        }
        if (d != NULL) {
            d->mKindData = NULL;
            d->mUnk_24[0] = NULL;
            d->mUnk_24[1] = NULL;
            d->mUnk_24[2] = NULL;
            d->mUnk_24[3] = NULL;
        }
        data_0217b4ec++;
    } while (data_0217b4ec < 0x85);
    gGrpconfTbl = FindMainRaceOrMainEffectFile("MapObj/grpconf.tbl");
    v = 1;
    if (data_021759c0->mMode != 1 && data_021759c0->mMode != 5) {
        v = 0;
    }
    data_0217b4e0 = v;
    data_0217b4f0->mUnk_17c = 0;
    data_0217b4f0->mUnk_180 = 0;
    data_0217b4f0->mUnk_184 = 0;
    data_0217b4f0->mUnk_188 = 0;
    data_0217b4e4 = NULL;
    data_0217b4d8 = NULL;
    func_02103598();
    func_020d7df8();
    func_020e662c();
    func_020d4bf0();
    data_0217b4c4 = data_0217b4c8;
    data_0217b4d0 = data_0217b4cc;
    for (i = 0; i < data_0217b4ec; i++) {
        if (data_0216b288[i].mUnk_04 != NULL) {
            data_0216b288[i].mUnk_04->mObjectCount = 0;
        }
    }
    for (i = 0; i < n; i++) {
        e = (Unk020fa294 *) ((u8 *) gCourseMap->mUnk_00 + i * sizeof(Unk020fa294));
        if (data_021759c0->mMode == 1 && (e->mUnk_38 & 1) == 0) {
            continue;
        }
        CreateMapObject(e->mUnk_24, e, NULL);
        data_0217b4f0->mUnk_17c |= func_020dff70(e->mUnk_24);
        data_0217b4f0->mUnk_180 |= func_020e4320(e->mUnk_24);
        data_0217b4f0->mUnk_184 |= func_020e3af0(e->mUnk_24);
        data_0217b4f0->mUnk_188 |= func_020ffabc(e->mUnk_24);
    }
    if (data_0217b4f0->mUnk_17c != 0 || data_0217b4f0->mUnk_180 != 0 || data_0217b4f0->mUnk_184 != 0 ||
        data_0217b4f0->mUnk_188 != 0) {
        data_0217b610 = 1;
    }
    func_02105214();
    data_0217b4f0->mUnk_128 = 0;
    for (m = 0; m < 24; m++) {
        data_0217b4f0->mUnk_008[m] = NULL;
    }
    for (i = 0; i < data_0217b4ec; i++) {
        if (data_0216b288[i].mUnk_04 == NULL) {
            continue;
        }
        v = data_0216b288[i].mUnk_04->mObjectCount;
        w[0] = data_0216b288[i].mUnk_04->mUnk_24[0];
        w[1] = data_0216b288[i].mUnk_04->mUnk_24[1];
        w[2] = data_0216b288[i].mUnk_04->mUnk_24[2];
        for (j = 0; j < 3; j++) {
            s32 g;
            if (w[j] == NULL) {
                continue;
            }
            g = 1;
            for (m = 0; m < data_0217b4f0->mUnk_128; m++) {
                if (data_0217b4f0->mUnk_008[m] == w[j]) {
                    func_020d4a10(w[j], v);
                    g = 0;
                }
            }
            if (g != 0) {
                func_020d4a18(w[j]);
                if (v != 0) {
                    func_020d4a10(w[j], v);
                    data_0217b4f0->mUnk_008[data_0217b4f0->mUnk_128++] = w[j];
                }
            }
        }
    }
    for (i = 0; i < data_0217b4f0->mUnk_128; i++) {
        func_020d49f0(data_0217b4f0->mUnk_008[i]);
    }
    for (i = 0; i < data_0217b4f0->mMapObjectCount; i++) {
        o = data_0217b4f0->mMapObjects[i];
        for (j = 0; j < data_0217b4ec; j++) {
            if (o->mKind == data_0216b288[j].mKind) {
                w[0] = data_0216b288[j].mUnk_04->mUnk_24[0];
                w[1] = data_0216b288[j].mUnk_04->mUnk_24[1];
                w[2] = data_0216b288[j].mUnk_04->mUnk_24[2];
                if (w[0] != NULL) {
                    func_020d49e0(w[0], o);
                }
                if (w[1] != NULL) {
                    func_020d49e0(w[1], o);
                }
                if (w[2] != NULL) {
                    func_020d49e0(w[2], o);
                }
            }
        }
    }
    for (i = 0; i < data_0217b4f0->mUnk_128; i++) {
        func_020d4990(data_0217b4f0->mUnk_008[i]);
    }
    data_0217b4f0->mUnk_130 = 1;
    func_020d2e24();
    n = data_0217b4f0->mUnk_128;
    c1 = 0;
    c2 = 0;
    s1 = 0;
    s2 = 0;
    for (t = 0; t < n; t++) {
        x = data_0217b4f0->mUnk_008[t];
        if (x->mUnk_20 != 0) {
            if (x->mUnk_18 == 1) {
                c1++;
            } else if (x->mUnk_18 == 2) {
                c2++;
            }
        }
    }
    m = 0;
    for (i = 0; i < n; i++) {
        x = data_0217b4f0->mUnk_008[i];
        if (x->mUnk_18 == 1) {
            y = data_0217b4f0->mUnk_068;
            data_0217b4f0->mUnk_12a++;
            if (x->mUnk_20 != 0) {
                k = s1++;
            } else {
                k = c1++;
            }
        } else if (x->mUnk_18 == 2) {
            y = data_0217b4f0->mUnk_0c8;
            data_0217b4f0->mUnk_12c++;
            if (x->mUnk_20 != 0) {
                k = s2++;
            } else {
                k = c2++;
            }
        }
        y[k] = x;
    }
    data_0217b4f0->mUnk_174 = 0;
    for (i = 0; i < 16; i++) {
        data_0217b4f0->mUnk_134[i] = NULL;
    }
    for (i = 0; i < data_0217b4ec; i++) {
        if (data_0216b288[i].mUnk_04 == NULL) {
            continue;
        }
        v = data_0216b288[i].mUnk_04->mObjectCount;
        x = data_0216b288[i].mUnk_04->mUnk_24[3];
        if (x == NULL) {
            continue;
        }
        g = 1;
        for (j = 0; j < data_0217b4f0->mUnk_174; j++) {
            if (data_0217b4f0->mUnk_134[j] == x) {
                func_020e6fc4(x, v);
                g = 0;
            }
        }
        if (g != 0) {
            func_020e6fcc(x);
            if (v != 0) {
                func_020e6fc4(x, v);
                data_0217b4f0->mUnk_134[data_0217b4f0->mUnk_174++] = x;
            }
        }
    }
    for (i = 0; i < data_0217b4f0->mUnk_174; i++) {
        func_020e6f9c(data_0217b4f0->mUnk_134[i]);
    }
    for (i = 0; i < data_0217b4f0->mMapObjectCount; i++) {
        o = data_0217b4f0->mMapObjects[i];
        for (j = 0; j < data_0217b4ec; j++) {
            if (o->mKind == data_0216b288[j].mKind && data_0216b288[j].mUnk_04->mUnk_24[3] != NULL) {
                func_020e6f58(data_0216b288[j].mUnk_04->mUnk_24[3], o);
            }
        }
    }
    data_0217b4f0->mUnk_178 = 1;
    func_020d2dec();
}

void func_020d2e24(void) {
    s32 i;
    s32 n;
    Unk020e6fd4 **p;
    n = data_0217b4f0->mUnk_128;
    p = data_0217b4f0->mUnk_008;
    if (data_0217b4e4 != NULL) {
        func_020d9900(data_0217b4e4);
    }
    func_020e52bc();
    for (i = 0; i < n; p++, i++) {
        if ((*p)->mUnk_08 != NULL) {
            (*p)->mUnk_08(*p);
        }
    }
}

void func_020d2dec(void) {
    s32 i;
    s32 n;
    Unk020e6fd4 **p;
    n = data_0217b4f0->mUnk_174;
    p = data_0217b4f0->mUnk_134;
    for (i = 0; i < n; p++, i++) {
        if ((*p)->mUnk_08 != NULL) {
            (*p)->mUnk_08(*p);
        }
    }
}

#pragma thumb off
