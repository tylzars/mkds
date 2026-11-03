#include "03/code_021b94b8.h"
#include "03/code_021b7bb4.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"

Unk021d687c data_ov003_021d687c[12] = {
    {0x0001, 0x02, 0}, {0x0002, 0x04, 0}, {0x0004, 0x0b, 0}, {0x0008, 0x0c, 0}, {0x0010, 0x12, 0}, {0x0020, 0x16, 0},
    {0x0040, 0x18, 0}, {0x0080, 0x24, 0}, {0x0100, 0x30, 0}, {0x0200, 0x48, 0}, {0x0400, 0x60, 0}, {0x0800, 0x6c, 0},
};

void func_ov003_021ba778(Unk021ba778Src *src, Unk021ba778Dst *dst) {
    int i;
    int count;
    int mode;
    dst->mUnk_00 = src->mUnk_0a;
    func_0214cffc(src->mUnk_0c, dst->mUnk_04, 0x20);
    dst->mUnk_24 = src->mUnk_36;
    func_0214cffc(src->mUnk_04, dst->mUnk_30, 6);
    count = 0;
    for (i = 0; i < 12; i++) {
        if (src->mUnk_30 & data_ov003_021d687c[i].mUnk_00) {
            dst->mUnk_3c[count] = data_ov003_021d687c[i].mUnk_02;
            if (src->mUnk_2e & data_ov003_021d687c[i].mUnk_00) {
                dst->mUnk_3c[count] |= 0x80;
            }
            count++;
        }
    }
    dst->mUnk_38 = count;
    dst->mUnk_4c = src->mUnk_32;
    mode = src->mUnk_2c & 3;
    if (mode == 1) {
        dst->mUnk_50 = 1;
    } else if (mode == 2) {
        dst->mUnk_50 = 2;
    } else {
        dst->mUnk_50 = 0;
    }
}

void func_ov003_021ba744(Unk021ba1b0 *request, Unk021ba778Src *rec) {
    vu16 zero = 0;
    func_0214cfe4(zero, rec->mUnk_0c, 0x20);
    rec->mUnk_0a = request->mUnk_00;
    func_0214d1fc(request->mUnk_04, rec->mUnk_0c, rec->mUnk_0a);
}

void func_ov003_021ba734(Unk021ba734 *list, Unk021ba778Src *src, s32 count) {
    list->mUnk_00 = count;
    func_ov003_021ba778(src, list->mUnk_04);
}

s32 func_ov003_021ba720(void *msg) {
    return func_0200eae8(&data_ov003_021d8a2c, msg, 0);
}

s32 func_ov003_021ba70c(void *msg) {
    return func_0200eae8(&data_ov003_021d8a2c, msg, 0);
}

s32 func_ov003_021ba61c(void *(*alloc)(u32), void (*release)(void *)) {
    BOOL running = TRUE;
    void *msg;
    void *buffer;
    u32 enabled;
    func_0200eb90(&data_ov003_021d8a2c, data_ov003_021d8a1c, 4);
    if (alloc == NULL || release == NULL) {
        return -1;
    }
    enabled = func_0200fca0();
    data_ov003_021d8a0c = alloc;
    data_ov003_021d8a18 = release;
    func_0200fcb4(enabled);
    buffer = data_ov003_021d8a0c(0x5890);
    data_ov003_021d8a14 = buffer;
    if (buffer == NULL) {
        return -1;
    }
    if (func_ov003_021ba818(func_ov003_021ba720, buffer, 0x5890) == 0) {
        running = FALSE;
    }
    if (running != FALSE) {
        do {
            func_0200ea3c(&data_ov003_021d8a2c, &msg, 1);
            switch ((u32) msg) {
                case 4:
                case 5:
                    break;
                case 6:
                    return 0;
                    // placeholder: labels that fall into default only give the original's jump table its size
                case 8:
                case 0xa:
                case 0xc:
                case 0xd:
                case 0xf:
                default:
                    running = FALSE;
                    break;
            }
        } while (running != FALSE);
    }
    data_ov003_021d8a18(data_ov003_021d8a14);
    return -1;
}

