#include <tests.h>

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