#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "num_guess.c"

int main() {
    assert(strcmp(to_roman(1), "I") == 0);
    assert(strcmp(to_roman(10), "X") == 0);
    assert(strcmp(to_roman(99), "XCIX") == 0);
    assert(strcmp(to_roman(2003), "Out of bounds") == 0);
    assert(strcmp(to_roman(-2), "Out of bounds") == 0);
    printf("Successfully passed all tests.\n");
    return 0;
}
