#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    int flag = 0;
    if (argc <= 1)
    {
        flag = 0;
    }
    else if (argc == 2 && strcmp(argv[1], "exit") == 0)
    {
        flag = 0;
    }
    else if (argc == 2 && strcmp(argv[1], "_exit") == 0)
    {
        flag = 1;
    }

    printf("one!");  // note that the sign \n could write the buffer into the file.

    if (flag == 0)
    {
        printf("exit(0)");
        exit(0);//print one!
    }
    else
    {
        printf("_exit(0)\n");
        _exit(0);//print nothing
    }

    printf("two!\n");

    return 0;
}

