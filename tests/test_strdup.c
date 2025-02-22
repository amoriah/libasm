#include <tests.h>

int ft_strdup_call(const char *src, const char *test_name) {
  char  *my_result = ft_strdup(src);
  char  *standart_result = strdup(src);

  printf("\nTest: %s\n", test_name);
  printf("Source string: %s\n", src);
  printf("Result from strdup: %s\n", standart_result);
  printf("Result from ft_strdup: %s\n", my_result);

  if (strlen(standart_result) != strlen(my_result)) {
    printf("%sERROR: Strings DO NOT match!%s\n", RED, NO_COLOR);
    free(my_result);
    free(standart_result);
    return 1;
  }
  printf("%sOK: Strings match!%s\n", GREEN, NO_COLOR);
  free(my_result);
  free(standart_result);

  return 0;
}

int test_strdup() {
  printf("\n%s          [ TEST FT_STRDUP ]          %s\n", BLUE, NO_COLOR);

  int test1_passed = ft_strdup_call(NORMAL_STRING, "normal string");
  int test2_passed = ft_strdup_call(EMPTY_STRING, "empty string");
  int test3_passed = ft_strdup_call(BIG_STRING, "big string string");

  if (!test1_passed && !test2_passed && !test3_passed) {
    printf("\n%s          All strdup tests PASSED!%s\n\n", GREEN, NO_COLOR);
    return 0;
  } else {
    printf("\n%s          Some strdup tests FAILED!%s\n\n", RED, NO_COLOR);
    return 1;
  }
}