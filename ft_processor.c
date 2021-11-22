#include "header.h"

int	ft_processor(const char *str, va_list argptr)
{
	int	printed;

	printed = 0;
	if (*str == 'c')
		printed += ft_putchar_fd(va_arg(argptr, int), STDOUT);
	if (*str == 'd')
		printed += ft_putstr_fd(ft_itoa_base(va_arg(argptr, int), "0123456789"), STDOUT);
	if (*str == 'i')
		printed += ft_putstr_fd(ft_itoa_base(va_arg(argptr, int), "0123456789"), STDOUT);
	if (*str == 's')
		printed += ft_putstr_fd(va_arg(argptr, char *), STDOUT);
	if (*str == '%')
		printed += ft_putchar_fd('%', STDOUT);
	return (printed);
}
