#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

// errno ...
// tests for write and read
// check ou null
// undestand makefile and commands
// write conspect in ru and eng
// check all and checkfile
// what is size_t

extern int      ft_strcmp(const char *s1, const char *s2);
extern size_t   ft_strlen(const char *s);
extern ssize_t  ft_read(int fd, void *buf, size_t count);
extern char     *ft_strcpy(char *dst, const char  *src);
extern char     *ft_strdup(const char *src);
extern ssize_t  ft_write(int fd, const void *buf, size_t count);

int test_strlen(const char *test_str, const char *test_name) {
  int sis_len = strlen(test_str);
  int my_len = ft_strlen(test_str);

  printf("\nTest: %s\n", test_name);
  printf("Input string: %s\n", test_str);
  printf("Result from strlen: %i\n", sis_len);
  printf("Result from ft_strlen: %i\n", my_len);
  if (my_len != sis_len) {
      printf("ERROR: Lengths DO NOT match!\n");
      return 1;
  }
  printf("OK: Lengths match!\n");
  return 0;
}


int  test_strcpy(const char *src, const char *test_name) {
  int   src_len = strlen(src) + 1;
  char  *my_dst = (char *)malloc(src_len * sizeof(char));
  char  *standart_dst = (char *)malloc(src_len * sizeof(char));

  if (my_dst == NULL || standart_dst == NULL) {
    printf("Allocated memory error");
    return (-1);
  }

  char *my_result = ft_strcpy(my_dst, src);
  char *standart_result = strcpy(standart_dst, src);
  printf("\nTest: %s\n", test_name);
  printf("Source string: %s\n", src);
  printf("Result from strcpy: %s\n", standart_result);
  printf("Result from ft_strcpy: %s\n", my_result);
  if (strlen(standart_result) != strlen(my_result)) {
      printf("ERROR: Strings DO NOT match!\n");
      free(my_dst);
      free(standart_dst);
      return 1;
  }
  printf("OK: Strings match!\n");
  free(my_dst);
  free(standart_dst);
  return 0;
}

int test_strcmp(const char *s1, const char *s2, const char *test_name) {
  int standart_result = strcmp(s1, s2);
  int my_result = ft_strcmp(s1, s2);

  printf("\nTest: %s\n", test_name);
  printf("First string: %s\n", s1);
  printf("Second string: %s\n", s2);
  printf("Result from strcmp: %i\n", standart_result);
  printf("Result from ft_strcmp: %i\n", my_result);
  if (standart_result != my_result) {
    printf("ERROR: results DO NOT match!\n");
    return 1;
  }
  printf("OK: results match!\n");
  return 0;
}

int test_strdup(const char *src, const char *test_name) {
  char  *my_result = ft_strdup(src);
  char  *standart_result = strdup(src);

  printf("\nTest: %s\n", test_name);
  printf("Source string: %s\n", src);
  printf("Result from strdup: %s\n", standart_result);
  printf("Result from ft_strdup: %s\n", my_result);
  if (strlen(standart_result) != strlen(my_result)) {
      printf("ERROR: Strings DO NOT match!\n");
      free(my_result);
      free(standart_result);
      return 1;
  }
  printf("OK: Strings match!\n");
  free(my_result);
  free(standart_result);
  return 0;
}

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

