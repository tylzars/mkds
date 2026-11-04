#include "code_02148950.h"

#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/unk_02180000.h"
#include "code_0200cd1c.h"
#include "code_0200fd1c.h"
#include "code_0214c778.h"
#include "Main/Unknown/code_0200c000.h"
#include "Main/Unknown/code_0214d000.h"
#include "00/code_02188720.h"
#include "Main/Unknown/code_02148cd0.h"
#include "Main/Unknown/code_02148d24.h"
#include "code_0200fe7c.h"

u8 data_0216f070[4] = {1, 0, 0, 0};

// Writes 0x80 to each byte of 0x4000240-0x4000246, 0x4000248 and 0x4000249 whose bit (0, 1, ... 8) is set in a.
void func_02149dd8(u32 a) {
    if (a & 0x1) {
        *(vu8 *) 0x4000240 = 0x80;
    }
    if (a & 0x2) {
        *(vu8 *) 0x4000241 = 0x80;
    }
    if (a & 0x4) {
        *(vu8 *) 0x4000242 = 0x80;
    }
    if (a & 0x8) {
        *(vu8 *) 0x4000243 = 0x80;
    }
    if (a & 0x10) {
        *(vu8 *) 0x4000244 = 0x80;
    }
    if (a & 0x20) {
        *(vu8 *) 0x4000245 = 0x80;
    }
    if (a & 0x40) {
        *(vu8 *) 0x4000246 = 0x80;
    }
    if (a & 0x80) {
        *(vu8 *) 0x4000248 = 0x80;
    }
    if (a & 0x100) {
        *(vu8 *) 0x4000249 = 0x80;
    }
}

// Clears the bits of a in the halfword at data_021802b0 after or-ing in the halfword at +2, stores a at +2, writes
// the bytes at 0x4000240-0x4000246 for the value of a (0x81, 0x89, 0x91 or 0x99), then passes the halfword at +0 to
// func_02149dd8.
void func_02149b20(s32 a) {
    ((u16 *) data_021802b0)[0] = (((u16 *) data_021802b0)[0] | ((u16 *) data_021802b0)[1]) & ~a;
    ((u16 *) data_021802b0)[1] = a;
    switch (a) {
        case 8:
            *(vu8 *) 0x4000243 = 0x81;
            break;
        case 12:
            *(vu8 *) 0x4000243 = 0x89;
        case 4:
            *(vu8 *) 0x4000242 = 0x81;
            break;
        case 14:
            *(vu8 *) 0x4000243 = 0x91;
        case 6:
            *(vu8 *) 0x4000242 = 0x89;
        case 2:
            *(vu8 *) 0x4000241 = 0x81;
            break;
        case 15:
            *(vu8 *) 0x4000243 = 0x99;
        case 7:
            *(vu8 *) 0x4000242 = 0x91;
        case 3:
            *(vu8 *) 0x4000241 = 0x89;
        case 1:
            *(vu8 *) 0x4000240 = 0x81;
            break;
        case 11:
            *(vu8 *) 0x4000240 = 0x81;
            *(vu8 *) 0x4000241 = 0x89;
            *(vu8 *) 0x4000243 = 0x91;
            break;
        case 13:
            *(vu8 *) 0x4000243 = 0x91;
        case 5:
            *(vu8 *) 0x4000240 = 0x81;
            *(vu8 *) 0x4000242 = 0x89;
            break;
        case 9:
            *(vu8 *) 0x4000240 = 0x81;
            *(vu8 *) 0x4000243 = 0x89;
            break;
        case 10:
            *(vu8 *) 0x4000241 = 0x81;
            *(vu8 *) 0x4000243 = 0x89;
            break;
        case 0x70:
            *(vu8 *) 0x4000246 = 0x99;
        case 0x30:
            *(vu8 *) 0x4000245 = 0x91;
        case 16:
            *(vu8 *) 0x4000244 = 0x81;
            break;
        case 0x50:
            *(vu8 *) 0x4000246 = 0x91;
            *(vu8 *) 0x4000244 = 0x81;
            break;
        case 0x60:
            *(vu8 *) 0x4000246 = 0x89;
        case 32:
            *(vu8 *) 0x4000245 = 0x81;
            break;
        case 0x40:
            *(vu8 *) 0x4000246 = 0x81;
            break;
    }
    func_02149dd8(((u16 *) data_021802b0)[0]);
}

