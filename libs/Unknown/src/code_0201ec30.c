#include "code_0201ec30.h"

#include "code_0200eddc.h"
#include "Main/Unknown/unk_02173000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_020204b4.h"
#include "code_0214eef0.h"

u8 data_02161ad8 = 1;

u8 data_02173288;
s32 data_021732a8;
s32 data_0217328c;
s32 data_021732a4;
Unk02173290 *data_02173290;
s32 data_02173294;
s32 data_02173298;
u8 data_021732a0[4];
s32 data_0217329c;

s32 func_02020498(s32 a) {
    if (a > 0x7f && a <= 0xfe) {
        return a - 0x7f;
    }
    return 0x7f - a;
}

void func_02020430(Unk02173290 *a) {
    s32 i;

    data_02173290 = a;
    data_02173294 = 1;
    data_02173288 = 0;
    data_02173298 = 0;
    for (i = 0; i < 4; i++) {
        data_021732a0[i] = 0;
    }
}

void func_0202041c(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_02173294;
    value1 = 1u;
    *(u32 *) ((value0) + (0)) = value1;
}

void func_020203e4(void) {
    if (data_02173294 == 0) {
        return;
    }
    data_02173294 = 0;
    data_02173288 = 0;
    data_02173298 = 0;
}

void func_020203d4(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = (u32) &data_02161ad8;
    *(u8 *) ((value1) + (0)) = (u8) value0;
}

