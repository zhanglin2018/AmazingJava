/*
 * pipe is space time:
 *    O_NONBLOCK disable: read calls block where the process pauses until data arrives.
 *    O_NONBLOCK enable:  read calls return -1, errno value is EAGAIN.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <iostream>
using namespace std;

int main()
{
    int pipefd[2];
    if (pipe(pipefd) != 0)
        cout << "pipe error" << endl;
 
    pid_t pid = fork();
    if (pid == -1)
        cout << "fork error" << endl;
 
    if (pid == 0)   //In Child, Write pipe
    {
        sleep(10);
        close(pipefd[0]);   //Close Read pipe
        string str("I Can Write Pipe from Child!");
 
        write(pipefd[1],str.c_str(),str.size());    //Write to pipe
        close(pipefd[1]);
        exit(EXIT_SUCCESS);
    }
 
    //In Parent, Read pipe
    close(pipefd[1]);   //Close Write pipe
    char buf[1024] = {0};
 
    //Set Read pipefd UnBlock! ???????????????????
//    int flags = fcntl(pipefd[0],F_GETFL, 0);
//    flags |= O_NONBLOCK;
//    if (fcntl(pipefd[0],F_SETFL,flags) == -1)
//        err_exit("Set UnBlock error");
 
 
    int readCount = read(pipefd[0],buf,sizeof(buf));    //Read from pipe
    if (readCount < 0)
        //read return immediately
        cout << "read error" << endl;
 
    cout << "Read from pipe: " << buf << endl;
    close(pipefd[0]);
}