// Clears the bits of a in halfword 0 of data_021802b0 after or-ing in halfword 2, stores a there, writes the bytes
// 0x4000240, 0x4000241 and 0x4000244-0x4000246 for a = 1, 2, 3, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60 and 0x70, then
// passes halfword 0 to func_02149dd8.
void func_021499b4(s32 a) {
    ((u16 *) data_021802b0)[0] = (((u16 *) data_021802b0)[0] | ((u16 *) data_021802b0)[2]) & ~a;
    ((u16 *) data_021802b0)[2] = a;
    switch (a) {
        case 0x40:
            *(vu8 *) 0x4000246 = 0x82;
            break;
        case 0:
            break;
        case 3:
            *(vu8 *) 0x4000241 = 0x8a;
        case 1:
            *(vu8 *) 0x4000240 = 0x82;
            break;
        case 2:
            *(vu8 *) 0x4000241 = 0x82;
            break;
        case 0x70:
            *(vu8 *) 0x4000246 = 0x9a;
        case 0x30:
            *(vu8 *) 0x4000245 = 0x92;
        case 0x10:
            *(vu8 *) 0x4000244 = 0x82;
            break;
        case 0x50:
            *(vu8 *) 0x4000246 = 0x92;
            *(vu8 *) 0x4000244 = 0x82;
            break;
        case 0x60:
            *(vu8 *) 0x4000246 = 0x8a;
        case 0x20:
            *(vu8 *) 0x4000245 = 0x82;
            break;
    }
    func_02149dd8(((u16 *) data_021802b0)[0]);
}

// Clears the bits of a in halfword 0 of data_021802b0 after or-ing in halfword 7, stores a there, sets bit 30 of the
// word at 0x4000000 and writes the bytes 0x4000244-0x4000246 for a = 0x10, 0x20, 0x40 and 0x60 (clears the bit for a
// = 0), then passes halfword 0 to func_02149dd8.
void func_021498a0(s32 a) {
    ((u16 *) data_021802b0)[0] = (((u16 *) data_021802b0)[0] | ((u16 *) data_021802b0)[7]) & ~a;
    ((u16 *) data_021802b0)[7] = a;
    switch (a) {
        case 0:
            *(vu32 *) 0x4000000 &= ~0x40000000;
            break;
        case 0x10:
            *(vu32 *) 0x4000000 |= 0x40000000;
            *(vu8 *) 0x4000244 = 0x84;
            break;
        case 0x40:
            *(vu32 *) 0x4000000 |= 0x40000000;
            *(vu8 *) 0x4000246 = 0x8c;
            break;
        case 0x60:
            *(vu8 *) 0x4000246 = 0x8c;
        case 0x20:
            *(vu8 *) 0x4000245 = 0x84;
            *(vu32 *) 0x4000000 |= 0x40000000;
            break;
    }
    func_02149dd8(((u16 *) data_021802b0)[0]);
}

// Clears the bits of a in halfword 0 of data_021802b0 after or-ing in halfword 8, stores a there, sets bit 31 of the
// word at 0x4000000 and writes 0x85 to 0x4000245 or 0x4000246 for a = 0x20 and 0x40 (clears the bit for a = 0), then
// passes halfword 0 to func_02149dd8.
void func_021497e8(u32 a) {
    ((u16 *) data_021802b0)[0] = (((u16 *) data_021802b0)[0] | ((u16 *) data_021802b0)[8]) & ~a;
    ((u16 *) data_021802b0)[8] = a;
    switch (a) {
        case 0x20:
            *(vu32 *) 0x4000000 |= 0x80000000;
            *(vu8 *) 0x4000245 = 0x85;
            break;
        case 0x40:
            *(vu32 *) 0x4000000 |= 0x80000000;
            *(vu8 *) 0x4000246 = 0x85;
            break;
        case 0:
            *(vu32 *) 0x4000000 &= ~0x80000000;
            break;
    }
    func_02149dd8(((u16 *) data_021802b0)[0]);
}

