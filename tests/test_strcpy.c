#include <tests.h>

int ft_strcpy_call(const char *src, const char *test_name) {
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
    printf("%sERROR: Strings DO NOT match!%s\n", RED, NO_COLOR);
    free(my_dst);
    free(standart_dst);
    return 1;
  }
  printf("%sOK: Strings match!%s\n", GREEN, NO_COLOR);
  free(my_dst);
  free(standart_dst);

  return 0;
}

int  test_strcpy() {
  printf("\n%s          [ TEST FT_STRCPY ]          %s\n", BLUE, NO_COLOR);

  int test1_passed = ft_strcpy_call(NORMAL_STRING, "normal string");
  int test2_passed = ft_strcpy_call(EMPTY_STRING, "big string");
  int test3_passed = ft_strcpy_call(BIG_STRING, "empty string");

  if (!test1_passed && !test2_passed && !test3_passed) {
    printf("\n%s           All strcpy tests PASSED!%s\n", GREEN, NO_COLOR);
    return 0;
  } else {
    printf( "\n%s           Some strcpy tests FAILED!%s\n", RED, NO_COLOR);
    return 1;
  }
}