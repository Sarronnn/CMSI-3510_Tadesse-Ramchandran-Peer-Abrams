#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ACCESS_OFFSET 4096

int main(int argc, char *argv[]){
    clock_t start, end;
    double execution_time;
    start = clock();
    
    if (argc != 2) {
        printf("1 argument only pal \n");
        return 1;
    }

    int arraySize = atoi( argv[1] );
    int* vmArray = (int*) malloc( sizeof(int) * arraySize );
    if( NULL == vmArray ) {
      printf( "\n    Could not allocate array of %d size.\n\n", arraySize );
      return 1;
    }

    int randomVal = 0;

    //fill loop
    for (int i = 0; i < arraySize; i+= 1) {
        *(vmArray + i) = (rand() % 100 + 1);
    }

    printf("Array has been filled \n \n");
    
    //printf( "Array element %d is %d\n", (arraySize - 1), vmArray[(arraySize - 1)]);

    //access loop
    for (int j = 0; j < arraySize; j += ACCESS_OFFSET) {
        printf( "\t Array element %10d is %3d\n", j, *(vmArray + j));
    }

    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("Time elapsed was %.2f seconds", execution_time);
    free(vmArray);
    return 0;
}

//14.27 Seconds
//13.67 Seconds
//12.93 Seconds
//12.70 Seconds
//12.43 Seconds
//12.37 Seconds
//12.35 Seconds
//12.36 Seconds
//12.18 Seconds
//12.29 Seconds
//12.48 Seconds

//12.74 Seconds Average