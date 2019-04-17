#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <iostream>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
using namespace std;

/*
 * O_NONBLOCK disable: write calls block until a process reads the data
 */

void handler(int signalNumber)
{
    cout << "handler pipe: " << signalNumber << endl;
    _exit(0);
}



int main(int argc, char* argv[])
{
    if (signal(SIGPIPE, handler) == SIG_ERR)
        perror("signal error: ");
 
    int pipefd[2];
    if (pipe(pipefd) != 0)
        perror("pipe error");
    
    if (argc >= 2)
    {
    
        int flags = fcntl(pipefd[1], F_GETFL, 0);
        if (fcntl(pipefd[1], F_SETFL, flags|O_NONBLOCK) == -1)
        perror("fcntl set error");
    }
 
    int count = 0;
    while (true)
    {
        if (write(pipefd[1], "A", 1) == -1)
        {
            cerr << "write pipe error: " << strerror(errno) << endl;
            break;
        }
        ++ count;
        cout << "pipe size = " << count << endl;
    }
 
    cout << "pipe size = " << count << endl;
}
