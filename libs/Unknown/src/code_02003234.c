#include "code_02003234.h"
#include "code_02004d80.h"
#include "code_0200dc3c.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_0214d000.h"

s32 FileCompareNamesNoCase(const u8 *a, const u8 *b, u32 c) {
    u32 i;
    u32 x;
    u32 y;

    for (i = 0; i < c; i++) {
        x = a[i] - 0x41;
        y = b[i] - 0x41;
        if (x <= 0x19) {
            x += 0x20;
        }
        if (y <= 0x19) {
            y += 0x20;
        }
        if (x != y) {
            return x - y;
        }
    }
    return 0;
}

void FileReadTableBytes(Unk02003ad8 *a, void *b, u32 c) {
    Unk02003a6c *o;
    s32 r;
    u32 s;

    o = a->mUnk_00;
    o->mUnk_1c |= 0x200;
    r = o->mUnk_50(o, b, a->mUnk_04, c);
    switch (r) {
        case 0:
        case 1:
            o->mUnk_1c &= ~0x200;
            break;
        case 6:
            s = func_0200fca0();
            if (o->mUnk_1c & 0x200) {
                do {
                    func_0200e01c(&o->mUnk_0c);
                } while (o->mUnk_1c & 0x200);
            }
            func_0200fcb4(s);
            break;
    }
    a->mUnk_04 += c;
}

s32 FileEnterDirectoryById(Unk02003024 *a, u32 b) {
    a->mUnk_0c |= 4;
    a->mUnk_30.h.mUnk_00 = a->mUnk_08;
    a->mUnk_30.w.mUnk_08 = 0;
    a->mUnk_30.h.mUnk_06 = 0;
    a->mUnk_30.h.mUnk_04 = b;
    return FileDispatchCommand(a, 2);
}

s32 FileReadViaArchive(Unk02003024 *a) {
    Unk02003a6c *o;
    void *buf;
    u32 pos;
    u32 n;

    pos = a->mUnk_2c;
    n = a->mUnk_30.p.mUnk_08;
    o = a->mUnk_08;
    buf = a->mUnk_30.p.mUnk_00;
    a->mUnk_2c = pos + n;
    return o->mUnk_48(o, buf, pos, n);
}

s32 FileWriteViaArchive(Unk02003024 *a) {
    Unk02003a6c *o;
    void *buf;
    u32 pos;
    u32 n;

    pos = a->mUnk_2c;
    n = a->mUnk_30.p.mUnk_08;
    o = a->mUnk_08;
    buf = a->mUnk_30.p.mUnk_00;
    a->mUnk_2c = pos + n;
    return o->mUnk_4c(o, buf, pos, n);
}

s32 FileReadDirTableEntry(Unk02003024 *a) {
    Unk02003a6c *o;
    Unk02003024U *q;
    Unk0200399c v;
    Unk02003ad8 c;

    o = a->mUnk_08;
    q = &a->mUnk_30;
    c.mUnk_00 = o;
    c.mUnk_04 = o->mUnk_34 + q->h.mUnk_04 * 8;
    FileReadTableBytes(&c, &v, 8);
    a->mUnk_20 = *q;
    if (q->h.mUnk_06 == 0 && q->h.mUnk_08 == 0) {
        a->mUnk_20.h.mUnk_06 = v.mUnk_04;
        a->mUnk_20.h.mUnk_08 = o->mUnk_34 + v.mUnk_00;
    }
    a->mUnk_2c = v.mUnk_06 & 0xfff;
    return 0;
}

