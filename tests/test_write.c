#include <tests.h>

int write_in_wrong_fd(const char *str, const char *test_name) {
  ssize_t my_result;
  ssize_t standart_result;

  printf("\nTest: %s\n", test_name);
  printf("Write to file from write: \n");

  standart_result = write(WRONG_FD, str, strlen(str));
  my_result = write(WRONG_FD, str, strlen(str));

  printf("write result: %li\n", standart_result);
  printf("ft_write result: %li\n", my_result);
  if (standart_result !=  my_result) {
    printf("%sERROR: Lengths DO NOT match!%s\n", RED, NO_COLOR);
    return 1;
  }

  printf("%sOK: Results match!%s\n", GREEN, NO_COLOR);
  return 0;
}

int write_in_file(const char *str, const char *test_name) {
  int     fd_write;
  int     fd_ft_write;
  ssize_t bytes_read;

  printf("\nTest: %s\n", test_name);

  fd_write = open("test_write.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  fd_ft_write = open("test_ft_write.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

  if (check_calls(fd_write, fd_ft_write)) return 1;

  write(fd_write, str, strlen(str));
  write(fd_ft_write, str, strlen(str));

  close(fd_write);
  close(fd_ft_write);

  char buffer_write[strlen(str) + 1];
  char buffer_ft_write[strlen(str) + 1];

  fd_write = open("test_write.txt", O_RDONLY);
  fd_ft_write = open("test_ft_write.txt", O_RDONLY);

  if (check_calls(fd_write, fd_ft_write)) return 1;

  bytes_read = read(fd_write, buffer_write, sizeof(buffer_write));
  bytes_read = read(fd_ft_write, buffer_ft_write, sizeof(buffer_ft_write));
  buffer_write[bytes_read] = '\0';
  buffer_ft_write[bytes_read] = '\0';

  close(fd_write);
  close(fd_ft_write);

  printf("In file 'test_write' length: %li\n", strlen(buffer_write));
  printf("In file 'test_ft_write' length: %li\n", strlen(buffer_ft_write));

  if (strlen(buffer_write)!= strlen(buffer_ft_write)) {
    printf("%sERROR: Lengths DO NOT match!%s\n", RED, NO_COLOR);
    return 1;
  }

  printf("%sOK: Lengths match!%s\n", GREEN, NO_COLOR);
  return 0;
}

int write_to_stdout(const char *str, const char *test_name) {
  int     str_len;
  ssize_t my_result;
  ssize_t standart_result;

  str_len = strlen(str);

  printf("\nTest: %s\n", test_name);
  printf("Output from write: \n");

  if ((standart_result = write(STDOUT_CODE, str, str_len)) == -1) {
    printf("%sError: can't write in stdout from write%s", RED, NO_COLOR);
    return 1;
  }
  printf("\nOutput from ft_write: \n");

  if ((my_result = write(STDOUT_CODE, str, str_len)) == -1) {
    printf("%sError: can't write in stdout from ft_write%s", RED, NO_COLOR);
    return 1;
  }

  printf("\nWrite length: %li  ", standart_result);
  printf("ft_write length: %li\n", my_result);

  if (my_result != standart_result) {
    printf("%sERROR: Lengths DO NOT match!%s\n", RED, NO_COLOR);
    return 1;
  }

  printf("%sOK: Lengths match!%s\n", GREEN, NO_COLOR);
  return 0;
}

int test_write() {
  printf("\n%s          [ TEST FT_WRITE ]          %s\n", BLUE, NO_COLOR);

  int   test1_passed = write_to_stdout(NORMAL_STRING, "write to stdout");
  int   test2_passed = write_in_file(NORMAL_STRING, "write in file");
  int   test3_passed = write_in_wrong_fd(NORMAL_STRING, "send wrong fd");

  if (!test1_passed && !test2_passed && !test3_passed) {
    printf("\n%s          All write tests PASSED!%s\n\n", GREEN, NO_COLOR);
    return 0;
  } else {
    printf( "\n%s          Some write tests FAILED!%s\n\n", RED, NO_COLOR);
    return 1;
  }
}
