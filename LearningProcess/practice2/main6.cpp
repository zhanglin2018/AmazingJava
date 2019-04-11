#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

/*
 * vfork() the child process share the data segments with the parent process.
 * fork() implemented the copy-on-write technology.
 *
 *
 *
 *
*/


int main(int argc, char* argv[])
{
    int iNumber = 10;
    cout << "Before vfork, pid = " << getpid() << endl;
 
    // you could compare the fork();
    pid_t pid;
    if (argc <= 1)
    {
        pid = vfork();
    }
    else if (argc == 2 && strcmp(argv[1], "fork") == 0)
    {
        pid = fork();
    }
    else if (argc == 2 && strcmp(argv[1], "vfork") == 0)
    {
        pid = vfork();
    }
 
    if (pid == -1)
        perror("fork");
    else if (pid > 0)
    {
        sleep(4);
        cout << "Parent, iNumber: " << iNumber << endl;
    }
    else if (pid == 0)
    {
        ++ iNumber;
        cout << "Child, iNumber = " << iNumber << endl;
        _exit(0);
    }
 
    return 0;
}
