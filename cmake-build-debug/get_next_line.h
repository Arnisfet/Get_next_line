//
// Created by Mickey Rudge on 5/18/21.
//
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef GET_NEXT_LINE_GET_NEXT_LINE_H
#define GET_NEXT_LINE_GET_NEXT_LINE_H
int get_next_line(int fd, char **line);
char	*ft_strdup(const char *str);
void	*ft_memcpy (void *dst, const void *src, size_t n);
size_t ft_strlen(const char *dest);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr (const char *str, int ch);
#endif //GET_NEXT_LINE_GET_NEXT_LINE_H
