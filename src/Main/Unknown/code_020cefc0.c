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

void ClearRaceHudSubScreenBombKouraWCells(void) {
    u32 address;
    u32 unused;
    address = (u32) &gRaceHudSubScreenBombKouraWCells;
    ClearRaceHudSubScreenCells((RaceHudSubScreenCells **) address);
}

void UpdateRaceHudSubScreenBombKouraWCells(void) {
    s32 i;
    s32 cellCount;
    s32 v;
    s32 activeCount;
    s32 bombStateFrames;
    s32 y;
    ItemPool *pool;
    ItemObject **objects;
    ItemObject *bomb;
    Vec3 *bombPosition;
    s32 kouraStateFrames;
    s32 y2;
    ItemObject *kouraW;
    Vec3 *kouraPosition;

    cellCount = 0;
    v = func_020c0db0();
    pool = &gItemPools[9];
    activeCount = pool->mActiveCount;
    objects = pool->mObjects;
    for (i = 0; i < activeCount; i++) {
        bomb = objects[i];
        if (IsItemBombState2(bomb) != FALSE) {
            bombPosition = func_020fd308((ItemBomb *) bomb, &bombStateFrames, &y);
            if (ComputeRaceHudSubScreenPosition(
                    bombPosition, &gRaceHudSubScreenBombKouraWCells->mCells[cellCount].mDrawPos, v, 1, 1) != FALSE) {
                gRaceHudSubScreenBombKouraWCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x63);
                gRaceHudSubScreenBombKouraWCells->mCells[cellCount].mUnk_0c = func_020b4e70(bombPosition) != 0 ? 2 : 3;
                gRaceHudSubScreenBombKouraWCells->mCells[cellCount].mUnk_10 = bombStateFrames;
                gRaceHudSubScreenBombKouraWCells->mCells[cellCount].mUnk_0e = bombStateFrames >= 0x16 ? 1 : 0;
                if (bombStateFrames >= 0x16) {
                    y = InterpolateS16(1, 0x1000, 10, bombStateFrames - 0x16, 0x22);
                }
                gRaceHudSubScreenBombKouraWCells->mUnk_0c[cellCount].mUnk_00 = y;
                cellCount++;
            }
        }
    }
    pool = &gItemPools[5];
    activeCount = pool->mActiveCount;
    objects = pool->mObjects;
    for (i = 0; i < activeCount; i++) {
        kouraW = objects[i];
        if (IsItemKouraWState7((ItemKouraW *) kouraW) != FALSE) {
            kouraPosition = GetItemKouraWState7Info((ItemKouraW *) kouraW, &kouraStateFrames, &y2);
            if (ComputeRaceHudSubScreenPosition(
                    kouraPosition, &gRaceHudSubScreenBombKouraWCells->mCells[cellCount].mDrawPos, v, 1, 1) != FALSE) {
                gRaceHudSubScreenBombKouraWCells->mCells[cellCount].mCell = GetRaceSNcerEntry(0x64);
                gRaceHudSubScreenBombKouraWCells->mCells[cellCount].mUnk_0c = func_020b4e70(kouraPosition) != 0 ? 2 : 3;
                gRaceHudSubScreenBombKouraWCells->mCells[cellCount].mUnk_10 = kouraStateFrames;
                gRaceHudSubScreenBombKouraWCells->mCells[cellCount].mUnk_0e = kouraStateFrames >= 0x16 ? 1 : 0;
                if (kouraStateFrames >= 0x16) {
                    y2 = InterpolateS16(1, 0x1000, 10, kouraStateFrames - 0x16, 0x22);
                }
                gRaceHudSubScreenBombKouraWCells->mUnk_0c[cellCount].mUnk_00 = y2;
                cellCount++;
            }
        }
    }
    gRaceHudSubScreenBombKouraWCells->mCellCount = cellCount;
}

void DrawRaceHudSubScreenBombKouraWCells(Unk020c06c4 *oamBuffer) {
    DrawRaceHudSubScreenCellsScaled(oamBuffer, gRaceHudSubScreenBombKouraWCells, 0);
}
