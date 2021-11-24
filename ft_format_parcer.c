#include "header.h"

static int	is_fmt_flag(int c)
{
	return (c == '0' || c == '+' || c == '-' || c == '#' || c == ' ');
}

static int	is_fmt_type(int c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%');
}

static void	ft_search_flags(const char *fmt, int *index, t_flags *flags)
{
	while (*fmt && is_fmt_flag(*fmt))
	{
		if (fmt[*index] == '0')
			flags->zero = 1;
		if (fmt[*index] == ' ')
			flags->space = 1;
		if (fmt[*index] == '-')
			flags->minus = 1;
		if (fmt[*index] == '+')
		{
			flags->plus = 1;
			flags->space = 1;
		}
		if (fmt[*index] == '#')
			flags->hash = 1;
		(*index)++;
	}
}

static void	ft_search_sizes(const char *fmt, int *index, t_flags *flags)
{
	while (ft_isdigit(fmt[*index]) || fmt[*index] == '.')
	{
        if (fmt[*index] == '.')
			flags->dot = 1;
        else if (!flags->dot)
        	flags->width *= 10 + fmt[*index] - '0';
        else
            flags->percition *= 10 + fmt[*index] - '0';
        (*index)++;
    }
}

void ft_format_parcer(const char *fmt, int *index, t_flags *flags)
{
	ft_search_flags(fmt, index, flags);
	ft_search_sizes(fmt, index, flags);
	if (is_fmt_type(*fmt))
		flags->type = *fmt;
}