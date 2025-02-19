#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

// errno ...
// tests for write and read
// divide on sections
// check ou null
// undestand makefile and commands
// write conspect in ru and eng 
// check all and checkfile
// move .o in obj .s src

extern int      ft_strcmp(const char *s1, const char *s2);
extern size_t   ft_strlen(const char *s);
extern ssize_t  ft_read(int fd, void *buf, size_t count);
extern char     *ft_strcpy(char *dst, char const *src);
extern char     *ft_strdup(const char *src);
extern char     *ft_write(unsigned int fd, const char *buf, size_t count);

int test_strlen(const char *test_str, const char *test_name) {
    int sis_len= strlen(test_str);
    int my_len = ft_strlen(test_str);

    printf("\nTest: %s\n", test_name);
    printf("Input string: %s\n", test_str); 
    printf("Result from strlen: %i\n", sis_len);
    printf("Result from ft_strlen: %i\n", my_len);

    if (my_len != sis_len) {
        printf("ERROR: Lengths DO NOT match!\n");
    } else {
        printf("OK: Lengths match!\n");
    }
    return 0;
}


int  test_strcpy(const char *src, const char *test_name) {
 int src_len = strlen(src) + 1;
 char *my_dst = (char *)malloc(src_len * sizeof(char));
 char *standart_dst = (char *)malloc(src_len * sizeof(char));

  if (my_dst == NULL || standart_dst == NULL) {
    printf("Allocated memory error");
    return (-1);
  }

  char *my_result = ft_strcpy(my_dst, src);
  char *standart_result = strcpy(standart_dst, src);

  
  printf("\nTest: %s\n", test_name);
  printf("Source string: %s\n", src); 

  printf("Result from strcpy: %s\n", standart_result );
  printf("Result from ft_strcpy: %s\n", my_result );

    if (strlen(standart_result) != strlen(my_result)) {
        printf("ERROR: Strings DO NOT match!\n");
    } else {
        printf("OK: Strings match!\n");
    }
    free(my_dst);
    free(standart_dst);
    return 0;
}

int test_strcmp(char const *s1, char const *s2, const char *test_name) {
  int standart_result = strcmp(s1, s2);
  int my_result = ft_strcmp(s1, s2);

  printf("\nTest: %s\n", test_name);
  printf("First string: %s\n", s1); 
  printf("Second string: %s\n", s2); 

  printf("Result from strcmp: %i\n", standart_result);
  printf("Result from ft_strcmp: %i\n", my_result);
  if (standart_result != my_result) {
        printf("ERROR: results DO NOT match!\n");
    } else {
        printf("OK: results match!\n");
    }

  return 0;
}

int test_strdup(char const *src, const char *test_name) {
  char *my_result = ft_strdup(src);
  char *standart_result = strdup(src);

  
  printf("\nTest: %s\n", test_name);
  printf("Source string: %s\n", src);

  printf("Result from strdup: %s\n", standart_result);
  printf("Result from ft_strdup: %s\n", my_result);
    if (strlen(standart_result) != strlen(my_result)) {
        printf("ERROR: Strings DO NOT match!\n");
    } else {
        printf("OK: Strings match!\n");
    }
    free(my_result);
    free(standart_result);
    return 0;
}

int test_write() {
  write(1, "hello from write", 16);
  ft_write(1, "hello from write", 16);
 
  return 0;
}

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

  return 0;
}

