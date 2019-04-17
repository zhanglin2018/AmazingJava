/*
 * Reentrant/non-reentrant functions:
 *     A reentrant function is a procedure that can be called by multiple tasks without worring about data error.
 *     In order to enhance the stability of the program, the reetranct function should be used in the signal processing function.
 *
 *   Most functions that satisfy the following conditions are non-reetrant
 *   1: called malloc() or free() function
 *   2: used static date structure
 *   3: used the standard I/O fucntion.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <iostream>
using namespace std;


struct Teacher
{
    int a;
    int b;
    int c;
    int d;
};
 
Teacher g_teacher;

void onSigAlarm(int signo)
{
    printf("%d %d", g_teacher.a, g_teacher.b);
    printf(" %d %d\n", g_teacher.c, g_teacher.d);
    alarm(1);
}
 
int main()
{
    if (signal(SIGALRM,onSigAlarm)== SIG_ERR)
        cout << "signal error" << endl;
 
    Teacher zero = {0, 0, 0, 0};
    Teacher ones = {1, 1, 1, 1};
 
    alarm(1);

    g_teacher = zero;

    while(true)
    {
        g_teacher = zero;
        g_teacher = ones;
    }
}


/*
 * output result as follows:
 *
 * 1 1 0 0
 * 1 1 0 0
 * 0 0 1 1
 * 1 1 0 0
 * 1 1 0 0
 * 1 1 1 1
 *
 */
