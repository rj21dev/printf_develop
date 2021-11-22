#include "header.h"

int ft_putstr_fd(char *s, int fd)
{
	int printed;

    printed = 0;
    if (!s)
		return (printed);
	while (*s)
		printed += write(fd, s++, sizeof(char));
    return (printed);
}
