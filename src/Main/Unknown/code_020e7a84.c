#include "Main/Unknown/code_02046ad0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d6dc0.h"
#include "Main/Unknown/code_020e7a84.h"

#include "Main/Unknown/code_020e8ac8.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0215f000.h"
#include "Main/Unknown/code_020e73b4.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_0210b000.h"
#include "code_0212c6ac.h"
#include "code_0212df7c.h"
#include "code_02147288.h"
#include "01/code_02187d14.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"

// non-matching: same instructions and data references. The data_0217b878 store comes after the products here (zero reg
// reused after the call; the original stores it right after data_0217b9c0.z, but writing it before the `if` scores
// lower) and data_0217b9a8.z stays in r5 where the original keeps it in lr, so the umull pair is lr/ip there
void func_020e8790(void) {
    Unk020e6514 *p;
    s32 t;

    // Stored through a pointer cast: as a plain store the compiler folds the test of data_0217b890 below,
    // which the original keeps.
    *(s32 *) &data_0217b890 = 2;
    data_0217b8e4 = 1;
    data_0217b8c4 = 0;
    data_0217b900 = 0;
    data_0217b8ac = 0;
    data_0217b8e8 = 0;
    if (data_0217b890 != 4) {
        p = data_0217baec[data_0217b890].mUnk_00;
        if (p != NULL) {
            p->mUnk_00c = 0;
            p->mUnk_1c[p->mUnk_1a]->mUnk_00 = p->mUnk_00c;
        }
        p = data_0217baf0[data_0217b890].mUnk_00;
        if (p != NULL) {
            p->mUnk_00c = 0;
            p->mUnk_1c[p->mUnk_1a]->mUnk_00 = p->mUnk_00c;
        }
    }
    data_0217b9cc[0] = &data_0217bb7c;
    data_0217b9cc[1] = data_0217bb28;
    data_0217b9cc[2] = &data_0217bb34;
    data_0217b9cc[3] = &data_0217bb40;
    func_020d7d18(&data_0217bb88.mUnk_00, 0, data_0217b9cc, 0x1ec);
    t = (s32) (((s64) data_0217b9a8.z * data_0215f4b4[1]) >> 12) -
        (s32) (((s64) data_0217b9a8.x * data_0215f4b4[0]) >> 12);
    data_0217b8b4 = 0x8000;
    data_0217b9c0.z = t;
    if (t > 0) {
        data_0217b9c0.z = t * 3;
    }
    data_0217b878 = 0;
    data_0217b9c0.x = (s32) (((s64) data_0217b9a8.z * data_0215f4b4[0]) >> 12) +
                      (s32) (((s64) data_0217b9a8.x * data_0215f4b4[1]) >> 12);
    data_0217b9c0.y = data_0217b9a8.y;
    func_02147288(&data_0217b9c0, &data_0217bab8, &data_0217b9c0);
    data_0217b90c = data_0217b9c0;
    data_0217b918 = data_0217b90c;
    data_0217b924.x = 0;
    data_0217b924.y = 0;
    data_0217b924.z = 0;
    data_0217b9b4.x = 0;
    data_0217b8b8 = 0;
    data_0217b9b4.y = 0;
    data_0217b9b4.z = 0;
    data_0217b8cc = 0;
    data_0217b870 = 0;
    data_0217b88c = 0;
    data_0217b8ec = 0;
    data_0217b8f0 = 1;
    data_0217b8bc = 1;
    data_0217b93c = data_0217b918;
    data_0217b99c = data_0217b93c;
    data_0217b930 = data_0217b99c;
    data_0217b948 = data_0217b930;
    data_0217b894 = 0;
}

void func_020e84b0(void) {
    Unk020e6514 *p;
    s32 n;
    u32 a;
    s32 i;
    s32 s;
    s32 c;
    s32 t;
    u32 *q;
    s32 b;
    enum { K0 } d;

    p = data_0217baf0[data_0217b890].mUnk_00;
    d = p->mUnk_00c;
    n = data_0217b8b4;
    a = ((u32) d << 4) >> 16;
    if (n > 0 && n < 0x10000) {
        i = (n >> 4) << 1;
        s = data_0215d4b4[i];
        c = data_0215d4b4[i + 1];
        b = (s32) (((s64) data_0217b9a8.z * c) >> 12);
        t = b - (s32) (((s64) data_0217b9a8.x * s) >> 12);
        data_0217b9c0.z = t;
        if (t > 0) {
            data_0217b9c0.z = t * 3;
        }
        data_0217b9c0.x = (s32) (((s64) data_0217b9a8.z * s) >> 12) + (s32) (((s64) data_0217b9a8.x * c) >> 12);
        data_0217b9c0.y = data_0217b9a8.y;
        func_02147288(&data_0217b9c0, &data_0217bab8, &data_0217b9c0);
        if (data_0217b8f8 != 0) {
            data_0217b8b4 -= 0xf0;
        } else {
            data_0217b8b4 += 0xf0;
        }
        data_0217b908 = data_021593bc.x;
        data_0217b894 = 1;
    } else {
        data_0217b894 = 0;
        func_020ea1d4(&data_0217b9a8, &data_02159404, &data_02159410);
        if (data_0217b8f0 == 0 && data_0217b8bc == 0) {
            func_02046bcc(&data_0217b9ec, 1);
        }
    }
    if (a == 0xa || a == 0x28) {
        q = (u32 *) func_02108e6c(4);
        data_0217b9dc.mUnk_0c = func_020d4ef4(&data_0217b930);
        func_0212c6f0((Unk0212c400 **) q, 0);
        func_0210b760(&data_0217b9dc, (Unk0212c400 **) q);
    }
    if (func_0203c880(data_0217b888) != 0 || (data_0217b8c8->mUnk_48 & 0x800) != 0) {
        func_02046bcc(&data_0217b9ec, 5);
        return;
    }
    if ((data_0217561c->mUnk_000[data_0217b888].mUnk_44 & 4) == 0) {
        if (++data_0217b8c4 > 0x3c) {
            func_02046bcc(&data_0217b9ec, 5);
            return;
        }
    } else {
        data_0217b8c4 = 0;
    }
    if ((data_0217b8c8->mUnk_48 & 1) == 0) {
        return;
    }
    func_02046bcc(&data_0217b9ec, 5);
}

