#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int
main(int argc, char *argv[])
{
    char ch;
    int fd;
    int opt;

    while ((opt = getopt(argc, argv, ":at")) != -1){
        switch (opt) {
            case 'a':
                fd = open(argv[2], O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
                break;
            case 't':
                fd = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
                break;
        }
    }

    while(read(STDIN_FILENO, &ch, 1) > 0)
    {
        write(STDOUT_FILENO, &ch, 1);
        write(fd, &ch, 1);
    }
    return EXIT_SUCCESS;
}