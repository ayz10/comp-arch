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

    //printf("%d\n",(1<<1)-1);
    
    // print bits; you will see this kind of for loop often in this assignment
    for ( int bit=sizeof(signed int)*8-1; 0<=bit; bit-- ) {
        printf("bit = %d ",bit);
        size_t bit_val = ((1<<4)-1) & input>>bit*4; // shift and mask
        //char character = bit_val ? '1' : '0';
        //printf("char = %c\n",character);
        //printf("mask = %d ",input>>bit*3);
        printf("bit_val = %ld\n",bit_val);
    }
    printf("\n");

    return EXIT_SUCCESS;

}
