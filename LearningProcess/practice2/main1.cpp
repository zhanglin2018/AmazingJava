#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <iostream>
using namespace std;

/*
 *if the parent process exits first and the chld does not exit,
 *the child's parent process becomes the init process.
 *Note that: any process must have a parent process.
*/

int main(int argc, char *argv[])
{
    pid_t pid = fork();

    if (pid < 0)
        cout << "fork error" << endl;
    else if (pid > 0)  // the parent process
    {    
	cout << "parent, pid=" << getpid() << " child, pid= " << pid <<  endl;
        exit(0);
    }
    else               // the child process
    {
        sleep(10);
        cout << "Child, pid = " << getpid() << " Parent, pid=" << getppid() << endl;
    }
    exit(0);
}
