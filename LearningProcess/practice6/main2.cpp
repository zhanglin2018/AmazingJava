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
    if (signal(SIGINT,onSignalAction) == SIG_ERR)
    {
        perror("signal error");
        return -1;
    }
    cout << "Main Start Sleeping..." << endl;
    int returnValue = sleep(100); // can be interrupted
    cout << "Main End Sleeping... returnValue = " << returnValue << endl;
 
}
