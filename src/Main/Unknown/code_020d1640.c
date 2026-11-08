#include "Main/Unknown/code_020d1640.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020b33d8.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b85dc.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_020b3000.h"
#include "Main/Unknown/code_020b4000.h"

void CreateSearchIconMBChildAndMultiDownload(void *heap) {
    data_0217b4b0 = HeapAlloc(heap, 0x2c);
    data_0217b4b0->mUnk_00 = FindFileInLoadedArchives("search_icon_00.bncl");
    data_0217b4b0->mUnk_04 = FindFileInLoadedArchives("search_icon_layout_00.bncl");
    LoadNcgrData2(&data_0217b4b0->mUnk_08, FindFileInLoadedArchives("search_icon_00.nce.ncgr"));
    LoadNcerData(&data_0217b4b0->mUnk_0c, FindFileInLoadedArchives("search_icon_00.nce.ncer"));
    LoadNclrData(&data_0217b4b0->mUnk_10, FindFileInLoadedArchives("search_icon_00_o.nclr"));
    switch (data_021759d0->mUnk_04) {
        default:
            func_020b478c(&data_0217b4b0->mUnk_14, FindFileInLoadedArchives("MBChild_us.NFTR"));
            break;
        case 2:
            func_020b478c(&data_0217b4b0->mUnk_14, FindFileInLoadedArchives("MBChild_fr.NFTR"));
            break;
        case 3:
            func_020b478c(&data_0217b4b0->mUnk_14, FindFileInLoadedArchives("MBChild_ge.NFTR"));
            break;
        case 4:
            func_020b478c(&data_0217b4b0->mUnk_14, FindFileInLoadedArchives("MBChild_it.NFTR"));
            break;
        case 5:
            func_020b478c(&data_0217b4b0->mUnk_14, FindFileInLoadedArchives("MBChild_es.NFTR"));
            break;
    }
    switch (data_021759d0->mUnk_04) {
        default:
            data_0217b4b0->mUnk_20 = FindFileInLoadedArchives("MBChild_us.bmg");
            break;
        case 2:
            data_0217b4b0->mUnk_20 = FindFileInLoadedArchives("MBChild_fr.bmg");
            break;
        case 3:
            data_0217b4b0->mUnk_20 = FindFileInLoadedArchives("MBChild_ge.bmg");
            break;
        case 4:
            data_0217b4b0->mUnk_20 = FindFileInLoadedArchives("MBChild_it.bmg");
            break;
        case 5:
            data_0217b4b0->mUnk_20 = FindFileInLoadedArchives("MBChild_es.bmg");
            break;
    }
    LoadNcgrData(&data_0217b4b0->mUnk_24, FindFileInLoadedArchives("multi_download_00_b.NCGR"));
    LoadNclrData(&data_0217b4b0->mUnk_28, FindFileInLoadedArchives("multi_download_00_b.NCLR"));
}
