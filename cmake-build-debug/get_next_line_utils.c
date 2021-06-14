//
// Created by Mickey Rudge on 5/18/21.
//

#include <stdlib.h>

size_t	ft_strlen (const char *str)
{
	size_t	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

void	*ft_memcpy (void *dst, const void *src, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	if (!dst && !src)
		return (0);
	p1 = (unsigned char *)dst;
	p2 = (unsigned char *)src;
	while (n--)
		*p1++ = *p2++;
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	arr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!arr)
		return (NULL);
	while (s1[i] != '\0')
	{
		arr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		arr[i] = s2[j];
		i++, j++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*p;

	len = ft_strlen(str) + 1;
	p = (char *)malloc(sizeof(char) * len);
	if (!p)
		return (NULL);
	p = ft_memcpy(p, str, len);
	return (p);
}

char	*ft_strchr(const char *str, int ch)
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