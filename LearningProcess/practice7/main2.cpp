#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <iostream>
using namespace std;


int main()
{
    int pipefd[2];
    if (pipe(pipefd) == -1)
        cout << "pipe error" << endl;
 
    pid_t pid = fork();
    if (pid == -1)
        cout << "fork error" << endl;
    if (pid == 0)   
    {
        close(pipefd[0]);   
        
        dup2(pipefd[1], STDOUT_FILENO); 
        close(pipefd[1]);
 
        execlp("/bin/ls", "ls", NULL);
        
        cerr << "child execlp error" << endl;;
        exit(EXIT_FAILURE);
    }
 
    //parent process 
    close(pipefd[1]);   //close write end
    
    dup2(pipefd[0], STDIN_FILENO);
    close(pipefd[0]);
 
    execlp("/usr/bin/wc", "wc", "-w", NULL);
    cerr << "parent execlp error" << endl;
    exit(EXIT_FAILURE);
}

