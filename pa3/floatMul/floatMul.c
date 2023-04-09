#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

#define EXP_SZ 8
#define FRAC_SZ 23

int main(int argc, char *argv[]) {

    // float value = *(float *) &binary; // you are not allowed to do this.
    // unsigned int binary = *(unsigned int*) &value; // you are not allowed to do this.

    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen failed");
        return EXIT_FAILURE;
    }

    // SETUP

    // first, read the binary number representation of multiplier
    /* ... */
    char buff;
    bool multiplier[32];
    for(int i=0;i<31;i++){
        multiplier[i] = false;
    }

    for(int i=31; 0<=i;i--){
        fscanf(fp, "%c", &buff);
        char temp = buff;
        if(temp == '1')
        multiplier[i] =  1;
    }

    // notice that you are reading two different lines; caution with reading
    /* ... */
    fscanf(fp, "%c", &buff);
    // first, read the binary number representation of multiplcand
    /* ... */
    bool multiplicand[32];
    for(int i=0;i<31;i++){
        multiplicand[i] = false;
    }

    for(int i=31; 0<=i;i--){
        fscanf(fp, "%c", &buff);
        char temp = buff;
        if(temp == '1')
        multiplicand[i] =  1;
    }

    // for (int i=31; 0<=i; i--){
    //     printf(multiplier[i] ? "1" : "0");
    // }
    // printf("\n");
    // for (int i=31; 0<=i; i--){
    //     printf(multiplicand[i] ? "1" : "0");
    // }

    // float product = *(float *) &multiplier * *(float *) &multiplicand; // you are not allowed to print from this.
    // unsigned int ref_bits = *(unsigned int *) &product; // you are not allowed to print from this. But you can use it to validate your solution.

    // SIGN
    /* ... */
    int sign = multiplier[31]^multiplicand[31];
    printf("%d_",sign);
        printf("\n");

    // assert (sign == (1&ref_bits>>(EXP_SZ+FRAC_SZ)));

    // EXP
    // get the exp field of the multiplier and multiplicand
    /* ... */
    int count = 0;
    bool firstExp[8];
    for(int i=0;i<8;i++){
        firstExp[i] = false;
    }
    for(int i = 23;i<=30;i++){
        firstExp[count] = multiplier[i];
        count++;
    }

    int count2 =0; 
    bool secondExp[8];
    for(int i=0;i<8;i++){
        secondExp[i] = false;
    }
    for(int i = 23;i<=30;i++){
        secondExp[count2] = multiplicand[i];
        count2++;
    }

    for(int i = 0; i<8;i++){
        printf(firstExp[i] ? "1" : "0");
    }
    printf("\n");
    for(int i = 0; i<8;i++){
        printf(secondExp[i] ? "1" : "0");
    }
printf("\n");
    // add the two exp together
    /* ... */
    bool expSum[8];
    for(int i=0;i<8;i++){
        expSum[i] = false;
    }

    int c = 0;
    for (int i=0; i<8; i++){
        if(firstExp[i]==false && secondExp[i]==false){
            if(c == 1){
                expSum[i] = 1;
                c = 0;
                //printf("test 1");
            }
            else if(c ==0){
                expSum[i] = 0;
                //printf("test 2");
            }
        }

        else if(firstExp[i]^secondExp[i]){
            if(c==1){
                expSum[i] = 0;
                //printf("test 3");
            }
            if(c==0){
                expSum[i] = 1;
                //printf("test 4");
            }
        }

        else if(firstExp[i]&secondExp[i]){
            if(c==1){
                expSum[i] = 1;
                //printf("test 5");
            }
            
            else if(c == 0){
                expSum[i] = 0;
                c = 1;
                //printf("test 6");
            }
        }
    }

    for(int i=0;i<8;i++){
        printf(expSum[i] ? "1" : "0");
    }

    

    // subtract bias
    /* ... */

    // FRAC
    // get the frac field of the multiplier and multiplicand
    /* ... */
    // assuming that the input numbers are normalized floating point numbers, add back the implied leading 1 in the mantissa
    /* ... */
    // multiply the mantissas
    /* ... */

    // overflow and normalize
    /* ... */

    // rounding
    /* ... */

    // move decimal point
    /* ... */

    // PRINTING
    // print exp
    // for ( int bit_index=EXP_SZ-1; 0<=bit_index; bit_index-- ) {
    //     bool trial_bit = 1&exp>>bit_index;
    //     printf("%d",trial_bit);
    //     assert (trial_bit == (1&ref_bits>>(bit_index+FRAC_SZ)));
    // }
    // printf("_");

    // // print frac
    // for ( int bit_index=FRAC_SZ-1; 0<=bit_index; bit_index-- ) {
    //     bool trial_bit = 1&frac>>bit_index;
    //     printf("%d",trial_bit);
    //     assert (trial_bit == (1&ref_bits>>(bit_index)));
    // }

    return(EXIT_SUCCESS);

}

//gcc -g -Wall -Werror -fsanitize=address -std=c99 -o TEST TEST.c -lm