int test_read(const char *str) {
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

int main() {

  int   test1_passed = 0;
  // int   test2_passed = 0;
  // int   test3_passed = 0;
  // int   test4_passed = 0;
  // int   test5_passed = 0;
  char  *normal_str = "Hello Paris!";
  // char  *big_str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent et consequat turpis. Pellentesque vehicula mauris sed augue rutrum, nec condimentum felis rutrum. Etiam tincidunt magna quis posuere eleifend. Proin nec dui vel diam viverra faucibus. Curabitur vitae ligula enim. Suspendisse vehicula elit vitae risus imperdiet iaculis. Sed et elementum odio, rhoncus porta risus. Proin sit amet erat quis lectus condimentum porttitor. Vivamus dapibus metus euismod sollicitudin fermentum. Vestibulum lorem nulla, semper id condimentum eget, porta ut mauris. In elit leo, pretium eu blandit ut, porttitor ut elit. Mauris vehicula vitae tortor eu malesuada. Nullam nec congue turpis. Nam tincidunt auctor pulvinar. Cras a diam vehicula, vestibulum nulla quis, condimentum massa. In in diam in lorem porta placerat at at turpis. Phasellus ullamcorper aliquam fermentum. Ut ultricies ante consequat, semper erat id, ullamcorper purus. Sed purus diam, maximus id suscipit id, molestie non libero. Pellentesque sed faucibus felis. Maecenas non aliquam leo, quis congue magna. Ut non enim orci. Quisque ipsum eros, egestas a urna ut, tincidunt pulvinar eros. Nulla scelerisque posuere eros, ut sagittis felis aliquet ut. Ut congue, tellus eget consectetur suscipit, purus diam dapibus nulla, in aliquam leo urna sed orci. Suspendisse dictum bibendum lacus at fringilla. Morbi lobortis malesuada ante, eu tempus risus lobortis vel. Aenean elementum, risus at mollis aliquet, risus eros sollicitudin sem, sit amet pulvinar felis est eu nibh. Nulla vulputate metus nunc, vel dignissim quam pulvinar eu. Phasellus sed odio finibus libero placerat efficitur. Nullam vel fermentum elit, at dictum nisl. Donec mi urna, pellentesque quis dui non, ullamcorper posuere tellus. Aliquam finibus magna vitae vehicula euismod. Sed ut purus mauris. Donec volutpat enim dolor, ac rutrum sapien volutpat vitae. Integer venenatis, tortor in aliquam bibendum, nulla purus pellentesque sem, vel ullamcorper ipsum tellus et mi. Etiam posuere enim nibh, sed pulvinar ante rhoncus a. Aliquam at ullamcorper odio.Ut sollicitudin iaculis dolor, vitae sodales justo rutrum sit amet. Proin pellentesque fringilla augue, in lacinia eros porta eu. Donec accumsan quis ante in congue. In molestie est quis molestie feugiat. Curabitur non imperdiet nunc. Integer sagittis commodo nisi a placerat. Vestibulum vitae dapibus mauris. Cras in nibh libero. Praesent sed nulla nisl.";
  // char  *empty_str = "";
  // char  *aa = "aa";

  //---------------------FT_STRLEN-------------------

  // printf("\n          [ TEST FT_STRLEN ]          \n");


  // test1_passed = test_strlen(normal_str, "normal string");
  // test2_passed = test_strlen(empty_str, "empty string");
  // test3_passed = test_strlen(big_str, "big string");

  // if (!test1_passed && !test2_passed && !test3_passed) {
  //       printf("          All strlen tests passed!\n\n");
  //   } else {
  //       printf( "          Some strlen tests failed!\n\n");
  //   }
  // test1_passed = 0;
  // test2_passed = 0;
  // test3_passed = 0;

  //---------------------FT_STRCPY-------------------

  // printf("\n          [ TEST FT_STRCPY ]          \n");

  // test1_passed = test_strcpy(normal_str, "normal string");
  // test2_passed = test_strcpy(big_str, "big string");
  // test3_passed = test_strcpy(empty_str, "empty string");

  // if (!test1_passed && !test2_passed && !test3_passed) {
  //       printf("          All strcpy tests passed!\n");
  //   } else {
  //       printf( "          Some strcpy tests failed!\n");
  //   }
  //   test1_passed = 0;
  // test2_passed = 0;
  // test3_passed = 0;

  //---------------------FT_STRCMP-------------------
  // printf("\n          [ TEST FT_STRCMP ]          \n");

  // test1_passed = test_strcmp(empty_str, normal_str, "first empty string");
  // test2_passed = test_strcmp(normal_str, empty_str, "second empty string");
  // test3_passed = test_strcmp(normal_str, normal_str, "equal string");
  // test4_passed = test_strcmp(normal_str, aa, "not equal string");
  // test5_passed = test_strcmp(aa, normal_str , "not equal string");

  // printf("Result from strcmp: %i\n",strcmp("bc", "bcc"));
  // printf("Result from ft_strcmp: %i\n",ft_strcmp("bc", "bcc"));
  // printf("Result from strcmp: %i\n",strcmp("ad", "a"));
  // printf("Result from ft_strcmp: %i\n",ft_strcmp("ad", "a"));
  // printf("Result from strcmp: %i\n",strcmp("", ""));
  // printf("Result from ft_strcmp: %i\n",ft_strcmp("", ""));

  // if (!test1_passed && !test2_passed && !test3_passed && !test4_passed && !test5_passed) {
  //   printf("          All strcmp tests passed!\n");
  // } else {
  //   printf( "          Some strcmp tests failed!\n");
  // }
  // test1_passed = 0;
  // test2_passed = 0;
  // test3_passed = 0;
  // test4_passed = 0;
  // test5_passed = 0;

  //---------------------FT_STRDUP-------------------
  // printf("\n          [ TEST FT_STRDUP ]          \n");

  // test1_passed = test_strdup(normal_str, "normal string");
  // test2_passed = test_strdup(empty_str, "empty string");
  // test3_passed = test_strdup(big_str, "big string string");

  // if (!test1_passed && !test2_passed && !test3_passed) {
  //     printf("          All strdup tests passed!\n\n");
  // } else {
  //     printf( "          Some strdup tests failed!\n\n");
  // }
  // test1_passed = 0;
  // test2_passed = 0;
  // test3_passed = 0;


  //---------------------FT_WRITE-------------------

  printf("\n          [ TEST FT_WRITE ]          \n");


  test1_passed = test_write(normal_str);
  if (!test1_passed) {
      printf("          All write tests passed!\n\n");
  } else {
      printf( "          Some write tests failed!\n\n");
  }
  test1_passed = 0;

  //---------------------FT_READ-------------------

  printf("\n          [ TEST FT_READ ]          \n");

  test1_passed = test_read(normal_str);
  if (!test1_passed) {
      printf("          All read tests passed!\n\n");
  } else {
      printf( "          Some read tests failed!\n\n");
  }
  test1_passed = 0;



  return 0;
}
