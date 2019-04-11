#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <iostream>
using namespace std;

/*
 * Zombie process:
 *   if the child process exits first, the parent didn't quit,
 *   then the child must wait until the parent captures the child exit status
 *   otherwise the child process will become a zombie process.
*/

int main(int argc, char *argv[])
{
    pid_t pid = fork();
	
    if (pid < 0)
        cout << "fork error" <<endl;
    else if (pid == 0) // the child process
        exit(0);
    else               // the parent process
    {
        sleep(10);
    }
    exit(0);
}
