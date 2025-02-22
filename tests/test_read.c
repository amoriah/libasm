#include <tests.h>

int check_read_errors(int bytes_read) {
  if (bytes_read == -1) {
    perror("Error from read");
    return 1;
  }
  return 0;
}

int read_from_stdin(const char *test_name) {
  ssize_t bytes_read;
  char    buffer[BUFFER_SIZE];

  printf("\nTest: %s\nInput something: \n", test_name);

  bytes_read = ft_read(STDIN_CODE, buffer, sizeof(buffer) - 1);
  if (check_read_errors(bytes_read)) return 1;
  buffer[bytes_read] = '\0';

  printf("Your input: %s\n", buffer);
  return 0;
}

int read_from_fd(const char *test_name) {
  int     fd_ft_write;
  int     fd_write;
  char    buffer[BUFFER_SIZE];
  ssize_t bytes_ft_read;
  ssize_t bytes_read;                                                                            ;

  printf("\nTest: %s\n", test_name);
  fd_write = open("test_write.txt", O_RDONLY);
  fd_ft_write = open("test_ft_write.txt", O_RDONLY);

  if (check_calls(fd_write, fd_ft_write)) return 1;

  bytes_ft_read = ft_read(fd_ft_write, buffer, sizeof(buffer) - 1);
  if (bytes_ft_read >= 0) {
    buffer[bytes_ft_read] = '\0';
    printf("Read from file by ft_read -> %s\n", buffer);
  } else {
    perror("Error ft_read from file");
    return 1;
  }

  bytes_read = read(fd_write, buffer, sizeof(buffer) - 1);
  if (bytes_read >= 0) {
    buffer[bytes_read] = '\0';
    printf("Read from file by read -> %s\n", buffer);
  } else {
    perror("Error read from file");
    return 1;
  }

  close(fd_write);
  close(fd_ft_write);

  if (bytes_read != bytes_ft_read) {
    printf("%sERROR: Lengths DO NOT match!%s\n", RED, NO_COLOR);
    return 1;
  }

  printf("%sOK: Lengths match!%s\n", GREEN, NO_COLOR);
  return 0;
}

int read_from_wrong_fd(const char *test_name) {
  char buffer[BUFFER_SIZE];
  ssize_t bytes_read;

  printf("\nTest: %s\n", test_name);
  bytes_read = ft_read(WRONG_FD, buffer, sizeof(buffer) - 1);
  if (bytes_read > 0) {
    printf("%sError: success reading from wrong fd %zd%s\n", RED, bytes_read, NO_COLOR);
    return 1;
  }
  printf("%sOK: error reading file from wrong fd, result: %ld %s\n", GREEN, bytes_read, NO_COLOR);
  return 0;
}

int test_read() {

  printf("\n%s          [ TEST FT_READ ]          %s\n", BLUE, NO_COLOR);

  int   test1_passed = read_from_stdin("read from stdin");
  int   test2_passed = read_from_fd("read from fd");
  int   test3_passed = read_from_wrong_fd("send wrong fd");

  if (!test1_passed && !test2_passed && !test3_passed) {
    printf("\n%s          All read tests PASSED!%s\n\n", GREEN, NO_COLOR);
    return 0;
  } else {
    printf( "\n%s          Some read tests FAILED!%s\n\n", RED, NO_COLOR);
    return 1;
  }
}