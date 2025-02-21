#include <tests.h>

int test_write(const char *str) {
    int     fd_write;
    int     fd_ft_write;
    int     str_len;
    ssize_t my_result;
    ssize_t standart_result;

    str_len = strlen(str);
    //------------stdout------------
    printf("\nTest: write to stdout\n");
    printf("Output from write: \n");
    if ((standart_result = write(1, str, str_len)) == -1) {
      printf("Error to write in stdout from write");
      return 1;
    }
    printf("\nOutput from ft_write: \n");
    if ((my_result = write(1, str, str_len)) == -1) {
      printf("Error to write in stdout from ft_write");
      return 1;
    }
    printf("\nWrite length: %li  ", standart_result);
    printf("ft_write length: %li\n", my_result);
    if (my_result != standart_result) {
      printf("ERROR: Lengths DO NOT match!\n");
      return 1;
    }
     //------------file------------
    printf("\n\nTest: write to fd\n");

    fd_write = open("test_write.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    fd_ft_write = open("test_ft_write.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_write == -1 || fd_ft_write == -1) {
      perror("Error opening file");
      return 1;
    }
    standart_result = write(fd_write, str, str_len);
    my_result = write(fd_ft_write, str, str_len);
    close(fd_write);
    close(fd_ft_write);
    char buffer_write[str_len];
    char buffer_ft_write[str_len];
    fd_write = open("test_write.txt", O_RDONLY);
    if (fd_write == -1) {
        perror("Error opening file");
        return 1;
    }
    ssize_t bytes_read = read(fd_write, buffer_write, sizeof(buffer_write) - 1);
    buffer_write[bytes_read] = '\0';
    fd_ft_write = open("test_ft_write.txt", O_RDONLY);
    if (fd_ft_write == -1) {
        perror("Error opening file");
        return 1;
    }
    bytes_read = read(fd_ft_write, buffer_ft_write, sizeof(buffer_ft_write) - 1);
    buffer_ft_write[bytes_read] = '\0';
    close(fd_write);
    close(fd_ft_write);


    printf("Write length: %li\n", strlen(buffer_write));
    printf("ft_write length: %li\n", strlen(buffer_ft_write));
    if ( strlen(buffer_write) !=  strlen(buffer_ft_write)) {
      printf("ERROR: Lengths DO NOT match!\n");
      return 1;
    }

    printf("\n\nTest: wrong fd\n");
    printf("Write to file from write: \n");
    standart_result = write(68, "Wrong test", str_len);
    my_result = write(68, "Wrong test", str_len);
    printf("write result: %li\n", standart_result);
    printf("ft_write result: %li\n", my_result);
    if ( standart_result !=  my_result) {
      printf("ERROR: Lengths DO NOT match!\n");
      return 1;
    }
    printf("OK: Results match!\n");
    close(fd_write);
    close(fd_ft_write);
    return 0;
  }