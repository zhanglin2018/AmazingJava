/*
 * Linux 3.x supports 64 signals
 *    Both sigaction and signal functions call the kernel service do_signal function. Kernel service function that
 *    an application cannot call.
 *
 *  The first 31 signals already have predefined values, each with a defined purpose and meaning, its own default action.
 *
 *  Non-real-time signals do not support queuing, are unrealiable signals;
 *  Real time signals support queuing, are reliable signals.
 *
 * Important: sleep() : the child process sends a signal to the parent process, sleep function of several points
 *
 * 1: sleep() , let the process sleep
 * 2: can be interrupted by signals, and then no longer sleep after processing the signal function. Exectute the code directly down.
 * 3: the return value of sleep funciton is the remaining seconds.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <iostream>
using namespace std;

void onSignalAction(int signalNumber)
{
    switch(signalNumber)
    {
    case SIGUSR1:
        cout << "SIGUSR1 = " << signalNumber << endl;
        break;
    default:
        cout << "Other Signal ..." << endl;
        break;
    }
}
 
int main()
{
    if (signal(SIGUSR1,onSignalAction)== SIG_ERR)
    {
        cout << "signal error" << endl;
        return -1;
    }
 
    pid_t pid = fork();
    if (pid == -1)
    {
        cout << "fork error" << endl;
        return -1;
    }
    else if (pid == 0)
    {
        // send a signal to the parent process
        pid_t ppid = getppid();
        cout << "parent process pid: " << ppid << endl;
        kill(ppid,SIGUSR1);
        
 
        // send a signal to all process in the same group, and the child process receive the signal  as well.
        //kill(0,SIGUSR1);
        
 
        // funtion that gets the process group pid

        //pid_t pgid = getpgrp();
        //cout << "process group pid : " << pgid << endl;
        //killpg(pgid,SIGUSR1);
        exit(0);
    }
 
    int sleepTime = 3;
    while (sleepTime > 0)
    {
        write(STDOUT_FILENO, "Parent start Sleep...\n",
              sizeof("Parent start Sleep...\n"));
        sleepTime = sleep(sleepTime); // can be interrupted by other process.
        write(STDOUT_FILENO,"Parent return from Sleep...\n",
              sizeof("Parent return from Sleep...\n"));
    }
 
    return 0;
}
