#include <tests.h>

// errno ...
// tests for write and read
// check ou null
// undestand makefile and commands
// write conspect in ru and eng
// check all and checkfile
// what is size_t

int main() {

  int   test1_passed = 0;
  // int   test2_passed = 0;
  // int   test3_passed = 0;
  // int   test4_passed = 0;
  // int   test5_passed = 0;
  // char  *normal_str = "Hello Paris!";
  // char  *big_str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent et consequat turpis. Pellentesque vehicula mauris sed augue rutrum, nec condimentum felis rutrum. Etiam tincidunt magna quis posuere eleifend. Proin nec dui vel diam viverra faucibus. Curabitur vitae ligula enim. Suspendisse vehicula elit vitae risus imperdiet iaculis. Sed et elementum odio, rhoncus porta risus. Proin sit amet erat quis lectus condimentum porttitor. Vivamus dapibus metus euismod sollicitudin fermentum. Vestibulum lorem nulla, semper id condimentum eget, porta ut mauris. In elit leo, pretium eu blandit ut, porttitor ut elit. Mauris vehicula vitae tortor eu malesuada. Nullam nec congue turpis. Nam tincidunt auctor pulvinar. Cras a diam vehicula, vestibulum nulla quis, condimentum massa. In in diam in lorem porta placerat at at turpis. Phasellus ullamcorper aliquam fermentum. Ut ultricies ante consequat, semper erat id, ullamcorper purus. Sed purus diam, maximus id suscipit id, molestie non libero. Pellentesque sed faucibus felis. Maecenas non aliquam leo, quis congue magna. Ut non enim orci. Quisque ipsum eros, egestas a urna ut, tincidunt pulvinar eros. Nulla scelerisque posuere eros, ut sagittis felis aliquet ut. Ut congue, tellus eget consectetur suscipit, purus diam dapibus nulla, in aliquam leo urna sed orci. Suspendisse dictum bibendum lacus at fringilla. Morbi lobortis malesuada ante, eu tempus risus lobortis vel. Aenean elementum, risus at mollis aliquet, risus eros sollicitudin sem, sit amet pulvinar felis est eu nibh. Nulla vulputate metus nunc, vel dignissim quam pulvinar eu. Phasellus sed odio finibus libero placerat efficitur. Nullam vel fermentum elit, at dictum nisl. Donec mi urna, pellentesque quis dui non, ullamcorper posuere tellus. Aliquam finibus magna vitae vehicula euismod. Sed ut purus mauris. Donec volutpat enim dolor, ac rutrum sapien volutpat vitae. Integer venenatis, tortor in aliquam bibendum, nulla purus pellentesque sem, vel ullamcorper ipsum tellus et mi. Etiam posuere enim nibh, sed pulvinar ante rhoncus a. Aliquam at ullamcorper odio.Ut sollicitudin iaculis dolor, vitae sodales justo rutrum sit amet. Proin pellentesque fringilla augue, in lacinia eros porta eu. Donec accumsan quis ante in congue. In molestie est quis molestie feugiat. Curabitur non imperdiet nunc. Integer sagittis commodo nisi a placerat. Vestibulum vitae dapibus mauris. Cras in nibh libero. Praesent sed nulla nisl.";
  // char  *empty_str = "";
  // char  *aa = "aa";

  //---------------------FT_STRLEN-------------------

  // printf("\n          [ TEST FT_STRLEN ]          \n");


  // test1_passed = test_strlen(normal_str, "normal string");
  // test2_passed = test_strlen(empty_str, "empty string");
  // test3_passed = test_strlen(big_str, "big string");

  // if (!test1_passed && !test2_passed && !test3_passed) {
  //       printf("          All strlen tests passed!\n\n");
  //   } else {
  //       printf( "          Some strlen tests failed!\n\n");
  //   }
  // test1_passed = 0;
  // test2_passed = 0;
  // test3_passed = 0;

  //---------------------FT_STRCPY-------------------

  // printf("\n          [ TEST FT_STRCPY ]          \n");

  // test1_passed = test_strcpy(normal_str, "normal string");
  // test2_passed = test_strcpy(big_str, "big string");
  // test3_passed = test_strcpy(empty_str, "empty string");

  // if (!test1_passed && !test2_passed && !test3_passed) {
  //       printf("          All strcpy tests passed!\n");
  //   } else {
  //       printf( "          Some strcpy tests failed!\n");
  //   }
  //   test1_passed = 0;
  // test2_passed = 0;
  // test3_passed = 0;

  //---------------------FT_STRCMP-------------------
  // printf("\n          [ TEST FT_STRCMP ]          \n");

  // test1_passed = test_strcmp(empty_str, normal_str, "first empty string");
  // test2_passed = test_strcmp(normal_str, empty_str, "second empty string");
  // test3_passed = test_strcmp(normal_str, normal_str, "equal string");
  // test4_passed = test_strcmp(normal_str, aa, "not equal string");
  // test5_passed = test_strcmp(aa, normal_str , "not equal string");



  // if (!test1_passed && !test2_passed && !test3_passed && !test4_passed && !test5_passed) {
  //   printf("          All strcmp tests passed!\n");
  // } else {
  //   printf( "          Some strcmp tests failed!\n");
  // }
  // test1_passed = 0;
  // test2_passed = 0;
  // test3_passed = 0;
  // test4_passed = 0;
  // test5_passed = 0;

  //---------------------FT_STRDUP-------------------
  // printf("\n          [ TEST FT_STRDUP ]          \n");

  // test1_passed = test_strdup(normal_str, "normal string");
  // test2_passed = test_strdup(empty_str, "empty string");
  // test3_passed = test_strdup(big_str, "big string string");

  // if (!test1_passed && !test2_passed && !test3_passed) {
  //     printf("          All strdup tests passed!\n\n");
  // } else {
  //     printf( "          Some strdup tests failed!\n\n");
  // }
  // test1_passed = 0;
  // test2_passed = 0;
  // test3_passed = 0;


  //---------------------FT_WRITE-------------------

  // printf("\n          [ TEST FT_WRITE ]          \n");


  // test1_passed = test_write(normal_str);
  // test2_passed = test_write(empty_str);
  // test3_passed = test_write(big_str);

  // //do we need to handle these?
  // // ft_write(1, "hh", 10);
  // // write(1, "hh", 10);

  // if (!test1_passed && !test2_passed && !test3_passed) {
  //     printf("          All write tests passed!\n\n");
  // } else {
  //     printf( "          Some write tests failed!\n\n");
  // }
  // test1_passed = 0;

  //---------------------FT_READ-------------------

  printf("\n          [ TEST FT_READ ]          \n");

  test1_passed = test_read();
  if (!test1_passed) {
      printf("          All read tests passed!\n\n");
  } else {
      printf( "          Some read tests failed!\n\n");
  }
  test1_passed = 0;



  return 0;
}
