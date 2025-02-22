#ifndef TESTS_H
# define TESTS_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

# define GREEN      "\033[32;1m"
# define RED        "\033[31;1m"
# define BLUE       "\033[34;1m"
# define NO_COLOR   "\033[0m"

# define NORMAL_STRING  "Hello Paris!"
# define BIG_STRING     "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent et consequat turpis. Pellentesque vehicula mauris sed augue rutrum, nec condimentum felis rutrum. Etiam tincidunt magna quis posuere eleifend. Proin nec dui vel diam viverra faucibus. Curabitur vitae ligula enim. Suspendisse vehicula elit vitae risus imperdiet iaculis. Sed et elementum odio, rhoncus porta risus. Proin sit amet erat quis lectus condimentum porttitor. Vivamus dapibus metus euismod sollicitudin fermentum. Vestibulum lorem nulla, semper id condimentum eget, porta ut mauris. In elit leo, pretium eu blandit ut, porttitor ut elit. Mauris vehicula vitae tortor eu malesuada. Nullam nec congue turpis. Nam tincidunt auctor pulvinar. Cras a diam vehicula, vestibulum nulla quis, condimentum massa. In in diam in lorem porta placerat at at turpis. Phasellus ullamcorper aliquam fermentum. Ut ultricies ante consequat, semper erat id, ullamcorper purus. Sed purus diam, maximus id suscipit id, molestie non libero. Pellentesque sed faucibus felis. Maecenas non aliquam leo, quis congue magna. Ut non enim orci. Quisque ipsum eros, egestas a urna ut, tincidunt pulvinar eros. Nulla scelerisque posuere eros, ut sagittis felis aliquet ut. Ut congue, tellus eget consectetur suscipit, purus diam dapibus nulla, in aliquam leo urna sed orci. Suspendisse dictum bibendum lacus at fringilla. Morbi lobortis malesuada ante, eu tempus risus lobortis vel. Aenean elementum, risus at mollis aliquet, risus eros sollicitudin sem, sit amet pulvinar felis est eu nibh. Nulla vulputate metus nunc, vel dignissim quam pulvinar eu. Phasellus sed odio finibus libero placerat efficitur. Nullam vel fermentum elit, at dictum nisl. Donec mi urna, pellentesque quis dui non, ullamcorper posuere tellus. Aliquam finibus magna vitae vehicula euismod. Sed ut purus mauris. Donec volutpat enim dolor, ac rutrum sapien volutpat vitae. Integer venenatis, tortor in aliquam bibendum, nulla purus pellentesque sem, vel ullamcorper ipsum tellus et mi. Etiam posuere enim nibh, sed pulvinar ante rhoncus a. Aliquam at ullamcorper odio.Ut sollicitudin iaculis dolor, vitae sodales justo rutrum sit amet. Proin pellentesque fringilla augue, in lacinia eros porta eu. Donec accumsan quis ante in congue. In molestie est quis molestie feugiat. Curabitur non imperdiet nunc. Integer sagittis commodo nisi a placerat. Vestibulum vitae dapibus mauris. Cras in nibh libero. Praesent sed nulla nisl."
# define AAA_STRING     "aAa"
# define EMPTY_STRING   ""

# define STDIN_CODE     0
# define STDOUT_CODE    1
# define WRONG_FD       -1
# define BUFFER_SIZE    100

extern int      ft_strcmp(const char *s1, const char *s2);
extern size_t   ft_strlen(const char *s);
extern ssize_t  ft_write(int fd, const void *buf, size_t count);
extern ssize_t  ft_read(int fd, void *buf, size_t count);
extern char     *ft_strcpy(char *dst, const char  *src);
extern char     *ft_strdup(const char *src);

int test_strlen();
int test_strcpy();
int test_strcmp();
int test_strdup();
int test_write();
int test_read();
int check_calls(int fd_write, int fd_ft_write);

#endif