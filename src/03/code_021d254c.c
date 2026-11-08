#include "03/code_021d254c.h"
#include "registers.h"

void CombineDispcntBits(int screen, u32 bits) {
    vu32 *dispcnt;
    u32 currentBits;

    if (screen == 1) {
        dispcnt = &reg_GXS_DB_DISPCNT;
        currentBits = (*dispcnt & 0x1f00) >> 8;
        *dispcnt = (*dispcnt & 0xffffe0ff) | ((bits | currentBits) << 8);
    } else {
        dispcnt = &reg_GX_DISPCNT;
        currentBits = (*dispcnt & 0x1f00) >> 8;
        *dispcnt = (*dispcnt & 0xffffe0ff) | ((bits | currentBits) << 8);
    }
}

void ClearDispcntBits(int screen, u32 bits) {
    vu32 *dispcnt;
    u32 currentBits;

    if (screen == 1) {
        dispcnt = &reg_GXS_DB_DISPCNT;
        currentBits = (*dispcnt & 0x1f00) >> 8;
        *dispcnt = (*dispcnt & 0xffffe0ff) | ((~bits & currentBits) << 8);
    } else {
        dispcnt = &reg_GX_DISPCNT;
        currentBits = (*dispcnt & 0x1f00) >> 8;
        *dispcnt = (*dispcnt & 0xffffe0ff) | ((~bits & currentBits) << 8);
    }
}

void WriteWinRect(int screen, int window, u16 *rect) {
    u16 bottom;
    u16 top;
    u16 left;

    if (screen == 1) {
        if (window == 0) {
            bottom = rect[3];
            top = rect[1];
            left = rect[0];
            reg_G2S_DB_WIN0H = ((left << 8) & 0xff00) | (rect[2] & 0xff);
            reg_G2S_DB_WIN0V = ((top << 8) & 0xff00) | (bottom & 0xff);
        } else {
            bottom = rect[3];
            top = rect[1];
            left = rect[0];
            *(u16 *) 0x4001042 = ((left << 8) & 0xff00) | (rect[2] & 0xff);
            *(u16 *) 0x4001046 = ((top << 8) & 0xff00) | (bottom & 0xff);
        }
    } else {
        if (window == 0) {
            bottom = rect[3];
            top = rect[1];
            left = rect[0];
            reg_G2_WIN0H = ((left << 8) & 0xff00) | (rect[2] & 0xff);
            reg_G2_WIN0V = ((top << 8) & 0xff00) | (bottom & 0xff);
        } else {
            bottom = rect[3];
            top = rect[1];
            left = rect[0];
            reg_G2_WIN1H = ((left << 8) & 0xff00) | (rect[2] & 0xff);
            reg_G2_WIN1V = ((top << 8) & 0xff00) | (bottom & 0xff);
        }
    }
}

void WriteWinInOutBits(int screen, int selector, u32 bits, int extraBitFlag) {
    u32 registerValue;

    switch (selector) {
        case 0:
            if (screen == 1) {
                registerValue = reg_G2S_DB_WININ;
                registerValue = (registerValue & ~0x3f) | bits;
                if (extraBitFlag != 0) {
                    registerValue |= 0x20;
                }
                reg_G2S_DB_WININ = registerValue;
            } else {
                registerValue = reg_G2_WININ;
                registerValue = (registerValue & ~0x3f) | bits;
                if (extraBitFlag != 0) {
                    registerValue |= 0x20;
                }
                reg_G2_WININ = registerValue;
            }
            break;
        case 1:
            if (screen == 1) {
                registerValue = (reg_G2S_DB_WININ & 0xffffc0ff) | (bits << 8);
                if (extraBitFlag != 0) {
                    registerValue |= 0x2000;
                }
                reg_G2S_DB_WININ = registerValue;
            } else {
                registerValue = (reg_G2_WININ & 0xffffc0ff) | (bits << 8);
                if (extraBitFlag != 0) {
                    registerValue |= 0x2000;
                }
                reg_G2_WININ = registerValue;
            }
            break;
        case 2:
            if (screen == 1) {
                registerValue = (reg_G2S_DB_WINOUT & 0xffffc0ff) | (bits << 8);
                if (extraBitFlag != 0) {
                    registerValue |= 0x2000;
                }
                reg_G2S_DB_WINOUT = registerValue;
            } else {
                registerValue = (reg_G2_WINOUT & 0xffffc0ff) | (bits << 8);
                if (extraBitFlag != 0) {
                    registerValue |= 0x2000;
                }
                reg_G2_WINOUT = registerValue;
            }
            break;
        case 3:
            if (screen == 1) {
                registerValue = reg_G2S_DB_WINOUT;
                registerValue = (registerValue & ~0x3f) | bits;
                if (extraBitFlag != 0) {
                    registerValue |= 0x20;
                }
                reg_G2S_DB_WINOUT = registerValue;
            } else {
                registerValue = reg_G2_WINOUT;
                registerValue = (registerValue & ~0x3f) | bits;
                if (extraBitFlag != 0) {
                    registerValue |= 0x20;
                }
                reg_G2_WINOUT = registerValue;
            }
            break;
    }
}
