#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <iostream>
using namespace std;

/*
 * Learning the family functions execve, you could use the shell command : man 3 execve  
 *
 *
*/


int main()
{
    int iNumber = 0;
    pid_t pid = vfork();
 
    if (pid == -1)
    {
        cout << "fork error. " << endl;
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
 
        char *const args[] = {(char *)"/bin/ls", (char *)"-l", NULL};
        int res = execve("/bin/ls",args,NULL);
        if (res == -1)
        {
            cout << "execve error." << endl;
            _exit(1);
        }
        _exit(0);
    }
 
    return 0;
}

