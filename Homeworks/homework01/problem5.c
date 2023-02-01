#include <pthread.h>
#include <unistd.h>
#include <stdio.h>


static void *child(void *ignored){
    while (1 == 1) {
    sleep(5);
    printf("Child is still sleeping, shhhh! \n");
    }
    return NULL;
}
int main(int argc, char *argv[]){
    pthread_t child_thread;
    char key_press;
    int code;
    code = pthread_create(&child_thread, NULL, child, NULL);
    if(code){
    fprintf(stderr, "pthread_create failed with code %d\n", code);
    }

    while (key_press != 0x0A) {
        key_press = fgetc(stdin);
    }
    pthread_cancel(child_thread);
    printf("Child thread was murdered \n");
    return 0;
}