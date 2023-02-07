
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARRAY_SIZE 25
#define END_VALUE -9999
int main( int argc, char * argv[] ) {
    //create array for storing numbers
    int numArray[MAX_ARRAY_SIZE];
    int input;
    int counter = 0;
    //prompt user for numbers until -9999 is entered
    while (1 == 1) {
        printf("Give me a number \n");
        scanf("%d", &input);
        if (input == -9999) {
            break;
        }
        numArray[counter] = input;
        counter++;
        if (counter == MAX_ARRAY_SIZE) {
            break;
        }
    }
    printf("\n");
    printf("\n");
    printf("\n");
    for (int i = 0; i < counter; i++) {
        printf("%d", numArray[i]);
        printf("\n");
    }
    printf("%d", counter);
}