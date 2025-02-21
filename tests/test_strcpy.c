#include <tests.h>

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