// Clears the bits of a in halfword 0 of data_021802b0 after or-ing in halfword 4, stores a there, clears bits 12-13
// and sets bit 0 of the halfword at 0x4000060 (a mask of 0xcffe for a = 0) and writes the bytes 0x4000240-0x4000243
// for a = 1 to 15, then passes halfword 0 to func_02149dd8.
void func_021495e4(u32 a) {
    ((u16 *) data_021802b0)[0] = (((u16 *) data_021802b0)[0] | ((u16 *) data_021802b0)[4]) & ~a;
    ((u16 *) data_021802b0)[4] = a;
    if (a == 0) {
        *(vu16 *) 0x4000060 &= 0xcffe;
    } else {
        *(vu16 *) 0x4000060 = (*(vu16 *) 0x4000060 & ~0x3000) | 0x1;
        switch (a) {
            case 5:
                *(vu8 *) 0x4000240 = 0x83;
                *(vu8 *) 0x4000242 = 0x8b;
                break;
            case 9:
                *(vu8 *) 0x4000240 = 0x83;
                *(vu8 *) 0x4000243 = 0x8b;
                break;
            case 10:
                *(vu8 *) 0x4000241 = 0x83;
                *(vu8 *) 0x4000243 = 0x8b;
                break;
            case 11:
                *(vu8 *) 0x4000240 = 0x83;
                *(vu8 *) 0x4000241 = 0x8b;
                *(vu8 *) 0x4000243 = 0x93;
                break;
            case 13:
                *(vu8 *) 0x4000240 = 0x83;
                *(vu8 *) 0x4000242 = 0x8b;
                *(vu8 *) 0x4000243 = 0x93;
                break;
            case 8:
                *(vu8 *) 0x4000243 = 0x83;
                break;
            case 12:
                *(vu8 *) 0x4000243 = 0x8b;
            case 4:
                *(vu8 *) 0x4000242 = 0x83;
                break;
            case 14:
                *(vu8 *) 0x4000243 = 0x93;
            case 6:
                *(vu8 *) 0x4000242 = 0x8b;
            case 2:
                *(vu8 *) 0x4000241 = 0x83;
                break;
            case 15:
                *(vu8 *) 0x4000243 = 0x9b;
            case 7:
                *(vu8 *) 0x4000242 = 0x93;
            case 3:
                *(vu8 *) 0x4000241 = 0x8b;
            case 1:
                *(vu8 *) 0x4000240 = 0x83;
                break;
        }
    }
    func_02149dd8(((u16 *) data_021802b0)[0]);
}

// Clears the bits of a in halfword 0 of data_021802b0 after or-ing in halfword 5, stores a there, writes the bytes
// 0x4000244-0x4000246 for a = 0x10, 0x20, 0x30, 0x40, 0x60 and 0x70, then passes halfword 0 to func_02149dd8.
void func_021494f0(s32 a) {
    ((u16 *) data_021802b0)[0] = (((u16 *) data_021802b0)[0] | ((u16 *) data_021802b0)[5]) & ~a;
    ((u16 *) data_021802b0)[5] = a;
    switch (a) {
        case 0:
            break;
        case 0x40:
            *(vu8 *) 0x4000246 = 0x83;
            break;
        case 0x60:
            *(vu8 *) 0x4000246 = 0x8b;
        case 0x20:
            *(vu8 *) 0x4000245 = 0x83;
            break;
        case 0x70:
            *(vu8 *) 0x4000246 = 0x9b;
        case 0x30:
            *(vu8 *) 0x4000245 = 0x93;
        case 0x10:
            *(vu8 *) 0x4000244 = 0x83;
            break;
    }
    func_02149dd8(((u16 *) data_021802b0)[0]);
}