s32 func_ov003_021ba560(void) {
    s32 result;
    BOOL running;
    void *msg;
    u32 enabled;
    running = TRUE;
    result = -1;
    if (data_ov003_021d8a18 == NULL) {
        return -1;
    }
    if (func_ov003_021ba9c0() == 0) {
        return -1;
    }
    do {
        func_0200ea3c(&data_ov003_021d8a2c, &msg, 1);
        switch ((u32) msg) {
            case 4:
            case 5:
                break;
            case 0x14:
                running = FALSE;
                result = 0;
                data_ov003_021d8a18(data_ov003_021d8a14);
                break;
                // placeholder: labels that fall into default only give the original's jump table its size
            case 8:
            case 0xa:
            case 0xc:
            case 0xd:
            case 0x12:
            case 0x13:
            default:
                running = FALSE;
                break;
        }
    } while (running != FALSE);
    enabled = func_0200fca0();
    data_ov003_021d8a0c = NULL;
    data_ov003_021d8a18 = NULL;
    func_0200fcb4(enabled);
    return result;
}

s32 func_ov003_021ba524(void) {
    BOOL done;
    s32 result = -1;
    void *msg;
    if (func_ov003_021baa28() != 0) {
        done = FALSE;
        do {
            func_0200ea3c(&data_ov003_021d8a2c, &msg, 1);
            /* waits for one entry; the loop flag is a placeholder */
            if ((u32) msg == 0xe) {
                result = 0;
                done = FALSE;
            }
        } while (done != FALSE);
    }
    return result;
}

s32 func_ov003_021ba394(Unk021ba734 **out) {
    BOOL found = FALSE;
    s32 result = -1;
    BOOL running = TRUE;
    s32 count = 0;
    s32 waits = 0;
    Unk021ba778Src *scan;
    Unk021ba778Src *buffer;
    Unk021ba734 *list;
    void *msg;
    Unk0200fb08 timer;
    s32 i;
    if (data_ov003_021d8a0c == NULL || data_ov003_021d8a18 == NULL) {
        return -1;
    }
    scan = data_ov003_021d8a0c(0x3000);
    if (scan == NULL) {
        return -1;
    }
    buffer = scan;
    if (func_ov003_021baaac(NULL, NULL, 0, 0x30bffe) != 0) {
        func_0200fb08(&timer);
        func_0200f950(&timer, 0x3fec42, (void (*)(void *)) func_ov003_021ba70c, (void *) 0x13);
        do {
            func_0200ea3c(&data_ov003_021d8a2c, &msg, 1);
            switch ((u32) msg) {
                case 0x13:
                    if (found == FALSE) {
                        if (waits != 0) {
                            count = func_ov003_021babc0(scan, 0x40);
                        }
                        if (func_ov003_021baa68() == 0) {
                            goto cleanup;
                        }
                        found = TRUE;
                    }
                    break;
                case 5:
                    if (found == FALSE) {
                        if (waits < 8) {
                            waits++;
                        } else {
                            count = func_ov003_021babc0(scan, 0x40);
                            if (func_ov003_021baa68() == 0) {
                                goto cleanup;
                            }
                            found = TRUE;
                        }
                    }
                    break;
                case 0xa:
                    running = FALSE;
                    result = 0;
                    break;
                case 4:
                case 8:
                case 0x12:
                    break;
                    // placeholder: labels that fall into default only give the original's jump table its size
                case 0xc:
                case 0xd:
                default:
                    goto cleanup;
            }
        } while (running != FALSE);
        if (count != 0) {
            list = data_ov003_021d8a0c((count - 1) * 0x54 + 0x58);
            if (list == NULL) {
                goto cleanup;
            }
        } else {
            list = data_ov003_021d8a0c(0x58);
            if (list == NULL) {
                goto cleanup;
            }
        }
        *out = list;
        list->mUnk_00 = count;
        for (i = 0; i < count; i++) {
            func_ov003_021ba778(scan, &list->mUnk_04[i]);
            scan++;
        }
    cleanup:
        func_0200f8b8(&timer);
        while (func_0200ea3c(&data_ov003_021d8a2c, &msg, 0) == 1) {
        }
    }
    data_ov003_021d8a18(buffer);
    return result;
}

