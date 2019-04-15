#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; ++i)
        printf("argv[%d]: %s\t", i , argv[i]);
    printf("\n");
 
    for (char **ptr = environ; *ptr != NULL; ++ ptr)
        printf("%s\n", *ptr);
 
    exit(0);
}
