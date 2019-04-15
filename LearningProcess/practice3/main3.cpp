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
 * envionment variable:
 *    1: The program will use the default environment variable if no environment variable is passed in.
 *
 * Summary:
 *    l represents variable argument list
 *    p represents searching file in PATH environment variable
 *  envp represents environment variable
 */

extern char **environ;

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
        cout << "After /bin/date..." << endl;
    }

    wait(NULL);

    pid = fork();
    if (pid == 0)
    {
	char *const environ[] =
        {
            (char *)"AA=11",
            (char *)"BB=22",
            (char *)"CC=33",
            NULL
        };
        execle("./hello","./hello",NULL,environ);	//
        cout << "After hello..." << endl;
    }

    wait(NULL);

    pid = fork();
    if (pid == 0)
    {

    cout << "In hello, pid = " << getpid() << endl;
 
    cout << "environ:" << endl;
    
    for (int i = 0; environ[i] != NULL; ++i)
    {
        cout << "\t" << environ[i] << endl;
    }


        cout << "test environment." << endl;
    }

    wait(NULL);
    pid = fork();
    if (pid == 0)
    {
        char *const args[] =
        {
            (char *)"hello",
            (char *)"myarg1",
            (char *)"MY ARG2",
            NULL
        };
        char *const env[] =
        {
            (char *)"USER=unknown",
            (char *)"PATH=/tmp",
            NULL
        };
 
        execve("./hello",args,env);
    }

    wait(NULL);
 
    pid = fork();
    if (pid == -1)
        cout << "fork error" << endl;
    else if (pid == 0)
    {
        execlp("./hello", "hello", "only one arg", NULL);
    }
}
