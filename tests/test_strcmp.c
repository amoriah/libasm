#include <tests.h>

int ft_strcmp_call(const char *s1, const char *s2, const char *test_name) {
  int standart_result = strcmp(s1, s2);
  int my_result = ft_strcmp(s1, s2);

  printf("\n* Test: %s\n", test_name);
  printf("* First string: %s\n", s1);
  printf("* Second string: %s\n", s2);
  printf("* Result from strcmp: %i\n", standart_result);
  printf("* Result from ft_strcmp: %i\n", my_result);

  int isPositive = standart_result > 0 && my_result > 0;
  int isNegative = standart_result < 0 && my_result < 0;
  int isZero = standart_result == 0 && my_result == 0;


  if (isPositive || isNegative || isZero) {
    printf("%sOK: results have the same sign !%s\n", GREEN, NO_COLOR);
    return 0;
  }
  printf("%sERROR: results have the different sign!%s\n", RED, NO_COLOR);
  return 1;
}

int test_strcmp() {
  printf("\n%s          [ III. TEST FT_STRCMP ]          %s\n", BLUE, NO_COLOR);

  int test1_passed = ft_strcmp_call(EMPTY_STRING, NORMAL_STRING, "first empty string");
  int test2_passed = ft_strcmp_call(NORMAL_STRING, EMPTY_STRING, "second empty string");
  int test3_passed = ft_strcmp_call(NORMAL_STRING, NORMAL_STRING, "equal string");
  int test4_passed = ft_strcmp_call(NORMAL_STRING, AAA_STRING, "not equal string");
  int test5_passed = ft_strcmp_call(AAA_STRING, NORMAL_STRING , "not equal string 2");

  if (!test1_passed && !test2_passed && !test3_passed && !test4_passed && !test5_passed) {
    printf("\n%s           All strcmp tests PASSED!%s\n", GREEN, NO_COLOR);
    return 0;
  } else {
    printf("\n%s           Some strcmp tests FAILED!%s\n", RED, NO_COLOR);
    return 1;
  }
}