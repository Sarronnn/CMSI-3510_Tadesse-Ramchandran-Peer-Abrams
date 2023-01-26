#include <stdio.h>
#include <stdlib.h>
int main( int argc, char * argv[] ) {
    char input [55];
    printf("what is your name?");
    gets(input); 
    printf("Hello,%s\n", input);
}
