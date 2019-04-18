#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <fcntl.h>
using namespace std;

/*
 * mkfifo:
 *     
 *     create a named pipe
 *
 *     The only difference between pipes and FIFOs is the manner in which they are created and opened.
 *     Once these tasks have been accomplised, I/O on pipes and FIFOs has exactly the same semantics.
 *
 *     O_NONBLOCK disable(blocking): blocks until a process turns on the fifo for write.
 *     O_NONBLOCK enable: return success immediately.
 */


int main()
{
    int fd = open("fifo", O_RDONLY|O_NONBLOCK);
	
    if (fd == -1)
    {
        perror("FIFO open error");
        _exit(-1);
    }
		
    int a = 1<<4-1;
    int b = (1<<4)-1;
    int c = 1<<4 - 1;
    int d = 1 << 4 - 1;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;

    cout << "fifo O_RDONLY open success" << endl;
}

