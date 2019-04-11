#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	string str1 = "hello, world";
	string str2 = str1 + to_string(10);


	const char* FIFO = "/tmp/myInfo";
	char buffer[100];
	int fd;
	cout << "start write : \n" << endl;
	unlink(FIFO);
//	int res = mkfifo(FIFO, S_IFIFO | 0777);
	int res = mkfifo(FIFO, 0777);
	if (res == -1) {
		cout << "mk fifo file error. " << endl;
	}

	char str[] = "hello, world!";
	fd = open(FIFO, O_WRONLY | O_NONBLOCK);
	if (fd < 0) {
		cout << "open fifo file error. " << endl;
	}

	cout << "start write the content: \n" << endl;
	int count = 0;
	while (true) {
		sleep(10);
		cout << "start the " << count << " count write" << " hello, world"
				<< endl;
		write(fd, str, sizeof(str));
		count++;
		if (count > 10) {
			break;
		}
	}
	close(fd);
}

