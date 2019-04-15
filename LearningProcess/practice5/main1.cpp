#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <iostream>
using namespace std;

/*
 * Interrupt:
 *     Hardware interrupt ( external interrupt)
 *     Software interrupt ( internal interrupt)
 *
 * Signal:  man 7 signal
 *
 * Similaritied between signal and interrupt
 *     1: adopt the asynchronous communication mode
 *     2: when a signal or interrupt request is detected, the executing program is suspended and transferred to the corresponding handler.
 *     3: return the original breakpoint after processing.
 *     4: signal or interrupt can be shielded.
 *
 * Difference between signal and interrupt
 *     1: the interrupt has priority while the signal has no priority, so all the sinals are equal.
 *     2: the signal processing program runs in the user state, while the interrupt processing program runs in the kernel state.
 *     3; the interrupt response is timely while the sinal process usually has a large time delay.
 *
 * The response of a process to a signal:
 *   1: ignore the signal
 *      Nothing is done, and two signals cannot be ignored, SIGKILL and SIGSTOP.
 *
 *   2: capture and process signals
 *      the kernel interrupts the executing code to execute the previously registed handler.
 *
 *   3: perform default action
 *      the default action is usually to terminate the process, depending on the specified signals.
 *
 *  typedef void (*__sighandler_t) (int);
 *  #define SIG_ERR ((__sighandler_t) -1)
 *  #define SIG_DFL ((__sighandler_t) 0)
 *  #define SIG_IGN ((__sighandler_t) 1)
 *  
 *  __sighandler_t signal(int signum, __sighandler_t handler);
 *
 * 
 * 
 *
 *
 */

void handler(int sigNum)
{
    cout << "receive a signal = " << sigNum << endl;
    exit(10);
}

int main(int argc, char* argv[])
{
    signal(SIGINT, handler); // interrupt from keyboard

    while (true)
    {
        sleep(1);
    }
}











