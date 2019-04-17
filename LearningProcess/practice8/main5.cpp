#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <iostream>
using namespace std;

/*
 * rule3:
 *
 *     if the file descriptors corresponding to all pipe write ends are closed, read will return 0.
 *
 */

int main()
{
    int pipefd[2];
    if (pipe(pipefd) != 0)
        perror("pipe error");
 
    pid_t pid = fork();
	
    if (pid == -1)
        perror("fork error");
    else if (pid == 0)
    {
        close(pipefd[1]);
        exit(EXIT_SUCCESS);
    }
 
    close(pipefd[1]);
    sleep(2);
    char buf[2];
	
    if (read(pipefd[0], buf, sizeof(buf)) == 0)
        cout << "sure" << endl;
}