s32 FileReadDirEntry(Unk02003024 *a) {
    Unk02003670 *e;
    u8 b;
    u16 h;
    Unk02003ad8 c;

    e = a->mUnk_30.e.mUnk_00;
    c.mUnk_00 = a->mUnk_08;
    c.mUnk_04 = a->mUnk_20.w.mUnk_08;
    FileReadTableBytes(&c, &b, 1);
    e->mUnk_10 = b & 0x7f;
    e->mUnk_0c = (b >> 7) & 1;
    if (e->mUnk_10 == 0) {
        return 1;
    }
    if (a->mUnk_30.w.mUnk_04 != 0) {
        c.mUnk_04 += e->mUnk_10;
    } else {
        FileReadTableBytes(&c, e->mUnk_14, e->mUnk_10);
        e->mUnk_14[e->mUnk_10] = 0;
    }
    if (e->mUnk_0c != 0) {
        FileReadTableBytes(&c, &h, 2);
        e->mUnk_00.h.mUnk_00 = a->mUnk_08;
        e->mUnk_00.h.mUnk_04 = h & 0xfff;
        e->mUnk_00.h.mUnk_06 = 0;
        e->mUnk_00.w.mUnk_08 = 0;
    } else {
        e->mUnk_00.h.mUnk_00 = a->mUnk_08;
        e->mUnk_00.w.mUnk_04 = a->mUnk_20.h.mUnk_06;
        a->mUnk_20.h.mUnk_06++;
    }
    a->mUnk_20.w.mUnk_08 = c.mUnk_04;
    return 0;
}

static inline int func_02003670_inline(u32 c) {
    int r;

    r = 0;
    if (c != 0 && c != 0x2f && c != 0x5c) {
        r = 1;
    }
    return r;
}

s32 FileWalkPath(Unk02003024 *a) {
    u32 f;
    Unk02003670 e;
    const u8 *p;
    u32 d;
    s32 n;
    u32 c;
    Unk02003024U *q;

    f = a->mUnk_40;
    p = a->mUnk_3c;
    FileDispatchCommand(a, 2);
    c = *p;
    if (c != 0) {
        do {
            for (n = 0; d = p[n], func_02003670_inline(d); n++) {
            }
            if (d != 0 || f != 0) {
                d = 1;
            }
            if (n == 0) {
                return 1;
            }
            if (c == 0x2e) {
                if (n == 1) {
                    p += 1;
                    goto next;
                }
                if ((n == 2) & (p[1] == 0x2e)) {
                    if (a->mUnk_20.h.mUnk_04 != 0) {
                        FileEnterDirectoryById(a, a->mUnk_2c);
                    }
                    p += 2;
                    goto next;
                }
            }
            if (n > 0x7f) {
                return 1;
            }
            a->mUnk_30.e.mUnk_00 = &e;
            a->mUnk_30.w.mUnk_04 = 0;
            do {
                if (FileDispatchCommand(a, 3) != 0) {
                    return 1;
                }
            } while (d != e.mUnk_0c || n != e.mUnk_10 || FileCompareNamesNoCase(p, e.mUnk_14, n) != 0);
            if (d != 0) {
                a->mUnk_30 = e.mUnk_00;
                p += n;
                FileDispatchCommand(a, 2);
            } else {
                if (f != 0) {
                    return 1;
                }
                q = a->mUnk_44;
                q->d.mUnk_00 = e.mUnk_00.d.mUnk_00;
                return 0;
            }
        next:
            p += (*p != 0) ? 1 : 0;
            c = *p;
        } while (c != 0);
    }
    if (f == 0) {
        return 1;
    }
    *a->mUnk_44 = a->mUnk_20;
    return 0;
}

