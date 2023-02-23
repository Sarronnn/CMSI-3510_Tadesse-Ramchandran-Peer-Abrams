#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>


//TODO Create thread function for displaying array values
typedef struct ThreadData_t {
	int threadID;
	int time;
	int startAddress;
};

static void *thready(void *argument, int *tables) {
    struct ThreadData_t *data = argument;
    int usleep = 100;
    
    for(int aNum = 0; aNum < 6; aNum++) {
        for(int i = 0; i < 4096; i++) {
            printf("%d", *tables[aNum][i]);
        }
    }

int main() {
    int arr0[4096];
    int arr1[4096];
    int arr2[4096];
    int arr3[4096];
    int arr4[4096];
    int arr5[4096];
    time_t t;
    int random;
    srand((unsigned) time(&t));
    int *tables[6] = {arr0, arr1, arr2, arr3, arr4, arr5};
    for (int aNum = 0; aNum < 6; aNum++) {
        for (int i = 0; i < 4096; i++) {
            random = (rand() % 65536) + 1;
            *(tables[aNum]+i) = random;
        }
    }


    for (int j = 0; j < 6; j++) {
        for (int k = 0; k < 10; k++) {
            printf("Value in array %d [%d] is %d \n", j, k, tables[j][k]);
        }
    }
    //TODO Make 6 threads
    pthread_t hThreads[6];
	int       threadIDs[6];
	struct    ThreadData_t tData[6];

	printf( "%s", "\n\n   Welcome to the Virtual Memory Base Table Simulator......\n" );
}