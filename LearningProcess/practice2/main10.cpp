#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/*
 * Note:
 *     Each time a file is writen, it is simply written to a buffer in memory.
 *     Certain conditions are met(a certain number is reached, or certain characters are encoutered,
 *     such as newline and EOF).
 *
 * Note that the function of the sign \n is that:
 *    it could write the content of buffer in memory into the file when you are using the printf or cout function.
 *    it could flush the memory buffer.
 *
 * cout << endl;   endl could represents both flushing the memory buffer and going to the new line.
 *
 * exit() and _exit() difference:
 *
 * _exit() system call funciton:
 *     1: declare in the <unistd.h> file
 *        .stop the running process
 *        .clear the memory space it uses
 *        .destroy its varous date structure in the kernel.
 *
 * exit() :
 *     1: decalre in the <stdlib.h> file
 *        .check the opening file description and writes the contents of the file buffer back to the file.
 *         which is called "clear I/O buffer."
 *        .impleted the function of _exit();
 *
 * return value:
 *     0: return successfully
 *    -1: return failurely
 *
*/


int main(int argc, const char *argv[])
{
    int flag = 0;
    if (argc <= 1)
    {
        flag = 0;
    }
    else if (argc == 2 && strcmp(argv[1], "exit") == 0)
    {
        flag = 0;
    }
    else if (argc == 2 && strcmp(argv[1], "_exit") == 0)
    {
        flag = 1;
    }

    cout << "one!\n";  // note that the sign \n could write the buffer into the file.

    if (flag == 0)
    {
        cout << "exit(0)\n";
        exit(0);//print one!
    }
    else
    {
        cout << "_exit(0)";
        _exit(0);//print nothing
    }

    cout << "two!";

    return 0;
}

