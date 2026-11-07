#include "Main/Unknown/code_020cefc0.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c0b84.h"

#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020fd264.h"
#include "Main/Unknown/code_020cf2fc.h"

void func_020cf2fc(void) {
    u32 value0;
    u32 value12;
    value0 = (u32) &data_0217b48c;
    ClearRaceHudSubScreenCells((RaceHudSubScreenCells **) value0);
}

void func_020cefdc(void) {
    s32 i;
    s32 n;
    s32 v;
    s32 m;
    s32 x;
    s32 y;
    ItemPool *q;
    ItemObject **b;
    ItemObject *e;
    Vec3 *p;
    s32 x2;
    s32 y2;
    ItemObject *e2;
    Vec3 *p2;

    n = 0;
    v = func_020c0db0();
    q = &gItemPools[9];
    m = q->mActiveCount;
    b = q->mObjects;
    for (i = 0; i < m; i++) {
        e = b[i];
        if (IsItemBombState2((Kart *) e) != FALSE) {
            p = func_020fd308((ItemBomb *) e, &x, &y);
            if (ComputeRaceHudSubScreenPosition(p, &data_0217b48c->mCells[n].mUnk_00, v, 1, 1) != FALSE) {
                data_0217b48c->mCells[n].mUnk_08 = GetRaceSNcerEntry(0x63);
                data_0217b48c->mCells[n].mUnk_0c = func_020b4e70(p) != 0 ? 2 : 3;
                data_0217b48c->mCells[n].mUnk_10 = x;
                data_0217b48c->mCells[n].mUnk_0e = x >= 0x16 ? 1 : 0;
                if (x >= 0x16) {
                    y = InterpolateS16(1, 0x1000, 10, x - 0x16, 0x22);
                }
                data_0217b48c->mUnk_0c[n].mUnk_00 = y;
                n++;
            }
        }
    }
    q = &gItemPools[5];
    m = q->mActiveCount;
    b = q->mObjects;
    for (i = 0; i < m; i++) {
        e2 = b[i];
        if (IsItemKouraWState7((ItemKouraW *) e2) != FALSE) {
            p2 = func_020fad9c((ItemKouraW *) e2, &x2, &y2);
            if (ComputeRaceHudSubScreenPosition(p2, &data_0217b48c->mCells[n].mUnk_00, v, 1, 1) != FALSE) {
                data_0217b48c->mCells[n].mUnk_08 = GetRaceSNcerEntry(0x64);
                data_0217b48c->mCells[n].mUnk_0c = func_020b4e70(p2) != 0 ? 2 : 3;
                data_0217b48c->mCells[n].mUnk_10 = x2;
                data_0217b48c->mCells[n].mUnk_0e = x2 >= 0x16 ? 1 : 0;
                if (x2 >= 0x16) {
                    y2 = InterpolateS16(1, 0x1000, 10, x2 - 0x16, 0x22);
                }
                data_0217b48c->mUnk_0c[n].mUnk_00 = y2;
                n++;
            }
        }
    }
    data_0217b48c->mCellCount = n;
}

void func_020cefc0(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCellsScaled(a, data_0217b48c, 0);
}
