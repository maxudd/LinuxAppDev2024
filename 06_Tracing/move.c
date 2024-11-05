#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define LEN 1000

int main(int argc, char** argv){ 
    FILE *file_in = fopen(argv[1], "r");
    if (!file_in) {
        printf("Error in the opening of input file: %s\n", strerror(errno));
        exit(1);
    }
    FILE *file_out = fopen(argv[2], "w");
    if (!file_out) {
        printf("Error in the opening of output file: %s\n", strerror(errno));
        fclose(file_out);
        exit(2);
    }
    char strbuf[LEN];
    while (!feof(file_in)) {
        char* res = fgets(strbuf, LEN, file_in);
        if (res)
            fputs(strbuf, file_out);
    }
    fclose(file_out);
    fclose(file_in);
    remove(argv[1]);

    return 0;
}