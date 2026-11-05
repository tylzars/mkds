#include "Main/Unknown/code_020f1a38.h"
#include "Main/Unknown/code_02036820.h"

#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020f1d40.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217c000.h"

#pragma thumb on

void CreateItemKinds(void) {
    ItemKind *p;
    enum { K0 } i;
    enum { K1 } j;
    s32 m;
    u32 v;

    p = HeapAlloc(GetHeap(func_020364e8()), 0x930);
    gItemKinds = p;
    p[0] = gItemKindKouraG;
    p[1] = gItemKindKouraR;
    p[2] = gItemKindBanana;
    p[3] = gItemKindKinoko;
    p[4] = gItemKindStar;
    p[5] = gItemKindKouraW;
    p[6] = gItemKindThunder;
    p[7] = gItemKindFBox;
    p[8] = data_0215a4dc;
    p[9] = gItemKindBomb;
    p[10] = gItemKindGesso;
    p[11] = gItemKindTeresa;
    p[12] = gItemKindKinokoP;
    p[13] = gItemKindKiller;
    for (i = 0; i < 0xe; i++) {
        gItemKinds[i].mUnk_4c = func_020f1d40(i);
        v = gItemKinds[i].mUnk_58;
        if (v != 0) {
            v = ((u32(*)(void)) v)();
        } else {
            v = data_0217ca6c[1].mUnk_20;
        }
        gItemKinds[i].mUnk_a4 = v;
    }
    m = data_021759c0->mMode;
    switch (m) {
        case MODE_BATTLE:
            gItemKinds[8].mLimit = 8;
            break;
        case MODE_MISSION_RUN:
            for (j = 0; j < 0xe; j++) {
                gItemKinds[j].mLimit = gItemKinds[j].mUnk_08;
            }
            break;
        case 5:
            gItemKinds[3].mLimit = 0x20;
            break;
    }
}

void ComputeItemKindObjectCounts(void) {
    s32 a[14];
    enum { K0 } i;
    enum { K1 } j;
    s32 n;

    for (i = 0; i < 0xe; i++) {
        gItemKinds[i].mUnk_10 = gItemKinds[i].mLimit - 1;
        a[i] = 1;
    }
    for (j = 0; j < 0x12; j++) {
        if (gItemInfos[j].mEnabled != FALSE) {
            i = gItemInfos[j].mObjectKind;
            n = gItemInfos[j].mObjectCount;
            if (a[i] < n) {
                a[i] = n;
            }
        }
    }
    for (i = 0; i < 0xe; i++) {
        gItemKinds[i].mUnk_10 = gItemKinds[i].mUnk_10 + a[i];
        gItemKinds[i].mObjectCount = gItemKinds[i].mUnk_10;
    }
    if (data_021759c0->mMode == 5) {
        for (i = 0; i < 0xe; i++) {
            gItemKinds[i].mObjectCount = gItemKinds[i].mObjectCount + 3;
        }
    } else {
        gItemKinds[2].mObjectCount = gItemKinds[2].mObjectCount + 0x10;
    }
}

#pragma thumb off
