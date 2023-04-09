#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen failed");
        return 0;
    }

    // first, read the number
    signed int input;
    fscanf(fp, "%d", &input);

    // print bits; you will see this kind of for loop often in this assignment
    for ( int bit=3; 0<=bit; bit-- ) {
        size_t bit_val = ((1<<4)-1) & input>>bit*4; // shift and mask
        //char character = bit_val ? '1' : '0';
        printf("%lx",bit_val);
    }
    printf("\n");

    return EXIT_SUCCESS;

}