s32 func_ov003_021ba1b0(Unk021ba1b0 *request, Unk021ba734 *out) {
    BOOL running = TRUE;
    s32 result;
    s32 retries;
    BOOL done;
    u32 flags;
    void *msg;
    Unk0200fb08 timer;
    done = FALSE;
    result = -1;
    if (request->mUnk_24 == 0) {
        flags = 0x80000;
    } else if (request->mUnk_24 == 1) {
        flags = 0xc0000;
    }
    func_0214d168(&data_ov003_021d8a4c, 0, 0x60);
    if (request->mUnk_28 == 5) {
        data_ov003_021d8a4c.mUnk_00 = 1;
    } else if (request->mUnk_28 == 0xd) {
        data_ov003_021d8a4c.mUnk_00 = 2;
    } else if (request->mUnk_28 == 0x10) {
        data_ov003_021d8a4c.mUnk_00 = 3;
    } else {
        return -1;
    }
    data_ov003_021d8a4c.mUnk_01 = 0;
    func_0214d1fc(request->mUnk_2c, data_ov003_021d8a4c.mUnk_02, request->mUnk_28);
    func_ov000_021a6894();
    if (func_ov003_021baaac(NULL, request->mUnk_04, request->mUnk_00, 0x30bffe) != 0) {
        retries = 0;
        func_0200fb08(&timer);
        func_0200f950(&timer, 0x3fec42, (void (*)(void *)) func_ov003_021ba70c, (void *) 0x12);
        flags |= 0x30000;
        do {
            func_0200ea3c(&data_ov003_021d8a2c, &msg, 1);
            switch ((u32) msg) {
                case 0x12:
                    if (done == FALSE) {
                        running = FALSE;
                    }
                    break;
                case 5:
                    if (done == FALSE) {
                        func_0200f8b8(&timer);
                        if (func_ov003_021babc0(&data_ov003_021d8ac0, 1) != 1) {
                            running = FALSE;
                        } else {
                            func_ov003_021ba744(request, &data_ov003_021d8ac0);
                            if (func_ov003_021ba910(&data_ov003_021d8ac0, &data_ov003_021d8a4c, flags) == 0) {
                                running = FALSE;
                            } else {
                                done = TRUE;
                            }
                        }
                    }
                    break;
                case 0xa:
                    func_ov003_021ba744(request, &data_ov003_021d8ac0);
                    if (func_ov003_021ba910(&data_ov003_021d8ac0, &data_ov003_021d8a4c, flags) == 0) {
                        running = FALSE;
                    }
                    break;
                case 0xc:
                    result = 0;
                    running = FALSE;
                    break;
                case 0xd:
                    retries++;
                    if (retries < 3) {
                        if (func_ov003_021ba910(&data_ov003_021d8ac0, &data_ov003_021d8a4c, flags) == 0) {
                            running = FALSE;
                        }
                    } else {
                        running = FALSE;
                    }
                    break;
                case 4:
                case 8:
                case 0x13:
                    break;
                default:
                    running = FALSE;
                    break;
            }
        } while (running != FALSE);
        func_0200f8b8(&timer);
        while (func_0200ea3c(&data_ov003_021d8a2c, &msg, 0) == 1) {
        }
    }
    func_ov003_021ba734(out, &data_ov003_021d8ac0, result == 0 ? 1 : 0);
    return result;
}

void func_ov003_021ba1a8(u32 msec) {
    func_0200dc3c(msec);
}

int func_ov003_021ba18c(int state) {
    if (data_ov003_021d8a10 != NULL) {
        data_ov003_021d8a10(state);
    }
    return 0;
}

