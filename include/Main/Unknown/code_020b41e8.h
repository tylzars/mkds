#pragma once

#include "types.h"

void InitFontIfLoaded(void *font, void *fontData);
void CopyCharsBlock(void *source, s32 sourceTileX, s32 sourceTileY, s32 tileWidth, s32 tileHeight, void *destination,
                    s32 destinationTileX, s32 destinationTileY);
void CopyCharsBlockFlippedVertically(u16 *source, s32 sourceTileX, s32 sourceTileY, s32 tileWidth, s32 tileHeight,
                                     u16 *destination, s32 destinationTileX, s32 destinationTileY);
void CopyScreenMapBlock(u16 *source, s32 sourceColumn, s32 sourceRow, s32 columnCount, s32 rowCount, u16 *destination,
                        s32 destinationColumn, s32 destinationRow);
void SetScreenMapBlockTopBits(u16 *screenMap, s32 column, s32 row, s32 columnCount, s32 rowCount, u16 topBits);
void SetScreenMapBlockLowBits(u16 *screenMap, s32 column, s32 row, s32 columnCount, s32 rowCount, s32 lowBits);
void CopyPlayerCharacterPaletteAndChars(u16 *paletteDestination, s32 paletteRow, u16 *charsDestination, s32 column,
                                        s32 row);
