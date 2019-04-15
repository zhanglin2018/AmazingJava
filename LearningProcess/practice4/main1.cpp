#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
#include <unistd.h>
using namespace std;



/*
 * Wait
 *   1: When the child process exits, the kernel sends a SIGCHLD signal to the parent, which is a asynchronous
 *      event(the child can terminate at any time while the parent process is running)
 *    
 *   2: When the child process exits, the kernel sets the child process to a zombie state. This process is called
 *      a zombie process, and it keeps only the smallest kernel data structures so that the parent process can query
 *      the exit state of the child process.
 *
 *   3: The parent process can query the exit state of the child process using the wait/waitpid function.
 *
 *   #include <sys/types.h>
 *   #include <sys/wait.h>
 *
 *   pid_t wait(int *status);
 *   pid_t waitpid(pid_t pid, int *status, int options);
 *
 *   4: when we fork a process, the child process has its own life ans will run independently. Sometimes, we need to 
 *      know if a child process has ended, so we can arrange for the parent process to finish after the child process
 *      by waiting. 
 *
 *   5: return states: 
 *      on success : return the process id of the terminated process
 *      on error   : return -1
 *
 *   6: The wait system call causes the parent process to suspend execution until any (but not all) of its child process have finished.
 *
 *   7: if status is not a null pointer, the status information is written to the position it points to.
 *
 *
 *
 *
 *
 */


int main()
{
    pid_t pid = fork();
    if (pid == -1)
    {
	cout << "fork error" << endl;
    }
    else if (pid == 0)
    {
	cout << "In child, pid = " << getpid() << endl;
        sleep(5);
        exit(10);
    }

    int status;
    int returnPid = wait(&status);

    cout << "In parent, returnPid = " << returnPid << ", status = " << status << endl;
}
