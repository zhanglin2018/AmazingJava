#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
#include <unistd.h>
#include <signal.h>
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


void printStatus(int status)
{
    if (WIFEXITED(status))
    {
        cout << "normal termination, exit status = " << WEXITSTATUS(status) << endl;
    }
    else if (WIFSIGNALED(status))
    {
        cout << "abnormal termination, signal number = " << WTERMSIG(status);
#ifdef WCOREDUMP
        if (WCOREDUMP(status))
            cout << " (core file generated)" << endl;
#else
        cout << endl;
#endif // WCOREDUMP
    }
    else if (WIFSTOPPED(status))
    {
        cout << "child stopped, status number = " << WSTOPSIG(status) << endl;
    }
    else
    {
        cout << "Unknow Stop!" << endl;
    }
}
 
int main()
{
    pid_t pid = fork();
	
    if (pid == -1)
        cout << "the first fork error ";
    else if (pid == 0)
        exit(7);
 
    int status;
    if (wait(&status) == -1)
        cout << "first wait error";
    printStatus(status);
 
    pid = fork();
    if (pid == -1)
        cout << "the second fork error";
    else if (pid == 0)
    {
        //abort();
        exit(100);
    }
 
    if (wait(&status) == -1)
        cout << "second wait error";
    printStatus(status);
 
    pid = fork();
    if (pid == -1)
        cout << "the third fork error ";
    else if (pid == 0)
    {
        int arr[5] = {1, 2, 3, 4, 5};
        arr[4] = 10;
        exit(125);
    }
     
 
    if (wait(&status) == -1)
        cout << "third wait error";
    cout << status << endl;
 
    return 0;
}
