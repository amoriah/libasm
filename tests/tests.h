#ifndef TESTS_H
# define TESTS_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

extern int      ft_strcmp(const char *s1, const char *s2);
extern size_t   ft_strlen(const char *s);
extern char     *ft_strcpy(char *dst, const char  *src);
extern char     *ft_strdup(const char *src);
extern ssize_t  ft_write(int fd, const void *buf, size_t count);
extern ssize_t  ft_read(int fd, void *buf, size_t count);

int test_strlen(const char *test_str, const char *test_name);
int test_strcpy(const char *src, const char *test_name);
int test_strcmp(const char *s1, const char *s2, const char *test_name);
int test_strdup(const char *src, const char *test_name);
int test_write(const char *str);
// int test_read(const char *str);
int test_read();
int check_calls(int fd_write, int fd_ft_write);

#endif