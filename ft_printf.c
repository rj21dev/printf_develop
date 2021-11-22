#include "header.h"

int	ft_printf(const char *str, ...)
{
	va_list	argptr;
	int		i;
	int		printed;

	va_start(argptr, str);
	printed = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			printed += ft_putchar_fd(str[i], STDOUT);
		else
		{
			printed += ft_processor(&str[i + 1], argptr);
			i += 1;
		}
		++i;
	}
	va_end(argptr);
	return (printed);
}
