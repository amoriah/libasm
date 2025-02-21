#include <tests.h>
//check return values (0, 1, -1)
int check_read_errors(int bytes_read) {
  if (bytes_read == -1) {
    perror("Error from read");
    return 1;
  }
  return 0;
}

int test_ft_read_stdin() {
  ssize_t bytes_read;
  char    buffer[100];

  printf("\nTest: read from stdin\nInput something: \n");
  bytes_read = ft_read(0, buffer, sizeof(buffer) - 1);
  if (check_read_errors(bytes_read)) return 1;
  buffer[bytes_read] = '\0'; // Добавляем нулевой символ в конец строки
  printf("Your input: %s\n", buffer);
  return 0;
}

int test_ft_read_file_descriptor() {
  int     fd_ft_write;
  int     fd_write;
  ssize_t bytes_read;
  char    buffer[100];

  printf("\nTest: read from file\n");
  fd_write = open("test_write.txt", O_RDONLY);
  fd_ft_write = open("test_ft_write.txt", O_RDONLY);

  if (check_calls(fd_write, fd_ft_write)) return 1;

  bytes_read = ft_read(fd_ft_write, buffer, sizeof(buffer) - 1);
  if (bytes_read >= 0) {
      buffer[bytes_read] = '\0'; // Добавляем нулевой символ в конец строки
      printf("Read from file by ft_read -> %s\n", buffer);
  } else {
      perror("Error ft_read from file");
      return 1;
  }
  bytes_read = read(fd_write, buffer, sizeof(buffer) - 1);
  if (bytes_read >= 0) {
      buffer[bytes_read] = '\0'; // Добавляем нулевой символ в конец строки
      printf("Read from file by read -> %s\n", buffer);
  } else {
      perror("Error read from file");
      return 1;
  }

  close(fd_write);
  close(fd_ft_write);
  return 0;
}

int test_ft_read_return_value() {
  char buffer[100];
  ssize_t bytes_read;

  printf("\nTest: read 0 bytes\n");
  bytes_read = ft_read(0, buffer, 0);
  if (bytes_read == 0) {
      printf("Success: reading 0 bytes returns 0\n");
      return 0;
  } else {
      printf("Error: reading 0 bytes returns: %zd\n", bytes_read);
      return 1;
  }
}

int test_ft_read_invalid_fd() {
  char buffer[100];
  ssize_t bytes_read;

  printf("\nTest: read from wrong fd\n");
  bytes_read = ft_read(-1, buffer, sizeof(buffer) - 1);
  if (bytes_read > 0) {
    printf("Success reading from wrong fd. It isn't good: %zd\n", bytes_read);
    return 1;
  }
  perror("Error reading file from wrong fd. It is good=>");
  return 0;
}

int test_read() {
  return (test_ft_read_stdin() \
          || test_ft_read_file_descriptor() \
          || test_ft_read_invalid_fd() \
          || test_ft_read_return_value());
}