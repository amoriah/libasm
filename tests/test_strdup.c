#include <tests.h>

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