#include "get_next_line.h"
#include "libft.h"

void	move_text_cursor(char *text, int offset)
{
	size_t	length;
	char	*text_left;

	text_left = text + offset;
	length = ft_strlen(text_left) + 1;
	ft_strlcpy(text, text_left, length);
}

int	fill_line(char **line, char *text)
{
	size_t	i;
	size_t	line_length;

	if (text && !ft_strchr(text, '\n'))
	{
		*line = ft_strdup(text);
		return (0);
	}
	line_length = 0;
	while (text[line_length] && text[line_length] != '\n')
		line_length++;
	*line = (char *)malloc(sizeof(char) * (line_length + 1));
	if (!*line)
		return (0);
	i = 0;
	while (text[i] && i < line_length)
	{
		(*line)[i] = text[i];
		i++;
	}
	(*line)[i++] = '\0';
	move_text_cursor(text, i);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	char		*buff;
	static char	*text;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff || !line || fd < 0 || read(fd, buff, 0) < 0 || BUFFER_SIZE <= 0)
	{
		clean_free(&buff);
		return (-1);
	}
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		buff[ret] = '\0';
		text = ft_strjoin_and_free(text, buff);
		if (ft_strchr(text, '\n'))
			break ;
	}
	clean_free(&buff);
	if (text && fill_line(line, text))
		return (1);
	clean_free(&text);
	return (0);
}
