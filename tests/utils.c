#include <tests.h>

int check_calls(int fd_write, int fd_ft_write) {
  if (fd_write == -1 || fd_ft_write == -1) {
    perror("Error opening file");
    close(fd_write);
    close(fd_ft_write);
    return 1;
  }
  return 0;
}