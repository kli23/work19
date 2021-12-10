#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main() {
    
    mkfifo("toworker", 0644); //creates both pipes
    mkfifo("tointer", 0644);

    int toworker, tointer;

    toworker = open("toworker", O_WRONLY);
    tointer = open("tointer", O_RDONLY);
    
    char line[2048];

    while (1) { //constantly prompts stdin
        
        printf("Input: ");
        fgets(line, sizeof(line), stdin);

        write( toworker, line, sizeof(line)); //writes to worker

        read( tointer, line, sizeof(line) ); // gets response and prints
        printf("\nProcessed input: %s\n", line);
    }

    return 0;
    
}
 
    
    
    

