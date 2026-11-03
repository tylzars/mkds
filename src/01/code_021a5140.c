#include "01/code_02184f7c.h"
#include "01/code_021928c8.h"
#include "01/code_021a5140.h"
#include "01/code_02181000.h"
#include "01/code_02184000.h"
#include "01/code_02185000.h"
#include "01/code_02192000.h"
#include "01/code_021a6000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02037a04.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_02038c94.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020ca000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020391d4.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020ca6c4.h"
#include "Main/Unknown/unk_0217a000.h"
#include "01/code_02180ce8.h"
#include "03/code_021b94b8.h"
#include "code_0214d018.h"

void InitEmblem(void) {
    Unk020391d4 unk;
    Unk0217aa08_04 *p;

    gEmblem = func_02036bec((void *) func_020364e0(func_020364e8()), 0x10c0);
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
    LoadNclrData((Unk020b4a44 **) (&gEmblem->mEmblemMONclr), (void *) (FindSceneFile("emblem_m_o.NCLR")));
    LoadNcgrData2((Unk020b4934 **) (&gEmblem->mEmblemMONcgr), (void *) (FindSceneFile("emblem_m_o.NCGR")));
    LoadNcerData(&gEmblem->mEmblemMNcer, FindSceneFile("emblem_m.NCER"));
    LoadNanrData(&gEmblem->mEmblemMNanr, FindSceneFile("emblem_m.NANR"));
    gEmblem->mEmblemMLld = func_ov001_021852f8("emblem_m.lld", gEmblem->mEmblemMNcer, gEmblem->mEmblemMNanr);
    LoadNclrData((Unk020b4a44 **) (&gEmblem->mEmblemMBNclr), (void *) (FindSceneFile("emblem_m_b.NCLR")));
    LoadNcgrData((Unk020b4934 **) (&gEmblem->mEmblemMBNcgr), (void *) (FindSceneFile("emblem_m_b.NCGR")));
    LoadNscrData((Unk020b47d8 **) (&gEmblem->mEmblemMNscr), (void *) (FindSceneFile("emblem_m.NSCR")));
    LoadNscrData((Unk020b47d8 **) (&gEmblem->mEmblemMBgNscr), (void *) (FindSceneFile("emblem_m_bg.NSCR")));
    LoadNclrData(&gEmblem->mEmblemSONclr, (void *) (FindSceneFile("emblem_s_o.NCLR")));
    LoadNcgrData2((Unk020b4934 **) (&gEmblem->mEmblemSONcgr), (void *) (FindSceneFile("emblem_s_o.NCGR")));
    LoadNcerData(&gEmblem->mEmblemSNcer, FindSceneFile("emblem_s.NCER"));
    LoadNanrData(&gEmblem->mEmblemSNanr, FindSceneFile("emblem_s.NANR"));
    gEmblem->mEmblemSLld = func_ov001_021852f8("emblem_s.lld", gEmblem->mEmblemSNcer, gEmblem->mEmblemSNanr);
    gEmblem->mEmblemTemplateSLld =
        func_ov001_021852f8("emblem_template_s.lld", gEmblem->mEmblemSNcer, gEmblem->mEmblemSNanr);
    LoadNclrData(&gEmblem->mEmblemSBNclr, (void *) (FindSceneFile("emblem_s_b.NCLR")));
    LoadNcgrData((Unk020b4934 **) (&gEmblem->mEmblemSBNcgr), (void *) (FindSceneFile("emblem_s_b.NCGR")));
    LoadNcgrData(&gEmblem->mEmblemTemplateBNcgr, (void *) (FindSceneFile("emblem_template_b.NCGR")));
    LoadNscrData((Unk020b47d8 **) (&gEmblem->mEmblemSTemplateFrameNscr),
                 (void *) (FindSceneFile("emblem_s_template_frame.NSCR")));
    LoadNscrData((Unk020b47d8 **) (&gEmblem->mEmblemSToolNscr), (void *) (FindSceneFile("emblem_s_tool.NSCR")));
    LoadNscrData((Unk020b47d8 **) (&gEmblem->mEmblemSBgNscr), (void *) (FindSceneFile("emblem_s_bg.NSCR")));
    LoadNscrData((Unk020b47d8 **) (&gEmblem->mEmblemSTemplateDarkNscr),
                 (void *) (FindSceneFile("emblem_s_template_dark.NSCR")));
    LoadNcgrData2((Unk020b4934 **) (&gEmblem->mEmblemCameraSONcgr), (void *) (FindSceneFile("emblem_camera_s_o.NCGR")));
    LoadNcerData(&gEmblem->mEmblemCameraSNcer, FindSceneFile("emblem_camera_s.NCER"));
    LoadNanrData(&gEmblem->mEmblemCameraSNanr, FindSceneFile("emblem_camera_s.NANR"));
    gEmblem->mEmblemCameraSLld =
        func_ov001_021852f8("emblem_camera_s.lld", gEmblem->mEmblemCameraSNcer, gEmblem->mEmblemCameraSNanr);
    LoadNcgrData((Unk020b4934 **) (&gEmblem->mEmblemCameraSBNcgr), (void *) (FindSceneFile("emblem_camera_s_b.NCGR")));
    LoadNscrData((Unk020b47d8 **) (&gEmblem->mEmblemCameraSDSNscr),
                 (void *) (FindSceneFile("emblem_camera_s_DS.NSCR")));
    LoadNscrData((Unk020b47d8 **) (&gEmblem->mEmblemCameraSBgNscr),
                 (void *) (FindSceneFile("emblem_camera_s_bg.NSCR")));
    func_ov001_02192d28();
    func_02078c58((void *) func_020364e0(func_020364e8()));
    InitEmblemChoises();
    func_020ae6d4(gEmblem->mUnk_0000, gEmblem->mUnk_0404);
    func_ov001_021a6238(0x40, 0x10, 0x20, 0x80, 0x10);
    p = data_0217aa08->mUnk_04;
    if (p->mUnk_004) {
        func_0214d1fc(p->mUnk_008, gEmblem->mUnk_087c, 0x200);
        func_020ac454(gEmblem->mUnk_087c, gEmblem->mUnk_0c7c, func_ov001_02181268());
        func_ov001_02181124(gEmblem->mUnk_0c7c);
        func_ov001_02181098();
        func_ov001_02181124(gEmblem->mUnk_0c7c);
        func_ov001_02181048();
    }
    func_ov001_021a63cc(2);
    func_ov001_021a63c0((u8) 1);
    func_ov001_021a63a8(0);
    func_ov001_021a6388(0);
    func_ov001_021a6350((s32) (func_ov001_02184fc8(func_ov001_02185160(gEmblem->mEmblemSLld, 0))),
                        (s32) (func_ov001_02184fb8(func_ov001_02185160(gEmblem->mEmblemSLld, 0))));
    func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 14), 1);
    func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 12), 0);
    func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 10), 0);
    func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 23), 2);
    func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 1), -1);
    func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 2), -1);
    func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 3), -1);
    func_ov001_02184f9c(func_ov001_02185160(gEmblem->mEmblemSLld, 14), -12, -12, 12, 12);
    func_ov001_02184f9c(func_ov001_02185160(gEmblem->mEmblemSLld, 15), -12, -12, 12, 12);
    func_ov001_02184f9c(func_ov001_02185160(gEmblem->mEmblemSLld, 16), -12, -12, 12, 12);
    func_ov001_02184f9c(func_ov001_02185160(gEmblem->mEmblemSLld, 17), -12, -12, 12, 12);
    func_ov001_02184f9c(func_ov001_02185160(gEmblem->mEmblemSLld, 18), -12, -12, 12, 12);
    func_ov001_02184f9c(func_ov001_02185160(gEmblem->mEmblemSLld, 19), -12, -12, 12, 12);
    func_ov001_02184f9c(func_ov001_02185160(gEmblem->mEmblemSLld, 20), -12, -12, 12, 12);
    func_ov001_02184f9c(func_ov001_02185160(gEmblem->mEmblemSLld, 21), -12, -12, 12, 12);
    func_ov001_02184f9c(func_ov001_02185160(gEmblem->mEmblemSLld, 22), -12, -12, 12, 12);
    func_ov001_02184f9c(func_ov001_02185160(gEmblem->mEmblemSLld, 23), -12, -12, 12, 12);
    func_ov001_02184f9c(func_ov001_02185160(gEmblem->mEmblemSLld, 27), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(gEmblem->mEmblemSLld, 28), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(gEmblem->mEmblemSLld, 29), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(gEmblem->mEmblemSLld, 30), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(gEmblem->mEmblemSLld, 31), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(gEmblem->mEmblemSLld, 32), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(gEmblem->mEmblemSLld, 33), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(gEmblem->mEmblemSLld, 34), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(gEmblem->mEmblemSLld, 35), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(gEmblem->mEmblemSLld, 36), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(gEmblem->mEmblemSLld, 37), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(gEmblem->mEmblemSLld, 38), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(gEmblem->mEmblemSLld, 39), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(gEmblem->mEmblemSLld, 40), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(gEmblem->mEmblemSLld, 41), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(gEmblem->mEmblemSLld, 42), -12, -11, 11, 11);
    func_ov001_02184f9c(func_ov001_02185160(gEmblem->mEmblemSLld, 25), -32, -20, 32, 20);
    func_ov001_02184f9c(func_ov001_02185160(gEmblem->mEmblemSLld, 26), -32, -20, 32, 20);
    func_ov001_02184f9c(func_ov001_02185160(gEmblem->mEmblemTemplateSLld, 1), -52, -15, 52, 15);
    gEmblem->mUnk_10ac = 1;
    gEmblem->mUnk_10b0 = 0;
    gEmblem->mUnk_10bc = 6;
}
