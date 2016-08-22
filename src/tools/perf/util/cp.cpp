#include <stdio.h>
extern "C" int __fsetlocking(FILE* fp, int type);

int __fsetlocking(FILE* fp, int type) {
    return 0;
}
