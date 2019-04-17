#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
using namespace std;

/*
 * Linux Pipe Features:
 *
 *     when the amount of data to be written is no greater than PIPE_BUF, linux will ensure the atomicity of the write operation.
 *     when the amount of data to be written is greater tran PIPE_BUF, linux will no longer guarantee the atomicity of the write operation.
 *
 */

int main()
{
    const int TEST_BUF = 68 * 1024; //the data is 68K
    char bufA[TEST_BUF];
    char bufB[TEST_BUF];
    memset(bufA, 'A', sizeof(bufA));
    memset(bufB, 'B', sizeof(bufB));
 
    int pipefd[2];
    if (pipe(pipefd) != 0)
    {
        perror("pipe error");
		_exit(-1);
    }
 
    pid_t pid;
    if ((pid = fork()) == -1)
    {
        perror("first fork error");
		_exit(-1);
    }
	
    else if (pid == 0)  //the first child process write the A char to pipe
    {
        close(pipefd[0]);
        int writeBytes = write(pipefd[1], bufA, sizeof(bufA));
        cout << "A Process " << getpid() << ", write "
             << writeBytes << " bytes to pipe" << endl;
        exit(EXIT_SUCCESS);
    }
 
    if ((pid = fork()) == -1)
    {
        perror("second fork error");
		_exit(-1);
    }
	
    else if (pid == 0)  // the second child process write the B char to pipe
    {
        close(pipefd[0]);
        int writeBytes = write(pipefd[1], bufB, sizeof(bufB));
        cout << "B Process " << getpid() << ", write "
             << writeBytes << " bytes to pipe" << endl;
        exit(EXIT_SUCCESS);
    }
 
    // parent process
    close(pipefd[1]);
    sleep(2);  
    char buf[4 * 1024]; 
	
    int fd = open("./test.txt", O_WRONLY|O_TRUNC|O_CREAT, 0666);
    if (fd == -1)
    {
        perror("file open error");
		_exit(-1);
    }
 
    while (true)
    {
        int readBytes = read(pipefd[0], buf, sizeof(buf));
		
        if (readBytes == 0)
            break;
			
        if (write(fd, buf, readBytes) == -1)
	{
            perror("write file error");
	    _exit(-1);
	}
		
        cout << "Parent Process " << getpid() << " read " << readBytes
             << " bytes from pipe, buf[4095] = " << buf[4095] << endl;
    }
}

