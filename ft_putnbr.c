#include "header.h"

int ft_putnbr_fd(int n, int fd)
{
	char	c;
    int     printed;

    printed = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		printed += write(fd, "-", sizeof(char));
		n *= -1;
	}
	if (n < 10)
	{
		c = n + '0';
		return (printed += write(fd, &c, sizeof(char)));
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
    return (printed);
}
