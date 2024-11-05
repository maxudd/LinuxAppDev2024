#include <dlfcn.h>
#include <string.h>
#include <unistd.h>

typedef int (*remove_t)(char*);

int remove(char* filename) {
    remove_t res = (remove_t) dlsym(RTLD_NEXT, "remove");
    if (strstr(filename, "PROTECT"))
        return -1;
    else
        return res(filename);
}