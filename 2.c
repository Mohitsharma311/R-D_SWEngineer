#include <stdio.h>

int main(void) {
    int i = 1;
    int limit = 1000;

loop:
    printf("%d\n", i);
    i++;
    if ( ((i - (limit + 1)) >> 31) & 1 )
        goto loop;

    return 0;
}
