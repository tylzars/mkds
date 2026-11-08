#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_02047104.h"

void *FindFileInLoadedArchivesWrapper(const char *name) {
    return FindFileInLoadedArchives(name);
}

void *FindSceneFileWrapper(const char *name) {
    return FindSceneFile(name);
}

void *FindCourseFileWrapper(const char *path) {
    return FindCourseFile(path);
}
