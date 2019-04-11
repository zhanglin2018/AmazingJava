#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    signal(SIGCHLD, SIG_IGN);
    int count = 10;
    pid_t pid = fork();
    if (pid == -1)
    {
        cout << "error occured." << endl;
        exit(-1);
    }
     
    else if (pid == 0)  // the child process
    {
        count += 5;
        cout << "In child: pid = " << getpid() << ", ppid = " << getppid() << endl;
        cout << "count = " << count << endl;
    }
    else if (pid > 0)   // the parent process
    {
        count += 10;
        cout << "In parent: pid = " << getpid() << ", child pid = " << pid << endl;
        cout << "count = " << count << endl;
    }
 
    exit(0);
}

