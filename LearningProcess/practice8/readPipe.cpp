#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <fcntl.h>
#include <signal.h>
#include <string>
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
    
 

    int infd = open("myFifo", O_RDONLY);    //read FIFO
    if (infd == -1 )
    {
        perror("open file/fifo error");
	_exit(-1);
    }
 
    char buf[BUFSIZ] = "";
    int readBytes;

    while (true)
    {
        readBytes = read(infd, buf, sizeof(buf));
        if (readBytes < 0)
        {
	    perror("read error");
	    _exit(-1);
        }

        cout << string(buf, buf+readBytes) << endl;
        
        if (string(buf, buf+readBytes).compare("quit") == 0)
        {
	    break;
        }
    }
 
    unlink("myFifo");   //delete FIFO
}

