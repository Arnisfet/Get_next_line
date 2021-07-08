#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(char *dest);
char	*ft_strjoin(char *s1, char *s2);
char	*searcher (const char *str, int ch);

#endif //GET_NEXT_LINE_GET_NEXT_LINE_H
