#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define STDOUT 1

int	ft_printf(const char *str, ...);
int	ft_putchar_fd(char c, int fd);
int	ft_processor(const char *str, va_list argptr);
int ft_putnbr_fd(int n, int fd);
int ft_putstr_fd(char *s, int fd);
char    *ft_itoa_base(int nbr, char *base);

#endif
