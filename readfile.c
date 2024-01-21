#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 2048

int main(int argc, char *argv[]) {

    int fd = open(argv[1], O_RDONLY);

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead = read(fd, buffer, BUFFER_SIZE);
    
    ssize_t bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);

    close(fd);
    return 0;
}
