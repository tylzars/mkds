#include "03/code_021bf4dc.h"
#include "03/code_021cdd28.h"
#include "03/code_021ce110.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021da000.h"
#include "03/code_021bf410.h"
#include "03/code_021bf000.h"
#include "03/code_021c2000.h"
#include "03/code_021ce000.h"
#include "03/code_021d1440.h"

#include "03/code_021c2530.h"
#include "03/unk_021d5000.h"
#include "03/code_021d1000.h"
#include "03/code_021c209c.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0200eddc.h"
#include "code_02139f70.h"

u8 *BuildFilePathWithLanguage(const u8 *path) {
    u32 language;

    strncpy((char *) data_ov003_021da110, (const char *) path, 0x3f);
    if (path[5] == 0x78) {
        return data_ov003_021da110;
    }
    language = GetLanguageIndex();
    if (path[5] == 0x79 && language != 0) {
        return data_ov003_021da110;
    }
    data_ov003_021da110[5] = data_ov003_021d5f04[language];
    return data_ov003_021da110;
}

u32 LoadFileToVram(void *path, void *loader) {
    u32 size;
    void *data;

    data = LoadFile(BuildFilePathWithLanguage(path), &size, 4);
    DC_FlushRange(data, size);
    ((void (*)(void *, u32, u32)) loader)(data, 0, size);
    DeleteLoadedFile(data);
}

void func_ov003_021bf5ec(u32 a) {
    int v1[2];
    func_ov003_021c2104(v1, NULL);
    if (v1[0] == 1) {
        func_ov003_021ce408(a);
        return;
    }
    if (v1[0] == 2) {
        func_ov003_021ce024(a);
    }
}

void func_ov003_021bf5c8(u32 variant) {
    int v1[2];
    func_ov003_021c2104(NULL, v1);
    if (v1[0] == 1) {
        CreateSlideButtons(variant);
    }
}

void PrintMessage(u32 messageIndex) {
    void *canvas;
    void *message;

    canvas = InitBgTextCanvas(0, 0);
    message = GetMessageEntry(gMessages, messageIndex);
    DrawCanvasTextRect(canvas, data_ov003_021d5f0c[0], data_ov003_021d5f0c[1], data_ov003_021d5f0c[2],
                       data_ov003_021d5f0c[3], 2, GetLanguageTextFlags(), message);
    RequestBgTextCanvasUpload(canvas);
}

void PrintMessageAndText(u32 text, u32 messageIndex) {
    void *canvas;
    void *message;

    canvas = InitBgTextCanvas(0, 0);
    message = GetMessageEntry(gMessages, messageIndex);
    DrawCanvasTextRect(canvas, data_ov003_021d5f14[0], data_ov003_021d5f14[1], data_ov003_021d5f14[2],
                       data_ov003_021d5f14[3], 2, GetLanguageTextFlags(), message);
    DrawCanvasText((u32) canvas, data_ov003_021d5f34[GetLanguageIndex() * 2],
                   data_ov003_021d5f36[GetLanguageIndex() * 2], 2, 0x209, text);
    RequestBgTextCanvasUpload(canvas);
}

u32 GetLanguageTextFlags(void) {
    u32 value0;
    u32 value1;
    value0 = GetLanguageIndex();
    value1 = (value0 << 2);
    value0 = (u32) &data_ov003_021d5f1c;
    value0 = *(const u32 *) ((value0) + (value1));
    return value0;
}
