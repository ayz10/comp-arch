#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


// Struct to hold the open and close braces and the pointer to the next element.
struct element {
    // char open; // not needed
    char close;
    struct element* next;
};

// Append the new element to the start of the stack
// This is one potential way to write this function signature
void push (
    struct element** stack,
    // char open, // not needed
    char close
) {
    /* ... */
    struct element* newElement = malloc(sizeof(struct element));
    newElement->close = close;
    newElement->next = *stack;
    *stack = newElement;
    //printf("pushed %c\n", close );
}

// Remove element from the top of the stack
char pop ( struct element** stack ) {

    if (*stack != NULL) {
        /* ... */
        struct element* temp = *stack;
        char close = temp -> close;
        *stack = temp->next;
        free(temp);
        //printf("popped %c\n", close );
        return close;
    } else {
        //perror("Empty stack");
        return '\0';
    }
}

bool isMatchingPair(char character1, char character2)
{
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else if (character1 == '<' && character2 == '>')
        return 1;
    else
        return 0;
}

int main(int argc, char* argv[]) {

    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen failed");
        return EXIT_FAILURE;
    }

    struct element* root = NULL;
    bool balanced = true;

    char buff;
    while ( fscanf(fp, "%c", &buff)==1 ) {

        switch(buff) {
            case '<' :
                /* ... */
                push(&root, buff);
                //printf("pushed %c\n", buff );
                break;
            case '(' :
                /* ... */
                push(&root, buff);
                //printf("pushed %c\n", buff );
                break;
            case '[' :
                /* ... */
                push(&root, buff);
                //printf("pushed %c\n", buff );
                break;
            case '{' :
                /* ... */
                push(&root, buff);
                //printf("pushed %c\n", buff );
                break;
            case '>' :
                /* ... */
                if(!isMatchingPair(pop(&root), buff)){
                    //printf("popped %c\n", '>' );
                    printf("no");
                    while(root){
                        pop(&root);
                    }
                    fclose(fp);
                    return 0;
                }
                break;
            case ')' :
                /* ... */
                if(!isMatchingPair(pop(&root), buff)){
                    //printf("popped %c\n", ')' );
                    printf("no");
                    while(root){
                        pop(&root);
                    }
                    fclose(fp);
                    return 0;
                }
                break;                
            case ']' :
                /* ... */
                if(!isMatchingPair(pop(&root), ']')){
                   // printf("popped %c\n", buff );
                    printf("no");
                    while(root){
                        pop(&root);
                    }
                    fclose(fp);
                    return 0;
                }  
                break;           
            case '}' :
                /* ... */
                if(!isMatchingPair(pop(&root), '}')){
                    //printf("popped %c\n", buff );
                    printf("no");
                    while(root){
                        pop(&root);
                    }
                    fclose(fp);
                    return 0;
                }      
                break;       
            default :
                printf("Invalid character\n" );
        }
    }
    while(root){
        pop(&root);
    }
    /* ... */
    printf ( balanced ? "yes" : "no" );

    fclose(fp);
    return 0;
}
