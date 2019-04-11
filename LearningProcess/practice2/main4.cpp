#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
using namespace std;

/*
 * You could test the main4 program:
 *     1: ./main4
 *     2: ./main4 > temp.file
 *
 *
 * std::endl: it will flush the buffer
 *
 * No buffer, row buffer, and block buffer
 *
 * 1: The standard error output is unbuffered, which means it will sent out the content as soon as
 * you write date to stderr.
 *
 * 2: Standard output is divided into two cases.
 *    if the output is directed to a device terminal, then used the line buffer.
 *    if the output is the device or file, then used the block buffer.
 *
 * Note that:
 *   when redirected to the file output, the print contents will be in the buffer.
 *   fork function will copy the current buffer and its content, but at the end of the process, the 
 *   system will automatically flush the buffer.
 *   
 *   fork() will copy the current buffer and its content when redirected to the file output.
 *   but will not copy the buffer when output to the device terminal.
 *
 * Note that:
 *  std::endl: it will flush the buffer.
 *
 * Note that:
 *  1: The all file descriptor of the process will be copyed to the child process.
 *     the parent and child process will shared the same file descriptor, file table and the file offset.
 *
*/
 
int main(int argc, char *argv[])
{
    signal(SIGCHLD, SIG_IGN);
 
    int fd = open("test.txt", O_WRONLY|O_CREAT|O_TRUNC, 0666);
    if (fd == -1)
    {
        cout << "file open error" << endl;
  	exit(-1);
    }

    cout << "We Don`t flash memory0\n" ;
    cout << "We Don`t flash memory1\n" ;
    cout << "We Don`t flash memory2\n" ;
    cout << "We Don`t flash memory3\n" ;
    
 
    char buf[1024] = "";
 
    pid_t pid = fork();

    if (pid < 0)
        cout << "fork error" <<endl;
    else if (pid > 0)   // the parent process
    {
        strcpy(buf, "Parent...");
        write(fd, buf, strlen(buf));
        close(fd);
        cout << "fd = " << fd << endl;
        exit(0);
    }
    else if (pid == 0)  // the child process
    {
        strcpy(buf, "Child...");
        write(fd, buf, strlen(buf));
        close(fd);
        cout << "fd = " << fd << endl;
        exit(0);
    }
}
