#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <wait.h>
using namespace std;

/*
 * int execlp(const char *file, const char* arg, ...);
 *
 * The number of the arguments are variable and the augument must end with a NULL pointer.
 *
 *
 */


int main()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        if (execlp("/bin/pwd", "pwd", NULL) == -1)
            cout << "execlp pwd error" << endl;
    }
    wait(NULL);
 
    pid = fork();
    if (pid == 0)
    {
        if (execlp("/bin/ls", "ls", "-l", NULL) == -1)
            cout << "execlp ls -l error" << endl;
    }
	
    wait(NULL);

    pid = fork();
    if (pid == 0)
    {

        char *const args[] =
        {
            (char *)"/bin/date",
            (char *)"+%F",
            NULL
        };
        execve("/bin/date",args,NULL);
        cout << "After fork..." << endl;
    }

    cout << "After execlp" << endl;
}
