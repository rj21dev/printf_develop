#include "libft.h"

static char	*read_from_fd(int fd, char **remainder, char **line);

static char	*eof_errno_case(int bytes_read, char **remainder, char **line);

char	*get_next_line(int fd)
{
	static char	*remainder[OPEN_MAX + 1];
	char		*line;
	char		*eol_ptr;
	char		*tmp;

	line = NULL;
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (remainder[fd])
	{
		eol_ptr = ft_strchr(remainder[fd], '\n');
		if (eol_ptr)
		{
			line = ft_substr(remainder[fd], 0, eol_ptr - remainder[fd] + 1);
			tmp = ft_substr(remainder[fd], eol_ptr - remainder[fd] + 1, BUFFER_SIZE);
			free(remainder[fd]);
			remainder[fd] = tmp;
			return (line);
		}
		line = remainder[fd];
		remainder[fd] = NULL;
	}
	else
		line = ft_realloc(line, 1);
	return (read_from_fd(fd, &remainder[fd], &line));
}

static char	*read_from_fd(int fd, char **remainder, char **line)
{
	char	buf[BUFFER_SIZE + 1];
	char	*eol_ptr;
	int		len;
	int		bytes_read;

	len = ft_strlen(*line) + 1;
	while (1)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		buf[bytes_read] = '\0';
		if (bytes_read <= 0)
			return (eof_errno_case(bytes_read, remainder, line));
		eol_ptr = ft_strchr(buf, '\n');
		if (eol_ptr)
			break ;
		len += bytes_read;
		*line = ft_realloc(*line, len);
		ft_strlcat(*line, buf, len);
	}
	len += eol_ptr - buf + 1;
	*line = ft_realloc(*line, len);
	ft_strlcat(*line, buf, len);
	*remainder = ft_substr(buf, eol_ptr - buf + 1, BUFFER_SIZE);
	return (*line);
}

static char	*eof_errno_case(int bytes_read, char **remainder, char **line)
{
	int	len;

	len = ft_strlen(*line);
	if ((*line && bytes_read < 0) || (*line && !len && !bytes_read))
	{
		free(*line);
		*line = NULL;
	}
	if (*remainder && bytes_read < 0)
	{
		free(*remainder);
		*remainder = NULL;
	}
	return (*line);
}
