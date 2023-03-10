#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include <unistd.h>

// This is the data structure we will use to pass arguments to the children
struct MyData {
   char threadLetter;
   int  secondsToRun;
};

#define TIME_SLICE 40

// This is the child thread function that will be started by "pthread_create()"
static void *child( void *passedData ) {

   struct MyData *childData = (struct MyData*)passedData;  // data struct passed in
   char threadLetter = childData->threadLetter;            // remember the struct is a pointer
   int  timeToLive   = childData->secondsToRun;            //   so we use the "->" to access fields

   // Loop until the time to live expires, then exit
   while( timeToLive >= 0 ) {
      timeToLive -= TIME_SLICE;
      if( timeToLive <= 0 ) {
         if( (timeToLive + TIME_SLICE) != 0 ) {
            printf( "%c:%d:done\n", threadLetter, timeToLive + TIME_SLICE );
         }
      } else {
         printf( "%c:%d:%d\n", threadLetter, TIME_SLICE, timeToLive );
      }
      sleep( 1 );
   }
   return NULL;
}

int main( int argc, char * argv[] ) {
    printf("Here \n");
    printf("%d", argc);
    printf("%s", argv[1]);
    printf("%s", argv[2]);

    int threads[argc/2];
    for(int i = 0; i < argc; i++){
        pthread_t child_thread;
        struct MyData data;
        data.threadLetter = argv[i];
        data.secondsToRun = atoi(argv[i+1]);
    }
    // pthread_t child_thread;
    // int i = 1;
    // int j = 0;
    // int threads[argc/2];
    // while(i < argc){
    //     struct MyData *data;
    //     data->threadLetter = *argv[i];
    //     data->secondsToRun = atoi(argv[i+1]);
    //     threads[j] = pthread_create(&child_thread, NULL, child, &data);
    //     printf("Here");
    //     j++;
    //     i += 2;
    // }
}