#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <iostream>
using namespace std;

/*
 * How to avoid zombie process
*/

int main(int argc, char *argv[])
{
    signal(SIGCHLD, SIG_IGN);  // use the signal function to avoid the zombie process.
    
    pid_t pid = fork();

    if (pid < 0)
        cout << "fork error" <<endl;
    else if (pid == 0) // the child process
        exit(0);
    else               // the parent process
    {
        sleep(20);
    }
    exit(0);
}
