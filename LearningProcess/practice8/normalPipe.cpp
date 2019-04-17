/*
 *  anonymous pipe can only be used for communication between process with common ancestor
 *  
 *  int pipe(int pipefd[2]);
 *
 *  create an anonymous pipe
 *  pipefd: array of file descriptors, where
 *  pipefd[0] represents the read end
 *  pipefd[1] represents the write end
 */

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char** argv)
{
	int n;
	int fd[2];
	pid_t pid;
	char line[100];
	
	// Set up the pipe to get a pair of file descriptors
	if (pipe(fd) == -1){
		std::cout << "Error occurs: create pipe fail." << std::endl;
		exit(0);
	}
	
	//The parent process copies the file descriptor to the child process
	if ((pid = fork()) == -1){
		std::cout << "Error occurs: create the process fail." << std::endl;
		exit(0);
	} else if (pid > 0){         // the parent process to write 
		close(fd[0]);        // close the read descriptor
		std::cout << "The process id is : " << getpid() 
		          <<   "\nThe parent process to write : " << std::endl;
		write(fd[1], "hello world\n", 14);
	} else if (pid == 0){     // the child process to read
		close(fd[1]);     // close the write descriptor
		n = read(fd[0], line, 100);
                write(STDOUT_FILENO, line, n);
		std::cout << "\nThe process id is : " << getpid() 
		          << "\nThe child process to read : \n" << line << std::endl;
	}
	
	return 0;
}
