#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char* toUpper(char input[]) {
    char* start = input;
    int i;
    for (i = 0; i < strlen(input); i++) {
        if (input[i] >= 'a' && input[i] <= 'z')
            input[i] -= 32;
    }
    return start;
}

int main() {

    char line[2048];
    int toworker, tointer;
    toworker = open("toworker", O_RDONLY);
    tointer = open("tointer", O_WRONLY);


    while (1) {
    
        read( toworker, line, sizeof(line) ); //gets input from interface
    
        toUpper(line); //processes input
            
        write( tointer, line, sizeof(line) ); //sends response back to interface
    
    }

    return 0;
     
}