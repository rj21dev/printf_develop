#include "libft.h"

void	*ft_realloc(void *src, size_t size)
{
	void	*dst;
	size_t	i;

	dst = malloc(size);
	if (!dst)
		return (NULL);
	i = 0;
	while (src && i < size && ((char *)src)[i])
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	((char *)dst)[i] = '\0';
	free(src);
	return (dst);
}
