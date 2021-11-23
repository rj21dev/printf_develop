#include "header.h"

void	ft_init_flags(t_flags *flags)
{
	flags->plus = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->width = 0;
	flags->percition = 0;
	flags->type = 0;
}

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
			printed += ft_processor(&str[++i], argptr);
			// i += 1;
		}
		++i;
	}
	va_end(argptr);
	return (printed);
}
