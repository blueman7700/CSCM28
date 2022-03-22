#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    setuid(0);
    printf("would you like to:\n1. print the message of the day\n2. exit\n");
    printf("\nPlease enter 1 or 2: ");

    unsigned int i;
    scanf("%d", &i);

    if(i == 1) {
        system("motd");
    } else if (i == 2) {
        printf("exiting...\n");
    } else {
        printf("invalid input! exiting...\n");
    }
    return 0;
}