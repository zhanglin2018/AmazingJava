#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>

using namespace std;

int main2(int argc, char** argv) {
	const char* FIFO = "/tmp/myInfo";
	char buffer[100];
	int fd;
	cout << "start read : \n" << endl;
	unlink(FIFO);
	mkfifo(FIFO, 0666);

	char str[] = "hello, world!";
	fd = open(FIFO, O_RDONLY);
	cout << "start read the content: \n" << endl;

	while (true) {
		sleep(10);
		read(fd, buffer, 100);
	}
	close(fd);
}

