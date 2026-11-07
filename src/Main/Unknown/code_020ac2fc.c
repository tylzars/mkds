#include "Main/Unknown/code_020ac2fc.h"

#pragma thumb on

// Splits each byte of a square image into two 4-bit entries and writes them in blocks of 8 x 8 entries.
void SplitBytesIntoNibbleTiles(void *bytes, u8 *tiles, s32 side) {
    s32 y;
    s32 rowBytes;
    s32 rowStart;
    s32 tilesPerRow;
    s32 j;
    s32 lowX;
    s32 highX;
    s32 byteIndex;

    rowBytes = side / 2;
    y = 0;
    if (side > 0) {
        rowStart = y;
        tilesPerRow = side / 8;
        do {
            j = 0;
            if (rowBytes > 0) {
                lowX = j;
                highX = 1;
                do {
                    byteIndex = j + rowStart;
                    tiles[(y & 7) * 8 + ((lowX & 7) + lowX / 8 * 64) + tilesPerRow * (y / 8 * 64)] =
                        ((u8 *) bytes)[byteIndex] & 0xf;
                    tiles[(y & 7) * 8 + ((highX & 7) + highX / 8 * 64) + tilesPerRow * (y / 8 * 64)] =
                        (((u8 *) bytes)[byteIndex] >> 4) & 0xf;
                    lowX += 2;
                    highX += 2;
                    j++;
                } while (j < rowBytes);
            }
            rowStart += rowBytes;
            y++;
        } while (y < side);
    }
}

// The reverse of SplitBytesIntoNibbleTiles: joins pairs of entries from the 8 x 8 blocks into bytes.
void JoinNibbleTilesIntoBytes(void *tiles, u8 *bytes, s32 side) {
    s32 y;
    s32 rowBytes;
    s32 rowStart;
    s32 tilesPerRow;
    s32 j;
    s32 highX;
    s32 lowX;

    rowBytes = side / 2;
    y = 0;
    if (side > 0) {
        rowStart = y;
        tilesPerRow = side / 8;
        do {
            j = 0;
            if (rowBytes > 0) {
                highX = 1;
                lowX = j;
                do {
                    bytes[j + rowStart] =
                        ((u8 *) tiles)[(y & 7) * 8 + ((lowX & 7) + lowX / 8 * 64) + tilesPerRow * (y / 8 * 64)] |
                        ((u8 *) tiles)[(y & 7) * 8 + ((highX & 7) + highX / 8 * 64) + tilesPerRow * (y / 8 * 64)] << 4;
                    highX += 2;
                    lowX += 2;
                    j++;
                } while (j < rowBytes);
            }
            rowStart += rowBytes;
            y++;
        } while (y < side);
    }
}

// Copies the bytes of a square image into the same 8 x 8 block order, two entries per byte.
void CopyBytesIntoTiles(void *bytes, u8 *tiles, s32 side) {
    s32 y;
    s32 tilesPerRow;
    s32 rowBytes;
    s32 j;
    s32 entryX;
    s32 rowStart;

    rowBytes = side / 2;
    y = 0;
    if (side > 0) {
        rowStart = y;
        tilesPerRow = side / 8;
        do {
            j = 0;
            if (rowBytes > 0) {
                entryX = j;
                do {
                    tiles[((y & 7) * 8 + ((entryX & 7) + entryX / 8 * 64) + tilesPerRow * (y / 8 * 64)) / 2] =
                        ((u8 *) bytes)[j + rowStart];
                    entryX += 2;
                    j++;
                } while (j < rowBytes);
            }
            rowStart += rowBytes;
            y++;
        } while (y < side);
    }
}

#pragma thumb off
