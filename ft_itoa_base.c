#include "header.h"

size_t ft_strlen(char *str)
{
    size_t i;

    i = 0;
    while (str[i])
        ++i;
    return (i);
}

char    *ft_itoa_base(int nbr, char *base)
{
    int    tmp;
    char            *num;
    size_t          numlen;
    size_t          baselen;
   
    numlen = 0;
    baselen = ft_strlen(base);
    tmp = nbr;
    if (nbr < 0)
        ++numlen;
    while (tmp)
    {
        tmp /= baselen;
        ++numlen;
    }
    num = (char *) malloc(sizeof(char) * numlen + (!nbr) + 1);
    if (!num)
        return (NULL);
    num[numlen + (!nbr)] = 0;
    if (!nbr)
        num[0] = '0';
    if (nbr < 0)
    {
        nbr *= -1;
        num[0] = '-';
    }
    while (nbr)
    {
        num[--numlen] = base[nbr % baselen];
        nbr /= baselen;
    }
    return (num);
}
