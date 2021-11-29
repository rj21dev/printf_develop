/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:32:01 by rjada             #+#    #+#             */
/*   Updated: 2021/10/10 19:02:22 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*area;
	size_t	i;
	size_t	total;

	if (size && count > (size_t)-1 / size)
		return (NULL);
	total = count * size;
	area = malloc(total);
	if (!area)
		return (NULL);
	i = 0;
	while (i < total)
		((unsigned char *)area)[i++] = 0;
	return (area);
}
