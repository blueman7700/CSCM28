#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {

    char buffer[16];
    unsigned int val = 0;

    if(argc == 1) {
        printf("No Shell For You!");
    } else if (argc == 2){
        strcpy(buffer, argv[1]);
        if(val == 3735928559) {
            setuid(1000);
            system("motd");
        }
    } else {
        printf("No Shell For You!");
    } 

    return 0;
}
