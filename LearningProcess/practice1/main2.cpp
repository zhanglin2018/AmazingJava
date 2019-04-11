#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    signal(SIGCHLD, SIG_IGN);
    fork();
    fork();
    fork();
    cout << "Hello World" << endl;
 
    exit(0);
}

