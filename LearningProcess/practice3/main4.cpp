#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <wait.h>
using namespace std;

/*
 * int system(const char* command) :  is a system call
 *
 * /bin/sh -c command
 * blocking the current process until the comamnd is executed,
 * when the system function executes, it calls functions such as
 * fork, execve, waitpid, and so on.
 *
 */



int mySystem(const char *command)
{
    if (command == NULL)
    {
        cout << "command is NULL" << endl;
        return -1;
    }

    pid_t pid = fork();
    if (pid == -1)
    {
        cout << "fork error" << endl;
        exit(-1);
    }

    else if (pid == 0)
    {
        execl("/bin/sh","sh","-c",command,NULL);
        exit(127);
    }
 
    int status;
    //waitpid(pid,&status,0);
    wait(&status); 

    return WEXITSTATUS(status);
}

int main()
{
    int status = mySystem("ls -la");
    cout << "status : " << status << endl;

    return 0;
}
