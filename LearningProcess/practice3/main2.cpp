#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
using namespace std;

/*
 * _exit is a system call and exit is a c library function
 * exit will clear the I/O cache, such as buffer in memory
 * exit will execute the call to the termination handler
 * 
 * Note that:
 *     atexit(void (*fun)(void)) : could be used register exit handler function.
 */

void exitHandler1(void)
{
    cout << "If exit with exit, the function exitHandler will be called1" << endl;
}
void exitHandler2(void)
{
    cout << "If exit with exit, the function exitHandler will be called2" << endl;
}
 
int main()
{
    cout << "In main, pid = " << getpid() << endl;

    atexit(exitHandler1);	//

    atexit(exitHandler2);

    exit(0);
    //_exit(0);
    //abort();

}


