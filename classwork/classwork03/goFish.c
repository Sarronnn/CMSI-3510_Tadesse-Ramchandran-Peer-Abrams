/*
1. The numbers must be prompted for in a loop
2. The special value -9999 is used to indicate that the entries are complete
3. Store the values in a structure of some kind that is initially declared to be size 25 int elements
4. Loop through the structure and sum the elements, then output the sum to the console
5. Count the number of elements in the structure, and output their average to the console
6. Loop through the structure again, and contatenate all the values into a long string
7. Output the string to the console
8. Loop through the string, and count all the 7 [seven] characters; this is like in the game Go Fish when you ask another player, GIMME ALL YOUR SEVENS.
9. Output the count to the console
*/

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
    //sum elements in array and print sum
    printf("Summing elements and printing sum \n");
    int sum = 0;
    for(int i = 0; i < counter; i++){
        sum += numArray[i];
    }
    printf("%d",sum); 
    printf("\n");
    //get size and use that and sum to get average and print it
    printf("Printing average \n");
    int average = sum/counter; 
    printf("%d \n", average);
    //concatenate all values together and print it
    printf("Concatenation \n");
    for(int i = 0; i < counter; i++) {
        printf("%s", numArray[i]);
    }
    printf("\n");
    
    //count 7s and print it
    printf("Counting 7's \n");
    int count = 0;
    for(int i = 0; i < counter; i++) {
        if(numArray[i] == 7) {
            printf("%s", numArray[i]);
            count += 1 ; 
        }
    }
} 