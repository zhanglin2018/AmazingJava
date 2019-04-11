#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
    signal(SIGCHLD, SIG_IGN);
 
    int processCount;
    cin >> processCount;
	
    for (int i = 0; i < processCount; ++i)
    {
        pid_t pid = fork();
		
        if (pid < 0)
            cout << "fork error" <<endl;
        else if (pid == 0) // the child process
        {
            cout << "Child process id: " << getpid() << " : " << i <<  endl;
            exit(0);
        }
    }
 
    exit(0);
}

