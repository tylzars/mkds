#include "01/code_021a5140.h"
#include "01/code_02181000.h"
#include "01/code_02184000.h"
#include "01/code_02185000.h"
#include "01/code_02192000.h"
#include "01/code_021a6000.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020ca000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020391d4.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "01/code_02180ce8.h"
#include "03/code_021b94b8.h"

void func_ov001_021a5140(void) {
    Unk020391d4 unk;
    Unk0217aa08_04 *p;

    data_ov001_021ca41c = func_02036bec((void *) func_020364e0(func_020364e8()), 0x10c0);
    func_020391d4(&unk);
    unk.mUnk_06 = 1;
    unk.mUnk_08 = 0;
    unk.mUnk_0a = 1;
    unk.mUnk_02 = 0x11;
    unk.mUnk_16 = 3;
    unk.mUnk_18 = 0x10;
    unk.mUnk_0e = 0x20;
    unk.mUnk_10 = 0x40;
    unk.mUnk_0c = 1;
    unk.mUnk_04 = 0x10;
    unk.mUnk_1c = 4;
    unk.mUnk_1e = 8;
    func_02037abc(func_02038d88((void *) func_020364e0(func_020364e8()), &unk));
    func_020b4a7c((Unk020b4a44 **) (&data_ov001_021ca41c->mUnk_0808), (void *) (func_0204799c("emblem_m_o.NCLR")));
    func_020b49f4((Unk020b4934 **) (&data_ov001_021ca41c->mUnk_0810), (void *) (func_0204799c("emblem_m_o.NCGR")));
    func_020b48ec(&data_ov001_021ca41c->mUnk_0820, func_0204799c("emblem_m.NCER"));
    func_020b486c(&data_ov001_021ca41c->mUnk_0824, func_0204799c("emblem_m.NANR"));
    data_ov001_021ca41c->mUnk_0828 =
        func_ov001_021852f8("emblem_m.lld", data_ov001_021ca41c->mUnk_0820, data_ov001_021ca41c->mUnk_0824);
    func_020b4a7c((Unk020b4a44 **) (&data_ov001_021ca41c->mUnk_080c), (void *) (func_0204799c("emblem_m_b.NCLR")));
    func_020b496c((Unk020b4934 **) (&data_ov001_021ca41c->mUnk_0814), (void *) (func_0204799c("emblem_m_b.NCGR")));
    func_020b4810((Unk020b47d8 **) (&data_ov001_021ca41c->mUnk_0818), (void *) (func_0204799c("emblem_m.NSCR")));
    func_020b4810((Unk020b47d8 **) (&data_ov001_021ca41c->mUnk_081c), (void *) (func_0204799c("emblem_m_bg.NSCR")));
    func_020b4a7c(&data_ov001_021ca41c->mUnk_082c, (void *) (func_0204799c("emblem_s_o.NCLR")));
    func_020b49f4((Unk020b4934 **) (&data_ov001_021ca41c->mUnk_0834), (void *) (func_0204799c("emblem_s_o.NCGR")));
    func_020b48ec(&data_ov001_021ca41c->mUnk_0850, func_0204799c("emblem_s.NCER"));
    func_020b486c(&data_ov001_021ca41c->mUnk_0854, func_0204799c("emblem_s.NANR"));
    data_ov001_021ca41c->mUnk_0858 =
        func_ov001_021852f8("emblem_s.lld", data_ov001_021ca41c->mUnk_0850, data_ov001_021ca41c->mUnk_0854);
    data_ov001_021ca41c->mUnk_085c =
        func_ov001_021852f8("emblem_template_s.lld", data_ov001_021ca41c->mUnk_0850, data_ov001_021ca41c->mUnk_0854);
    func_020b4a7c(&data_ov001_021ca41c->mUnk_0830, (void *) (func_0204799c("emblem_s_b.NCLR")));
    func_020b496c((Unk020b4934 **) (&data_ov001_021ca41c->mUnk_0838), (void *) (func_0204799c("emblem_s_b.NCGR")));
    func_020b496c(&data_ov001_021ca41c->mUnk_083c, (void *) (func_0204799c("emblem_template_b.NCGR")));
    func_020b4810((Unk020b47d8 **) (&data_ov001_021ca41c->mUnk_0848),
                  (void *) (func_0204799c("emblem_s_template_frame.NSCR")));
    func_020b4810((Unk020b47d8 **) (&data_ov001_021ca41c->mUnk_0840), (void *) (func_0204799c("emblem_s_tool.NSCR")));
    func_020b4810((Unk020b47d8 **) (&data_ov001_021ca41c->mUnk_0844), (void *) (func_0204799c("emblem_s_bg.NSCR")));
    func_020b4810((Unk020b47d8 **) (&data_ov001_021ca41c->mUnk_084c),
                  (void *) (func_0204799c("emblem_s_template_dark.NSCR")));
    func_020b49f4((Unk020b4934 **) (&data_ov001_021ca41c->mUnk_0860),
                  (void *) (func_0204799c("emblem_camera_s_o.NCGR")));
    func_020b48ec(&data_ov001_021ca41c->mUnk_0870, func_0204799c("emblem_camera_s.NCER"));
    func_020b486c(&data_ov001_021ca41c->mUnk_0874, func_0204799c("emblem_camera_s.NANR"));
    data_ov001_021ca41c->mUnk_0878 =
        func_ov001_021852f8("emblem_camera_s.lld", data_ov001_021ca41c->mUnk_0870, data_ov001_021ca41c->mUnk_0874);
    func_020b496c((Unk020b4934 **) (&data_ov001_021ca41c->mUnk_0864),
                  (void *) (func_0204799c("emblem_camera_s_b.NCGR")));
    func_020b4810((Unk020b47d8 **) (&data_ov001_021ca41c->mUnk_0868),
                  (void *) (func_0204799c("emblem_camera_s_DS.NSCR")));
    func_020b4810((Unk020b47d8 **) (&data_ov001_021ca41c->mUnk_086c),
                  (void *) (func_0204799c("emblem_camera_s_bg.NSCR")));
    func_ov001_02192d28();
    func_02078c58((void *) func_020364e0(func_020364e8()));
    func_020ca6c4();
    func_020ae6d4(data_ov001_021ca41c->mUnk_0000, data_ov001_021ca41c->mUnk_0404);
    func_ov001_021a6238(0x40, 0x10, 0x20, 0x80, 0x10);
    p = data_0217aa08->mUnk_04;
    if (p->mUnk_004) {
        func_0214d1fc(p->mUnk_008, data_ov001_021ca41c->mUnk_087c, 0x200);
        func_020ac454(data_ov001_021ca41c->mUnk_087c, data_ov001_021ca41c->mUnk_0c7c, func_ov001_02181268());
        func_ov001_02181124(data_ov001_021ca41c->mUnk_0c7c);
        func_ov001_02181098();
        func_ov001_02181124(data_ov001_021ca41c->mUnk_0c7c);
        func_ov001_02181048();
    }
    func_ov001_021a63cc(2);
    func_ov001_021a63c0((u8) 1);
    func_ov001_021a63a8(0);
    func_ov001_021a6388(0);
    func_ov001_021a6350((s32) (func_ov001_02184fc8(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 0))),
                        (s32) (func_ov001_02184fb8(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 0))));
    func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 14), 1);
    func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 12), 0);
    func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 10), 0);
    func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 23), 2);
    func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 1), -1);
    func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 2), -1);
    func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 3), -1);
    func_ov001_02184f9c(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 14), -12, -12, 12, 12);
    func_ov001_02184f9c(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 15), -12, -12, 12, 12);
    func_ov001_02184f9c(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 16), -12, -12, 12, 12);
    func_ov001_02184f9c(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 17), -12, -12, 12, 12);
    func_ov001_02184f9c(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 18), -12, -12, 12, 12);
    func_ov001_02184f9c(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 19), -12, -12, 12, 12);
    func_ov001_02184f9c(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 20), -12, -12, 12, 12);
    func_ov001_02184f9c(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 21), -12, -12, 12, 12);
    func_ov001_02184f9c(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 22), -12, -12, 12, 12);
    func_ov001_02184f9c(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 23), -12, -12, 12, 12);
    func_ov001_02184f9c(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 27), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 28), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 29), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 30), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 31), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 32), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 33), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 34), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 35), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 36), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 37), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 38), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 39), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 40), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 41), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 42), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 25), -32, -20, 32, 20);
    func_ov001_02184f9c(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 26), -32, -20, 32, 20);
    func_ov001_02184f9c(func_ov001_02185160(data_ov001_021ca41c->mUnk_085c, 1), -52, -15, 52, 15);
    data_ov001_021ca41c->mUnk_10ac = 1;
    data_ov001_021ca41c->mUnk_10b0 = 0;
    data_ov001_021ca41c->mUnk_10bc = 6;
}
