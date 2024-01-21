#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int input_fd;
    int bytes_read;
    char buffer[2048];
    
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            
            input_fd = open(argv[i], O_RDONLY);
            
            
            while ((bytes_read = read(input_fd, buffer, sizeof(buffer))) > 0) {
                write(STDOUT_FILENO, buffer, bytes_read);
            }

            close(input_fd);
        }
    } else {
        while ((bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0) {
            write(STDOUT_FILENO, buffer, bytes_read);
        }
    }
    
    return 0;
}
