//
// Created by Mickey Rudge on 5/18/21.
//
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "get_next_line.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*tmp;

	tmp = dst;
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (tmp);
}

char *check_r(char *reminder, char **line)
{
	char *p_n;

	p_n = NULL;
	if (reminder)
	{
		p_n = ft_strchr(reminder, '\n');
		if (p_n)
		{
			*p_n = '\0';
			*line = ft_strdup(reminder);
			++p_n;
			ft_strcpy(reminder, p_n);
		}
		else
			*line = ft_strdup(reminder);
	}
	return (p_n);
}

int get_next_line(int fd, char **line)
{
	char buf[10 + 1];
	int byte_was_read;
	char *point;
	static char *reminder;
	char *mem_point;

	point = check_r(reminder, line);
	byte_was_read = 1;
	while (!point && byte_was_read)
	{
		byte_was_read  = read(fd, buf, 10);
		buf[byte_was_read] = '\0';
		if (point = ft_strchr(buf, '\n'))
		{
			*point = '\0';
			reminder = ft_strdup(++point);
		}
		mem_point = *line;
		*line = ft_strjoin(*line, buf);

	}
	if (byte_was_read || ft_strlen(reminder) || ft_strlen(line))
		return (1);
	return (0);
}