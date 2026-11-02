#include "ITCM/code_01ffdee4.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "ITCM/code_01fff000.h"

#include "Main/Unknown/code_020e0680.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/unk_0216b000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02147cd8.h"

int func_01ffdee4(void *a, u32 *b, u32 c, int r, u32 fl, short e, void *f, void *g, int *h, u32 *o, u32 *j, int *k,
                  u16 *l, u32 *m) {
    u16 *pl;
    Unk0217b614_08 *ta;
    s64 ss;
    Vec3 *tb;
    UnkVec16 *tc;
    u16 hw;
    s64 qq;
    s64 tq;
    Unk0217b614_08 tr;
    Vec3 pa;
    Vec3 pb;
    Vec3 ua;
    Vec3 ub;
    BOOL rv = FALSE;
    Vec3 uc = {0, 0, 0};
    BOOL fa = f != NULL || g != NULL || h != NULL;
    u32 ra = 0;
    Unk020e0764 wa = data_0216b8c4;
    Unk020e0764 wb = data_0216b8ec;
    Vec3 ca = {0, 0, 0};
    Vec3 cb = {0, 0, 0};
    Vec3 cc = {0, 0, 0};
    Vec3 cd = {0, 0, 0};
    Vec3 vt;
    Vec3 n[4];
    Vec3 ud;
    Unk0217b614 *kp;
    u32 x;
    u32 y;
    u32 z;
    u32 sh;
    u8 *p;
    s32 v;
    u16 ix;
    s32 pe;
    s32 d0;
    s32 d1;
    s32 d2;
    s32 d3;
    u16 at;
    s32 dt;
    u32 bt;
    s32 i;
    s32 ct;
    void *ob;
    u32 bi;

    if (j != NULL) {
        ud.x = 0;
        ud.z = 0;
        ud.y = r * 2;
    }
    data_027e0060 = 0;
    kp = &gCourseCollision;
    pa = *(Vec3 *) a;
    if (b != NULL) {
        pb = *(Vec3 *) b;
    }
    x = (pa.x - kp->mUnk_14) >> 12;
    ss = (s64) r * r;
    if (x & kp->mUnk_20) {
        return 0;
    }
    y = (pa.y - kp->mUnk_18) >> 12;
    if (y & kp->mUnk_24) {
        return 0;
    }
    z = (pa.z - kp->mUnk_1c) >> 12;
    if (z & kp->mUnk_28) {
        return 0;
    }
    sh = kp->mUnk_2c;
    v = ((z >> sh) << kp->mUnk_34) | ((y >> sh) << kp->mUnk_30) | (x >> sh);
    p = kp->mUnk_0c;
    v = ((s32 *) p)[v];
    while (v >= 0) {
        p += v;
        sh--;
        v = ((s32 *) p)[((x >> sh) & 1) | ((((z >> sh) & 1) << 2) | (((y >> sh) & 1) << 1))];
    }
    p += v & 0x7fffffff;
    ta = kp->mUnk_08;
    tb = kp->mUnk_00;
    tc = kp->mUnk_04;
    pl = (u16 *) p;
    while ((ix = *++pl) != 0) {
        tr = ta[ix];
        vt = tb[tr.mUnk_04];
        func_021484d0(&pa, &vt, &ua);
        n[3].x = tc[tr.mUnk_0c].x;
        n[3].y = tc[tr.mUnk_0c].y;
        n[3].z = tc[tr.mUnk_0c].z;
        dt = func_02039828(&ua, &n[3]);
        if (dt < -r) {
            continue;
        }
        d3 = dt - tr.mUnk_00;
        if (d3 >= r) {
            continue;
        }
        n[1].x = tc[tr.mUnk_08].x;
        n[1].y = tc[tr.mUnk_08].y;
        n[1].z = tc[tr.mUnk_08].z;
        d1 = func_02039828(&ua, &n[1]);
        if (d1 >= r) {
            continue;
        }
        n[2].x = tc[tr.mUnk_0a].x;
        n[2].y = tc[tr.mUnk_0a].y;
        n[2].z = tc[tr.mUnk_0a].z;
        d2 = func_02039828(&ua, &n[2]);
        if (d2 >= r) {
            continue;
        }
        n[0].x = tc[tr.mUnk_06].x;
        n[0].y = tc[tr.mUnk_06].y;
        n[0].z = tc[tr.mUnk_06].z;
        d0 = func_02039828(&ua, &n[0]);
        pe = r - d0;
        if (pe >= 0 && pe <= 0x1e000) {
            at = tr.mUnk_0e;
            if (at & 0x2010) {
                if ((fl & 4) && (at & 0x2000)) {
                    continue;
                }
                if ((fl & 1) && (at & 0x10)) {
                    continue;
                }
            }
            if ((fl & 0x10) && (at & 0xa000)) {
                continue;
            }
            uc.y = -(s32) (((s64) d0 * n[0].y) >> 12);
            uc.x = -(s32) (((s64) d0 * n[0].x) >> 12);
            uc.z = -(s32) (((s64) d0 * n[0].z) >> 12);
            v = 1;
            if (d1 > d2) {
                if (d1 > d3) {
                    goto la;
                } else {
                    goto lc;
                }
            } else {
                if (d2 > d3) {
                    goto lb;
                } else {
                    goto lc;
                }
            }
        la:
            if (d1 <= 0) {
                goto lm;
            }
            if (d0 < 0) {
                if (b == NULL) {
                    continue;
                }
                func_021484d0(&pb, &vt, &ub);
                if (func_02039828(&ub, &n[0]) < 0) {
                    continue;
                }
                if (func_02039828(&ub, &n[1]) > 0) {
                    continue;
                }
            }
            if (d2 > d3) {
                dt = func_02039828(&n[1], &n[2]);
                if ((s32) (((s64) dt * d1) >> 12) > d2) {
                    goto ld;
                } else {
                    goto lg;
                }
            } else {
                dt = func_02039828(&n[1], &n[3]);
                if ((s32) (((s64) dt * d1) >> 12) > d3) {
                    goto ld;
                } else {
                    goto li;
                }
            }
        lb:
            if (d2 <= 0) {
                goto lm;
            }
            if (d0 < 0) {
                if (b == NULL) {
                    continue;
                }
                func_021484d0(&pb, &vt, &ub);
                if (func_02039828(&ub, &n[0]) < 0) {
                    continue;
                }
                if (func_02039828(&ub, &n[2]) > 0) {
                    continue;
                }
            }
            if (d3 > d1) {
                dt = func_02039828(&n[2], &n[3]);
                if ((s32) (((s64) dt * d2) >> 12) > d3) {
                    goto le;
                } else {
                    goto lh;
                }
            } else {
                dt = func_02039828(&n[2], &n[1]);
                if ((s32) (((s64) dt * d2) >> 12) > d1) {
                    goto le;
                } else {
                    goto lg;
                }
            }
        lc:
            if (d3 <= 0) {
                goto lm;
            }
            if (d0 < 0) {
                if (b == NULL) {
                    continue;
                }
                func_021484d0(&pb, &vt, &ub);
                if (func_02039828(&ub, &n[0]) < 0) {
                    continue;
                }
                if (func_02039828(&ub, &n[3]) > tr.mUnk_00) {
                    continue;
                }
            }
            if (d1 > d2) {
                dt = func_02039828(&n[3], &n[1]);
                if ((s32) (((s64) dt * d3) >> 12) > d1) {
                    goto lf;
                } else {
                    goto li;
                }
            } else {
                dt = func_02039828(&n[3], &n[2]);
                if ((s32) (((s64) dt * d3) >> 12) > d2) {
                    goto lf;
                } else {
                    goto lh;
                }
            }
        ld:
            qq = ss - (s64) d1 * d1;
            if (n[1].y > 0x424 || n[1].y < -0x424) {
                v = 0;
            }
            if (j != NULL) {
                func_02147fd8(-d1, &n[1], &uc, &uc);
            }
            goto lk;
        le:
            qq = ss - (s64) d2 * d2;
            if (n[2].y > 0x424 || n[2].y < -0x424) {
                v = 0;
            }
            if (j != NULL) {
                func_02147fd8(-d2, &n[2], &uc, &uc);
            }
            goto lk;
        lf:
            qq = ss - (s64) d3 * d3;
            if (n[3].y > 0x424 || n[3].y < -0x424) {
                v = 0;
            }
            if (j != NULL) {
                func_02147fd8(-d3, &n[3], &uc, &uc);
            }
            goto lk;
        lg:
            func_01fff434(dt, d2, d1, &ua, &n[1], &n[2], &qq);
            goto lj;
        lh:
            func_01fff434(dt, d3, d2, &ua, &n[2], &n[3], &qq);
            goto lj;
        li:
            func_01fff434(dt, d1, d3, &ua, &n[3], &n[1], &qq);
        lj:
            qq = ss - qq;
            if (qq <= 0) {
                continue;
            }
            if (j != NULL) {
                func_021484d0(&uc, &ua, &uc);
            }
            v = 0;
        lk:
            tq = qq;
            *(vu16 *) 0x40002b0 = 1;
            *(vs64 *) 0x40002b8 = tq;
            while (*(vu16 *) 0x40002b0 & 0x8000) {
            }
            pe = *(vs32 *) 0x40002b4 - d0;
            if (pe < 0) {
                continue;
            }
            goto ln;
        lm:
            if (d0 < 0 && b != NULL) {
                func_021484d0(&pb, &vt, &ub);
                if (func_02039828(&ub, &n[0]) < 0) {
                    if (fl & 0x20) {
                        continue;
                    }
                    if (func_02039828(&ub, &n[1]) > 0) {
                        continue;
                    }
                    if (func_02039828(&ub, &n[2]) > 0) {
                        continue;
                    }
                    if (func_02039828(&ub, &n[3]) > tr.mUnk_00) {
                        continue;
                    }
                }
            }
            v = 0;
        ln:
            bt = 1 << ((at & 0x1f00) >> 8);
            bt |= 1 << (((at & 0xc) >> 2) + 0x1a);
            bt |= (at & 2) << 0x17;
            if (b != NULL) {
                func_021484d0(&pb, &vt, &ub);
                dt = func_02039828(&ub, &n[0]);
                if (dt < 0) {
                    if (v && (bt & 0x214300) && c != 0) {
                        ua.x = (s32) (((s64) pe * n[0].x) >> 2);
                        ua.z = (s32) (((s64) pe * n[0].z) >> 2);
                        if (ua.x > cc.x) {
                            cc.x = ua.x;
                        } else if (ua.x < cd.x) {
                            cd.x = ua.x;
                        }
                        if (ua.z > cc.z) {
                            cc.z = ua.z;
                        } else if (ua.z < cd.z) {
                            cd.z = ua.z;
                        }
                    }
                    if (fl & 0x3b) {
                        continue;
                    }
                    if (dt < -0xa000) {
                        continue;
                    }
                }
                func_021484d0(&pa, &pb, &ub);
                if (func_02039828(&ub, &n[0]) > 0x333) {
                    if (v && (bt & 0x214300) && c != 0) {
                        ua.x = (s32) (((s64) pe * n[0].x) >> 2);
                        ua.z = (s32) (((s64) pe * n[0].z) >> 2);
                        if (ua.x > cc.x) {
                            cc.x = ua.x;
                        } else if (ua.x < cd.x) {
                            cd.x = ua.x;
                        }
                        if (ua.z > cc.z) {
                            cc.z = ua.z;
                        } else if (ua.z < cd.z) {
                            cd.z = ua.z;
                        }
                    }
                    continue;
                }
            }
            if ((fl & 2) && (bt & 0x200)) {
                continue;
            }
            if (j != NULL && uc.y < ud.y) {
                ud = uc;
            }
            if (fa) {
                uc.x = (s32) (((s64) pe * n[0].x) >> 2);
                uc.y = (s32) (((s64) pe * n[0].y) >> 2);
                uc.z = (s32) (((s64) pe * n[0].z) >> 2);
                if (bt & 0x1e34ef) {
                    if (uc.x > wa.mUnk_00) {
                        wa.mUnk_00 = uc.x;
                    } else if (uc.x < wa.mUnk_0c) {
                        wa.mUnk_0c = uc.x;
                    }
                    if (uc.y > wa.mUnk_04) {
                        wa.mUnk_04 = uc.y;
                    } else if (uc.y < wa.mUnk_10) {
                        wa.mUnk_10 = uc.y;
                    }
                    if (uc.z > wa.mUnk_08) {
                        wa.mUnk_08 = uc.z;
                    } else if (uc.z < wa.mUnk_14) {
                        wa.mUnk_14 = uc.z;
                    }
                    if (g != NULL && pe >= wa.mUnk_18) {
                        wa.mUnk_18 = pe;
                        wa.mUnk_1c.x = n[0].x;
                        wa.mUnk_1c.y = n[0].y;
                        wa.mUnk_1c.z = n[0].z;
                    }
                } else if (bt & 0x214300) {
                    if (bt & 0x10000) {
                        bt |= data_02156904;
                        if (uc.x > ca.x) {
                            ca.x = uc.x;
                        } else if (uc.x < cb.x) {
                            cb.x = uc.x;
                        }
                        if (uc.y > ca.y) {
                            ca.y = uc.y;
                        } else if (uc.y < cb.y) {
                            cb.y = uc.y;
                        }
                        if (uc.z > ca.z) {
                            ca.z = uc.z;
                        } else if (uc.z < cb.z) {
                            cb.z = uc.z;
                        }
                    } else {
                        if (uc.x > wb.mUnk_00) {
                            wb.mUnk_00 = uc.x;
                        } else if (uc.x < wb.mUnk_0c) {
                            wb.mUnk_0c = uc.x;
                        }
                        if (uc.y > wb.mUnk_04) {
                            wb.mUnk_04 = uc.y;
                        } else if (uc.y < wb.mUnk_10) {
                            wb.mUnk_10 = uc.y;
                        }
                        if (uc.z > wb.mUnk_08) {
                            wb.mUnk_08 = uc.z;
                        } else if (uc.z < wb.mUnk_14) {
                            wb.mUnk_14 = uc.z;
                        }
                    }
                    if (h != NULL && pe >= wb.mUnk_18) {
                        wb.mUnk_18 = pe;
                        wb.mUnk_1c.x = n[0].x;
                        wb.mUnk_1c.y = n[0].y;
                        wb.mUnk_1c.z = n[0].z;
                    }
                    if (c != 0) {
                        if (((s32 *) &uc)[0] > cc.x) {
                            cc.x = ((s32 *) &uc)[0];
                        } else if (((s32 *) &uc)[0] < cd.x) {
                            cd.x = ((s32 *) &uc)[0];
                        }
                        if (((s32 *) &uc)[2] > cc.z) {
                            cc.z = ((s32 *) &uc)[2];
                        } else if (((s32 *) &uc)[2] < cd.z) {
                            cd.z = ((s32 *) &uc)[2];
                        }
                    }
                }
            }
            ra |= data_02156908;
            ra |= bt;
            if (data_027e0060 == 16) {
                data_027e0060--;
            }
            data_027e0084[data_027e0060] = bt;
            rv = TRUE;
            data_027e0064[data_027e0060] = at;
            data_027e0060++;
        }
    }
    if (k != NULL) {
        ((Vec3 *) k)->x = 0;
        ((Vec3 *) k)->y = 0;
        ((Vec3 *) k)->z = 0;
    }
    if (l != NULL) {
        *l = 0;
    }
    if (m != NULL) {
        *(void ***) m = data_0217b5d0;
        data_0217b5d0[1] = NULL;
        data_0217b5d0[0] = NULL;
    }
    if (data_0217b610 != 0 && e != -2) {
        ct = 0;
        if (e == -1) {
            func_020d5180(a, r, 0x1000);
        } else {
            func_01ffd900(e, 0x1000);
        }
        for (i = 0; i < data_0217b5a8; i++) {
            ob = data_0217b5c4[i];
            if (func_020e1d10(ob, (Vec3 *) a, r, fl, &wa, &wb, j != NULL ? &ud : 0, &hw, (Vec3 *) k, l)) {
                ra |= data_0215690c;
                ra |= 1 << hw;
                if (data_027e0060 == 16) {
                    data_027e0060--;
                }
                bi = 1 << hw;
                data_027e0084[data_027e0060] = bi;
                data_027e0064[data_027e0060] = hw << 8;
                data_027e0060++;
                if (m != NULL) {
                    if (bi & 0x1e34ef) {
                        data_0217b5d0[ct++] = data_0217b5d0[0];
                        data_0217b5d0[0] = ob;
                    } else {
                        data_0217b5d0[ct++] = ob;
                    }
                    data_0217b5d0[ct] = NULL;
                    if (ct >= 15) {
                        ct--;
                    }
                }
                rv = TRUE;
            }
        }
    }
    if (rv == FALSE) {
        return rv;
    }
    if (g != NULL) {
        *(Vec3 *) g = wa.mUnk_1c;
    }
    if (h != NULL) {
        *(Vec3 *) h = wb.mUnk_1c;
    }
    if (j != NULL) {
        *(Vec3 *) j = ud;
    }
    if (f != NULL) {
        uc.y = wa.mUnk_04 > wb.mUnk_04 ? wa.mUnk_04 : wb.mUnk_04;
        uc.y += wa.mUnk_10 < wb.mUnk_10 ? wa.mUnk_10 : wb.mUnk_10;
        if (ra & 0x10000) {
            if (j != NULL && (ra & 0x1e34ef) && !(ra & 0x400) && !(ra & 0x800)) {
                ud.x >>= 4;
                ud.y >>= 4;
                ud.z >>= 4;
                if (ud.y * ud.y < ud.x * ud.x + ud.z * ud.z) {
                    uc.y = 0;
                    ra = (ra & 0xffe1cb10) | data_02156910;
                    if (g != NULL) {
                        ((Vec3 *) g)->x = 0;
                        ((Vec3 *) g)->y = 0;
                        ((Vec3 *) g)->z = 0;
                    }
                } else {
                    ra &= ~0x10000;
                    goto lo;
                }
            } else {
                ra = (ra & ~0x10000) | data_02156910;
            }
            if (ca.y > uc.y) {
                uc.y = ca.y;
            }
            if (ca.x > wb.mUnk_00) {
                wb.mUnk_00 = ca.x;
            }
            if (cb.x < wb.mUnk_0c) {
                wb.mUnk_0c = cb.x;
            }
            if (ca.z > wb.mUnk_08) {
                wb.mUnk_08 = ca.z;
            }
            if (cb.z < wb.mUnk_14) {
                wb.mUnk_14 = cb.z;
            }
        }
    lo:
        uc.x = wa.mUnk_00 > wb.mUnk_00 ? wa.mUnk_00 : wb.mUnk_00;
        uc.x += wa.mUnk_0c < wb.mUnk_0c ? wa.mUnk_0c : wb.mUnk_0c;
        uc.z = wa.mUnk_08 > wb.mUnk_08 ? wa.mUnk_08 : wb.mUnk_08;
        uc.z += wa.mUnk_14 < wb.mUnk_14 ? wa.mUnk_14 : wb.mUnk_14;
        ((Vec3 *) f)->x = uc.x >> 10;
        ((Vec3 *) f)->y = uc.y >> 10;
        ((Vec3 *) f)->z = uc.z >> 10;
        if ((ra & 0x214300) && c != 0 && k != NULL && h != NULL) {
            cc.x = cc.x + cd.x;
            cc.z = cc.z + cd.z;
            qq = (s64) cc.x * ((Vec3 *) h)->z - (s64) cc.z * ((Vec3 *) h)->x;
            if (qq < -16 || qq > 16) {
                cd.x = ((s64) cc.x * ((Vec3 *) c)->x) >> 12;
                cd.z = ((s64) cc.z * ((Vec3 *) c)->z) >> 12;
                cc.x = cc.x - (s32) (((s64) cd.x * ((Vec3 *) c)->x) >> 12);
                cc.z = cc.z - (s32) (((s64) cd.z * ((Vec3 *) c)->z) >> 12);
                func_02148504((Vec3 *) &wa.mUnk_00, (Vec3 *) &wa.mUnk_0c, &ua);
                if (func_02039828(&cc, &ua) >= 0) {
                    if ((s64) cc.x * cc.x + (s64) cc.y * cc.y + (s64) cc.z * cc.z >= 16) {
                        func_02039860(&cc, &cc);
                    }
                    cc.x = ((s64) cc.x * (r >> 5)) >> 12;
                    cc.y = ((s64) cc.y * (r >> 5)) >> 12;
                    cc.z = ((s64) cc.z * (r >> 5)) >> 12;
                    ((Vec3 *) k)->x += cc.x;
                    ((Vec3 *) k)->z += cc.z;
                }
            }
        }
    }
    if (o != NULL) {
        *o = ra;
    }
    return rv;
}