void *func_ov003_021ba178(u32 size) {
    return data_ov003_021d8a0c(size);
}

void func_ov003_021ba164(void *ptr) {
    data_ov003_021d8a18(ptr);
}

s32 func_ov003_021ba05c(Unk021b94c4 *req) {
    s32 status;
    s32 ret;
    if (req->mUnk_106 == 0 || req->mUnk_106 < -1 || req->mUnk_108 < -1 || req->mUnk_10a == 0 || req->mUnk_10a < -1 ||
        req->mUnk_10c < -1 || req->mUnk_10e < -1 || req->mUnk_004 == 0 || req->mUnk_004 > 0x100 ||
        req->mUnk_006[req->mUnk_004 - 1] != 0) {
        status = -1;
    } else {
        status = 0;
    }
    if (data_ov003_021d8a0c == NULL || data_ov003_021d8a18 == NULL) {
        status = -1;
    }
    if (status == -1) {
        req->mUnk_116 = 0xf;
        func_ov003_021b9518();
        return -1;
    }
    data_ov003_021d7c54 = func_ov003_021ba178(0x5f8);
    if (data_ov003_021d7c54 == NULL) {
        req->mUnk_116 = 0xf;
        func_ov003_021b9518();
        return -1;
    }
    func_ov003_021b9134(-1);
    ret = func_ov003_021b9570(req);
    func_ov003_021ba164(data_ov003_021d7c54);
    func_ov003_021b9518();
    if (data_ov003_021d6804 != -1) {
        func_ov003_021b7ce4(data_ov003_021d6804);
    }
    return ret;
}

