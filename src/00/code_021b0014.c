#include "00/code_021b0014.h"

u32 func_ov000_021b01b4(const void *buffer, u32 length, u32 sum) {
    const u8 *bytes = buffer;

    if ((u32) bytes & 1) {
        while (length > 1) {
            sum += (u16) ((bytes[0] << 8) | bytes[1]);
            bytes += 2;
            length -= 2;
        }
    } else {
        u16 word = sum;

        sum = (u16) ((word >> 8) | (word << 8));
        while (length > 1) {
            sum += *(const u16 *) bytes;
            bytes += 2;
            length -= 2;
        }
        sum = ((sum >> 8) & 0x00ff00ff) | ((sum << 8) & 0xff00ff00);
        sum = (sum >> 16) | (sum << 16);
    }
    if (length != 0) {
        sum += *bytes << 8;
    }
    sum = (sum & 0xffff) + (sum >> 16);
    sum += sum >> 16;
    return (u16) sum;
}

u16 func_ov000_021b01a0(u16 sum) {
    sum ^= 0xffff;
    if (sum == 0) {
        sum = 0xffff;
    }
    return sum;
}

u16 func_ov000_021b0188(const void *buffer, u32 length) {
    return func_ov000_021b01a0((u16) func_ov000_021b01b4(buffer, length, 0));
}

BOOL func_ov000_021b0138(const void *buffer, u32 length, const Unk021b0138 *header, u32 sum) {
    sum = func_ov000_021b01b4(buffer, length, sum);
    sum = func_ov000_021b01b4(header->mUnk_0c, 8, sum);
    sum += length;
    if (sum & 0x10000) {
        sum = (sum + 1) & 0xffff;
    }
    if (sum != 0xffff) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_ov000_021b00fc(u32 address) {
    return address == 0xffffffff || address == 0x7f000001 ||
           (address & data_ov000_021b6380) == (data_ov000_021b63b4 & data_ov000_021b6380);
}

u32 func_ov000_021b00e0(u32 address) {
    if (func_ov000_021b00fc(address) == FALSE) {
        address = data_ov000_021b639c;
    }
    return address;
}

s32 func_ov000_021b00b0(u32 address) {
    BOOL result = FALSE;

    if (func_ov000_021b00fc(address) != FALSE && (address & ~data_ov000_021b6380) == ~data_ov000_021b6380) {
        result = TRUE;
    }
    return result;
}

BOOL func_ov000_021b0094(u32 address) {
    if ((address & 0xf0000000) == 0xe0000000) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_ov000_021b003c(u32 address) {
    return data_ov000_021b63b4 == 0 || address == data_ov000_021b63b4 || address == 0x7f000001 ||
           func_ov000_021b00b0(address) != 0 || func_ov000_021b0094(address) != FALSE;
}

BOOL func_ov000_021b0014(const u16 *first, const u16 *second) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (*first++ != *second++) {
            return TRUE;
        }
    }
    return FALSE;
}
