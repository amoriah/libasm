#include <tests.h>
//check return values (0, 1, -1)
int check_read_errors(int bytes_read) {
  if (bytes_read == -1) {
    perror("Error read from stdin");
    return 1;
  }
  return 0;
}

int test_read() {
  int test1;
  int test2;
  ssize_t bytes_read;
  char buffer[100];

  int test_ft_read_stdin() {
      // char buffer[100];
      // ssize_t bytes_read;

      printf("\nTest: read from stdin\nInput something: \n");
      bytes_read = ft_read(0, buffer, sizeof(buffer) - 1);
      if (check_read_errors(bytes_read)) return 1;
      buffer[bytes_read] = '\0'; // Добавляем нулевой символ в конец строки
      printf("Your input: %s\n", buffer);
      return 0;

  }

  int test_ft_read_file_descriptor() {
      int fd_ft_write;
      int fd_write;
      // char buffer[100];

      fd_write = open("../test_write.txt", O_RDONLY);
      fd_ft_write = open("../test_ft_write.txt", O_RDONLY);
      if (check_calls(fd_write, fd_ft_write)) return 1;


      bytes_read = ft_read(fd, buffer, sizeof(buffer) - 1);
      if (bytes_read >= 0) {
          buffer[bytes_read] = '\0'; // Добавляем нулевой символ в конец строки
          printf("Чтение из файла: %s\n", buffer);
      } else {
          perror("Ошибка чтения из файла");
      }

      close(fd);
  }

  // void test_ft_read_invalid_fd() {
  //     char buffer[100];
  //     ssize_t bytes_read = ft_read(-1, buffer, sizeof(buffer) - 1); // Неправильный файловый дескриптор
  //     if (bytes_read < 0) {
  //         perror("Ошибка чтения с неправильного файлового дескриптора (ожидается ошибка)");
  //     } else {
  //         printf("Чтение с неправильного файлового дескриптора не вызвало ошибку! Возвращаемое значение: %zd\n", bytes_read);
  //     }
  // }

  // void test_ft_read_return_value() {
  //     char buffer[100];

  //     // Пробуем прочитать 0 байт
  //     ssize_t bytes_read = ft_read(0, buffer, 0); // Чтение 0 байт должно вернуть 0
  //     if (bytes_read == 0) {
  //         printf("Тест: чтение 0 байт успешно вернуло: %zd\n", bytes_read);
  //     } else {
  //         printf("Ошибка: чтение 0 байт вернуло: %zd\n", bytes_read);
  //     }
  // }
  test1 = test_ft_read_stdin();
  test2 = test_ft_read_file_descriptor();
  // test_ft_read_invalid_fd();
  // test_ft_read_return_value();

    // return test1 || test2;
    return test1 ;
}