// Clears the bits of a in halfword 0 of data_021802b0 after or-ing in halfword 6, stores a there, writes the bytes
// 0x4000240-0x4000243 for a = 1, 2, 3, 4, 8 and 12 and sets (clears for a = 0) bit 14 of the halfword at 0x4000060,
// then passes halfword 0 to func_02149dd8.
void func_021493b0(u32 a) {
    ((u16 *) data_021802b0)[0] = (((u16 *) data_021802b0)[0] | ((u16 *) data_021802b0)[6]) & ~a;
    ((u16 *) data_021802b0)[6] = a;
    switch (a) {
        case 3:
            *(vu8 *) 0x4000240 = 0x93;
        case 2:
            *(vu8 *) 0x4000241 = 0x9b;
            *(vu16 *) 0x4000060 |= 0x4000;
            break;
        case 12:
            *(vu8 *) 0x4000242 = 0x93;
        case 8:
            *(vu8 *) 0x4000243 = 0x9b;
            *(vu16 *) 0x4000060 |= 0x4000;
            break;
        case 0:
            *(vu16 *) 0x4000060 &= ~0x4000;
            break;
        case 1:
            *(vu8 *) 0x4000240 = 0x9b;
            *(vu16 *) 0x4000060 |= 0x4000;
            break;
        case 4:
            *(vu8 *) 0x4000242 = 0x9b;
            *(vu16 *) 0x4000060 |= 0x4000;
            break;
    }
    func_02149dd8(((u16 *) data_021802b0)[0]);
}

// Clears the bits of a in halfword 0 of data_021802b0 after or-ing in halfword 3, stores a there, writes the bytes
// 0x4000242 and 0x4000243 for a = 4, 8 and 12, then passes halfword 0 to func_02149dd8.
void func_021492f8(s32 a) {
    ((u16 *) data_021802b0)[0] = (((u16 *) data_021802b0)[0] | ((u16 *) data_021802b0)[3]) & ~a;
    ((u16 *) data_021802b0)[3] = a;
    switch (a) {
        case 0:
            break;
        case 12:
            *(vu8 *) 0x4000243 = 0x8a;
            *(vu8 *) 0x4000242 = 0x82;
            break;
        case 4:
            *(vu8 *) 0x4000242 = 0x82;
            break;
        case 8:
            *(vu8 *) 0x4000243 = 0x82;
            break;
    }
    func_02149dd8(((u16 *) data_021802b0)[0]);
}

// Or-s a into halfword 0 of data_021802b0 and passes a to func_02149dd8.
void func_021492d8(u32 a) {
    ((u16 *) data_021802b0)[0] = ((u16 *) data_021802b0)[0] | a;
    func_02149dd8(a);
}

// Clears the bits of a in halfword 0 of data_021802b0 after or-ing in halfword 9, stores a there, writes 0x84 to
// 0x4000242 for a = 4 and 0x81 to 0x4000248 (and 0x4000249 for a = 0x180) for a = 0x80 and 0x180, then passes
// halfword 0 to func_02149dd8.
void func_0214922c(s32 a) {
    ((u16 *) data_021802b0)[0] = (((u16 *) data_021802b0)[0] | ((u16 *) data_021802b0)[9]) & ~a;
    ((u16 *) data_021802b0)[9] = a;
    switch (a) {
        case 0:
            break;
        case 4:
            *(vu8 *) 0x4000242 = 0x84;
            break;
        case 0x180:
            *(vu8 *) 0x4000249 = 0x81;
        case 0x80:
            *(vu8 *) 0x4000248 = 0x81;
            break;
    }
    func_02149dd8(((u16 *) data_021802b0)[0]);
}

// Clears the bits of a in halfword 0 of data_021802b0 after or-ing in halfword 10, stores a there, writes 0x84 to
// 0x4000243 for a = 8 and 0x82 to 0x4000249 for a = 0x100, then passes halfword 0 to func_02149dd8.
void func_021491b0(u32 a) {
    ((u16 *) data_021802b0)[0] = (((u16 *) data_021802b0)[0] | ((u16 *) data_021802b0)[10]) & ~a;
    ((u16 *) data_021802b0)[10] = a;
    if (a != 0) {
        switch (a) {
            case 0x100:
                *(vu8 *) 0x4000249 = 0x82;
                break;
            case 8:
                *(vu8 *) 0x4000243 = 0x84;
                break;
        }
    }
    func_02149dd8(((u16 *) data_021802b0)[0]);
}

