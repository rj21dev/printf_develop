#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define STDOUT 1

int	ft_printf(const char *str, ...);
int	ft_print_decimal(va_list argptr);
int	ft_print_unsigned(va_list argptr);
int	ft_print_hex(va_list argptr);
int	ft_print_upper_hex(va_list argptr);
int	ft_print_voidptr(va_list argptr);


int	ft_putchar_fd(char c, int fd);
int ft_putstr_fd(char *s, int fd);
char    *ft_ultoa(unsigned long int nbr, char *base);
char	*ft_itoa(int n);

#endif