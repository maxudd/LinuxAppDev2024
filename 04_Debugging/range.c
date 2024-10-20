#include "stdio.h"
#include "stdlib.h"


void help(){
    fprintf(stderr, "range: Print elements in given range\012\t"\
                    "Usage: range [arg1 [arg2 [arg3]]]\n");
}

void range(int M, int N, int S){
    int i = M;
    for ( i; i < N; i = i + S)
        printf("%d\n", i);
}

int main(int argc, char** argv){
    switch (argc) {
    case 1:
        help();
        break;
    case 2:
        range(atoi(argv[1]), 0, 1);
        break;
    case 3:
        range(atoi(argv[1]), atoi(argv[2]), 1);
        break;
    case 4:
        range(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
        break;
    default:
        printf("Too many parameters.\n");
        break;
    }

    return 0;
}