// Clears the bits of a in halfword 0 of data_021802b0 after or-ing in halfword 11, stores a there, sets bit 30 of
// the word at 0x4001000 and writes 0x82 to 0x4000248 for a = 0x80 (clears the bit for a = 0), then passes halfword 0
// to func_02149dd8.
void func_02149124(u32 a) {
    ((u16 *) data_021802b0)[0] = (((u16 *) data_021802b0)[0] | ((u16 *) data_021802b0)[11]) & ~a;
    ((u16 *) data_021802b0)[11] = a;
    if (a != 0) {
        if (a == 0x80) {
            *(vu32 *) 0x4001000 |= 0x40000000;
            *(vu8 *) 0x4000248 = 0x82;
        }
    } else {
        *(vu32 *) 0x4001000 &= ~0x40000000;
    }
    func_02149dd8(((u16 *) data_021802b0)[0]);
}

// Clears the bits of a in halfword 0 of data_021802b0 after or-ing in halfword 12, stores a there, sets bit 31 of
// the word at 0x4001000 and writes 0x83 to 0x4000249 for a = 0x100 (clears the bit for a = 0), then passes halfword
// 0 to func_02149dd8.
void func_02149098(u32 a) {
    ((u16 *) data_021802b0)[0] = (((u16 *) data_021802b0)[0] | ((u16 *) data_021802b0)[12]) & ~a;
    ((u16 *) data_021802b0)[12] = a;
    if (a != 0) {
        if (a == 0x100) {
            *(vu32 *) 0x4001000 |= 0x80000000;
            *(vu8 *) 0x4000249 = 0x83;
        }
    } else {
        *(vu32 *) 0x4001000 &= ~0x80000000;
    }
    func_02149dd8(((u16 *) data_021802b0)[0]);
}

// Reads the halfword at p and stores 0 there, or-s it into the halfword at data_021802b0, passes it to func_02149dd8
// and returns it.
u16 func_02149060(u16 *p) {
    u16 v;

    v = *p;
    *p = 0;
    ((u16 *) data_021802b0)[0] = ((u16 *) data_021802b0)[0] | v;
    func_02149dd8(v);
    return v;
}

// Clears bit 30 of the word at 0x4000000, then returns func_02149060(&data_021802be).
u16 func_0214903c(void) {
    *(vu32 *) 0x4000000 &= ~0x40000000;
    return func_02149060(&data_021802be);
}

// Clears bit 31 of the word at 0x4000000, then returns func_02149060(&data_021802c0).
u16 func_02149018(void) {
    *(vu32 *) 0x4000000 &= ~0x80000000;
    return func_02149060(&data_021802c0);
}

// Returns func_02149060(&data_021802b8).
u16 func_02149004(void) {
    return func_02149060(&data_021802b8);
}

// Returns func_02149060(&data_021802ba).
u16 func_02148ff0(void) {
    return func_02149060(&data_021802ba);
}

// Returns func_02149060(&data_021802bc).
u16 func_02148fdc(void) {
    return func_02149060(&data_021802bc);
}

// Returns func_02149060(&data_021802c2).
u16 func_02148fc8(void) {
    return func_02149060(&data_021802c2);
}

// Returns func_02149060(&data_021802c4).
u16 func_02148fb4(void) {
    return func_02149060(&data_021802c4);
}

// Clears bit 30 of the word at 0x4001000, then returns func_02149060(&data_021802c6).
u16 func_02148f8c(void) {
    *(vu32 *) 0x4001000 &= ~0x40000000;
    return func_02149060(&data_021802c6);
}

// Clears bit 31 of the word at 0x4001000, then returns func_02149060(&data_021802c8).
u16 func_02148f64(void) {
    *(vu32 *) 0x4001000 &= ~0x80000000;
    return func_02149060(&data_021802c8);
}

