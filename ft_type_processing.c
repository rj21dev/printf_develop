/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_processing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:29:26 by rjada             #+#    #+#             */
/*   Updated: 2021/11/30 18:29:31 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "./libft/libft.h"

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
	num = ft_ultoa(va_arg(argptr, unsigned int), DEC);
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
	hex = ft_ultoa(va_arg(argptr, unsigned int), HEX);
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
	upper_hex = ft_ultoa(va_arg(argptr, unsigned int), HEX_UP);
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
	voidptr = ft_ultoa(va_arg(argptr, unsigned int), HEX);
	if (!voidptr)
		return (printed);
	printed += ft_putstr_fd("0x", STDOUT);
	printed += ft_putstr_fd(voidptr, STDOUT);
	free(voidptr);
	return (printed);
}