u8 func_0201ec30(void) {
    u8 *p;
    s32 n;
    s32 prev;
    s32 mind;
    s32 last;
    s32 cnt3;
    s32 lim;
    s32 len;
    u16 pos;
    u8 *buf;
    s32 cnt;
    s32 maxv;
    s32 maxd;
    s32 cnt2;
    s32 i;
    s32 d;
    s32 v;
    s32 j;
    s32 k;
    s32 q;
    s32 ok;
    s32 m;

    cnt = 0;
    n = 0;
    len = data_02173290->mUnk_08;
    last = 9999;
    maxv = 0;
    lim = 2;
    prev = 0;
    cnt3 = 0;
    maxd = 0;
    cnt2 = 0;
    if (data_02173294 == 0) {
        return 0;
    }
    mind = len;
    p = (u8 *) func_0214f1a0();
    buf = data_02173290->mUnk_04;
    pos = p - buf;
    if (pos >= len / 8) {
        i = pos - len / 8;
        func_0200ee3c(buf + i, pos);
        for (; i < pos; i++) {
            if (data_02173290->mUnk_00 == 0) {
                v = func_02020498(func_020204b4(buf[i]));
            } else {
                v = (s8) buf[i];
                if (v < 0) {
                    v = -v;
                }
            }
            if (v >= 125) {
                cnt2++;
            }
            if (v > maxv) {
                maxv = v;
            }
        }
    } else {
        i = len - (len / 8 - pos);
        func_0200ee3c(buf + i, (u16) len);
        for (; i < len; i++) {
            if (data_02173290->mUnk_00 == 0) {
                v = func_02020498(func_020204b4(buf[i]));
            } else {
                v = (s8) buf[i];
                if (v < 0) {
                    v = -v;
                }
            }
            if (v >= 125) {
                cnt2++;
            }
            if (v > maxv) {
                maxv = v;
            }
        }
        func_0200ee3c(buf, pos);
        for (i = 0; i < pos; i++) {
            if (data_02173290->mUnk_00 == 0) {
                v = func_02020498(func_020204b4(buf[i]));
            } else {
                v = (s8) buf[i];
                if (v < 0) {
                    v = -v;
                }
            }
            if (v >= 125) {
                cnt2++;
            }
            if (v > maxv) {
                maxv = v;
            }
        }
    }
    for (j = 0; j < 4; j++) {
        data_021732a0[j] = 0;
    }
    for (i = pos; i < len; i++) {
        if (data_02173290->mUnk_00 != 0) {
            v = (s8) buf[i] + 127;
        } else {
            v = func_020204b4(buf[i]);
        }
        if (maxv > 30) {
            if (v > 127 && prev <= 127) {
                cnt3++;
                if (last == 9999 || cnt3 < 3) {
                    cnt++;
                    last = i;
                } else {
                    d = i - last;
                    if (d > maxd) {
                        maxd = d;
                    }
                    if (d < mind) {
                        mind = d;
                    }
                    cnt++;
                    last = i;
                    for (j = 0; j < 4; j++) {
                        if (j == 4) {
                            if (d > j * 25) {
                                data_021732a0[j]++;
                                j = 4;
                            }
                        } else if (d > j * 25 && d <= (j + 1) * 25) {
                            data_021732a0[j]++;
                            j = 4;
                        }
                    }
                }
            }
            prev = v;
        }
    }
    cnt3 = last - len;
    for (i = 0; i < pos; i++) {
        if (data_02173290->mUnk_00 != 0) {
            v = (s8) buf[i] + 127;
        } else {
            v = func_020204b4(buf[i]);
        }
        if (maxv > 30) {
            if (v > 127 && prev <= 127) {
                d = i - cnt3;
                if (d > maxd) {
                    maxd = d;
                }
                if (d < mind) {
                    mind = d;
                }
                cnt++;
                cnt3 = i;
                for (k = 0; k < 4; k++) {
                    if (k == 4) {
                        if (d > k * 25) {
                            data_021732a0[k]++;
                            k = 4;
                        }
                    } else if (d > k * 25 && d <= (k + 1) * 25) {
                        data_021732a0[k]++;
                        k = 4;
                    }
                }
            }
            prev = v;
        }
    }
    q = 0x400 / (len / 10);
    cnt2 = cnt2 * q / 10;
    m = (cnt << 3) * q / 10;
    for (i = 0; i < 4; i++) {
        data_021732a0[i] = data_021732a0[i] * q / 10;
    }
    data_0217328c = maxv;
    data_0217329c = m;
    data_021732a4 = cnt2;
    data_021732a8 = maxd;
    ok = 0;
    data_02173288 = 0;
    if (m > 99) {
        if (data_02173290->mUnk_00 == 0) {
            func_02020498(func_020204b4(*p));
        }
        n = m;
        if (m > 1883) {
            n = 1883;
        }
        switch (data_02161ad8) {
            case 2:
                if (m >= 100 && m < 200) {
                    if (maxv >= 70 && data_021732a0[0] <= 9 && data_021732a0[0] >= 5 && data_021732a0[1] <= 14 &&
                        data_021732a0[1] >= 3 && data_021732a0[2] <= 7 && data_021732a0[2] >= 1 &&
                        data_021732a0[3] <= 7 && data_021732a0[3] >= 1 && maxd <= 600 && maxd >= 80) {
                        ok = 1;
                    }
                } else if (m >= 200 && m < 300) {
                    if (maxv >= 90 && data_021732a0[0] <= 32 && data_021732a0[0] >= 14 && data_021732a0[1] <= 6 &&
                        data_021732a0[1] >= 2 && data_021732a0[2] <= 5 && data_021732a0[2] >= 1 &&
                        data_021732a0[3] <= 4 && maxd <= 500 && maxd >= 79) {
                        ok = 1;
                    }
                } else if (m >= 300 && m < 400) {
                    if (maxv >= 100 && data_021732a0[0] <= 40 && data_021732a0[0] >= 24 && data_021732a0[1] <= 19 &&
                        data_021732a0[1] >= 2 && data_021732a0[2] <= 4 && data_021732a0[2] >= 1 &&
                        data_021732a0[3] <= 2 && maxd <= 400 && maxd >= 65) {
                        ok = 1;
                    }
                } else if (m >= 400 && m < 500) {
                    if (maxv == 127 && data_021732a0[0] <= 89 && data_021732a0[0] >= 31 && data_021732a0[1] <= 18 &&
                        data_021732a0[1] >= 1 && data_021732a0[2] <= 4 && data_021732a0[3] <= 1 && maxd <= 400 &&
                        maxd >= 35 && cnt2 >= 7) {
                        ok = 1;
                    }
                } else if (m >= 500 && m < 600) {
                    if (maxv == 127 && data_021732a0[0] <= 109 && data_021732a0[0] >= 41 && data_021732a0[1] <= 14 &&
                        data_021732a0[1] >= 1 && data_021732a0[2] <= 1 && data_021732a0[3] <= 1 && maxd <= 400 &&
                        maxd >= 30 && cnt2 >= 5) {
                        ok = 1;
                    }
                } else if (m >= 600 && m < 700) {
                    if (maxv == 127 && data_021732a0[0] <= 130 && data_021732a0[0] >= 66 && data_021732a0[1] <= 14 &&
                        data_021732a0[1] >= 1 && data_021732a0[2] == 0 && data_021732a0[3] == 0 && maxd <= 400 &&
                        maxd >= 30 && cnt2 >= 6) {
                        ok = 1;
                    }
                } else if (m >= 700 && m < 800) {
                    if (maxv == 127 && data_021732a0[0] <= 142 && data_021732a0[0] >= 66 && data_021732a0[1] <= 14 &&
                        data_021732a0[1] >= 1 && data_021732a0[2] == 0 && data_021732a0[3] == 0 && maxd <= 200 &&
                        maxd >= 15 && cnt2 >= 7) {
                        ok = 1;
                    }
                } else if (m >= 800 && m < 900) {
                    if (maxv == 127 && data_021732a0[0] <= 150 && data_021732a0[0] >= 76 && data_021732a0[1] <= 9 &&
                        data_021732a0[1] >= 1 && data_021732a0[2] == 0 && data_021732a0[3] == 0 && maxd <= 100 &&
                        maxd >= 15 && cnt2 >= 7) {
                        ok = 1;
                    }
                } else if (m >= 900 && m < 1100) {
                    if (maxv == 127 && data_021732a0[0] <= 160 && data_021732a0[0] >= 90 && data_021732a0[1] <= 7 &&
                        data_021732a0[2] == 0 && data_021732a0[3] == 0 && maxd <= 100 && maxd >= 15 && cnt2 >= 8) {
                        ok = 1;
                    }
                } else if (m >= 1100 && m < 1300) {
                    if (maxv == 127 && data_021732a0[0] < 170 && data_021732a0[0] >= 120 && data_021732a0[1] <= 4 &&
                        data_021732a0[2] < 2 && data_021732a0[3] == 0 && maxd <= 100 && maxd >= 13 && cnt2 >= 9) {
                        ok = 1;
                    }
                } else if (m >= 1300 && m < 1500) {
                    if (maxv == 127 && data_021732a0[0] <= 190 && data_021732a0[0] >= 150 && data_021732a0[1] <= 2 &&
                        data_021732a0[2] == 0 && data_021732a0[3] == 0 && maxd <= 100 && maxd >= 13 && cnt2 >= 15) {
                        ok = 1;
                    }
                } else if (m >= 1500 && m < 1883) {
                    if (maxv == 127 && data_021732a0[0] >= 180 && data_021732a0[1] <= 2 && data_021732a0[2] == 0 &&
                        data_021732a0[3] == 0 && maxd <= 100 && maxd >= 9 && cnt2 >= 28) {
                        ok = 1;
                    }
                } else {
                    if (maxv == 127 && data_021732a0[1] == 0 && data_021732a0[2] == 0 && data_021732a0[3] == 0 &&
                        maxd <= 100 && maxd >= 5 && cnt2 >= 28) {
                        ok = 1;
                    }
                }
                break;
            case 1:
                if (m >= 100 && m < 200) {
                    if (maxv >= 70 && data_021732a0[0] <= 9 && data_021732a0[0] >= 1 && data_021732a0[1] <= 14 &&
                        data_021732a0[1] >= 1 && data_021732a0[2] <= 7 && data_021732a0[3] <= 7 && maxd <= 600 &&
                        maxd >= 80) {
                        ok = 1;
                    }
                } else if (m >= 200 && m < 300) {
                    if (maxv >= 90 && data_021732a0[0] <= 32 && data_021732a0[0] >= 9 && data_021732a0[1] <= 14 &&
                        data_021732a0[1] >= 2 && data_021732a0[2] <= 6 && data_021732a0[2] >= 1 &&
                        data_021732a0[3] <= 4 && maxd <= 500 && maxd >= 79) {
                        ok = 1;
                    }
                } else if (m >= 300 && m < 400) {
                    if (maxv >= 100 && data_021732a0[0] <= 40 && data_021732a0[0] >= 20 && data_021732a0[1] <= 19 &&
                        data_021732a0[1] >= 2 && data_021732a0[2] <= 5 && data_021732a0[2] >= 1 &&
                        data_021732a0[3] <= 3 && maxd <= 400 && maxd >= 61) {
                        ok = 1;
                    }
                } else if (m >= 400 && m < 500) {
                    if (maxv >= 115 && data_021732a0[0] <= 89 && data_021732a0[0] >= 22 && data_021732a0[1] <= 18 &&
                        data_021732a0[1] >= 6 && data_021732a0[2] <= 4 && data_021732a0[3] <= 3 && maxd <= 400 &&
                        maxd >= 35) {
                        ok = 1;
                    }
                } else if (m >= 500 && m < 600) {
                    if (maxv == 127 && data_021732a0[0] <= 109 && data_021732a0[0] >= 41 && data_021732a0[1] <= 14 &&
                        data_021732a0[1] >= 1 && data_021732a0[2] <= 4 && data_021732a0[3] <= 1 && maxd <= 400 &&
                        maxd >= 30 && cnt2 >= 1) {
                        ok = 1;
                    }
                } else if (m >= 600 && m < 700) {
                    if (maxv == 127 && data_021732a0[0] <= 130 && data_021732a0[0] >= 61 && data_021732a0[1] <= 14 &&
                        data_021732a0[1] >= 1 && data_021732a0[2] <= 3 && data_021732a0[3] == 0 && maxd <= 400 &&
                        maxd >= 30 && cnt2 >= 6) {
                        ok = 1;
                    }
                } else if (m >= 700 && m < 800) {
                    if (maxv == 127 && data_021732a0[0] <= 142 && data_021732a0[0] >= 66 && data_021732a0[1] <= 14 &&
                        data_021732a0[1] >= 1 && data_021732a0[2] <= 1 && data_021732a0[3] == 0 && maxd <= 200 &&
                        maxd >= 15 && cnt2 >= 7) {
                        ok = 1;
                    }
                } else if (m >= 800 && m < 900) {
                    if (maxv == 127 && data_021732a0[0] <= 150 && data_021732a0[0] >= 76 && data_021732a0[1] <= 9 &&
                        data_021732a0[1] >= 1 && data_021732a0[2] <= 1 && data_021732a0[3] == 0 && maxd <= 125 &&
                        maxd >= 15 && cnt2 >= 7) {
                        ok = 1;
                    }
                } else if (m >= 900 && m < 1100) {
                    if (maxv == 127 && data_021732a0[0] <= 160 && data_021732a0[0] >= 90 && data_021732a0[1] <= 7 &&
                        data_021732a0[2] <= 1 && data_021732a0[3] == 0 && maxd <= 115 && maxd >= 20 && cnt2 >= 8) {
                        ok = 1;
                    }
                } else if (m >= 1100 && m < 1300) {
                    if (maxv == 127 && data_021732a0[0] < 170 && data_021732a0[0] >= 120 && data_021732a0[1] <= 4 &&
                        data_021732a0[2] <= 1 && data_021732a0[3] == 0 && maxd <= 100 && maxd >= 32 && cnt2 >= 9) {
                        ok = 1;
                    }
                } else if (m >= 1300 && m < 1500) {
                    if (maxv == 127 && data_021732a0[0] <= 190 && data_021732a0[0] >= 150 && data_021732a0[1] <= 2 &&
                        data_021732a0[2] == 0 && data_021732a0[3] == 0 && maxd <= 100 && maxd >= 32 && cnt2 >= 15) {
                        ok = 1;
                    }
                } else if (m >= 1500 && m < 1883) {
                    if (maxv == 127 && data_021732a0[0] >= 180 && data_021732a0[1] <= 2 && data_021732a0[2] == 0 &&
                        data_021732a0[3] == 0 && maxd <= 100 && maxd >= 28 && cnt2 >= 28) {
                        ok = 1;
                    }
                } else {
                    if (maxv == 127 && data_021732a0[1] == 0 && data_021732a0[2] == 0 && data_021732a0[3] == 0 &&
                        maxd <= 100 && maxd >= 29 && cnt2 >= 28) {
                        ok = 1;
                    }
                }
                break;
            case 0:
                lim = 1;
                if (m >= 100 && m < 200) {
                    if (maxv >= 30 && data_021732a0[0] <= 13 && data_021732a0[0] >= 1 && data_021732a0[1] <= 14 &&
                        data_021732a0[1] >= 1 && data_021732a0[2] <= 7 && data_021732a0[3] <= 7 && maxd <= 600 &&
                        maxd >= 80) {
                        ok = 1;
                    }
                } else if (m >= 200 && m < 300) {
                    if (maxv >= 40 && data_021732a0[0] <= 20 && data_021732a0[0] >= 6 && data_021732a0[1] <= 17 &&
                        data_021732a0[1] >= 1 && data_021732a0[2] <= 6 && data_021732a0[3] <= 4 && maxd <= 500 &&
                        maxd >= 79) {
                        ok = 1;
                    }
                } else if (m >= 300 && m < 400) {
                    if (maxv >= 50 && data_021732a0[0] <= 40 && data_021732a0[0] >= 20 && data_021732a0[1] <= 19 &&
                        data_021732a0[1] >= 1 && data_021732a0[2] <= 5 && data_021732a0[3] <= 3 && maxd <= 400 &&
                        maxd >= 61) {
                        ok = 1;
                    }
                } else if (m >= 400 && m < 500) {
                    if (maxv >= 80 && data_021732a0[0] <= 89 && data_021732a0[0] >= 22 && data_021732a0[1] <= 18 &&
                        data_021732a0[1] >= 6 && data_021732a0[2] <= 4 && data_021732a0[3] <= 3 && maxd <= 400 &&
                        maxd >= 35) {
                        ok = 1;
                    }
                } else if (m >= 500 && m < 600) {
                    if (maxv == 100 && data_021732a0[0] <= 109 && data_021732a0[0] >= 41 && data_021732a0[1] <= 14 &&
                        data_021732a0[1] >= 1 && data_021732a0[2] <= 4 && data_021732a0[3] <= 1 && maxd <= 400 &&
                        maxd >= 30 && cnt2 >= 1) {
                        ok = 1;
                    }
                } else if (m >= 600 && m < 700) {
                    if (maxv == 127 && data_021732a0[0] <= 130 && data_021732a0[0] >= 61 && data_021732a0[1] <= 14 &&
                        data_021732a0[1] >= 1 && data_021732a0[2] <= 3 && data_021732a0[3] == 0 && maxd <= 400 &&
                        maxd >= 30 && cnt2 >= 6) {
                        ok = 1;
                    }
                } else if (m >= 700 && m < 800) {
                    if (maxv == 127 && data_021732a0[0] <= 142 && data_021732a0[0] >= 66 && data_021732a0[1] <= 14 &&
                        data_021732a0[1] >= 1 && data_021732a0[2] <= 1 && data_021732a0[3] == 0 && maxd <= 200 &&
                        maxd >= 15 && cnt2 >= 7) {
                        ok = 1;
                    }
                } else if (m >= 800 && m < 900) {
                    if (maxv == 127 && data_021732a0[0] <= 150 && data_021732a0[0] >= 76 && data_021732a0[1] <= 9 &&
                        data_021732a0[1] >= 1 && data_021732a0[2] <= 1 && data_021732a0[3] == 0 && maxd <= 125 &&
                        maxd >= 15 && cnt2 >= 7) {
                        ok = 1;
                    }
                } else if (m >= 900 && m < 1100) {
                    if (maxv == 127 && data_021732a0[0] <= 160 && data_021732a0[0] >= 90 && data_021732a0[1] <= 7 &&
                        data_021732a0[2] <= 1 && data_021732a0[3] == 0 && maxd <= 115 && maxd >= 20 && cnt2 >= 8) {
                        ok = 1;
                    }
                } else if (m >= 1100 && m < 1300) {
                    if (maxv == 127 && data_021732a0[0] < 170 && data_021732a0[0] >= 120 && data_021732a0[1] <= 4 &&
                        data_021732a0[2] <= 1 && data_021732a0[3] == 0 && maxd <= 100 && maxd >= 32 && cnt2 >= 9) {
                        ok = 1;
                    }
                } else if (m >= 1300 && m < 1500) {
                    if (maxv == 127 && data_021732a0[0] <= 190 && data_021732a0[0] >= 150 && data_021732a0[1] <= 2 &&
                        data_021732a0[2] == 0 && data_021732a0[3] == 0 && maxd <= 100 && maxd >= 32 && cnt2 >= 15) {
                        ok = 1;
                    }
                } else if (m >= 1500 && m < 1883) {
                    if (maxv == 127 && data_021732a0[0] >= 180 && data_021732a0[1] <= 2 && data_021732a0[2] == 0 &&
                        data_021732a0[3] == 0 && maxd <= 100 && maxd >= 28 && cnt2 >= 28) {
                        ok = 1;
                    }
                } else {
                    if (maxv == 127 && data_021732a0[1] == 0 && data_021732a0[2] == 0 && data_021732a0[3] == 0 &&
                        maxd <= 100 && maxd >= 29 && cnt2 >= 28) {
                        ok = 1;
                    }
                }
                break;
        }
    }
    if (ok == 1) {
        if (data_02173298 >= lim) {
            if (n >= 1883) {
                data_02173288 = 255;
            } else {
                data_02173288 = n / 7 - 13;
            }
        } else {
            data_02173298++;
        }
    } else {
        data_02173298 = 0;
    }
    return data_02173288;
}
