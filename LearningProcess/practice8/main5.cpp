#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <fcntl.h>
#include <signal.h>
using namespace std;

/*
 * mkfifo:
 *     
 *     create a named pipe
 *
 *     The only difference between pipes and FIFOs is the manner in which they are created and opened.
 *     Once these tasks have been accomplised, I/O on pipes and FIFOs has exactly the same semantics.
 *
 *     O_NONBLOCK disable(blocking): blocks until a process turns on the fifo for read.
 *     O_NONBLOCK enable: return success immediately.
 */

void handler(int signalNum)
{
	cout << "signalNum: " << signalNum << endl;
        _exit(-1);
}

int main()
{
        
    if (signal(SIGINT, handler) == SIG_ERR)
    {
        perror("signal error");
    }

    int fd = open("fifo", O_WRONLY|O_NONBLOCK); 
    
    // ctrl+c generate the SIGINT signal, but the open operation is still blocked after perform the handler function. 

    if (fd == -1)
    {
        perror("FIFO open error");
        _exit(-1);
    }
    
    cout << sizeof(int) << endl;
    cout << sizeof(int *) << endl;

    cout << "FIFO O_WRONLY open success" << endl;
}

