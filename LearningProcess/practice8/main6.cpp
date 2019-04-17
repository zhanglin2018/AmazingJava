#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <iostream>
using namespace std;

/*
 * rule4:
 *
 *     if the file descriptors corresponding to all pipe readers are closed,
 *     the write operation will generate singal SIGPIPE: signal number is 13
 *
 *
 *
 */

void handler(int signalNum)
{
	cout << "signalNum: " << signalNum << endl;
}

int main()
{
    if (signal(SIGPIPE, handler) == SIG_ERR)
        perror("signal error");
 
    int pipefd[2];
    if (pipe(pipefd) != 0)
        perror("pipe error");
 
    pid_t pid = fork();
    if (pid == -1)
        perror("fork error");
    else if (pid == 0)
    {
        close(pipefd[0]);
        exit(EXIT_SUCCESS);
    }
 
    close(pipefd[0]);
    sleep(2);
    char test = 'A';
	
    if (write(pipefd[1], &test, sizeof(test)) < 0)
        perror("write error");

    cout << "perror after" << endl;
}


