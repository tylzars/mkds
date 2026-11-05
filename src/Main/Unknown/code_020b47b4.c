#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_02047104.h"

void *func_020b47cc(const char *arg0) {
    u32 value0 = (u32) arg0;
    u32 value12;
    value12 = (u32) &func_02047a28;
    value0 = (u32) func_02047a28((const char *) value0);
    return (void *) value0;
}

void *FindSceneFileWrapper(const char *arg0) {
    u32 value0 = (u32) arg0;
    u32 value12;
    value12 = (u32) &FindSceneFile;
    value0 = (u32) FindSceneFile((const char *) value0);
    return (void *) value0;
}

void *FindCourseFileWrapper(const char *arg0) {
    u32 value0 = (u32) arg0;
    u32 value12;
    value12 = (u32) &FindCourseFile;
    value0 = (u32) FindCourseFile((const char *) value0);
    return (void *) value0;
}
