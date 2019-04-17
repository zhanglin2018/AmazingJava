/*
 *  anonymous pipe can only be used for communication between process with common ancestor
 *  
 *  int pipe(int pipefd[2]);
 *
 *  create an anonymous pipe
 *  pipefd: array of file descriptors, where
 *  pipefd[0] represents the read end
 *  pipefd[1] represents the write end
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <iostream>
using namespace std;

//send data from child process to parent process.


int main()
{
    int fd[2];
    if (pipe(fd) == -1)
        cout << "pipe error" << endl;
 
    pid_t pid = fork();
    if (pid == -1)
        cout << "fork error" << endl;
    if (pid == 0)   
    {
        close(fd[0]);   //close read end
        string str("message from child process!");
        write(fd[1], str.c_str(), str.size());  
        close(fd[1]);
        exit(EXIT_SUCCESS);
    }
 
    close(fd[1]);   // close write end
    char buf[BUFSIZ] = {0};
    read(fd[0], buf, sizeof(buf));
    close(fd[0]);
    cout << buf << endl;
}

