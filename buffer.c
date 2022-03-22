#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_CHAR 32

int main(int argc, char *argv[]) {

    setuid(0);
    printf("Testing!\n");

    char name[MAX_CHAR]; //this take the input correctly.

    // The follow code demonstrates that without the correct checks
    // a buffer overflow attack can be made.

    if(argc == 1) {
        printf("Not Enough Arguments! Please Enter a Name\n");
    } else if (argc == 2){
        strcpy(name, argv[1]);
        printf("\nHello %s!\n", name);
    } else {
        printf("Too many arguments!\n");
    }    

    // The follow code demonstrates how the attack can be avoided
    // using the correct checks.
    // if(argc == 1) {
    //     printf("Please enter a name!");
    // } else if (argc == 2){
    //     if(strlen(argv[1]) < MAX_CHAR) {
    //         strcpy(name, argv[1]);
    //         printf("\nEntered Sentence is: %s", name);
    //     } else {
    //         printf("Input is too long!");
    //     }
    // } else {
    //     printf("Too many arguments!");
    // }

    return 0;
}