s32 func_ov003_021b9570(Unk021b94c4 *req) {
    s16 timeout;
    s32 mode;
    s32 state;
    s32 addr;
    Unk021d7c54 *buffer;
    s32 scanResult;
    s32 result;
    Unk021d6808 scan = data_ov003_021d6808;
    Unk021d6808 limits = {0, 0};
    s32 value = 1;
    s32 attempts;
    s32 ret;
    u8 code;
    s16 cnt;
    s16 delay;
    Unk021b7cec src2;
    s32 srcLen;
    s32 received;
    Unk021b7ba0 set;
    Unk021b7d1c wait;
    Unk021b7cec info;
    Unk021b916c list[3];
    Unk021ba1b0 request;
    Unk021b86e4 buf;

    mode = 0;
    attempts = mode;
    addr = mode;
    func_ov003_021b7d84(list, 0, sizeof(list));
    scan.mUnk_00 = req->mUnk_106;
    if (scan.mUnk_00 == -1) {
        scan.mUnk_00 = 10;
    }
    limits.mUnk_00 = req->mUnk_10a;
    if (limits.mUnk_00 == -1) {
        limits.mUnk_00 = 10;
    }
    scan.mUnk_02 = req->mUnk_108;
    if (scan.mUnk_02 == -1) {
        scan.mUnk_02 = 100;
    }
    limits.mUnk_02 = req->mUnk_10c;
    if (limits.mUnk_02 == -1) {
        limits.mUnk_02 = 100;
    }
    timeout = req->mUnk_10e;
    if (timeout == -1) {
        timeout = 2000;
    }
    func_ov003_021b94c4(req);
    if ((data_ov003_021d7c6c.mUnk_08 & 1) != 1) {
        func_ov003_021b94b8(0x13);
        req->mUnk_116 = 0xf;
        func_ov003_021b9518();
        return -1;
    }

    cnt = 0;
    func_ov003_021b9134(0);
    delay = scan.mUnk_02;
    while (1) {
        if (data_ov003_021d7c44 != NULL) {
            func_ov003_021ba164(data_ov003_021d7c44);
            data_ov003_021d7c44 = NULL;
        }
        if (func_ov003_021ba394(&data_ov003_021d7c44) == -1) {
            req->mUnk_116 = 0xf;
            func_ov003_021b9518();
            return -1;
        }
        result = func_ov003_021b91f0(data_ov003_021d7c44);
        if (result == 4) {
            req->mUnk_116 = 2;
            func_ov003_021b9518();
            return -1;
        }
        if (result == 0) {
            break;
        }
        if (cnt >= scan.mUnk_00) {
            req->mUnk_116 = 1;
            func_ov003_021b9518();
            return -1;
        }
        func_ov003_021ba1a8(delay);
        cnt++;
    }

    func_ov003_021b9134(1);
    func_ov003_021b7d84(&request, 0, 0x3c);
    if (func_ov003_021b91a4(&request) != 0) {
        req->mUnk_116 = 0xf;
        func_ov003_021b9518();
        return -1;
    }
    data_ov003_021d7c4c = func_ov003_021ba178(0x58);
    if (data_ov003_021d7c4c == NULL) {
        req->mUnk_116 = 0xf;
        func_ov003_021b9518();
        return -1;
    }
    func_ov003_021b7d84(data_ov003_021d7c4c, 0, 0x58);
    cnt = 0;
    if (scan.mUnk_00 > 0) {
        do {
            result = func_ov003_021ba1b0(&request, data_ov003_021d7c4c);
            if (result == -1) {
                req->mUnk_116 = 0xf;
                func_ov003_021b9518();
                return -1;
            }
            if (result == 0) {
                /* repeated test of result, kept as a placeholder */
                if (result != 0 || data_ov003_021d7c4c->mUnk_00 == 1) {
                    break;
                }
            }
            func_ov003_021ba1a8(delay);
            cnt++;
        } while (cnt < scan.mUnk_00);
    }
    if (cnt == scan.mUnk_00) {
        req->mUnk_116 = 0xf;
        func_ov003_021b9518();
        return -1;
    }
    if (func_ov003_021b7df4(0xc0a80b65, 0xffffff00, 0xc0a80b65) != 0) {
        func_ov003_021b94b8(0xc);
        req->mUnk_116 = 0xf;
        func_ov003_021b9518();
        return -1;
    }
    func_ov003_021b9518();
    func_ov003_021b916c(3, list, req->mUnk_110);
    data_ov003_021d6804 = func_ov003_021b7cf8(2, 2, 0);
    if (data_ov003_021d6804 < 0) {
        req->mUnk_116 = 0xf;
        func_ov003_021b9518();
        return -1;
    }
    if (func_ov003_021b7d00(data_ov003_021d6804, 0xffff, 1, &value, 4) < 0) {
        func_ov003_021b94b8(0xb);
        req->mUnk_116 = 0xf;
        func_ov003_021b9518();
        return -1;
    }
    func_ov003_021b7d84(&info, 0, 8);
    info.mUnk_01 = 2;
    info.mUnk_04 = func_ov003_021b7cac(0xc0a80b65);
    info.mUnk_02 = func_ov003_021b7c94(0x5790);
    if (func_ov003_021b7cec(data_ov003_021d6804, &info, 8) < 0) {
        req->mUnk_116 = 0xf;
        func_ov003_021b9518();
        return -1;
    }

    while (1) {
        buffer = data_ov003_021d7c54;
        func_ov003_021b7d84(&buf, 0, 0x14);
        buf.mUnk_10 = 0xc0a80b65;
        buf.mUnk_00 = 0xc0a80b01;
        while (1) {
            if (mode == 1 && data_ov003_021d7c6c.mUnk_18 != 1) {
                if (data_ov003_021d6804 != -1) {
                    func_ov003_021b7ce4(data_ov003_021d6804);
                }
                data_ov003_021d6804 = -1;
                if (func_ov003_021b7dc8() != 0) {
                    req->mUnk_116 = 0xf;
                    func_ov003_021b9518();
                    return -1;
                }
                if (data_ov003_021d7c44 != NULL) {
                    func_ov003_021ba164(data_ov003_021d7c44);
                    data_ov003_021d7c44 = NULL;
                }
                data_ov003_021d7c44 = func_ov003_021ba178(0x58);
                if (data_ov003_021d7c44 == NULL) {
                    req->mUnk_116 = 0xf;
                    func_ov003_021b9518();
                    return -1;
                }
                while (1) {
                    scanResult = func_ov003_021ba394(&data_ov003_021d7c44);
                    if (scanResult == -1) {
                        req->mUnk_116 = 0xf;
                        func_ov003_021b9518();
                        return -1;
                    }
                    result = func_ov003_021b91f0(data_ov003_021d7c44);
                    if (result == 4) {
                        req->mUnk_116 = 2;
                        func_ov003_021b9518();
                        return -1;
                    }
                    if (result == 0) {
                        break;
                    }
                    if (cnt >= scan.mUnk_00) {
                        req->mUnk_116 = 1;
                        func_ov003_021b9518();
                        return -1;
                    }
                    func_ov003_021ba1a8(delay);
                    cnt++;
                }
                if (scanResult == -1) {
                    req->mUnk_116 = 0xf;
                    func_ov003_021b9518();
                    return -1;
                }
                data_ov003_021d7c4c = func_ov003_021ba178(0x58);
                if (data_ov003_021d7c4c == NULL) {
                    req->mUnk_116 = 0xf;
                    func_ov003_021b9518();
                    return -1;
                }
                func_ov003_021b7d84(data_ov003_021d7c4c, 0, 0x58);
                cnt = 0;
                if (scan.mUnk_00 > 0) {
                    do {
                        result = func_ov003_021ba1b0(&request, data_ov003_021d7c4c);
                        if (result == -1) {
                            req->mUnk_116 = 0xf;
                            func_ov003_021b9518();
                            return -1;
                        }
                        if (result == 0) {
                            /* repeated test of result, kept as a placeholder */
                            if (result != 0 || data_ov003_021d7c4c->mUnk_00 == 1) {
                                break;
                            }
                        }
                        func_ov003_021ba1a8(delay);
                        cnt++;
                    } while (cnt < scan.mUnk_00);
                }
                if (cnt == scan.mUnk_00) {
                    req->mUnk_116 = 0xf;
                    func_ov003_021b9518();
                    return -1;
                }
                addr = func_ov003_021b9550(data_ov003_021d7c6c.mUnk_10, data_ov003_021d7c6c.mUnk_14);
                if (func_ov003_021b7df4(addr, data_ov003_021d7c6c.mUnk_14, addr) != 0) {
                    func_ov003_021b94b8(0xc);
                    req->mUnk_116 = 0xf;
                    func_ov003_021b9518();
                    return -1;
                }
                data_ov003_021d7c6c.mUnk_18 = 1;
                func_ov003_021b9518();
                data_ov003_021d6804 = func_ov003_021b7cf8(2, 2, 0);
                if (data_ov003_021d6804 < 0) {
                    req->mUnk_116 = 0xf;
                    func_ov003_021b9518();
                    return -1;
                }
                if (func_ov003_021b7d00(data_ov003_021d6804, 0xffff, 1, &value, 4) < 0) {
                    func_ov003_021b94b8(0xb);
                    req->mUnk_116 = 0xf;
                    func_ov003_021b9518();
                    return -1;
                }
                func_ov003_021b7d84(&info, 0, 8);
                info.mUnk_01 = 2;
                info.mUnk_04 = func_ov003_021b7cac(addr);
                info.mUnk_02 = func_ov003_021b7c94(0x5790);
                if (func_ov003_021b7cec(data_ov003_021d6804, &info, 8) < 0) {
                    req->mUnk_116 = 0xf;
                    func_ov003_021b9518();
                    return -1;
                }
            }
            if (func_ov003_021b86e4(mode, &buf, list, data_ov003_021d6804) == -1) {
                func_ov003_021b94b8(mode + 0x1000);
                req->mUnk_116 = 0xf;
                func_ov003_021b9518();
                return -1;
            }
            func_ov003_021b7d84(buffer, 0, 0x5f8);
            func_ov003_021b7ba8(&set);
            func_ov003_021b7ba0(data_ov003_021d6804, &set);
            wait.mUnk_00 = timeout / 1000;
            wait.mUnk_04 = timeout % 1000 * 1000;
            if (func_ov003_021b7d1c(data_ov003_021d6804 + 1, &set, NULL, NULL, &wait) > 0) {
                break;
            }
            attempts++;
            if (attempts > limits.mUnk_00) {
                if (mode == 0) {
                    func_ov003_021b94b8(0xf);
                } else if (mode == 1) {
                    func_ov003_021b94b8(0x10);
                } else {
                    func_ov003_021b94b8(0x11);
                }
                ret = -1;
                goto cleanup;
            }
            func_ov003_021ba1a8(limits.mUnk_02);
        }
        srcLen = 8;
        received = func_ov003_021b7d68(data_ov003_021d6804, buffer->mUnk_0c, 0x5dc, 0, &src2, &srcLen);
        buffer->mUnk_00 = data_ov003_021d6804;
        buffer->mUnk_04 = func_ov003_021b7c44((u16) received);
        state = func_ov003_021b9078(mode, buffer, &attempts, list, data_ov003_021d6804);
        if (state == 0x64) {
            ret = 0;
            goto cleanup;
        }
        if (state == -1) {
            ret = -1;
            goto cleanup;
        }
        if (mode != state) {
            if (state == 2) {
                if (data_ov003_021d6804 != -1) {
                    func_ov003_021b7ce4(data_ov003_021d6804);
                }
                data_ov003_021d6804 = -1;
                if (func_ov003_021b7dc8() != 0) {
                    req->mUnk_116 = 0xf;
                    func_ov003_021b9518();
                    return -1;
                }
                cnt = 0;
                func_ov003_021b9134(4);
                while (1) {
                    if (data_ov003_021d7c44 != NULL) {
                        func_ov003_021ba164(data_ov003_021d7c44);
                        data_ov003_021d7c44 = NULL;
                    }
                    if (func_ov003_021ba394(&data_ov003_021d7c44) == -1) {
                        req->mUnk_116 = 0xf;
                        func_ov003_021b9518();
                        return -1;
                    }
                    result = func_ov003_021b91f0(data_ov003_021d7c44);
                    if (result == 4) {
                        req->mUnk_116 = 2;
                        func_ov003_021b9518();
                        return -1;
                    }
                    if (result == 0) {
                        break;
                    }
                    if (cnt >= scan.mUnk_00) {
                        req->mUnk_116 = 1;
                        func_ov003_021b9518();
                        return -1;
                    }
                    func_ov003_021ba1a8(delay);
                    cnt++;
                }
                data_ov003_021d7c4c = func_ov003_021ba178(0x58);
                if (data_ov003_021d7c4c == NULL) {
                    req->mUnk_116 = 0xf;
                    func_ov003_021b9518();
                    return -1;
                }
                func_ov003_021b7d84(data_ov003_021d7c4c, 0, 0x58);
                cnt = 0;
                if (scan.mUnk_00 > 0) {
                    do {
                        result = func_ov003_021ba1b0(&request, data_ov003_021d7c4c);
                        if (result == -1) {
                            req->mUnk_116 = 0xf;
                            func_ov003_021b9518();
                            return -1;
                        }
                        if (result == 0) {
                            /* repeated test of result, kept as a placeholder */
                            if (result != 0 || data_ov003_021d7c4c->mUnk_00 == 1) {
                                break;
                            }
                        }
                        func_ov003_021ba1a8(delay);
                        cnt++;
                    } while (cnt < scan.mUnk_00);
                }
                if (cnt == scan.mUnk_00) {
                    req->mUnk_116 = 0xf;
                    func_ov003_021b9518();
                    return -1;
                }
                if (func_ov003_021b7df4(addr, data_ov003_021d7c6c.mUnk_14, addr) != 0) {
                    func_ov003_021b94b8(0xc);
                    req->mUnk_116 = 0xf;
                    func_ov003_021b9518();
                    return -1;
                }
                func_ov003_021b9518();
                data_ov003_021d6804 = func_ov003_021b7cf8(2, 2, 0);
                if (data_ov003_021d6804 < 0) {
                    req->mUnk_116 = 0xf;
                    func_ov003_021b9518();
                    return -1;
                }
                if (func_ov003_021b7d00(data_ov003_021d6804, 0xffff, 1, &value, 4) < 0) {
                    func_ov003_021b94b8(0xb);
                    req->mUnk_116 = 0xf;
                    func_ov003_021b9518();
                    return -1;
                }
                func_ov003_021b7d84(&info, 0, 8);
                info.mUnk_01 = 2;
                info.mUnk_04 = func_ov003_021b7cac(addr);
                info.mUnk_02 = func_ov003_021b7c94(0x5790);
                if (func_ov003_021b7cec(data_ov003_021d6804, &info, 8) < 0) {
                    req->mUnk_116 = 0xf;
                    func_ov003_021b9518();
                    return -1;
                }
            }
            mode = state;
            continue;
        }
        mode = state;
        if (attempts > limits.mUnk_00) {
            if (state == 0) {
                func_ov003_021b94b8(0xf);
            } else if (state == 1) {
                func_ov003_021b94b8(0x10);
            } else {
                func_ov003_021b94b8(0x11);
            }
            ret = -1;
            goto cleanup;
        }
        func_ov003_021ba1a8(limits.mUnk_02);
        continue;
    }

cleanup:
    if (data_ov003_021d6804 != -1) {
        func_ov003_021b7ce4(data_ov003_021d6804);
    }
    data_ov003_021d6804 = -1;
    if (func_ov003_021b7dc8() != 0) {
        req->mUnk_116 = 0xf;
        func_ov003_021b9518();
        return -1;
    }
    if (ret != 0) {
        switch (func_ov003_021b94ac()) {
            case 0xf:
                code = 3;
                break;
            case 0x10:
                code = 4;
                break;
            case 0x11:
                code = 5;
                break;
            case 0x14:
                code = 7;
                break;
            case 0x15:
                code = 8;
                break;
            default:
                code = 0xf;
                break;
        }
        req->mUnk_116 = code;
        func_ov003_021b9518();
        return -1;
    }
    if (func_ov003_021b929c(req) != 0) {
        req->mUnk_116 = 6;
        func_ov003_021b9518();
        return -1;
    }
    return 0;
}

