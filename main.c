#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

extern int  ft_strlen(char const *str);
extern char *ft_strcpy(char *dst, char const *src);
extern int  ft_strcmp(const char *s1, const char *s2);

int test_strlen(const char *test_str, const char *test_name) {
    int sis_len= strlen(test_str);
    int my_len = ft_strlen(test_str);

    printf("\nTest: %s\n", test_name);
    printf("Input string: %s\n", test_str); 
    printf("Result from strlen: %i\n", sis_len);
    printf("Result from ft_strlen: %i\n", my_len);

    if (my_len != sis_len) {
        printf("ERROR: Lengths DO NOT match!\n");
        return 1; 
    } else {
        printf("OK: Lengths match!\n");
        return 0; 
    }
    return 0;
}


int  test_strcpy(const char *src, const char *test_name) {
  char *dst = malloc(strlen(src) + 1);

  if (dst == NULL) {
    printf("Allocated memory error");
    return 1;
  }

  char *my_result = ft_strcpy(dst, src);
  char *standart_result = strcpy(dst, src);

  
  printf("\nTest: %s\n", test_name);
  printf("Source string: %s\n", src); 

  printf("Result from strcpy: %s\n", my_result);
  printf("Result from ft_strcpy: %s\n", standart_result);
  free(dst);
    if (strlen(standart_result) != strlen(my_result)) {
        printf("ERROR: Strings DO NOT match!\n");
        return 1; 
    } else {
        printf("OK: Strings match!\n");
        return 0; 
    }
    return 0;
}

int test_strcmp(char const *s1, char const *s2) {
  printf("strcmp index exit =  %i\n", ft_strcmp(s1, s2));
  return 0;
}

int main() {

  // char  *normal_str = "Hello Paris!";
  // char  *big_str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent et consequat turpis. Pellentesque vehicula mauris sed augue rutrum, nec condimentum felis rutrum. Etiam tincidunt magna quis posuere eleifend. Proin nec dui vel diam viverra faucibus. Curabitur vitae ligula enim. Suspendisse vehicula elit vitae risus imperdiet iaculis. Sed et elementum odio, rhoncus porta risus. Proin sit amet erat quis lectus condimentum porttitor. Vivamus dapibus metus euismod sollicitudin fermentum. Vestibulum lorem nulla, semper id condimentum eget, porta ut mauris. In elit leo, pretium eu blandit ut, porttitor ut elit. Mauris vehicula vitae tortor eu malesuada. Nullam nec congue turpis. Nam tincidunt auctor pulvinar. Cras a diam vehicula, vestibulum nulla quis, condimentum massa. In in diam in lorem porta placerat at at turpis. Phasellus ullamcorper aliquam fermentum. Ut ultricies ante consequat, semper erat id, ullamcorper purus. Sed purus diam, maximus id suscipit id, molestie non libero. Pellentesque sed faucibus felis. Maecenas non aliquam leo, quis congue magna. Ut non enim orci. Quisque ipsum eros, egestas a urna ut, tincidunt pulvinar eros. Nulla scelerisque posuere eros, ut sagittis felis aliquet ut. Ut congue, tellus eget consectetur suscipit, purus diam dapibus nulla, in aliquam leo urna sed orci. Suspendisse dictum bibendum lacus at fringilla. Morbi lobortis malesuada ante, eu tempus risus lobortis vel. Aenean elementum, risus at mollis aliquet, risus eros sollicitudin sem, sit amet pulvinar felis est eu nibh. Nulla vulputate metus nunc, vel dignissim quam pulvinar eu. Phasellus sed odio finibus libero placerat efficitur. Nullam vel fermentum elit, at dictum nisl. Donec mi urna, pellentesque quis dui non, ullamcorper posuere tellus. Aliquam finibus magna vitae vehicula euismod. Sed ut purus mauris. Donec volutpat enim dolor, ac rutrum sapien volutpat vitae. Integer venenatis, tortor in aliquam bibendum, nulla purus pellentesque sem, vel ullamcorper ipsum tellus et mi. Etiam posuere enim nibh, sed pulvinar ante rhoncus a. Aliquam at ullamcorper odio.Ut sollicitudin iaculis dolor, vitae sodales justo rutrum sit amet. Proin pellentesque fringilla augue, in lacinia eros porta eu. Donec accumsan quis ante in congue. In molestie est quis molestie feugiat. Curabitur non imperdiet nunc. Integer sagittis commodo nisi a placerat. Vestibulum vitae dapibus mauris. Cras in nibh libero. Praesent sed nulla nisl.";
  
  // //---------------------FT_STRLEN-------------------

  // printf("\n          [ TEST FT_STRLEN ]          \n"); 

  // int  test_passed = 0;

  // test_passed = test_strlen(normal_str, "normal string");
  // test_passed = test_strlen("", "empty string"); 
  // test_passed = test_strlen(big_str, "big string");
  
  // if (!test_passed) {
  //       printf("          All strlen tests passed!\n");
  //   } else {
  //       printf( "          Some strlen tests failed!\n");
  //   }
  // test_passed = 0;

  // //---------------------FT_STRCPY-------------------

  // printf("\n          [ TEST FT_STRCPY ]          \n"); 

  // test_passed = test_strcpy(normal_str, "normal string");
  // test_passed = test_strcpy(big_str, "big string");
  // test_passed = test_strcpy("", "empty string");

  // if (!test_passed) {
  //       printf("          All strcpy tests passed!\n");
  //   } else {
  //       printf( "          Some strcpy tests failed!\n");
  //   }

  //---------------------FT_STRCMP-------------------

test_strcmp("abc", "abc");
  
  return 0;
}