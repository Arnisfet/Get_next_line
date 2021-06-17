//
// Created by Mickey Rudge on 6/16/21.
//Алгоритм:
// 0) Создание массива для будущей чистки памяти
// 1) Чтение строки в буфер на количество опроеделенных символов.
// 2) Обнуление конца буфера и конкатенация существующего буфера в массви.
// 3) Проверка на /n в буфере, при его наличии производится экстренный выход
// из цикла массив и его перезапись в лайн.
// 4) Очистка созданного массива  в начале программы.



//Алгоритм очистки массива
//1) Вводится счетчик и просчитывается длина массива (while (* != '\0' ||
// '\n'), если попался нуль терминатор, то это конец строки и проводится
// очистка.
//2) Если это не нул терминатор, то подсчитывается общая длина строки и из
// нее вычитается кол-во символов до слэщ эн.
//3) Под получившееся число выделяется память и происходит перезапись в
// другой массив с места, где был найден слэш эн.
//4) Очистка входящего массива и возврат нового.
#include "get_next_line.h"

char	*clear_arr(char *saved_buf)
{
	int		i;
	int		j;
	size_t	length;
	char	*new_buf;

	i = 0;
	if (!saved_buf)
		return (NULL);
	while (saved_buf[i] && saved_buf[i] != '\n')
		i++;
	if (saved_buf[i] == '\0')
	{
		free(saved_buf);
		return (NULL);
	}
	length = ft_strlen(saved_buf) - i;
	new_buf = malloc(sizeof(char) * (length + 1));
	if (!new_buf)
		return (NULL);
	i++, j = 0;
	while (saved_buf[i])
		new_buf[j++] = saved_buf[i++];
	new_buf[j] = '\0';
	free(saved_buf);
	return (new_buf);
}

char	*str_n(char *saved_buf)
{
	int		i;
	char	*new_line;

	i = 0;
	while (saved_buf && saved_buf[i] && saved_buf[i] != '\n')
		i++;
	new_line = malloc(sizeof(char) * (i + 1));
	if (!new_line)
		return (NULL);
	i = 0;
	while (saved_buf && saved_buf[i] && saved_buf[i] != '\n')
	{
		new_line[i] = saved_buf[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (unsigned char)c)
		i++;
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (NULL);
}

int get_next_line(int fd, char **line)
{
	static char *clean;
	char *buf;
	int reader;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (-1);
	buf = NULL;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	reader = read(fd, buf, BUFFER_SIZE);
	while(reader > 0)
	{

		buf[reader] = '\0';
		clean = ft_strjoin(clean, buf);
		if (ft_strchr(clean, '\n'))
			break ;
		reader = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	*line = str_n(clean);
	clean = clear_arr(clean);
	if (reader == 0 && !clean && ft_strlen(*line) == 0)
		return (0);
	return (1);
}