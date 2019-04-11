#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>

using namespace std;

int mainNamePipe(int argc, char** argv){
//int mainNamePipe(int argc, char** argv){
	const char* FIFO = "/tmp/myInfo";
	char buffer[100];
	int fd;
//	unlink(FIFO);
	mkfifo(FIFO, 0777);
	
	if (fork() > 0){
		char str[] = "hello, world!";
		fd = open(FIFO, O_WRONLY);
		write(fd, str, sizeof(str));
		close(fd);
	} else {
		fd = open(FIFO, O_RDONLY);
		read(fd, buffer, 100);
		cout << buffer << endl;
		close(fd);
	}
}
	
		
