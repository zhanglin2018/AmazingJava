/*
 * alarm(unsigned int seconds):
 *    Alarm function to set an alarm clock to delay sending SIGALARM signal
 *    tell the linux kernel to send SIGALARM signal after n seonds.
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
    case SIGALRM:
        cout << "SIGALRM = " << signalNumber << endl;
        alarm(1);	//recursive call the function onSignalAction
        break;
    default:
        cout << "Other Signal ..." << endl;
        break;
    }
}

void handlerINT(int signalNumber)
{
    cout << "handler Interrupt: " << signalNumber << endl;
    _exit(0);
}

 
int main()
{
    if (signal(SIGALRM,onSignalAction)== SIG_ERR)
    {
        perror("signal error");
        return -1;
    }

    if (signal(SIGINT, handlerINT)== SIG_ERR)
    {
        perror("signal error");
        return -1;
    }
    
 
    alarm(1);
 
    while(true)
    {
        pause();
        cout << "pause returned..." << endl;
    }
 
    return 0;
}