u32 func_ov003_021b9550(u32 addr, u32 mask) {
    u32 base = addr & mask;
    u32 next = (addr & ~mask) + 1;
    if ((base | next) < (base | ~mask)) {
        return base | next;
    }
    return base | 1;
}

void func_ov003_021b9518(void) {
    if (data_ov003_021d7c4c != NULL) {
        func_ov003_021ba164(data_ov003_021d7c4c);
        data_ov003_021d7c4c = NULL;
    }
    if (data_ov003_021d7c44 != NULL) {
        func_ov003_021ba164(data_ov003_021d7c44);
        data_ov003_021d7c44 = NULL;
    }
}

void func_ov003_021b94c4(Unk021b94c4 *req) {
    func_ov003_021b7d84(data_ov003_021d7c58, 0, 8);
    data_ov003_021d7c50 = 1;
    func_ov003_021b7d84(&data_ov003_021d7c6c, 0, 0x1c);
    data_ov003_021d7c6c.mUnk_00 = req->mUnk_006;
    data_ov003_021d7c6c.mUnk_04 = req->mUnk_004;
    data_ov003_021d7c6c.mUnk_08 = req->mUnk_000 & 0xf;
    data_ov003_021d7c6c.mUnk_19 = req->mUnk_002;
    data_ov003_021d7c6c.mUnk_0c = 0;
    data_ov003_021d7c6c.mUnk_10 = 0xc0a80b01;
    data_ov003_021d7c6c.mUnk_18 = 0;
}

void func_ov003_021b94b8(s32 code) {
    data_ov003_021d7c50 = code;
}
