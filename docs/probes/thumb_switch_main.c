// Compiler probe (docs/compiler.md): Thumb switch dispatch in main. Matches on 1.2 b56 and base only.
// python3 tools/probe_compilers.py docs/probes/thumb_switch_main.c --flags="-O4,p -inline on,noauto"

typedef struct {
    char pad0[0xc8];
    int mUnk_c8;
} Obj02029930;

typedef struct {
    char pad0[0x10];
    int mUnk_10;
} Obj0217a9e0;

extern int data_02153274[];
extern int data_02153240[];
extern Obj0217a9e0 *data_0217a9e0;
Obj02029930 *func_02029930(void);
void func_02050e60(int arg);

// PROBE: func_02025e60 main 0x02025e60
int func_02025e60(int idx) {
    int result = -1;
    switch (func_02029930()->mUnk_c8) {
        case 0:
        case 1:
        case 3:
        case 5:
            result = data_02153274[idx];
            break;
        case 2:
            result = data_02153240[idx];
            break;
    }
    return result;
}

// PROBE: RepeatedScanCallback main 0x0204e3b4
void RepeatedScanCallback(int arg) {
    switch (arg) {
        case 0:
        case 1:
            break;
        case 2:
            func_02050e60(5);
            break;
        case 3:
            data_0217a9e0->mUnk_10 = 0;
            break;
    }
}
