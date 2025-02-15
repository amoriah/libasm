#include <stdio.h>
#include <unistd.h>
#include  <string.h>

extern int ft_strlen(const char *str);

int main() {
  int myLength = ft_strlen("Hello Paris");
  int standartLength = strlen("Hello Paris");
  printf("myLength = %i\n", myLength);
  printf("standartLength = %i\n", standartLength);
  if (myLength == standartLength) {
      printf("Lengths match!\n");
  } else {
      printf("Lengths DO NOT match!\n");
  }
  return 0;
}