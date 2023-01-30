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