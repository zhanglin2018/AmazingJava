#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

/*
 * mkfifo:
 *     
 *     create a named pipe
 */

int main()
{
    if (mkfifo("fifo", 0644) == -1)
    {
        perror("mkfifo error");
	_exit(-1);
    }
}
