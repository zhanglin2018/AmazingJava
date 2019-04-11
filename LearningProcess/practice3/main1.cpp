#include <stdio.h>
#include <unistd.h>
#include <iostream>
using namespace std;

/*
 * _exit is a system call and exit is a c library function
 * exit will clear the I/O cache, such as buffer in memory
 * exit will execute the call to the termination handler
 *
 */


int main(int argc, const char *argv[])
{

    cout << "In main, pid = " << getpid(); // 
   
    fflush(stdout);  // increased refresh buffer work. 
    
    _exit(0);//print nothing


    return 0;
}