// Reads the halfword at p and stores 0 there, writes 0 to each byte of 0x4000240-0x4000246, 0x4000248 and 0x4000249
// whose bit (0, 1, ... 8) is set in it, calls func_0200fe7c with it and data_021802a8, and returns it.
u32 func_02148e80(u16 *p) {
    u32 v;

    v = *p;
    *p = 0;
    if (v & 0x1) {
        *(vu8 *) 0x4000240 = 0;
    }
    if (v & 0x2) {
        *(vu8 *) 0x4000241 = 0;
    }
    if (v & 0x4) {
        *(vu8 *) 0x4000242 = 0;
    }
    if (v & 0x8) {
        *(vu8 *) 0x4000243 = 0;
    }
    if (v & 0x10) {
        *(vu8 *) 0x4000244 = 0;
    }
    if (v & 0x20) {
        *(vu8 *) 0x4000245 = 0;
    }
    if (v & 0x40) {
        *(vu8 *) 0x4000246 = 0;
    }
    if (v & 0x80) {
        *(vu8 *) 0x4000248 = 0;
    }
    if (v & 0x100) {
        *(vu8 *) 0x4000249 = 0;
    }
    func_0200fe7c((u16) v, data_021802a8);
    return v;
}

// Returns func_02148e80(&data_021802b2).
u32 func_02148e6c(void) {
    return func_02148e80(&data_021802b2);
}

// Returns func_02148e80(&data_021802b4).
u32 func_02148e58(void) {
    return func_02148e80(&data_021802b4);
}

// Clears bit 30 of the word at 0x4000000, then returns func_02148e80(&data_021802be).
u32 func_02148e34(void) {
    *(vu32 *) 0x4000000 &= ~0x40000000;
    return func_02148e80(&data_021802be);
}

// Clears bit 31 of the word at 0x4000000, then returns func_02148e80(&data_021802c0).
u32 func_02148e10(void) {
    *(vu32 *) 0x4000000 &= ~0x80000000;
    return func_02148e80(&data_021802c0);
}

// Returns func_02148e80(&data_021802b8).
u32 func_02148dfc(void) {
    return func_02148e80(&data_021802b8);
}

// Returns func_02148e80(&data_021802ba).
u32 func_02148de8(void) {
    return func_02148e80(&data_021802ba);
}

// Returns func_02148e80(&data_021802bc).
u32 func_02148dd4(void) {
    return func_02148e80(&data_021802bc);
}

// Returns func_02148e80(&data_021802b6).
u32 func_02148dc0(void) {
    return func_02148e80(&data_021802b6);
}

// Returns func_02148e80(data_021802b0).
u32 func_02148dac(void) {
    return func_02148e80((u16 *) data_021802b0);
}

// Returns func_02148e80(&data_021802c2).
u32 func_02148d98(void) {
    return func_02148e80(&data_021802c2);
}

// Returns func_02148e80(&data_021802c4).
u32 func_02148d84(void) {
    return func_02148e80(&data_021802c4);
}

// Clears bit 30 of the word at 0x4001000, then returns func_02148e80(&data_021802c6).
u32 func_02148d5c(void) {
    *(vu32 *) 0x4001000 &= ~0x40000000;
    return func_02148e80(&data_021802c6);
}

// Clears bit 31 of the word at 0x4001000, then returns func_02148e80(&data_021802c8).
u32 func_02148d34(void) {
    *(vu32 *) 0x4001000 &= ~0x80000000;
    return func_02148e80(&data_021802c8);
}

u32 func_02148d24(void) {
    u32 value0;
    value0 = (u32) &data_021802b0;
    value0 = (u32) * (const u16 *) ((value0) + (8));
    return value0;
}

