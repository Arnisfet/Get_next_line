//
// Created by Mickey Rudge on 6/16/21.
//

#include "get_next_line.h"

size_t	ft_strlen (char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*arr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	arr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!arr)
		return (NULL);
	if (s1)
	{
		while (s1[i] != '\0')
		{
			arr[i] = s1[i];
			i++;
		}
	}
	if (s2)
		while (s2[j] != '\0')
			arr[i++] = s2[j++];
	arr[i] = '\0';
	free(s1);
	return (arr);
}

char	*searcher(const char *str, int ch)
{
	char	*p;
	char	i;

	i = (char)ch;
	p = (char *)str;
	while (*p && *p != ch)
		p++;
	if (*p == ch)
		return (p);
	return (NULL);
}
