#include "00/code_02194cac.h"
#include "03/code_021b94b8.h"
#include "00/code_0218e49c.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_021906e4.h"
#include "00/code_021960a4.h"
#include "00/code_02196590.h"
#include "00/code_021965a0.h"
#include "00/code_0218eb9c.h"
#include "00/code_02196000.h"
#include "00/unk_021b3000.h"
#include "00/code_021965c8.h"
#include "00/code_02196914.h"
#include "00/code_021a3668.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "code_0213442c.h"
#include "code_02134d30.h"
#include "code_0213a460.h"

s32 func_ov000_02194cac(Unk0218f960 *a, Unk02194cac *b) {
    u8 w0[0x200];
    u8 w1[0x200];
    Unk02194cac_10 e;
    u32 h;
    s32 n;
    Unk02190ed4Cb c1;
    u32 j;
    u32 m;
    Unk02190ed4Cb c8;
    Unk02190ed4Cb c7;
    Unk02190ed4Cb c6;
    Unk02190ed4Cb c5;
    Unk02190ed4Cb c4;
    Unk02190ed4Cb c3;
    Unk02190ed4Cb c2;
    s32 d;
    s32 g;
    Unk0218f960_00 *o;
    Unk02194cac_04 *p;
    s32 k;
    s32 r;
    s32 f;
    s32 x;
    s32 y;
    s32 v;
    u8 *q;
    Unk02194cac_ac *q1;
    Unk02194cac_ac *t1;
    Unk02194cac_128 *q4;
    Unk02194cac_128 *t4;
    Unk02194cac_3c *u2;
    Unk02194cac_44 *u3;
    Unk02194cac_102 *u4;
    Unk02194cac_08 *u5;
    Unk02194cac_0c *u7;
    s32 i;
    Unk02194cac_0c2 *u9;

    o = a->mUnk_00;
    p = b->mUnk_04;
    if (b->mUnk_08 != 0) {
        k = 1;
    } else {
        k = 0;
    }
    do {
        r = func_ov000_021906e4(a, p->mUnk_004, (Unk021906e4 *) p->mUnk_018, &m, 1, (const s8 *) data_ov000_021b3634);
        if (r != 0) {
            return r;
        }
        if (b->mUnk_14 == 1) {
            r = func_ov000_02196714(a, p->mUnk_004, &h);
            if (r != 0) {
                return r;
            }
            if (h == 4) {
                func_ov000_021965a0(a, 0xd01, data_ov000_021b3638);
                func_ov000_02190f4c(a, 4, 0);
                return 4;
            }
            if (h == 3) {
                if (p->mUnk_000 == 1) {
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b3664);
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b3670);
                    func_ov000_02190b58(a, p->mUnk_018, o->mUnk_198);
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b367c);
                    func_ov000_02190b58(a, p->mUnk_018, o->mUnk_1a0);
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b3688);
                    func_ov000_02190b58(a, p->mUnk_018, o->mUnk_470);
                    if (p->mUnk_028[0] != 0) {
                        func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b3698);
                        func_ov000_02190b80(a, p->mUnk_018, (u8 *) p->mUnk_028);
                    }
                    if (p->mUnk_047[0] != 0) {
                        func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b36a0);
                        func_ov000_02190b80(a, p->mUnk_018, (u8 *) p->mUnk_047);
                    }
                    if (p->mUnk_05c[0] != 0) {
                        func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b36b0);
                        func_ov000_02190b80(a, p->mUnk_018, (u8 *) p->mUnk_05c);
                    }
                    if (p->mUnk_08f[0] != 0) {
                        func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b36b8);
                        func_ov000_02190b80(a, p->mUnk_018, (u8 *) p->mUnk_08f);
                    }
                    if (p->mUnk_0ae[0] != 0) {
                        func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b36c4);
                        func_ov000_02190b80(a, p->mUnk_018, (u8 *) p->mUnk_0ae);
                    }
                    if (p->mUnk_130 != 0) {
                        func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b36d0);
                        func_ov000_02190b58(a, p->mUnk_018, p->mUnk_130);
                    }
                    if (p->mUnk_134 > 0) {
                        func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b36dc);
                        func_ov000_02190b58(a, p->mUnk_018, p->mUnk_134);
                    }
                } else if (p->mUnk_000 == 2) {
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b36e4);
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b36b0);
                    func_ov000_02190b80(a, p->mUnk_018, (u8 *) p->mUnk_05c);
                } else if (p->mUnk_000 == 3) {
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b36ec);
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b36b0);
                    func_ov000_02190b80(a, p->mUnk_018, (u8 *) p->mUnk_05c);
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b36f4);
                    func_ov000_02190b80(a, p->mUnk_018, (u8 *) p->mUnk_0cd);
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b3688);
                    func_ov000_02190b58(a, p->mUnk_018, o->mUnk_470);
                } else if (p->mUnk_000 == 4) {
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b36fc);
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b3670);
                    func_ov000_02190b58(a, p->mUnk_018, o->mUnk_198);
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b367c);
                    func_ov000_02190b58(a, p->mUnk_018, o->mUnk_1a0);
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b3708);
                    func_ov000_02190b58(a, p->mUnk_018, p->mUnk_138);
                } else if (p->mUnk_000 == 5) {
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b3714);
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b3698);
                    func_ov000_02190b80(a, p->mUnk_018, (u8 *) p->mUnk_028);
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b36b0);
                    func_ov000_02190b80(a, p->mUnk_018, (u8 *) p->mUnk_05c);
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b36f4);
                    func_ov000_02190b80(a, p->mUnk_018, (u8 *) p->mUnk_0cd);
                } else if (p->mUnk_000 == 6) {
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b371c);
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b3698);
                    func_ov000_02190b80(a, p->mUnk_018, (u8 *) p->mUnk_028);
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b36b0);
                    func_ov000_02190b80(a, p->mUnk_018, (u8 *) p->mUnk_05c);
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b36f4);
                    func_ov000_02190b80(a, p->mUnk_018, (u8 *) p->mUnk_0cd);
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b3728);
                    func_ov000_02190b58(a, p->mUnk_018, o->mUnk_46c);
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b3688);
                    func_ov000_02190b58(a, p->mUnk_018, o->mUnk_470);
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b36a0);
                    func_ov000_02190b80(a, p->mUnk_018, (u8 *) p->mUnk_047);
                    if (p->mUnk_0ec[0] != 0) {
                        func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b3734);
                        func_ov000_02190b80(a, p->mUnk_018, (u8 *) p->mUnk_0ec);
                    }
                } else if (p->mUnk_000 == 7) {
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b373c);
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b3670);
                    func_ov000_02190b58(a, p->mUnk_018, o->mUnk_198);
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b367c);
                    func_ov000_02190b58(a, p->mUnk_018, o->mUnk_1a0);
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b3688);
                    func_ov000_02190b58(a, p->mUnk_018, o->mUnk_470);
                } else if (p->mUnk_000 == 8) {
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b3748);
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b3758);
                    func_ov000_02190b80(a, p->mUnk_018, (u8 *) p->mUnk_047);
                    func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b3688);
                    func_ov000_02190b58(a, p->mUnk_018, o->mUnk_470);
                } else {
                    func_0213442c(data_ov000_021b3768, data_ov000_021b3628, 0, 0x275);
                }
                func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b376c);
                func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b4d6c);
                func_ov000_02190b80(a, p->mUnk_018, data_ov000_021b3778);
                b->mUnk_14 = 4;
            }
        } else if (b->mUnk_14 == 4) {
            r = func_ov000_021907e8(a, p->mUnk_004, (Unk021906e4 *) &p->mUnk_008, (s32 *) &j, &m,
                                    (const s8 *) data_ov000_021b3634);
            if (r != 0) {
                if (r != 3) {
                    return r;
                }
                func_ov000_021965a0(a, 0xd01, data_ov000_021b3780);
                func_ov000_02190f4c(a, 3, 0);
                return 3;
            }
            if (func_02139f70(p->mUnk_008, data_ov000_021b3778) != 0) {
                n = 0;
                b->mUnk_14 = 5;
                if (func_ov000_02196870(a, p->mUnk_008, 1) != 0) {
                    p->mUnk_140 = 1;
                    return 4;
                }
                if (p->mUnk_000 == 1) {
                    d = 0;
                    e.mUnk_00 = 0;
                    e.mUnk_04 = 0;
                    e.mUnk_0c = 0;
                    e.mUnk_08 = 0x601;
                    do {
                        r = func_ov000_021965c8(a, (s8 *) p->mUnk_008, &n, (s8 *) w0, (s8 *) w1);
                        if (r != 0) {
                            return r;
                        }
                        if (func_0213a074(w0, data_ov000_021b37ac) == 0) {
                            r = func_ov000_021965c8(a, (s8 *) p->mUnk_008, &n, (s8 *) w0, (s8 *) w1);
                            if (r != 0) {
                                return r;
                            }
                            if (func_0213a074(w0, data_ov000_021b37b4) == 0 &&
                                func_0213a074(w1, data_ov000_021b3768) != 0) {
                                e.mUnk_08 = 0x600;
                            }
                            d = 1;
                        } else if (func_0213a074(w0, data_ov000_021b37bc) == 0) {
                            q1 = func_ov000_021a3678(e.mUnk_0c, ++e.mUnk_04 * 0xac);
                            e.mUnk_0c = q1;
                            if (q1 == 0) {
                                func_ov000_02196590(a, data_ov000_021b35f8);
                                return 1;
                            }
                            i = e.mUnk_04 - 1;
                            t1 = &q1[i];
                            func_02134de0(t1, 0, 0xac);
                            q1[i].mUnk_00 = func_0213bf90(w1);
                            f = 0;
                            do {
                                g = n;
                                r = func_ov000_021965c8(a, (s8 *) p->mUnk_008, &n, (s8 *) w0, (s8 *) w1);
                                if (r != 0) {
                                    return r;
                                }
                                if (func_0213a074(w0, data_ov000_021b37c0) == 0) {
                                    func_ov000_02196914((u8 *) t1->mUnk_04, w1, 0x1f);
                                } else if (func_0213a074(w0, data_ov000_021b37c8) == 0) {
                                    func_ov000_02196914((u8 *) t1->mUnk_23, w1, 0x15);
                                } else if (func_0213a074(w0, data_ov000_021b37d4) == 0) {
                                    func_ov000_02196914((u8 *) t1->mUnk_38, w1, 0x1f);
                                } else if (func_0213a074(w0, data_ov000_021b37e0) == 0) {
                                    func_ov000_02196914((u8 *) t1->mUnk_57, w1, 0x1f);
                                } else if (func_0213a074(w0, data_ov000_021b37ec) == 0) {
                                    func_ov000_02196914((u8 *) t1->mUnk_76, w1, 0x33);
                                } else if (func_0213a074(w0, data_ov000_021b37bc) == 0 ||
                                           func_0213a074(w0, data_ov000_021b37ac) == 0) {
                                    f = 1;
                                    n = g;
                                }
                            } while (f == 0);
                        } else {
                            func_ov000_021965a0(a, 1, data_ov000_021b37f4);
                            func_ov000_02190f4c(a, 3, 1);
                            return 3;
                        }
                    } while (d == 0);
                    v = e.mUnk_08;
                    c1 = b->mUnk_0c;
                    if (c1.mUnk_00 != 0) {
                        c1.mUnk_00(a, &e, c1.mUnk_04);
                    }
                    if (v == 0x600 && e.mUnk_08 == 0x600) {
                        r = func_ov000_021960a4(a, p->mUnk_028, p->mUnk_047, p->mUnk_05c, p->mUnk_08f, p->mUnk_0ae,
                                                p->mUnk_130, e.mUnk_04 + p->mUnk_134, b->mUnk_08,
                                                (u32) b->mUnk_0c.mUnk_00, (u32) b->mUnk_0c.mUnk_04);
                        if (r != 0) {
                            return r;
                        }
                    }
                    func_ov000_021a3668(e.mUnk_0c);
                    e.mUnk_0c = 0;
                } else if (p->mUnk_000 == 2) {
                    c2 = b->mUnk_0c;
                    if (c2.mUnk_00 != 0) {
                        r = func_ov000_021965c8(a, (s8 *) p->mUnk_008, &n, (s8 *) w0, (s8 *) w1);
                        if (r != 0) {
                            return r;
                        }
                        if (func_0213a074(w0, data_ov000_021b381c) != 0) {
                            func_ov000_021965a0(a, 1, data_ov000_021b37f4);
                            func_ov000_02190f4c(a, 3, 1);
                            return 3;
                        }
                        u2 = func_ov000_021a3690(0x3c);
                        if (u2 == 0) {
                            func_ov000_02196590(a, data_ov000_021b35f8);
                            return 1;
                        }
                        u2->mUnk_00 = 0;
                        func_ov000_02196914((u8 *) u2->mUnk_04, p->mUnk_05c, 0x33);
                        if ((s8) w1[0] == 0x30) {
                            u2->mUnk_38 = 0;
                        } else {
                            u2->mUnk_38 = 1;
                        }
                        r = func_ov000_02190ed4(a, c2, u2, (Unk021937c0Node *) b, 0);
                        if (r != 0) {
                            return r;
                        }
                    }
                } else if (p->mUnk_000 == 3) {
                    c3 = b->mUnk_0c;
                    if (c3.mUnk_00 != 0) {
                        u3 = func_ov000_021a3690(0x44);
                        if (u3 == 0) {
                            func_ov000_02196590(a, data_ov000_021b35f8);
                            return 1;
                        }
                        u3->mUnk_00 = 0;
                        func_0213a2d0(u3->mUnk_04, (u8 *) p->mUnk_05c);
                        u3->mUnk_38 = 0;
                        u3->mUnk_3c = 0;
                        u3->mUnk_40 = 0;
                        r = func_ov000_021965c8(a, (s8 *) p->mUnk_008, &n, (s8 *) w0, (s8 *) w1);
                        if (r != 0) {
                            return r;
                        }
                        if (func_0213a074(w0, data_ov000_021b3820) != 0) {
                            func_ov000_021965a0(a, 1, data_ov000_021b37f4);
                            func_ov000_02190f4c(a, 3, 1);
                            return 3;
                        }
                        d = 0;
                        do {
                            r = func_ov000_021965c8(a, (s8 *) p->mUnk_008, &n, (s8 *) w0, (s8 *) w1);
                            if (r != 0) {
                                return r;
                            }
                            if (func_0213a074(w0, data_ov000_021b37c0) == 0) {
                                q = func_ov000_021a3678(u3->mUnk_3c, (u3->mUnk_38 + 1) * 4);
                                if (q == 0) {
                                    func_ov000_02196590(a, data_ov000_021b35f8);
                                    return 1;
                                }
                                u3->mUnk_3c = (u8 **) q;
                                q = func_ov000_021a3690(0x1f);
                                if (q == 0) {
                                    func_ov000_02196590(a, data_ov000_021b35f8);
                                    return 1;
                                }
                                u3->mUnk_3c[u3->mUnk_38] = q;
                                func_ov000_02196914((u8 *) u3->mUnk_3c[u3->mUnk_38], w1, 0x1f);
                                u3->mUnk_38++;
                            } else if (func_0213a074(w0, data_ov000_021b37c8) == 0) {
                                if (u3->mUnk_38 > 0) {
                                    q = func_ov000_021a3678(u3->mUnk_40, u3->mUnk_38 * 4);
                                    if (q == 0) {
                                        func_ov000_02196590(a, data_ov000_021b35f8);
                                        return 1;
                                    }
                                    u3->mUnk_40 = (u8 **) q;
                                    q = func_ov000_021a3690(0x15);
                                    if (q == 0) {
                                        func_ov000_02196590(a, data_ov000_021b35f8);
                                        return 1;
                                    }
                                    u3->mUnk_40[u3->mUnk_38 - 1] = q;
                                    func_ov000_02196914((u8 *) u3->mUnk_40[u3->mUnk_38 - 1], w1, 0x15);
                                }
                            } else if (func_0213a074(w0, data_ov000_021b3824) == 0) {
                                d = 1;
                            } else {
                                func_ov000_021965a0(a, 1, data_ov000_021b37f4);
                                func_ov000_02190f4c(a, 3, 1);
                                return 3;
                            }
                        } while (d == 0);
                        r = func_ov000_02190ed4(a, c3, u3, (Unk021937c0Node *) b, 3);
                        if (r != 0) {
                            return r;
                        }
                    }
                } else if (p->mUnk_000 == 4) {
                    c4 = b->mUnk_0c;
                    if (c4.mUnk_00 != 0) {
                        u4 = func_ov000_021a3690(0x10);
                        if (u4 == 0) {
                            func_ov000_02196590(a, data_ov000_021b35f8);
                            return 1;
                        }
                        u4->mUnk_04 = p->mUnk_138;
                        d = 0;
                        u4->mUnk_00 = 0;
                        u4->mUnk_08 = 0;
                        u4->mUnk_0c = 0;
                        do {
                            r = func_ov000_021965c8(a, (s8 *) p->mUnk_008, &n, (s8 *) w0, (s8 *) w1);
                            if (r != 0) {
                                return r;
                            }
                            if (func_0213a074(w0, data_ov000_021b382c) == 0) {
                                d = 1;
                            } else if (func_0213a074(w0, data_ov000_021b3834) == 0) {
                                u4->mUnk_08++;
                                u4->mUnk_0c = func_ov000_021a3678(u4->mUnk_0c, u4->mUnk_08 * 0x128);
                                q4 = u4->mUnk_0c;
                                if (q4 == 0) {
                                    func_ov000_02196590(a, data_ov000_021b35f8);
                                    return 1;
                                }
                                i = u4->mUnk_08 - 1;
                                t4 = &q4[i];
                                func_02134de0(t4, 0, 0x128);
                                t4->mUnk_024 = 1;
                                q4[i].mUnk_000 = func_0213bf90(w1);
                                f = 0;
                                do {
                                    g = n;
                                    r = func_ov000_021965c8(a, (s8 *) p->mUnk_008, &n, (s8 *) w0, (s8 *) w1);
                                    if (r != 0) {
                                        return r;
                                    }
                                    if (func_0213a074(w0, data_ov000_021b3838) == 0) {
                                        func_ov000_02196914((u8 *) t4->mUnk_028, w1, 0x100);
                                    } else if (func_0213a074(w0, data_ov000_021b37c0) == 0) {
                                        func_ov000_02196914((u8 *) t4->mUnk_004, w1, 0x1f);
                                    }
                                    if (func_0213a074(w0, data_ov000_021b3840) == 0) {
                                        t4->mUnk_024 = func_0213bf90(w1);
                                    } else if (func_0213a074(w0, data_ov000_021b3834) == 0 ||
                                               func_0213a074(w0, data_ov000_021b382c) == 0) {
                                        f = 1;
                                        n = g;
                                    }
                                } while (f == 0);
                            } else {
                                func_ov000_021965a0(a, 1, data_ov000_021b37f4);
                                func_ov000_02190f4c(a, 3, 1);
                                return 3;
                            }
                        } while (d == 0);
                        r = func_ov000_02190ed4(a, c4, u4, (Unk021937c0Node *) b, 4);
                        if (r != 0) {
                            return r;
                        }
                    }
                } else if (p->mUnk_000 == 5) {
                    c5 = b->mUnk_0c;
                    if (c5.mUnk_00 != 0) {
                        r = func_ov000_021965c8(a, (s8 *) p->mUnk_008, &n, (s8 *) w0, (s8 *) w1);
                        if (r != 0) {
                            return r;
                        }
                        if (func_0213a074(w0, data_ov000_021b384c) != 0) {
                            func_ov000_021965a0(a, 1, data_ov000_021b37f4);
                            func_ov000_02190f4c(a, 3, 1);
                            return 3;
                        }
                        x = func_0213bf90(w1);
                        if (x != 0) {
                            o->mUnk_418 = x;
                            y = 0;
                        } else {
                            if (func_ov000_021967b4(p->mUnk_008, data_ov000_021b3850, w1, 0x200) == 0) {
                                func_ov000_021965a0(a, 1, data_ov000_021b37f4);
                                func_ov000_02190f4c(a, 3, 1);
                                return 3;
                            }
                            y = func_0213bf90(w1);
                        }
                        u5 = func_ov000_021a3690(8);
                        if (u5 == 0) {
                            func_ov000_02196590(a, data_ov000_021b35f8);
                            return 1;
                        }
                        u5->mUnk_00 = x;
                        u5->mUnk_04 = y;
                        r = func_ov000_02190ed4(a, c5, u5, (Unk021937c0Node *) b, 0);
                        if (r != 0) {
                            return r;
                        }
                    }
                } else if (p->mUnk_000 == 6) {
                    c6 = b->mUnk_0c;
                    if (c6.mUnk_00 != 0) {
                        r = func_ov000_021965c8(a, (s8 *) p->mUnk_008, &n, (s8 *) w0, (s8 *) w1);
                        if (r != 0) {
                            return r;
                        }
                        if (func_0213a074(w0, data_ov000_021b3858) != 0) {
                            func_ov000_021965a0(a, 1, data_ov000_021b37f4);
                            func_ov000_02190f4c(a, 3, 1);
                            return 3;
                        }
                        x = func_0213bf90(w1);
                        if (x != 0) {
                            o->mUnk_418 = x;
                        }
                        if (func_ov000_021967b4(p->mUnk_008, data_ov000_021b3850, w1, 0x200) == 0) {
                            if (x == 0) {
                                func_ov000_021965a0(a, 1, data_ov000_021b37f4);
                                func_ov000_02190f4c(a, 3, 1);
                                return 3;
                            }
                            y = 0;
                        } else {
                            y = func_0213bf90(w1);
                        }
                        u5 = func_ov000_021a3690(8);
                        if (u5 == 0) {
                            func_ov000_02196590(a, data_ov000_021b35f8);
                            return 1;
                        }
                        u5->mUnk_00 = x;
                        u5->mUnk_04 = y;
                        r = func_ov000_02190ed4(a, c6, u5, (Unk021937c0Node *) b, 0);
                        if (r != 0) {
                            return r;
                        }
                    }
                } else if (p->mUnk_000 == 7) {
                    c7 = b->mUnk_0c;
                    if (c7.mUnk_00 != 0) {
                        u7 = func_ov000_021a3690(0xc);
                        if (u7 == 0) {
                            func_ov000_02196590(a, data_ov000_021b35f8);
                            return 1;
                        }
                        u7->mUnk_00 = 0;
                        u7->mUnk_04 = 0;
                        u7->mUnk_08 = 0;
                        r = func_ov000_021965c8(a, (s8 *) p->mUnk_008, &n, (s8 *) w0, (s8 *) w1);
                        if (r != 0) {
                            return r;
                        }
                        if (func_0213a074(w0, data_ov000_021b385c) != 0) {
                            func_ov000_021965a0(a, 1, data_ov000_021b37f4);
                            func_ov000_02190f4c(a, 3, 1);
                            return 3;
                        }
                        d = 0;
                        do {
                            r = func_ov000_021965c8(a, (s8 *) p->mUnk_008, &n, (s8 *) w0, (s8 *) w1);
                            if (r != 0) {
                                return r;
                            }
                            if (func_0213a074(w0, data_ov000_021b3864) == 0) {
                                d = 1;
                            } else if (func_0213a074(w0, data_ov000_021b386c) == 0) {
                                q1 = func_ov000_021a3678(u7->mUnk_08, (u7->mUnk_04 + 1) * 0xac);
                                if (q1 == 0) {
                                    func_ov000_02196590(a, data_ov000_021b35f8);
                                    return 1;
                                }
                                u7->mUnk_08 = q1;
                                q1 = u7->mUnk_08;
                                i = u7->mUnk_04;
                                t1 = &q1[i];
                                func_02134de0(t1, 0, 0xac);
                                u7->mUnk_04++;
                                q1[i].mUnk_00 = func_0213bf90(w1);
                                f = 0;
                                do {
                                    g = n;
                                    r = func_ov000_021965c8(a, (s8 *) p->mUnk_008, &n, (s8 *) w0, (s8 *) w1);
                                    if (r != 0) {
                                        return r;
                                    }
                                    if (func_0213a074(w0, data_ov000_021b37c0) == 0) {
                                        func_ov000_02196914((u8 *) t1->mUnk_04, w1, 0x1f);
                                    } else if (func_0213a074(w0, data_ov000_021b37c8) == 0) {
                                        func_ov000_02196914((u8 *) t1->mUnk_23, w1, 0x15);
                                    } else if (func_0213a074(w0, data_ov000_021b3870) == 0) {
                                        func_ov000_02196914((u8 *) t1->mUnk_38, w1, 0x1f);
                                    } else if (func_0213a074(w0, data_ov000_021b3878) == 0) {
                                        func_ov000_02196914((u8 *) t1->mUnk_57, w1, 0x1f);
                                    } else if (func_0213a074(w0, data_ov000_021b37ec) == 0) {
                                        func_ov000_02196914((u8 *) t1->mUnk_76, w1, 0x33);
                                    } else if (func_0213a074(w0, data_ov000_021b386c) == 0 ||
                                               func_0213a074(w0, data_ov000_021b3864) == 0) {
                                        f = 1;
                                        n = g;
                                    }
                                } while (f == 0);
                            } else {
                                func_ov000_021965a0(a, 1, data_ov000_021b37f4);
                                func_ov000_02190f4c(a, 3, 1);
                                return 3;
                            }
                        } while (d == 0);
                        r = func_ov000_02190ed4(a, c7, u7, (Unk021937c0Node *) b, 8);
                        if (r != 0) {
                            return r;
                        }
                    }
                } else if (p->mUnk_000 == 8) {
                    c8 = b->mUnk_0c;
                    if (c8.mUnk_00 != 0) {
                        i = 0;
                        u9 = func_ov000_021a3690(0xc);
                        if (u9 == 0) {
                            func_ov000_02196590(a, data_ov000_021b35f8);
                            return 1;
                        }
                        u9->mUnk_00 = 0;
                        u9->mUnk_04 = 0;
                        u9->mUnk_08 = 0;
                        r = func_ov000_021965c8(a, (s8 *) p->mUnk_008, &n, (s8 *) w0, (s8 *) w1);
                        if (r != 0) {
                            return r;
                        }
                        if (func_0213a074(w0, data_ov000_021b3880) != 0) {
                            func_ov000_021965a0(a, 1, data_ov000_021b37f4);
                            func_ov000_02190f4c(a, 3, 1);
                            return 3;
                        }
                        u9->mUnk_04 = func_0213bf90(w1);
                        u9->mUnk_08 = func_ov000_021a3690(u9->mUnk_04 * 4);
                        if (u9->mUnk_08 == 0) {
                            func_ov000_02196590(a, data_ov000_021b35f8);
                            return 1;
                        }
                        d = 0;
                        do {
                            r = func_ov000_021965c8(a, (s8 *) p->mUnk_008, &n, (s8 *) w0, (s8 *) w1);
                            if (r != 0) {
                                return r;
                            }
                            if (func_0213a074(w0, data_ov000_021b37c0) == 0) {
                                u9->mUnk_08[i] = func_ov000_021a3690(0x15);
                                if (u9->mUnk_08[i] == 0) {
                                    func_ov000_02196590(a, data_ov000_021b35f8);
                                    return 1;
                                }
                                func_ov000_02196914((u8 *) u9->mUnk_08[i], w1, 0x15);
                                i++;
                            } else if (func_0213a074(w0, data_ov000_021b3884) == 0) {
                                if (i != u9->mUnk_04) {
                                    func_0213442c(data_ov000_021b388c, data_ov000_021b3628, 0, 0x515);
                                }
                                u9->mUnk_04 = i;
                                d = 1;
                            } else {
                                func_ov000_021965a0(a, 1, data_ov000_021b37f4);
                                func_ov000_02190f4c(a, 3, 1);
                                return 3;
                            }
                        } while (d == 0);
                        r = func_ov000_02190ed4(a, c8, u9, (Unk021937c0Node *) b, 9);
                        if (r != 0) {
                            return r;
                        }
                    }
                } else {
                    func_0213442c(data_ov000_021b3768, data_ov000_021b3628, 0, 0x52a);
                }
                p->mUnk_140 = 1;
                k = 0;
            }
        }
        if (k != 0) {
            func_ov000_0218e8bc(10);
        }
    } while (k != 0);
    return 0;
}