u32 func_02148cd0(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 compareLeft0;
    u32 compareRight0;
    u32 compareLeft1;
    u32 compareRight1;
    u32 compareLeft2;
    u32 compareRight2;
    u32 compareLeft3;
    u32 compareRight3;
    u32 compareLeft4;
    u32 compareRight4;
    u32 compareLeft5;
    u32 compareRight5;
    u32 compareLeft6;
    u32 compareRight6;
    u32 compareLeft7;
    u32 compareRight7;
    u32 compareLeft8;
    u32 compareRight8;
    value2 = 0u;
    value1 = (value0) & (1u);
    compareLeft0 = value1;
    compareRight0 = 0u;
    if (compareLeft0 != compareRight0) {
        value2 = (value2) + (0x20000u);
    }
    value1 = (value0) & (2u);
    compareLeft1 = value1;
    compareRight1 = 0u;
    if (compareLeft1 != compareRight1) {
        value2 = (value2) + (0x20000u);
    }
    value1 = (value0) & (4u);
    compareLeft2 = value1;
    compareRight2 = 0u;
    if (compareLeft2 != compareRight2) {
        value2 = (value2) + (0x20000u);
    }
    value1 = (value0) & (8u);
    compareLeft3 = value1;
    compareRight3 = 0u;
    if (compareLeft3 != compareRight3) {
        value2 = (value2) + (0x20000u);
    }
    value1 = (value0) & (0x10u);
    compareLeft4 = value1;
    compareRight4 = 0u;
    if (compareLeft4 != compareRight4) {
        value2 = (value2) + (0x10000u);
    }
    value1 = (value0) & (0x20u);
    compareLeft5 = value1;
    compareRight5 = 0u;
    if (compareLeft5 != compareRight5) {
        value2 = (value2) + (0x4000u);
    }
    value1 = (value0) & (0x40u);
    compareLeft6 = value1;
    compareRight6 = 0u;
    if (compareLeft6 != compareRight6) {
        value2 = (value2) + (0x4000u);
    }
    value1 = (value0) & (0x80u);
    compareLeft7 = value1;
    compareRight7 = 0u;
    if (compareLeft7 != compareRight7) {
        value2 = (value2) + (0x8000u);
    }
    value0 = (value0) & (0x100u);
    compareLeft8 = value0;
    compareRight8 = 0u;
    if (compareLeft8 != compareRight8) {
        value2 = (value2) + (0x4000u);
    }
    value0 = value2;
    return value0;
}

u32 func_02148cb8(void) {
    u32 value0;
    u32 value12;
    value0 = (u32) &data_021802b0;
    value12 = (u32) &func_02148cd0;
    value0 = (u32) * (const u16 *) ((value0) + (4));
    value0 = (u32) func_02148cd0(value0);
    return value0;
}

u32 func_02148ca0(void) {
    u32 value0;
    u32 value12;
    value0 = (u32) &data_021802b0;
    value12 = (u32) &func_02148cd0;
    value0 = (u32) * (const u16 *) ((value0) + (20));
    value0 = (u32) func_02148cd0(value0);
    return value0;
}

// Zeroes the 13 halfwords at data_021802b0, the word at 0x4000240, the bytes at 0x4000244-0x4000246 and the halfword
// at 0x4000248.
void func_02148c20(void) {
    ((u16 *) data_021802b0)[0] = 0;
    ((u16 *) data_021802b0)[1] = 0;
    ((u16 *) data_021802b0)[2] = 0;
    ((u16 *) data_021802b0)[3] = 0;
    ((u16 *) data_021802b0)[4] = 0;
    ((u16 *) data_021802b0)[5] = 0;
    ((u16 *) data_021802b0)[6] = 0;
    ((u16 *) data_021802b0)[7] = 0;
    ((u16 *) data_021802b0)[8] = 0;
    ((u16 *) data_021802b0)[9] = 0;
    ((u16 *) data_021802b0)[10] = 0;
    ((u16 *) data_021802b0)[11] = 0;
    ((u16 *) data_021802b0)[12] = 0;
    *(vu32 *) 0x4000240 = 0;
    *(vu8 *) 0x4000244 = 0;
    *(vu8 *) 0x4000245 = 0;
    *(vu8 *) 0x4000246 = 0;
    *(vu16 *) 0x4000248 = 0;
}

