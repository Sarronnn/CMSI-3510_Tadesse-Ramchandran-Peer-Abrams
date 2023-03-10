Due Wednesday of Week 4 (Feb 1st, 2023)

1. What is the difference between an operating system and middleware?

=>An operating system is software that can manage hardware for the execution of other applications. It manages concurrency, networking, file systems, and interactions between different computations. Middleware is software between applications and the operating system. It does not have control over hardware and rather relies on the operating system to support applications.

2. What is the relationship between threads and processes?

=>  The basic difference between a process and a thread is that a process takes place in different memory spaces, whereas a thread executes in the same memory space (Source)

3. Of all the topics previewed in chapter one of the text book, which one are you most looking forward to learning more about? Why?

=>  The topic that most intrigued us in chapter was was section 1.5 'Multiple Computations on one computer'. The advancement of computers is something that we all are interested in, and the section outlines that the process of running multiple computations simultaneously is what leads to a more efficient computer. Through understanding of physichal components, and the knowledege of the theory of how to maximize the efficiency of multiple computations running, we can create new systems that can propell us into the future of the computing world.

4. Suppose thread A goes through a loop 100 times, each time performing one disk I/O operation, taking 10 milliseconds, and then some computation, taking 1 millisecond. While each 10-millisecond disk operation is in progress, thread A cannot make any use of the processor. Thread B runs for 1 second, purely in the processor, with no I/O. One millisecond of processor time is spent each time the processor switches threads; other than this switching cost, there is no problem with the processor working on thread B during one of thread A's I/O operations. [The processor and disk drive do not contend for memory access bandwidth, for example.]

    + Suppose the processor and disk work purely on thread A until its completion, and then the processor switches to thread B and runs all of that thread. What will the total elapsed time be?

    A = (100 * 10 + 100 * 1)  millisconds
    Switch = 1 millisconds
    B = 1000 millisconds
    A + Switch + B = 2101 millisconds
    
    + Suppose the processor starts out working on thread A, but every time thread A performs a disk operation, the processor switches to B during the operation and then back to A upon the disk operation's completion. What will the total elapsed time be?

    A = (100 * 1 + 100 * 1) millisconds
    Switch = (100 * 1) millisconds
    B = 1000 millisconds
    A + Switch + B = 1300 millisconds
    
    + _In your opinion_, which do you think is more efficient, and why?

    I bleive that the second scenario is more efficient as even though it has a lot of switching, saving 9 milliseconds on every Disk I/O operation that A has to do leads to huge saves in time. Scenario 1 times at 2101 millisconds whereas scenario 2 tims at 1300 millisconds. That is a 701 millisconds save from 1 that 2 has. Therefor I beleive 2 to be the most efficient option as it leads to the fastest output. 

5. Find and read the documentation for `pthread_cancel[]`. Then, using your C programming environment, use the information and the model provided in Figure 2.4 on page 26 of the text book to write a program in which the initial [main] thread creates a second thread. The main thread should sit on a read call of some kind, waiting to read input from the keyboard, waiting until the user presses the Enter key. At that point, it should kill off the second thread and print out a message reporting that it has done so. Meanwhile, the second thread should be in an infinite loop; during each iteration it must sleep five seconds and then print out a message. Try running your program. Can the sleeping thread print its periodic messages while the main thread is waiting for keyboard input? Can the main thread read input, kill the sleeping thread, and print a message while the sleeping thread is in the early part of one of its five-second sleeps?

The sleeping thread can print its periodic message while the parent thread waits for input. The parent thread can also read input and kill the thread during any part of the five second sleep phase.

```c
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
```

6. Suppose a system has three threads [T1, T2, and T3] that are all available to run at time 0 and need one, two, and three seconds of processing, respectively. Suppose each thread is run to completion before starting another. Draw six different Gantt charts, one for each possible order the threads can be run in. For each chart, compute the turnaround time of each thread; that is, the time elapsed from when it was _ready [time 0]_ until it is completed [finished]. Also, compute the _average_ turnaround time for _each order_. Which order has the shortest average turnaround time? What is the name of the scheduling policy that produces this order? {You can look this up in the textbook.]

=> B/c the answer to this question is long, it is added as a separate pdf file under our homework1 file. Its name is problem6.pdf. 

7. Perform an Internet search of the C standard library API and find out how to get information from the command line first by using a `printf[]` call to display a prompt, then another function call [which you will look up] to get the user input. Write a program in C to prompt the user for their demographic information including name, age, class year, and any three other data items you wish. Structure the program as a call-and-response application such that each data item is a single question with a single answer entry. When all data has been obtained, display the data on the console. Each data item must be on a separate line, and it must be appropriately labeled. The output must be done using a **single** `printf[]` statement.

You can find the program for this problem in this file: [problem7.c](https://github.com/Sarronnn/CMSI-3510_Tadesse-Ramchandran-Peer-Abrams/blob/main/Homeworks/homework01/problem7.c)

Here is the code you will find in that file:

```c
#include <stdio.h>
#include <stdlib.h>
int main( int argc, char * argv[] ) {
    char inputs [6][55];
    printf("What is your name?\n");
    gets(inputs[0]); 
    printf("What is your age?\n");
    gets(inputs[1]);
    printf("What is your class year?\n");
    gets(inputs[2]);
    printf("What is your favorite hobby?\n");
    gets(inputs[3]);
    printf("What is your favorite TV show?\n");
    gets(inputs[4]);
    printf("What is your favorite song?\n");
    gets(inputs[5]);

    printf("\nThis is the info you entered:\nName: %s\nAge: %s\nClass Year: %s\nFavorite Hobby: %s\nFavorite TV Show: %s\nFavorite Song: %s\n\n", inputs[0], inputs[1], inputs[2], inputs[3], inputs[4], inputs[5]);
}
```
