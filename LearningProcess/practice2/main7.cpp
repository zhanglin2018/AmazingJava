#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <iostream>
using namespace std;

/*
 *
 * you could use the function execve() to call a executable program.
 *
 * 
*/


int main()
{
    int iNumber = 0;
    pid_t pid = fork();
 
    if (pid == -1)
    {
        cout << "fork error." << endl;
        return -1;
    }
    else if (pid > 0)
    {
        cout << "In Parent Program..." << endl;
        cout << "iNumber = " << iNumber << endl;
        cout << "pid = " << static_cast<int>(getpid());
        cout << "\t ppid = " << static_cast<int>(getppid()) << endl;
 
    }
    else if (pid == 0)
    {
        iNumber ++;
        cout << "In Child Program..." << endl;
        cout << "iNumber = " << iNumber << endl;
        cout << "pid = " << static_cast<int>(getpid());
        cout << "\t ppid = " << static_cast<int>(getppid()) << endl;
 

        execve("../practice1/main2",NULL,NULL);
        _exit(0);
    }
 
    return 0;
}
