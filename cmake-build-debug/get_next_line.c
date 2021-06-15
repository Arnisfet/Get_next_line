//
// Created by Mickey Rudge on 5/18/21.
//
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "get_next_line.h"

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (size > 0)
		str[size--] = '\0';
	str[0] = '\0';
	return (str);
}

void	ft_strclr(char *s)
{
	if (s)
	{
		while (*s)
		{
			*s = '\0';
			s++;
		}
	}
}

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
		} else
		{
			*line = ft_strdup(reminder);
			ft_strclr(reminder);
		}
	}
	else
		*line = ft_strnew(1);
	return (p_n);
}

int get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	int byte_was_read;
	char *point;
	static char *reminder;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || (read(fd, NULL, 0) < 0))
		return (-1);
	*line = "\0";
	point = check_r(reminder, line);
	byte_was_read = 1;
	while (!point && byte_was_read)
	{
		byte_was_read  = read(fd, buf, BUFFER_SIZE);
		buf[byte_was_read] = '\0';
		point = ft_strchr(buf, '\n');
		if (point)
		{
			*point = '\0';
			reminder = ft_strdup(++point);
		}
		*line = ft_strjoin(*line, buf);
	}
	if (byte_was_read || ft_strlen(*line))
		return (1);
	return (0);
}