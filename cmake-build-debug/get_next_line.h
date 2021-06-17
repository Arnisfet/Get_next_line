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
char	*ft_strdup(char *str);
void	*ft_memcpy (void *dst, const void *src, size_t n);
size_t ft_strlen(char *dest);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
#define BUFFER_SIZE 100
#endif //GET_NEXT_LINE_GET_NEXT_LINE_H
