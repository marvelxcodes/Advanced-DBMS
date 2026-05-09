#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main() {

    // Reading
    int fd = open("file.txt", O_RDONLY);
    if (fd < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return 1;
    }

    char buff[513];
    int bytes_read = read(fd, buff, 512);

    if (bytes_read < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return 1;
    }

    if (bytes_read < 512)
        buff[bytes_read] = '\0';

    printf("%d bytes read\n", bytes_read);
    printf("%s\n", buff);

    close(fd);

    // Writing
    fd = open("file.txt", O_WRONLY | O_APPEND);
    if (fd < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return 1;
    }

    char to_write[] = "abcd\n";
    int bytes_written = write(fd, to_write, sizeof(to_write) - 1);

    if (bytes_written < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return 1;
    }

    printf("%d bytes written\n", bytes_written);

    close(fd);

    return 0;
}