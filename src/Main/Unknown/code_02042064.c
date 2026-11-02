#include "Main/Unknown/code_02042064.h"
#include "Main/Unknown/unk_021759c0.h"

#include "Main/Unknown/code_02042fd8.h"
#include "Main/Unknown/code_020429c8.h"
#include "Main/Unknown/code_020431bc.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_020472a8.h"
#include "code_02135014.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"

#pragma thumb on

Unk02175620_74 *func_020423fc(u32 a) {
    return &gCourseMap->mUnk_74[a];
}

#pragma thumb off

#pragma thumb on
void func_0204236c(void) {
    void *h;
    Unk02175620_74 *e;
    Unk02175620_d8 **q;
    u16 i;
    u16 j;

    h = func_020364e0(func_020364e8());
    i = 0;
    for (j = 0; j < 8; j++) {
        gCourseMap->mUnk_d8[j] = NULL;
    }
    for (i = 0; i < gCourseMap->mUnk_78; i++) {
        e = func_020423fc(i);
        if (e->mUnk_44 == 3) {
            q = &gCourseMap->mUnk_d8[(s16) e->mUnk_3c];
            while (*q != NULL) {
                q = &(*q)->mUnk_04;
            }
            *q = func_02036bec(h, 8);
            (*q)->mUnk_00 = e;
            (*q)->mUnk_04 = NULL;
        }
    }
}
#pragma thumb off

#pragma thumb on

void func_02042320(void) {
    u16 count;
    u16 i;
    count = 0;
    for (i = 0; i < gCourseMap->mUnk_78; i++) {
        if (func_020423fc(i)->mUnk_44 == 4) {
            count++;
        }
    }
    gCourseMap->mUnk_102 = count;
}

void func_020422c4(void) {
    u8 count;
    u16 i;
    count = 0;
    if (data_021759c0->mUnk_08 == 4) {
        for (i = 0; i < gCourseMap->mUnk_78; i++) {
            if (func_020423fc(i)->mUnk_44 == 2) {
                count++;
            }
        }
    }
    gCourseMap->mUnk_10f = count;
}

#pragma thumb off

#pragma thumb on
s32 func_02042280(void *a, ...) {
    gCourseMap->mUnk_78 = func_020431a4(&a);
    if (gCourseMap->mUnk_78 == 0) {
        gCourseMap->mUnk_74 = NULL;
    } else {
        gCourseMap->mUnk_74 = a;
    }
    func_0204236c();
    func_02042320();
    func_020422c4();
    return 1;
}

s32 func_02042170(void *a, ...) {
    u16 i;
    Unk02175620_7c *e;

    gCourseMap->mUnk_80 = func_020431a4(&a);
    if (gCourseMap->mUnk_80 == 0) {
        gCourseMap->mUnk_7c = NULL;
        return 1;
    }
    gCourseMap->mUnk_7c = a;
    gCourseMap->mUnk_c4 = NULL;
    gCourseMap->mUnk_c8 = NULL;
    gCourseMap->mUnk_cc = NULL;
    gCourseMap->mUnk_d0 = NULL;
    for (i = 0; i < gCourseMap->mUnk_80; i++) {
        e = gCourseMap->mUnk_7c + i;
        if (gCourseMap->mUnk_c4 == NULL && e->mUnk_4a == 1) {
            gCourseMap->mUnk_c4 = e;
        }
        if (gCourseMap->mUnk_c8 == NULL && e->mUnk_4a == 2) {
            gCourseMap->mUnk_c8 = e;
        }
        if (gCourseMap->mUnk_cc == NULL && e->mUnk_3e == 6) {
            gCourseMap->mUnk_cc = e;
        }
        if (data_021759c0->mUnk_08 == 2 && gCourseMap->mUnk_d0 == NULL && e->mUnk_3e == 7) {
            gCourseMap->mUnk_d0 = e;
        }
        if (data_021759c0->mUnk_08 == 4 && gCourseMap->mUnk_d4 == NULL && e->mUnk_3e == 8) {
            gCourseMap->mUnk_d4 = e;
        }
    }
    return 1;
}

void CreateCourseMap(void *a) {
    char path[0x100];
    Unk02042064 *header;
    Unk02175620 *courseMap;
    s32 *offset;
    u8 *base;
    s32 i;
    u16 j;

    switch (data_021759c0->mUnk_08) {
        case 4:
            if (data_021759c0->mUnk_00c == 6) {
                header = FindCourseFile("/course_map.nkm");
            } else {
                snprintf(path, 0x100, "/MissionRun/%s_tool.nkm", data_021759c0->mUnk_048);
                header = FindCourseFile(path);
            }
            break;
        case 5:
            header = FindCourseFile("/Net/net_course_map.nkm");
            if (header == NULL) {
                header = FindCourseFile("/course_map.nkm");
            }
            break;
        default:
            header = FindCourseFile("/course_map.nkm");
            break;
    }
    courseMap = func_020431bc((u32) a);
    gCourseMap = courseMap;
    courseMap->mUnk_10c = header->mUnk_04;
    offset = header->mSectionOffsets;
    base = (u8 *) header + header->mBaseOffset;
    for (i = 0; i < 17; i++) {
        if (data_usa_0215407c[i](base + *offset) != 0) {
            offset++;
        }
    }
    func_02042fd8(a);
    func_020429c8(a);
    gCourseMap->mUnk_9c = 0;
    for (j = 0; j < gCourseMap->mUnk_50; j++) {
        if (gCourseMap->mUnk_4c[j].mUnk_0a > gCourseMap->mUnk_9c) {
            gCourseMap->mUnk_9c = gCourseMap->mUnk_4c[j].mUnk_0a;
        }
    }
}
#pragma thumb off