s32 FileBuildPathString(Unk02003024 *a) {
    Unk02003a6c *o;
    Unk02003670 e;
    Unk02003024 c;
    Unk02003024U *p;
    u32 k;
    u32 id;
    u32 i;
    u32 limit;
    u32 t;
    u32 total;
    u8 *buf;
    u32 len;
    u32 off;
    u32 n;

    o = a->mUnk_08;
    p = &a->mUnk_30;
    FS_InitFile(&c);
    c.mUnk_08 = a->mUnk_08;
    if (((a->mUnk_0c & 0x20) ? 1 : 0) != 0) {
        k = a->mUnk_20.h.mUnk_04;
        id = 0x10000;
    } else {
        id = a->mUnk_20.w.mUnk_00;
        if (p->b.mUnk_08 != 0) {
            k = p->b.mUnk_0a;
        } else {
            i = 0;
            limit = 0;
            k = 0x10000;
            do {
                FileEnterDirectoryById(&c, i);
                if (i == 0) {
                    limit = c.mUnk_2c;
                }
                c.mUnk_30.e.mUnk_00 = &e;
                c.mUnk_30.w.mUnk_04 = 1;
                if (FileDispatchCommand(&c, 3) == 0) {
                    do {
                        if (e.mUnk_0c == 0 && e.mUnk_00.w.mUnk_04 == id) {
                            k = c.mUnk_20.h.mUnk_04;
                            break;
                        }
                    } while (FileDispatchCommand(&c, 3) == 0);
                }
                if (k != 0x10000) {
                    break;
                }
                i++;
            } while (i < limit);
        }
    }
    if (k == 0x10000) {
        p->b.mUnk_08 = 0;
        return 1;
    }
    if (p->b.mUnk_08 == 0) {
        total = 0;
        if (o->mUnk_00 <= 0xff) {
            total += 1;
        } else if (o->mUnk_00 <= 0xff00) {
            total += 2;
        } else {
            total += 3;
        }
        total += 2;
        if (id != 0x10000) {
            total += e.mUnk_10;
        }
        t = k;
        if (t != 0) {
            FileEnterDirectoryById(&c, t);
            do {
                FileEnterDirectoryById(&c, c.mUnk_2c);
                c.mUnk_30.e.mUnk_00 = &e;
                c.mUnk_30.w.mUnk_04 = 1;
                if (FileDispatchCommand(&c, 3) == 0) {
                    do {
                        if (e.mUnk_0c != 0 && e.mUnk_00.h.mUnk_04 == t) {
                            total += e.mUnk_10 + 1;
                            break;
                        }
                    } while (FileDispatchCommand(&c, 3) == 0);
                }
                t = c.mUnk_20.h.mUnk_04;
            } while (t != 0);
        }
        p->b.mUnk_08 = total + 1;
        p->b.mUnk_0a = k;
    }
    buf = p->b.mUnk_00;
    if (buf == 0) {
        return 0;
    }
    len = p->b.mUnk_08;
    if (p->b.mUnk_04 < len) {
        return 1;
    }
    off = 0;
    if (o->mUnk_00 <= 0xff) {
        n = 1;
    } else if (o->mUnk_00 <= 0xff00) {
        n = 2;
    } else {
        n = 3;
    }
    func_0214d1fc(o, buf, n);
    off += n;
    func_0214d1fc(":/", buf + off, 2);
    FileEnterDirectoryById(&c, k);
    if (id != 0x10000) {
        c.mUnk_30.e.mUnk_00 = &e;
        c.mUnk_30.w.mUnk_04 = 0;
        if (FileDispatchCommand(&c, 3) == 0) {
            do {
                if (e.mUnk_0c == 0 && e.mUnk_00.w.mUnk_04 == id) {
                    break;
                }
            } while (FileDispatchCommand(&c, 3) == 0);
        }
        n = e.mUnk_10 + 1;
        func_0214d1fc(e.mUnk_14, buf + len - n, n);
        len -= n;
    } else {
        *(buf + len - 1) = 0;
        len--;
    }
    if (k != 0) {
        do {
            FileEnterDirectoryById(&c, c.mUnk_2c);
            c.mUnk_30.e.mUnk_00 = &e;
            c.mUnk_30.w.mUnk_04 = 0;
            *(buf + len - 1) = 0x2f;
            len--;
            if (FileDispatchCommand(&c, 3) == 0) {
                do {
                    if (e.mUnk_0c != 0 && e.mUnk_00.h.mUnk_04 == k) {
                        n = e.mUnk_10;
                        func_0214d1fc(e.mUnk_14, buf + len - n, n);
                        len -= n;
                        break;
                    }
                } while (FileDispatchCommand(&c, 3) == 0);
            }
            k = c.mUnk_20.h.mUnk_04;
        } while (k != 0);
    }
    return 0;
}

s32 FileOpenFromTableEntry(Unk02003024 *a) {
    Unk02003a6c *o;
    u32 n;
    u32 off;
    Unk02003234 v;
    Unk02003ad8 c;

    o = a->mUnk_08;
    n = a->mUnk_30.w.mUnk_04;
    off = n << 3;
    if (off >= o->mUnk_30) {
        return 1;
    }
    c.mUnk_00 = o;
    c.mUnk_04 = o->mUnk_2c + off;
    FileReadTableBytes(&c, &v, 8);
    a->mUnk_30.w.mUnk_00 = v.mUnk_00;
    a->mUnk_30.w.mUnk_04 = v.mUnk_04;
    a->mUnk_30.w.mUnk_08 = n;
    return FileDispatchCommand(a, 7);
}
