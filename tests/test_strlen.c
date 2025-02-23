#include <tests.h>

int ft_strlen_call(const char *test_str, const char *test_name) {
  int sis_len = strlen(test_str);
  int my_len = ft_strlen(test_str);

  printf("\n* Test: %s\n", test_name);
  printf("* Input string: %s\n", test_str);
  printf("* Result from strlen: %i\n", sis_len);
  printf("* Result from ft_strlen: %i\n", my_len);

  if (my_len != sis_len) {
    printf("%sERROR: Lengths DO NOT match!%s\n", RED, NO_COLOR);
    return 1;
  }
  printf("%sOK: Lengths match!%s\n", GREEN, NO_COLOR);
  return 0;
}

int test_strlen() {
  printf("\n%s          [ I. TEST FT_STRLEN ]          %s\n", BLUE, NO_COLOR);

  int test1_passed = ft_strlen_call(NORMAL_STRING, "normal string");
  int test2_passed = ft_strlen_call(EMPTY_STRING, "empty string");
  int test3_passed = ft_strlen_call(BIG_STRING, "big string");

  if (!test1_passed && !test2_passed && !test3_passed) {
      printf("\n%s          All strlen tests PASSED!%s\n\n", GREEN, NO_COLOR);
      return 0;
  } else {
      printf("\n%s          Some strlen tests FAILED!%s\n\n", RED, NO_COLOR);
      return 1;
  }
}
