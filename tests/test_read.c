#include <tests.h>

int test_read() {
    int fd;
    char ch;
    char my_ch ;

    fd = open("./hello.txt", O_RDONLY);
    if (fd < 0) {
      fprintf(stderr, "Error open file\n");
      exit(1);
    }

    while (read(fd, &ch, 1) > 0) {
      write(1, &ch, 1);
    }

    while (ft_read(fd, &my_ch, 1) > 0) {
       write(1, &my_ch, 1);
    }
    close(fd);

    return 0;
}