// Updates the halfword at 0x4000304, calls func_02148c20, then calls func_0200cd28 until data_021802a8 is nonzero
// (calling func_0200fd1c when it returns -3). Zeroes 0x4000004 and 0x4000000, then passes 0 with the ranges
// 0x4000008 (size 0x60) and 0x4001000 (size 0x70) to func_0214cc04 when data_0216f074[0] is not -1 and to
// MemFillWords otherwise, with the halfword at 0x400006c zeroed in between. Finally stores 0x100 in the halfwords
// at 0x4000020, 0x4000026, 0x4000030, 0x4000036 and the same offsets from 0x4001000.
void func_02148a88(void) {
    s32 r;

    *(vu16 *) 0x4000304 |= 0x8000;
    *(vu16 *) 0x4000304 = (*(vu16 *) 0x4000304 & ~0x20e) | 0x20e;
    *(vu16 *) 0x4000304 |= 0x1;
    func_02148c20();
    while (*(vu16 *) &data_021802a8 == 0) {
        r = func_0200cd28();
        if (r == -3) {
            func_0200fd1c();
        }
        *(vu16 *) &data_021802a8 = r;
    }
    *(vu16 *) 0x4000004 = 0;
    *(vu32 *) 0x4000000 = 0;
    if (data_0216f074[0] != -1) {
        func_0214cc04(data_0216f074[0], (void *) 0x4000008, 0, 0x60);
        *(vu16 *) 0x400006c = 0;
        func_0214cc04(data_0216f074[0], (void *) 0x4001000, 0, 0x70);
    } else {
        volatile u32 z0 = 0;
        volatile u32 z1;

        MemFillWords(z0, (void *) 0x4000008, 0x60);
        *(vu16 *) 0x400006c = 0;
        z1 = 0;
        MemFillWords(z1, (void *) 0x4001000, 0x70);
    }
    *(vu16 *) 0x4000020 = 0x100;
    *(vu16 *) 0x4000026 = 0x100;
    *(vu16 *) 0x4000030 = 0x100;
    *(vu16 *) 0x4000036 = 0x100;
    *(vu16 *) 0x4001020 = 0x100;
    *(vu16 *) 0x4001026 = 0x100;
    *(vu16 *) 0x4001030 = 0x100;
    *(vu16 *) 0x4001036 = 0x100;
}

// Sets (a != 0) or clears bit 3 of the halfword at 0x4000004 and returns its previous value (0 or 8).
u32 func_02148a58(s32 a) {
    u32 old;

    old = *(vu16 *) 0x4000004 & 0x8;
    if (a != 0) {
        *(vu16 *) 0x4000004 |= 0x8;
    } else {
        *(vu16 *) 0x4000004 &= ~0x8;
    }
    return old;
}

void func_02148a10(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 value12;
    u32 value14;
    value14 = 0x4000000u;
    value12 = (u32) * (const u32 *) ((value14) + (0));
    value1 = (u32) &data_0216f070;
    value2 = (value12) & (0x30000u);
    value3 = 0u;
    value0 = (u32) &data_021802ac;
    value2 = (value2 >> 16);
    *(u16 *) ((value1) + (0)) = (u16) value3;
    *(u16 *) ((value0) + (0)) = (u16) value2;
    value0 = (value12) & ~(0x30000u);
    *(u32 *) ((value14) + (0)) = value0;
}

// Sets data_0216f070 to 1. When data_021802ac is 0, sets bit 16 of the word at 0x4000000; otherwise replaces bits
// 16-17 of that word with data_021802ac.
void func_021489c4(void) {
    u32 a;

    *(u16 *) data_0216f070 = 1;
    a = *(u16 *) data_021802ac;
    if (a != 0) {
        *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & ~0x30000) | (a << 16);
    } else {
        *(vu32 *) 0x4000000 |= 0x10000;
    }
}

// Stores a in data_021802ac, then replaces the word at 0x4000000 by (word & 0xfff0fff0) | (a << 16) | b | (c << 3),
// with a taken as 0 when data_0216f070 is 0. Clears data_0216f070 when data_021802ac is 0.
void func_02148950(u16 a, u32 b, s32 c) {
    u32 v;
    u32 x;

    x = *(vu32 *) 0x4000000;
    v = *(u16 *) data_0216f070;
    *(u16 *) data_021802ac = a;
    if (v == 0) {
        a = 0;
    }
    *(vu32 *) 0x4000000 = ((x & 0xfff0fff0) | (a << 16) | b) | (c << 3);
    if (*(u16 *) data_021802ac == 0) {
        *(u16 *) data_0216f070 = 0;
    }
}
