#include <tests.h>

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