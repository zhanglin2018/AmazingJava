/*
 * sleep() function: let the process sleep.
 * can be interrupted by signals, and then execute the code directly down.
 * return the remaining seconds of the sleep function.
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
    case SIGINT:
        cout << "SIGINT = " << signalNumber << endl;
        break;
    default:
        cout << "Other Signal ..." << endl;
        break;
    }
}
 
int main()
{
    if (signal(SIGINT,onSignalAction)== SIG_ERR)
    {
        perror("signal error");
        return -1;
    }
    cout << "Main Start Sleeping..." << endl;
    int returnValue = sleep(100); // can be interrupted
    cout << "Main End Sleeping... returnValue = " << returnValue << endl;
	
    int sleepTime = 20;
    do
    {
        sleepTime = sleep(sleepTime);
        cout << "continue..." << endl;
    }
    while (sleepTime > 0);
	
    cout << "Main End Sleeping... sleepTime = " << sleepTime << endl;
 
    return 0;


}
