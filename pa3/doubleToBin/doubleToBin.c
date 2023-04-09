#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

#define EXP_SZ 11
#define FRAC_SZ 52

double calculatePower(double base, int exponent){
    double result = 1.0;
    while(exponent!=0){
        result*=base;
        --exponent;
    }
    return result;
}

double fabs (double value) {
    return value<0.0 ? -value : value;
}

int main(int argc, char *argv[]) {

    // SETUP

    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen failed");
        return 0;
    }

    // first, read the number
    double value;
    fscanf(fp, "%lf", &value);

    // the reference solution ('the easy way')
    // you are not allowed to print from this casted 'ref_bits' variable below
    // but, it is helpful for validating your solution
    unsigned long int ref_bits = *(unsigned long int*) &value;

    // THE SIGN BIT
    bool sign = value<0.0;
    printf("%d_",sign);
    assert (sign == (1&ref_bits>>(EXP_SZ+FRAC_SZ))); // validate your result against the reference

    // THE EXP FIELD
    // find the exponent E such that the fraction will be a canonical fraction:
    // 1.0 <= fraction < 2.0
    double fraction = sign ? -value : value;

    //signed short trial_exp=(1<<(EXP_SZ-1))-1; // start by assuming largest possible exp (before infinity)
    // do trial division until the proper exponent E is found
    /* ... */
    signed short trial_exp = 0;;
    // printf("%d\n", trial_exp);
    // printf("%f", fraction);
    // (fraction/calculatePower(2,trial_exp)) < 1 || (calculatePower(2,trial_exp) >=2)
    // if(fraction < 1){
    //         trial_exp = (1<<(EXP_SZ-1))-1;
    //         printf("trialexp = 11\n");
    //     }
    // else{
    //     trial_exp = 0;
    //     printf("trialexp = 0\n");
    // }

    // printf("%f, %d\n", fraction, trial_exp);
    // printf("%f\n",fraction/calculatePower(2,trial_exp));
    // printf("%f\n",fraction/ldexp(1,-1));
    //printf("%f",fraction/calculatePower(2,trial_exp-1));

    bool run = true;
    while(run){
        if(fraction==0.0){
            trial_exp = -1023;
            run = false;
        }
        else if((fraction/ldexp(1, trial_exp)) < 1 ){
            trial_exp--;
            // printf("%f, %d\n", fraction, trial_exp);
        }
        else if((fraction/ldexp(1, trial_exp)) >=2){
            trial_exp++;
            // printf("%f, %d\n", fraction, trial_exp);
        }
        else{
            run = false;
            // printf("end with %f, %d\n", fraction, trial_exp);
        }
    }
    //printf("%f, %d\n", fraction, trial_exp);    
    unsigned short bias = (1<<(EXP_SZ-1))-1;
    signed short exp = trial_exp + bias;
    //
    for ( int exp_index=EXP_SZ-1; 0<=exp_index; exp_index-- ) {
        bool exp_bit = 1&exp>>exp_index;
        printf("%d",exp_bit);
        assert (exp_bit == (1&ref_bits>>(exp_index+FRAC_SZ))); // validate your result against the reference
    }
    printf("_");
    // printf("\n");
    // for(int i =0; i<52; i++){
    //     printf("%d",0);
    // }
    // printf("%d\n", exp);
    // you get partial credit by getting the exp field correct
    // even if you print zeros for the frac field next
    // you should be able to pass test cases 0, 1, 2, 3

    
    // THE FRAC FIELD
    // prepare the canonical fraction such that:
    // 1.0 <= fraction < 2.0
    /* ... */
    // double frac = sign ? -value : value;
    // while(frac>=1){
    //     frac--;
    // }
    // printf("%f\n", frac);

    bool frac_array[FRAC_SZ+1]; // one extra LSB bit for rounding
    for ( int frac_index=FRAC_SZ; 0<=frac_index; frac_index-- ) {
        frac_array[frac_index] = false; // frac set to zero to enable partial credit
    }

    // double result = 0.0;
    // if(frac !=0.0){
    //     for(int i = 0; i<=FRAC_SZ; i++){
    //         printf("i = %d , frac = %f , 1/2^i = %f, result = %f\n",i, frac, 1/ldexp(1,i+1), result);
            
    //         if((result+(1/ldexp(1, i+1))) <= frac){
    //             frac_array[i] = true;
    //             printf("result + 1/2^i = %f\n", result + (1/ldexp(1, i+1)));
    //             result = result + (1/ldexp(1, i+1));
    //             printf("updated\n");
    //         }
    //     }
    // }
    

    // bool frac_array[FRAC_SZ+1]; // one extra LSB bit for rounding
    // for ( int frac_index=FRAC_SZ; 0<=frac_index; frac_index-- ) {
    //     frac_array[frac_index] = false; // frac set to zero to enable partial credit
    //     /* ... */
    // }

    // // rounding
    // /* ... */

    for ( int frac_index=FRAC_SZ-1; 0<=frac_index; frac_index-- ) {
        bool frac_bit = frac_array[frac_index+1]; // skipping the extra LSB bit for rounding
        printf("%d", frac_bit);
        //assert (frac_bit == (1&ref_bits>>frac_index)); // validate your result against the reference
    }

}
