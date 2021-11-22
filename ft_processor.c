#include "header.h"

int	ft_processor(const char *str, va_list argptr)
{
	int	printed;

	printed = 0;
	if (*str == 'c')
		printed += ft_putchar_fd(va_arg(argptr, int), STDOUT);
	if (*str == 'd' || *str == 'i')
	{
		char *num = ft_itoa(va_arg(argptr, int));
		printed += ft_putstr_fd(num, STDOUT);
		free(num);
	}
	if (*str == 'u')
	{
		char *num = ft_ultoa(va_arg(argptr, unsigned int), "0123456789");
		printed += ft_putstr_fd(num, STDOUT);
		free(num);
	}
	if (*str == 'x')
	{
		char *num = ft_ultoa(va_arg(argptr, unsigned int), "0123456789abcdef");
		printed += ft_putstr_fd(num, STDOUT);
		free(num);
	}
	if (*str == 'X')
	{
		char *num = ft_ultoa(va_arg(argptr, unsigned int), "0123456789ABCDEF");
		printed += ft_putstr_fd(num, STDOUT);
		free(num);
	}
	if (*str == 's')
		printed += ft_putstr_fd(va_arg(argptr, char *), STDOUT);
	if (*str == '%')
		printed += ft_putchar_fd('%', STDOUT);
	return (printed);
}
