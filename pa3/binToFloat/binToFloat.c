#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define EXP_SZ 8
#define FRAC_SZ 23

int calculatePower(int base, int exponent){
    // printf("%f ^", base);
    // printf("%d =", exponent);
    int result = 1;
    while(exponent!=0){
        result*=base;
        --exponent;
    }
    // printf("%f \n", result);
    return result;
}

double calculatePowerDouble(double base, int exponent){
    // printf("%f ^", base);
    // printf("%d =", exponent);
    double result = 1.0;
    while(exponent!=0){
        result*=base;
        --exponent;
    }
    // printf("%f \n", result);
    return result;
}


int main(int argc, char *argv[]) {

    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen failed");
        return EXIT_FAILURE;
    }

    // SETUP

    // first, read the binary number representation of float point number
    char buff;
    unsigned int binary = 0;
    bool bitString[32];
    for(int i = 0; i < 31; i++){
        bitString[i]=false;
    }
    for (int i=EXP_SZ+FRAC_SZ; 0<=i; i--) { // read MSB first as that is what comes first in the file
        /* ... */
    fscanf(fp, "%c", &buff);
        // printf("min buf = %c ", buff);
        char temp = buff;
        if(temp == '1')
            bitString[i] =  1;
    }

    if(bitString[31]==1){
        binary = 1;
    }

    // for (int i=31; 0<=i; i--){
    //     printf(bitString[i] ? "1" : "0");
    // }
    // printf("\n");

    // float number = *(float *)&binary; // you are not allowed to do this.
    
    /* ... */
    
    // E
    /* ... */
    //iterate through exp of bitString: [30] -> [23]  8 bits.
    int counter = 0;
    int expValue = 0;
    for(int i = 23; i<=30;i++){
        if(bitString[i]){
            expValue += calculatePower(2, counter);
        }
        // printf("expVal= %d counter= %d ", expValue, counter);
        counter++;
    }
    int bias = 127;
    int E;
    if(expValue==0){//DENOMRALIZED
        E = 1 - bias;
    }
    else{//NORMALIZED
        E = expValue - bias;
    }
    // printf("%d\n", E);
    // printf("\n");
    // for (int i=30; 23<=i;i--){
    //     printf(bitString[i] ? "1" : "0");
    // }
    
    // printf("%d", expValue);
    // for(int i = 22; 0<=i;i--){
    //     printf(bitString[i] ? "1" : "0");
    // }
    // printf("\n");
    // M
    /* ... */
    int counter2 = 1;
    double frac = 0.0;
    for(int i = 22; 0<=i; i--){
        if(bitString[i]){
            frac += (1/calculatePowerDouble(2.0, counter2));
        }
        counter2++;
    }

    double M;
    if(expValue==0){//DENOMRALIZED
        M = frac;
    }
    else{//NORMALIZED
        M = 1.0+frac;
    }

    // https://www.tutorialspoint.com/c_standard_library/c_function_ldexp.htm
    double number = ldexp ( M, E );
    if(binary==1){
        number = -number;
    }
    //number = sign ? -number : number;
    printf("%f\n", number);

    return EXIT_SUCCESS;

}
