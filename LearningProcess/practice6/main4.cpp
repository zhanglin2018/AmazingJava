/*
 * pause():
 *    set the process to interruptable sleep, it calls the kernel function schedule() to have the  linux process s
 *    scheduler find another process to run.
 *
 * Note:
 *    Pause suspends the caller process until a signals is caught.
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
    case SIGINT:
        cout << "SIGINT = " << signalNumber << endl;
        break;
    default:
        cout << "Other Signal ..." << endl;
        break;
    }
    _exit(0);
}
 

int main()
{
    if (signal(SIGINT, onSignalAction)== SIG_ERR)
        cout << "signal error";
		
    while(true)
    {
	cout << "pause before : " << endl;
        pause();
        cout << "pause after..." << endl;
    }
}

