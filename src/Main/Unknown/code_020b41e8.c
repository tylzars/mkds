#include "Main/Unknown/code_020b41e8.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "00/code_02181f98.h"
#include "code_0214cfe4.h"
#include "code_02022aa8.h"

void InitFontIfLoaded(void *font, void *fontData) {
    if (fontData != NULL) {
        NNS_G2dFontInitAuto(font, fontData);
    }
}

void CopyCharsBlock(void *source, s32 sourceTileX, s32 sourceTileY, s32 tileWidth, s32 tileHeight, void *destination,
                    s32 destinationTileX, s32 destinationTileY) {
    s32 i;
    s32 j;

    for (i = 0; i < tileWidth; i++) {
        for (j = 0; j < tileHeight; j++) {
            MIi_CpuCopy16((u8 *) source + (sourceTileX + i) * 32 + (sourceTileY + j) * 1024,
                          (u8 *) destination + (destinationTileX + i) * 32 + (destinationTileY + j) * 1024, 0x20);
        }
    }
}

void CopyCharsBlockFlippedVertically(u16 *source, s32 sourceTileX, s32 sourceTileY, s32 tileWidth, s32 tileHeight,
                                     u16 *destination, s32 destinationTileX, s32 destinationTileY) {
    s32 i;
    s32 j;
    s32 k;
    s32 l;

    for (i = 0; i < tileWidth; i++) {
        for (j = 0; j < tileHeight; j++) {
            for (k = 0; k < 8; k++) {
                for (l = 0; l < 2; l++) {
                    (destination + (destinationTileX + i) * 16 +
                     (destinationTileY + (tileHeight - j - 1)) * 512)[(7 - k) * 2 + l] =
                        (source + (sourceTileX + i) * 16 + (sourceTileY + j) * 512)[k * 2 + l];
                }
            }
        }
    }
}

void CopyScreenMapBlock(u16 *source, s32 sourceColumn, s32 sourceRow, s32 columnCount, s32 rowCount, u16 *destination,
                        s32 destinationColumn, s32 destinationRow) {
    u16 *destinationMap;
    s32 j;
    s32 i;

    destinationMap = destination;
    for (i = 0; i < rowCount; i++) {
        for (j = 0; j < columnCount; j++) {
            destinationMap[(destinationColumn + j) + (destinationRow + i) * 32] =
                source[(sourceColumn + j) + (sourceRow + i) * 32];
        }
    }
}

void SetScreenMapBlockTopBits(u16 *screenMap, s32 column, s32 row, s32 columnCount, s32 rowCount, u16 topBits) {
    s32 i;
    s32 j;

    for (i = row; i < row + rowCount; i++) {
        for (j = column; j < column + columnCount; j++) {
            screenMap[i * 32 + j] = (topBits << 12) | (u16) (screenMap[i * 32 + j] & 0xfff);
        }
    }
}

void SetScreenMapBlockLowBits(u16 *screenMap, s32 column, s32 row, s32 columnCount, s32 rowCount, s32 lowBits) {
    s32 i;
    s32 j;

    for (i = row; i < row + rowCount; i++) {
        for (j = column; j < column + columnCount; j++) {
            screenMap[i * 32 + j] = lowBits | (u16) (screenMap[i * 32 + j] & 0xfc00);
        }
    }
}

static inline u16 *func_020b41e8_inline(u16 *chars, s32 firstTile, s32 tileIndex) {
    return chars + (firstTile + tileIndex % 4) * 16 + tileIndex / 4 * 512;
}

void CopyPlayerCharacterPaletteAndChars(u16 *paletteDestination, s32 paletteRow, u16 *charsDestination, s32 column,
                                        s32 row) {
    RaceSetup *raceSetup = gRaceSetup;
    Nclr *palette;
    Ncgr *chars;
    u16 *charsRightColumn;
    u16 *charsBlock;
    u16 *paletteColors;
    s32 characterIndex;
    s32 paletteCharacterIndex;
    s32 y;
    s32 j;
    s32 x;
    u16 entryIndex;
    u16 *charsBottomRow;
    s32 w;

    entryIndex = raceSetup->mRaceKind == RACE_KIND_DEMO ? raceSetup->mFollowedKartIndex : raceSetup->mEntryIndex;
    characterIndex = raceSetup->mCurrentEntries[entryIndex].mCharacterIndex;
    if (characterIndex == 12) {
        palette = GetPlayerCharacterShyguyNclr(1);
    } else {
        palette = GetPlayerCharacterNclr(1);
    }
    chars = GetPlayerCharacterNcgr(1);
    paletteColors = palette->mData;
    if (characterIndex == 12) {
        paletteCharacterIndex = data_0217b488->mShuffledIndices[(
            u16) (gRaceSetup->mRaceKind == RACE_KIND_DEMO ? gRaceSetup->mFollowedKartIndex : gRaceSetup->mEntryIndex)];
    } else {
        paletteCharacterIndex = characterIndex;
    }
    for (x = 0; x < 16; x++) {
        paletteDestination[paletteRow * 16 + x] = paletteColors[paletteCharacterIndex * 16 + x];
    }
    charsBlock = chars->mData;
    for (j = 0; j < 16; j++) {
        MIi_CpuCopy16(charsBlock + (characterIndex * 25 + j) * 16,
                      func_020b41e8_inline(charsDestination, column + row * 32, j), 0x20);
    }
    charsRightColumn = chars->mData;
    for (y = 0; y < 4; y++) {
        MIi_CpuCopy16(charsRightColumn + (characterIndex * 25 + 16 + y) * 16,
                      charsDestination + (column + 4 + row * 32) * 16 + y * 512, 0x20);
    }
    charsBottomRow = chars->mData;
    for (w = 0; w < 4; w++) {
        MIi_CpuCopy16(charsBottomRow + (characterIndex * 25 + 20 + w) * 16,
                      func_020b41e8_inline(charsDestination, column + (row + 4) * 32, w), 0x20);
    }
    MIi_CpuCopy16(chars->mData + (characterIndex * 25 + 24) * 16, charsDestination + (column + 4 + (row + 4) * 32) * 16,
                  0x20);
}
