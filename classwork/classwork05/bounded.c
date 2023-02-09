#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int mutex = 1;
int full  = 0;
int empty = 7;          // maximum of seven messages in buffer
int x     = 0;


int count = 0;

int myWait( int s ) {
    return( --s );
}

int mySignal( int s ) {
    return( ++s );
}

static void *producer(void *ignored){
    while (1) {
        if( (mutex == 1) && (empty != 0) ) {
            mutex = myWait( mutex );
            full  = mySignal( full );
            empty = myWait( empty );
            x++;
            printf( "\t Producer produces the item %d \n", x );
            mutex = mySignal( mutex );
            usleep(567890);
        } else {
            printf( "Buffer is full!! \n" );
            usleep(123456);
        }
    }
    return NULL;
}

static void *consumer(void *ignored){
    while (1) {   
        if( (mutex == 1) && (full != 0) ) {
            mutex = myWait( mutex );
            full  = myWait( full );
            empty = mySignal( empty );
            printf( "\t Consumer consumes the item %d \n", x );
            x--;
            mutex = mySignal( mutex );
            usleep(1000000);
        } else {
            printf("Buffer is empty!! \n");
            usleep(135790);
        }
    }
    return NULL;
}

int main() {
    int wait_( int );
    int signal_( int );
    int code = 0;
    pthread_t producer_thread;
    pthread_t consumer_thread;
    
    code = pthread_create(&producer_thread, NULL, producer, NULL);
    if(code){
         fprintf(stderr, "pthread_create failed with code %d\n", code);
    }
    
    code = pthread_create(&consumer_thread, NULL, consumer, NULL);
    if(code){
        fprintf(stderr, "pthread_create failed with code %d\n", code);
    }

    sleep(25);
    printf("Parent is done sleeping 25 seconds.\n");
    pthread_cancel(producer_thread);
    pthread_cancel(consumer_thread);
    printf("Threads were murdered \n");
    return 0;
}