#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {

    setuid(0);
    char buffer[16];
    unsigned int val = 0;

    if(argc == 1) {
        printf("No Shell For You!");
    } else if (argc == 2){
        if(val == 3735928559) {
        system("bash");
    }
    } else {
        printf("No Shell For You!");
    } 

    return 0;
}