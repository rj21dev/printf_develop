#include "header.h"

static int	count_mem(int nbr);

static char	*putnbr_str(char *str, int nbr, int len, int sign);

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		sign;

	len = count_mem(n);
	sign = 1;
	if (n < 0)
		sign *= -1;
	res = (char *) malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	return (putnbr_str(res, n, len, sign));
}

static int	count_mem(int nbr)
{
	int	nbr_len;

	nbr_len = 0;
	if (!nbr)
		return (1);
	else if (nbr < 0)
		++nbr_len;
	while (nbr)
	{
		nbr /= 10;
		++nbr_len;
	}
	return (nbr_len);
}

static char	*putnbr_str(char *str, int nbr, int len, int sign)
{
	if (!nbr)
		str[0] = '0';
	if (nbr < 0)
		str[0] = '-';
	str[len] = 0;
	while (nbr)
	{
		str[len - 1] = nbr % 10 * sign + '0';
		nbr /= 10;
		--len;
	}
	return (str);
}