int main() {

  int   test1_passed = 0;
  int   test2_passed = 0;
  int   test3_passed = 0;
  int   test4_passed = 0;
  int   test5_passed = 0;
  char  *normal_str = "Hello Paris!";
  char  *big_str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent et consequat turpis. Pellentesque vehicula mauris sed augue rutrum, nec condimentum felis rutrum. Etiam tincidunt magna quis posuere eleifend. Proin nec dui vel diam viverra faucibus. Curabitur vitae ligula enim. Suspendisse vehicula elit vitae risus imperdiet iaculis. Sed et elementum odio, rhoncus porta risus. Proin sit amet erat quis lectus condimentum porttitor. Vivamus dapibus metus euismod sollicitudin fermentum. Vestibulum lorem nulla, semper id condimentum eget, porta ut mauris. In elit leo, pretium eu blandit ut, porttitor ut elit. Mauris vehicula vitae tortor eu malesuada. Nullam nec congue turpis. Nam tincidunt auctor pulvinar. Cras a diam vehicula, vestibulum nulla quis, condimentum massa. In in diam in lorem porta placerat at at turpis. Phasellus ullamcorper aliquam fermentum. Ut ultricies ante consequat, semper erat id, ullamcorper purus. Sed purus diam, maximus id suscipit id, molestie non libero. Pellentesque sed faucibus felis. Maecenas non aliquam leo, quis congue magna. Ut non enim orci. Quisque ipsum eros, egestas a urna ut, tincidunt pulvinar eros. Nulla scelerisque posuere eros, ut sagittis felis aliquet ut. Ut congue, tellus eget consectetur suscipit, purus diam dapibus nulla, in aliquam leo urna sed orci. Suspendisse dictum bibendum lacus at fringilla. Morbi lobortis malesuada ante, eu tempus risus lobortis vel. Aenean elementum, risus at mollis aliquet, risus eros sollicitudin sem, sit amet pulvinar felis est eu nibh. Nulla vulputate metus nunc, vel dignissim quam pulvinar eu. Phasellus sed odio finibus libero placerat efficitur. Nullam vel fermentum elit, at dictum nisl. Donec mi urna, pellentesque quis dui non, ullamcorper posuere tellus. Aliquam finibus magna vitae vehicula euismod. Sed ut purus mauris. Donec volutpat enim dolor, ac rutrum sapien volutpat vitae. Integer venenatis, tortor in aliquam bibendum, nulla purus pellentesque sem, vel ullamcorper ipsum tellus et mi. Etiam posuere enim nibh, sed pulvinar ante rhoncus a. Aliquam at ullamcorper odio.Ut sollicitudin iaculis dolor, vitae sodales justo rutrum sit amet. Proin pellentesque fringilla augue, in lacinia eros porta eu. Donec accumsan quis ante in congue. In molestie est quis molestie feugiat. Curabitur non imperdiet nunc. Integer sagittis commodo nisi a placerat. Vestibulum vitae dapibus mauris. Cras in nibh libero. Praesent sed nulla nisl.";
  char  *empty_str = "";
  char  *aa = "aa";
  
  //---------------------FT_STRLEN-------------------

  printf("\n          [ TEST FT_STRLEN ]          \n"); 


  test1_passed = test_strlen(normal_str, "normal string");
  test2_passed = test_strlen(empty_str, "empty string"); 
  test3_passed = test_strlen(big_str, "big string");
  
  if (!test1_passed && !test2_passed && !test3_passed) {
        printf("          All strlen tests passed!\n\n");
    } else {
        printf( "          Some strlen tests failed!\n\n");
    }
  test1_passed = 0;
  test2_passed = 0;
  test3_passed = 0;

  //---------------------FT_STRCPY-------------------

  printf("\n          [ TEST FT_STRCPY ]          \n"); 

  test1_passed = test_strcpy(normal_str, "normal string");
  test2_passed = test_strcpy(big_str, "big string");
  test3_passed = test_strcpy(empty_str, "empty string");

  if (!test1_passed && !test2_passed && !test3_passed) {
        printf("          All strcpy tests passed!\n");
    } else {
        printf( "          Some strcpy tests failed!\n");
    }
    test1_passed = 0;
  test2_passed = 0;
  test3_passed = 0;

  //---------------------FT_STRCMP-------------------
  printf("\n          [ TEST FT_STRCMP ]          \n"); 

  test1_passed = test_strcmp(empty_str, normal_str, "first empty string"); 
  test2_passed = test_strcmp(normal_str, empty_str, "second empty string"); 
  test3_passed = test_strcmp(normal_str, normal_str, "equal string");
  test4_passed = test_strcmp(normal_str, aa, "not equal string");
  test5_passed = test_strcmp(aa, normal_str , "not equal string");

  printf("Result from strcmp: %i\n",strcmp("bc", "bcc"));
  printf("Result from ft_strcmp: %i\n",ft_strcmp("bc", "bcc"));
  printf("Result from strcmp: %i\n",strcmp("ad", "a"));
  printf("Result from ft_strcmp: %i\n",ft_strcmp("ad", "a"));
  printf("Result from strcmp: %i\n",strcmp("", ""));
  printf("Result from ft_strcmp: %i\n",ft_strcmp("", ""));

  if (!test1_passed && !test2_passed && !test3_passed && !test4_passed && !test5_passed) {
    printf("          All strcmp tests passed!\n");
  } else {
    printf( "          Some strcmp tests failed!\n");
  }
  test1_passed = 0;
  test2_passed = 0;
  test3_passed = 0; 
  test4_passed = 0;
  test5_passed = 0;

  //---------------------FT_STRDUP-------------------
  printf("\n          [ TEST FT_STRDUP ]          \n"); 

  test1_passed = test_strdup(normal_str, "normal string"); 
  test2_passed = test_strdup(empty_str, "empty string"); 
  test3_passed = test_strdup(big_str, "big string string");

  if (!test1_passed && !test2_passed && !test3_passed) {
      printf("          All strdup tests passed!\n\n");
  } else {
      printf( "          Some strdup tests failed!\n\n");
  }
  test1_passed = 0;
  test2_passed = 0;
  test3_passed = 0;


  //---------------------FT_WRITE-------------------

  printf("\n          [ TEST FT_WRITE ]          \n"); 


  //---------------------FT_READ-------------------

  printf("\n          [ TEST FT_READ ]          \n"); 

  return 0;
}