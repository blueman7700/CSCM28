#include <stdio.h>
#include <string.h>

#define MAX_CHAR 32

int main() {
    setuid(0);
    printf("Testing!\n");

    char sentence[MAX_CHAR]; //this take the input correctly.

    // The follow code demonstrates that without the correct checks
    // a buffer overflow attack can be made.
    printf("\nEnter your Sentence: ");
    gets(sentence);
    printf("\nEntered Sentence is: %s", sentence);

    // The follow code demonstrates how the attack can be avoided
    // using the correct checks.
//    printf("\n\nEnter your Sentence: ");
//    fgets(sentence, MAX_CHAR, stdin);
//    unsigned long length = strlen(sentence);
//    printf("\nLength of string: %lu", length);
//    if (length > MAX_CHAR)
//    {
//        printf("\nThe sentence you entered is too long!");
//    } else {
//        printf("\nYour sentence is: %s", sentence);
//    }

    return 0;
}
