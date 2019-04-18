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



int main(int argc, char *argv[])
{
    // create fifo
    unlink("myFifo");    

    if (mkfifo("myFifo", 0644) == -1)
    {
        perror("mkfifo error");
	_exit(-1);
    }
		
    int outfd = open("myFifo", O_WRONLY);   //write FIFO

    if (outfd == -1)
    {
        perror("open fifo error");
        _exit(-1);
    }
 
    string buffer;

    while (true)
    {
        cin >> buffer;
        write(outfd, buffer.c_str(), buffer.size()); 
    }

    close(outfd);
}

