#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_02047104.h"

void *func_020b47cc(const char *arg0) {
    return FindFileInLoadedArchives(arg0);
}

void *FindSceneFileWrapper(const char *arg0) {
    return FindSceneFile(arg0);
}

void *FindCourseFileWrapper(const char *arg0) {
    return FindCourseFile(arg0);
}