void func_020e8418(void) {
    Vec3 v;

    if (data_0217b87c != data_0217b884) {
        data_0217bae8[0].mUnk_0c->mUnk_18 = data_0217b87c - 2;
    }
    data_0217b8b4 = 0;
    v = data_0217b978;
    v.x += data_0217b88c;
    func_02147288(&v, &data_0217bab8, &data_0217b9c0);
}

void func_020e8368(void) {
    Vec3 v;

    v = data_0217b978;
    v.x += data_0217b88c;
    func_02147288(&v, &data_0217bab8, &data_0217b9c0);
    if (++data_0217b8b4 > data_0217b880 || (data_0217b8c8->mUnk_48 & 0x800) != 0) {
        func_02046bcc(&data_0217b9ec, 5);
    }
}

void func_020e82dc(void) {
    data_0217b9cc[0] = &data_0217bb7c;
    data_0217b9cc[1] = data_0217bb28;
    data_0217b9cc[2] = &data_0217bb34;
    data_0217b9cc[3] = &data_0217bb40;
    func_020d7d18(&data_0217bb88.mUnk_00, 0, data_0217b9cc, 0x1ec);
    data_0217b878 = 0;
    func_020ea1d4(&data_0217b990, &data_021593e0, &data_021593ec);
}

void func_020e827c(void) {
    func_020ea1d4(&data_0217b990, &data_021593e0, &data_021593ec);
    if ((data_0217b8c8->mUnk_48 & 0x800) == 0) {
        return;
    }
    func_02046bcc(&data_0217b9ec, 5);
}

void func_020e7fa8(void) {
    Unk020e6514 *p;
    u32 *q;

    data_0217b8c4 = 0;
    // Stored through a pointer cast: as a plain store the compiler folds the test of data_0217b890 below,
    // which the original keeps.
    *(s32 *) &data_0217b890 = 4;
    data_0217b8e4 = 1;
    data_0217b874 = 0x1f;
    data_0217b900 = 0;
    data_0217b8ac = 0;
    data_0217b8e8 = 0;
    if (data_0217b890 != 4) {
        p = data_0217baec[data_0217b890].mUnk_00;
        if (p != NULL) {
            p->mUnk_00c = 0;
            p->mUnk_1c[p->mUnk_1a]->mUnk_00 = p->mUnk_00c;
        }
        p = data_0217baf0[data_0217b890].mUnk_00;
        if (p != NULL) {
            p->mUnk_00c = 0;
            p->mUnk_1c[p->mUnk_1a]->mUnk_00 = p->mUnk_00c;
        }
    }
    data_0217ba2c.mUnk_18 = 1;
    data_0217b8b4 = 0;
    if (func_0203c5e4() != 0) {
        q = (u32 *) func_020e6b48();
        ((Unk02012f58 *) q)->mUnk_00[3] = data_0217b954;
        func_02147288(&data_0217b960, (Unk02012f58 *) q, &data_0217b9c0);
    } else {
        func_02147288(&data_0217b960, &data_0217bab8, &data_0217b9c0);
    }
    data_0217b90c = data_0217b9c0;
    data_0217b918 = data_0217b90c;
    data_0217b93c = data_0217b918;
    data_0217b99c = data_0217b93c;
    data_0217b930 = data_0217b99c;
    data_0217b9b4.x = 0;
    data_0217b9b4.y = 0;
    data_0217b9b4.z = 0;
    data_0217b924.x = 0;
    data_0217b870 = 0;
    data_0217b8b8 = 0;
    data_0217b924.y = 0;
    data_0217b924.z = 0;
    data_0217b88c = 0;
    data_0217b8cc = 0;
    data_0217b8ec = 0;
    data_0217b948 = data_0217b930;
    data_0217b8f0 = 1;
    data_0217b8bc = 1;
    data_0217b894 = 0;
    func_0212c6f0((void *) func_02108e6c(4), 1);
    q = (u32 *) func_02108e6c(4);
    if ((data_0217c780 & 1) == 0) {
        return;
    }
    if (data_0217d084.mUnk_0c == 0) {
        return;
    }
    if (q[0] != 0) {
        func_0212c6f0((Unk0212c400 **) q, 0);
    }
    if (q[0] != 0) {
        func_0212c6f0((Unk0212c400 **) q, 0);
    }
    func_0212ecc0(q, 0, 0x102);
}

