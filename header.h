#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_flags
{
	int	plus;
	int	minus;
	int zero;
	int	space;
	int hash;
	int	width;
	int	percition;
	int	type;
}	t_flags;

# define STDOUT 1

int	ft_printf(const char *str, ...);
int	ft_putchar_fd(char c, int fd);
int	ft_processor(const char *str, va_list argptr);
int ft_putnbr_fd(int n, int fd);
int ft_putstr_fd(char *s, int fd);
char    *ft_ultoa(unsigned long int nbr, char *base);
char	*ft_itoa(int n);

#endif