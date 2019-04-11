#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <iostream>
#include <stdio.h>
using namespace std;

/*
 * vfork() has the limitation that the child process must execute _exit() or exec()
 * series functions immediately.
 *
 * vfork(): the child process share date segments with the parent process, so the parent
 * and child process updates the data synchronously.
 * vfork(): the child process execute first, followed by the parent process.
 *
 *
 *
*/


int main()
{
    int iNumber = 0;
    pid_t pid = vfork();
 
    if (pid == -1)
    {
        perror("fork");
        return -1;
    }
    else if (pid > 0)
    {
        cout << "In Parent Program..." << endl;
        cout << "iNumber = " << iNumber << endl;
        cout << "pid = " << static_cast<int>(getpid());
        cout << "\t ppid = " << static_cast<int>(getppid()) << endl;
        _exit(0);
    }
    else if (pid == 0)
    {
        iNumber ++;
        cout << "In Child Program..." << endl;
        cout << "iNumber = " << iNumber << endl;
        cout << "pid = " << static_cast<int>(getpid());
        cout << "\t ppid = " << static_cast<int>(getppid()) << endl;
       _exit(0);
    }
                                                                 
    return 0;
}

