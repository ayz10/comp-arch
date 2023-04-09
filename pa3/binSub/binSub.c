#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen failed");
        return EXIT_FAILURE;
    }

    // SETUP

    // first, read the minuend (number to be subtracted from)
    char buff;
    bool minuend[8]; // suggested that you store bits as array of bools; minuend[0] is the LSB
    for(int i = 0; i < 7; i++)
        minuend[i] = false;

    for (int i=7; 0<=i; i--) { // read MSB first as that is what comes first in the file
        /* ... */
        fscanf(fp, "%c", &buff);
        // printf("min buf = %c ", buff);
        char temp = buff;
        if(temp == '1')
            minuend[i] =  1;
    }

    //printf("\n");
    // notice that you are reading two different lines; caution with reading
    /* ... */
    fscanf(fp, "%c", &buff);

    // second, read the subtrahend (number to subtract)
    bool subtrahend[8]; // suggested that you store bits as array of bools; subtrahend[0] is the LSB
    for(int i = 0; i < 7; i++)
        subtrahend[i] = false;

    for (int i=7; 0<=i; i--) { // read MSB first as that is what comes first in the file
        /* ... */
        fscanf(fp, "%c", &buff);
        //printf("sub buf = %c ", buff);
        char temp = buff;
        if(temp == '1')
            subtrahend[i] =  1;
    }

    // printf("\n");
    // for (int i=7; 0<=i; i--)
    //      printf(minuend[i] ? "1 " : "0 ");
    // printf("\n");
    // for (int i=7; 0<=i; i--)
    //      printf(subtrahend[i] ? "1 " : "0 ");


    // WE WILL DO SUBTRACTION BY NEGATING THE SUBTRAHEND AND ADD THAT TO THE MINUEND

    // Negate the subtrahend
    // flip all bits
    /* ... */
    for(int i = 7; 0<=i; i--){
        if(!subtrahend[i])
            subtrahend[i] = true;
        else if(subtrahend[i])
            subtrahend[i] = false;
    }
    // for (int i=7; 0<=i; i--)
    //      printf(minuend[i] ? "1 " : "0 ");
    // printf("\n");
    // for (int i=7; 0<=i; i--)
    //      printf(subtrahend[i] ? "1 " : "0 ");

    // add one
    bool carry = true; // to implement the 'add one' logic, we do binary addition logic with carry set to true at the beginning
    for (int i=0; i<8; i++) { // iterate from LSB to MSB
        /* ... */
        if(carry == false){
            break;
        }
        if(carry == true){
            if(subtrahend[i]==true){
                subtrahend[i]=false;
        }
            else if(subtrahend[i]==false){
                subtrahend[i]=true;
                carry = false;
            }
        }
        
        
    }

    // for (int i=7; 0<=i; i--)
    //      printf(minuend[i] ? "1 " : "0 ");
    // printf("\n");
    // for (int i=7; 0<=i; i--)
    //      printf(subtrahend[i] ? "1 " : "0 ");
    // printf("\n");

    // // Add the minuend and the negated subtrahend
    bool difference[8];
    
    /* ... */
    int c = 0;
    for (int i=0; i<8; i++){
        if(minuend[i]==false && subtrahend[i]==false){
            if(c == 1){
                difference[i] = 1;
                c = 0;
                //printf("test 1");
            }
            else if(c ==0){
                difference[i] = 0;
                //printf("test 2");
            }
        }

        else if(minuend[i]^subtrahend[i]){
            if(c==1){
                difference[i] = 0;
                //printf("test 3");
            }
            if(c==0){
                difference[i] = 1;
                //printf("test 4");
            }
        }

        else if(minuend[i]&subtrahend[i]){
            if(c==1){
                difference[i] = 1;
                //printf("test 5");
            }
            
            else if(c == 0){
                difference[i] = 0;
                c = 1;
                //printf("test 6");
            }
        }
    }

    // print the difference bit string
    for (int i=7; 0<=i; i--)
        printf("%d",difference[i]);

    return EXIT_SUCCESS;

}
