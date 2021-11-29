#ifndef HEADER_H
# define HEADER_H

# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_print_decimal(va_list argptr);
int	ft_print_unsigned(va_list argptr);
int	ft_print_hex(va_list argptr);
int	ft_print_upper_hex(va_list argptr);
int	ft_print_voidptr(va_list argptr);

#endif