void func_020e7ed0(void) {
    void *p;

    if (data_0217b8b4 == 0) {
        data_0217b954 = data_0217b8c8->mUnk_80;
    } else if (--data_0217b8b4 <= 0) {
        data_0217ba2c.mUnk_18 = 0;
        func_02046bcc(&data_0217b9ec, 5);
    }
    if (func_0203c5e4() != 0) {
        p = (void *) func_020e6b48();
        ((Unk02012f58 *) p)->mUnk_00[3] = data_0217b954;
        func_02147288(&data_0217b960, (Unk02012f58 *) p, &data_0217b9c0);
    } else {
        func_02147288(&data_0217b960, &data_0217bab8, &data_0217b9c0);
    }
}

void func_020e7e58(void) {
    s32 a;

    data_0217b8e4 = 1;
    func_02147288(&data_0217b9c0, &data_0217ba88, &data_0217b984);
    data_0217b89c = 0;
    a = 0;
    if ((data_0217b8c8->mUnk_48 & 1) == 0) {
        a = 0xffffbccd;
    }
    data_0217b8d8 = a;
}

void func_020e7d90(void) {
    s32 a;

    func_02147288(&data_0217b984, &data_0217bab8, &data_0217b9c0);
    if ((data_0217b8c8->mUnk_48 & 1) != 0) {
        a = 0x2000;
    } else {
        a = 0x800;
    }
    data_0217b8d8 += a;
    data_0217b89c += data_0217b8d8;
    data_0217b9c0.y += data_0217b89c;
    if (data_0217b89c <= 0x5dc000) {
        return;
    }
    if (data_0217b8f0 != 0) {
        return;
    }
    func_0212c6f0((void *) func_02108e6c(4), 1);
    func_02046bcc(&data_0217b9ec, 0);
}

void func_020e7b7c(void) {
    Unk020e6514 *p;
    s32 b;
    s32 a;
    s32 i;
    s32 t;

    data_0217b8e4 = 1;
    data_0217b8e8 = 0;
    if (data_0217b890 != 4) {
        p = data_0217baec[data_0217b890].mUnk_00;
        if (p != NULL) {
            p->mUnk_00c = 0;
            p->mUnk_1c[p->mUnk_1a]->mUnk_00 = p->mUnk_00c;
        }
        p = data_0217baf0[data_0217b890].mUnk_00;
        if (p != NULL) {
            p->mUnk_00c = 0;
            p->mUnk_1c[p->mUnk_1a]->mUnk_00 = p->mUnk_00c;
        }
    }
    func_02147288(&data_0217b9c0, &data_0217ba88, &data_0217b96c);
    for (i = 0, b = 0, a = 0; i < 0x1e; i++) {
        t = (b > -0x3000) ? -0x3000 : b;
        a -= t;
        b += 0x19a;
    }
    data_0217b9c0.y += a;
    data_0217b90c = data_0217b9c0;
    data_0217b918 = data_0217b90c;
    data_0217b93c = data_0217b918;
    data_0217b898 = a;
    data_0217b99c = data_0217b93c;
    data_0217b8d0 = b;
    data_0217b930 = data_0217b99c;
    data_0217b9b4.x = 0;
    data_0217b9b4.y = 0;
    data_0217b9b4.z = 0;
    data_0217b924.x = 0;
    data_0217b924.y = 0;
    data_0217b924.z = 0;
    data_0217b870 = 0;
    data_0217b8b8 = 0;
    data_0217b88c = 0;
    data_0217b8cc = 0;
    data_0217b8ec = 0;
    data_0217b948 = data_0217b930;
    data_0217b8f0 = 1;
    data_0217b8bc = 1;
    data_0217b894 = 0;
}

void func_020e7a84(void) {
    s32 a;
    s32 b;

    func_02147288(&data_0217b96c, &data_0217bab8, &data_0217b9c0);
    data_0217b8d0 -= 0x19a;
    a = data_0217b8d0;
    if (a > -0x3000) {
        a = -0x3000;
    }
    b = data_0217b898 + a;
    data_0217b898 = b;
    data_0217b9c0.y += b;
    if (b <= 0) {
        switch (data_0217b890) {
            case 0:
            case 1:
                func_02046bcc(&data_0217b9ec, 2);
                break;
            case 3:
                func_02046bcc(&data_0217b9ec, 3);
                break;
            default:
                func_02046bcc(&data_0217b9ec, 5);
                break;
        }
    }
    data_0217b908 = data_021593bc.x;
}
