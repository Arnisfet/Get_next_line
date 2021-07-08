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

int	counter_w(char *array)
{
	int	i;

	i = 0;
	while (array && array[i] && array[i] != '\n')
		i++;
	return (i);
}

char	*clear_arr(char *memmory)
{
	int		i;
	int		j;
	size_t	len;
	char	*new_buf;

	i = 0;
	if (!memmory)
		return (NULL);
	i = counter_w(memmory);
	if (memmory[i] == '\0')
	{
		free(memmory);
		return (NULL);
	}
	len = ft_strlen(memmory) - i;
	new_buf = malloc(sizeof(char) * (len + 1));
	if (!new_buf)
		return (NULL);
	i++, j = 0;
	while (memmory[i])
		new_buf[j++] = memmory[i++];
	new_buf[j] = '\0';
	free(memmory);
	return (new_buf);
}

char	*str_n(char *memmory)
{
	int		i;
	char	*new_line;

	i = counter_w(memmory);
	new_line = malloc(sizeof(char) * (i + 1));
	if (!new_line)
		return (NULL);
	i = 0;
	while (memmory && memmory[i] && memmory[i] != '\n')
	{
		new_line[i] = memmory[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

int	get_next_line(int fd, char **line)
{
	static char	*clean;
	char		*buf;
	int			reader;

	if (BUFFER_SIZE < 1 || !line || read(fd, NULL, 0) < 0 || fd < 0)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	reader = read(fd, buf, BUFFER_SIZE);
	while (reader)
	{
		buf[reader] = '\0';
		clean = ft_strjoin(clean, buf);
		if (searcher(clean, '\n'))
			break ;
		reader = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	*line = str_n(clean);
	clean = clear_arr(clean);
	if (reader == 0 && !clean)
		return (0);
	return (1);
}
