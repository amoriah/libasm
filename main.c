#include <tests.h>

// undestand makefile and commands
// write conspect in ru and eng
// check all and checkfile
// what is size_t

int main() {

  int strlen_result = test_strlen();
  int strcpy_result = test_strcpy();
  int strcmp_result = test_strcmp();
  int strdup_result = test_strdup();
  int write_result = test_write();
  int read_result = test_read();

  int tests_result = strlen_result \
                      || strcpy_result \
                      || strcmp_result \
                      || strdup_result \
                      || write_result \
                      || read_result;

  if (tests_result == 1) {
    printf("\n%s         * Something wrong happened :( *         %s\n", RED, NO_COLOR);
    return tests_result;
  }

  printf("%s*** All libasm tests passed :) ***%s\n", GREEN, NO_COLOR);

  return read_result;
}
