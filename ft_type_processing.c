#include "header.h"

int	ft_print_decimal(va_list argptr)
{
	char	*num;
	int		printed;

	printed = 0;
	num = ft_itoa(va_arg(argptr, int));
	if (!num)
		return (printed);
	printed += ft_putstr_fd(num, STDOUT);
	free(num);
	return (printed);
}

int	ft_print_unsigned(va_list argptr)
{
	char	*num;
	int		printed;

	printed = 0;
	num = ft_ultoa(va_arg(argptr, unsigned int), "0123456789");
	if (!num)
		return (printed);
	printed += ft_putstr_fd(num, STDOUT);
	free(num);
	return (printed);
}

int	ft_print_hex(va_list argptr)
{
	char	*hex;
	int		printed;

	printed = 0;
	hex = ft_ultoa(va_arg(argptr, unsigned int), "0123456789abcdef");
	if (!hex)
		return (printed);
	printed += ft_putstr_fd(hex, STDOUT);
	free(hex);
	return (printed);
}

int	ft_print_upper_hex(va_list argptr)
{
	char	*upper_hex;
	int		printed;

	printed = 0;
	upper_hex = ft_ultoa(va_arg(argptr, unsigned int), "0123456789ABCDEF");
	if (!upper_hex)
		return (printed);
	printed += ft_putstr_fd(upper_hex, STDOUT);
	free(upper_hex);
	return (printed);
}

int	ft_print_voidptr(va_list argptr)
{
	char	*voidptr;
	int		printed;

	printed = 0;
	voidptr = ft_ultoa(va_arg(argptr, unsigned int), "0123456789abcdef");
	if (!voidptr)
		return (printed);
	printed += ft_putstr_fd("0x", STDOUT);
	printed += ft_putstr_fd(voidptr, STDOUT);
	free(voidptr);
	return (printed);
}
