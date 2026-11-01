#include "code_0214d5b8.h"
#include "code_0200c914.h"
#include "Main/Unknown/code_0200f000.h"
#include "registers.h"

UnkFunc *data_0218032c[32];
u16 data_02180328;

// Runs once: clears the first word at mUnk_388 and the 32 entries of data_0218032c, writes 0xc408 to the register
// at 0x04000184, calls func_0200ca68, func_0200cc74 (with func_0214d5c4) and func_0200cae4 with 0x40000, then
// writes the low 4 bits read from the register at 0x04000180 back shifted left by 8 until the conditions of its loop
// hold.
void func_0214d830(void) {
    u32 s;
    s32 i;
    s32 n;
    u32 v;
    s32 j;
    Unk027ffc00 *p;

    s = func_0200fca0();
    if (data_02180328 == 0) {
        data_02180328 = 1;
        p = (Unk027ffc00 *) 0x027ffc00;
        p->mUnk_388[0] = 0;
        for (i = 0; i < 32; i++) {
            data_0218032c[i] = 0;
        }
        reg_PXI_SUBP_FIFO_CNT = 0xc408;
        func_0200ca68(0x40000);
        func_0200cc74(0x40000, (UnkFunc *) func_0214d5c4);
        func_0200cae4(0x40000);
        j = 0;
        for (;;) {
            v = reg_PXI_SUBPINTF & 0xf;
            reg_PXI_SUBPINTF = v << 8;
            if (v == 0 && j > 4) {
                break;
            }
            n = 1000;
            while ((reg_PXI_SUBPINTF & 0xf) == v) {
                if (n <= 0) {
                    j = 0;
                    break;
                }
                n--;
            }
            j++;
        }
    }
    func_0200fcb4(s);
}

// Stores fn in entry a of the table and sets or clears bit a of the first word at mUnk_388.
void func_0214d7c4(u32 a, UnkFunc *fn) {
    u32 s;
    Unk027ffc00 *p;

    s = func_0200fca0();
    data_0218032c[a] = fn;
    p = (Unk027ffc00 *) 0x027ffc00;
    if (fn != 0) {
        p->mUnk_388[0] |= 1 << a;
    } else {
        p->mUnk_388[0] &= ~(1 << a);
    }
    func_0200fcb4(s);
}

// Returns whether bit a of word b at mUnk_388 is set.
s32 func_0214d79c(u32 a, u32 b) {
    Unk027ffc00 *p;

    p = (Unk027ffc00 *) 0x027ffc00;
    return (p->mUnk_388[b] & (1 << a)) != 0;
}

// Packs a (5 bits), c (1 bit) and b (26 bits) into one word and writes it to the register at 0x04000188.
// Returns -1 when the register at 0x04000184 shows bit 0x4000 (cleared by writing 0xc000), -2 when bit 2 is set.
s32 func_0214d6e8(u32 a, u32 b, u32 c) {
    Unk0214d5c4 v;
    u32 s;

    v.mUnk_00_0 = a;
    v.mUnk_00_5 = c;
    v.mUnk_00_6 = b;
    if (reg_PXI_SUBP_FIFO_CNT & 0x4000) {
        reg_PXI_SUBP_FIFO_CNT |= 0xc000;
        return -1;
    }
    s = func_0200fca0();
    if (reg_PXI_SUBP_FIFO_CNT & 2) {
        func_0200fcb4(s);
        return -2;
    }
    reg_PXI_SEND_FIFO = *(u32 *) &v;
    func_0200fcb4(s);
    return 0;
}

// Reads words from 0x04100000 until the register at 0x04000184 shows bit 0x100; calls the table entry selected by
// the low 5 bits with the word's other fields; an unhandled word with bit 5 clear is written back with bit 5 set.
void func_0214d5c4(void) {
    Unk0214d5c4 v;
    s32 r;
    u32 s;
    UnkFunc *f;

    for (;;) {
        if (reg_PXI_SUBP_FIFO_CNT & 0x4000) {
            reg_PXI_SUBP_FIFO_CNT |= 0xc000;
            r = -3;
        } else {
            s = func_0200fca0();
            if (reg_PXI_SUBP_FIFO_CNT & 0x100) {
                func_0200fcb4(s);
                r = -4;
            } else {
                *(u32 *) &v = reg_PXI_RECV_FIFO;
                func_0200fcb4(s);
                r = 0;
            }
        }
        if (r == -4) {
            return;
        }
        if (r == -3) {
            continue;
        }
        if (v.mUnk_00_0 == 0) {
            continue;
        }
        f = data_0218032c[v.mUnk_00_0];
        if (f != 0) {
            f(v.mUnk_00_0, v.mUnk_00_6, v.mUnk_00_5);
            continue;
        }
        if (v.mUnk_00_5 == 0) {
            v.mUnk_00_5 = 1;
            if (reg_PXI_SUBP_FIFO_CNT & 0x4000) {
                reg_PXI_SUBP_FIFO_CNT |= 0xc000;
                continue;
            }
            s = func_0200fca0();
            if (reg_PXI_SUBP_FIFO_CNT & 2) {
                func_0200fcb4(s);
            } else {
                reg_PXI_SEND_FIFO = *(u32 *) &v;
                func_0200fcb4(s);
            }
        }
    }
}

// Calls func_0214d830.
void func_0214d5b8(void) {
    func_0214d830();
}
