#include <tests.h>

int write_in_file(const char *str, int str_len) {
  int     fd_write;
  int     fd_ft_write;
  ssize_t bytes_read;
  ssize_t my_result;
  ssize_t standart_result;

  printf("\nTest: write to file\n");
  //--------write to file--------
  fd_write = open("test_write.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  fd_ft_write = open("test_ft_write.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

  if (check_calls(fd_write, fd_ft_write)) return 1;

  standart_result = write(fd_write, str, str_len);
  my_result = write(fd_ft_write, str, str_len);

  close(fd_write);
  close(fd_ft_write);

  //--------read result from file--------
  char buffer_write[str_len + 1];
  char buffer_ft_write[str_len + 1];

  fd_write = open("test_write.txt", O_RDONLY);
  fd_ft_write = open("test_ft_write.txt", O_RDONLY);

  if (check_calls(fd_write, fd_ft_write)) return 1;

  bytes_read = read(fd_write, buffer_write, sizeof(buffer_write));
  bytes_read = read(fd_ft_write, buffer_ft_write, sizeof(buffer_ft_write));
  buffer_write[bytes_read] = '\0';
  buffer_ft_write[bytes_read] = '\0';

  close(fd_write);
  close(fd_ft_write);

  printf("In test_write str length: %li\n", strlen(buffer_write));
  printf("In test_ft_write length: %li\n", strlen(buffer_ft_write));
  if (strlen(buffer_write)!= strlen(buffer_ft_write)) {
    printf("ERROR: Lengths DO NOT match!\n");
    return 1;
  }

  printf("\nTest: wrong fd\n");
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
  return 0;
}

int test_write(const char *str) {
  int     str_len;
  int     write_to_file_res;
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
  write_to_file_res = write_in_file(str, str_len);
  return write_to_file_res;
}