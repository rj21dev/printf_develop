#include "header.h"
#include "./libft/libft.h"

static int	ft_print_str(va_list argptr)
{
	char	*str;

	str = va_arg(argptr, char *);
	if (!str)
		return(ft_putstr_fd("(null)", STDOUT));
    return (ft_putstr_fd(str, STDOUT));
}

static int	ft_type_selector(const char *str, va_list argptr)
{
	int	printed;

	printed = 0;
	if (*str == 'c')
		printed += ft_putchar_fd(va_arg(argptr, int), STDOUT);
	if (*str == 's')
		printed += ft_print_str(argptr);
	if (*str == 'p')
		printed += ft_print_voidptr(argptr);
	if (*str == 'd' || *str == 'i')
		printed += ft_print_decimal(argptr);
	if (*str == 'u')
		printed += ft_print_unsigned(argptr);
	if (*str == 'x')
		printed += ft_print_hex(argptr);
	if (*str == 'X')
		printed += ft_print_upper_hex(argptr);
	if (*str == '%')
		printed += ft_putchar_fd('%', STDOUT);
	return (printed);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		printed;
	va_list	argptr;

	i = 0;
	printed = 0;
	va_start(argptr, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
			printed += ft_type_selector(&str[++i], argptr);		
		else
			printed += ft_putchar_fd(str[i], STDOUT);
		++i;
	}
	va_end(argptr);
	return (printed);
}
